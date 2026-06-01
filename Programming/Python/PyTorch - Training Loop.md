---
tags:
  - Python
  - PyTorch
  - DeepLearning
  - Programming
  - 工程实践
title: "PyTorch - Training Loop \u2014 From Data to Trained Model"
created: 2026-06-01
---

# PyTorch - Training Loop \u2014 From Data to Trained Model

> [!abstract] Overview
> 训练循环是深度学习项目中最常重复的代码模式——epoch 循环、loss backward、优化器步进、梯度管理、模型保存。虽然每个项目细节不同，但骨架高度一致。本文梳理标准训练循环的各个组件，以 CTM 的训练系统为案例，展示工业级训练循环的设计决策。

Related: [[CTM - Training System]] | [[CTM - Loss Functions]] | [[CTM - Walk-Forward Validation]] | [[PyTorch - nn.Module]]

---

## 1. Core Principles \u2014 What & Why

### The Standard Loop Skeleton

每个训练循环都包含这五个步骤，顺序固定：

```python
for epoch in range(num_epochs):
    model.train()
    for batch in train_loader:
        # Step 1: 梯度清零
        optimizer.zero_grad()

        # Step 2: 前向传播
        pred = model(batch)

        # Step 3: 损失计算
        loss = loss_fn(pred, batch)

        # Step 4: 反向传播
        loss.backward()

        # Step 5: 参数更新
        optimizer.step()
```

### optimizer.zero_grad() \u2014 Why It Must Be Called

PyTorch 的梯度是**累积的**——每次 `.backward()` 将梯度累加到 `.grad` 属性中，而不是替换。这在某些场景下很有用（如梯度累积模拟更大的 batch），但大多数训练需要在每个 batch 前清零：

```python
# 不清零的效果
loss1.backward()  # grad += grad1
loss2.backward()  # grad += grad2
optimizer.step()  # 用 grad1 + grad2 更新参数（通常不是你想要的）
```

> [!tip] 梯度累积技巧：当显存不够时，可以在 K 个 batch 后再 step 一次，达到 K 倍有效 batch size 的效果。只需调用 `optimizer.zero_grad()` 每 K 次而非每次。

### Gradient Clipping \u2014 Preventing Explosion

梯度裁剪在反向传播后、优化器步进前执行。它对所有参数的梯度向量求范数，如果超过阈值则等比例缩放：

```python
# 反向传播后，step 前
loss.backward()
nn.utils.clip_grad_norm_(model.parameters(), max_norm=1.0)
optimizer.step()
```

| 方法 | 行为 | 适用场景 |
|------|------|---------|
| `clip_grad_norm_` | 按全局 L2 范数缩放 | RNN, SSM, Transformer |
| `clip_grad_value_` | 按值截断到 [-value, value] | 值异常但方向不重要时 |

> [!warning] `nn.utils.clip_grad_norm_` 返回裁剪前的总范数——可用于日志监控。如果总范数异常高（如 > 100），说明训练可能不稳定。

### LR Scheduling

学习率调度器在 **每个 epoch（或 step）结束后**更新学习率。调度器与优化器绑定：

```python
optimizer = AdamW(model.parameters(), lr=1e-3)
scheduler = CosineAnnealingLR(optimizer, T_max=100)

for epoch in range(100):
    train_one_epoch(...)
    scheduler.step()          # 更新 LR
```

> [!warning] 不同调度器的 `step()` 调用时机不同。`ReduceLROnPlateau` 需要传入 val_loss：`scheduler.step(val_loss)`。`OneCycleLR` 通常每个 batch step 一次。务必阅读文档。

### SequentialLR \u2014 Composing Schedulers

`SequentialLR` 连接多个调度器，通过 `milestones` 定义切换点：

```python
scheduler = SequentialLR(optimizer, schedulers=[
    LinearLR(optimizer, start_factor=0.01, end_factor=1.0,
             total_iters=warmup_epochs),
    CosineAnnealingLR(optimizer, T_max=total_epochs - warmup_epochs),
], milestones=[warmup_epochs])
```

