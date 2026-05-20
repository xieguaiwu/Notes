---
tags:
  - Math
  - LinearAlgebra
  - 定义性
title: Inner Product and Norm
created: 2026-05-20
modified:
---

# Inner Product and Norm

## 1. 核心概念：一句话概括

**内积**（inner product）是向量之间"夹角"和"长度"的代数推广——让我们能在抽象的[[Vector Spaces and Subspaces|向量空间]]中测量角度和距离；**范数**（norm）是"长度"概念的推广，用来衡量一个向量的大小。

## 2. 内积（Inner Product）

### 2.1 标准内积（点积）

R^n 中最常见的内积就是**点积**（dot product），已在 [[Vector and Matrix#场景一：计算向量的点积（内积）]] 中介绍：

$$\langle x, y \rangle = x^T y = \sum_{i=1}^n x_i y_i$$

### 2.2 一般内积的定义

内积是一个二元函数 <,>: V x V -> R，满足：

| 性质 | 公式 |
|------|------|
| **对称性** | <x, y> = <y, x> |
| **线性（第一变元）** | <c1 x1 + c2 x2, y> = c1 <x1, y> + c2 <x2, y> |
| **正定性** | <x, x> >= 0，等号成立 iff x = 0 |

### 2.3 其他内积的例子

**加权内积**（Weighted Inner Product）：

$$\langle x, y \rangle = \sum_{i=1}^n w_i x_i y_i, \quad w_i > 0$$

**函数空间的内积**（L^2 内积）：

$$\langle f, g \rangle = \int_a^b f(t) g(t) \, dt$$

## 3. 范数（Norm）

### 3.1 由内积诱导的范数

内积可以自然地诱导出一个"长度"概念：

$$||x|| = \sqrt{\langle x, x \rangle}$$

对于标准内积，得到**欧几里得范数**（L2 范数）：

$$||x||_2 = \sqrt{x_1^2 + x_2^2 + \cdots + x_n^2}$$

### 3.2 常见的向量范数

| 范数 | 公式 | 直观理解 |
|------|------|---------|
| **L1 范数**（曼哈顿范数） | $||x||_1 = \sum |x_i|$ | 各坐标绝对值之和 |
| **L2 范数**（欧几里得范数） | $||x||_2 = \sqrt{\sum x_i^2}$ | 到原点的直线距离 |
| **L_inf 范数**（最大值范数） | $||x||_\infty = \max_i |x_i|$ | 最大坐标绝对值 |
| **p-范数**（一般） | $||x||_p = (\sum |x_i|^p)^{1/p}$ | 上述的推广 |

### 3.3 范数公理

范数 ||.||: V -> R 必须满足：

1. **正定性**：||x|| >= 0，且 ||x|| = 0 iff x = 0
2. **齐次性**：||c x|| = |c| ||x||
3. **三角不等式**：||x + y|| <= ||x|| + ||y||

## 4. 长度、距离与角度

### 4.1 向量的长度

$$||x|| = \sqrt{\langle x, x \rangle}$$

### 4.2 向量之间的距离

$$d(x, y) = ||x - y||$$

这就是欧几里得距离：

$$d(x, y) = \sqrt{(x_1 - y_1)^2 + \cdots + (x_n - y_n)^2}$$

### 4.3 向量之间的夹角

利用内积定义两个向量的夹角 theta：

$$\cos\theta = \frac{\langle x, y \rangle}{||x|| \; ||y||}$$

**几何直观**：
- cos theta = 1：同向，y = c x, c > 0
- cos theta = -1：反向，y = c x, c < 0
- cos theta = 0：**正交**（垂直），<x, y> = 0

### 4.4 Cauchy-Schwarz 不等式

$$|\langle x, y \rangle| \le ||x|| \; ||y||$$

等号成立 iff x 与 y 线性相关。

> [!tip] 直觉
> 从余弦公式来看，因为 |cos theta| <= 1，所以这是显然的。但它在抽象内积空间中是一个深刻的结论。

## 5. 正交性（Orthogonality）

### 5.1 正交的定义

$$x \perp y \iff \langle x, y \rangle = 0$$

零向量与任何向量正交。

### 5.2 正交基

一组基中向量两两正交，称为**正交基**（orthogonal basis）。

如果还满足每个基向量长度均为 1，称为**标准正交基**（orthonormal basis）：

$$\langle q_i, q_j \rangle = \begin{cases} 1 & i = j \\ 0 & i \neq j \end{cases}$$

### 5.3 标准正交基的好处

在标准正交基下，向量的坐标可以用内积直接计算：

$$v = \sum_{i=1}^n \langle v, q_i \rangle q_i$$

即每个坐标分量就是 v 与该基向量的内积。

### 5.4 Gram-Schmidt 正交化

将任意一组线性无关的向量 {v_1, ..., v_k} 转化为标准正交基的算法：

```
u1 = v1
u2 = v2 - (<v2,u1>/<u1,u1>) u1
u3 = v3 - (<v3,u1>/<u1,u1>) u1 - (<v3,u2>/<u2,u2>) u2
...
```

最后将每个 u_i 归一化（除以长度）即得标准正交基。

## 6. 正交投影

### 6.1 投影到向量

x 在 y 方向上的正交投影：

$$\text{proj}_y(x) = \frac{\langle x, y \rangle}{\langle y, y \rangle} y$$

### 6.2 投影到子空间

给定标准正交基 {q_1, ..., q_k}，x 到子空间 W 的投影：

$$\text{proj}_W(x) = \sum_{i=1}^k \langle x, q_i \rangle q_i$$

**几何意义**：投影是子空间中最接近 x 的点。

```
          x
          |
          |  (x - proj 垂直于子空间)
          |
          v
     ---- proj ----  (子空间 W)
```

## 7. QR 分解

将矩阵 A 分解为：

$$A = Q R$$

- Q：列标准正交的矩阵（Q^T Q = I）
- R：上三角矩阵

计算方法：对 A 的列执行 Gram-Schmidt 正交化 -> Q；记录系数 -> R。

**应用**：
- 求解线性最小二乘问题
- 特征值算法（QR algorithm）的基础

## 8. 范数的对比与选择

| 范数 | 适用场景 | 优点 |
|------|---------|------|
| L1 | 稀疏性、Lasso 回归 | 鼓励稀疏解，对异常值鲁棒 |
| L2 | 大多数常规场景 | 光滑、可微、计算稳定 |
| L_inf | 均匀误差控制 | 强调最大偏差最小化 |
| Frobenius（矩阵范数） | 矩阵整体大小的度量 | 相当于矩阵元素的 L2 范数 |

> [!note] 范数的等价性
> 在有限维空间中，所有范数都是等价的：存在常数 c, C > 0 使得 c||x||_p <= ||x||_q <= C||x||_p。这意味着用不同范数衡量收敛性，结论一致。

## 9. 在 NumPy 中的体现

```python
import numpy as np

x = np.array([3, -4])
y = np.array([1, 2])

# 内积
dot = np.dot(x, y)
print(f"x.y = {dot}")

# 各种范数
norm_l1 = np.linalg.norm(x, ord=1)
norm_l2 = np.linalg.norm(x, ord=2)
norm_inf = np.linalg.norm(x, ord=np.inf)
print(f"||x||_1 = {norm_l1}, ||x||_2 = {norm_l2}, ||x||_oo = {norm_inf}")

# 距离
distance = np.linalg.norm(x - y)
print(f"d(x, y) = {distance}")

# 夹角
cos_theta = np.dot(x, y) / (np.linalg.norm(x) * np.linalg.norm(y))
print(f"cos(theta) = {cos_theta:.4f}, theta = {np.arccos(cos_theta):.4f} rad")

# Gram-Schmidt 正交化
def gram_schmidt(A):
    Q = np.zeros_like(A, dtype=float)
    for i in range(A.shape[1]):
        q = A[:, i].copy()
        for j in range(i):
            q -= np.dot(A[:, i], Q[:, j]) * Q[:, j]
        Q[:, i] = q / np.linalg.norm(q)
    return Q

A = np.array([[1, 1], [1, 0], [0, 1]], dtype=float)
Q = gram_schmidt(A)
print("正交基:\n", Q)
print("Q^T Q = I?\n", Q.T @ Q)
```

## 相关链接
- [[Vector and Matrix]]（点积的基础）
- [[Vector Spaces and Subspaces]]（内积空间是向量空间的扩展）
- [[Linear Systems and Gaussian Elimination]]（最小二乘法的几何基础）
- [[Eigenvalues and Eigenvectors]]（对称矩阵的正交对角化）
- [[Diagonalization]]（正交对角化）
