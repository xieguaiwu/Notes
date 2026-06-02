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

可以这样直观想象：在二维平面上随机取一个向量，用矩阵 $\mathbf{A}$ 对它做线性变换——大多数向量的方向和长度都会改变。但存在某些特殊方向，$\mathbf{A}$ 的作用仅仅是拉伸（或压缩），方向保持不变。这些特殊方向就是特征向量，拉伸倍数就是特征值。

## 2. 为什么重要？

特征值和特征向量揭示了线性变换的"内在结构"：尽管矩阵可以作用于无穷多个向量，但其中只有某些特殊方向（特征向量）在经过变换后保持方向不变。找到这些方向，就能极大地简化对矩阵的理解和计算。

### 2.1 典型应用

- **Google PageRank**：互联网网页的排名本质上是一个超大规模矩阵的主特征向量问题——排名最高的网页对应最大特征值的特征向量
- **PCA（主成分分析）**：对数据的协方差矩阵做特征分解，取最大特征值对应的方向作为方差最大的方向，用于降维和可视化
- **量子力学**：物理系统的可观测量由算符表示，其可能的取值就是算符的特征值——"本征值问题"是整个量子力学的数学根基
- **振动分析**：桥梁、建筑、机械结构的固有频率由动力学矩阵的特征值决定；工程设计需要确保固有频率远离外部激励频率，避免共振
- **谱聚类**：将图的拉普拉斯矩阵的特征向量作为聚类依据，可以处理非凸形状的聚类问题

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

由 $\mathbf{A}\mathbf{v} = \lambda\mathbf{v}$ 出发：

$$
\mathbf{A}\mathbf{v} - \lambda\mathbf{v} = \mathbf{0}
\implies (\mathbf{A} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}
$$

这里的关键推理：如果存在非零向量 $\mathbf{v}$ 满足 $(\mathbf{A} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}$，那么矩阵 $\mathbf{A} - \lambda\mathbf{I}$ 一定有一个非平凡的零空间——这意味着 $\mathbf{A} - \lambda\mathbf{I}$ 不可逆（奇异）。对矩阵来说，不可逆等价于行列式为 0。因此：

$$
\det(\mathbf{A} - \lambda\mathbf{I}) = 0
$$

**直觉**：方程 $(\mathbf{A} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}$ 是一个齐次线性方程组。如果 $\lambda$ 是特征值，该方程组有非零解（特征向量），所以系数矩阵 $\mathbf{A} - \lambda\mathbf{I}$ 的秩不足，行列式必然为零。反之，使行列式为零的 $\lambda$ 一定是特征值。

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

### 4.4 举例：$3\times3$ 矩阵

求 $\mathbf{A} = \begin{bmatrix} 5 & 0 & 0 \\ 0 & 3 & 1 \\ 0 & 1 & 3 \end{bmatrix}$ 的特征值和特征向量。

**Step 1: 特征多项式**

$$
\det(\mathbf{A} - \lambda\mathbf{I}) = \det\begin{bmatrix}
5-\lambda & 0 & 0 \\
0 & 3-\lambda & 1 \\
0 & 1 & 3-\lambda
\end{bmatrix}
= (5-\lambda)[(3-\lambda)^2 - 1] = (5-\lambda)(\lambda^2 - 6\lambda + 8) = 0
$$

即 $(5-\lambda)(\lambda-2)(\lambda-4) = 0$。

**Step 2: 解特征值**

$$
\lambda_1 = 5,\; \lambda_2 = 2,\; \lambda_3 = 4
$$

三个不同的实特征值。

**Step 3: 求特征向量**

$\lambda = 5$：

$$
(\mathbf{A} - 5\mathbf{I})\mathbf{v} = \begin{bmatrix} 0 & 0 & 0 \\ 0 & -2 & 1 \\ 0 & 1 & -2 \end{bmatrix}\mathbf{v} = \mathbf{0}
\implies v_2 = v_3 = 0
$$

特征向量：$\mathbf{v}_1 = t\begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}$（$t \neq 0$）。

$\lambda = 2$：

$$
(\mathbf{A} - 2\mathbf{I})\mathbf{v} = \begin{bmatrix} 3 & 0 & 0 \\ 0 & 1 & 1 \\ 0 & 1 & 1 \end{bmatrix}\mathbf{v} = \mathbf{0}
\implies v_1 = 0,\; v_2 + v_3 = 0
$$

特征向量：$\mathbf{v}_2 = t\begin{bmatrix} 0 \\ 1 \\ -1 \end{bmatrix}$（$t \neq 0$）。

$\lambda = 4$：

