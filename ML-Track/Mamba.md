---
tags:
  - MachineLearning
  - Architecture
  - SequenceModel
  - Math
  - LinearAlgebra
  - 定义性
  - ComputerScience
title: Mamba
created: 2026-05-08
modified: 2026-06-01
---

# Mamba

> [!abstract] Overview
> Mamba 是一类**选择性状态空间模型** (Selective State Space Model)，由 Gu & Dao 于 2023 年提出。它在保持 SSM 线性复杂度 $O(T)$ 的同时，通过输入依赖的参数化实现了 Transformer 级别的内容感知能力。本文聚焦于 [[CTM - Mamba and S6 SSM]] 未覆盖的内容：架构的宽度/深度解耦、块结构细节、参数表、与 LSTM 的详细对比、反向传播要点、初始化策略，以及从 S4 到 Mamba-2 的完整演进路线。

> [!note] 阅读提示
> 核心理论——从 LTI SSM 到选择性 SSM 的演进、离散化 (ZOH)、S6 参数化、扫描策略对比、数值稳定性分析——详见 [[CTM - Mamba and S6 SSM §1]]。本文假定读者已熟悉这些概念。

---

## 1. 解耦：宽度 × 深度

Mamba 将隐藏状态拆分为两个独立的维度管理：

- $d_{\text{model}}$：通道数（特征类型数），增加它参数量增长 $O(d_{\text{model}}^2)$
- $d_{\text{state}}$：每通道记忆深度，增加它只影响两个小投影矩阵

**对比 LSTM**：LSTM 的状态是单一向量 $h \in \mathbb{R}^{d_h}$，宽度和深度耦合在同一个维度，增加记忆容量必然 $O(d_h^2)$ 增参。

这种解耦是 Mamba 参数效率的关键来源。

---

## 2. Mamba 块结构

```
x_t (d_x × 1)
│
├── W_in (2·d_model × d_x)
│   └── z = W_in · x_t → 拆为 z1 (SSM分支) + z2 (门控分支)
│
├── 因果 1D 卷积 (d_model × d_conv)
│   └── x_conv = causal_conv1d(z1) + b_conv
│
├── 选择性参数计算
│   ├── Δ = softplus(W_Δ · x_conv + b_Δ)     ← 步长
│   ├── B = W_B · x_conv                      ← 输入选择
│   └── C = W_C · x_conv                      ← 输出选择
│
├── SSM 离散化
│   ├── Ā = exp(Δ ⊙ A)         (A = -exp(A_log))
│   └── B̄ = Δ ⊙ B^T           (外层积)
│
├── 选择性扫描（逐通道独立）
│   └── h_t[i][j] = Ā_t[i] · h_{t-1}[i][j] + B̄_t[i][j] · x_conv[i]
│
├── SSM 输出
│   └── y_ssm[i] = ∑_j C[j] · h_t[i][j] + D[i] · x_conv[i]
│
├── SiLU 门控
│   └── y = SiLU(z2) ⊙ y_ssm
│
└── 输出投影
    └── ŷ = softmax(W_out · y)
```

> [!note] 结构与 CTM 实现的关系
> 上方的通用块结构对应 CTM 中 `BaseMambaBlock` 的模板方法设计。CTM 的实现在此基础上增加了双向融合和 RecurrentCTM 的循环迭代，详见 [[CTM - Mamba and S6 SSM §2]]。

---

## 3. 参数表

| 参数 | 维度 | 说明 |
|------|------|------|
| $W_{\text{in}}$ | $(2\cdot d_{\text{model}}) \times d_x$ | 输入投影（2x 用于门控） |
| $W_{\text{conv}}$ | $d_{\text{model}} \times d_{\text{conv}}$ | 因果 1D 卷积核 |
| $b_{\text{conv}}$ | $d_{\text{model}} \times 1$ | 卷积偏置 |
| $A_{\text{log}}$ | $d_{\text{model}} \times 1$ | $\log(-A)$，$A = -\exp(A_{\text{log}})$ |
| $D$ | $d_{\text{model}} \times 1$ | 跳跃连接 |
| $W_{\Delta}$ | $d_{\text{model}} \times d_{\text{model}}$ | $\Delta$ 投影 |
| $b_{\Delta}$ | $d_{\text{model}} \times 1$ | $\Delta$ 偏置 |
| $W_B$ | $d_{\text{state}} \times d_{\text{model}}$ | B 投影 |
| $W_C$ | $d_{\text{state}} \times d_{\text{model}}$ | C 投影 |
| $W_{\text{out}}$ | $d_y \times d_{\text{model}}$ | 输出投影 |

