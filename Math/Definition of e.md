---
tags:
  - Calculus
  - Math
  - 定义性
title: Definition of e
created: 2025-11-18T12:08:00
modified:
---
# Definition of $e$
[[calculus]]
[[数学]]
自然对数$e$的定义如下：
$$e=\lim_{n\to\infty}(1+\frac{1}{n})^n$$

---

其在经济学中的应用即为连续复利公式，见[[Basic Finance]]**2**。
由于一般的复利公式是
$$A=P(1+\frac{r}{n})^{nt}$$
于是
$$\lim_{n\to\infty}P(1+\frac{r}{n})^{nt}=Pe^{rt}$$

---

回到其数学定义，可以看到它同时也能写成
$$e=\lim_{h\to 0}(1+h)^{1/h}$$
那么可以得到$\ln e$的定义：
$$\ln e=\ln\lim_{h\to 0}((1+h)^{1/h})=\lim_{h\to 0}\frac{\ln(1+h)}{h}$$

这在[[differentiation]]中的一些特殊的导数上有所作用