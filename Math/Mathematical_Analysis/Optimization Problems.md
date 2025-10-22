---
tags:
  - Math
  - Calculus
  - 定义性
  - 证明
title: Optimization Problems
created: 2025-10-22T13:41:00
modified:
---
# Optimization Problems
## 1. Basic Method
见[[differentiation]]的**3.1**中的图：
![[f'(c)=0.png]]
由此可知，当$f'(c)=0$时，可以求得函数的局部最大或最小值。

## 2. Example
对于柱形的体积，有如下公式：
$$V=\pi r^2\times h$$
已知$V=16\pi$的情况下，如果要求得表面积$A_{max}$的情况，那么首先需要整理公式：
$$16\pi=\pi r^2\times h$$
$$\Rightarrow h=\frac{16}{r^2}$$
另一方面：
$$A=2\times 2\pi r^2+2\pi r\times h$$
$$\Rightarrow A=4\pi r^2+\frac{32\pi}{r}$$
使用乘法法则求导来找到$f'(c)=0$时$c$：
$$\frac{dA}{dr}=8\pi r-32\pi r^{-2}$$
现代求出$A'(r)=0$时的情况：
$$8\pi r-32\pi r^{-2}=0$$
有唯一解
$$\Rightarrow r=4^{\frac{1}{3}}\approx 1.5874...$$
带入验证后得出$A(4^{\frac{1}{3}})$是函数的最小值，因此表面积无最大值。

