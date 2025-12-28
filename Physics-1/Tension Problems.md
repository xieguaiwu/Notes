---
tags:
  - Exercise
  - Physics
  - 证明
title: Tension Problems
created: 2025-12-27T20:04:00
modified:
---
# Tension Problems

- 面对复杂情景时，**从下往上分析**
- 绳子上拉力**处处相等**，指向**收缩的方向**
- 连接体问题中，所有物体**共享加速度**

分析的关键：
$$a=\frac{\sum F}{m}=\frac{\text{动力}-\text{阻力}}{m_A+m_B+\ldots}$$

## IMP 1. 连通体与张力
>见下方的两个情境：
>Case 1中A与桌面的摩擦力可以忽略不计，被绳子与滑轮联通，受到向下的外力$F_0$；Case 2中一切不变，但是**向下的外力变成了一个重$F_0$的物体B**

![[connected_bodies_and_tension.png]]
重要：两个情境中，**A所受外力不同，加速度也不同**

Case 1中，物体受绳子的恒定的拉力$T_1=F_0$，于是根据牛顿第二定律计算加速度：
$$a_1=\frac{F_0}{M}=\frac{T_1}{M}$$

Case 2中，由于A向右移动$x$会同时令B向下移动$x$，所以**两个物体加速度相同，加速度方向不同**。
重新分析拉力$T_2$，需要先分析物体B，其受到重力和绳子的拉力。
$$\sum F_B=F_0-T_2=m_B\cdot a_2$$
其中
$$m_B=\frac{F_0}{g}$$
那么最终求出Case 2的加速度：
$$a_2=\frac{F_0-T_2}{m_B}=\frac{F_0-T_2}{\frac{F_0}{g}}$$
或者也可以通过总质量求出加速度
$$a_2=\frac{T_2}{m_A+m_B}$$

---

## 2. 多绳子+夹角
>如图所示，两个质量同样为$m$的方块被两根绳子$\text{Cord 1}$和$\text{Cord 2}$吊起

![[tension_problem_degree.png]]

分析复杂的tension问题中的重要步骤是**从下往上作受力分析**，故先处理情景，忽略掉上方与平面成夹角的$\text{Cord 1}$和$\text{Cord 2}$

![[tension_problem_degree2.png]]
其中设定$\text{Cord 4}$的张力为$T_4$，可以意识到
$$T_4=mg$$
若设定$\text{Cord 3}$的张力为$T_3$，那么
$$T_3=2mg$$
现在看上方部分
![[tension_problem_degree3.png]]
此时$\text{Cord 1}$和$\text{Cord 2}$的合力有
$$\vec{T_1}+\vec{T_2}=2mg$$
对它们各自进行矢量分解：
$$T_1x=T_1\cdot\cos 30$$
$$T_1y=T_1\cdot\sin 30$$
$$T_2x=T_2\cdot\cos 60$$
$$T_2y=T_2\cdot\sin 60$$
考虑到情景中**水平不受力**，那么$$\vec{T_1x}+\vec{T_2x}=0N$$

那么自然
$$T_1x\cdot\cos 30=T_2\cdot\cos 60$$

---

## IMP 3. 变换质量对张力的影响
>如图所示，小车在桌面上被绳子与一个方块连接，摩擦力忽略不计，同时将小车和方块的质量$\times 2$，求张力和小车加速度的变化

![[changing_mass_to_tension.png]]

首先进行第一轮分析，设定小车质量为$m_1$，方块质量为$m_2$，那么得到张力的大小
$$T=m_2\cdot g$$
于是求得一开始的加速度
$$a=\frac{\sum F}{m}=\frac{m_2\cdot g}{m_1+m_2}$$
当质量同时改变后：
$$T_2=2m_2\cdot g=2T$$
说明**张力也变成了原来的两倍**
但是对于加速度来说：
$$a_2=\frac{2m_2\cdot g}{2(m_1+m_2)}=\frac{m_2\cdot g}{m_1+m_2}=a$$
说明加速度不变