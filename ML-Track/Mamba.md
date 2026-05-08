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
modified:
---
# Mamba

Selective State Space Model（选择性状态空间模型）。Gu & Dao, 2023。

## 1. 核心理念

从 RNN 到 SSM：Mamba 的核心是一个**线性时变系统**：

$$h_t = \bar{A}_t \odot h_{t-1} + \bar{B}_t \cdot x_t$$

$$y_t = C_t \cdot h_t + D \odot x_t$$

其中 $\bar{A}_t, \bar{B}_t, C_t$ 都是从当前输入 $x_t$ **实时计算**的——这就是 **Selective（选择性）** 的含义：模型根据输入内容决定如何传播和遗忘信息。

## 2. 解耦：宽度 × 深度

Mamba 将隐藏状态拆分为两个独立的维度管理：

- $d_{\text{model}}$：通道数（特征类型数），增加它参数量增长 $O(d_{\text{model}}^2)$
- $d_{\text{state}}$：每通道记忆深度，增加它只影响两个小投影矩阵

**对比 LSTM**：LSTM 的状态是单一向量 $h \in \mathbb{R}^{d_h}$，宽度和深度耦合在同一个维度，增加记忆容量必然 $O(d_h^2)$ 增参。

## 3. Mamba 块结构

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

## 4. 参数表

| 参数 | 维度 | 说明 |
|------|------|------|
| $W_{\text{in}}$ | $(2\cdot d_{\text{model}}) \times d_x$ | 输入投影（2× 用于门控） |
| $W_{\text{conv}}$ | $d_{\text{model}} \times d_{\text{conv}}$ | 因果 1D 卷积核 |
| $b_{\text{conv}}$ | $d_{\text{model}} \times 1$ | 卷积偏置 |
| $A_{\text{log}}$ | $d_{\text{model}} \times 1$ | $\log(-A)$，$A = -\exp(A_{\text{log}})$ |
| $D$ | $d_{\text{model}} \times 1$ | 跳跃连接 |
| $W_{\Delta}$ | $d_{\text{model}} \times d_{\text{model}}$ | Δ 投影 |
| $b_{\Delta}$ | $d_{\text{model}} \times 1$ | Δ 偏置 |
| $W_B$ | $d_{\text{state}} \times d_{\text{model}}$ | B 投影 |
| $W_C$ | $d_{\text{state}} \times d_{\text{model}}$ | C 投影 |
| $W_{\text{out}}$ | $d_y \times d_{\text{model}}$ | 输出投影 |

## 5. Selective（选择性）的数学含义

选择性体现在三个参数从输入实时计算：

- **Δ**: 步长参数（离散化分辨率）。$\Delta$ 大 → 记住更多；$\Delta$ 小 → 忽略/滤除
- **B**: 输入投影矩阵。决定从输入中选择哪些信息进入状态
- **C**: 输出投影矩阵。决定从状态中选择哪些信息读出

这与 LSTM 的遗忘/输入/输出门功能等价，但数学形式不同、参数更少。

## 6. 离散化细节

连续 SSM：$\dot{h}(t) = A h(t) + B x(t)$

零阶保持离散化（ZOH）：
- $\bar{A} = \exp(\Delta A)$
- $\bar{B} = \int_0^\Delta e^{A(\Delta - \tau)} B d\tau \approx \Delta B$（简化近似）

$A$ 初始化为负值（$A_{\text{log}} = -1 \implies A \approx -0.368$），确保 $|\bar{A}| < 1$，状态不爆炸。

## 7. Mamba vs LSTM

| 维度 | LSTM | Mamba |
|------|------|-------|
| **时序建模** | 4 个门控网络 | 1 个 SSM 递推 + 门控 |
| **状态** | $h_t \in \mathbb{R}^{d_h}$ | $h_t \in \mathbb{R}^{d_{\text{model}} \times d_{\text{state}}}$ |
| **门控激活** | sigmoid（静态权重） | SiLU + 输入依赖选择 |
| **参数量** | $O(d_h^2)$ | $O(d_{\text{model}}^2 + d_{\text{model}} \cdot d_{\text{state}})$ |
| **训练并行度** | 无 | 可并行（关联扫描） |
| **推理速度** | $O(T)$ 顺序 | $O(T)$ 顺序（极小常数） |
| **长程依赖** | 加法路径缓解 | 选择性遗忘 + 小 $d_{\text{state}}$ |
| **内容自适应** | 无（权重固定） | 有（Δ, B, C 取决于 $x$） |

## 8. 反向传播要点

Mamba 反向传播比 LSTM 复杂，梯度通过**选择性扫描递推路径**和**输入依赖参数化路径**同时流动。

### 8.1 输出梯度

$$\frac{\partial L}{\partial o_t^{\text{out}}} = \hat{y}_t - \mathbf{1}_{y_t}$$

### 8.2 门控

$$\frac{\partial L}{\partial y_{\text{ssm},t}} = \frac{\partial L}{\partial y_t} \odot \text{SiLU}(z_2)$$

### 8.3 SSM 递推

$$\frac{\partial L}{\partial h_{t-1}} += \frac{\partial L}{\partial h_t} \odot \bar{A}_t$$

### 8.4 离散化

$$\frac{\partial L}{\partial \Delta_t} = \frac{\partial L}{\partial \bar{A}_t} \odot \bar{A}_t \odot A + \frac{\partial L}{\partial \bar{B}_t} \odot B_t^T$$

### 8.5 输入梯度

通过 $\Delta_t, B_t, C_t$ 的三个投影传回卷积输出，再通过因果卷积的反向传播传到 $z_1$，最终与 $z_2$ 的梯度合并传到 $W_{\text{in}}$。

## 9. 权重初始化

- Xavier 初始化：$W_{\text{in}}, W_{\text{conv}}, W_{\Delta}, W_B, W_C, W_{\text{out}}$
- $A_{\text{log}} = -1$：$A = -e^{-1} \approx -0.368$
- $D = 0$：跳跃连接初始为零
- $b_{\Delta}$：初始化为小的正值（如 0.001）
- $b_{\text{conv}}$：初始化为零

## 10. 演进路线

```
普通 RNN (1986)
→ LSTM (1997): 门控+加法细胞状态
→ GRU (2014): 简化版 LSTM
→ Transformer (2017): 自注意力+完全并行
→ S4 (2022): 结构化状态空间模型
→ Mamba (2023): 选择性 SSM + 硬件高效扫描
→ Mamba-2 (2024): SSD 架构，更高效并行
```
