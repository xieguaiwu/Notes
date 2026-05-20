---
tags:
  - Math
  - LinearAlgebra
  - 定义性
title: Vector Spaces and Subspaces
created: 2026-05-20
modified:
---

# Vector Spaces and Subspaces

## 1. 核心概念：一句话概括

**向量空间**是一个满足加法和数乘封闭性的集合，其中的元素（向量）可以相加、可以乘以标量，且结果仍在集合内；**子空间**是向量空间内的一个子集，它本身也构成一个向量空间。

## 2. 向量空间的定义

一个集合 $V$ 称为 $\mathbb{R}$ 上的向量空间（vector space），如果定义了**加法**和**数乘**两种运算，且满足以下 **8 条公理**：

### 加法封闭性
对任意 $\mathbf{u}, \mathbf{v} \in V$，$\mathbf{u} + \mathbf{v} \in V$

### 数乘封闭性
对任意 $\mathbf{v} \in V$ 和标量 $c \in \mathbb{R}$，$c\mathbf{v} \in V$

### 8 条公理

| # | 名称 | 条件 |
|---|------|------|
| 1 | 加法交换律 | $\mathbf{u} + \mathbf{v} = \mathbf{v} + \mathbf{u}$ |
| 2 | 加法结合律 | $(\mathbf{u} + \mathbf{v}) + \mathbf{w} = \mathbf{u} + (\mathbf{v} + \mathbf{w})$ |
| 3 | 零元存在 | 存在 $\mathbf{0} \in V$ 使得 $\mathbf{v} + \mathbf{0} = \mathbf{v}$ |
| 4 | 负元存在 | 对每个 $\mathbf{v} \in V$，存在 $-\mathbf{v}$ 使得 $\mathbf{v} + (-\mathbf{v}) = \mathbf{0}$ |
| 5 | 数乘结合律 | $c(d\mathbf{v}) = (cd)\mathbf{v}$ |
| 6 | 数乘分配律 1 | $(c + d)\mathbf{v} = c\mathbf{v} + d\mathbf{v}$ |
| 7 | 数乘分配律 2 | $c(\mathbf{u} + \mathbf{v}) = c\mathbf{u} + c\mathbf{v}$ |
| 8 | 数乘单位元 | $1\mathbf{v} = \mathbf{v}$ |

> [!note] 不需要死记
> 实际使用时，绝大多数自然出现的集合都满足这些公理。核心记住**加法和数乘封闭**最关键。

### 常见向量空间举例

| 空间 | 元素 | 维数 |
|------|------|------|
| $\mathbb{R}^n$ | $n$ 维实向量 | $n$ |
| $\mathbb{R}^{m \times n}$ | $m \times n$ 实矩阵 | $mn$ |
| $\mathcal{P}_n$ | 次数 $\le n$ 的多项式 | $n+1$ |
| $\mathcal{C}[a,b]$ | $[a,b]$ 上的连续函数 | $\infty$ |

## 3. 子空间（Subspace）

### 3.1 定义

$H \subseteq V$ 是 $V$ 的**子空间**（subspace），当且仅当：
1. $\mathbf{0} \in H$（含零向量）
2. **加法封闭**：$\mathbf{u}, \mathbf{v} \in H \implies \mathbf{u} + \mathbf{v} \in H$
3. **数乘封闭**：$\mathbf{v} \in H, c \in \mathbb{R} \implies c\mathbf{v} \in H$

> [!tip] 检验技巧
> 要验证 $H$ 是子空间，只需验证三条：**零向量 + 加法封闭 + 数乘封闭**。如果 $H$ 是用"满足某条线性方程/条件"描述的，通常就是子空间。

### 3.2 例子

**是子空间：**
- $\mathbb{R}^2$ 中过原点的直线：$\{t(1,2) \mid t \in \mathbb{R}\}$
- $\mathbb{R}^3$ 中过原点的平面：$\{s(1,0,1) + t(0,1,0) \mid s,t \in \mathbb{R}\}$
- 所有对称矩阵构成 $\mathbb{R}^{n \times n}$ 的子空间
- [[Rank and Nullity]] 中介绍的零空间 $\text{Null}(\mathbf{A})$ 和列空间 $\text{Col}(\mathbf{A})$

**不是子空间：**
- $\mathbb{R}^2$ 中**不过**原点的直线：不含零向量
- 第一象限 $\{(x,y) \mid x \ge 0, y \ge 0\}$：数乘 $-1$ 不封闭
- 单位圆 $\{(x,y) \mid x^2 + y^2 = 1\}$：加法和数乘都不封闭

## 4. 生成（Span）

向量集合 $\{\mathbf{v}_1, \mathbf{v}_2, \dots, \mathbf{v}_k\}$ 的**生成**（span）：

$$
\text{span}\{\mathbf{v}_1, \dots, \mathbf{v}_k\} = \{c_1\mathbf{v}_1 + \cdots + c_k\mathbf{v}_k \mid c_i \in \mathbb{R}\}
$$

即所有线性组合的集合。$\text{span}\{\mathbf{v}_1, \dots, \mathbf{v}_k\}$ 总是 $\mathbb{R}^n$ 的子空间。

> [!abstract] 生成子空间
> 向量集合的**生成**是**最小**包含这些向量的子空间。它是构造子空间的基本方法。

## 5. 线性无关与线性相关

### 5.1 定义

向量组 $\{\mathbf{v}_1, \dots, \mathbf{v}_k\}$ **线性无关**（linearly independent），如果：

$$
c_1\mathbf{v}_1 + c_2\mathbf{v}_2 + \cdots + c_k\mathbf{v}_k = \mathbf{0}
\implies c_1 = c_2 = \cdots = c_k = 0
$$

