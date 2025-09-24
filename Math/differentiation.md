---
tags:
  - Calculus
  - Math
title: differentiation
created: 2025-09-24T10:08:00
modified:
---
# differentiation

---

## 0. vocab
tangent line 切线/secant line割线
## 1. Simple start
average rate of change在几何上等值于secant line:
$$m_{sec}=\frac{f(c+\Delta x)-f(c)}{(c+\Delta x)-c}$$
Tangent line is the secant line at the a limit of function. For example (this is for **nonlinear functions**):
$$f(x)=x^2-7x+15$$
$$f(x)'=lim_{\Delta x\to 0} \frac{(x+\Delta x)^2-7(x+\Delta x)+15-x^2+7x-15}{\Delta x}$$
常数被消除
$$f(x)'=\lim_{\Delta x\to 0}\frac{2\Delta x\times x+\Delta x^2-7\Delta x}{\Delta x}$$
$$f(x)'=\lim_{\Delta x \to 0}2x+\Delta x-7=2x-7$$
$$(\forall f(x)^a) f(x)^{a}=ax^{a-1}$$