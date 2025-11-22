---
tags:
  - Math
  - Calculus
  - 定义性
title: Higher Order Derivative
created: 2025-10-15T12:18:00
modified:
---
# Higher Order Derivative
## 1. Def
一阶导数的符号是$\frac{dy}{dx}$，n阶导数的写法则是$\frac{d^n y}{dx^n}$：
$$y'\Leftrightarrow \frac{dy}{dx}\Leftrightarrow D_x[y]$$
$$y''\Leftrightarrow \frac{d^2y}{dx^2}\Leftrightarrow D_x^2[y]$$
## 2. Usage
### 2.1
函数的单调性 (Monotonicity) 由一阶导数判断，**函数的凹凸性 (Concavity)** 由二阶导数判断
如果在区间$(a,b)$中**函数$f(x)$的一阶导数递增**，那么$x\in(a,b)\Rightarrow f''(x)>0$，这样的函数是**凹向上的**，或者说**凸的 (concave up)**，即凸函数：
$$(\forall c)(c\in(a,b))f'(c+\Delta c)>f'(c)\Rightarrow \text{Concave Up in }(a,b)$$
![[concave_up.png]]

如果在区间$(a,b)$中**函数$f(x)$的一阶导数递减**，那么$x\in(a,b)\Rightarrow f''(x)<0$，这样的函数是**凹向下的**，或者说**凸出的 (concave Down)**，即凹函数：
$$(\forall c)(c\in(a,b))f(c+\Delta c)'<f'(c)\Rightarrow \text{Concave Down in }(a,b)$$
![[concave_down.png]]

### 2.2
当$f'(c)=0$时难以直接判断原函数图象，而是具有多种可能性，其可能性如[[differentiation]]中所示：
![[f'(c)=0.png]]
- $f''(c)>0$**局部最小值 (local minimum)**
- $f''(c)<0$**局部最大值 (local maximum)**
- $f''(c)=0$时不确定，仍然可能是上述任意一种
