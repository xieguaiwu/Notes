---
tags:
  - Math
  - LinearAlgebra
  - 定义性
title: Matrix Operations
created: 2026-05-20T12:00:00
modified:
---
# Matrix Operations

## 1. 核心概念：什么是矩阵？

**矩阵**（Matrix）是一个按**行**和**列**排列的矩形数表。一个 $m \times n$ 的矩阵有 $m$ 行、$n$ 列：

$$
\mathbf{A} = \begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{bmatrix}
$$

其中 $a_{ij}$ 表示第 $i$ 行、第 $j$ 列的元素。矩阵是线性代数中最基本的对象之一，[[Vector and Matrix]] 中已介绍向量作为矩阵的特例（$n \times 1$ 列向量或 $1 \times n$ 行向量）。

---

## 2. 矩阵加法与减法

两个**同型**（行数列数相同）矩阵可以逐元素相加（减）：

$$
\mathbf{A} + \mathbf{B} = \begin{bmatrix}
a_{11}+b_{11} & a_{12}+b_{12} & \cdots & a_{1n}+b_{1n} \\
a_{21}+b_{21} & a_{22}+b_{22} & \cdots & a_{2n}+b_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1}+b_{m1} & a_{m2}+b_{m2} & \cdots & a_{mn}+b_{mn}
\end{bmatrix}
$$

**例子：**

$$
\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} + \begin{bmatrix} 5 & 6 \\ 7 & 8 \end{bmatrix} = \begin{bmatrix} 6 & 8 \\ 10 & 12 \end{bmatrix}
$$

**性质：**
- **交换律**：$\mathbf{A} + \mathbf{B} = \mathbf{B} + \mathbf{A}$
- **结合律**：$(\mathbf{A} + \mathbf{B}) + \mathbf{C} = \mathbf{A} + (\mathbf{B} + \mathbf{C})$
- **零矩阵**：$\mathbf{A} + \mathbf{0} = \mathbf{A}$，其中 $\mathbf{0}$ 是所有元素为 0 的矩阵

---

## 3. 标量乘法（数乘）

一个矩阵乘以一个标量（实数）$k$，等于每个元素乘以 $k$：

$$
k\mathbf{A} = \begin{bmatrix}
k a_{11} & k a_{12} & \cdots & k a_{1n} \\
k a_{21} & k a_{22} & \cdots & k a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
k a_{m1} & k a_{m2} & \cdots & k a_{mn}
\end{bmatrix}
$$

**例子：**

$$
3 \times \begin{bmatrix} 1 & -2 \\ 0 & 4 \end{bmatrix} = \begin{bmatrix} 3 & -6 \\ 0 & 12 \end{bmatrix}
$$

**性质：**
- $k(\mathbf{A} + \mathbf{B}) = k\mathbf{A} + k\mathbf{B}$
- $(k_1 + k_2)\mathbf{A} = k_1\mathbf{A} + k_2\mathbf{A}$
- $(k_1 k_2)\mathbf{A} = k_1(k_2\mathbf{A})$

---

## 4. 矩阵乘法（核心重点）

矩阵乘法 **不是** 逐元素相乘，而是"**行乘列**"法则。这是线性代数中最重要也最易错的操作。

### 4.1 核心直觉：为什么要这样乘？

矩阵乘法 $\mathbf{A}\mathbf{B}$ 的本质是：**用 $\mathbf{A}$ 的每一行，去"点积" $\mathbf{B}$ 的每一列**。

> 回忆 [[Vector and Matrix]] 中的向量点积：$\mathbf{a} \cdot \mathbf{b} = \sum a_i b_i$
>
> 矩阵乘法就是把这个操作推广到了矩阵的每个行-列对之间。

### 4.2 乘法的条件（维度匹配）

$\mathbf{A}$ 与 $\mathbf{B}$ 可乘 $\iff$ **$\mathbf{A}$ 的列数 $=$ $\mathbf{B}$ 的行数**

$$
\boxed{\mathbf{A}_{m \times \color{red}{n}} \quad \mathbf{B}_{\color{red}{p} \times q} \quad\Longrightarrow\quad \color{red}{n = p}}
$$

结果矩阵的形状是 $m \times q$（取 $\mathbf{A}$ 的行数、$\mathbf{B}$ 的列数）：

