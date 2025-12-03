---
tags:
  - Math
  - Calculus
title: limit
created: 2025-08-24T09:43:00
modified:
---
# limit
## **1. Def**
![[limit_def.png]]
$$\text{As shown above, }f(x)( x\ne a)$$
[[function mapping]]
$$\text{In order to reach (a,L), the value on x-axis should very near to a: }\lim_{x\to a } f(x)$$
While on the other hand, $y$ should also be as close to $L$ as possible:
$$L-\varepsilon<y<L+\varepsilon$$
We can also use the same method on $x$:
$$a-\delta<x<a+\delta$$
We say that **"$x$ is within a distance $\delta$ of $a$"**
$$\text{Primarily, }|f(x)-L|<\varepsilon (0<|x-a|<\delta)$$

Introducing second-order predicate logic:
$$\text{(Beware of the causal relationship: $\forall\varepsilon\Rightarrow\exists\delta $ and $x\Rightarrow y$)}$$
$$(\forall\varepsilon>0)(\exists\delta>0)(\forall x\in\mathbb{R})(0<|x-a|<\delta\Rightarrow |f(x)-L|<\varepsilon)$$
## 2. 常见
$$\lim_{x\to 0}\cos(x)=1$$
$$\lim_{x\to 0}\frac{1-\cos(x)}{x}=0$$
$$\lim_{x\to 0}\frac{\sin(x)}{x}=1$$
$$\lim_{x\to 0}\frac{\tan x}{x}=\lim_{x\to 0}\frac{\sin x}{x\cdot\cos x}=\lim_{x\to 0}\frac{\sin(x)}{x}\cdot\lim_{x\to0}\frac{1}{\cos x}=1$$
## 3. 常见无穷小替换
以下式子全部在$\lim{x\to 0}$时成立
$$\sin x\sim x$$
$$\tan x\sim x$$
$$\arcsin x\sim x$$
$$\arctan x\sim x$$
$$(1-\cos x)\sim\frac{x^2}{2}$$
$$\ln(1+x)\sim x$$
$$(e^x-1)\sim x$$
$$(a^x-1)\sim x\cdot\ln a(a>0,a\neq 1)$$
$$\log_a(1+x)\sim\frac{x}{\ln a}$$
$$(1+x)^a-1\sim ax$$
$$^n\sqrt{1+x}-1\sim\frac{x}{n}$$
$$\ln(1+x)-x\sim -\frac{1}{2}x^2$$
