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
$$\text{Primarily, }|f(x)-L|<\varepsilon (0<|x-a|<\delta)$$
Introducing second-order predicate logic:
$$\text{(Beware of the causal relationship: $\forall\varepsilon\Rightarrow\exists\delta $ and $x\Rightarrow y$)}$$
$$(\forall\varepsilon>0)(\exists\delta>0)(\forall x\in\mathbb{R})(0<|x-a|<\delta\Rightarrow |f(x)-L|<\varepsilon)$$
$$$$
