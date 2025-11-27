---
tags:
  - Physics
  - 定义性
  - Geometry
  - Dynamics
title: Circular Motion & Gravitation
created: 2025-11-26T12:33:00
modified: 2025-11-27
---
# Circular Motion & Gravitation
## 1. Uniform Circular Motion
Uniform circular motion即物体速度不变的圆周运动，其图示如下：
![[uniform_circular_motion.png]]
对于这种运动，其运动方向的变化就是其加速度，则加速度$\vec{a}$和$\Delta\vec{v}$方向相同，都是向运动中心的，所以称其为centripetal/radical acceleration（向心加速度），记作$\vec{a}_R$

为了计算$\vec{a}_R$，见下方的示意图
![[centripetal_movement.png]]
取一个足够小的$\Delta\theta$，于是从$A$点到$B$点的运动距离趋近于$\Delta l$
结合圆弧计算公式，可以知道
$$\Delta l=r\cdot\Delta\theta$$

考虑到$a=\frac{\Delta v}{\Delta t}$，需要想办法在圆周运动的模型中找到表示$\Delta v$和$\Delta t$的方式：
![[velocity_vectors_in_centripetal_movement.png]]
如图所示，两个速度向量之间的变化值近似于三角形的第三边，同样将$\Delta\theta$视作瞬间的极小变化量（此时$\lim_{\Delta t\to 0}$），则$|\vec{v_1}|=|\vec{v_2}|=v$，故继续结合圆弧计算公式：
$$|\Delta \vec{v}|=v\cdot\Delta\theta$$

结合两式的形式，可以在$\lim_{\Delta t\to 0}$时得出等式：
$$\frac{\Delta v}{v}\approx\frac{\Delta l}{r}$$
那么就得出$\Delta v$的表达式
$$\Delta v=\Delta l\cdot\frac{v}{r}$$
带入进$a_R=\frac{\Delta v}{\Delta t}$：
$$a_R=\frac{\Delta l}{\Delta t}\cdot\frac{v}{r}$$
由于根据速度$v$的定义式
$$v=\frac{\Delta l}{\Delta t}$$
则最终得到向心加速度$a_R$ 的定义式
$$a_R=\frac{v^2}{r}$$