---
tags:
  - Math
  - LinearAlgebra
  - 定义性
title: Augmented Matrix
created: 2026-06-02
modified:
---

# Augmented Matrix

> [!abstract] 概述
> **增广矩阵**（Augmented Matrix）是将线性方程组的系数矩阵与右侧常数向量（或多个向量）拼接而成的矩阵。它将"多个方程"的信息压缩为**一个矩阵**，使高斯消元等操作可以统一作用于整个矩阵而无需每次单独处理等号右侧。

## 1. 核心定义

对于一个 $m$ 个方程、$n$ 个未知数的线性方程组：

$$
\begin{cases}
a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\
a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\
\quad\vdots \\
a_{m1}x_1 + a_{m2}x_2 + \cdots + a_{mn}x_n = b_m
\end{cases}
$$

其增广矩阵为：

$$
[\mathbf{A} \mid \mathbf{b}] =
\left[\begin{array}{cccc|c}
a_{11} & a_{12} & \cdots & a_{1n} & b_1 \\
a_{21} & a_{22} & \cdots & a_{2n} & b_2 \\
\vdots & \vdots & \ddots & \vdots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn} & b_m
\end{array}\right]
$$

其中竖线 `|` 不是数学运算符，而是**视觉分隔符**——标识等号的位置。在形式化表述中，增广矩阵写作 $(\mathbf{A} \mid \mathbf{b})$。

> [!note] 与分块矩阵的关系
> 增广矩阵可以看作分块矩阵 $[\mathbf{A} \ \mathbf{b}]$（即矩阵 $\mathbf{A}$ 后拼接列向量 $\mathbf{b}$）。竖线只是为了强调左侧是系数、右侧是常数。

## 2. 为什么要"增广"？

理由一：**简化操作**——对增广矩阵做行变换 = 同时变换方程两侧，无需分别处理。

理由二：**统一视角**——把"一组方程"看作一个数学对象，而非多个独立方程。

| | 单独处理方程组 | 用增广矩阵 |
|--|--------------|-----------|
| 操作对象 | 多个方程 + 等号 | 一个矩阵 |
| 行变换 | 分别写每个方程 | 对矩阵的一行操作即可 |
| 出错概率 | 容易遗漏或抄错 | 集中在一张表上 |
| 视觉清晰度 | 方程越多越混乱 | 结构规整 |

## 3. 增广矩阵的两种经典用法

### 3.1 求解线性方程组 $[ \mathbf{A} \mid \mathbf{b} ]$

对增广矩阵施加行变换到 REF 或 RREF，然后直接读出解。

**例子**：

$$
\begin{cases}
x + y = 3 \\
2x + 3y = 7
\end{cases}
\Longrightarrow
\left[\begin{array}{cc|c}
1 & 1 & 3 \\
2 & 3 & 7
\end{array}\right]
$$

$R_2 \to R_2 - 2R_1$：

$$
\left[\begin{array}{cc|c}
1 & 1 & 3 \\
0 & 1 & 1
\end{array}\right]
$$

$R_1 \to R_1 - R_2$：

$$
\left[\begin{array}{cc|c}
1 & 0 & 2 \\
0 & 1 & 1
\end{array}\right]
\quad\Longrightarrow\quad
\begin{cases}
x = 2 \\
y = 1
\end{cases}
$$

整个过程中，竖线右侧的"3"和"7"随行变换同步更新——这正是增广的意义。

> 详见 [[Linear Systems and Gaussian Elimination]]。

### 3.2 求逆矩阵 $[ \mathbf{A} \mid \mathbf{I} ]$

将系数矩阵 $\mathbf{A}$ 与同阶单位矩阵 $\mathbf{I}$ 拼接，通过行变换将左侧化为 $\mathbf{I}$，右侧即得 $\mathbf{A}^{-1}$。

**例子**：求 $\mathbf{A} = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$ 的逆。

$$
\left[\begin{array}{cc|cc}
1 & 2 & 1 & 0 \\
3 & 4 & 0 & 1
\end{array}\right]
\xrightarrow{R_2 \to R_2 - 3R_1}
\left[\begin{array}{cc|cc}
1 & 2 & 1 & 0 \\
0 & -2 & -3 & 1
\end{array}\right]
$$

$$
\xrightarrow{R_2 \to -\frac12 R_2}
\left[\begin{array}{cc|cc}
1 & 2 & 1 & 0 \\
0 & 1 & \frac32 & -\frac12
\end{array}\right]
\xrightarrow{R_1 \to R_1 - 2R_2}
\left[\begin{array}{cc|cc}
1 & 0 & -2 & 1 \\
0 & 1 & \frac32 & -\frac12
\end{array}\right]
$$

