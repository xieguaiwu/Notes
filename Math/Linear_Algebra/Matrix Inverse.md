---
tags:
  - Math
  - LinearAlgebra
  - 方法性
title: Matrix Inverse
created: 2026-06-02
modified:
---

# Matrix Inverse

> [!abstract] 概述
> 逆矩阵是线性代数中核心概念之一——对于 $n$ 阶方阵 $\mathbf{A}$，逆矩阵 $\mathbf{A}^{-1}$ 满足 $\mathbf{A}\mathbf{A}^{-1} = \mathbf{A}^{-1}\mathbf{A} = \mathbf{I}_n$。[[Matrix Operations#8 逆矩阵 Inverse Matrix]] 中已介绍了二阶矩阵的求逆公式，本文在此基础上给出 $n \ge 3$ 时的一般求解方法。

## 1. 从二阶到 $n$ 阶：直觉

二阶矩阵的逆有简洁公式：
$$
\mathbf{A}^{-1} = \frac{1}{\det(\mathbf{A})} \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}
$$

但对于 $3\times3$ 及以上，不存在如此简单的封闭公式（原因：$n$ 阶逆矩阵包含 $n^2$ 个元素，每个元素是 $n-1$ 阶子式与行列式的组合，复杂度随 $n$ 爆炸增长）。因此需要系统性的算法。

## 2. 方法一：高斯-若尔当消元法（Gauss-Jordan Elimination）

**最推荐的手算方法**，也是计算机实现的标准方式。核心思想是**用初等行变换将 $\mathbf{A}$ 化为 $\mathbf{I}$ 的同时，将 $\mathbf{I}$ 变为 $\mathbf{A}^{-1}$**。

> [!tip] 为什么可行？
> 初等行变换可以表示为一个初等矩阵 $\mathbf{E}_i$ 左乘。若依次施加的初等行变换的复合为 $\mathbf{E}$，则 $\mathbf{E}\mathbf{A} = \mathbf{I}$，即 $\mathbf{E} = \mathbf{A}^{-1}$。与此同时 $\mathbf{E}\mathbf{I} = \mathbf{E} = \mathbf{A}^{-1}$，所以 $\mathbf{I}$ 经过同样的行变换就变成了 $\mathbf{A}^{-1}$。

### 2.1 算法步骤

```
输入：n 阶方阵 A

1. 构造增广矩阵 [A | I_n]
2. 从左到右逐列处理：
   a. 选主元：当前列中从当前行向下的绝对值最大元素（部分主元）
   b. 若主元所在行不是当前行，交换两行
   c. 将主元行除以主元值，使主元变为 1
   d. 用主元行消去当前列其他行的所有元素（使该列除主元外全为 0）
3. 当 A 部分变为 I_n 时，右侧 I_n 已变为 A⁻¹
```

### 2.2 完整例子：$3\times3$ 矩阵

求 $\mathbf{A} = \begin{bmatrix} 1 & 2 & 1 \\ 0 & -2 & 2 \\ 2 & 3 & 1 \end{bmatrix}$ 的逆矩阵。

**Step 1: 构造增广矩阵**

$$
\left[\begin{array}{ccc|ccc}
1 & 2 & 1 & 1 & 0 & 0 \\
0 & -2 & 2 & 0 & 1 & 0 \\
2 & 3 & 1 & 0 & 0 & 1
\end{array}\right]
$$

**Step 2: 处理第 1 列**

列 1 中主元选 $a_{31} = 2$（绝对值最大），交换 $R_1 \leftrightarrow R_3$：

$$
\left[\begin{array}{ccc|ccc}
2 & 3 & 1 & 0 & 0 & 1 \\
0 & -2 & 2 & 0 & 1 & 0 \\
1 & 2 & 1 & 1 & 0 & 0
\end{array}\right]
$$

$R_1 \to \frac12 R_1$（主元化为 1）：

$$
\left[\begin{array}{ccc|ccc}
1 & \frac32 & \frac12 & 0 & 0 & \frac12 \\
0 & -2 & 2 & 0 & 1 & 0 \\
1 & 2 & 1 & 1 & 0 & 0
\end{array}\right]
$$

$R_3 \to R_3 - R_1$（消去第 1 列的第 3 行）：

$$
\left[\begin{array}{ccc|ccc}
1 & \frac32 & \frac12 & 0 & 0 & \frac12 \\
0 & -2 & 2 & 0 & 1 & 0 \\
0 & \frac12 & \frac12 & 1 & 0 & -\frac12
\end{array}\right]
$$

**Step 3: 处理第 2 列**

第 2 列主元选 $a_{22} = -2$，无需交换。$R_2 \to -\frac12 R_2$：

$$
\left[\begin{array}{ccc|ccc}
1 & \frac32 & \frac12 & 0 & 0 & \frac12 \\
0 & 1 & -1 & 0 & -\frac12 & 0 \\
0 & \frac12 & \frac12 & 1 & 0 & -\frac12
\end{array}\right]
$$

$R_1 \to R_1 - \frac32 R_2$，$R_3 \to R_3 - \frac12 R_2$：

$$
\left[\begin{array}{ccc|ccc}
1 & 0 & 2 & 0 & \frac34 & \frac12 \\
0 & 1 & -1 & 0 & -\frac12 & 0 \\
0 & 0 & 1 & 1 & \frac14 & -\frac12
\end{array}\right]
$$

**Step 4: 处理第 3 列**

$R_1 \to R_1 - 2R_3$，$R_2 \to R_2 + R_3$：

$$
\left[\begin{array}{ccc|ccc}
1 & 0 & 0 & -2 & \frac14 & \frac32 \\
0 & 1 & 0 & 1 & -\frac14 & -\frac12 \\
0 & 0 & 1 & 1 & \frac14 & -\frac12
\end{array}\right]
$$

**Step 5: 读出结果**

右侧即为 $\mathbf{A}^{-1}$：

$$
\mathbf{A}^{-1} = \begin{bmatrix}
-2 & \frac14 & \frac32 \\[4pt]
1 & -\frac14 & -\frac12 \\[4pt]
1 & \frac14 & -\frac12
\end{bmatrix}
$$

> [!note] 验算
> $$ \mathbf{A}\mathbf{A}^{-1} = \begin{bmatrix}
> 1 & 2 & 1 \\
> 0 & -2 & 2 \\
> 2 & 3 & 1
> \end{bmatrix}
> \begin{bmatrix}
> -2 & \frac14 & \frac32 \\
> 1 & -\frac14 & -\frac12 \\
> 1 & \frac14 & -\frac12
> \end{bmatrix}
> = \begin{bmatrix}
> 1 & 0 & 0 \\
> 0 & 1 & 0 \\
> 0 & 0 & 1
> \end{bmatrix}
> $$

### 2.3 何时无解？

如果在消元过程中出现全零行（$\mathbf{A}$ 部分的一整行全为 0），说明 $\mathbf{A}$ **不可逆**（行列式为 0，即奇异矩阵），中止计算。

## 3. 方法二：伴随矩阵法（Adjugate / Cofactor Method）

理论价值最高，手算 $n\ge4$ 时计算量过大。

### 3.1 基本公式

$$
\mathbf{A}^{-1} = \frac{1}{\det(\mathbf{A})} \cdot \operatorname{adj}(\mathbf{A})
$$

其中 $\operatorname{adj}(\mathbf{A})$ 是 $\mathbf{A}$ 的**伴随矩阵**（adjugate matrix），即**余子式矩阵的转置**。

### 3.2 步骤分解

以 $3\times3$ 矩阵 $\mathbf{A} = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{bmatrix}$ 为例：

**① 计算每个元素的余子式 $M_{ij}$**

余子式 $M_{ij}$ = 去掉第 $i$ 行、第 $j$ 列后的 $(n-1)$ 阶子矩阵的行列式。

例如 $M_{11}$（去掉第 1 行第 1 列）：

$$
M_{11} = \det\begin{bmatrix} a_{22} & a_{23} \\ a_{32} & a_{33} \end{bmatrix} = a_{22}a_{33} - a_{23}a_{32}
$$

**② 计算代数余子式 $C_{ij}$**

$$
C_{ij} = (-1)^{i+j} M_{ij}
$$

符号规律（棋盘式）：正负交替

$$
\begin{bmatrix}
+ & - & + \\
- & + & - \\
+ & - & +
\end{bmatrix}
$$

**③ 构造余子式矩阵，再转置得到伴随矩阵**

$$
\operatorname{adj}(\mathbf{A}) = \begin{bmatrix}
C_{11} & C_{12} & C_{13} \\
C_{21} & C_{22} & C_{23} \\
C_{31} & C_{32} & C_{33}
\end{bmatrix}^{\!T}
= \begin{bmatrix}
C_{11} & C_{21} & C_{31} \\
C_{12} & C_{22} & C_{32} \\
C_{13} & C_{23} & C_{33}
\end{bmatrix}
$$

**④ 除以行列式**

$$
\mathbf{A}^{-1} = \frac{1}{\det(\mathbf{A})} \begin{bmatrix}
C_{11} & C_{21} & C_{31} \\
C_{12} & C_{22} & C_{32} \\
C_{13} & C_{23} & C_{33}
\end{bmatrix}
$$

### 3.3 用伴随矩阵法重算上例

对于 $\mathbf{A} = \begin{bmatrix} 1 & 2 & 1 \\ 0 & -2 & 2 \\ 2 & 3 & 1 \end{bmatrix}$：

**余子式计算：**

$$
\begin{aligned}
M_{11} &= \det\begin{bmatrix} -2 & 2 \\ 3 & 1 \end{bmatrix} = (-2)(1) - (2)(3) = -8 \\
M_{12} &= \det\begin{bmatrix} 0 & 2 \\ 2 & 1 \end{bmatrix} = (0)(1) - (2)(2) = -4 \\
M_{13} &= \det\begin{bmatrix} 0 & -2 \\ 2 & 3 \end{bmatrix} = (0)(3) - (-2)(2) = 4 \\
M_{21} &= \det\begin{bmatrix} 2 & 1 \\ 3 & 1 \end{bmatrix} = (2)(1) - (1)(3) = -1 \\
M_{22} &= \det\begin{bmatrix} 1 & 1 \\ 2 & 1 \end{bmatrix} = (1)(1) - (1)(2) = -1 \\
M_{23} &= \det\begin{bmatrix} 1 & 2 \\ 2 & 3 \end{bmatrix} = (1)(3) - (2)(2) = -1 \\
M_{31} &= \det\begin{bmatrix} 2 & 1 \\ -2 & 2 \end{bmatrix} = (2)(2) - (1)(-2) = 6 \\
M_{32} &= \det\begin{bmatrix} 1 & 1 \\ 0 & 2 \end{bmatrix} = (1)(2) - (1)(0) = 2 \\
M_{33} &= \det\begin{bmatrix} 1 & 2 \\ 0 & -2 \end{bmatrix} = (1)(-2) - (2)(0) = -2
\end{aligned}
$$

**代数余子式（带上符号）：**

$$
\begin{aligned}
C_{11} = +M_{11} = -8, &\quad C_{12} = -M_{12} = 4, \quad C_{13} = +M_{13} = 4 \\
C_{21} = -M_{21} = 1,  &\quad C_{22} = +M_{22} = -1, \quad C_{23} = -M_{23} = 1 \\
C_{31} = +M_{31} = 6,  &\quad C_{32} = -M_{32} = -2, \quad C_{33} = +M_{33} = -2
\end{aligned}
$$

**伴随矩阵（转置）：**

$$
\operatorname{adj}(\mathbf{A}) = \begin{bmatrix}
C_{11} & C_{21} & C_{31} \\
C_{12} & C_{22} & C_{32} \\
C_{13} & C_{23} & C_{33}
\end{bmatrix}
= \begin{bmatrix}
-8 & 1 & 6 \\
4 & -1 & -2 \\
4 & 1 & -2
\end{bmatrix}
$$

**行列式**（按第 1 行展开）：

$$
\begin{aligned}
\det(\mathbf{A}) &= a_{11}C_{11} + a_{12}C_{12} + a_{13}C_{13} \\
&= (1)(-8) + (2)(4) + (1)(4) = -8 + 8 + 4 = 4
\end{aligned}
$$

**逆矩阵：**

$$
\mathbf{A}^{-1} = \frac{1}{4} \begin{bmatrix}
-8 & 1 & 6 \\
4 & -1 & -2 \\
4 & 1 & -2
\end{bmatrix}
= \begin{bmatrix}
-2 & \frac14 & \frac32 \\
1 & -\frac14 & -\frac12 \\
1 & \frac14 & -\frac12
\end{bmatrix}
$$

与方法一结果一致。

### 3.4 优点与局限

| 优点 | 局限 |
|------|------|
| 公式直观，理论推导常用 | 计算量 $O(n!)$ 级别——$n$ 每增加 1，余子式计算量暴增 |
| 可直接得到逆矩阵的解析表达式 | $n \ge 4$ 时手算极不现实 |
| 对符号矩阵（含参数）有效 | 数值上不稳定（浮点误差累积） |

> [!warning] 实用建议
> - **手算**：$n = 3$ 可用伴随矩阵法或高斯-若尔当；$n \ge 4$ 始终用高斯-若尔当
> - **编程**：永远不用显式求逆，而是解线性方程组 $\mathbf{A}\mathbf{x} = \mathbf{b}$（对应 Python 的 `np.linalg.solve()`）
> - **数值计算**：永远不用伴随矩阵法（数值灾难），用 `np.linalg.inv()` 内部调用 LAPACK

## 4. 方法三：分块矩阵求逆（Block Matrix Inversion）

适用于有**特殊分块结构**的大矩阵，如：
$$
\mathbf{M} = \begin{bmatrix} \mathbf{A} & \mathbf{B} \\ \mathbf{C} & \mathbf{D} \end{bmatrix}
$$

其中 $\mathbf{A}, \mathbf{D}$ 为方阵。

### 4.1 若 $\mathbf{A}$ 可逆

$$
\mathbf{M}^{-1} = \begin{bmatrix}
\mathbf{A}^{-1} + \mathbf{A}^{-1}\mathbf{B}\mathbf{S}^{-1}\mathbf{C}\mathbf{A}^{-1} & -\mathbf{A}^{-1}\mathbf{B}\mathbf{S}^{-1} \\
-\mathbf{S}^{-1}\mathbf{C}\mathbf{A}^{-1} & \mathbf{S}^{-1}
\end{bmatrix}
$$
其中 $\mathbf{S} = \mathbf{D} - \mathbf{C}\mathbf{A}^{-1}\mathbf{B}$ 称为 **Schur 补**。

### 4.2 若 $\mathbf{D}$ 可逆（等价形式）

$$
\mathbf{M}^{-1} = \begin{bmatrix}
\mathbf{T}^{-1} & -\mathbf{T}^{-1}\mathbf{B}\mathbf{D}^{-1} \\
-\mathbf{D}^{-1}\mathbf{C}\mathbf{T}^{-1} & \mathbf{D}^{-1} + \mathbf{D}^{-1}\mathbf{C}\mathbf{T}^{-1}\mathbf{B}\mathbf{D}^{-1}
\end{bmatrix}
$$
其中 $\mathbf{T} = \mathbf{A} - \mathbf{B}\mathbf{D}^{-1}\mathbf{C}$。

> [!tip] 何时用分块法？
> 当 $\mathbf{A}$ 或 $\mathbf{D}$ 有简单结构（如对角矩阵、稀疏矩阵）时，分块法可将大规模求逆化为多个小规模求逆，显著减少计算量。

## 5. 方法对比

| 方法 | 手算 $3\times3$ | 手算 $n\ge4$ | 编程实现 | 适用场景 |
|------|:---:|:---:|:---:|---------|
| **高斯-若尔当** | ✅ 推荐 | ✅ 唯一可行 | $O(n^3)$ | 通用首选 |
| **伴随矩阵法** | ✅ 可选 | ❌ 计算量爆炸 | ❌ 数值不稳 | 理论推导、含参数的符号矩阵 |
| **分块法** | ❌ 杀鸡用牛刀 | ⚠️ 需特殊结构 | $O(n^3)$ | 大型稀疏/块对角矩阵 |
| `np.linalg.inv()` | — | — | $O(n^3)$ | 编程实践（底层用 LAPACK 的 LU 分解） |

## 6. 数值稳定性

> [!warning] 不建议显式求逆
> 在实际数值计算中，绝大多数场景下**不需要显式计算 $\mathbf{A}^{-1}$**。求解 $\mathbf{A}\mathbf{x} = \mathbf{b}$ 时，使用求解器而非 $\mathbf{x} = \mathbf{A}^{-1}\mathbf{b}$——后者更慢且数值误差更大。
>
> ```python
> # ❌ 不推荐
> x = np.linalg.inv(A) @ b
>
> # ✅ 推荐
> x = np.linalg.solve(A, b)
> ```

**为何避免显式求逆：**

| 问题 | 说明 |
|------|------|
| **计算量** | 求逆 $O(n^3)$，求解 $O(n^3)$ 但常数更小 |
| **数值误差** | 求逆过程放大舍入误差，解方程更稳定 |
| **稀疏破坏** | 逆矩阵通常是稠密的，即使原矩阵是稀疏的 |

### 条件数（Condition Number）

矩阵 $\mathbf{A}$ 的**条件数** $\kappa(\mathbf{A}) = \|\mathbf{A}\| \cdot \|\mathbf{A}^{-1}\|$ 衡量矩阵对误差的敏感程度：

- $\kappa(\mathbf{A})$ **小** → 矩阵"良态"，求逆稳定
- $\kappa(\mathbf{A})$ **大** → 矩阵"病态"，求逆结果对输入误差高度敏感
- $\kappa(\mathbf{A}) \to \infty$ → 矩阵接近奇异，数值上不可逆

> [!tip] Python 中计算条件数
> ```python
> import numpy as np
> kappa = np.linalg.cond(A)  # 默认使用 2-范数
> ```

## 相关链接

- [[Matrix Operations]]（矩阵基础运算，含二阶逆矩阵公式）
- [[Linear Systems and Gaussian Elimination]]（高斯消元基础）
- [[Determinant]]（行列式——伴随矩阵法的前置知识）
- [[Rank and Nullity]]（可逆 ⟺ 满秩）
- [[Vector Spaces and Subspaces]]（可逆变换的几何意义）
