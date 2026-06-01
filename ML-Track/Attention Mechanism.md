---
tags:
  - MachineLearning
  - DeepLearning
  - Architecture
  - Attention
  - Math
  - 定义性
title: Attention Mechanism
created: 2026-06-01
---

# Attention Mechanism

*缩放点积注意力、Q/K/V 变换与注意力变体*

> [!abstract] Overview
> 注意力机制 (Attention) 是深度学习中最具影响力的组件之一。它让模型能够动态选择输入中最相关的信息，而非对所有输入一视同仁。从机器翻译到序列推荐，注意力机制的核心思想——根据查询与键的匹配程度聚合值——已经成为构建现代序列模型的基础模块。

Related: [[Transformer]] | [[LSTM]] | [[CTM - MultiAsset Model]]

---

## 1. Core Principles — Attention

### What & Why

注意力机制解决了序列建模中的一个根本问题：**如何让模型关注输入中最重要的部分**。

在注意力出现之前，主流方案是固定权重聚合（平均池化、RNN 最后隐状态），或通过门控机制 (LSTM/GRU) 实现软性选择。但它们的表达能力受限于递推瓶颈或固定的参数化方式。

注意力机制的核心思想：

$$\text{Attention} = \sum_i \alpha_i \cdot v_i, \quad \alpha_i = \text{score}(q, k_i)$$

其中 $\alpha_i$ 是归一化的注意力权重，决定了每个值 $v_i$ 对输出的贡献度。

> [!note] 数据库查询类比
> 可以把注意力想象成数据库查询：Query 是搜索关键词，Key 是每条记录的索引标签，Value 是记录本身。通过比对 Query 与 Key 的匹配程度，决定每条记录应占多大的权重。

### Scaled Dot-Product Attention

缩放点积注意力是应用最广泛的注意力形式：

$$\text{Attention}(Q, K, V) = \text{softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)V$$

**为什么需要缩放**：假设 $q$ 和 $k$ 的每个元素独立服从标准正态分布，则 $q \cdot k$ 的均值为 0，方差为 $d_k$。不缩放时，大 $d_k$ 导致点积结果方差大，softmax 在高值区域的梯度趋于 0，造成梯度消失。除以 $\sqrt{d_k}$ 后，方差恢复为 1：

$$\text{Var}\left(\frac{QK^T}{\sqrt{d_k}}\right) = \frac{d_k}{d_k} = 1$$

**计算流程**：

```
Q (T_q, d_k)          K (T_k, d_k)          V (T_k, d_v)
    │                      │                     │
    └────────┬─────────────┘                     │
             ↓                                   │
       QK^T  (T_q, T_k)                          │
             │                                   │
       ÷ √d_k (缩放)                              │
             │                                   │
       softmax (逐行归一化)                         │
             │                                   │
             └──────────┬────────────────────────┘
                        ↓
                 Attention (T_q, d_v)
```

### Q, K, V — 三者的角色

$Q$, $K$, $V$ 来自输入 $X$ 的线性投影，每个都承载不同的角色：

| 角色 | 符号 | 来源 | 含义 |
|------|------|------|------|
| 查询 (Query) | $Q = XW_Q$ | 当前元素 | 我想找什么 |
| 键 (Key) | $K = XW_K$ | 所有元素 | 我有什么信息 |
| 值 (Value) | $V = XW_V$ | 所有元素 | 我提供什么信息 |

关键洞察：**$Q$ 和 $K$ 负责匹配，$V$ 负责传递内容**。

- $Q$ 和 $K$ 的维度 $d_k$ 可以很小（降低匹配成本）
- $V$ 的维度 $d_v$ 可以很大（保留丰富信息）
- $Q$ 和 $K$ 的投影矩阵可以不同（灵活度更高）

### Self-Attention vs Cross-Attention

| 类型 | 公式 | 含义 | 应用 |
|------|------|------|------|
| **Self-Attention** | $Q=K=V=X$ | 序列内部交互 | Encoder、Decoder 第一层 |
| **Cross-Attention** | $Q=X, K=V=Y$ | 序列间交互 | Decoder 到 Encoder、多模态 |

在 Self-Attention 中，每个位置关注序列中的所有位置（包括自身），实现全局上下文理解。在 Cross-Attention 中，Query 来自目标序列，Key 和 Value 来自源序列，实现信息传递。

### Causal Masking

在自回归生成任务中，当前时间步只能关注过去和当前，不能看到未来。实现方式是在注意力矩阵的上三角区域填充 $-\infty$：

```python
mask = torch.triu(torch.ones(T, T), diagonal=1).bool()
scores = scores.masked_fill(mask, float('-inf'))
attn_weights = torch.softmax(scores, dim=-1)
```

$$\text{MaskedAttention}(Q, K, V) = \text{softmax}\left(\frac{QK^T}{\sqrt{d_k}} + M\right)V$$

其中 $M_{ij} = 0$ 如果 $i \geq j$，否则 $M_{ij} = -\infty$。

> [!warning] 因果掩码的意义
> 无因果掩码时，模型会在训练阶段偷看未来信息（标签泄露），导致推理时的自回归生成完全失效。这在所有序列模型中都至关重要——无论在 Transformer 还是 SSM 中，因果结构都必须严格保证。

