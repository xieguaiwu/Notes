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

### 1.1 为什么要对角化？（Why Diagonalize?）

对角化不仅仅是一个代数技巧——它解决了实际问题中最重要的计算需求：**把一个复杂的矩阵运算转化为简单的标量运算**。

核心思想：对角化 = 寻找一个"好的坐标系"，在这个坐标系中，原本复杂的线性变换简化为各方向独立的伸缩。

具体好处：

- **快速计算矩阵的幂** $\mathbf{A}^k$：直接做矩阵乘法需要 $O(k n^3)$，对角化后只需要 $O(n^3)$ 一次预处理，然后对每个对角元算 $k$ 次幂即可。PageRank（Google 的网页排序算法）本质上就是计算一个巨大矩阵的幂来提取网页排名的稳态分布。
- **解耦线性系统**：耦合的微分方程组 $\mathbf{x}' = \mathbf{A}\mathbf{x}$ 对角化后变成 $n$ 个独立的标量微分方程 $\mathbf{y}' = \mathbf{D}\mathbf{y}$，每个方程的解 $e^{\lambda_i t}$ 一眼看出。
- **简化矩阵函数**：计算 $e^{\mathbf{A}}$、$\sin(\mathbf{A})$ 等矩阵函数时，对角化将问题简化为对每个特征值计算相同的标量函数 $f(\lambda_i)$。

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

### 2.1 可视化理解 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$

将 $\mathbf{A}$ 作用于向量 $\mathbf{v}$ 的过程，可拆解为三个清晰步骤：

$$
\begin{aligned}
\mathbf{v} &\xrightarrow{\mathbf{P}^{-1}} \mathbf{P}^{-1}\mathbf{v} \;(\text{转换到特征基坐标}) \\[2pt]
&\xrightarrow{\mathbf{D}} \mathbf{D}\mathbf{P}^{-1}\mathbf{v} \;(\text{各分量被对应 }\lambda_i\text{ 独立缩放}) \\[2pt]
&\xrightarrow{\mathbf{P}} \mathbf{P}\mathbf{D}\mathbf{P}^{-1}\mathbf{v} = \mathbf{A}\mathbf{v}
\end{aligned}
$$

1. **$\mathbf{P}^{-1}\mathbf{v}$** —— 将 $\mathbf{v}$ 从标准基坐标转换到**特征基**（eigenbasis）坐标。在特征基下，$\mathbf{A}$ 看起来最简单。
2. **$\mathbf{D}(\mathbf{P}^{-1}\mathbf{v})$** —— 在特征基下，$\mathbf{A}$ 就是对角的：每个坐标分量被对应的特征值 $\lambda_i$ 缩放。
3. **$\mathbf{P}(\mathbf{D}\mathbf{P}^{-1}\mathbf{v})$** —— 将结果从特征基坐标映射回标准基坐标。

> $\mathbf{P}$ 的列就是特征向量，因此 $\mathbf{P}$ 是将"特征基下的坐标"转换为"标准基下的坐标"的矩阵。$\mathbf{P}^{-1}$ 则相反，将标准基坐标转换到特征基。

这正是"**对角化 = 找到正确的坐标系**"这一核心直觉的数学表达。

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

**为什么 Jordan 块不可对角化？——一个直观理解**

要对角化一个 $2\times 2$ 矩阵，我们需要 2 个线性无关的特征向量。但 $\mathbf{J}$ 的特征方程 $(\lambda - \lambda)^2 = 0$ 给出唯一特征值 $\lambda$（代数重数 2）。

求解特征向量：$(\mathbf{J} - \lambda\mathbf{I})\mathbf{v} = \mathbf{0}$ 即：
$$
\begin{bmatrix} 0 & 1 \\ 0 & 0 \end{bmatrix} \mathbf{v} = \mathbf{0}
$$
解得 $\mathbf{v} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$ 及其倍数——只有**一个**独立方向！几何重数为 1。

换句话说，$\mathbf{J}$ 右上角的 $1$ 引入了一个**剪切**（shear）分量：这个剪切方向没有自己的特征向量，所有向量最终都被"推向"同一个方向，无法形成 2 个独立的坐标轴。因此不存在足够的特征向量来张成 $\mathbb{R}^2$，也就不可能找到可逆的 $\mathbf{P}$ 将其对角化。

> **直觉总结**：可对角化 = 特征向量构成一组完整的"新坐标轴"；不可对角化 = 至少缺失一个坐标轴，总有一些方向在变换下不是被缩放，而是被剪切或扭曲。

## 4. 如何对角化一个矩阵

### 4.1 步骤