$$
\mathbf{A}_{m \times \color{red}{n}} \cdot \mathbf{B}_{\color{red}{n} \times q} = \mathbf{C}_{m \times q}
$$

> **记忆口诀**：左列 = 右行，结果取"左行右列"
>
> $(\text{行},\,\text{列}) \cdot (\text{行},\,\text{列}) \to$ 消去中间的列和行，留下 $(\text{左行},\,\text{右列})$

### 4.3 计算方法：一步一步拆解

结果矩阵 $\mathbf{C} = \mathbf{A}\mathbf{B}$ 中，第 $i$ 行第 $j$ 列的元素 $c_{ij}$ 等于：

$$
c_{ij} = \mathbf{A} \text{ 的第 } i \text{ 行} \;\cdot\; \mathbf{B} \text{ 的第 } j \text{ 列}
       = \sum_{k=1}^{n} a_{ik}\, b_{kj}
       = a_{i1}b_{1j} + a_{i2}b_{2j} + \cdots + a_{in}b_{nj}
$$

**直观示意（$2\times2$ 为例）：**

$$
\begin{aligned}
\mathbf{A}\mathbf{B}
&= \begin{bmatrix}
\color{blue}{a_{11}} & \color{blue}{a_{12}} \\
a_{21} & a_{22}
\end{bmatrix}
\begin{bmatrix}
\color{red}{b_{11}} & b_{12} \\
\color{red}{b_{21}} & b_{22}
\end{bmatrix}
\\[6pt]
&= \begin{bmatrix}
\color{blue}{a_{11}}\color{red}{b_{11}} + \color{blue}{a_{12}}\color{red}{b_{21}} & \quad
\color{blue}{a_{11}}b_{12} + \color{blue}{a_{12}}b_{22} \\[4pt]
a_{21}\color{red}{b_{11}} + a_{22}\color{red}{b_{21}} & \quad
a_{21}b_{12} + a_{22}b_{22}
\end{bmatrix}
\end{aligned}
$$

**过程动画式分解（$2\times2$ 具体数值）：**

设：
$$
\mathbf{A} = \begin{bmatrix}
\color{blue}{1} & \color{blue}{2} \\
\color{green}{3} & \color{green}{4}
\end{bmatrix},\quad
\mathbf{B} = \begin{bmatrix}
\color{red}{5} & 6 \\
\color{red}{7} & 8
\end{bmatrix}
$$

**① 先算 $c_{11}$（第1行 × 第1列）：**
$$
c_{11} = \mathbf{A}_{1\text{行}} \cdot \mathbf{B}_{1\text{列}}
= \color{blue}{1}\times\color{red}{5} + \color{blue}{2}\times\color{red}{7}
= 5 + 14 = 19
$$

**② 再算 $c_{12}$（第1行 × 第2列）：**
$$
c_{12} = \mathbf{A}_{1\text{行}} \cdot \mathbf{B}_{2\text{列}}
= \color{blue}{1}\times 6 + \color{blue}{2}\times 8
= 6 + 16 = 22
$$

**③ 再算 $c_{21}$（第2行 × 第1列）：**
$$
c_{21} = \mathbf{A}_{2\text{行}} \cdot \mathbf{B}_{1\text{列}}
= \color{green}{3}\times\color{red}{5} + \color{green}{4}\times\color{red}{7}
= 15 + 28 = 43
$$

**④ 最后 $c_{22}$（第2行 × 第2列）：**
$$
c_{22} = \mathbf{A}_{2\text{行}} \cdot \mathbf{B}_{2\text{列}}
= \color{green}{3}\times 6 + \color{green}{4}\times 8
= 18 + 32 = 50
$$

**结果：**
$$
\mathbf{A}\mathbf{B} = \begin{bmatrix}
19 & 22 \\
43 & 50
\end{bmatrix}
$$

### 4.4 手算技巧："横着划，竖着对齐"

用笔算时，左手食指横着划过 $\mathbf{A}$ 的行，右手食指竖着划过 $\mathbf{B}$ 的列，交点处做点积：

$$
\underbrace{
\left[
\begin{array}{cc}
a_{11} & a_{12} \\ \hline
a_{21} & a_{22}
\end{array}
\right]
}_{\text{← 横着划}}
\qquad
\overbrace{
\begin{bmatrix}
b_{11} & b_{12} \\
b_{21} & b_{22}
\end{bmatrix}
}^{\text{竖着对齐 ↓}}
$$

