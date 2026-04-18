---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: series_problem_04.17
created: 2026-04-17
modified: 
---
# series_problem_04.17
## 1
>幂级数$$\sum_{n=0}^\infty a_n(x+1)^n$$在$x=3$处收敛，请考虑$x=-5, x=-4, x=4$ 是否一定收敛

![[power_series_convergent_radius.png]]

根据
![[power_series_center_demo.png]]

可以知道这里的幂级数的中心是$c=-1$

既然$x=3$收敛，那么可以知道收敛半径至少是$R=3-(-1)=4$，**那么$(-5,-1]$中除了$x=-5$之外应该都收敛**（$x=5$不确定）

那么只能够确定$x=-4$是收敛的

## 2
>设函数 $f$ 在所有实数上具有各阶导数，且 $T_3(x)$ 表示函数 $f$ 在 $x=0$ 处的三阶泰勒多项式。已知在区间 $0 \le x \le 0.3$ 上，函数 $y = f^{(4)}(x)$ 的图像如图所示。
>如果使用 $T_3(0.3)$ 来近似 $f(0.3)$，那么根据拉格朗日误差上界，可以保证的最大误差是多少？

三阶泰勒多项式的拉格朗日余项为$$|R_3(x)| \le \frac{M|x-a|^4}{4!}$$

其中：
- $M = \max |f^{(4)}(x)|$（在区间上的**最大绝对值**!）

![[forth_order_derivative_on_graph.png]]

观察图像可得$$M = \max |f^{(4)}(x)| = 3$$
$$\boxed{|R_3(x)| \le \frac{3(0.3)^4}{4!}}$$
