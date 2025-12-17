---
tags:
  - Calculus
  - Math
  - 定义性
  - 证明
title: Definite Integrals
created: 2025-12-09T16:25:00
modified:
---
# Definite Integrals
## 1. Def - Riemann Method
![[measure_integration_2.png]]
首先，延续[[Indefinite Integration]]中**5.2**的思想，需要将一个连续函数的面积分割成足够小的份数，那么先定义
$$\text{mesh}=\max(\Delta x_1,\Delta x_2,\ldots,\Delta x_n)$$
之后只需要利用极限$\lim_{\text{mesh}\to 0}$就可以完成无限分割的工作，这个操作在**5.2**中是通过分割成无限份实现的（$\lim_{n\to\infty}\sum_i^n$），它们本质上是等值的
$$\int^b_af(x)dx=\lim_{\text{mesh}\to 0}\sum^n_{i=1}f(c_i)(x_i-x_{i-1})$$
这与[[Indefinite Integration]]中的求和方法别无二致，同样需要保证：
$$c_i\in[x_{i-1},x_i]$$
另一方面，对于upper limit和lower limit $a$和$b$：
$$a=x_0<x_1<\ldots<x_n=b$$
这些$x_n$形成了区间$[a,b]$当中每一个间隔的划分

可以看到，与[[Indefinite Integration]]相比，definite integral是一个固定的数值，而indefinite integral则是一组函数

结合[[continuity]]以及[[Differentiability and Continuity]]：
只要函数$f$在区间$[a,b]$上是连续的，那么$f$ is **integrable on $[a,b]$**，于是$\exists\int^b_af(x)dx$

---

## 2. Rules of Integrals
1. 假如$\exists f(a)$：$$\int^a_af(x)dx=0$$
2. If $f$ is integrable on $[a,b]$:$$\int^a_bf(x)dx=-\int^b_af(x)dx$$
3. 如果已知$c\in[a,b]$，那么$$\int^b_af(x)dx=\int^c_af(x)dx+\int^b_cf(x)dx$$
4. $$\int^b_ak\cdot f(x)dx=k\cdot\int^b_af(x)dx$$
5. $$\int^b_a[f(x)\pm(x)]dx=\int^b_af(x)dx\pm\int^b_ag(x)dx$$
6. 为了计算两个函数所积面积之间的面积
![[integral_between_two_functions.png]]
$$\int_a^b|f(x)-g(x)|dx$$

---

## 3. Fundamental Theorems in Calculus
