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
$$f'(x)=lim_{\Delta x\to 0} \frac{(x+\Delta x)^2-7(x+\Delta x)+15-x^2+7x-15}{\Delta x}$$
常数被消除
$$f'(x)=\lim_{\Delta x\to 0}\frac{2\Delta x\times x+\Delta x^2-7\Delta x}{\Delta x}$$
$$f'(x)=\lim_{\Delta x \to 0}2x+\Delta x-7=2x-7$$
$$(\forall f(x)^a)\frac{d}{dx} f(x)^{a}=ax^{a-1}$$
## 2. 可导性定义
当**双侧导数**都存在且彼此相等时，函数可导：
$$\lim_{x\to c^+}\frac{f(x+c)-f(x)}{c}=\lim_{x\to c^-}\frac{f(x+c)-f(x)}{c}$$
双侧导数即左导数和右导数，与双侧极限等同[[limit]]，这在几何图象上意味着函数图象**是光滑且没有断裂的**，绝对值函数是一个反例：
![[abs_func.png]]
对于$f(x)=|x|$，当$x>0$时，$f'(x)=\lim_{\Delta x \to 0}\frac{|x+\Delta x|-|x|}{\Delta x}=1$，但重要的是，当$x<0$时，$f'(x)=\lim_{\Delta x \to 0}\frac{|x+\Delta x|-|x|}{\Delta x}=\lim_{\Delta x \to 0}\frac{-x-\Delta x+x}{\Delta x}=-1$
因此，我们会意识到$f(x)\lim_{x\to 0^+}\neq f(x)\lim_{x\to 0^-}$
**对于这个函数，当$f(x)=0$时，导数不存在**

## 3. 特殊情况
### 3.1
当$f'(c)=0$ 时无法直接判断原函数图象，其有以下几种可能：
![[f'(c)=0.png]]

当函数在点$c$出现 **垂直的切线 (vertical tangent line)** 时：
$$\lim_{\Delta x\to 0} \frac{f(c+\Delta x)-f(c)}{\Delta x}=\pm\infty$$
假如函数连续，那么可以认为：
$$f'(c)=\pm\infty$$
**函数在这点是不可导的！**
图像如下：
![[Vertical_tangent.svg]]
### 3.2
$$D_x[\log_a x]=\frac{1}{x\ln a}$$
$$D_x[\ln x]=\frac{1}{x}$$
$$D_x[e^x]=e^x$$
$$D_x[\tan x]=\sec^2 x$$
$$D_x[\sin x]=\cos x$$
$$D_x[\cos x]=-\sin x$$
$$D_x[\cot x]=-\csc^2 x$$
$$D_x[\sec x]=\sec x\tan x$$
$$D_x[\csc x]=-\csc x\cot x$$

---
#### 3.21 证明$D_x[e^x]=e^x$
$$D_x[e^x]=\lim_{h\to 0}\frac{e^{x+h}-e^x}{h}$$
考虑到
$$e^{x+h}=e^x\cdot e^h$$
带入原式
$$D_x[e^x]=\lim_{h\to 0}\frac{e^x(e^h-1)}{h}=e^x\lim_{h\to 0}\frac{e^h-1}{h}$$
于是现在只需要考虑极限
$$\lim_{h\to 0}\frac{e^h-1}{h}$$
通过换元法，设定$x=e^h-1$，那么当$h\to 0$时，可以意识到$x\to 0$，于是将它带入此极限可得
$$\lim_{h\to 0}\frac{e^h-1}{h}=\lim_{x\to 0}\frac{x}{\ln(x+1)}$$
---

另一方面，根据[[Definition of e]]，可知
$$e=\lim_{h\to 0}(1+h)^{1/h}$$
那么可以得到$\ln e$的定义：
$$\ln e=\ln\lim_{h\to 0}((1+h)^{1/h})=\lim_{h\to 0}\frac{\ln(1+h)}{h}$$

---

那么再次操作原先的极限：
$$\lim_{x\to 0}\frac{x}{\ln(x+1)}=\lim_{x\to 0}\frac{1}{\frac{\ln(x+1)}{x}}$$
单独观察分母，立刻意识到这和$\ln e$的定义如出一辙
$$\lim_{x\to 0}\frac{\ln(x+1)}{x}=\ln e=1$$
那么原极限就等于一
$$\lim_{h\to 0}\frac{e^h-1}{h}=\lim_{x\to 0}\frac{x}{\ln(x+1)}=\lim_{x\to 0}\frac{1}{\ln e}=1$$
于是起初的导数就是
$$D_x[e^x]=e^x\lim_{h\to 0}\frac{e^h-1}{h}=e^x\cdot 1=e^x$$

---

## 4. Rule of Derivative
### 4.1
$$\frac{d}{dx}[f(x)+g(x)]=f'(x)+g(x)'$$
$$\frac{d}{dx}[f(x)-g(x)]=f'(x)-g(x)'$$
### 4.2
$$\frac{d}{dx}[f(x)\times g(x)]=f(x)g'(x)+g(x)f'(x)$$
$$\frac{d}{dx}[f(x)\div g(x)]=\frac{f'(x)g(x)-g'(x)f(x)}{g(x)^2}(g(x)\ne 0)$$
### 4.3 Chain Rule
$$\frac{d}{dx}[f(g(x))]=f'(g(x))\times g'(x)$$
如果函数$y=f(u)$可导，函数$u=g(x)$可导，那么：
$$\frac{dy}{dx}=\frac{dy}{du}\times \frac{du}{dx}$$
## 5. 其它问题
正如前文所言，求导在几何上的意义在于作切线 (tangent line)。这里有两种特殊的切线：**vertical tangent line**和**horizontal tangent line**