也就是说：任何一个向量都不能表示为其余向量的线性组合。

**线性相关**（linearly dependent）：存在不全为零的系数使得组合为零向量。

### 5.2 几何直觉

| 维数 | 线性无关的几何条件 |
|------|------------------|
| $\mathbb{R}^2$ 中 2 个向量 | 不共线 |
| $\mathbb{R}^3$ 中 3 个向量 | 不共面 |
| 任意空间 | $k > n$ 个 $n$ 维向量**必然**线性相关 |

> [!warning]
> 如果向量个数 > 向量维数，则必然线性相关。$n+1$ 个 $n$ 维向量一定存在冗余。

## 6. 基（Basis）

### 6.1 定义

$B = \{\mathbf{b}_1, \dots, \mathbf{b}_d\}$ 是向量空间 $V$ 的**基**（basis），如果：
1. $B$ **线性无关**
2. $B$ **生成** $V$：$\text{span}(B) = V$

### 6.2 标准基

| 空间 | 标准基 |
|------|--------|
| $\mathbb{R}^n$ | $\{\mathbf{e}_1, \dots, \mathbf{e}_n\}$，$\mathbf{e}_i = (0,\dots,1,\dots,0)$ |
| $\mathbb{R}^{2 \times 2}$ | $\{\begin{bmatrix}1&0\\0&0\end{bmatrix}, \begin{bmatrix}0&1\\0&0\end{bmatrix}, \begin{bmatrix}0&0\\1&0\end{bmatrix}, \begin{bmatrix}0&0\\0&1\end{bmatrix}\}$ |
| $\mathcal{P}_2$ | $\{1, x, x^2\}$ |

### 6.3 基的重要性质

- 一个向量空间可以有多个不同的基
- 所有基的**元素个数相同**（即维数）
- 基是"**最经济的生成集**"：去掉任一元素就不足以生成整个空间
- 基也是"**最大的线性无关集**"：再加入任一向量就会变得相关

## 7. 维数（Dimension）

### 7.1 定义

向量空间 $V$ 的维数 $\dim(V)$ 等于其基中向量的个数。

### 7.2 基本结论

- $\dim(\mathbb{R}^n) = n$
- $\dim(\mathbb{R}^{m \times n}) = mn$
- $\dim(\mathcal{P}_n) = n + 1$
- 零空间 $\{\mathbf{0}\}$ 的维数为 0

### 7.3 坐标（Coordinates）

选定了基 $B = \{\mathbf{b}_1, \dots, \mathbf{b}_n\}$ 后，任意向量 $\mathbf{v} \in V$ 可以唯一地表示为：

$$
\mathbf{v} = c_1\mathbf{b}_1 + c_2\mathbf{b}_2 + \cdots + c_n\mathbf{b}_n
$$

系数向量 $[\mathbf{v}]_B = (c_1, c_2, \dots, c_n)$ 称为 $\mathbf{v}$ 在基 $B$ 下的**坐标**（coordinates）。

> [!tip] 基的选择很重要
> 同一个向量在不同基下的坐标不同——这正是 [[Diagonalization]] 中 $\mathbf{P}$ 矩阵在做的事情：将特征向量基下的坐标转换到标准基。

## 8. 子空间与基的经典结论

- 如果 $\dim(V) = n$，则 $V$ 中任意 $n$ 个线性无关的向量构成一组基
- 如果 $\dim(V) = n$，则 $V$ 中任意 $n$ 个生成 $V$ 的向量构成一组基
- 子空间的维数 $\le$ 母空间的维数
- $\dim(\text{span}\{\mathbf{v}_1,\dots,\mathbf{v}_k\})$ = $\text{rank}([\mathbf{v}_1 \; \cdots \; \mathbf{v}_k])$

## 9. 概念拓扑图

```
向量空间 ──→ 子空间 ──→ 基（最"经济"的生成集）
   │                      │
   │                      ▼
   │                    维数 = 基的个数
   │
   └──→ span（子空间构造方法）
   └──→ 线性无关（基的核心条件）
```

这些概念贯穿线性代数始终，是理解 [[Rank and Nullity]]、[[Linear Transformations]] 和 [[Eigenvalues and Eigenvectors]] 的基础。

## 10. 在 NumPy 中的体现

```python
import numpy as np

# 检验线性无关性
v1 = np.array([1, 2, 3])
v2 = np.array([4, 5, 6])
v3 = np.array([7, 8, 9])

A = np.column_stack([v1, v2, v3])
rank = np.linalg.matrix_rank(A)
print(f"矩阵的秩 = {rank}，3个向量{'线性无关' if rank == 3 else '线性相关'}")

# 检验一组向量是否构成 R^3 的基
B = np.column_stack([np.array([1,0,0]),
                     np.array([1,1,0]),
                     np.array([1,1,1])])
det_B = np.linalg.det(B)
print(f"行列式 = {det_B:.2f}，是{'一组基' if abs(det_B) > 1e-10 else '不是基'}")

# 求 span 的维数
vectors = np.random.randn(3, 5)  # 5 个 R^3 中的向量
span_dim = np.linalg.matrix_rank(vectors)
print(f"5 个 R^3 向量的 span 的维数 = {span_dim}（必有冗余）")
```

## 相关链接
- [[Vector and Matrix]]（向量的基本概念）
- [[Linear Systems and Gaussian Elimination]]（解空间与零空间）
- [[Rank and Nullity]]（子空间维数的应用）
- [[Linear Transformations]]（线性映射的核与像）
- [[Matrix Operations]]（矩阵作为向量空间）
