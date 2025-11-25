---
tags:
  - Calculus
  - Math
  - 证明
title: Differentiability and Continuity
created: 2025-09-28T19:44:00
modified:
---
# Differentiability and Continuity
思路上最简洁的方法无非是在定义上用代数证明，其关键在于可导性和连续性定义中都会出现的$\Delta x \lim_{x\to 0}$
$$\text{Continuity: }\lim_{\Delta x \to 0}f(x+\Delta x)=f(x)$$
$$\text{Differentiability: }\lim_{\Delta x \to 0}\frac{f(x+\Delta x)-f(x)}{\Delta x}$$
对于二式，可以简单变形并得出：
$$\lim_{\Delta x \to 0}(\frac{f(x+\Delta x)-f(x)}{\Delta x}\times \Delta x)=\lim_{\Delta x \to 0}\frac{f(x+\Delta x)-f(x)}{\Delta x}\times\lim_{\Delta x \to 0}\Delta x$$
由于$\lim_{\Delta x \to 0}\Delta x=0$，所以可知原极限内出现了乘以零的情况：
$$\lim_{\Delta x \to 0}(f(x+\Delta x)-f(x))=0$$
由于$f(x)$不受极限的影响，可以直接将它从括号中剔出，于是：
$$\lim_{\Delta x \to 0}f(x+\Delta x)=f(x)$$