右侧矩阵即为 $\mathbf{A}^{-1} = \begin{bmatrix} -2 & 1 \\ \frac32 & -\frac12 \end{bmatrix}$。

> 详见 [[Matrix Inverse#2 方法一 高斯-若尔当消元法 Gauss-Jordan Elimination]]。

这两种用法共享同一核心思想：**将两个矩阵并排放置，对它们同步施加相同的行变换**。

## 4. 多右侧向量的增广矩阵

只要行数匹配，右侧可以拼接任意多个列向量。这在同时求解多个线性系统（同一系数矩阵 $\mathbf{A}$，不同右侧 $\mathbf{b}_1, \mathbf{b}_2, \dots$）时极其有用。

$$
\left[\ \mathbf{A} \ \middle| \ \mathbf{b}_1 \ \mathbf{b}_2 \ \cdots \ \mathbf{b}_k \ \right]
$$

**例子**：同时求解 $\mathbf{A}\mathbf{x} = \mathbf{b}_1$ 和 $\mathbf{A}\mathbf{x} = \mathbf{b}_2$：

$$
\mathbf{A} = \begin{bmatrix} 1 & 0 \\ 0 & 2 \end{bmatrix},\quad
\mathbf{b}_1 = \begin{bmatrix} 3 \\ 4 \end{bmatrix},\quad
\mathbf{b}_2 = \begin{bmatrix} 1 \\ 2 \end{bmatrix}
$$

$$
\left[\begin{array}{cc|cc}
1 & 0 & 3 & 1 \\
0 & 2 & 4 & 2
\end{array}\right]
\xrightarrow{R_2 \to \frac12 R_2}
\left[\begin{array}{cc|cc}
1 & 0 & 3 & 1 \\
0 & 1 & 2 & 1
\end{array}\right]
$$

解为 $\mathbf{x}_1 = \begin{bmatrix}3\\2\end{bmatrix}$，$\mathbf{x}_2 = \begin{bmatrix}1\\1\end{bmatrix}$。

> [!tip] 求逆的推广视角
> $[\mathbf{A} \mid \mathbf{I}]$ 就是多右侧的特殊情况——同时求解 $\mathbf{A}\mathbf{x} = \mathbf{e}_1,\ \mathbf{A}\mathbf{x} = \mathbf{e}_2,\ \dots,\ \mathbf{A}\mathbf{x} = \mathbf{e}_n$，其中 $\mathbf{e}_i$ 是标准基向量。所有解拼在一起就是 $\mathbf{A}^{-1}$。

## 5. 矩阵形式 vs 方程组形式的对比

| | 方程组形式 | 增广矩阵形式 |
|--|----------|-------------|
| 表达 | $x + y = 3,\ 2x + 3y = 7$ | $\begin{bmatrix}1&1&3\\2&3&7\end{bmatrix}$ |
| $R_2 \to R_2 - 2R_1$ | $2x+3y=7$ 变为 $y=1$ | 第二行从 `[2 3 7]` 变为 `[0 1 1]` |
| 回代 | 需将结果代入原方程 | RREF 直接读出 |
| 信息密度 | 低 | 高（紧凑、系统化） |
| 适合编程 | 否 | 是（二维数组） |

## 6. 在 Python 中的体现

```python
import numpy as np

# 构建增广矩阵 [A | b]
A = np.array([[1, 2], [3, 4]], dtype=float)
b = np.array([5, 6], dtype=float)
aug = np.column_stack([A, b])  # 或 np.hstack([A, b.reshape(-1, 1)])
print("增广矩阵 [A | b]:\n", aug)

# 多右侧：同时 [A | b1 b2]
b1 = np.array([1, 2], dtype=float)
b2 = np.array([3, 4], dtype=float)
aug_multi = np.column_stack([A, b1, b2])
print("\n多右侧增广矩阵 [A | b1 b2]:\n", aug_multi)

# 求逆矩阵的增广矩阵 [A | I]
I = np.eye(2)
aug_inv = np.column_stack([A, I])
print("\n求逆增广矩阵 [A | I]:\n", aug_inv)
```

## 相关链接

- [[Linear Systems and Gaussian Elimination]]（增广矩阵在高斯消元中的应用）
- [[Matrix Inverse]]（增广矩阵在求逆中的应用：$[\mathbf{A} \mid \mathbf{I}] \to [\mathbf{I} \mid \mathbf{A}^{-1}]$）
- [[Row Operations and Elementary Matrices]]（行变换是增广矩阵的操作基础）
- [[Matrix Operations]]（矩阵拼接与分块操作）
