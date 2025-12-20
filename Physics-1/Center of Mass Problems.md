---
tags:
  - Physics
  - Exercise
  - 定义性
  - 证明
title: Center of Mass Problems
created: 2025-12-15T19:42:00
modified:
---
# Center of Mass Problems
## 1. IMP 连通体与张力
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

## 2. 密度与质量比
>有一个24cm长的块状物体，左右各被分成了等长且均匀的物体A和物体B，$2\rho_A=\rho_B$
>块状物体被从质心处切开，求左侧和右侧的质量比$m_1:m_2$

![[bar_density_and_mass.png]]
首先需要计算质心，先算出两个物体各自的质量，设定物体的横截面积为$v$
$$m_A=12v\rho_A$$
$$m_B=24v\rho_A$$
物体A和B分别的质心都位于其几何中心：
$$x_A=6cm$$
$$x_B=12cm+6cm=18cm$$
那么质心计算为
$$CM=\frac{m_A\cdot x_A+m_B\cdot x_B}{36v}=\frac{504}{36}=14cm$$
从$x=14cm$处切开后，左侧物体包含了完整的物体A的2cm长的物体B
$$m_1=m_A+(14cm-12cm)v\cdot 2\rho_A=12\rho_A+4\rho_A=16\rho_A$$
右侧物体仅仅包含了10cm长的物体B
$$m_2=(12cm-2cm)\cdot 2\rho_A=20\rho_A$$
于是得到比值：
$$\frac{m_1}{m_2}=\frac{16}{20}=4:5$$

## 3. 由质量变化造成的质心变化
>有一块长$L$且质量为$M$的均匀的长条，质量为$3M$的人站在$x=0$处，他随后走向$x=L$处，求取新的质心的位置

![[shift_in_CM_due_to_shift_in_mass.png]]