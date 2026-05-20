---
tags:
  - Math
  - LinearAlgebra
  - 概念性
title: Linear Transformations
created: 2026-05-20
modified:
---

# Linear Transformations

## 1. 核心概念：一句话概括

**线性变换**（linear transformation）是将向量映射到向量的函数，满足两条核心规则：**加法保持**和**数乘保持**。而**每一个**从 R^n 到 R^m 的线性变换，都对应一个唯一的 m x n 矩阵——这就是为什么矩阵如此重要。

## 2. 定义

### 2.1 线性变换的定义

从向量空间 V 到 W 的映射 T: V -> W 称为**线性变换**，如果：

1. **可加性**（Additivity）：T(u + v) = T(u) + T(v)，对所有 u, v in V
2. **齐次性**（Homogeneity）：T(c v) = c T(v)，对所有 v in V 和标量 c

这两条可以合并为一条：

$$T(c_1 v_1 + c_2 v_2) = c_1 T(v_1) + c_2 T(v_2)$$

### 2.2 等价说法

- T 保持**线性组合**
- T 保持向量空间的线性结构
- T 将直线映射到直线（或点），将原点映射到原点：T(0) = 0

### 2.3 常见例子

| 变换 | 公式 | 几何效果 |
|------|------|---------|
| 缩放 | T(x) = k x | 沿各个方向均匀拉伸 k 倍 |
| 旋转（角度 theta） | T(x) = R(theta) x | 逆时针旋转 theta |
| 剪切 | T(x,y) = (x + ky, y) | 水平方向错切 |
| 投影到 x 轴 | T(x,y) = (x, 0) | 投影到 x 轴 |
| 反射 | T(x,y) = (x, -y) | 关于 x 轴对称 |

## 3. 线性变换的矩阵表示

### 3.1 标准矩阵

任何线性变换 T: R^n -> R^m 都可以表示为：

$$T(x) = A x$$

其中 A 是 m x n 矩阵，称为 T 的**标准矩阵**。

如何求标准矩阵？将标准基 e_1, ..., e_n 分别作为输入，变换后的输出按列排列：

$$A = [ T(e_1)  T(e_2)  ...  T(e_n) ]$$

### 3.2 例子

求逆时针旋转 90 度的矩阵。

$$T(e_1) = T(1,0) = (0,1), T(e_2) = T(0,1) = (-1,0)$$

$$A = \begin{bmatrix} 0 & -1 \\ 1 & 0 \end{bmatrix}$$

验证：A [x; y] = [-y; x]

### 3.3 一般基下的矩阵表示

如果选定了 V 的基 B 和 W 的基 C，则 T: V -> W 可以表示为矩阵 [T]_{C <- B}。

