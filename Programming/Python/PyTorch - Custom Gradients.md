---
tags:
  - Python
  - PyTorch
  - DeepLearning
  - Autograd
  - Gradient
  - 概念性
title: PyTorch - Custom Gradients
created: 2026-06-01
---

# PyTorch - Custom Gradients — Manual Gradient Control

> [!abstract] Overview
> PyTorch 的自动求导（autograd）引擎是深度学习的核心基础设施。但实际训练中，仅仅调用 `loss.backward()` 远远不够——你需要手动提取中间梯度、定义自定义梯度传播规则、控制计算图生命周期。本文从 `torch.autograd.grad()`、`torch.autograd.Function`、梯度切断和计算图保留四个维度展开，以 CTM 的 Loss Bridge 为案例，展示手动梯度控制在复杂训练系统中的关键作用。

Related: [[Python - Decorators]] | [[Python - Abstract Base Classes]] | [[CTM - Training System]] | [[CTM - Loss Functions]]

---

## 1. Custom Gradients — Core Principles

### What & Why

自动求导掩盖了三个常见但重要的操作：

- **手动提取梯度**：`loss.backward()` 将梯度累积到 `.grad` 属性，但你有时需要直接获取梯度张量（例如传给另一个模型或分析梯度范数）
- **自定义算子**：某些操作不可微，或你需要替换标准梯度（如 STE 直通估计器、梯度裁剪后反向传播）
- **计算图控制**：`retain_graph` 允许同一计算图多次反向传播；`detach()` 切断梯度流
- **跨模型梯度桥接**：混合模型系统中，一个模型计算损失，另一个模型接收梯度

### Mathematical / Theoretical Foundation

**手动梯度提取 (torch.autograd.grad)**：比 `backward()` 更细粒度。`backward()` 从叶子节点开始累积到 `.grad`，而 `grad()` 直接返回输出对输入的梯度：

| 方法 | 返回 | 副作用 | 适用场景 |
|------|------|--------|---------|
| `loss.backward()` | None | 填充 `.grad`，累积到叶子节点 | 标准训练循环 |
| `torch.autograd.grad()` | 梯度张量列表 | 无副作用，不修改 `.grad` | 中间梯度提取、梯度传递 |

```python
# backward 方式
loss.backward()
dnn_grad = model.fc.weight.grad  # 从叶子节点读取

# grad 方式——不修改模型状态
dnn_grad = torch.autograd.grad(
    outputs=loss,
    inputs=model.parameters(),
    retain_graph=True,        # 保留计算图供后续使用
    create_graph=True         # 创建高阶梯度计算图
)
```

**自定义 Autograd Function**：通过继承 `torch.autograd.Function`，定义前向和反向传播：

```python
class GradientBridgeFunction(torch.autograd.Function):
    @staticmethod
    def forward(ctx, dnn_output, gbdt_gradient):
        # ctx 存储供 backward 使用的中间变量
        ctx.save_for_backward(dnn_output, gbdt_gradient)
        # 前向直接返回 DNN 输出（不影响原始预测）
        return dnn_output.clone()

    @staticmethod
    def backward(ctx, grad_output):
        dnn_output, gbdt_gradient = ctx.saved_tensors
        # grad_output 是 loss 对 DNN 输出的梯度
        # 返回两个输入的梯度（None 表示不需要梯度）
        return gbdt_gradient, None
```

**梯度切断 (detach)**：`detach()` 从计算图中剥离张量，返回一个 requires_grad=False 的新张量：

| 操作 | 梯度流 |
|------|--------|
| `x` | 全部通过 |
| `x.detach()` | 完全切断 |
| `x.detach().clone()` | 切断并复制 |
| `x.data` | 切断（不安全，不推荐） |

### Key Design Dimensions & Tradeoffs

