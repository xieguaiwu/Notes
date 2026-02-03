---
tags:
  - Physics
  - 定义性
title: Reference Frames Problems
created: 2025-11-25T10:02:00
modified:
---
# Reference Frames Problems
## 0. 相对速度

相对速度公式：v_{A相对B} = v_A - v_B

如果A车速度为v_A，B车速度为v_B，那么A相对于B的速度就是两者之差。

若A车速度为正（向右），B车速度也为正（向右），则：
- 如果v_A > v_B，则A相对于B向右运动
- 如果v_A < v_B，则A相对于B向左运动


## 1.
>A rowboat moving in a lake is accelerating at a constant rate towards the shore. An observer in **another boat moving at a constant velocity** measures the row boat’s acceleration. A second observer, **standing still on the shore**, also measures the acceleration of the rowboat. Are the two accelerations measured by the two observers the same? Why or why not?

两个观测者：
- 船中以匀速行进者
- 岸边静止的观测者

两个观测者的**加速度为零**，考虑到**加上（或减去）一个恒定速度不会改变加速度**，可知它们各自观测到的加速度都是相同的

## 2.
>Three vehicles pass each other traveling on a three-lane roadway. Vehicle A is moving west with speed $v_A$ relative to the road; Vehicle B is moving east with speed $v_B$ relative to the road; and Vehicle C is moving east with speed $v_C$ relative to the road. Assume **east is the positive direction**. What is the velocity of Vehicle B relative to observers in Vehicle A and in Vehicle C?

大致的示意图如下所示
![[relative_velocities_of_vehicles.png]]

IMP: **对于A车而言，B车的速度是$v_B+v_A$**

另一方面，对于C车来说，B的速度则是$v_B-v_C$

## 3.
>Students A and B are standing inside **a train that is accelerating to the right with a magnitude of $2m/s^2$**. Student A throws a ball to the left toward Student B with a horizontal velocity of magnitude $4m/s$ relative to the train. At the instant the ball leaves Student A’s hand, the speed of the train relative to the ground is $10m/s$ to the right. The ball takes $0.5$ second to reach Student B. Immediately before the ball reaches Student B, the horizontal speed of the ball relative to the ground is?

![[Relative_motion_ball_thrown_on_accelerating_train.png]]

假设火车目前的速度是$v_0$，由于是A向B扔球，故知其相对于地面的速度永远是$v_0-4m/s$

那么，当$v_0=10m/2$，球相对于地面的速度自然是$6m/s$

## 4. IMP
>A cart equipped with a launcher launches a dart horizontally, as shown. The dart is always given the same horizontal velocity $v_{dart}$ relative to the cart. In Trial 1, the cart is at rest at Point P a distance D from a target and launches the dart toward the target. The dart takes a time $t_1$ to reach the target. In Trial 2, **the cart is moving toward the target with constant speed $v_{cart}$** and launches the dart at the instant the cart is at Point P. The dart takes a time $t_2$ to reach the target. The cart has a negligible change in speed during the launch. Which of the following is a correct expression for the cart’s speed $v_{cart}$?

![[IMPRelative_motion-carts_launching_darts_at_target.png]]

首先，在图一中：
$$v_{dart}=\frac{D}{t_1}$$
其次，必须意识到在图二中，**飞镖相对地面的速度等同于车速+镖速**
$$v_{ground}=v_{cart}+v_{dart}$$
考虑到在图二时
$$v_{ground}=\frac{D}{t_2}$$
结合两个等式可得出：
$$\frac{D}{t_2}=v_{cart}+\frac{D}{t_1}$$
那么自然
$$v_{cart}=\frac{D}{t_2}-\frac{D}{t_1}$$

## 5. 火车与变速的小球
>一列火车以相对于地面的速度 $v_t$ 向 $+x$ 方向行驶。火车上的乘客以相对于火车的速度 $v_0$ 在 $-x$ 方向滚动一个小球。另一名乘客迅速停止小球并以相同的速度 $v_0$ 相对于火车向相反方向滚动。

根据**3**所提供的公式，可以知道
- 开始时，$v_{Ball}=v_t-v_0$，其中$v_t>t_0$，故$v_{Ball}>0$
- 中间时，小球被停下，所以$v_{Ball}=v_t$
- 结束时，小球向正方向行驶$v_{Ball}=v_t+v_0$

所以最终的$v-t$图象是：
![[train_and_ball_problem.png]]
