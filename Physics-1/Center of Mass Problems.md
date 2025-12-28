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

## 2. 由质量变化造成的质心变化
>有一块长$L$且质量为$M$的均匀的长条，质量为$3M$的人站在$x=0$处，他随后走向$x=L$处，求取新的质心的位置

![[shift_in_CM_due_to_shift_in_mass.png]]