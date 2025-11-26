---
tags:
  - Physics
  - 定义性
  - Dynamics
title: Dynamic & Friction
created: 2025-11-26T08:50:00
modified:
---
# Dynamic & Friction
## 1. Def
Friction:
- Kinetic Friction
- Static Friction

### 1.1 Kinetic Friction
物体滑动时，kinetic friction会在**物体速度方向的反方向上**起作用。
Kinetic friction的大小取决于两块表面的性质，而**两块表面间的支持力与摩擦力大小成比例**，其公式如下：
$$F_{fr}=\mu_k\cdot F_N$$
其中$\mu_k$即为coefficient of kinetic friction

以下是一些常见物体的coefficient of kinetic friction
![[coefficient_of_kinetic_friction_in_normal_objs.png]]

### 1.2 Static Friction
当施加足够大的力时方可将大质量的物体移动，其数学描述可以给出coefficient of static friction，即$\mu_s$的公式：
$$(F_{fr})_{max}=\mu_s\cdot F_N$$
另一方面
$$F_{fr}\leq\mu_s\cdot F_N$$

一般来说，通常有$\mu_k<\mu_s$

## 2. Situations
### 2.1 Stable Box on the Wall
![[coefficient_of_kinetic_friction_certain_situation.png]]
图中重力竖直向下，而static friction向上，有：
$$mg=F_{fr}$$
在这种情况下，必须要保证$mg\leq\mu_s F_N$才能令static friction从侧面托举住箱子

### 2.2 Two Boxes Together
![[coefficient_of_kinetic_friction_certain_situation2.png]]
必须注意到其中A因为受kinetic friction留在了桌面上，设其数值大小是$\mu_k$，若能够保持平衡态：
$$F_{frA}=\mu_k\cdot F_{gB}$$

### 2.3 Leaned Ground
![[coefficient_of_kinetic_friction_on_ice.png]]
另一方面，当物体处于非静止状态，即$\sum F\neq 0$时：
$$\sum F=F_{gx}-F_{fr}\neq 0$$
在处理非静止状态下的kinetic friction时，必须用到公式
$$F_{fr}=\mu_k F_N$$
此处的支持力$F_N$与水平方向的受力情况无关，而只与$F_{gy}$相关，于是：
$$\vec{F_N}=\vec{F_{gy}}=mg\cdot\cos\theta$$
另一方面，也有
$$\sum F=m\cdot a_x$$
其中$a_x$直接指向倾斜的平面上的加速度

将所有数值一一带入可得：
$$F_{gx}-F_{fr}=m\cdot a_x$$
$$F_{gx}-\mu_k F_N=m\cdot a_x$$
$$\Rightarrow mg\sin\theta-\mu_k(mg\cos\theta)=m\cdot a_x$$