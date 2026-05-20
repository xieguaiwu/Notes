---
tags:
  - Math
  - LinearAlgebra
  - 定理性
title: Rank and Nullity
created: 2026-05-20
modified:
---

# Rank and Nullity

## 1. 核心概念：一句话概括

**秩（Rank）** 是矩阵列（或行）向量之间"真正独立"的数量；**零化度（Nullity）** 是被矩阵映射到零的向量空间的维数。两者通过**秩-零化度定理**（Rank-Nullity Theorem）紧密联系：

$$
\boxed{\text{rank}(\mathbf{A}) + \text{nullity}(\mathbf{A}) = n}
$$

其中 $n$ 是矩阵 $\mathbf{A}$ 的列数。

## 2. 四个基本子空间

对于一个 $m \times n$ 矩阵 $\mathbf{A}$，其定义了四个重要的子空间（关于子空间的定义见 [[Vector Spaces and Subspaces]]）：

### 2.1 列空间（Column Space / Range）

$$
\text{Col}(\mathbf{A}) = \text{span}\{\mathbf{a}_{\cdot 1}, \mathbf{a}_{\cdot 2}, \dots, \mathbf{a}_{\cdot n}\} \subseteq \mathbb{R}^m
$$

$\mathbf{A}$ 所有列的线性组合构成的集合。也记作 $\mathcal{R}(\mathbf{A})$。

**几何意义**：$\mathbf{A}\mathbf{x}$ 所有可能的输出值。即线性变换 $\mathbf{x} \mapsto \mathbf{A}\mathbf{x}$ 的**像**（见 [[Linear Transformations]]）。

### 2.2 行空间（Row Space）

$$
\text{Row}(\mathbf{A}) = \text{span}\{\mathbf{a}_{1\cdot}, \mathbf{a}_{2\cdot}, \dots, \mathbf{a}_{m\cdot}\} \subseteq \mathbb{R}^n
$$

$\mathbf{A}$ 所有行的线性组合构成的集合。注意 $\text{Row}(\mathbf{A}) = \text{Col}(\mathbf{A}^T)$。

### 2.3 零空间（Null Space / Kernel）

$$
\text{Null}(\mathbf{A}) = \{\mathbf{x} \in \mathbb{R}^n \mid \mathbf{A}\mathbf{x} = \mathbf{0}\} \subseteq \mathbb{R}^n
$$

所有被 $\mathbf{A}$ 映射到零向量的 $\mathbf{x}$ 构成的集合。也记作 $\ker(\mathbf{A})$。

**几何意义**：线性变换 $\mathbf{x} \mapsto \mathbf{A}\mathbf{x}$ 中"被压缩到原点的方向"。

### 2.4 左零空间（Left Null Space）

$$
\text{Null}(\mathbf{A}^T) = \{\mathbf{y} \in \mathbb{R}^m \mid \mathbf{y}^T\mathbf{A} = \mathbf{0}^T\} \subseteq \mathbb{R}^m
$$

即 $\mathbf{A}^T$ 的零空间。

### 总结：四个子空间的维度关系

| 子空间 | 记作 | 所在空间 | 维数 |
|--------|------|---------|------|
| 列空间 | $\text{Col}(\mathbf{A})$ | $\mathbb{R}^m$ | $\text{rank}(\mathbf{A})$ |
| 行空间 | $\text{Row}(\mathbf{A})$ | $\mathbb{R}^n$ | $\text{rank}(\mathbf{A})$ |
| 零空间 | $\text{Null}(\mathbf{A})$ | $\mathbb{R}^n$ | $\text{nullity}(\mathbf{A})$ |
| 左零空间 | $\text{Null}(\mathbf{A}^T)$ | $\mathbb{R}^m$ | $m - \text{rank}(\mathbf{A})$ |

## 3. 秩（Rank）

### 3.1 定义

**列秩** = $\dim(\text{Col}(\mathbf{A}))$，即列空间中线性无关列的最大个数。
**行秩** = $\dim(\text{Row}(\mathbf{A}))$，即行空间中线性无关行的最大个数。

> [!note] 核心结论
> 对于任何矩阵，**列秩 = 行秩**，统称为矩阵的秩 $\text{rank}(\mathbf{A})$。

### 3.2 如何计算秩

