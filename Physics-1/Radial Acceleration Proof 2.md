---
tags:
  - Physics
  - Calculus
  - 定义性
  - 证明
title: Radial Acceleration Proof 2
created: 2025-11-29T16:10:00
modified:
---
# Radial Acceleration Proof 2
考虑到[[Circular Motion & Gravitation]]中对于angular velocity $\omega$的基础定义，将uniform circular motion定义为如下参数方程：
$$x=r\cdot\cos(\omega\cdot t)$$
$$y=r\cdot\sin(\omega\cdot t)$$
其中$r$是圆周运动的轨迹的半径
于是做圆周运动的任意一点都可以用$(x,y)$的形式表示
通过对position求导（见[[differentiation]]中的**3.2**）可以得出竖直和水平方向的速度：
$$v_x=\frac{d}{dt}r\cdot\cos(\omega\cdot t)=-r\omega\cdot\sin(\omega\cdot t)$$
$$v_y=\frac{d}{dt}r\cdot\sin(\omega\cdot t)=r\omega\cdot\cos(\omega\cdot t)$$
于是再对速度分别求导即可得出竖直和水平方向的加速度
$$a_x=\frac{d}{dt}(-r\omega\cdot\sin(\omega\cdot t))=-r\omega^2\cdot\cos(\omega\cdot t)$$
$$a_y=\frac{d}{dt}(r\omega\cdot\cos(\omega\cdot t))=-r\omega^2\cdot\sin(\omega\cdot t)$$
那么最终得到总加速度：
$$a_R=\sqrt{a_x^2+a_y^2}=\sqrt{r^2\omega^4(\cos^2(\omega\cdot t)+\sin^2(\omega\cdot t))}$$
考虑到$\cos^2(x)+\sin^2(x)=1$
$$\Rightarrow a_R=\sqrt{\omega^4r^2}=\omega^2r=\frac{v^2}{r}$$
