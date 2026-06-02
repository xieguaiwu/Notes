---
tags:
  - Math
  - LinearAlgebra
  - 方法性
title: Linear Systems and Gaussian Elimination
created: 2026-05-20
modified:
---

# Linear Systems and Gaussian Elimination

## 1. 核心概念：一句话概括

**线性方程组**是一组形如 $a_1x_1 + a_2x_2 + \cdots + a_nx_n = b$ 的方程集合，而**高斯消元法**是求解这类方程组最基础、最通用的系统性方法——通过"消去变量"将方程组化为最简形式，直接读出解。

## 2. 线性方程组的矩阵表示

一个 $m$ 个方程、$n$ 个未知数的线性方程组：

$$
\begin{cases}
a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\
a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\
\quad\vdots \\
a_{m1}x_1 + a_{m2}x_2 + \cdots + a_{mn}x_n = b_m
\end{cases}
$$

可以紧凑地写成矩阵形式：

$$
\mathbf{A}\mathbf{x} = \mathbf{b}, \quad
\mathbf{A} = \begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{bmatrix},\;
\mathbf{x} = \begin{bmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{bmatrix},\;
\mathbf{b} = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_m \end{bmatrix}
$$

### 增广矩阵（Augmented Matrix）

将系数矩阵 $\mathbf{A}$ 和右侧向量 $\mathbf{b}$ 合并为一个矩阵：

$$
[\mathbf{A} \mid \mathbf{b}] = \left[\begin{array}{cccc|c}
a_{11} & a_{12} & \cdots & a_{1n} & b_1 \\
a_{21} & a_{22} & \cdots & a_{2n} & b_2 \\
\vdots & \vdots & \ddots & \vdots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn} & b_m
\end{array}\right]
$$

增广矩阵是高斯消元的操作对象——对矩阵的行进行操作，等价于对方程组做合法变换。关于增广矩阵的定义、多右侧向量的推广、以及求逆中的应用，详见 [[Augmented Matrix]]。

> [!note] 与已有笔记的联系
> [[Matrix Operations]] 中介绍了矩阵的基础运算。这里我们把矩阵用到了"求解方程组"这一具体场景中——系数矩阵 $\mathbf{A}$ 和向量 $\mathbf{b}$ 拼接，就是增广矩阵。

## 3. 初等行变换（Elementary Row Operations）

三种基本操作，保持方程组的解不变：

| 操作 | 数学含义 | 矩阵记号 |
|------|---------|---------|
| **交换两行** | 交换两个方程的位置 | $R_i \leftrightarrow R_j$ |
| **某行乘以非零常数** | 方程两边同乘非零数 | $R_i \to kR_i$ |
| **某行加另一行的倍数** | 一个方程加上另一个方程的倍数 | $R_i \to R_i + kR_j$ |

> [!tip] 核心思想
> 这三种操作都是**可逆**的——不会丢失也不引入新的解。因此用它们化简方程组，解集不变。
>
> 每种行变换都对应一个**初等矩阵**的左乘，详见 [[Row Operations and Elementary Matrices]]。

## 4. 行阶梯形与行最简形

消元的目标是将增广矩阵化为两种标准形式：

### 4.1 行阶梯形（Row Echelon Form, REF）

满足以下条件的矩阵：
1. 所有非零行在零行之上
2. 每一行的首个非零元素（**主元，pivot**）所在的列，在其下方的所有行中都是 0

形状像"楼梯"：

$$
\begin{bmatrix}
\boxed{1} & 2 & 3 & 4 \\
0 & \boxed{5} & 6 & 7 \\
0 & 0 & 0 & \boxed{8} \\
0 & 0 & 0 & 0
\end{bmatrix}
$$

$\boxed{\text{方框}}$ 处即主元位置。矩阵中主元的个数就是 [[Rank and Nullity]] 中定义的**秩**。

### 4.2 行最简形（Reduced Row Echelon Form, RREF）

在 REF 基础上进一步：
1. 主元必须为 **1**
2. 主元所在列的其他元素全为 **0**

$$
\begin{bmatrix}
\boxed{1} & 0 & 0 & 4 \\
0 & \boxed{1} & 0 & 7 \\
0 & 0 & \boxed{1} & 8 \\
0 & 0 & 0 & 0
\end{bmatrix}
$$

> [!note] 唯一性
> RREF 是**唯一**的——无论消元步骤如何，同一矩阵的 RREF 形式相同。REF 不唯一。

## 5. 高斯消元法

### 5.1 算法步骤

```
输入：增广矩阵 [A | b]

1. 从最左列开始，找到第一个非零且未处理的列 → 主元列
2. 将该列中绝对值最大的行交换到当前位置（部分主元法）
3. 用主元行消去下方所有行的该列元素
4. 重复直到矩阵变为 REF
5. 回代求解（或继续化简到 RREF → 高斯-若尔当消元）
```

### 5.2 具体例子

解方程组：

$$
\begin{cases}
x + 2y + z = 2 \\
2x + 4y + 2z = 4 \\
3x + y + 2z = 1
\end{cases}
$$

**Step 1: 写出增广矩阵**

