---
tags:
  - Physics
  - Exercise
  - 证明
title: Momentum & Impulse Problems
created: 2026-03-29T09:49:00
modified:
---
# Momentum & Impulse Problems
## 1. 反弹的动量和冲量
> 一个质量为 $m$ 的圆盘以恒定速率 $v$ 滑行，与墙发生碰撞后以相同速率 $v$ 反弹，入射角与反射角均为 $\theta$。求墙对圆盘施加的**冲量大小**。

![[rebound_impulse_and_momentum.png]]
关键理解

$\theta$ 是速度与墙的夹角，因此：
 - 速度与法线的夹角为 $90^\circ - \theta$
 - 法向分速度为 $v\sin\theta$
 - 切向分速度为 $v\cos\theta$

1. 碰撞前的速度分量：
   - 垂直分量：$v_{y1} = -v\sin\theta$（向下为负）
   - 水平分量：$v_{x1} = v\cos\theta$
2. 碰撞后的速度分量：
   - 垂直分量：$v_{y2} = +v\sin\theta$（向上为正）
   - 水平分量：$v_{x2} = v\cos\theta$
3. 根据冲量定理：$\vec{I} = \Delta\vec{p} = m\Delta\vec{v}$
   - 水平方向： $\Delta p_x = m(v\cos\theta - v\cos\theta) = 0$
   - 垂直方向： $\Delta p_y = m[v\sin\theta - (-v\sin\theta)] = 2mv\sin\theta$
$$I = 2mv\sin\theta$$

