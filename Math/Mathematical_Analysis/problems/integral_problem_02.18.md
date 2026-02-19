---
tags:
  - Math
  - Calculus
  - 证明
  - Exercise
title: integral_problem_02.18
created: 2026-02-18T16:58:00
modified:
---
# integral_problem_02.18
## 1.
>下图是函数$f$的导函数，其中在$x\in [-2,2]$间存在一个**半圆**，已知$f(2)=1$，求$f(-5)$

![[integral_problem_02.18.png]]
题目的关键在于如何逆用微积分基本定理（见[[Definite Integrals]]）：
$$f(b)-f(a)=\int^b_af'(x)dx$$
那么
$$f(2) - f(-5) = \int_{-5}^{2} f'(x)dx$$
其中
$$\int^2_{-5}f'(x)dx=A_{三角形}-A_{半圆}=3-2\pi$$
$$f(-5)=1-(3-2\pi)$$
$$f(-5)=2\pi-2$$

## 2.
$$\int^2_0\ln(3-x)^2dx$$
换元： 令 $u = 3-x$，则 $du = -dx$
$$-\int_3^1 (\ln u)^2 \, du = \int_1^3 (\ln u)^2 \, du$$
设 $v = (\ln u)^2$，$dw = du$，则 $dv = \frac{2\ln u}{u}du$，$w = u$
$$\int (\ln u)^2 \, du = u(\ln u)^2 - 2\int \ln u \, du$$
  再求 $\displaystyle\int \ln u \, du$：

  $$\int \ln u \, du = u\ln u - u + C$$
 因此：
  $$\int (\ln u)^2 \, du = u(\ln u)^2 - 2u\ln u + 2u + C$$
代入上下限计算
$$\begin{aligned}
\int_1^3 (\ln u)^2 \, du &= \Big[u(\ln u)^2 - 2u\ln u + 2u\Big]_1^3 \\[6pt]
  &= \big[3(\ln 3)^2 - 6\ln 3 + 6\big] - \big[1 \cdot 0 - 0 + 2\big] \\[6pt]
  &= 3(\ln 3)^2 - 6\ln 3 + 6 - 2 \\[6pt]
  &= \boxed{3(\ln 3)^2 - 6\ln 3 + 4}
\end{aligned}$$
  