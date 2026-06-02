---
tags:
  - Math
  - LinearAlgebra
  - 方法性
title: 补充：2x2 Matrix Inverse - Gauss-Jordan Derivation
created: 2026-06-02
modified:
---

# 2x2 Matrix Inverse - Gauss-Jordan Derivation

> [!abstract] 概述
> 对于二阶矩阵，逆矩阵存在简洁的封闭公式 $A^{-1} = \dfrac{1}{ad-bc}\begin{pmatrix}d & -b \\ -c & a\end{pmatrix}$。本文用 [[Matrix Inverse#2 方法一 高斯-若尔当消元法 Gauss-Jordan Elimination|Gauss-Jordan 消元法]] 系统推导这一公式，展示增广矩阵行变换如何在一般情况下得到逆矩阵。

## 1. 问题设定

设 $A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}$，且 $A$ 可逆，即行列式 $\det(A) = ad - bc \neq 0$。目标是用 Gauss-Jordan 消元法推导 $A^{-1}$。

**核心思路**：将 $[A \mid I]$ 通过行初等变换化为 $[I \mid A^{-1}]$。

## 2. 构造增广矩阵

$$
[A \mid I] = \left[\begin{array}{cc|cc}
a & b & 1 & 0 \\
c & d & 0 & 1
\end{array}\right]
$$

## 3. 前向消去（化为行阶梯形）

选取 $(1,1) = a$ 为主元（先假设 $a \neq 0$，$a = 0$ 的情况见后文）。

$$
R_2 \leftarrow R_2 - \frac{c}{a}R_1
$$

逐元素计算：

$$
\begin{aligned}
R_2[1] &= c - \frac{c}{a} \cdot a = 0 \\[4pt]
R_2[2] &= d - \frac{c}{a} \cdot b = d - \frac{bc}{a} = \frac{ad - bc}{a} \\[4pt]
R_2[3] &= 0 - \frac{c}{a} \cdot 1 = -\frac{c}{a} \\[4pt]
R_2[4] &= 1 - \frac{c}{a} \cdot 0 = 1
\end{aligned}
$$

得到行阶梯形：

$$
\left[\begin{array}{cc|cc}
a & b & 1 & 0 \\
0 & \dfrac{ad-bc}{a} & -\dfrac{c}{a} & 1
\end{array}\right]
$$

主元为 $a$（第 1 行）和 $\dfrac{ad-bc}{a}$（第 2 行）。由于 $\det = ad-bc \neq 0$，第二个主元非零，矩阵满秩，可逆。

## 4. 后向消去（化为行最简形）

### 4.1 主元归一

先归一第 2 行主元：$R_2 \leftarrow \dfrac{a}{ad-bc}R_2$

$$
\left[\begin{array}{cc|cc}
a & b & 1 & 0 \\[4pt]
0 & 1 & -\dfrac{c}{ad-bc} & \dfrac{a}{ad-bc}
\end{array}\right]
$$

再归一第 1 行主元：$R_1 \leftarrow \dfrac{1}{a}R_1$

$$
\left[\begin{array}{cc|cc}
1 & \dfrac{b}{a} & \dfrac{1}{a} & 0 \\[8pt]
0 & 1 & -\dfrac{c}{ad-bc} & \dfrac{a}{ad-bc}
\end{array}\right]
$$

### 4.2 消去 $(1,2)$

$$
R_1 \leftarrow R_1 - \frac{b}{a}R_2
$$

计算右侧两列：

$$
\begin{aligned}
R_1[3] &= \frac{1}{a} - \frac{b}{a} \cdot \left(-\frac{c}{ad-bc}\right)
       = \frac{1}{a} + \frac{bc}{a(ad-bc)}
       = \frac{ad-bc + bc}{a(ad-bc)}
       = \frac{ad}{a(ad-bc)}
       = \frac{d}{ad-bc} \\[8pt]
R_1[4] &= 0 - \frac{b}{a} \cdot \frac{a}{ad-bc}
       = -\frac{b}{ad-bc}
\end{aligned}
$$

得到行最简形：

$$
\left[\begin{array}{cc|cc}
1 & 0 & \dfrac{d}{ad-bc} & -\dfrac{b}{ad-bc} \\[8pt]
0 & 1 & -\dfrac{c}{ad-bc} & \dfrac{a}{ad-bc}
\end{array}\right]
$$

## 5. 结果

右侧矩阵即为 $A^{-1}$：

$$
\boxed{A^{-1} = \begin{pmatrix}
\dfrac{d}{ad-bc} & -\dfrac{b}{ad-bc} \\[8pt]
-\dfrac{c}{ad-bc} & \dfrac{a}{ad-bc}
\end{pmatrix}
= \frac{1}{ad-bc}\begin{pmatrix}
d & -b \\
-c & a
\end{pmatrix}}
$$

> [!tip] 记忆口诀
> **主对角元互换，副对角元取反，除以行列式。**

## 6. 特殊情况：$a = 0$

若 $a = 0$，则 $\det = 0 \cdot d - b \cdot c = -bc \neq 0$，必有 $b \neq 0$ 且 $c \neq 0$。此时先交换行 $R_1 \leftrightarrow R_2$：

$$
\left[\begin{array}{cc|cc}
0 & b & 1 & 0 \\
c & d & 0 & 1
\end{array}\right]
\overset{R_1\leftrightarrow R_2}{\longrightarrow}
\left[\begin{array}{cc|cc}
c & d & 0 & 1 \\
0 & b & 1 & 0
\end{array}\right]
$$

以 $c$ 为主元继续推导，最终得出的公式与标准公式完全一致。

## 7. 验证

$$
\begin{aligned}
AA^{-1} &= \frac{1}{ad-bc}
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
\begin{pmatrix}
d & -b \\
-c & a
\end{pmatrix} \\[6pt]
&= \frac{1}{ad-bc}
\begin{pmatrix}
ad - bc & -ab + ba \\
cd - dc & -cb + da
\end{pmatrix} \\[6pt]
&= \frac{1}{ad-bc}
\begin{pmatrix}
ad-bc & 0 \\
0 & ad-bc
\end{pmatrix}
= I \quad ✅
\end{aligned}
$$

## 8. 操作总结

| 操作 | 目的 |
|---|---|
| $R_2 \leftarrow R_2 - \dfrac{c}{a}R_1$ | 消去 $(2,1)$ |
| $R_2 \leftarrow \dfrac{a}{ad-bc}R_2$ | 主元 $(2,2)$ 归一 |
| $R_1 \leftarrow \dfrac{1}{a}R_1$ | 主元 $(1,1)$ 归一 |
| $R_1 \leftarrow R_1 - \dfrac{b}{a}R_2$ | 消去 $(1,2)$ |

## 相关链接

- [[Augmented Matrix]]（增广矩阵的定义与操作）
- [[Matrix Inverse]]（逆矩阵的一般求法）
- [[Row Operations and Elementary Matrices]]（行变换 = 左乘初等矩阵）
- [[Linear Systems and Gaussian Elimination]]（高斯消元法）
- [[Matrix Operations#8 逆矩阵 Inverse Matrix]]（二阶逆矩阵的公式形式）
