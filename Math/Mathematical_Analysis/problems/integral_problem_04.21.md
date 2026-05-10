---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: integral_problem_04.21
created: 2026-04-21T20:51:50.930Z
modified:
---
# integral_problem_04.21
## Q1
> 对于某个连续函数 $f$，使用 $n$ 个等长子区间的右黎曼和来近似计算 $\displaystyle\int_0^2 f(x) \, dx$，其结果为 $\displaystyle\frac{2(n+1)(3n+2)}{n^2}$（对所有 $n$ 成立）。求 $\displaystyle\int_0^2 f(x) \, dx$ 的值。

**解析**：利用黎曼和与定积分的关系，**当子区间数 $n \to \infty$ 时，右黎曼和的极限等于定积分的精确值**。

计算过程：

已知右黎曼和为：
$$R_n = \frac{2(n+1)(3n+2)}{n^2}$$
$$R_n = \frac{6n^2 + 10n + 4}{n^2} = 6 + \frac{10}{n} + \frac{4}{n^2}$$
取极限 $n \to \infty$：
$$\int_0^2 f(x) \, dx = \lim_{n \to \infty} R_n = \lim_{n \to \infty} \left(6 + \frac{10}{n} + \frac{4}{n^2}\right) = 6 + 0 + 0 = 6$$

