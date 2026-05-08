---
tags:
  - Architecture
  - SequenceModel
  - ComputerScience
  - 定义性
  - MachineLearning
  - Math
  - LinearAlgebra
title: LSTM
created: 2026-05-08
modified:
---
# LSTM

Long Short-Term Memory（长短期记忆网络）。Hochreiter & Schmidhuber, 1997。

## 1. 核心创新：门控 + 加法细胞状态

解决 RNN 梯度消失的关键：引入**细胞状态** $C_t$ 作为信息高速公路，梯度可以沿 $C_{t-1} \to C_t$ 几乎无损传递。

## 2. 参数表

| 参数 | 维度 | 作用 |
|------|------|------|
| $W_f$ | $d_h \times (d_h + d_x)$ | 遗忘门权重 |
| $W_i$ | $d_h \times (d_h + d_x)$ | 输入门权重 |
| $W_C$ | $d_h \times (d_h + d_x)$ | 候选记忆权重 |
| $W_o$ | $d_h \times (d_h + d_x)$ | 输出门权重 |
| $W_{hy}$ | $d_y \times d_h$ | 输出权重 |
| $b_f, b_i, b_C, b_o$ | $d_h \times 1$ | 四个门控偏置 |
| $b_y$ | $d_y \times 1$ | 输出偏置 |

各门权重列数为 $d_h + d_x$，因为输入是拼接向量 $[h_{t-1}; x_t]$。

## 3. 前向传播

给定 $x_t$，上一状态 $h_{t-1}, C_{t-1}$：

### 3.1 四个门

| 门 | 公式 | 激活 | 作用 |
|---|------|------|------|
| 遗忘门 | $f_t = \sigma(W_f [h_{t-1}; x_t] + b_f)$ | sigmoid | 保留多少旧记忆 |
| 输入门 | $i_t = \sigma(W_i [h_{t-1}; x_t] + b_i)$ | sigmoid | 接受多少新信息 |
| 候选记忆 | $\tilde{C}_t = \tanh(W_C [h_{t-1}; x_t] + b_C)$ | tanh | 生成候选新值 |
| 输出门 | $o_t = \sigma(W_o [h_{t-1}; x_t] + b_o)$ | sigmoid | 输出多少信息 |

### 3.2 状态更新

$$C_t = f_t \odot C_{t-1} + i_t \odot \tilde{C}_t$$

$$h_t = o_t \odot \tanh(C_t)$$

$$\hat{y}_t = \text{softmax}(W_{hy} h_t + b_y)$$

### 3.3 直觉

- **遗忘门**决定从 $C_{t-1}$ 中丢弃什么。$f_t$ 接近 0 表示"忘掉"，接近 1 表示"保留"
- **输入门**决定新信息如何写入。$i_t$ 控制写入量，$\tilde{C}_t$ 控制写入内容
- $C_t = f_t \odot C_{t-1} + i_t \odot \tilde{C}_t$：**加法更新**，这是核心
- **输出门**决定 $C_t$ 中哪些信息暴露为 $h_t$

## 4. 为什么解决梯度消失

$$\frac{\partial C_t}{\partial C_{t-1}} = f_t$$

这是一个**逐元素乘法**（Hadamard 积），没有权重矩阵的连乘。RNN 中 $\frac{\partial h_t}{\partial h_{t-1}}$ 包含 $W_{hh}$ 的连乘（必然衰减或爆炸），而 LSTM 中梯度沿 $C_{t-1} \to C_t$ 传递时只乘 $f_t \in [0,1]$。

只要 $f_t$ 不趋近零，梯度就能无损传递。

## 5. 反向传播

关键步骤（从时间步 T 倒推）：

### 5.1 输出层梯度

$$\frac{\partial L}{\partial o_t^{\text{out}}} = \hat{y}_t - \mathbf{1}_{y_t}$$

### 5.2 隐藏状态梯度

$$\frac{\partial L}{\partial h_t} = W_{hy}^T \frac{\partial L}{\partial o_t^{\text{out}}} + \frac{\partial L}{\partial h_t}\big|_{\text{from } t+1}$$

### 5.3 细胞状态梯度

$$\frac{\partial L}{\partial C_t} = \frac{\partial L}{\partial h_t} \odot o_t \odot (1 - \tanh^2(C_t)) + \frac{\partial L}{\partial C_{t+1}} \odot f_{t+1}$$

### 5.4 门梯度

$$\frac{\partial L}{\partial f_t} = \frac{\partial L}{\partial C_t} \odot C_{t-1}$$
$$\frac{\partial L}{\partial i_t} = \frac{\partial L}{\partial C_t} \odot \tilde{C}_t$$
$$\frac{\partial L}{\partial \tilde{C}_t} = \frac{\partial L}{\partial C_t} \odot i_t$$

### 5.5 参数梯度（累积所有时间步）

$$\frac{\partial L}{\partial W_f} = \sum_{t=1}^{T} \delta f_t \cdot a_t^T, \quad a_t = [h_{t-1}; x_t]$$

## 6. 权重初始化

- **Xavier 初始化**：$W_{ij} \sim \mathcal{N}(0, \sqrt{2/(n_{\text{in}} + n_{\text{out}})})$
- **$b_f = 1.0$**：遗忘门偏置初始化为 1（非 0），使 $f_t \approx 1$，默认记住过去
- 其余偏置初始化为 0

## 7. 遗留问题

1. **不能并行训练**——严格时序依赖，$h_t$ 依赖 $h_{t-1}$
2. **参数量大**——$O(d_h^2)$，4 个门+1 个输出
3. **推理效率低**——每个时间步依赖前一步结果
4. **遗忘门退化**——如果 $b_f$ 训练到很大正值，$f_t \approx 1$，模型"忘记如何遗忘"

## 8. 变体

- **GRU**：合并遗忘门和输入门为更新门，去掉细胞状态，参数更少
- **Peephole LSTM**：门控可以"偷看"细胞状态
- **双向 LSTM**：前向+后向，隐藏状态拼接
- **Stacked LSTM**：多层堆叠，上层输出是下层输入
