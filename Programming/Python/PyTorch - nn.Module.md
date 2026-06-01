---
tags:
  - Python
  - PyTorch
  - DeepLearning
  - Programming
  - 代码模式
title: "PyTorch - nn.Module \u2014 Foundation of Neural Network Components"
created: 2026-06-01
---

# PyTorch - nn.Module \u2014 Foundation of Neural Network Components

> [!abstract] Overview
> nn.Module 是 PyTorch 中所有神经网络组件的基类。理解它的设计哲学——参数注册、前向计算、子模块管理——是写出正确、可维护模型的前提。本文从 nn.Module 的核心机制出发，结合 CTM 项目中的实际使用模式，梳理最佳实践。

Related: [[CTM - StockModel Architecture]] | [[CTM - Architecture Patterns]] | [[CTM - Training System]] | [[PyTorch - Training Loop]]

---

## 1. Core Principles \u2014 What & Why

### What is nn.Module

nn.Module 是一个**自动参数管理容器**。你定义 `__init__` 声明参数和子模块，PyTorch 自动追踪它们。你实现 `forward()` 定义计算图，PyTorch 自动管理梯度。

```python
class MyLinear(nn.Module):
    def __init__(self, in_dim, out_dim):
        super().__init__()
        # nn.Parameter 自动注册为可训练参数
        self.weight = nn.Parameter(torch.randn(out_dim, in_dim) * 0.01)
        self.bias = nn.Parameter(torch.zeros(out_dim))

    def forward(self, x):
        return F.linear(x, self.weight, self.bias)
```

### Parameter vs Buffer

nn.Module 区分两种状态：

| 类型 | 注册方式 | 梯度 | 用途 |
|------|---------|------|------|
| **Parameter** | `nn.Parameter(...)` | 有 | 可训练的权重、偏置 |
| **Buffer** | `self.register_buffer(...)` | 无 | 统计量（running_mean, running_var） |

```python
class BatchNorm1d(nn.Module):
    def __init__(self, dim):
        super().__init__()
        self.weight = nn.Parameter(torch.ones(dim))     # 可训练
        self.bias = nn.Parameter(torch.zeros(dim))      # 可训练
        self.register_buffer("running_mean", torch.zeros(dim))   # 不可训练
        self.register_buffer("running_var", torch.ones(dim))    # 不可训练
```

> [!tip] Buffer 会自动随 `.to(device)` 迁移，`model.state_dict()` 也会包含它们。这是统计量管理的标准方式。

### Sub-module Registration

任何赋值为 `nn.Module` 属性的子模块都会自动注册：

```python
class DeepNet(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(64, 128)     # 自动注册
        self.fc2 = nn.Linear(128, 64)     # 自动注册
        self.blocks = nn.ModuleList()     # 列表容器，自动注册
        for _ in range(3):
            self.blocks.append(nn.Linear(64, 64))
```

**不自动注册的情况**：`list`、`dict`、`tuple` 中的 Module 不会自动注册。必须使用 `nn.ModuleList`、`nn.ModuleDict` 或 `nn.ParameterList`。

```python
# 错误示范：不会被注册
self.layers = [nn.Linear(64, 128) for _ in range(3)]
# 正确做法
self.layers = nn.ModuleList([nn.Linear(64, 128) for _ in range(3)])
```

### nn.Sequential vs nn.ModuleList

| 容器 | 是否保持 forward 顺序 | 适用场景 |
|------|----------------------|---------|
| `nn.Sequential` | 是，自动串联 | 单路径线性管道 |
| `nn.ModuleList` | 无 forward 语义 | 可迭代的子模块集合 |
| `nn.ModuleDict` | 无 forward 语义 | 按名字查找子模块 |

```python
# Sequential: 自动串联 forward
self.pipeline = nn.Sequential(
    nn.Linear(64, 128),
    nn.ReLU(),
    nn.Linear(128, 64),
)

# ModuleList: 需要手动迭代
self.blocks = nn.ModuleList([
    MambaBlock(d_model) for _ in range(n_layers)
])

def forward(self, x):
    for block in self.blocks:
        x = block(x)
    return x
```

> [!warning] `nn.Sequential` 会丢失对中间层输出的访问。如果需要在中间层做跳跃连接或异构操作，使用 `nn.ModuleList` + 手动 forward 更灵活。

### forward() \u2014 The Only Required Method

`forward()` 定义模型的计算图。它不一定要用 `self` 的成员——可以调用任何函数：

```python
def forward(self, x, asset_ids=None, return_aux=False):
    h = self.input_proj(x)
    h = self.causal_conv(h)
    h, aux = self.mamba_block(h)

    if asset_ids is not None:
        cond = self.asset_embed(asset_ids)
        h = h + cond.unsqueeze(0).unsqueeze(2)

    out = self.output_head(h)
    if return_aux:
        return out, aux
    return out
```

与 `__call__` 的核心区别：`__call__` 会调用 `forward()` 但还负责 hook 的执行。**永远不要直接调用 `forward()`**——否则 hooks 不会触发：

```python
# 正确
out = model(x)
# 错误（hooks 不执行）
out = model.forward(x)
```

---

## 2. Case Study: CTM Patterns

### Pattern 1: CTMStockModel \u2014 Composed Sub-modules

CTMStockModel 的 `__init__` 展示了清晰的子模块分层：

