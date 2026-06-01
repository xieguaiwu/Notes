---
tags:
  - Python
  - PyTorch
  - DeepLearning
  - Programming
  - 工程实践
title: "PyTorch - Tensor Layout \u2014 Shape, Stride, and Memory Semantics"
created: 2026-06-01
---

# PyTorch - Tensor Layout \u2014 Shape, Stride, and Memory Semantics

> [!abstract] Overview
> PyTorch 张量的核心抽象是 shape 和 stride。shape 定义逻辑维度，stride 定义维度间在内存中的步长。reshape、view、permute、transpose 等操作在语义上相近但底层行为不同——理解它们的区别可以避免 bug，写出更高效的张量操作代码。

Related: [[CTM - MultiAsset Model]] | [[CTM - StockModel Architecture]] | [[PyTorch - nn.Module]] | [[PyTorch - Training Loop]]

---

## 1. Core Principles \u2014 What & Why

### Shape, Stride, and Contiguity

每个 PyTorch 张量有三个核心属性：

```python
t = torch.randn(3, 4)
print(t.shape)    # torch.Size([3, 4])
print(t.stride()) # (4, 1) —— dim 0 跨 4 个元素，dim 1 跨 1 个元素
print(t.storage().data_ptr())  # 内存地址
```

**Contiguous 的定义**：如果张量在内存中按行优先（row-major / C-order）排列，即 `stride[i] == stride[i+1] * shape[i+1]`，则该张量是 contiguous 的。

```python
t = torch.randn(3, 4)
print(t.is_contiguous())  # True —— (4, 1) 符合行优先

t_t = t.T                 # 转置：stride 变为 (1, 4)
print(t_t.is_contiguous())  # False —— (1, 4) 不符合行优先
```

非 contiguous 张量的元素在内存中没有按逻辑顺序排列。许多操作（如 `view`）要求 contiguous 输入。

### view() vs reshape() vs permute() vs transpose()

这四个操作的语义容易混淆，但核心区别在于**是否改变内存布局**：

| 操作 | 是否改变 stride | 是否要求 contiguous | 是否分配新内存 |
|------|---------------|-------------------|--------------|
| `view()` | 否 | **是** | 否 |
| `reshape()` | 否 | 自动处理 | 必要时 |
| `permute()` | **是** | 否 | 否 |
| `transpose()` | **是** | 否 | 否 |

```python
x = torch.randn(3, 4, 5)       # contiguous: True

# view: 仅改变逻辑 shape，不改变 stride
y = x.view(3, 20)              # 可行，因为 x contiguous
# y = x.T.view(20, 3)         # ERROR! x.T 非 contiguous

# reshape: 类似 view，但自动处理非 contiguous
z = x.T.reshape(20, 3)         # 可行，reshape 内部做了 contiguous 拷贝

# permute: 重新排列维度，改变 stride
p = x.permute(1, 0, 2)         # shape: (4, 3, 5), stride 变为 (5, 20, 1)
# p 非 contiguous

# transpose: 交换两个维度，等价于 permute 的 2D 特化
t = x.transpose(0, 1)          # 同 x.permute(1, 0, 2)
```

> [!warning] `view()` 和 `permute()` 都返回原张量的**视图**——共享存储。修改视图会影响原张量。`reshape()` 在非 contiguous 时返回副本。

### Broadcasting Rules

Broadcasting 允许不同形状的张量进行逐元素运算。规则简单但严格：

1. **从右往左对齐维度**
2. **每个维度要么相等要么为 1**
3. **为 1 的维度会 broadcast 到目标的 size**

```python
a = torch.randn(3, 1, 5)      # shape: (3, 1, 5)
b = torch.randn(1, 4, 1)      # shape: (1, 4, 1)
c = a + b                     # result: (3, 4, 5) —— 两个维度都 broadcast

# 常见的加法条件信号注入
cond = cond_signal.unsqueeze(0).unsqueeze(2)  # (1, N, 1, D)
x = x + cond                                   # (B, N, T, D) + (1, N, 1, D)
```