> [!note] 参数效率的关键
> $A_{\text{log}}$ 和 $D$ 都是 $O(d_{\text{model}})$ 的向量，而非 $O(d_{\text{model}}^2)$ 的矩阵。这是 Mamba 参数量远小于同等容量 LSTM 的原因。CTM 实现中 **$\Delta$ 使用低秩分解**进一步压缩，详见 [[CTM - Mamba and S6 SSM §2]]。

---

## 4. Mamba vs LSTM

| 维度 | LSTM | Mamba |
|------|------|-------|
| **时序建模** | 4 个门控网络 | 1 个 SSM 递推 + 门控 |
| **状态** | $h_t \in \mathbb{R}^{d_h}$ | $h_t \in \mathbb{R}^{d_{\text{model}} \times d_{\text{state}}}$ |
| **门控激活** | sigmoid（静态权重） | SiLU + 输入依赖选择 |
| **参数量** | $O(d_h^2)$ | $O(d_{\text{model}}^2 + d_{\text{model}} \cdot d_{\text{state}})$ |
| **训练并行度** | 无 | 可并行（关联扫描） |
| **推理速度** | $O(T)$ 顺序 | $O(T)$ 顺序（极小常数） |
| **长程依赖** | 加法路径缓解 | 选择性遗忘 + 小 $d_{\text{state}}$ |
| **内容自适应** | 无（权重固定） | 有（$\Delta, B, C$ 取决于 $x$） |

> [!note] 为什么 Mamba 不直接使用 LSTM 的门控？
> Mamba 的选择性参数 ($\Delta, B, C$) 在功能上等价于 LSTM 的遗忘门、输入门、输出门。但 Mamba 的数学形式更简洁：LSTM 每个门控是一个完整的神经网络层（$W \cdot [h_{t-1}, x_t] + b$），而 Mamba 的选择性参数是轻量级的线性投影（仅依赖于 $x_t$，不包含 $h_{t-1}$）。这种简化使 Mamba 在保持表达力的同时，参数更少、训练更稳定。

---

## 5. 反向传播要点

Mamba 反向传播比 LSTM 复杂，梯度通过**选择性扫描递推路径**和**输入依赖参数化路径**同时流动。

### 5.1 输出梯度

$$\frac{\partial L}{\partial o_t^{\text{out}}} = \hat{y}_t - \mathbf{1}_{y_t}$$

### 5.2 门控

$$\frac{\partial L}{\partial y_{\text{ssm},t}} = \frac{\partial L}{\partial y_t} \odot \text{SiLU}(z_2)$$

### 5.3 SSM 递推

$$\frac{\partial L}{\partial h_{t-1}} += \frac{\partial L}{\partial h_t} \odot \bar{A}_t$$

### 5.4 离散化

$$\frac{\partial L}{\partial \Delta_t} = \frac{\partial L}{\partial \bar{A}_t} \odot \bar{A}_t \odot A + \frac{\partial L}{\partial \bar{B}_t} \odot B_t^T$$

### 5.5 输入梯度

通过 $\Delta_t, B_t, C_t$ 的三个投影传回卷积输出，再通过因果卷积的反向传播传到 $z_1$，最终与 $z_2$ 的梯度合并传到 $W_{\text{in}}$。

---

## 6. 权重初始化

- Xavier 初始化：$W_{\text{in}}, W_{\text{conv}}, W_{\Delta}, W_B, W_C, W_{\text{out}}$
- $A_{\text{log}} = -1$：$A = -e^{-1} \approx -0.368$
- $D = 0$：跳跃连接初始为零
- $b_{\Delta}$：初始化为小的正值（如 0.001）
- $b_{\text{conv}}$：初始化为零

> [!tip] 初始化的意义
> $A_{\text{log}}$ 初始化为 $-1$ 确保了 $A$ 为负、$\bar{A}$ 在 $(0,1)$ 区间，这是 SSM 数值稳定性的基础。更多关于数值稳定性的讨论见 [[CTM - Mamba and S6 SSM §1.4]]。

---

## 7. 演进路线：从 RNN 到 Mamba-2

```
普通 RNN (1986)
→ LSTM (1997): 门控 + 加法细胞状态，缓解梯度消失
→ GRU (2014): 简化 LSTM，合并遗忘门和输入门
→ Transformer (2017): 自注意力 + 完全并行，O(T^2) 复杂度
→ S4 (2022): 结构化状态空间模型，引入 HiPPO 初始化
→ Mamba-1 (2023): 选择性 SSM (S6) + 硬件高效并行扫描
→ Mamba-2 (2024): SSD (State Space Dual) 架构
```