$$
\left[\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
2 & 4 & 2 & 4 \\
3 & 1 & 2 & 1
\end{array}\right]
$$

**Step 2: 消去第一列**

$R_2 \to R_2 - 2R_1$，$R_3 \to R_3 - 3R_1$：

$$
\left[\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
0 & 0 & 0 & 0 \\
0 & -5 & -1 & -5
\end{array}\right]
$$

**Step 3: 交换行得到 REF**

$R_2 \leftrightarrow R_3$：

$$
\left[\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
0 & -5 & -1 & -5 \\
0 & 0 & 0 & 0
\end{array}\right]
$$

**Step 4: 化简为 RREF**

$R_2 \to -\frac{1}{5}R_2$：

$$
\left[\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
0 & 1 & \frac{1}{5} & 1 \\
0 & 0 & 0 & 0
\end{array}\right]
$$

$R_1 \to R_1 - 2R_2$：

$$
\left[\begin{array}{ccc|c}
1 & 0 & \frac{3}{5} & 0 \\
0 & 1 & \frac{1}{5} & 1 \\
0 & 0 & 0 & 0
\end{array}\right]
$$

**Step 5: 读出解**

RREF 对应：

$$
\begin{cases}
x + \frac{3}{5}z = 0 \\
y + \frac{1}{5}z = 1
\end{cases}
\Longrightarrow
\begin{cases}
x = -\frac{3}{5}z \\
y = 1 - \frac{1}{5}z
\end{cases}
$$

$z$ 是**自由变量**（free variable），解为无穷多组（一条直线）。

> [!tip] 联系 [[Vector Spaces and Subspaces]]
> 所有解构成的集合 $\{(-\frac{3}{5}t,\; 1-\frac{1}{5}t,\; t)\}$ 是一个仿射子空间（平移后的子空间），其中自由变量 $z$ 对应一个维度。

## 6. 解的分类

| 增广矩阵 RREF 形态 | 解的情况 |
|-------------------|---------|
| 无 $[0\;0\;\cdots\;0 \mid 1]$ 行 | **有解** |
| 有 $[0\;0\;\cdots\;0 \mid 1]$ 行 | **无解**（矛盾方程组） |
| 有解 + **所有列都有主元** | **唯一解** |
| 有解 + **存在自由变量**（非主元列） | **无穷多解** |

### 直观理解

- **唯一解**：$n$ 个独立方程约束 $n$ 个未知数，交点唯一
- **无穷多解**：方程不足或存在冗余（[[Rank and Nullity]] 中秩 < 列数）
- **无解**：方程互相矛盾（如 $x=1$ 且 $x=2$）

## 7. 高斯-若尔当消元（Gauss-Jordan Elimination）

高斯消元到 REF 后用**回代**求解；高斯-若尔当则继续化简到 RREF **直接读出解**。

> 两者本质相同，停止点不同。高斯-若尔当更系统化（适合计算机实现），普通高斯消元手算更快。

## 8. 齐次方程组 $\mathbf{A}\mathbf{x} = \mathbf{0}$

- **总有零解** $\mathbf{x} = \mathbf{0}$（平凡解）
- 有非零解 $\iff$ $\text{rank}(\mathbf{A}) < n$（有自由变量）
- 解集是 $\mathbb{R}^n$ 的**子空间**（见 [[Vector Spaces and Subspaces]]）——即 $\mathbf{A}$ 的零空间

## 9. 数值稳定性：部分主元法

使用浮点数运算时，若主元很小会导致严重数值误差。**部分主元法**在每列中选择绝对值最大的元素作为主元。这是所有专业数值库（LAPACK、NumPy）的默认做法。

## 10. 在 NumPy 中的体现

```python
import numpy as np

# 唯一解的情况
A = np.array([[1, 2], [3, 4]], dtype=float)
b = np.array([5, 6], dtype=float)
x = np.linalg.solve(A, b)
print(f"唯一解: {x}")

# 无穷多解 / 无解的情况 → 最小二乘解
A2 = np.array([[1, 2, 1],
               [2, 4, 2],
               [3, 1, 2]], dtype=float)
b2 = np.array([2, 4, 1], dtype=float)

# lstsq 返回最小二乘解
x_lstsq, residuals, rank, s = np.linalg.lstsq(A2, b2, rcond=None)
print(f"最小二乘解: {x_lstsq}")
print(f"矩阵的秩: {rank}")

# 齐次方程组 A x = 0 的非零解（通过 SVD）
U, s, Vt = np.linalg.svd(A2)
null_vector = Vt[-1]  # 对应最小奇异值的右奇异向量
print(f"A x = 0 的一个解: {null_vector}")
print(f"验证 A @ null_vector ≈ 0: {np.allclose(A2 @ null_vector, np.zeros(3))}")
```

## 相关链接
- [[Matrix Operations]]（矩阵基础运算）
- [[Vector and Matrix]]（矩阵乘向量的形式）
- [[Rank and Nullity]]（秩与自由变量的关系）
- [[Vector Spaces and Subspaces]]（解空间与零空间）
- [[Linear Transformations]]（线性方程组的变换视角）