### 4.5 更多形状的例子（加深理解）

**例1：$2\times3$ 乘 $3\times2$（非方阵）**

$$
\mathbf{A}_{2\times3} = \begin{bmatrix}
1 & 0 & 2 \\
-1 & 3 & 1
\end{bmatrix},\quad
\mathbf{B}_{3\times2} = \begin{bmatrix}
3 & 1 \\
2 & 1 \\
0 & -2
\end{bmatrix}
$$

维度检查：$\mathbf{A}_{2\times\color{red}{3}} \cdot \mathbf{B}_{\color{red}{3}\times2} \to$ 可乘，结果 $\mathbf{C}_{2\times2}$

$$
\begin{aligned}
\mathbf{A}\mathbf{B}
&= \begin{bmatrix}
(1)(3)+(0)(2)+(2)(0) & (1)(1)+(0)(1)+(2)(-2) \\
(-1)(3)+(3)(2)+(1)(0) & (-1)(1)+(3)(1)+(1)(-2)
\end{bmatrix} \\[6pt]
&= \begin{bmatrix}
3+0+0 & 1+0-4 \\
-3+6+0 & -1+3-2
\end{bmatrix}
= \begin{bmatrix}
3 & -3 \\
3 & 0
\end{bmatrix}
\end{aligned}
$$

**例2：$3\times2$ 乘 $2\times1$（矩阵乘列向量）**

