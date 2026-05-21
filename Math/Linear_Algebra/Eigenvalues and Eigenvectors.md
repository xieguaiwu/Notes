---
tags:
  - Math
  - LinearAlgebra
  - 概念性
  - 定义性
title: Eigenvalues and Eigenvectors
created: 2026-05-20
modified:
---

# Eigenvalues and Eigenvectors

## 1. 核心概念：一句话概括

对于一个方阵 $\mathbf{A}$，**特征向量**（eigenvector）是一个非零向量 $\mathbf{v}$，经过 $\mathbf{A}$ 变换后方向不变、只有长度的伸缩；**特征值**（eigenvalue）$\lambda$ 就是这个伸缩倍数：

$$
\boxed{\mathbf{A}\mathbf{v} = \lambda\mathbf{v}}
$$

## 2. 为什么重要？

特征值和特征向量揭示了线性变换的"内在结构"：尽管矩阵可以作用于无穷多个向量，但其中只有某些特殊方向（特征向量）在经过变换后保持方向不变。找到这些方向，就能极大地简化对矩阵的理解和计算。

## 3. 定义

### 3.1 严格定义

设 $\mathbf{A}$ 是 $n \times n$ 方阵。若存在非零向量 $\mathbf{v} \neq \mathbf{0}$ 和标量 $\lambda$ 使得：

$$
\mathbf{A}\mathbf{v} = \lambda \mathbf{v}
$$

则 $\lambda$ 称为 $\mathbf{A}$ 的**特征值**，$\mathbf{v}$ 称为对应 $\lambda$ 的**特征向量**。

### 3.2 几何直觉

```
     ┌──────────┐
  v  │          │     λv
────→│    A     │────→────
     │          │
     └──────────┘
  输入向量      输出向量 = λ × 输入向量
  （方向不变，仅伸缩）
```

> [!tip] 直觉
> 想象一个弹性平面上的某个方向：沿这个方向拉，它会均匀拉伸 $\lambda$ 倍，但方向不变。特征值就是拉伸系数，特征向量就是这些特殊方向。

## 4. 如何计算特征值

### 4.1 特征多项式

由 $\mathbf{A}\mathbf{v} = \lambda\mathbf{v}$ 得：

$$
\mathbf{A}\mathbf{v} - \lambda\mathbf{v} = \mathbf{0}
\implies (\mathbf{A} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}
$$

由于 $\mathbf{v} \neq \mathbf{0}$，系数矩阵 $\mathbf{A} - \lambda\mathbf{I}$ 必须**不可逆**，即行列式为 0：

$$
\det(\mathbf{A} - \lambda\mathbf{I}) = 0
$$

这个关于 $\lambda$ 的 $n$ 次多项式称为**特征多项式**（characteristic polynomial）。

### 4.2 求解步骤

1. 计算 $\det(\mathbf{A} - \lambda\mathbf{I}) = 0$，得到特征多项式
2. 解特征多项式得到 $n$ 个特征值（可能有重根、可能是复数）
3. 对每个 $\lambda$，解齐次方程组 $(\mathbf{A} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}$ 得到特征向量（即 [[Rank and Nullity]] 中 $\mathbf{A} - \lambda\mathbf{I}$ 的零空间）

### 4.3 举例：$2\times2$ 矩阵

求 $\mathbf{A} = \begin{bmatrix} 4 & 1 \\ 2 & 3 \end{bmatrix}$ 的特征值和特征向量。

**Step 1: 特征多项式**

$$
\det(\mathbf{A} - \lambda\mathbf{I}) = \det\begin{bmatrix}
4-\lambda & 1 \\
2 & 3-\lambda
\end{bmatrix}
= (4-\lambda)(3-\lambda) - 2 = \lambda^2 - 7\lambda + 10 = 0
$$

**Step 2: 解特征值**

$$
\lambda^2 - 7\lambda + 10 = (\lambda - 2)(\lambda - 5) = 0
\implies \lambda_1 = 2,\; \lambda_2 = 5
$$

**Step 3: 求特征向量**

$\lambda = 2$：

$$
(\mathbf{A} - 2\mathbf{I})\mathbf{v} = \begin{bmatrix} 2 & 1 \\ 2 & 1 \end{bmatrix} \begin{bmatrix} v_1 \\ v_2 \end{bmatrix} = \mathbf{0}
\implies 2v_1 + v_2 = 0 \implies v_1 = -\frac{1}{2}v_2
$$

特征向量：$\mathbf{v}_1 = t\begin{bmatrix} -1 \\ 2 \end{bmatrix}$（$t \neq 0$），即 $\text{span}\{(-1,2)\}$ 上所有非零向量。

$\lambda = 5$：

$$
(\mathbf{A} - 5\mathbf{I})\mathbf{v} = \begin{bmatrix} -1 & 1 \\ 2 & -2 \end{bmatrix} \begin{bmatrix} v_1 \\ v_2 \end{bmatrix} = \mathbf{0}
\implies v_1 = v_2
$$

特征向量：$\mathbf{v}_2 = t\begin{bmatrix} 1 \\ 1 \end{bmatrix}$（$t \neq 0$）。

## 5. 重要性质

### 5.1 迹与行列式

