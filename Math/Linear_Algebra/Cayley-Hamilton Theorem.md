---
tags:
  - Math
  - LinearAlgebra
  - 定理性
  - 方法性
title: Cayley-Hamilton Theorem
created: 2026-06-25
modified:
---

# Cayley-Hamilton Theorem

## 1. 定理陈述

设 $A \in \mathbb{C}^{n \times n}$，$p(\lambda) = \det(\lambda I - A) = \lambda^n + c_{n-1}\lambda^{n-1} + \cdots + c_1\lambda + c_0$ 是 $A$ 的**特征多项式**。则

$$
p(A) = A^n + c_{n-1}A^{n-1} + \cdots + c_1 A + c_0 I = 0.
$$

即：**矩阵满足自己的特征方程**。这个结论初看反直觉——将矩阵代入以标量为变量的多项式并非自然的操作，但 Cayley-Hamilton 定理保证了这样做的结果是零矩阵。

## 2. 证明思路（简要）

**情况 1 — 可对角化：** 若 $A = PDP^{-1}$ 且 $D = \operatorname{diag}(\lambda_1,\dots,\lambda_n)$，则

$$
p(A) = P \cdot p(D) \cdot P^{-1} = P \cdot \operatorname{diag}\big(p(\lambda_1),\dots,p(\lambda_n)\big) \cdot P^{-1}.
$$

每个 $\lambda_i$ 是特征多项式 $p(\lambda)$ 的根，故 $p(\lambda_i) = 0$，从而 $p(D) = 0$，$p(A) = 0$。

**情况 2 — 一般方阵：** 对不可对角化矩阵，利用伴随矩阵恒等式 $(\lambda I - A) \cdot \operatorname{adj}(\lambda I - A) = p(\lambda) I$。将右端 $p(\lambda)I$ 展开为 $\lambda$ 的多项式矩阵，对比系数后代入 $A$，发现每一项均消去。此论证避免了可对角化假设，适用于所有方阵。

## 3. 例子

### 3.1 一般 $2 \times 2$

设 $A = \begin{bmatrix}a & b \\ c & d\end{bmatrix}$，特征多项式为 $p(\lambda) = \lambda^2 - (\operatorname{tr} A)\lambda + \det A$。定理断言：

$$
A^2 - (\operatorname{tr} A) A + (\det A) I = 0.
$$

**验证：** 直接展开 $A^2$ 并代入即得恒等式。

### 3.2 数值 $2 \times 2$

$$A = \begin{bmatrix}1 & 2 \\ 3 & 4\end{bmatrix},\quad p(\lambda) = \lambda^2 - 5\lambda - 2.$$

$$A^2 = \begin{bmatrix}7 & 10 \\ 15 & 22\end{bmatrix},\quad
A^2 - 5A - 2I = \begin{bmatrix}0 & 0 \\ 0 & 0\end{bmatrix}.$$

### 3.3 数值 $3 \times 3$

$$A = \begin{bmatrix}2 & 1 & 0 \\ 0 & 2 & 1 \\ 0 & 0 & 2\end{bmatrix},\quad p(\lambda) = (\lambda-2)^3 = \lambda^3 - 6\lambda^2 + 12\lambda - 8.$$

计算得 $A^3 - 6A^2 + 12A - 8I = 0$（验证略，幂零部分可自行代入确认）。

## 4. 核心推论

### 4.1 高次幂的降阶表示

对 $n$ 阶矩阵 $A$，任何 $A^k\;(k \ge n)$ 均可表示为 $I, A, A^2, \dots, A^{n-1}$ 的线性组合。反复使用 $A^n = -c_{n-1}A^{n-1} - \cdots - c_0 I$ 即得递推约化。

### 4.2 逆矩阵的表达

若 $A$ 可逆（$c_0 = (-1)^n \det A \ne 0$），由 $p(A) = 0$ 得：

$$
A^{-1} = -\frac{1}{c_0}\big(A^{n-1} + c_{n-1}A^{n-2} + \cdots + c_1 I\big).
$$

这给出了逆矩阵的一个多项式表达式，无需高斯消元。

## 5. 最小多项式

特征多项式 $p(\lambda)$ 是矩阵 $A$ 的一个**零化多项式**（即 $p(A) = 0$）。所有零化多项式中次数最低的首一多项式称为**最小多项式** $\mu(\lambda)$。由 Cayley-Hamilton 定理直接可知 $\mu(\lambda) \mid p(\lambda)$，且 $\mu(\lambda)$ 与 $p(\lambda)$ 含相同的**不同特征根**。最小多项式能揭示特征值的代数重数与几何重数的差异——这正是 [[Jordan Canonical Form]] 的核心话题。

## 6. 与 [[Diagonalization]] 的关系

矩阵可对角化当且仅当其最小多项式无重根（即每个特征值的代数重数等于几何重数）。Cayley-Hamilton 定理保证特征多项式包含对角化所需的所有特征值信息，但要判断是否真的可以对角化，需检查最小多项式的根结构而非仅仅特征多项式的根结构。

## 7. 数值计算中的意义

直接计算矩阵的高次幂 $A^k$（如 PageRank 的稳态迭代）复杂度为 $O(k n^3)$。利用 Cayley-Hamilton 定理可将幂运算转化为 $I, A, \dots, A^{n-1}$ 的线性组合，这些低次幂可并行计算或复用。结合特征值分解或 Krylov 子空间方法（如 Arnoldi 迭代），Cayley-Hamilton 为矩阵函数 $f(A)$ 的高效数值逼近提供了理论基础。