$$
\mathbf{A}_{3\times2} = \begin{bmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{bmatrix},\quad
\mathbf{x}_{2\times1} = \begin{bmatrix}
x_1 \\ x_2
\end{bmatrix}
$$

$$
\mathbf{A}\mathbf{x} = \begin{bmatrix}
1x_1 + 2x_2 \\
3x_1 + 4x_2 \\
5x_1 + 6x_2
\end{bmatrix}
$$

这正是[[Vector and Matrix]]中 $\mathbf{w}^T\mathbf{x}$ 的推广：矩阵乘向量 = 用矩阵的行分别与向量做点积，结果是一个新向量。

### 4.6 常见错误（避坑）

| ❌ 错误 | ✅ 正确 |
|---------|---------|
| $\begin{bmatrix}1&2\\3&4\end{bmatrix} \begin{bmatrix}5&6\\7&8\end{bmatrix} = \begin{bmatrix}5&12\\21&32\end{bmatrix}$（逐元素乘） | 必须**行乘列**求和，不是对应位置相乘 |
| $\mathbf{A}\mathbf{B} = \mathbf{B}\mathbf{A}$（交换顺序） | 大多数情况下 $\mathbf{A}\mathbf{B} \neq \mathbf{B}\mathbf{A}$，甚至 $\mathbf{B}\mathbf{A}$ 可能维度不匹配无法计算 |
| $\mathbf{A}(\mathbf{B}\mathbf{C}) \neq (\mathbf{A}\mathbf{B})\mathbf{C}$ | 结合律**成立**，括号位置可随意移动（但顺序不变） |

### 4.7 重要性质

- **不满足交换律**：$\mathbf{A}\mathbf{B} \neq \mathbf{B}\mathbf{A}$（一般情况下，甚至 $\mathbf{B}\mathbf{A}$ 可能不合法）
- **满足结合律**：$(\mathbf{A}\mathbf{B})\mathbf{C} = \mathbf{A}(\mathbf{B}\mathbf{C})$（括号可重排，顺序不变）
- **满足分配律**：$\mathbf{A}(\mathbf{B} + \mathbf{C}) = \mathbf{A}\mathbf{B} + \mathbf{A}\mathbf{C}$，以及 $(\mathbf{A}+\mathbf{B})\mathbf{C} = \mathbf{A}\mathbf{C} + \mathbf{B}\mathbf{C}$
- 若 $\mathbf{A}\mathbf{B} = \mathbf{0}$，**不能**推出 $\mathbf{A} = \mathbf{0}$ 或 $\mathbf{B} = \mathbf{0}$（存在非零矩阵相乘得零矩阵）
- $\mathbf{A}\mathbf{B} = \mathbf{A}\mathbf{C}$ 且 $\mathbf{A} \neq \mathbf{0}$，**不能**推出 $\mathbf{B} = \mathbf{C}$（矩阵乘法不满足消去律）

### 4.8 乘法的几何直觉

矩阵乘法可以理解为**线性变换的复合**：

- $\mathbf{A}$ 是一个线性变换（将向量映射到另一个向量）
- $\mathbf{B}$ 是另一个线性变换
- $\mathbf{A}\mathbf{B}$ 表示**先做 $\mathbf{B}$ 变换，再做 $\mathbf{A}$ 变换**（注意顺序从右向左读！）

这解释了为什么矩阵乘法不交换：先旋转再拉伸 $\neq$ 先拉伸再旋转。

### 4.9 为什么矩阵乘法如此重要？

矩阵乘法是连接线性变换的桥梁，几乎所有现代科学计算都离不开它：

- **计算机图形学**：3D 场景中的旋转、平移、缩放和投影——每个操作都是一个矩阵，连续操作就是矩阵乘法。GPU 每秒执行数万亿次矩阵乘法来渲染每一帧画面。
- **神经网络与深度学习**：全连接层做的就是 $\mathbf{y} = \mathbf{W}\mathbf{x} + \mathbf{b}$——矩阵乘权重再偏置。整个深度学习就是一连串矩阵乘法的叠加。
- **PageRank 算法**：Google 将网页链接构造成一个矩阵，网页排名就是求这个矩阵的特征向量——每一步都要做矩阵乘向量。
- **控制论与机器人**：状态空间模型 $\mathbf{x}_{k+1} = \mathbf{A}\mathbf{x}_k + \mathbf{B}\mathbf{u}_k$ 中，矩阵乘法描述系统如何从当前状态演化到下一状态。

> 矩阵乘法在科学计算中无处不在，理解它就是理解线性代数的"语法"。

---

## 5. 转置（Transpose）

矩阵的转置将行变为列、列变为行，记作 $\mathbf{A}^T$ 或 $\mathbf{A}^{\top}$：

$$
\mathbf{A} = \begin{bmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \\ a_{31} & a_{32} \end{bmatrix}_{3\times2},
\quad
\mathbf{A}^T = \begin{bmatrix} a_{11} & a_{21} & a_{31} \\ a_{12} & a_{22} & a_{32} \end{bmatrix}_{2\times3}
$$

详细讨论见 [[Vector and Matrix]]。

**性质：**
- $(\mathbf{A}^T)^T = \mathbf{A}$
- $(\mathbf{A} + \mathbf{B})^T = \mathbf{A}^T + \mathbf{B}^T$
- $(k\mathbf{A})^T = k\mathbf{A}^T$
- $(\mathbf{A}\mathbf{B})^T = \mathbf{B}^T \mathbf{A}^T$

---

## 6. 特殊矩阵

### 6.1 单位矩阵（Identity Matrix）

主对角线为 1、其余为 0 的方阵，记作 $\mathbf{I}_n$（$n$ 阶）：

$$
\mathbf{I}_3 = \begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
$$

单位矩阵是矩阵乘法的"单位元"：$\mathbf{A}\mathbf{I} = \mathbf{I}\mathbf{A} = \mathbf{A}$（当维度匹配时）。

> **现实直觉**：单位矩阵就像数字运算中的 $1$——任何数乘以 $1$ 不变，任何矩阵乘以单位矩阵不变。在图形学中，单位矩阵表示"不做任何变换"。

### 6.2 零矩阵（Zero Matrix）

所有元素均为 0 的矩阵，记作 $\mathbf{0}$，是矩阵加法的"零元"。

> **现实直觉**：零矩阵就像数字 $0$——加零不变，乘零为零。零矩阵表示"把一切映射到原点"的变换——任何向量乘零矩阵都变成零向量。

### 6.3 对角矩阵（Diagonal Matrix）

非对角线元素全为 0 的方阵：

$$
\mathbf{D} = \begin{bmatrix}
d_1 & 0 & \cdots & 0 \\
0 & d_2 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & d_n
\end{bmatrix}
$$

> **现实直觉**：对角矩阵是"最友好"的矩阵——它只沿着各坐标轴方向独立伸缩，不做任何旋转或混合。在图像处理中，对 RGB 三个通道分别调整亮度，就是一个 $3\times 3$ 对角矩阵。对角化的终极目标就是把任意矩阵化简为这种形式。

### 6.4 对称矩阵（Symmetric Matrix）

满足 $\mathbf{A}^T = \mathbf{A}$ 的方阵，即 $a_{ij} = a_{ji}$。

> **现实直觉**：对称矩阵 $\mathbf{A}^T = \mathbf{A}$ 意味着"双向作用对称"——如果 $a_{ij}$ 表示节点 $i$ 到节点 $j$ 的权重，那么对称矩阵就表示连接是**无向的**（双向等权）。图的邻接矩阵、距离矩阵、协方差矩阵都是对称的。对称矩阵一定可对角化（谱定理），且特征值都是实数——这是 PCA（主成分分析）的数学基础。

---

## 7. 行列式（Determinant）

行列式是一个将**方阵**映射到标量的函数，记作 $\det(\mathbf{A})$ 或 $|\mathbf{A}|$。

### 7.1 二阶行列式

$$
\det\begin{pmatrix} a & b \\ c & d \end{pmatrix} = ad - bc
$$

### 7.2 三阶行列式

$$
\det\begin{pmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}
= a_{11}a_{22}a_{33} + a_{12}a_{23}a_{31} + a_{13}a_{21}a_{32}
- a_{13}a_{22}a_{31} - a_{12}a_{21}a_{33} - a_{11}a_{23}a_{32}
$$

### 7.3 几何意义

二阶行列式的绝对值等于以两个行（列）向量为边的**平行四边形的面积**；三阶行列式的绝对值等于以三个行（列）向量为棱的**平行六面体的体积**。

**为什么这个几何意义如此重要？**

- **二维**：$\det(\mathbf{A})$ 的绝对值是两个列向量张成的平行四边形的面积。如果 $\det(\mathbf{A}) = 0$，两个列向量共线，面积为零——意味着 $\mathbf{A}$ 把平面压缩成一条线，信息丢失，不可逆。
- **三维**：$\det(\mathbf{A})$ 的绝对值是三个列向量张成的平行六面体的体积。$\det(\mathbf{A}) = 0$ 意味着三个向量共面或共线——体积为零，变换降维。
- **正负号**：表示变换是否改变了空间的**定向**（orientation）。$\det(\mathbf{A}) < 0$ 意味着变换做了"翻转"（如镜像反转）。

> **核心直觉**：行列式的绝对值 = **变换后体积的缩放因子**。如果一个区域的面积是 $S$，经过 $\mathbf{A}$ 变换后的面积就是 $|\det(\mathbf{A})| \cdot S$。
>
> 这解释了为什么 $\det(\mathbf{A}\mathbf{B}) = \det(\mathbf{A})\det(\mathbf{B})$：连续变换的总体积缩放因子等于各自缩放因子的乘积。
>
> 这也解释了 $\det(\mathbf{A}) \neq 0 \iff \mathbf{A}$ 可逆：体积缩放为 0 意味着变换压缩了空间维度，无法恢复——就像把 3D 物体拍成 2D 照片后丢失了深度信息。

---

## 8. 逆矩阵（Inverse Matrix）

对于 $n$ 阶方阵 $\mathbf{A}$，若存在 $\mathbf{A}^{-1}$ 使得：

$$
\mathbf{A}\mathbf{A}^{-1} = \mathbf{A}^{-1}\mathbf{A} = \mathbf{I}_n
$$

则称 $\mathbf{A}$ 可逆（非奇异），$\mathbf{A}^{-1}$ 为 $\mathbf{A}$ 的逆矩阵。

### 8.1 二阶矩阵的逆

$$
\mathbf{A} = \begin{bmatrix} a & b \\ c & d \end{bmatrix},\quad
\mathbf{A}^{-1} = \frac{1}{ad - bc} \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}
$$

其中 $ad - bc \neq 0$（即行列式不为零）。

**为什么公式长这样？一个直观推导**

设 $\mathbf{A}^{-1} = \begin{bmatrix} x_{11} & x_{12} \\ x_{21} & x_{22} \end{bmatrix}$，由 $\mathbf{A}\mathbf{A}^{-1} = \mathbf{I}$：

$$
\begin{bmatrix} a & b \\ c & d \end{bmatrix}
\begin{bmatrix} x_{11} & x_{12} \\ x_{21} & x_{22} \end{bmatrix}
= \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}
$$