特征值的一个重要用途：不需要显式计算，就能知道矩阵的一些关键信息。

设 $\lambda_1, \dots, \lambda_n$ 是 $\mathbf{A}$ 的特征值（含重数）：

| 性质 | 公式 |
|------|------|
| **迹** = 对角元之和 = 特征值之和 | $\text{tr}(\mathbf{A}) = \sum a_{ii} = \sum \lambda_i$ |
| **行列式** = 特征值之积 | $\det(\mathbf{A}) = \prod \lambda_i$ |

> [!note] 快速检验
> 如果 $\det(\mathbf{A}) = 0$，则至少有一个特征值为 0——矩阵奇异。

### 5.2 其他重要性质

- **三角矩阵**的特征值就是其对角元
- **实对称矩阵**的特征值**全部为实数**，且特征向量相互正交
- 可逆矩阵的特征值均不为 0
- $\mathbf{A}$ 和 $\mathbf{A}^T$ 有**相同的特征值**（但特征向量不同）
- $\mathbf{A}$ 的特征值为 $\lambda \implies \mathbf{A}^k$ 的特征值为 $\lambda^k$
- 若 $\mathbf{A}$ 可逆，$\mathbf{A}^{-1}$ 的特征值为 $\lambda^{-1}$

### 5.3 矩阵类型与特征值的特性

| 矩阵类型 | 特征值特性 | 特征向量特性 |
|---------|-----------|-------------|
| 实对称 | 全实数 | 可正交 |
| 正交矩阵 | 模长为 1 | 相互正交 |
| 上三角 | 即对角元 | 不一定正交 |
| 旋转矩阵 $R(\theta)$ | 共轭复数对 $e^{\pm i\theta}$ | 不实数化 |

## 6. 代数重数与几何重数

### 6.1 代数重数（Algebraic Multiplicity）

特征值作为特征多项式根的重数。

例如 $(\lambda - 2)^3(\lambda - 5) = 0$：$\lambda=2$ 的代数重数为 3，$\lambda=5$ 为 1。

### 6.2 几何重数（Geometric Multiplicity）

对应特征值 $\lambda$ 的线性无关特征向量的个数，即 $\dim(\text{Null}(\mathbf{A} - \lambda\mathbf{I}))$。

### 6.3 关键关系

$$
1 \le \text{几何重数} \le \text{代数重数}
$$

> [!warning] 缺陷矩阵
> 如果某个特征值的几何重数 < 代数重数，则矩阵**不可对角化**。这称为**缺陷矩阵**（defective matrix）。

## 7. 特征值的几何含义

| 特征值 | 几何含义 |
|-------|---------|
| $\lambda > 1$ | 沿特征向量方向**拉伸** |
| $0 < \lambda < 1$ | 沿特征向量方向**压缩** |
| $\lambda < 0$ | 沿特征向量方向**翻转** |
| $\lambda = 0$ | 沿特征向量方向**压缩到零**（矩阵奇异） |
| $\lambda = 1$ | 沿特征向量方向**保持不变** |
| $\lambda = a + bi$（复数） | **旋转 + 缩放** |

## 8. 特征空间（Eigenspace）

对应特征值 $\lambda$ 的所有特征向量加上零向量构成的集合：

$$
E_\lambda = \text{Null}(\mathbf{A} - \lambda\mathbf{I})
$$

$E_\lambda$ 是 $\mathbb{R}^n$ 的[[Vector Spaces and Subspaces|子空间]]，其维数就是 $\lambda$ 的几何重数。

## 9. 与后续内容的关系

```
Eigenvalues & Eigenvectors
        │
        ├──→ Diagonalization（对角化）
        ├──→ SVD（奇异值分解的基石）
        ├──→ PCA（主成分分析，协方差矩阵的特征分解）
        ├──→ PageRank（Google 搜索引擎核心）
        ├──→ 微分方程（解耦合系统）
        └──→ 量子力学（本征值问题）
```

## 10. 在 NumPy 中的体现

```python
import numpy as np

A = np.array([[4, 1],
              [2, 3]])

# 计算特征值和特征向量
eigenvalues, eigenvectors = np.linalg.eig(A)

print("特征值:", eigenvalues)
print("特征向量（每列是一个特征向量）:\n", eigenvectors)

# 验证 A @ v = λv
for i in range(len(eigenvalues)):
    v = eigenvectors[:, i]
    lam = eigenvalues[i]
    lhs = A @ v
    rhs = lam * v
    print(f"λ = {lam:.2f}:  A@v ≈ λv? {np.allclose(lhs, rhs)}")

# 验证迹 = 特征值之和，行列式 = 特征值之积
print(f"tr(A) = {np.trace(A)}, sum(λ) = {np.sum(eigenvalues):.2f}")
print(f"det(A) = {np.linalg.det(A):.2f}, prod(λ) = {np.prod(eigenvalues):.2f}")
```

## 相关链接
- [[Matrix Operations]]（行列式、逆矩阵）
- [[Diagonalization]]（对角化的条件与步骤）
- [[Vector Spaces and Subspaces]]（特征空间作为子空间）
- [[Rank and Nullity]]（零特征值对应奇异矩阵）
- [[Linear Transformations]]（特征向量的变换视角）
