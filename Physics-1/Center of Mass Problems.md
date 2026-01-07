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

合外力为零，则**质心不变**

特殊提醒：**质量比例位移题**
对于像第二题那样的题目，必须意识到物体会随着人的移动而**等比例移动**，人向前走时，物体会向后退
一般而言，若人的质量是$m$而位移为$x_1$，而物体的质量是$m_2$且位移是$x_2$，有如下关系：
$$x_1\cdot m=x_2\cdot m_2$$

## 1. 密度与质量比
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

## 2. IMP 质量比例位移题
>有一块长$L$且质量为$M$的均匀的长条，长条**浮在水面上**，水对它没有任何阻力，质量为$3M$的人站在$x=0$处，他随后走向长条最右端，求取新的质心的位置

![[shift_in_CM_due_to_shift_in_mass.png]]
首先算出一开始时的质心，在图中用粉色虚线标出
由于长条密度均匀，故其质心位于$\frac{1}{2}L$
$$CM=\frac{3M\cdot 0L+M\cdot\frac{1}{2}L}{4M}=\frac{L}{8}$$
必须要注意到的一点是，**长条浮在水面上**，这意味着人在行走时，**长条也会因为受到反作用力而移动**，设置此时长条的移动量为$\Delta x$
![[shift_in_CM_due_to_shift_in_mass_2.png]]
重新计算新质心得到
$$CM'=\frac{3M\cdot L+M\cdot\frac{L}{2}}{4M}=\frac{7}{8}L$$
由于此时的质心是从新木板的新原点处开始的，所以它在图中的位置是在此处
![[shift_in_CM_due_to_shift_in_mass_3.png]]
