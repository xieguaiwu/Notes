---
tags:
  - Physics
  - Exercise
  - 定义性
  - 证明
title: Vector & Scalar Problems
created: 2025-12-13T15:35:00
modified:
---
# Vector & Scalar Problems
## 1. Change in Speed to Change in Velocity
>在$t_0$时，小车以$v_0$的**speed**向右前进，而$t_1$时，它则以$v_1$的**speed**向左行进，求$t_0$到$t_1$之间的$\Delta\vec{v}$

注意，题目原文中的$v_0$和$v_1$都是speed，因此绝对不能简单地用$\Delta v=\vec{v_f}-\vec{v_i}$进行计算！
由于$\vec{v_f}=-v_1$，所以：
$$\Delta v=\vec{v_f}-\vec{v_i}=-v_1-v_0=-(v_1+v_0)$$
必须注意题目中的数值属于scalar还是vector

## 2. Horizontal Constant Acceleration
>小车在$x_i$上以$v_i$行进，在此刻它开始以magnitude of $a$的匀加速度减速，当它位于$x_f$时，其速度为$v_f$，求$x_f$的表达式

请注意，题目中 **$a$是加速度的大小，而不含方向**
对于$\Delta x=x_f-x_i$，有公式
$$\Delta x=x_f-x_i=\frac{v_f^2-v_i^2}{2\vec{a}}$$
在题目中，考虑到加速度与正方向相反，所以：
$$\Delta x=x_f-x_i=\frac{v_f^2-v_i^2}{-2a}$$
$$\Rightarrow x_f=\frac{v_i^2-v_f^2}{2a}+x_i$$