这其实是 4 个方程组成的两组独立方程组（矩阵乘法按列来看）：

- 第一列：$\begin{cases} a x_{11} + b x_{21} = 1 \\ c x_{11} + d x_{21} = 0 \end{cases}$
- 第二列：$\begin{cases} a x_{12} + b x_{22} = 0 \\ c x_{12} + d x_{22} = 1 \end{cases}$

解这两个 $2\times 2$ 线性方程组（如消元法），即得 $\mathbf{A}^{-1} = \frac{1}{ad-bc}\begin{bmatrix} d & -b \\ -c & a \end{bmatrix}$。

**几何视角**：$\mathbf{A}^{-1}$ 的作用是"撤销" $\mathbf{A}$ 的线性变换。分母 $ad-bc$ 正是 $\det(\mathbf{A})$——变换的"面积缩放因子"。如果 $\det(\mathbf{A}) = 0$，变换把面积压缩为零（降维），信息丢失，自然不可逆。所以可逆 $\iff$ 行列式非零。

### 8.2 $n \ge 3$ 的一般求解

二阶公式无法推广到三阶及以上，需要系统性的算法，详见 [[Matrix Inverse]]。

### 8.3 性质

- $(\mathbf{A}^{-1})^{-1} = \mathbf{A}$
- $(\mathbf{A}\mathbf{B})^{-1} = \mathbf{B}^{-1}\mathbf{A}^{-1}$
- $(\mathbf{A}^T)^{-1} = (\mathbf{A}^{-1})^T$

