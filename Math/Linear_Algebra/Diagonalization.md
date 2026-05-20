---
tags:
  - Math
  - LinearAlgebra
  - 方法性
title: Diagonalization
created: 2026-05-20
modified:
---

# Diagonalization

## 1. 核心概念：一句话概括

**对角化**（Diagonalization）是将一个方阵 $\mathbf{A}$ 分解为 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$ 的形式，其中 $\mathbf{D}$ 是对角矩阵（非对角元全为 0）。这种分解能极大简化矩阵乘方、求解微分方程等计算——因为对角矩阵的运算极其简单。

## 2. 对角化的定义

$n \times n$ 矩阵 $\mathbf{A}$ **可对角化**（diagonalizable），如果存在可逆矩阵 $\mathbf{P}$ 和对角矩阵 $\mathbf{D}$ 使得：

$$
\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}
$$

等价地：

$$
\mathbf{P}^{-1}\mathbf{A}\mathbf{P} = \mathbf{D}
$$

> [!note] 相似变换
> 这个过程称为**相似对角化**。$\mathbf{A}$ 与 $\mathbf{D}$ 是**相似矩阵**（similar matrices）——它们代表了同一个线性变换在不同基下的矩阵表示（见 [[Linear Transformations#7. 基变换与坐标变换]]）。

## 3. 对角化的条件

### 3.1 充要条件

$\mathbf{A}$ 可对角化 $\iff$ $\mathbf{A}$ 有 $n$ 个**线性无关**的特征向量。

### 3.2 充分条件

- 如果 $\mathbf{A}$ 有 $n$ 个**互不相同的特征值**，则 $\mathbf{A}$ 一定可对角化
- **实对称矩阵**总是可对角化（且 $\mathbf{P}$ 可取为正交矩阵）

### 3.3 不可对角化的情况

如果某个特征值的**几何重数 < 代数重数**（见 [[Eigenvalues and Eigenvectors#6. 代数重数与几何重数]]），则矩阵不可对角化。

**典型反例——Jordan 块：**

$$
\mathbf{J} = \begin{bmatrix} \lambda & 1 \\ 0 & \lambda \end{bmatrix}
$$

特征值 $\lambda$ 代数重数 2，几何重数 1，不可对角化。

## 4. 如何对角化一个矩阵

### 4.1 步骤

1. 求 $\mathbf{A}$ 的 $n$ 个线性无关的特征向量 $\mathbf{v}_1, \dots, \mathbf{v}_n$
2. 将特征向量作为列构成矩阵 $\mathbf{P} = [\mathbf{v}_1 \; \mathbf{v}_2 \; \cdots \; \mathbf{v}_n]$
3. 特征值按对应顺序构成对角矩阵 $\mathbf{D} = \text{diag}(\lambda_1, \lambda_2, \dots, \lambda_n)$
4. 于是 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$

### 4.2 完整例子

对角化 $\mathbf{A} = \begin{bmatrix} 4 & 1 \\ 2 & 3 \end{bmatrix}$。

由 [[Eigenvalues and Eigenvectors#4.3 举例]] 的结果：
- $\lambda_1 = 2$，$\mathbf{v}_1 = \begin{bmatrix} -1 \\ 2 \end{bmatrix}$
- $\lambda_2 = 5$，$\mathbf{v}_2 = \begin{bmatrix} 1 \\ 1 \end{bmatrix}$

构造：

$$
\mathbf{P} = \begin{bmatrix} -1 & 1 \\ 2 & 1 \end{bmatrix},\quad
\mathbf{D} = \begin{bmatrix} 2 & 0 \\ 0 & 5 \end{bmatrix}
$$

验证：

$$
\mathbf{P}^{-1}\mathbf{A}\mathbf{P}
= \frac{1}{-3}\begin{bmatrix} 1 & -1 \\ -2 & -1 \end{bmatrix}
\begin{bmatrix} 4 & 1 \\ 2 & 3 \end{bmatrix}
\begin{bmatrix} -1 & 1 \\ 2 & 1 \end{bmatrix}
= \begin{bmatrix} 2 & 0 \\ 0 & 5 \end{bmatrix}
= \mathbf{D}
$$

## 5. 对角化的巨大威力

### 5.1 矩阵乘方（核心应用）

如果 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$，则：

$$
\mathbf{A}^k = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}
$$

而对角矩阵的幂极其简单：

$$
\mathbf{D}^k = \begin{bmatrix}
\lambda_1^k & 0 & \cdots & 0 \\
0 & \lambda_2^k & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \lambda_n^k
\end{bmatrix}
$$

**例子：** 计算 $\mathbf{A}^{100}$

$$
\mathbf{A}^{100}
= \mathbf{P} \begin{bmatrix} 2^{100} & 0 \\ 0 & 5^{100} \end{bmatrix} \mathbf{P}^{-1}
$$

比直接算 100 次矩阵乘法快无数倍。

> [!tip] 回顾 [[Matrix Operations#9. 矩阵乘方（Matrix Exponentiation）]]
> 之前介绍的二进制快速幂和对角化法是同一问题的两种策略。二进制快速幂是通用方法；对角化法在有 $n$ 个线性无关特征向量时更高效。

### 5.2 计算矩阵函数

对角化可以将任何矩阵函数简化为对角元上的标量函数：

$$
f(\mathbf{A}) = \mathbf{P}\, f(\mathbf{D})\, \mathbf{P}^{-1},
\quad
f(\mathbf{D}) = \begin{bmatrix}
f(\lambda_1) & & \\
& \ddots & \\
& & f(\lambda_n)
\end{bmatrix}
$$

这对计算 $\exp(\mathbf{A})$（矩阵指数）、$\sin(\mathbf{A})$ 等很有用。

### 5.3 求解差分方程与微分方程

对于 $\mathbf{x}_{k+1} = \mathbf{A}\mathbf{x}_k$：

$$
\mathbf{x}_k = \mathbf{A}^k \mathbf{x}_0 = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}\mathbf{x}_0
$$

对角化后，$n$ 维耦合系统解耦为 $n$ 个独立的一维系统——每个特征值 $\lambda_i$ 对应一个独立的演化模式。

## 6. 对角化与相似性

### 6.1 相似矩阵

如果 $\mathbf{B} = \mathbf{P}^{-1}\mathbf{A}\mathbf{P}$，则 $\mathbf{A}$ 与 $\mathbf{B}$ 相似。对角化就是找到一个 $\mathbf{P}$ 使 $\mathbf{A}$ 与一个对角矩阵相似。

### 6.2 相似变换下的不变量

| 不变量 | 公式 |
|-------|------|
| 特征值 | 完全相同 |
| 迹 | $\text{tr}(\mathbf{A}) = \text{tr}(\mathbf{B})$ |
| 行列式 | $\det(\mathbf{A}) = \det(\mathbf{B})$ |
| 秩 | $\text{rank}(\mathbf{A}) = \text{rank}(\mathbf{B})$ |
| 特征多项式 | $\det(\lambda\mathbf{I} - \mathbf{A}) = \det(\lambda\mathbf{I} - \mathbf{B})$ |

## 7. 正交对角化

对于**实对称矩阵**，不仅可对角化，还可以用**正交矩阵** $\mathbf{Q}$（$\mathbf{Q}^{-1} = \mathbf{Q}^T$）对角化：

$$
\mathbf{A} = \mathbf{Q}\mathbf{D}\mathbf{Q}^T
$$

这就是**谱定理**（Spectral Theorem）的内容。正交对角化在数值计算中更稳定，也是 PCA 的理论基础。

## 8. 对角化 vs Jordan 标准形

| 矩阵类型 | 分解形式 | 说明 |
|---------|---------|------|
| 可对角化 | $\mathbf{P}\mathbf{D}\mathbf{P}^{-1}$ | $\mathbf{D}$ 为对角矩阵 |
| 不可对角化 | $\mathbf{P}\mathbf{J}\mathbf{P}^{-1}$ | $\mathbf{J}$ 为 Jordan 标准形，含 Jordan 块 |

> 对角化是"最好的情况"——矩阵在某个坐标系下就是一个简单的对角矩阵。如果做不到，Jordan 标准形是最接近的替代。

## 9. 在 NumPy 中的体现

```python
import numpy as np
from scipy.linalg import funm  # 矩阵函数

A = np.array([[4, 1],
              [2, 3]])

# 对角化（np.linalg.eig 做的就是对角化）
eigenvalues, eigenvectors = np.linalg.eig(A)

P = eigenvectors                # 特征向量构成 P
D = np.diag(eigenvalues)        # 特征值构成对角矩阵
P_inv = np.linalg.inv(P)

# 验证 A = P @ D @ P^{-1}
A_reconstructed = P @ D @ P_inv
print("A ≈ P D P^{-1}?", np.allclose(A, A_reconstructed))

# 利用对角化计算 A^100
A_power_100 = P @ np.diag(eigenvalues ** 100) @ P_inv

# 利用对角化计算 exp(A)
A_exp = P @ np.diag(np.exp(eigenvalues)) @ P_inv
A_exp_scipy = funm(A, np.exp)  # scipy 标准结果
print("exp(A) 一致?", np.allclose(A_exp, A_exp_scipy))
```

## 相关链接
- [[Eigenvalues and Eigenvectors]]（对角化的前提知识）
- [[Matrix Operations#9. 矩阵乘方（Matrix Exponentiation）]]（对角化在矩阵乘方中的应用）
- [[Linear Transformations#7. 基变换与坐标变换]]（相似变换的几何解释）
- [[Vector Spaces and Subspaces]]（特征空间与特征基）