将矩阵化为 [[Linear Systems and Gaussian Elimination#4.1 行阶梯形（REF）|行阶梯形]]，**主元的个数**就是秩：

$$
\mathbf{A} = \begin{bmatrix}
1 & 2 & 1 \\
2 & 4 & 2 \\
3 & 1 & 2
\end{bmatrix}
\;\xrightarrow{\text{消元}}\;
\begin{bmatrix}
\boxed{1} & 2 & 1 \\
0 & \boxed{-5} & -1 \\
0 & 0 & 0
\end{bmatrix}
\;\Longrightarrow\; \text{rank}(\mathbf{A}) = 2
$$

### 3.3 秩的性质

- $0 \le \text{rank}(\mathbf{A}) \le \min(m, n)$
- $\text{rank}(\mathbf{A}^T) = \text{rank}(\mathbf{A})$
- $\text{rank}(\mathbf{A}\mathbf{B}) \le \min(\text{rank}(\mathbf{A}), \text{rank}(\mathbf{B}))$
- $\text{rank}(\mathbf{A} + \mathbf{B}) \le \text{rank}(\mathbf{A}) + \text{rank}(\mathbf{B})$
- **满秩**：$\text{rank}(\mathbf{A}) = \min(m, n)$。方阵满秩 $\iff$ [[Matrix Operations#8. 逆矩阵|可逆]]

### 3.4 秩的直观意义

| 秩的值 | 含义 |
|-------|------|
| $\text{rank}(\mathbf{A}) = n$（列满秩） | $\mathbf{A}\mathbf{x} = \mathbf{0}$ 只有零解，映射是**单射** |
| $\text{rank}(\mathbf{A}) = m$（行满秩） | $\mathbf{A}\mathbf{x} = \mathbf{b}$ 对所有 $\mathbf{b}$ 有解，映射是**满射** |
| $\text{rank}(\mathbf{A}) < n$ | 存在自由变量，$\mathbf{A}\mathbf{x} = \mathbf{0}$ 有非零解 |

## 4. 零化度（Nullity）

### 4.1 定义

$$
\text{nullity}(\mathbf{A}) = \dim(\text{Null}(\mathbf{A}))
$$

即零空间的维数，也就是自由变量的个数。

### 4.2 如何计算零化度

先求秩，再用秩-零化度定理：

$$
\text{nullity}(\mathbf{A}) = n - \text{rank}(\mathbf{A})
$$

其中 $n$ 是 $\mathbf{A}$ 的**列数**。

## 5. 秩-零化度定理（Rank-Nullity Theorem）

### 5.1 定理陈述

对于 $m \times n$ 矩阵 $\mathbf{A}$：

$$
\boxed{\text{rank}(\mathbf{A}) + \text{nullity}(\mathbf{A}) = n}
$$

### 5.2 直观理解

$$
\underbrace{\text{输入空间的维数}}_{\;n\;}
\;=\;
\underbrace{\text{输出空间的维数}}_{\text{rank}(\mathbf{A})}
\;+\;
\underbrace{\text{被压缩到零的维数}}_{\text{nullity}(\mathbf{A})}
$$

线性变换将 $\mathbb{R}^n$ 的一部分方向"保留"到输出空间，另一部分方向"压缩"到零：

```
原始空间 (R^n)          输出空间 (R^m)
┌──────────────┐
│  保留的方向  │ ──────→ Col(A) (rank 维)
│  (rank 个)   │
│              │
│  压缩到零    │ ──────→ 0
│  (nullity 个)│
└──────────────┘
```

> [!tip] 能量守恒
> 输入的自由度总量固定为 $n$，一部分体现在输出中（秩），一部分被压缩消失（零化度）。

### 5.3 例子

对于矩阵 $\mathbf{A} = \begin{bmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 3 & 1 & 2 \end{bmatrix}$：

- $\text{rank}(\mathbf{A}) = 2$
- $n = 3$
- $\text{nullity}(\mathbf{A}) = 3 - 2 = 1$

验证：解 $\mathbf{A}\mathbf{x} = \mathbf{0}$ 得 $x = -\frac{3}{5}z,\; y = -\frac{1}{5}z$，零空间为 $\text{span}\{(-\frac{3}{5}, -\frac{1}{5}, 1)\}$，正好 1 维。

## 6. 可逆矩阵与满秩

$n \times n$ 方阵 $\mathbf{A}$ 可逆 $\iff$ $\text{rank}(\mathbf{A}) = n$ $\iff$ $\text{nullity}(\mathbf{A}) = 0$。

此时：
- $\text{Col}(\mathbf{A}) = \mathbb{R}^n$（列空间充满整个空间）
- $\text{Null}(\mathbf{A}) = \{\mathbf{0}\}$（零空间只有零向量）
- $\mathbf{A}\mathbf{x} = \mathbf{b}$ 对任意 $\mathbf{b}$ 有唯一解

## 7. 在 NumPy 中的体现

```python
import numpy as np

A = np.array([[1, 2, 1],
              [2, 4, 2],
              [3, 1, 2]], dtype=float)

# 计算秩（使用 SVD 分解，数值稳定）
rank = np.linalg.matrix_rank(A)
print(f"rank(A) = {rank}")

# 零空间（通过 SVD）
U, s, Vt = np.linalg.svd(A)
null_mask = s < 1e-10
null_space = Vt[null_mask].T
print(f"nullity(A) = {null_space.shape[1]}")

# 验证 rank + nullity = n
m, n = A.shape
print(f"rank + nullity = {rank} + {n - rank} = {n}")

# 四个基本子空间的关系验证
print(f"Col(A) ⊆ R^{m}, dim = {rank}")
print(f"Row(A) ⊆ R^{n}, dim = {rank}")
print(f"Null(A) ⊆ R^{n}, dim = {n - rank}")
print(f"Null(A^T) ⊆ R^{m}, dim = {m - rank}")
```

## 相关链接
- [[Linear Systems and Gaussian Elimination]]（主元个数 → 秩）
- [[Vector Spaces and Subspaces]]（子空间的维数与基）
- [[Linear Transformations]]（秩-零化度定理的线性变换版本）
- [[Matrix Operations]]（行列式、逆矩阵与满秩的关系）
- [[Eigenvalues and Eigenvectors]]（零特征值对应奇异矩阵）