| 调度器 | 行为 | 适用场景 |
|--------|------|---------|
| `LinearLR` | 从 `start_factor` 线性到 1.0 | 预热期 |
| `CosineAnnealingLR` | 余弦退火到 0 | 标准衰减 |
| `StepLR` | 每 `step_size` 乘以 `gamma` | 阶段性任务 |
| `ReduceLROnPlateau` | 指标平台期时降 LR | 自动调度 |

### Checkpoint Saving

标准的 checkpoint 保存 `state_dict`，而非整个模型对象：

```python
torch.save({
    "epoch": epoch,
    "model_state_dict": model.state_dict(),
    "optimizer_state_dict": optimizer.state_dict(),
    "scheduler_state_dict": scheduler.state_dict(),
    "best_val_metric": best_val,
    "config": config,
}, f"checkpoint_epoch_{epoch}.pt")
```

恢复时用 `load_state_dict`：

```python
checkpoint = torch.load("checkpoint_epoch_10.pt")
model.load_state_dict(checkpoint["model_state_dict"])
optimizer.load_state_dict(checkpoint["optimizer_state_dict"])
scheduler.load_state_dict(checkpoint["scheduler_state_dict"])
```

### Early Stopping

最简单的早停实现：

```python
best_metric = -float("inf")
patience = 10
no_improve = 0

for epoch in range(num_epochs):
    val_metric = validate(model, val_loader)

    if val_metric > best_metric:
        best_metric = val_metric
        no_improve = 0
        torch.save(model.state_dict(), "best_model.pt")
    else:
        no_improve += 1
        if no_improve >= patience:
            print(f"Early stopping at epoch {epoch}")
            break
```

---

## 2. Case Study: CTM Training Loop

### Complete Walk-Forward Training

CTM 使用 Walk-Forward Validation 进行时间序列交叉验证，每个窗口独立训练。这里展示了完整的训练循环，集成了所有组件：

```python
window_results = []

for window_idx, (train_data, val_data) in enumerate(walk_forward_splits):
    # 窗口初始化
    model = RecurrentCTM(d_model=128, n_layers=4, n_iterations=3)
    optimizer = AdamW(model.parameters(), lr=3e-4, weight_decay=1e-5)

    # SequentialLR: 预热 + 余弦退火
    warmup_epochs = 5
    total_epochs = 50
    scheduler = SequentialLR(optimizer, schedulers=[
        LinearLR(optimizer, start_factor=0.01, end_factor=1.0,
                 total_iters=warmup_epochs),
        CosineAnnealingLR(optimizer, T_max=total_epochs - warmup_epochs),
    ], milestones=[warmup_epochs])

    # 早停状态
    best_sharpe = -float("inf")
    no_improve = 0
    patience = 10
    window_metrics = []

    for epoch in range(total_epochs):
        # ---- 训练 ----
        model.train()
        total_loss = 0.0
        for batch in train_loader:
            # 渐进式损失：前期 MSE-only，后期引入 Sharpe
            lambda_sharpe = get_effective_lambda(
                epoch, warmup_epochs, ramp_epochs=15, target_lambda=0.3
            )

            optimizer.zero_grad()
            pred_reg, pred_cls = model(batch["x"])
            loss = composite_loss(pred_reg, pred_cls, batch, lambda_sharpe)
            loss.backward()

            # 梯度裁剪（SSM 路径的关键保护）
            grad_norm = nn.utils.clip_grad_norm_(
                model.parameters(), max_norm=1.0
            )
            optimizer.step()

            total_loss += loss.item()

        # ---- 验证 ----
        model.eval()
        val_sharpe = validate(model, val_data)

        # ---- 调度器步进 ----
        scheduler.step()
        current_lr = scheduler.get_last_lr()[0]

        # ---- 记录 ----
        window_metrics.append({
            "epoch": epoch,
            "train_loss": total_loss / len(train_loader),
            "val_sharpe": val_sharpe,
            "lr": current_lr,
            "grad_norm": grad_norm,
        })

        # ---- 早停检查 ----
        if val_sharpe > best_sharpe:
            best_sharpe = val_sharpe
            no_improve = 0
            torch.save({
                "model_state_dict": model.state_dict(),
                "optimizer_state_dict": optimizer.state_dict(),
                "config": model.config,
                "best_sharpe": best_sharpe,
                "epoch": epoch,
            }, f"window_{window_idx}_best.pt")
        else:
            no_improve += 1
            if no_improve >= patience:
                print(f"Window {window_idx}: early stop at epoch {epoch}")
                break

    # 窗口结果汇总
    window_results.append(TrainingResult(
        best_sharpe=best_sharpe,
        epochs_run=epoch + 1,
        window_metrics=window_metrics,
    ))
```

