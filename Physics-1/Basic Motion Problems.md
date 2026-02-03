---
tags:
  - Physics
  - 定义性
  - 证明
title: Basic Motion Problems
created: 2026-01-02T15:01:00
modified:
---
# Basic Motion Problems
## 0. 平衡力与相互作用力的区别

| 比较项目 | 平衡力 | 相互作用力（作用力与反作用力） |
|---------|--------|--------------------------|
| **定义** | 作用在同一物体上，使物体保持平衡状态的两个或多个力 | 两个物体间相互作用的一对力 |
| **作用对象** | 同一物体 | 两个不同物体 |
| **力的性质** | 可以是不同性质的力（如重力和弹力） | 一定是同性质的力（如都是弹力或都是摩擦力） |
| **大小关系** | 大小相等，方向相反 | 大小相等，方向相反 |
| **作用线** | 必须在同一直线上（对于二力平衡） | 不一定在同一直线上（但在同一条作用线上） |
| **产生原因** | 为了保持物体平衡 | 物体间的相互作用 |
| **存在条件** | 物体处于平衡状态（静止或匀速直线运动） | 任何情况下都存在（牛顿第三定律） |
| **时间关系** | 可以独立存在 | 同时产生，同时消失 |
| **叠加性** | 可以合成，合力为零 | 不能合成（作用在不同物体上） |
| **典型例子** | 重物放在桌面上，重力与支持力 | 人推墙时，人对墙的力与墙对人的力 |
| **运动状态** | 物体静止或匀速直线运动 | 不影响物体的运动状态（各自作用在不同物体上） |

1. **平衡力**：作用在**同一物体上的多个力，合力为零**，使物体保持静止或匀速直线运动状态。
2. **相互作用力**：根据牛顿第三定律，**两个物体间**的作用力和反作用力总是大小相等、方向相反、作用在不同物体上、同时产生同时消失。
3. **关键区别**：平衡力作用在同一物体上，可以抵消；而相互作用力作用在不同物体上，不能抵消，各自产生各自的作用效果。

## 1.
>A football is kicked off the ground a distance of 50 yards downfield. Neglecting air resistance, which of the following statements would be **INCORRECT** when the football reaches the highest point? 
>(A) all of the balls original kinetic energy has been changed into potential energy
>(B) the ball’s horizontal velocity is the same as when it left the kickers foot 
>(C) the ball will have been in the air one-half of its total flight time
>(D) the vertical component of the velocity is equal to zero

- **选项 (A)**：当足球到达最高点时，其初始动能并未全部转化为势能。因为足球在水平方向上速度保持不变，所以仍然具有动能（水平动能）。实际上，初始动能等于最高点时的动能（水平方向）与势能之和。因此，该说法错误。
    
- **选项 (B)**：由于忽略空气阻力，水平方向不受力，因此水平速度保持不变，与刚踢出时的水平速度相同。该说法正确。
    
- **选项 (C)**：抛体运动具有时间对称性，上升阶段与下降阶段时间相等。因此，到达最高点的时间恰好是总飞行时间的一半。该说法正确。
    
- **选项 (D)**：在最高点，竖直方向的速度由向上变为向下，因此竖直分速度为零。该说法正确。

## 2.
>A rock is dropped from the top of a tall tower. Half a second later another rock, twice as massive as the first, is dropped. Ignoring air resistance,
>(A) the distance between the rocks increases while both are falling.
>(B) the acceleration is greater for the more massive rock. 
>(C) they strike the ground more than half a second apart.
>(D) they strike the ground with the same kinetic energy.


**选项 (A)**：当两个岩石都在下落时，它们之间的距离是否增加？  
- 设第一个岩石的位置为 $y_1 = \frac{1}{2}gt^2$（$t$ 从第一个岩石释放开始计时）。  
- 第二个岩石在 $t \geq 0.5\,\text{s}$ 时的位置为 $y_2 = \frac{1}{2}g(t-0.5)^2$。  
- 两者之间的距离为 $d = y_1 - y_2 = \frac{1}{2}g[t^2 - (t-0.5)^2] = \frac{1}{2}g(t - 0.25)$（当 $t \geq 0.5\,\text{s}$）。  
- 由于 $t$ 增加时 $t - 0.25$ 增加，因此距离 $d$ 随时间增加。此外，两岩石的相对速度 $v_{\text{rel}} = v_1 - v_2 = gt - g(t-0.5) = 0.5g$ 为常数，故距离匀速增加。  
- ✅ 该说法正确。

**选项 (B)**：质量更大的岩石是否有更大的加速度？  
- 忽略空气阻力时，所有物体自由下落的加速度均为 $g$，与质量无关。  
- ❌ 该说法错误。

**选项 (C)**：它们撞击地面的时间差是否大于 0.5 秒？  
- 设塔高为 $h$，第一个岩石的下落时间 $t_1$ 满足 $h = \frac{1}{2}gt_1^2$。  
- 第二个岩石的实际下落时间也为 $t_1$，但因为它晚释放 0.5 秒，所以从同一时间起点看，第二个岩石的撞击时间 $t_2 = t_1 + 0.5$。  
- 因此，撞击时间差为 $t_2 - t_1 = 0.5\,\text{s}$，恰好等于释放的时间差，而非大于 0.5 秒。  
- ❌ 该说法错误。

**选项 (D)**：它们撞击地面时是否具有相同的动能？  
- 撞击地面时，速度均为 $v = \sqrt{2gh}$，与质量无关。  
- 但动能 $E_k = \frac{1}{2}mv^2$，由于质量不同（第一个为 $m$，第二个为 $2m$），因此第二个岩石的动能是第一个的两倍。  
- ❌ 该说法错误。
## 3. 向上斜抛运动，计算水平位移
>如图所示，其中球在到达其无墙时的**理论最高点时刻**，恰好撞到墙。求球的水平位移

![[golf_striker.png]]

已知：
$$v_{0x} = v_0 \cos\theta$$
$$v_{0y} = v_0 \sin\theta$$

### 5.1 方法一
设到达墙的时间为 $t_1$。根据题意，此时球处于理论最高点，竖直速度为 0：
$$v_y(t_1) = v_0\sin\theta - g t_1 = 0 $$
$$\Rightarrow t_1 = \frac{v_0 \sin\theta}{g}$$
那么自然
$$x = v_{0x} \cdot t_1 = (v_0 \cos\theta) \cdot \left(\frac{v_0 \sin\theta}{g}\right) = \frac{v_0^2 \sin\theta \cos\theta}{g}$$

### IMP 5.2 方法二
由于球最终落回原点，我们可以使用镜像法来理解这个问题。弹性碰撞于竖直墙等价于在墙的另一侧存在一个镜像物体。

**从击球点到墙的距离为 $x$，从墙到镜像物体的落点也为 $x$，因此总水平射程为 $2x$**
对于一个完整的抛体运动，水平射程公式为：
$$x_{total} = \frac{v_0^2 \sin(2\theta)}{g} = \frac{2v_0^2 \sin\theta \cos\theta}{g}$$
既然
$$2x = \frac{2v_0^2 \sin\theta \cos\theta}{g}$$
那么
$$x = \frac{v_0^2 \sin\theta \cos\theta}{g}$$