| 常见错误 | 表现 | 修正 |
|---------|------|------|
| 维度不匹配 | `RuntimeError: The size of tensor a (...) must match the size of tensor b (...)` | 用 `.unsqueeze()` 显式扩展 |
| 语义错误 | 广播到错误维度 | 明确目标维度后再 `.unsqueeze()` |

### Contiguity and Performance

非 contiguous 张量在运算前需要**隐式 contiguous 化**，这会触发内存拷贝。对于频繁访问的张量，提前调用 `.contiguous()` 可以避免重复拷贝：

```python
# 多次操作时
h = x.permute(0, 2, 1, 3)     # 非 contiguous
h = h.contiguous()             # 一次拷贝，变为 contiguous
h = h.view(B, T, -1)          # 后续 view 操作安全
```

> [!tip] `torch.flip` 是零拷贝操作——它只改变 stride，不改变 storage。因此 CTM 的 Bi-Mamba 使用的 `torch.flip(h, dims=(1,))` 几乎没有显存开销。

---

## 2. Case Study: CTM Patterns

### Pattern 1: MultiAssetCTM \u2014 (B, N, T, D) Reshape

多资产张量的标准布局是 `(B, N, T, D)` 的四维张量。共享 Mamba Backbone 需要将其 reshape 为 `(B*N, T, D)`：

```python
class MultiAssetCTM(nn.Module):
    def forward(self, x):
        B, N, T, D = x.shape

        # reshape: (B, N, T, D) → (B*N, T, D)
        # 这里 x 是新创建的，通常 is_contiguous
        x_reshaped = x.reshape(B * N, T, D)

        # 共享 Backbone 处理合并的 batch
        h = self.mamba_backbone(x_reshaped)       # (B*N, T, model_dim)

        # reshape 回 4D 用于跨资产注意力
        h = h.reshape(B, N, T, -1)                # (B, N, T, model_dim)
```

**为什么此处用 reshape 而非 view**：`x` 可能是某个操作的输出，其 contiguous 性不确定。`reshape` 做了安全保证——contiguous 时等同 view，否则拷贝。

### Pattern 2: CrossAssetMix \u2014 permute for Attention

跨资产注意力在**资产维度**上交互，需要将 `(B, N, T, D)` permute 为 `(B, T, N, D)` 然后将 B 和 T 合并：

```python
# 输入 h: (B, N, T, model_dim)

# Step 1: permute 交换维度 N 和 T
h_bt = h.permute(0, 2, 1, 3)          # (B, T, N, D), 非 contiguous

# Step 2: reshape 合并 B 和 T
h_bt = h_bt.reshape(B * T, N, D)      # 自动 contiguous 化

# Step 3: 在 N 维度上计算注意力
Q = self.q_proj(h_bt)                 # (B*T, N, D)
K = self.k_proj(h_bt)                 # (B*T, N, D)
scores = torch.matmul(Q, K.transpose(-2, -1))  # (B*T, N, N)
```

| 操作 | 作用 |
|------|------|
| `permute(0, 2, 1, 3)` | 交换 Asset 和 Time 维度 |
| `reshape(B*T, N, D)` | 合并 Batch 和 Time |
| `transpose(-2, -1)` | Q·K^T 需要的最后两维转置 |

> [!note] permute → reshape 的顺序很重要。如果先 reshape 再 permute，语义完全不同：`(B*N, T, D) → permute` 会破坏资产-时间的对应关系。

### Pattern 3: Bi-Mamba \u2014 flip + concat

双向融合使用 `torch.flip` 沿时间维度反转，然后拼接：

