---
tags:
  - Physics
  - 证明
  - Exercise
  - 定义性
title: Pendulum Problems
created: 2026-04-14T10:43:00
modified:
---
# Pendulum Problems
[[Conical Pendulum]]

## 1. 
>质量为 $m$ 的物体在水平圆周上运动，半径为 $r$，周期为 $T_1$ 将质量改为 $2m$，同样的半径 $r$，周期为 $T_2$ ，求$T_2$ 与 $T_1$ 的关系？

![[Enterprise_pendulum.png]]

圆锥摆的周期公式为：$$T = 2\pi \sqrt{\frac{L \cos\theta}{g}}$$
**周期与质量无关** — 这意味着改变质量不会改变摆动周期。因此 $T_2 = T_1$

## 2.
[[Energy & Work Problems.md]]
> 一个由球形质量块和长绳组成的单摆悬挂在地球表面的天花板上。将单摆**从竖直方向拉开一个小角度 $\theta$，然后从静止释放**。当球通过**最低点**时的动能为 $K_E$。
> 然后将单摆带到一颗行星上，**该行星的重力场强度约为地球上重力场强度的一半**。单摆再次悬挂在天花板上，拉开相同的小角度 $\theta$，从静止释放。当球通过最低点时的动能为 $K_P$。
> 比较 $K_E$ 和 $K_P$的大小关系

![[pendulum_with_different_g.png]]

### 步骤1：确定摆动的最大高度
单摆从角度 $\theta$ 处释放，相对于最低点的高度为：
$h = L(1 - \cos\theta)$

其中 $L$ 为摆长。

### 步骤2：应用机械能守恒
以最低点为零势能参考点：
- 初始状态（最高点）：势能 $U_i = mgh$，动能 $K_i = 0$
- 末态（最低点）：势能 $U_f = 0$，动能 $K_{\max}$

- 地球上$$K_E = mgL(1 - \cos\theta)$$
- 新行星上$$g' = \dfrac{1}{2}g$$
$$K_P = mg'L(1 - \cos\theta) = m \cdot \frac{g}{2} \cdot L(1 - \cos\theta) = \frac{1}{2}K_E$$