---

## 9. 矩阵乘方（Matrix Exponentiation）

矩阵乘方 $\mathbf{A}^k$（$\mathbf{A}$ 为 $n\times n$ 方阵，$k$ 为正整数）即 $\mathbf{A}$ 自乘 $k$ 次。直接逐次相乘 $O(k n^3)$ 太慢，需要更聪明的方法。

### 9.1 二进制快速幂（Binary Exponentiation）— 通用首选

将 $k$ 拆为二进制表示，反复平方：

$$
\mathbf{A}^{13} = \mathbf{A}^{8} \cdot \mathbf{A}^{4} \cdot \mathbf{A}^{1},
\quad 13 = 1101_2
$$

**算法步骤：**

1. 依次计算 $\mathbf{A}, \mathbf{A}^2, \mathbf{A}^4, \mathbf{A}^8, \dots$（每次平方）
2. 将 $k$ 二进制位为 1 的幂次相乘

**例子：** 计算 $\mathbf{A}^5$

$$
\begin{aligned}
\mathbf{A}^1 &\quad (101_2\text{ 的第 0 位为 1}) \\
\mathbf{A}^2 &\quad (\text{第 1 位为 0，跳过}) \\
\mathbf{A}^4 &\quad (\text{第 2 位为 1}) \\
\mathbf{A}^5 &= \mathbf{A}^4 \cdot \mathbf{A}^1
\end{aligned}
$$

> **复杂度**：$O(\log k)$ 次乘法，每次 $O(n^3)$。**对任意方阵都适用**，是最通用的方法。

### 9.2 对角化法（Diagonalization）— 最快，但有条件

若 $\mathbf{A}$ 可对角化，即存在可逆矩阵 $\mathbf{P}$ 和对角矩阵 $\mathbf{D}$ 使得：

$$
\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}
$$

则：

$$
\mathbf{A}^k = \mathbf{P}\mathbf{D}^k \mathbf{P}^{-1}
$$

其中 $\mathbf{D}^k$ 只需对每个对角元求 $k$ 次幂：

$$
\mathbf{D} = \begin{bmatrix}
\lambda_1 & & \\
& \ddots & \\
& & \lambda_n
\end{bmatrix},\quad
\mathbf{D}^k = \begin{bmatrix}
\lambda_1^k & & \\
& \ddots & \\
& & \lambda_n^k
\end{bmatrix}
$$

**例子：** $\mathbf{A} = \begin{bmatrix} 2 & 0 \\ 0 & 3 \end{bmatrix}$ 已经是对角矩阵：

