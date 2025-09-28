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
## 2. 可导性定义
当**双侧导数**都存在且彼此相等时，函数可导：
$$\lim_{x\to c^+}\frac{f(x+c)-f(x)}{c}=\lim_{x\to c^-}\frac{f(x+c)-f(x)}{c}$$
双侧导数即左导数和右导数，与双侧极限等同[[limit]]，这在几何图象上意味着函数图象**是光滑且没有断裂的**，绝对值函数是一个反例：
![[abs_func.png]]
对于$f(x)=|x|$，当$x>0$时，$f(x)'=\lim_{\Delta x \to 0}\frac{|x+\Delta x|-|x|}{\Delta x}=1$，但重要的是，当$x<0$时，$f(x)'=\lim_{\Delta x \to 0}\frac{|x+\Delta x|-|x|}{\Delta x}=\lim_{\Delta x \to 0}\frac{-x-\Delta x+x}{\Delta x}=-1$
因此，我们会意识到$f(x)\lim_{x\to 0^+}\neq f(x)\lim_{x\to 0^-}$
**对于这个函数，当$f(x)=0$时，导数不存在**