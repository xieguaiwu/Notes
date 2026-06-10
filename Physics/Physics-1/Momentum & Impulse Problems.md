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
## 1. IMP 反弹的动量和冲量
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
1. **根据冲量定理**：$\vec{I} = \Delta\vec{p} = m\Delta\vec{v}$
   - 水平方向： $\Delta p_x = m(v\cos\theta - v\cos\theta) = 0$
   - 垂直方向： $\Delta p_y = m[v\sin\theta - (-v\sin\theta)] = 2mv\sin\theta$
$$I = 2mv\sin\theta$$

## 2.
>一个质量为 2 kg 的物体沿虚线 $y = 3$ m 以恒定速率 3 m/s 向左运动。在图示瞬间，物体位于坐标(4 m, 3 m)。该物体相对于原点的角动量大小最接近多少？

![[angular_momentum_ball_flying.png]]

**角动量定义**：

质点相对于某参考点的角动量：
$$\vec{L} = \vec{r} \times \vec{p} = \vec{r} \times m\vec{v}$$

大小：
$$L = r_\perp \cdot p = r_\perp \cdot mv$$

其中 $r_\perp$ 为动量到参考点的垂直距离（力臂）。

物体沿 $y = 3$ m 直线运动，速度沿水平方向。

动量到原点的垂直距离即为 **y 坐标**：$$r_\perp = 3 \text{ m}$$

动量大小$$p = mv = 2 \times 3 = 6 \text{ kg·m/s}$$
角动量大小$$L = r_\perp \cdot p = 3 \times 6 = 18 \text{ kg·m}^2/\text{s}$$

**物理理解**：
- 物体沿水平直线运动，位置矢量与速度矢量不平行
- 角动量垂直于运动平面（$z$ 方向）
- 角动量大小取决于运动直线到原点的距离

## 3.
> 一个质量为 80 kg 的人站在质量为 15 kg 的木筏上，木筏最初静止在平静的池塘中。此人开始在木筏上以 +0.5 m/s 的速度向前走，如图所示。当人向前走时，木筏的最终速度是多少？

![[man_walking_on_raft_considering_conservation_of_momentum.png]]

由于水平方向没有外力作用（忽略水的阻力），人-木筏系统的总动量守恒。

- 初始总动量：$p_{\text{initial}} = 0$（系统静止）

根据动量守恒：$$0 = m_p v_p + m_r v_r$$
$$0 = 80 \times 0.5 + 15 \times v_r$$
$$0 = 40 + 15v_r$$
$$v_r = -\frac{40}{15} = -2.67 \approx -2.7\ \text{m/s}$$

负号表示木筏向与人运动相反的方向运动。


