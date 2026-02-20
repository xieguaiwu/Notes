---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: integral_problem_02.21
created: 2026-02-21T01:46:00
modified:
---
# integral_problem_02.21
[[Indefinite Integration]]
[[trigonometric identity]]
$$\frac{1}{2}\int[2\cos(3\theta)]^2d\theta$$
展开后：
 $$\frac{1}{2}\int 4\cos^2(3\theta)\, d\theta = 2\int \cos^2(3\theta)\, d\theta$$
**IMP**：利用恒等式
$$\boxed{\cos^2 x = \dfrac{1+\cos 2x}{2}}$$
$$\cos^2(3\theta) = \frac{1+\cos(6\theta)}{2}$$

代入得：
  $$2\int \frac{1+\cos(6\theta)}{2}\, d\theta = \int [1+\cos(6\theta)]\, d\theta$$
逐项积分

  $$\int d\theta + \int \cos(6\theta)\, d\theta = \theta + \frac{\sin(6\theta)}{6} + C$$