| 设计维度 | 选项 | 取舍 |
|---------|------|------|
| **梯度提取** | `backward()` / `grad()` | backward 简单但有副作用；grad 精确但不累积 |
| **自定义算子** | Function / 纯 Python 重写 | Function 侵入式但可微；重写简单但可能丢失梯度通路 |
| **计算图保留** | `retain_graph=True/False` | True 灵活但内存翻倍；False 高效但只允许一次反向 |
| **梯度切断** | detach / detach_ / no_grad | detach 创建新张量；no_grad 上下文管理器批量控制 |
| **高阶梯度** | `create_graph=True/False` | True 支持 Hessian 等二次梯度但 OOM 风险 |

---

## 2. Case Study: CTM Patterns

### How CTM Applies These Principles

CTM 训练系统的核心特征之一是 **Loss Bridge**——它将 DNN 模型的梯度作为监督信号传递给 GBDT 模型。这本质上是手动梯度控制的应用：

| 通用技术 | CTM 的具体使用 | 动机 |
|---------|---------------|------|
| `torch.autograd.grad()` | 提取 CTM 对各样本的梯度向量 | 不需要修改 DNN 参数，只取梯度值传给 GBDT |
| `retain_graph=True` | Loss Bridge 中保留 DNN 计算图 | DNN 自身仍需正常反向传播优化参数 |
| `detach()` | 分离 GBDT 预测分支的梯度 | 防止 GBDT 参与的路径影响 DNN 参数更新 |
| `torch.autograd.Function` | 自定义梯度桥接算子（若有） | 在 DNN 和 GBDT 之间建立可微通路 |

**Loss Bridge 梯度提取**：

```python
def bridge_dnn_to_gbdt(dnn_model, loss_fn, batch, gbdt_model):
    """
    提取 DNN 对损失函数的梯度，作为 GBDT 的学习目标。
    类似于 Gradient Boosting 中计算残差的思想。
    """
    x, y = batch
    dnn_output = dnn_model(x)

    # 计算 DNN 预测的损失
    loss = loss_fn(dnn_output, y)

    # 使用 grad() 提取 DNN 参数的梯度——不修改 .grad
    dnn_grads = torch.autograd.grad(
        outputs=loss,
        inputs=dnn_model.parameters(),
        retain_graph=True,          # DNN 后续仍需 backward()
        create_graph=False          # 不需要二阶梯度
    )

    # 聚合为样本级梯度信号（梯度范数或方向向量）
    grad_signal = aggregate_gradients(dnn_grads)

    # 传给 GBDT 作为训练目标（与原始预测无关）
    gbdt_model.fit(x.detach().cpu().numpy(), grad_signal.detach().cpu().numpy())

    # DNN 正常反向传播
    loss.backward()                 # 复用 retain_graph 保留的计算图
    optimizer.step()

    return loss.item()
```

### Design Decisions & Rationale

**1. 为什么不用 backward() 代替 grad()？**

`backward()` 会将梯度累积到模型参数的 `.grad` 属性，而这个 `.grad` 在 `optimizer.step()` 时被消费更新。如果先 `backward()` 一次传给 GBDT，再 `backward()` 一次用于参数更新，两次梯度的累积会混在一起——第一个梯度被用于两个目的，第二个梯度才是真正的当前 batch 梯度。`grad()` 无副作用，是梯度读取的正确选择。

**2. 为什么 GBDT 分支需要 detach()？**

```python
# 错误写法——GBDT 路径污染 DNN 计算图
gbdt_input = dnn_output               # GBDT 参与反向传播
gbdt_pred = gbdt_model(gbdt_input)
combined_loss = loss_fn(dnn_output, y) + gbdt_loss_fn(gbdt_pred, y)
combined_loss.backward()               # DNN 收到两份梯度

# 正确写法——切断 GBDT 分支
gbdt_input = dnn_output.detach()       # 梯度不回流
gbdt_pred = gbdt_model(gbdt_input)
# GBDT 的损失只指导 GBDT 参数更新，不影响 DNN
```

如果 GBDT 参与的计算图不切断，DNN 会同时接收来自 loss_fn 和 GBDT 的梯度。在 CTM 的集成设计中，GBDT 的梯度信号应该**只影响 GBDT 自己的参数**，而不应在 DNN 中引入额外的梯度分量。

**3. 为什么 retain_graph=True 是必要的？**

