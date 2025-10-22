---
tags:
  - Calculus
  - 证明
  - Math
title: limit_problem_10.22
created: 2025-10-22T12:22:00
modified:
---
# limit_problem_10.22
## 1.
>$$\lim_{x\to 0}\frac{\sin(2x)}{x}$$

首先，正如[[squeeze_theorem]]所说：
$$(\forall x)\lim_{x\to 0}\frac{\sin(x)}{x}=1$$
![[sin_squeeze.png]]
正因如此，只需要把原式化作这种形式即可：
$$\text{Let }n=2x\text{, so the original equation would be: }\lim_{n\to 0}\frac{\sin(n)}{\frac{1}{2}n}$$
$$\Rightarrow\lim_{x\to 0}\frac{\sin(2x)}{x}=2\times\lim_{n\to 0}\frac{\sin(n)}{n}=2\times1=2$$

## 2.
>$$\lim_{x\to 1^{-}}\frac{x}{x-1}$$

首先，必须注意到原式中所趋近的是左极限，而原函数的图像如下：
![[frac{x}{x-1}.png]]
可知**当$lim_{x\to 1^{-}}$时，$\lim_{f(x)\to -\infty}$**，所以对于原式而言：
$$\lim_{x\to 1^{-}}\frac{x}{x-1}=\frac{\text{positive}}{\text{negative}}$$
$$\Rightarrow\lim_{x\to 1^{-}}\frac{x}{x-1}=-\infty$$
