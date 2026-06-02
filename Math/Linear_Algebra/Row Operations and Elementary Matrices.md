---
tags:
  - Math
  - LinearAlgebra
  - 方法性
title: Row Operations and Elementary Matrices
created: 2026-06-02
modified:
---

# Row Operations and Elementary Matrices

> [!abstract] 概述
> 矩阵的**初等行变换**（Elementary Row Operations）是线性代数中最基础的操作工具——高斯消元、求逆矩阵、计算行列式全都建立在它之上。每一种行变换都对应一个**初等矩阵**（Elementary Matrix）的左乘，这一视角将行变换纳入矩阵乘法的统一框架。

## 1. 三种初等行变换

对矩阵进行行操作，等价于对方程组做合法变形：保持解集不变。

### 1.1 行交换（Row Swap / Switch）

$$
R_i \leftrightarrow R_j
$$

交换第 $i$ 行和第 $j$ 行的位置。

**例子：**

$$
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\xrightarrow{R_1 \leftrightarrow R_3}
\begin{bmatrix}
7 & 8 & 9 \\
4 & 5 & 6 \\
1 & 2 & 3
\end{bmatrix}
$$

**逆操作**：自身——再交换一次即恢复，即 $(R_i \leftrightarrow R_j)^{-1} = R_i \leftrightarrow R_j$。

> [!tip] switch 的直观含义
> "switch" 即交换两行的物理位置。在高斯消元中，它用于将绝对值大的元素"换"到主元位置（部分主元法），以提升数值稳定性。

### 1.2 行倍乘（Row Scaling）

$$
R_i \to kR_i \quad (k \neq 0)
$$

将第 $i$ 行所有元素乘以非零常数 $k$。

**例子：**

$$
\begin{bmatrix}
2 & 4 & 6 \\
3 & 5 & 7
\end{bmatrix}
\xrightarrow{R_1 \to \frac12 R_1}
\begin{bmatrix}
1 & 2 & 3 \\
3 & 5 & 7
\end{bmatrix}
$$

**逆操作**：$R_i \to \frac1k R_i$。

> [!warning] $k = 0$ 禁止
> 乘以 0 会丢失信息，不可逆——改变方程组的解集，不是合法的行变换。

### 1.3 行倍加（Row Addition / Replacement）

$$
R_i \to R_i + kR_j \quad (i \neq j)
$$

将第 $j$ 行的 $k$ 倍加到第 $i$ 行，第 $j$ 行本身不变。

**例子：**

$$
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{bmatrix}
\xrightarrow{R_2 \to R_2 - 4R_1}
\begin{bmatrix}
1 & 2 & 3 \\
0 & -3 & -6
\end{bmatrix}
$$

这是高斯消元中最核心的操作——用于消去主元下方的元素。

**逆操作**：$R_i \to R_i - kR_j$。

## 2. Switch 操作的深层理解

"交换两行"看似简单，但在矩阵理论中有深远含义。

### 2.1 Switch 作为置换矩阵

行交换 $\equiv$ **左乘一个置换矩阵**（Permutation Matrix）。具体来说，交换 $R_i \leftrightarrow R_j$ 等价于左乘将单位矩阵第 $i$、$j$ 行交换后得到的矩阵。

**例子**：交换 $3\times3$ 矩阵的 $R_1$ 和 $R_3$：