$$
\mathbf{A}^k = \begin{bmatrix} 2^k & 0 \\ 0 & 3^k \end{bmatrix}
$$

> **限制**：必须存在 $n$ 个线性无关的特征向量（即 $\mathbf{A}$ 可对角化）。
>
> **优势**：对角化只做一次 $O(n^3)$，之后对**任意 $k$ 都只需 $\mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}$**，适合多次计算不同指数。

### 9.3 Cayley-Hamilton 递推法

**Cayley-Hamilton 定理**：矩阵 $\mathbf{A}$ 满足其特征多项式 $p(\lambda) = \det(\lambda\mathbf{I} - \mathbf{A})$，即：

$$
p(\mathbf{A}) = \mathbf{A}^n + c_{n-1}\mathbf{A}^{n-1} + \cdots + c_0\mathbf{I} = \mathbf{0}
$$

因此 $\mathbf{A}^n$ 可表示为 $\mathbf{I}, \mathbf{A}, \dots, \mathbf{A}^{n-1}$ 的线性组合。同理，$\mathbf{A}^{n+1}, \mathbf{A}^{n+2}, \dots$ 都满足同一条**线性递推关系**。

于是 $\mathbf{A}^k$ 可用递推的快速算法（如线性递推倍增或 Kitamasa 法）在 $O(n^2 \log k) \sim O(n^3 \log k)$ 内算出。

> **适用场景**：不需要对角化条件，但不适合手算，通常用于编程实现。

### 9.4 特殊矩阵的闭式解

| 矩阵类型 | 条件 | 乘方结果 |
|---------|------|---------|
| **幂等矩阵** | $\mathbf{A}^2 = \mathbf{A}$ | $\mathbf{A}^k = \mathbf{A}$（投影矩阵） |
| **对合矩阵** | $\mathbf{A}^2 = \mathbf{I}$ | 周期为 2 |
| **幂零矩阵** | $\mathbf{A}^m = \mathbf{0}$ | $k \ge m$ 时 $\mathbf{A}^k = \mathbf{0}$ |
| **旋转矩阵** | $R(\theta) = \begin{bmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{bmatrix}$ | $R(\theta)^k = R(k\theta)$ |
| **Jordan 块** | $J(\lambda) = \begin{bmatrix} \lambda & 1 & & \\ & \lambda & \ddots & \\ & & \ddots & 1 \\ & & & \lambda \end{bmatrix}$ | 二项式展开形式（含组合数） |

### 9.5 方法对比

| 方法 | 复杂度 | 限制 | 推荐场景 |
|------|--------|------|---------|
| **二进制快速幂** | $O(n^3 \log k)$ | 无 | **通用首选** |
| 对角化 | $O(n^3)$（一次）+ $O(n^3)$ | 需可对角化 | 同一矩阵算多个不同 $k$ |
| Cayley-Hamilton 递推 | $O(n^2 \log k) \sim O(n^3 \log k)$ | 需特征多项式 | $n$ 小，$k$ 极大（如 $k > 10^9$） |
| 特殊闭式解 | $O(1)$ | 特定结构 | 具体问题具体分析 |

> **实用建议**：手算时优先看能否对角化或用特殊结构；编程实现一律用二进制快速幂。

---

## 10. 在 Python 中的体现（NumPy）

```python
import numpy as np

# 创建矩阵
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])

# 加法
print("A + B:\n", A + B)

# 标量乘法
print("3 * A:\n", 3 * A)

# 矩阵乘法
print("A @ B:\n", A @ B)       # Python 3.5+ 的 @ 运算符
print("np.dot(A, B):\n", np.dot(A, B))  # 等价写法

# 转置
print("A.T:\n", A.T)

# 行列式
print("det(A):", np.linalg.det(A))

# 逆矩阵
print("A^{-1}:\n", np.linalg.inv(A))

# 单位矩阵
I = np.eye(3)
print("I_3:\n", I)
```

输出：
```
A + B:
 [[ 6  8]
 [10 12]]
3 * A:
 [[ 3  6]
 [ 9 12]]
A @ B:
 [[19 22]
 [43 50]]
A.T:
 [[1 3]
 [2 4]]
det(A): -2.0000000000000004
A^{-1}:
 [[-2.   1. ]
 [ 1.5 -0.5]]
```
