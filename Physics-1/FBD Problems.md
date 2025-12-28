---
tags:
  - Physics
  - 定义性
  - Exercise
  - 证明
title: FBD Problems
created: 2025-12-04T09:29:00
modified:
---
# FBD Problems
## IMP 1. Contact Force in Non-contact Situation
>The figure presents a diagram of 3 blocks on a horizontal **rough surface**. From left to right the blocks are labeled Block 1, Block 2, and Block 3. Block 1 is the smallest and Block 2 is the largest. **The blocks are touching**. A rightward pointing arrow labeled P points toward the left side of Block 1.

![[FBD_for_3_blocks.png]]
有$\vec{P}$推动三个方块，$\vec{F_C}$是方块2和方块3之间的contact force，另一方面，已知还存在$F_f$，$F_N$和$F_G$三个力
对方块2做受力分析

注意：由于$P$并不与方块2直接接触，所以**方块2在左侧并不直接受$P$，而只受方块1的$F_C$**
于是其受力分析如下：
![[FBD_for_3_blocks_Answer.png]]

## 2.
>在figure 1的情况中对Pin做受力分析，其形式如figure 2


![[FBD_Table_Acceleration.png]]
若要知道其加速度，须先计算合力，合力方向即加速度方向
$$\sum F_y=3-1=2N$$
$$\sum F_x=-8+5=-3N$$
注意：考虑到右侧是正方向，所以必须意识到 **$|\vec{F_4}|$是负数**，即$\vec{F_4}=-8N$

## IMP 3. Intermediate Static Friction
![[intermediate_friction_when_moving_together.png]]
联系[[Dynamic & Friction]]的**1.2**中关于静摩擦的知识点

若A和B**不受加速度**，那么**A不受摩擦力**
在A和B共同运动时：
- 若有共同加速度，且没有相对滑动，那么**A受static friction，提供加速度**

在A和B间有相对滑动时，**A受kinetic friction**

另一方面，直接与地面接触的B会受到摩擦力

## IMP 4. Gravity & Friction
>在这个系统的两边分别给予外力，考虑中间四个相互挤压的质量相同物体之间的摩擦力
![[friction_by_gravity_and_squeezing.png]]
注意：必须意识到这些物体之间除了压力之外**还受到重力**

首先，**1和4会受到摩擦力作用**，这是自然的。
另一方面，1和4会受到重力作用，从而**令1、2和3、4间存在相对运动**，因此2的左侧和3的右侧**都受到竖直向上的摩擦力**
2和3也会受到竖直向下的重力作用，但是它们两侧的竖直向上的摩擦力会抵消掉重力作用，因此，**2和3之间没有相对运动**，它们之间**没有摩擦力**

## IMP 5. 有角度的外力和支持力
![[exerted_force_and_normal_force.png]]
如图所示，一个物体G被一个与水平面有夹角$\theta=40^\circ$的外力作用
外力包括垂直分量$\vec{w}$和水平分量$\vec{v}$，**其中$\vec{w}$与支持力$\vec{F_N}$方向一致**

此时，物体的**支持力小于重力**，因为一部分支持力被垂直分量分担了：
$$F_N=m\cdot g-F\cdot\sin\theta$$

## IMP 6. 墙上的梯子
>如图所示，有一个梯子斜在墙面和地面间，求其在地面上受到的摩擦力$F_{fr}$的情况

![[ladder_on_the_wall.png]]
在受力分析中，必须意识到的是，**摩擦力所抵消掉的是墙面对梯子的支持力**，只有当
$$\vec{F_{fr}}+\vec{F_N}=0N$$
时，梯子才能静止地立在原地，所以自然，在数值上
$$F_{fr}=F_N$$