```python
class CTMStockModel(nn.Module):
    def __init__(self, config: dict):
        super().__init__()
        self.input_proj = nn.Linear(config["d_x"], config["d_model"])

        # CausalConv1d 使用 nn.Parameter + F.conv1d
        self.conv = nn.Parameter(
            torch.randn(config["d_model"], 1, config["d_conv"])
        )

        # ModuleList: 可变层数
        self.mamba_blocks = nn.ModuleList([
            MambaBlock(config["d_model"]) for _ in range(config["n_layers"])
        ])

        # Bi-Mamba 双向融合投影
        self.bi_proj = nn.Linear(config["d_model"] * 2, config["d_model"])

        # 多任务输出头
        self.reg_head = nn.Linear(config["d_model"], 1)
        self.cls_head = nn.Linear(config["d_model"], 3)
```

每个子模块的职责单一，forward 串联清晰：

```python
    def forward(self, x):
        h = self.input_proj(x)
        h = F.conv1d(h.transpose(1, 2), self.conv, groups=self.conv.size(0))
        h = h.transpose(1, 2)

        for block in self.mamba_blocks:
            h = block(h)

        h = torch.cat([h, torch.flip(h, dims=(1,))], dim=-1)
        h = self.bi_proj(h)

        return self.reg_head(h), self.cls_head(h)
```

### Pattern 2: MambaBlock \u2014 Template Method

MambaBlock 使用 `nn.Module` 的 Template Method 模式：共享骨架（参数化、卷积、SSM 计算），子类实现扫描策略：

```python
class MambaBlock(nn.Module):
    def __init__(self, d_model):
        super().__init__()
        self.in_proj = nn.Linear(d_model, d_model * 2)
        self.conv1d = nn.Conv1d(d_model, d_model, kernel_size=4,
                                groups=d_model, padding=3)
        self.x_proj = nn.Linear(d_model, 3 * d_model)  # delta, B, C

    def forward(self, x):
        residual = x
        x, gate = self.in_proj(x).chunk(2, dim=-1)
        x = self.conv1d(x.transpose(-1, 1)).transpose(-1, 1)
        delta, B, C = self.x_proj(x).chunk(3, dim=-1)
        x = self.selective_scan(x, delta, B, C)  # 子类可重写
        return residual + x * gate
```

### Pattern 3: LearnableWeights \u2014 Plain nn.Parameter

不是所有模块都需要 `forward()` 包含复杂的层操作。CTM 中的 `LearnableWeights` 类直接注册裸参数：

```python
class LearnableWeights(nn.Module):
    """纯可学习权重向量，用于自适应加权"""
    def __init__(self, n_weights, init_value=1.0):
        super().__init__()
        self.weights = nn.Parameter(torch.full((n_weights,), init_value))

    def forward(self):
        return F.softmax(self.weights, dim=-1)
```

核心特点：没有可学习参数的子模块，forward 仅返回经过 softmax 的值。这种"轻量 nn.Module"模式在需要自适应权重的场合非常有用。

### Pattern 4: MultiAssetCTM \u2014 Conditional Parameters

MultiAssetCTM 通过 `nn.Embedding` + 条件注入实现跨资产共享：

```python
class MultiAssetCTM(nn.Module):
    def __init__(self, n_assets, embed_dim, model_dim):
        super().__init__()
        self.asset_embed = nn.Embedding(n_assets, embed_dim)   # (N, embed_dim)
        self.cond_proj = nn.Linear(embed_dim, model_dim)       # (N, model_dim)
        self.backbone = CTMStockModel(...)                     # 共享 Backbone

    def forward(self, x, asset_ids):
        cond = self.cond_proj(self.asset_embed(asset_ids))
        cond = cond.unsqueeze(0).unsqueeze(2)                 # (1, N, 1, model_dim)
        x = x + cond
        return self.backbone(x.reshape(-1, *x.shape[2:]))
```

---

## 3. Key Takeaways

### Best Practices

| 原则 | 说明 |
|------|------|
| **一次继承 nn.Module** | 所有可学习参数都在 nn.Module 子树中管理 |
| **明确区分 Parameter 和 Buffer** | 可训练用 Parameter，统计量用 Buffer |
| **使用 ModuleList/ModuleDict** | 不要用 Python list/dict 装模块 |
| **forward = 纯函数** | 不修改 `self` 的成员变量，只做计算 |
| **不要直接调用 forward()** | 用 `model(x)` 触发 hook 链 |
| **保持 sub-module 层次扁平** | 避免过深嵌套带来的状态管理复杂化 |

### Common Pitfalls to Avoid

- **忘记 `super().__init__()`**：子类不调用父类构造器，参数不会被注册，`model.parameters()` 返回空
- **循环引用**：Module 持有 DataLoader 或 Dataset 引用可能导致无法析构。退出时手动 `del model` 或用 `with torch.no_grad()` 隔离
- **修改 Parameter 原地**：`param.data += 1` 不会触发梯度，应使用 `nn.init` 或 `param.data.copy_()`
- **Train/Eval 模式管理**：`model.train()` 和 `model.eval()` 影响 BN/Dropout/Mamba 的 selectivescan 行为，验证推理必须切 mode
- **共享权重但不共享参数**：一个 Parameter 对象赋值给多个模块属性时，梯度会正确累积；但复制同一个 `nn.Module` 对象的部分 `state_dict` 可能导致梯度双重计数

### Related Concepts

- [[CTM - StockModel Architecture]] — CTMStockModel 的完整架构
- [[CTM - Architecture Patterns]] — Template Method 模式在 MambaBlock 中的应用
- [[PyTorch - Training Loop]] — nn.Module 的 state_dict 在训练中如何被管理
- Paszke et al., *PyTorch: An Imperative Style, High-Performance Deep Learning Library* (2019) — nn.Module 的设计原论文