### Softmax Temperature

标准 softmax 可以通过温度参数 $\tau$ 调控权重的锐利程度：

$$\text{softmax}_i = \frac{\exp(z_i / \tau)}{\sum_j \exp(z_j / \tau)}$$

| $\tau$ | 效果 | 注意力分布 |
|--------|------|-----------|
| $\tau \to 0$ | 硬注意力 (接近 one-hot) | 只关注最相关的元素 |
| $\tau = 1$ | 标准 softmax | 正常分布 |
| $\tau \to \infty$ | 均匀注意力 | 所有位置同等权重 |

实际上，$\sqrt{d_k}$ 缩放也可以视为对温度的控制。较大的 $d_k$ 相当于较低的 $\tau$，得到更锐利的注意力分布。

### Attention Variants 对比

| 变体 | 复杂度 | 核心创新 | 适用场景 |
|------|--------|---------|---------|
| 缩放点积注意力 | $O(T^2)$ | 标准形式，通用性最强 | 大部分序列任务 |
| 线性注意力 | $O(T)$ | 用核函数近似 softmax | 长序列 |
| Flash Attention | $O(T^2)$ 实际加速 | IO 感知的分块算法 | 所有 Transformer (硬件优化) |
| 稀疏注意力 | $O(T \sqrt{T})$ | 只计算部分位置对 | 超长文本 |

---

## 2. Case Study: CTM Cross-Asset Attention

### MultiAssetCTM 中的交叉注意力

CTM 的 `MultiAssetCTM` 模块使用交叉注意力 (Cross-Attention) 实现跨资产的依赖建模：

```
输入: 多资产数据 (B, K, T, d)     K = 资产数
  │
  ├── 逐个资产编码 (Shared Mamba)
  │      每个资产独立通过 MambaBlock → (B, K, T, d)
  │
  └── Cross-Asset Attention
          Q = 当前资产编码
          K = V = 所有资产编码
          → 融合其他资产的信息
```

**为什么用 Cross-Attention 而非 Self-Attention**：

| 方案 | 含义 | 问题 |
|------|------|------|
| Global Self-Attention | K 个资产全部互相注意力 | $O(K^2)$ 跨资产交互，显存爆炸 |
| Cross-Attention (CTM) | 每个资产关注所有资产 | 共享 $K$ 和 $V$，计算高效 |
| 独立资产 (无交互) | 每个资产各自为政 | 丢失资产间协动信息 |

Cross-Attention 中所有资产共享同一组 $K$ 和 $V$ (来自所有资产的编码)，但每个资产有自己的 $Q$。这种方式在实现跨资产信息融合的同时保持 $O(K \cdot K)$ 的计算量。

### 对比：标准 Cross-Attention vs CTM 实现

| 维度 | 标准 Transformer Cross-Attention | CTM MultiAsset Cross-Attention |
|------|----------------------------------|-------------------------------|
| Q 来源 | 解码器隐状态 | 当前资产的 Mamba 编码 |
| K/V 来源 | 编码器输出 | 所有资产的编码 |
| 序列维度 | T (时间步) | K (资产) |
| 注意力维度 | 时间步之间的依赖 | 资产之间的依赖 |
| 缩放 | $\sqrt{d_k}$ | $\sqrt{d_k}$ |

> [!note] 注意力维度的切换
> 标准 Transformer 在时间维度 $T$ 上做注意力，而 MultiAssetCTM 在资产维度 $K$ 上做注意力。这是理解 CTM 注意力用法的关键——注意力维度可以是任意的，核心是 Q 和 K 的匹配逻辑。

---

## 3. Key Takeaways

### 何时使用何种注意力

| 需求 | 推荐方案 |
|------|---------|
| 序列内部全局建模 | Self-Attention |
| 两个序列间的信息传递 | Cross-Attention |
| 自回归生成 | Self-Attention + Causal Mask |
| 多源信息融合 | Cross-Attention (多组 K/V) |
| 长序列 (T > 4096) | 线性注意力或 SSM |

### 常见陷阱

- **温度或缩放控制缺失**：不加 $\sqrt{d_k}$ 缩放时，深层 Transformer 训练不稳定。这是新手最常见的错误之一
- **因果掩码应用位置错误**：Decoder 的自注意力层需要掩码，但 Cross-Attention 层不需要。编码器输出是完整序列
- **多头注意力中头数过多**：每头有效维度 $d_k = d_{\text{model}} / h$ 过小会导致表达能力不足。推荐 $d_k \geq 64$
- **注意力头冗余**：多头注意力的头并非都同等重要，后训练剪枝可以移除部分头而不影响性能

### 相关概念

- [[Transformer]] — 注意力机制在其中发挥核心作用
- [[Mamba]] — 选择性 SSM 作为注意力的替代
- [[CTM - MultiAsset Model]] — 跨资产 Cross-Attention 的完整实现
- [[CTM - Mamba and S6 SSM]] — SSM 的 $O(T)$ 复杂度与注意力的 $O(T^2)$ 对比
- [[Normalization]] — 注意力层后的归一化