$$
\mathbf{P} = \begin{bmatrix}
0 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 0
\end{bmatrix},
\quad
\mathbf{P}\mathbf{A} = \begin{bmatrix}
0 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 0
\end{bmatrix}
\begin{bmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{bmatrix}
= \begin{bmatrix}
a_{31} & a_{32} & a_{33} \\
a_{21} & a_{22} & a_{23} \\
a_{11} & a_{12} & a_{13}
\end{bmatrix}
$$

验证：$\mathbf{P}$ 的第 1 行 $(0,0,1)$ 取 $\mathbf{A}$ 第 3 行 → 结果第 1 行 = $\mathbf{A}$ 第 3 行。这正是 $R_1 \leftrightarrow R_3$。

### 2.2 置换矩阵的性质

| 性质 | 说明 |
|------|------|
| **每行每列恰有一个 1** | 其余为 0 |
| **正交性** | $\mathbf{P}^T = \mathbf{P}^{-1}$（置换矩阵是正交矩阵） |
| **行列式** | $\det(\mathbf{P}) = \pm 1$（偶置换为 +1，奇置换为 -1） |
| **乘积** | 两个置换矩阵的乘积仍是置换矩阵（置换群封闭） |

每次行交换对应 $\det = -1$，因此 $\det(\mathbf{P}) = (-1)^{\#\text{swaps}}$。

> [!tip] 列交换呢？
> 列交换不是行变换，但等价于**右乘**一个置换矩阵：$\mathbf{A}\mathbf{P}$。行变换：左乘；列变换：右乘。

## 3. 初等矩阵（Elementary Matrices）

将行变换**代数化**：每一种行变换都对应一个"对 $\mathbf{I}_n$ 施加同样操作"后得到的初等矩阵 $\mathbf{E}$。施加行变换 $\equiv$ 左乘 $\mathbf{E}$。

### 3.1 三种初等矩阵

| 行变换 | 初等矩阵 $\mathbf{E}$ | 例子（$3\times3$） |
|-------|----------------------|-------------------|
| $R_i \leftrightarrow R_j$ | $\mathbf{E}$ = 交换 $\mathbf{I}$ 的 $i,j$ 行 | $\begin{bmatrix}0&0&1\\0&1&0\\1&0&0\end{bmatrix}$ |
| $R_i \to kR_i$ | $\mathbf{E}$ = 将 $\mathbf{I}$ 的 $(i,i)$ 改为 $k$ | $\begin{bmatrix}1&0&0\\0&k&0\\0&0&1\end{bmatrix}$ |
| $R_i \to R_i + kR_j$ | $\mathbf{E}$ = 在 $\mathbf{I}$ 的 $(i,j)$ 处放 $k$ | $\begin{bmatrix}1&0&0\\k&1&0\\0&0&1\end{bmatrix}$ |

### 3.2 初等矩阵的逆

每种行变换可逆 $\iff$ 每个初等矩阵可逆，且逆矩阵也是初等矩阵：

| 初等矩阵 $\mathbf{E}$ | $\mathbf{E}^{-1}$ |
|----------------------|-------------------|
| 交换 $i,j$ 行 | 自身（再交换一次） |
| $R_i \to kR_i$ | $R_i \to \frac1k R_i$ |
| $R_i \to R_i + kR_j$ | $R_i \to R_i - kR_j$ |

### 3.3 完整例子

用初等矩阵重现高斯-若尔当求逆过程（[[Matrix Inverse#2 方法一 高斯-若尔当消元法 Gauss-Jordan Elimination]] 中的例题）：

$$
\mathbf{A} = \begin{bmatrix} 1 & 2 & 1 \\ 0 & -2 & 2 \\ 2 & 3 & 1 \end{bmatrix}
$$

**Step 1:** 交换 $R_1 \leftrightarrow R_3$

$$
\mathbf{E}_1 = \begin{bmatrix} 0 & 0 & 1 \\ 0 & 1 & 0 \\ 1 & 0 & 0 \end{bmatrix},\quad
\mathbf{E}_1\mathbf{A} = \begin{bmatrix} 2 & 3 & 1 \\ 0 & -2 & 2 \\ 1 & 2 & 1 \end{bmatrix}
$$

**Step 2:** $R_1 \to \frac12 R_1$

$$
\mathbf{E}_2 = \begin{bmatrix} \frac12 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix},\quad
\mathbf{E}_2(\mathbf{E}_1\mathbf{A}) = \begin{bmatrix} 1 & \frac32 & \frac12 \\ 0 & -2 & 2 \\ 1 & 2 & 1 \end{bmatrix}
$$

**Step 3:** $R_3 \to R_3 - R_1$

$$
\mathbf{E}_3 = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ -1 & 0 & 1 \end{bmatrix},\quad
\mathbf{E}_3(\mathbf{E}_2\mathbf{E}_1\mathbf{A}) = \begin{bmatrix} 1 & \frac32 & \frac12 \\ 0 & -2 & 2 \\ 0 & \frac12 & \frac12 \end{bmatrix}
$$

**如此继续……最终：**

$$
\mathbf{E}_k \cdots \mathbf{E}_2\mathbf{E}_1 \mathbf{A} = \mathbf{I} \quad\Longrightarrow\quad \mathbf{A}^{-1} = \mathbf{E}_k \cdots \mathbf{E}_2\mathbf{E}_1
$$

这正是高斯-若尔当法的代数本质：**初等矩阵的乘积就是逆矩阵**。

## 4. 行变换的几何直觉

### 4.1 左乘改变行空间

行变换 $\equiv$ 左乘 $\mathbf{E}$，本质是对矩阵的**行向量进行重组**。三种变换分别对应：

| 行变换 | 几何含义 |
|-------|---------|
| $R_i \leftrightarrow R_j$ | 重新排列基向量的顺序 |
| $R_i \to kR_i$ | 拉伸/压缩某个基向量方向 |
| $R_i \to R_i + kR_j$ | 沿一个方向"剪切"另一个方向（[[Linear Transformations]] 中的 shear 变换） |

### 4.2 为什么行变换保持解集？

对于线性方程组 $\mathbf{A}\mathbf{x} = \mathbf{b}$，左乘可逆矩阵 $\mathbf{E}$ 得到 $\mathbf{E}\mathbf{A}\mathbf{x} = \mathbf{E}\mathbf{b}$。因为 $\mathbf{E}$ 可逆，新方程组与原方程组是**等价变形**：若 $\mathbf{x}$ 满足原式，则左乘 $\mathbf{E}$ 后也满足新式；反之，若满足新式，左乘 $\mathbf{E}^{-1}$ 即回到原式。解集完全相同。

这就是所有行变换必须可逆的根本原因。

## 5. 列变换（Column Operations）

虽然本笔记聚焦行变换，列变换与之**对偶**：行变换 = 左乘，列变换 = 右乘。

| 操作 | 行变换 | 列变换 |
|------|--------|--------|
| 乘法方向 | 左乘 $\mathbf{E}$ | 右乘 $\mathbf{E}$ |
| 效果 | 重组行向量 | 重组列向量 |
| 解集 | 保持（方程组视角） | **改变**解集 |
| 求逆 | 高斯-若尔当用行变换 | 也可用列变换（不常用） |

> [!warning] 求解方程组时只用行变换
> 列变换会改变变量顺序（相当于重新排列未知数），解集不再对应原来的变量，因此求解 $\mathbf{A}\mathbf{x} = \mathbf{b}$ 时禁止使用列变换。

## 6. 与 LU 分解的联系

一个可逆矩阵 $\mathbf{A}$ 可以通过行变换分解为：

$$
\mathbf{P}\mathbf{A} = \mathbf{L}\mathbf{U}
$$

其中：
- $\mathbf{P}$ 是**置换矩阵**（记录所有 switch 操作的复合）
- $\mathbf{L}$ 是**单位下三角矩阵**（记录所有倍加操作）
- $\mathbf{U}$ 是**上三角矩阵**（消元结果）

> 详见 PLU 分解的相关笔记。

## 相关链接

- [[Linear Systems and Gaussian Elimination]]（初等行变换在高斯消元中的应用）
- [[Matrix Inverse]]（高斯-若尔当求逆法——行变换的完整实例）
- [[Matrix Operations]]（矩阵乘法基础）
- [[Linear Transformations]]（行变换作为剪切操作的几何视角）
