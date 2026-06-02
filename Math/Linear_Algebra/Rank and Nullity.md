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

> [!info] Why This Matters
> Rank and nullity answer a fundamental question: when a matrix multiplies a vector, how much information is preserved and how much is lost? In data science, rank tells you how many independent features your data truly has. In engineering, nullity reveals the "blind spots" of a sensor or control system. In computer graphics, rank tells you whether a transformation squashes 3D objects into a 2D plane (rank 2, nullity 1). Understanding rank and nullity is understanding what your matrices can and cannot do.

> [!tip] The Room Analogy
> Imagine a room with n doors — these are the n dimensions of the input space R^n. A vector enters through one of these doors, passes through the matrix, and exits on the other side. What happens inside?
> - **rank(A)** of the doors lead to distinct, nonzero outputs — these directions survive the transformation.
> - **nullity(A)** of the doors all lead to the same output: zero — these directions get "crushed" and lose all information.
>
> Since there are n doors in total, rank(A) + nullity(A) = n. This is the Rank-Nullity Theorem: a conservation law for information. Every input dimension either contributes to the output or gets annihilated — none are lost or created.

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

| 子空间 | 记作 | 所在空间 | 维数 | 直观理解 |
|--------|------|---------|------|---------|
| 列空间 | $\text{Col}(\mathbf{A})$ | $\mathbb{R}^m$ | $\text{rank}(\mathbf{A})$ | 变换能输出的所有方向 — "到达范围" |
| 行空间 | $\text{Row}(\mathbf{A})$ | $\mathbb{R}^n$ | $\text{rank}(\mathbf{A})$ | 输入中对输出有贡献的方向 — "有效输入方向" |
| 零空间 | $\text{Null}(\mathbf{A})$ | $\mathbb{R}^n$ | $\text{nullity}(\mathbf{A})$ | 被压缩到零的方向 — "变换的盲区" |
| 左零空间 | $\text{Null}(\mathbf{A}^T)$ | $\mathbb{R}^m$ | $m - \text{rank}(\mathbf{A})$ | 输出中无法被到达的方向 — "死胡同" |

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

**A deeper look**: The Rank-Nullity Theorem is a **conservation law**. Think of R^n as containing n independent directions. After a linear transformation, each direction either:
- **Survives** and contributes to the output — spanning the **column space** (rank(A) dimensions)
- **Gets crushed** to zero — forming the **null space** (nullity(A) dimensions)

These two sets together account for all n input dimensions — they partition the space. This connects directly to [[Linear Transformations#4. 线性变换的核与像]]: the kernel of a linear transformation is the null space of its matrix, and the image is the column space.

### 5.3 A Simple 2D Example First

Before the full 3D example, consider the simplest nontrivial case: **projection onto the x-axis**.

$$
\mathbf{A} = \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \qquad
\mathbf{A} \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} x \\ 0 \end{bmatrix}
$$

- $\text{rank}(\mathbf{A}) = 1$ (the x-direction survives and becomes the output)
- $n = 2$
- $\text{nullity}(\mathbf{A}) = 2 - 1 = 1$ (the y-direction is crushed to zero)

Null space: $\text{Null}(\mathbf{A}) = \{(0, y) \mid y \in \mathbb{R}\} = \text{span}\{(0,1)\}$, exactly the y-axis.

Check: $\text{rank}(1) + \text{nullity}(1) = 2 = n$. Every direction is accounted for — one reaches the output, one is annihilated.

```
  y                      output
  |                       |
  |                       |  ← only x survives
  -- x                    --
  ↓ crushed to zero
```

### 5.4 三维例子

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

## Quick Reference / Cheatsheet

### Key Ideas at a Glance

| Concept | Intuition | Formula |
|---------|-----------|---------|
| Rank | Number of independent columns = dimension of column space | rank(A) = dim(Col(A)) |
| Nullity | Dimension of null space = number of free variables | nullity(A) = dim(Null(A)) |
| Rank-Nullity Theorem | Input dimensions = output dimensions + crushed dimensions | rank(A) + nullity(A) = n |
| Column space (Col(A)) | All possible outputs of A x | subspace of R^m, dim = rank |
| Row space (Row(A)) | Same dimension as column space | subspace of R^n, dim = rank |
| Null space (Null(A)) | All x such that A x = 0 | subspace of R^n, dim = nullity |
| Full rank | No information lost — invertible if square | rank = min(m,n) |

### How to Think About...

- **Rank as "effective dimension"**: Even if a matrix has 100 columns, its rank might be only 10 — meaning the data really only has 10 independent features.
- **Nullity as "lost dimensions"**: Every free variable in Ax = 0 represents a direction that maps to zero.
- **Rank-Nullity as conservation**: The total number of columns equals the number that survive (rank) plus the number that get crushed (nullity). No exceptions.
- **Four subspaces as a complete picture**: The column space and null space partition the action of A on R^n; the row space and left null space partition the action of A^T on R^m.

### Connection to Other Notes

- [[Linear Transformations#4. 线性变换的核与像]]: The kernel of a linear transformation is Null(A); the image is Col(A).
- [[Linear Transformations#1. 核心概念：一句话概括]]: Every matrix defines a linear transformation; rank and nullity describe how much information that transformation preserves or destroys.
- [[Diagonalization]]: A diagonalizable matrix with all nonzero eigenvalues has full rank — zero eigenvalues correspond to nullspace directions.
- [[Eigenvalues and Eigenvectors]]: An eigenvalue of 0 means the corresponding eigenvector lies in the null space.

### Common Pitfalls

- **Confusing rank with number of rows or columns**: Rank <= min(m,n), but it can be much smaller. Always compute, don't assume.
- **Thinking nullity = number of zero rows**: Nullity is about free variables in Ax = 0, not about zero rows in REF. They often coincide but are conceptually distinct.
- **Forgetting that row rank = column rank**: This is a theorem, not an accident. It reflects the deep fact that row space and column space have the same dimension even though they live in different spaces.

## 相关链接
- [[Linear Systems and Gaussian Elimination]]（主元个数 → 秩）
- [[Vector Spaces and Subspaces]]（子空间的维数与基）
- [[Linear Transformations]]（秩-零化度定理的线性变换版本）
- [[Matrix Operations]]（行列式、逆矩阵与满秩的关系）
- [[Eigenvalues and Eigenvectors]]（零特征值对应奇异矩阵）