1. 求 $\mathbf{A}$ 的 $n$ 个线性无关的特征向量 $\mathbf{v}_1, \dots, \mathbf{v}_n$
2. 将特征向量作为列构成矩阵 $\mathbf{P} = [\mathbf{v}_1 \; \mathbf{v}_2 \; \cdots \; \mathbf{v}_n]$
3. 特征值按对应顺序构成对角矩阵 $\mathbf{D} = \text{diag}(\lambda_1, \lambda_2, \dots, \lambda_n)$
4. 于是 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$

> **几何视角**：$\mathbf{P}$ 是将特征基坐标转换成标准基坐标的矩阵。第 $i$ 个特征向量 $\mathbf{v}_i$ 就是特征基的第 $i$ 个基向量在标准基下的表示。乘以 $\mathbf{P}$ 就是在说："用特征向量的线性组合来还原标准基下的向量"。

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

### 5.4 经典案例：斐波那契数列

斐波那契数列 $F_{k+2} = F_{k+1} + F_k$（$F_0 = 0, F_1 = 1$）是一个**线性递推**，可写成矩阵形式：

$$
\begin{bmatrix} F_{k+1} \\ F_k \end{bmatrix} = \underbrace{\begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}}_{\mathbf{A}} \begin{bmatrix} F_k \\ F_{k-1} \end{bmatrix},\quad
\text{于是 } \begin{bmatrix} F_{k+1} \\ F_k \end{bmatrix} = \mathbf{A}^k \begin{bmatrix} 1 \\ 0 \end{bmatrix}
$$

$\mathbf{A}$ 的特征值和特征向量：
- $\lambda_1 = \phi = \dfrac{1+\sqrt{5}}{2}$（黄金比例），$\mathbf{v}_1 = \begin{bmatrix} \phi \\ 1 \end{bmatrix}$
- $\lambda_2 = \psi = \dfrac{1-\sqrt{5}}{2} = -\phi^{-1}$，$\mathbf{v}_2 = \begin{bmatrix} \psi \\ 1 \end{bmatrix}$

对角化 $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$，则 $\mathbf{A}^k = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}$。代入计算即得**比奈公式（Binet's formula）**：

$$
F_k = \frac{\phi^k - \psi^k}{\sqrt{5}}
$$

这个公式直接给出了斐波那契数列的闭式解——无需循环迭代，$O(1)$ 即可计算任意 $F_k$。

> **启示**：任何线性递推 $a_{n+m} = c_1 a_{n+m-1} + \cdots + c_m a_n$ 都可表示为矩阵形式，对角化后即可得到闭式解。这就是对角化在组合数学和算法分析中的典型应用。

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

## Quick Reference 速查表

| 概念 | 公式 / 条件 | 关键直觉 |
|------|------------|---------|
| 对角化定义 | $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$ | $\mathbf{A}$ 在特征基下就是对角的 |
| $\mathbf{P}$ 的含义 | 列 = 特征向量 | 从特征基转换到标准基 |
| $\mathbf{D}$ 的含义 | 对角元 = 特征值 | 在特征基下各方向独立缩放 |
| 可对角化条件 | $n$ 个线性无关特征向量 | 有完整的"新坐标轴"集合 |
| 充分条件 | $n$ 个互异特征值 | 每个特征值贡献一个独立方向 |
| 不可对角化 | 几何重数 < 代数重数 | 坐标轴缺失，存在剪切 |
| 矩阵幂 | $\mathbf{A}^k = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}$ | 只需对特征值求幂 |
| 矩阵函数 | $f(\mathbf{A}) = \mathbf{P}f(\mathbf{D})\mathbf{P}^{-1}$ | 转化为标量函数 $f(\lambda_i)$ |
| 差分方程 | $\mathbf{x}_k = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}\mathbf{x}_0$ | $n$ 维耦合 $\rightarrow$ $n$ 个独立演化 |
| 正交对角化 | $\mathbf{A} = \mathbf{Q}\mathbf{D}\mathbf{Q}^T$（$\mathbf{Q}^{-1} = \mathbf{Q}^T$） | 实对称矩阵的特权，数值更稳定 |
| Jordan 标准形 | $\mathbf{A} = \mathbf{P}\mathbf{J}\mathbf{P}^{-1}$ | 不可对角化时的"次优"替代 |

## 相关链接
- [[Eigenvalues and Eigenvectors]]（对角化的前提知识）
- [[Matrix Operations#9. 矩阵乘方（Matrix Exponentiation）]]（对角化在矩阵乘方中的应用）
- [[Linear Transformations#7. 基变换与坐标变换]]（相似变换的几何解释）
- [[Vector Spaces and Subspaces]]（特征空间与特征基）
