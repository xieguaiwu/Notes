---
tags:
  - MachineLearning
  - Architecture
  - SequenceModel
  - Math
  - LinearAlgebra
  - 定义性
title: Vanilla RNN
created: 2026-05-08
modified:
---
# Vanilla RNN

循环神经网络（Recurrent Neural Network），序列建模的起点。

## 1. 核心公式

每个时间步维护一个隐藏状态 $h_t$，用当前输入 $x_t$ 和上一步状态 $h_{t-1}$ 更新：

$$h_t = \tanh(W_{hh} h_{t-1} + W_{xh} x_t + b_h)$$

输出：

$$\hat{y}_t = \text{softmax}(W_{hy} h_t + b_y)$$

## 2. 参数表

| 参数 | 维度 | 说明 |
|------|------|------|
| $W_{hh}$ | $d_h \times d_h$ | 状态-状态权重 |
| $W_{xh}$ | $d_h \times d_x$ | 输入-状态权重 |
| $b_h$ | $d_h \times 1$ | 隐藏状态偏置 |
| $W_{hy}$ | $d_y \times d_h$ | 输出权重 |
| $b_y$ | $d_y \times 1$ | 输出偏置 |

## 3. 三大缺陷

### 3.1 梯度消失

长程依赖的梯度随时间步指数级衰减：

$$\frac{\partial h_t}{\partial h_{t-k}} = \prod_{i=1}^{k} \operatorname{diag}\bigl(\tanh'(z_{t-i+1})\bigr) \cdot W_{hh}$$

当 $W_{hh}$ 特征值小于 1 时，连乘指数衰减至零，模型无法学习超过 ~10 步的依赖。

### 3.2 梯度爆炸

当 $W_{hh}$ 特征值大于 1 时，梯度指数级增长，导致 NaN 或训练发散。

解法：梯度裁剪 $\text{grad}_i \leftarrow \min(|\text{grad}_i|, c) \cdot \operatorname{sign}(\text{grad}_i)$

### 3.3 并行困难

$$h_t = f(h_{t-1}, x_t)$$

严格时序依赖：计算 $h_t$ 必须等 $h_{t-1}$ 算完。训练时无法在序列维度上并行。

## 4. BPTT

核心逻辑：前向传播保存所有 $h_t$，反向传播从 $T$ 到 $1$ 倒推。

$$\frac{\partial L}{\partial h_t} = W_{hy}^T \frac{\partial L}{\partial o_t^{\text{out}}} + W_{hh}^T \frac{\partial L}{\partial h_{t+1}} \odot \tanh'(z_{t+1})$$

参数梯度累积所有时间步：

$$\frac{\partial L}{\partial W_{hh}} = \sum_{t=1}^{T} \frac{\partial L}{\partial h_t} \odot \tanh'(z_t) \cdot h_{t-1}^T$$

## 5. 应用场景

已被 LSTM/GRU 完全替代。仅在极简单的基线比较中出现。

## 6. 变体

- **GRU（Gated Recurrent Unit）**：简化版 LSTM，只有重置门和更新门，无独立细胞状态
- **双向 RNN**：前向 + 后向两个 RNN，隐藏状态拼接
- **深度 RNN**：多层 RNN 堆叠