### Key Design Decisions

| 决策 | CTM 的选择 | 理由 |
|------|-----------|------|
| **LR 调度** | SequentialLR(LinearLR + CosineAnnealingLR) | 解耦预热和衰减，各自独立控制 |
| **梯度裁剪** | `clip_grad_norm_(max_norm=1.0)` | SSM 路径的梯度爆炸风险，按范数保留方向 |
| **渐进式损失** | get_effective_lambda 逐步引入 Sharpe | 先训练回归能力，再引入序列级目标 |
| **早停指标** | Val Sharpe（而非 val loss） | 直接挂钩最终交易性能 |
| **Checkpoint 格式** | dict 含 state_dict + config + 指标 | 完整可恢复，含实验元数据 |
| **窗口级早停** | 每个 walk-forward 窗口独立早停 | 高波动期需更多 epoch，平稳期防止过拟合 |

> [!tip] `scheduler.get_last_lr()[0]` 用于调试日志。CTM 在 window_metrics 中记录每个 epoch 的 LR，便于分析训练动态。

---

## 3. Key Takeaways

### The Complete Pipeline

```
optimizer.zero_grad() → forward() → loss.backward()
→ clip_grad_norm_() → optimizer.step() → scheduler.step()
```

这个顺序是固定的。任何调换都会破坏训练逻辑。

### Common Pitfalls to Avoid

- **`.zero_grad()` 遗忘**：梯度累积导致参数不收敛或直接发散
- **`model.eval()` 遗忘**：BN 和 Dropout 在验证时行为不同，遗忘会导致验证指标异常
- **`torch.no_grad()` 遗忘**：验证/推理时不关梯度，显存爆炸且浪费时间
- **调度器 step 时机错误**：`ReduceLROnPlateau` 需要 val_loss、`CosineAnnealingLR` 按 epoch、`OneCycleLR` 按 step，混用会错位
- **Checkpoint 只存 model**：不存 optimizer 和 scheduler 导致无法恢复训练中断
- **梯度裁剪位置错误**：必须在 `loss.backward()` 之后、`optimizer.step()` 之前
- **早停 patience 过大或过小**：经验值：总 epoch 的 10%-20%

### When to Add Each Component

| 组件 | 必须？ | 何时添加 |
|------|--------|---------|
| gradient zeroing | 是 | 每个 batch |
| loss.backward() | 是 | 每个 batch |
| optimizer.step() | 是 | 每个 batch |
| gradient clipping | 强烈建议 | RNN/SSM/Transformer 必须，MLP 可选 |
| LR scheduler | 强烈建议 | 几乎所有深度学习任务 |
| early stopping | 建议 | 存在过拟合风险时 |
| checkpointing | 是 | 生产环境必须 |
| logging/metrics | 是 | 调试和实验对比必备 |

### Related Concepts

- [[CTM - Training System]] — CTM 训练系统的完整设计
- [[CTM - Walk-Forward Validation]] — 与训练循环配合的时间序列交叉验证
- [[CTM - Loss Functions]] — 渐进式损失引入策略
- [[PyTorch - nn.Module]] — model.state_dict() 的底层机制
- Loshchilov & Hutter, *SGDR* (2017) — 余弦退火 LR 调度
- Smith, *Cyclical Learning Rates* (2017) — 学习率调度的系统研究
