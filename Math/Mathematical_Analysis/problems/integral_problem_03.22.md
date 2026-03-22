---
tags:
  - Calculus
  - Math
  - Exercise
  - 证明
title: integral_problem_03.22
created: 2026-03-22T12:03:00
modified:
---
# integral_problem_03.22
## Q1
>The velocity vector of a particle moving in the xy-plane has components given $\frac{dx}{dt} =\sin (t^2)$ and $\frac{dy}{dt} = e^{\cos(t)}$. At time $t= 4$ the position of the particle is $(2, 1)$.
>What is the **y-coordinate of the position** by vector at time $t= 3$?

对于这种题目，首先必须要注意的就是**光用积分只能求出位移，而求不出位置**，因为必须要以一个已知的位置作为基准才能根据位移得出当前的位置。

在这道题目中，已知的位置是$t=4\Rightarrow (2,1)$
所以在$t=3$时的$y$坐标应该用如下式子求出：
$$1-\int_3^4e^{\cos t}\approx 0.590$$

## Q2
>$$\int_3^\infty\frac{1}{x^2+9}dx$$

这是一个标准形式的反常积分。利用积分公式：
$$\int \frac{1}{x^2+a^2}dx = \frac{1}{a}\arctan\frac{x}{a} + C$$

**解答过程：**

$$\int_3^\infty\frac{1}{x^2+9}dx = \int_3^\infty\frac{1}{x^2+3^2}dx$$

$$= \lim_{b \to \infty} \left[\frac{1}{3}\arctan\frac{x}{3}\right]_3^b$$

$$= \frac{1}{3}\left(\lim_{b \to \infty}\arctan\frac{b}{3} - \arctan 1\right)$$

$$= \frac{1}{3}\left(\frac{\pi}{2} - \frac{\pi}{4}\right)$$

$$= \frac{1}{3} \cdot \frac{\pi}{4} = \boxed{\frac{\pi}{12}}$$