记 [v]_B 为 v 在基 B 下的[[Vector Spaces and Subspaces#7.3 坐标|坐标]]，则：

$$[T(v)]_C = [T]_{C \leftarrow B} [v]_B$$

> [!tip] 与 [[Diagonalization]] 的关系
> 对角化中的 P 本质上就是基变换矩阵——它将特征向量基下的坐标变换到标准基。对角化的 D 则是在特征向量基下线性变换的简单（对角）表示。

## 4. 线性变换的核与像

### 4.1 核（Kernel）/ 零空间

$$\ker(T) = \{ v \in V \mid T(v) = 0 \}$$

当 T 由矩阵 A 表示时，ker(T) = Null(A)（见 [[Rank and Nullity#2.3 零空间]]）。

**几何意义**：所有被 T 压缩到零的向量。

### 4.2 像（Image）/ 值域

$$\text{Im}(T) = \{ T(v) \mid v \in V \}$$

当 T 由矩阵 A 表示时，Im(T) = Col(A)（见 [[Rank and Nullity#2.1 列空间]]）。

**几何意义**：T 所有可能的输出。

### 4.3 秩-零化度定理（线性变换版本）

对于线性变换 T: V -> W：

$$\dim(V) = \dim(\ker(T)) + \dim(\text{Im}(T))$$

这正是 [[Rank and Nullity#5. 秩-零化度定理]] 在抽象线性变换下的推广。

## 5. 线性变换的复合

### 5.1 复合 = 矩阵乘法

如果 T: R^n -> R^m 的矩阵为 A，S: R^m -> R^p 的矩阵为 B，则复合变换 S o T: R^n -> R^p：

$$(S \circ T)(x) = S(T(x)) = B(A x) = (BA)x$$

**因此**：线性变换的复合对应矩阵乘法 BA。

> [!abstract] 深层理解
> 这就是为什么[[Matrix Operations#4. 矩阵乘法（核心重点）|矩阵乘法]]定义为"行乘列"——它是复合变换的自然代数表示。

### 5.2 顺序很重要！

$$S \circ T \neq T \circ S$$（一般情况下）

对应矩阵：BA != AB——解释了矩阵乘法不满足交换律的几何本质。

```
   x ----> T(x) ----> S(T(x))
   |                    |
   |  矩阵 A            |  矩阵 BA
   +--------------------+
```

## 6. 单射、满射与同构

### 6.1 单射（Injective / One-to-one）

T 是单射 iff ker(T) = {0} iff nullity(T) = 0

即不同输入映射到不同输出。

### 6.2 满射（Surjective / Onto）

T 是满射 iff Im(T) = W iff rank(T) = dim(W)

即每个输出都能被某个输入映射到。

### 6.3 同构（Isomorphism）

T 既是单射又是满射，则称为**同构**。此时：
- dim(V) = dim(W)
- T 可逆，T^{-1} 也是线性变换
- 从矩阵角度：方阵 A 可逆

> [!note] 维数是同构不变量
> 两个有限维向量空间同构 iff 它们维数相同。

## 7. 基变换与坐标变换

设同一向量 v 在基 B 和基 C 下的坐标分别为 [v]_B 和 [v]_C，则：

$$[v]_C = P_{C \leftarrow B} [v]_B$$

其中 P_{C <- B} 是**基变换矩阵**，它的列就是 B 的基向量在基 C 下的坐标。

基变换矩阵 P 正好连接了同一个线性变换在不同基下的矩阵表示：

$$[T]_C = P^{-1} [T]_B P$$

这正是[[Diagonalization]]中相似变换的核心公式。

## 8. 线性变换的概念图

```
          线性变换 T: V -> W
               |
      +--------+--------+
      |                  |
   核 ker(T)          像 Im(T)
      |                  |
  T(v) = 0          所有可能的输出
      |                  |
      +--------+--------+
               |
        秩-零化度定理
    dim(V) = dim(ker) + dim(Im)
               |
       +-------+-------+
       |               |
    单射 (ker={0})   满射 (Im=W)
       |               |
       +-------+-------+
               |
         同构 (可逆)
```

## 9. 在 NumPy 中的体现

```python
import numpy as np

# 定义线性变换：旋转 + 缩放
theta = np.pi / 4
A = np.array([[np.cos(theta), -np.sin(theta), 0],
              [np.sin(theta),  np.cos(theta), 0],
              [0,              0,             2]])

# 应用变换
v = np.array([1, 0, 1])
T_v = A @ v
print(f"v = {v} -> T(v) = {T_v}")

# 验证线性性
u = np.array([2, 3, 4])
c = 5
print("T(u+v) == T(u) + T(v)?", np.allclose(A @ (u+v), A @ u + A @ v))
print("T(cv) == c T(v)?", np.allclose(A @ (c*v), c * (A @ v)))

# 核（零空间）
U, s, Vt = np.linalg.svd(A)
null_mask = s < 1e-10
if np.any(null_mask):
    print("核的基向量:", Vt[null_mask])
else:
    print("核为 {0}，变换是单射")

# 像（列空间的维数 = 秩）
print("像的维数 = 秩 =", np.linalg.matrix_rank(A))
```

## 相关链接
- [[Vector Spaces and Subspaces]]（变换的定义域与值域）
- [[Rank and Nullity]]（核与像的维数关系）
- [[Matrix Operations]]（线性变换的代数实现）
- [[Diagonalization]]（基变换的极简表示）
- [[Eigenvalues and Eigenvectors]]（变换的不变方向）