### S4 (2022)

S4 首次将经典 SSM 引入深度学习序列建模，核心创新是 **HiPPO 初始化**——使用 Legendre 多项式构建状态矩阵 $A$，使 SSM 能记住长程历史。S4 仍然是 LTI 系统，无法进行内容感知的选择性处理。

### Mamba-1 (2023, S6)

Mamba 的关键创新：
1. **选择性机制**：$A, B, C$ 变为输入相关，打破 LTI 限制
2. **硬件高效扫描**：通过 parallel associative scan 实现 $O(T \log T)$ 的并行训练
3. **宽度/深度解耦**：$d_{\text{model}} \times d_{\text{state}}$ 双维度设计

详见 [[CTM - Mamba and S6 SSM]] 对 S6 的完整论述。

### Mamba-2 (2024, SSD)

| 维度 | Mamba-1 (S6) | Mamba-2 (SSD) |
|------|-------------|---------------|
| **SSM 类型** | 标量 SSM（每通道独立标量 $A$）| 矩阵 SSM（多通道共享矩阵 $A$）|
| **并行策略** | 并行关联扫描 | 矩阵乘法 + 分块关联扫描 |
| **训练速度** | 1x | 2-8x 更快 |
| **与 Attention 关系** | 功能等价 | 结构等价（SSD 是 Attention 的特例）|
| **参数量** | 少（标量 $A$）| 略多（矩阵 $A$）|
| **长程能力** | 受限于 $d_{\text{state}}$ | 更强的长程建模能力 |

**SSD (State Space Dual)** 的核心洞察：选择性 SSM 的数学形式与**线性注意力** (Linear Attention) 存在对偶关系。将 SSM 的递推形式重写为矩阵乘法形式：

$$y = (M \odot (B \cdot x)) \cdot C^T$$

其中 $M$ 是掩码矩阵，$M_{ij} = \prod_{k=j+1}^i \bar{A}_k$。当 $\bar{A}$ 为标量时，$M$ 是**半可分矩阵** (semiseparable matrix)，其矩阵乘法可以使用特殊的硬件高效算法计算。

> [!note] Mamba-2 与 Attention 的等价性
> SSD 证明 SSM 和 Attention 不是互斥的架构——它们是对偶的。当 $A=0$ 时，SSM 退化为线性层的组合；当 $A$ 为特定结构时，SSM 等价于某种形式的注意力。这个发现统一了两条看似独立的模型演进路线。

---

## 8. Key Takeaways

### Mamba 系列的演进逻辑

从 RNN 到 Mamba-2，核心趋势是：

1. **从 LTI 到时变**：固定权重到输入依赖的选择性
2. **并行性递增**：顺序 RNN 到并行 Mamba
3. **表达力与效率的平衡**：Mamba-1 用标量 SSM 追求轻量，Mamba-2 用矩阵 SSM 追求更强表达力

### 何时选择 Mamba

- **长序列**：序列长度大于 1024 时，$O(T)$ SSM 优于 $O(T^2)$ Transformer
- **推理效率优先**：Mamba 的推理递推比自注意力更省显存
- **参数受限场景**：$d_{\text{state}}$ 可以独立控制而无需增加主要参数量

### 何时选择替代方案

| 替代方案 | 优势 | 劣势 |
|---------|------|------|
| **Transformer** | 擅长中等长度序列，生态丰富 | $O(T^2)$ 复杂度，长序列不可行 |
| **LSTM** | 实现简单，生态成熟 | 无法并行训练，长程能力差 |
| **RWKV** | RNN 推理 + Transformer 训练 | 表达力仍不如 Mamba |

### 进一步阅读

- [[CTM - Mamba and S6 SSM]] — S6 选择性 SSM 的理论细节与 CTM 实现
- [[Neural Network]] — 神经网络基础（激活函数、FFN 结构）
- Gu & Dao, *Mamba: Linear-Time Sequence Modeling with Selective State Spaces* (2023)
- Dao & Gu, *Transformers are SSMs: Generalized Models and Efficient Algorithms Through Structured State Space Duality* (2024) — Mamba-2 / SSD 论文
- Gu, Goel, Re, *Efficiently Modeling Long Sequences with Structured State Spaces* (2022) — S4 论文