Loss Bridge 需要先提取梯度（消耗一次反向传播），DNN 参数优化又需要第二次反向传播。如果 `retain_graph=False`（默认），第一次 `grad()` 后计算图已被释放，第二次 `backward()` 会报错。设置 `retain_graph=True` 相当于告诉 PyTorch："这个图我有两个用途，别急着销毁"。

> [!warning] retain_graph 的内存代价
> 保留计算图意味着所有中间激活值保留在内存中，直到显式调用 `backward()` 消耗它。对于 CTM 这种包含 SSM 块的模型（序列长度 × 层数 × batch_size 的激活值），内存开销可能翻倍。GBDT 梯度提取应在 loss 计算后立即进行，减少计算图持有时间。

### GradientBridgeFunction — 自定义桥接算子

```python
class GradientBridge(torch.autograd.Function):
    """
    桥接 DNN 和另一模型（如 GBDT/规则系统）的梯度。
    前向：透传 DNN 输出（不修改预测值）
    反向：将外部梯度注入 DNN 的梯度流
    """
    @staticmethod
    def forward(ctx, dnn_out, external_grad=None):
        ctx.external_grad = external_grad
        return dnn_out.clone()

    @staticmethod
    def backward(ctx, grad_output):
        external_grad = ctx.external_grad
        if external_grad is not None:
            # 合并 DNN 自身梯度和外部梯度
            combined_grad = grad_output + external_grad
            return combined_grad, None
        return grad_output, None
```

> [!note] 与 CTM Training System 的关系
> Loss Bridge 的梯度传递是 [[CTM - Training System]] 中渐进式损失引入的底层机制。梯度在 DNN 和 GBDT 之间的桥接使得两个模型可以基于同一批数据、同一个目标函数联合优化。

---

## 3. Key Takeaways

### When to Use These Techniques

| 技术 | 适用场景 |
|------|---------|
| **torch.autograd.grad()** | 需要梯度但不修改模型参数时（梯度监控、梯度剪枝、梯度传递）|
| **torch.autograd.Function** | 自定义不可微操作、STE 直通估计器、梯度替换策略 |
| **retain_graph=True** | 单计算图需要多次反向传播（如 Loss Bridge 的双阶段梯度计算）|
| **detach()** | 需要阻断模型 A 到模型 B 的梯度路径，防止误传 |
| **create_graph=True** | 计算二阶梯度（Hessian 向量积、Meta-Learning、Gradient Penalty）|

### Common Pitfalls to Avoid

- **grad() 的 requires_grad 检查**：`torch.autograd.grad()` 的 `inputs` 必须全部 `requires_grad=True`，否则报错。使用 `filter(lambda p: p.requires_grad, model.parameters())` 过滤
- **retain_graph 释放时机**：保留的计算图必须在同一批次内被 `backward()` 消费，否则内存泄漏。不要跨 batch 保留
- **detach() 后原地修改**：`detach()` 返回的 tensor 和原始 tensor **共享内存**。修改 detach 后的 tensor 也会修改原始 tensor 的梯度流。如需隔离，用 `detach().clone()`
- **Function 的 GPU 内存**：`save_for_backward` 存储的张量会留在 GPU 上直到 backward 执行。对长序列（如 CTM 的 SSM 时序），这可能导致 OOM
- **data 属性不要用**：`x.data` 是 detach 的非安全版本，在 PyTorch 0.4+ 中已被标记为不推荐。总是用 `x.detach()`

### Related Concepts & Further Reading

- [[CTM - Training System]] — Loss Bridge 的完整训练管线上下文
- [[CTM - Loss Functions]] — 被桥接的损失函数设计（MSE → Sharpe Loss 渐进式引入）
- [[CTM - Ensemble and GBDT]] — GBDT 如何消费 DNN 的梯度信号
- PyTorch Autograd 文档 — `torch.autograd.grad()` 和 `torch.autograd.Function` 的官方 API
- *Straight-Through Estimator (STE)* — 离散化操作的梯度估计方法（BinaryConnect, BERT 量化）