$$
(\mathbf{A} - 4\mathbf{I})\mathbf{v} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & -1 & 1 \\ 0 & 1 & -1 \end{bmatrix}\mathbf{v} = \mathbf{0}
\implies v_1 = 0,\; -v_2 + v_3 = 0
$$

特征向量：$\mathbf{v}_3 = t\begin{bmatrix} 0 \\ 1 \\ 1 \end{bmatrix}$（$t \neq 0$）。

> [!note] 观察
> 这是一个对称矩阵，三个特征值全是实数，且特征向量 $(1,0,0), (0,1,-1), (0,1,1)$ 相互正交——这正是实对称矩阵的性质。

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

### 6.4 缺陷矩阵的例子

考虑 $\mathbf{A} = \begin{bmatrix} 1 & 1 \\ 0 & 1 \end{bmatrix}$（一个剪切变换矩阵）。

特征多项式：$\det(\mathbf{A} - \lambda\mathbf{I}) = (1-\lambda)^2 = 0$，特征值 $\lambda = 1$ 的代数重数为 2。

求特征向量：$(\mathbf{A} - \mathbf{I})\mathbf{v} = \begin{bmatrix} 0 & 1 \\ 0 & 0 \end{bmatrix}\mathbf{v} = \mathbf{0} \implies v_2 = 0$，特征向量为 $\mathbf{v} = t\begin{bmatrix} 1 \\ 0 \end{bmatrix}$。

只有一个线性无关的特征方向 $(1,0)^T$，几何重数 = 1 < 代数重数 = 2。这就是一个缺陷矩阵。

**几何理解**：剪切变换将水平方向拉伸的同时斜向扭曲，只在水平方向上有不变方向，缺少第二个独立特征方向——因此无法通过对角化来简化。

> [!tip] 直观判断
> 代数重数告诉你"应该有多少个特征方向"，几何重数告诉你"实际有多少个"。两者不相等时，矩阵缺少足够的特征方向来构成一组基，自然无法对角化。

## 7. 特征值的几何含义

| 特征值 | 几何含义 | 详细描述 |
|-------|---------|---------|
| $\lambda > 1$ | 沿特征向量方向**拉伸** | 向量被拉长为 $|\lambda|$ 倍，方向不变——$\lambda$ 越大，拉伸越剧烈 |
| $0 < \lambda < 1$ | 沿特征向量方向**压缩** | 向量被缩短到原长度的 $\lambda$ 倍，方向不变——$\lambda$ 越接近 0，压缩越厉害 |
| $\lambda < 0$ | 沿特征向量方向**翻转** | 方向反转（反向），长度变为 $|\lambda|$ 倍——负号相当于附加了 $180^\circ$ 旋转 |
| $\lambda = 0$ | 沿特征向量方向**压缩到零** | 该方向上的向量被映射为零向量——矩阵有非平凡零空间，不可逆 |
| $\lambda = 1$ | 沿特征向量方向**保持不变** | 该方向上的每个向量都是变换的不动点——恒等变换的特征 |
| $\lambda = a+bi$（复数） | **旋转 + 缩放** | 实数特征方向不存在；复平面上模长 $|\lambda| = \sqrt{a^2+b^2}$ 决定缩放量，辐角决定旋转角度 |

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

## 11. Quick Reference

| 概念 | 公式 / 要点 |
|------|------------|
| 定义 | $\mathbf{A}\mathbf{v} = \lambda\mathbf{v}$，$\mathbf{v} \neq \mathbf{0}$ |
| 特征多项式 | $\det(\mathbf{A} - \lambda\mathbf{I}) = 0$ |
| 迹 = 特征值之和 | $\text{tr}(\mathbf{A}) = \sum a_{ii} = \sum \lambda_i$ |
| 行列式 = 特征值之积 | $\det(\mathbf{A}) = \prod \lambda_i$ |
| 代数重数 | 特征值作为多项式根的重数 |
| 几何重数 | $\dim\text{Null}(\mathbf{A} - \lambda\mathbf{I})$，即线性无关特征向量个数 |
| 重数关系 | $1 \le \text{几何重数} \le \text{代数重数}$ |
| 实对称矩阵 | 特征值全实数，特征向量可正交 |
| 特征值几何 | $\lambda>1$ 拉伸，$0<\lambda<1$ 压缩，$\lambda<0$ 翻转，$\lambda=0$ 奇异，复数 = 旋转+缩放 |
| 缺陷矩阵 | 几何重数 < 代数重数 → 不可对角化 |

## 相关链接
- [[Matrix Operations]]（行列式、逆矩阵）
- [[Diagonalization]]（对角化的条件与步骤）
- [[Vector Spaces and Subspaces]]（特征空间作为子空间）
- [[Rank and Nullity]]（零特征值对应奇异矩阵）
- [[Linear Transformations]]（特征向量的变换视角）