```python
# h: (B, N, T, D) 或 (B, T, D)
h_forward = h
h_backward = torch.flip(h, dims=(1 if h.ndim == 3 else 2,))
# flip 仅修改 stride——零拷贝

h_combined = torch.cat([h_forward, h_backward], dim=-1)  # (..., D*2)
h_out = self.bi_proj(h_combined)                          # (..., D)
```

### Pattern 4: Output Layout \u2014 permute + reshape

多资产输出需要将 `(B, N, T, out_dim)` 转为 `(B, T, N * out_dim)` 以匹配展平 loss：

```python
out_reg = self.reg_head(h)                   # (B, N, T, 1)
out_reg = out_reg.permute(0, 2, 1, 3)        # (B, T, N, 1)
out_reg = out_reg.reshape(B, T, N * 1)       # (B, T, N)
```

这种 permute + reshape 的双重操作非常常见。关键是要画清楚维度映射图：

```
(B, N, T, D) --permute(0,2,1,3)--> (B, T, N, D) --reshape--> (B, T, N*D)
```

### Broadcasting in Conditional Injection

CTM 的 Asset Embedding 使用 broadcasting 将 `(N, D)` 扩展到 `(B, N, T, D)`：

```python
emb = self.asset_embed(asset_ids)         # (N, embed_dim)
cond = self.cond_proj(emb)                 # (N, model_dim)
cond = cond.unsqueeze(0).unsqueeze(2)      # (1, N, 1, model_dim)
x = x + cond                               # (B, N, T, model_dim) 广播到 B 和 T
```

`(1, N, 1, D)` 与 `(B, N, T, D)` 相加时，第 0 维（B）和第 2 维（T）自动 broadcast。

---

## 3. Key Takeaways

### Choosing the Right Operation

| 你想做什么 | 用哪个 | 理由 |
|-----------|-------|------|
| 仅改变 shape（顺序不变） | `view()` | 最轻量，要求 contiguous |
| 改变 shape，不关心 contiguity | `reshape()` | 安全通用 |
| 重排维度顺序 | `permute()` | 灵活的多维交换 |
| 交换两个维度 | `transpose()` | `permute` 的 2D 特化 |
| 反转某个维度 | `flip()` | 零拷贝 |
| 确保 contiguous | `.contiguous()` | 显式控制，避免隐式拷贝 |

### Contiguity Decision Tree

```
张量是 contiguous 吗？
├── 是 → view() 安全，性能最佳
└── 否 → 你需要什么？
    ├── 仅读取 → permute/transpose 足够，无需拷贝
    ├── 写入 + 非原位操作 → reshape() 自动处理
    └── 写入 + 多次操作 → 提前 .contiguous() 避免多次隐式拷贝
```

### Common Pitfalls to Avoid

- **`view()` 在非 contiguous 张量上崩溃**：总是用 `reshape()`，除非你明确知道张量是 contiguous
- **permute 后忘记 contiguous**：permute → view 链会报错，中间加 `.contiguous()` 或改用 `reshape()`
- **广播到错误维度**：`(4, 3) + (3,)` 广播的是最后一维，不是第一维。需要先 `unsqueeze(0)` 或 `unsqueeze(-1)`
- **transpose 与 permute 混淆**：`transpose(0, 1)` 等价于 `permute(1, 0, 2, 3, ...)`，后者在 3D+ 时语义更清晰
- **reshape 改变元素总数**：`reshape` 后的元素数必须与原张量一致，否则报错

### Related Concepts

- [[CTM - MultiAsset Model]] — (B, N, T, D) 张量布局和多资产 reshape 模式
- [[CTM - StockModel Architecture]] — CausalConv1d 中的 padding 和维度转置
- [[PyTorch - nn.Module]] — Parameter 的 shape 定义和初始化
- PyTorch Documentation — `torch.Tensor.view`, `torch.reshape`, `torch.permute`, `torch.transpose`
- Paszke et al., *PyTorch: An Imperative Style, High-Performance Deep Learning Library* (2019) — Tensor 的 stride 设计
