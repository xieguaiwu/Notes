---
tags:
  - Physics
  - 定义性
title: FBD Problems
created: 2025-12-04T09:29:00
modified:
---
# FBD Problems
## 1.
>The figure presents a diagram of 3 blocks on a horizontal **rough surface**. From left to right the blocks are labeled Block 1, Block 2, and Block 3. Block 1 is the smallest and Block 2 is the largest. **The blocks are touching**. A rightward pointing arrow labeled P points toward the left side of Block 1.

![[FBD_for_3_blocks.png]]
有$\vec{P}$推动三个方块，$\vec{F_C}$是方块2和方块3之间的contact force，另一方面，已知还存在$F_f$，$F_N$和$F_G$三个力
对方块2做受力分析

注意：由于$P$并不与方块2直接接触，所以**方块2在左侧并不直接受$P$，而只受方块1的$F_C$**
于是其受力分析如下：
![[FBD_for_3_blocks_Answer.png]]

## 2.
>在图1的情况中对Pin做受力分析，其形式如图2


![[FBD_Table_Acceleration.png]]
若要知道其加速度，须先计算合力，合力方向即加速度方向
$$\sum F_y=3-1=2N$$
$$\sum F_x=-8+5=-3N$$
注意：考虑到右侧是正方向，所以必须意识到 **$|\vec{F_4}|$是负数**，即$\vec{F_4}=-8N$

## IMP 2. Intermediate Static Friction
![[intermediate_friction_when_moving_together.png]]
联系[[Dynamic & Friction]]的**1.2**中关于静摩擦的知识点

若A和B**不受加速度**，那么**A不受摩擦力**
在A和B共同运动时：
- 若有共同加速度，且没有相对滑动，那么**A受static firction，提供加速度**

在A和B间有相对滑动时，**A受kinetic friction**