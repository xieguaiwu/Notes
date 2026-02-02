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
## MCQ
### 1.
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

## 3. 相对速度

相对速度公式：v_{A相对B} = v_A - v_B

如果A车速度为v_A，B车速度为v_B，那么A相对于B的速度就是两者之差。

若A车速度为正（向右），B车速度也为正（向右），则：
- 如果v_A > v_B，则A相对于B向右运动
- 如果v_A < v_B，则A相对于B向左运动

## 4. 相对速度题目
>一列火车以相对于地面的速度 $v_t$ 向 $+x$ 方向行驶。火车上的乘客以相对于火车的速度 $v_0$ 在 $-x$ 方向滚动一个小球。另一名乘客迅速停止小球并以相同的速度 $v_0$ 相对于火车向相反方向滚动。

根据**3**所提供的公式，可以知道
- 开始时，$v_{Ball}=v_t-v_0$，其中$v_t>t_0$，故$v_{Ball}>0$
- 中间时，小球被停下，所以$v_{Ball}=v_t$
- 结束时，小球向正方向行驶$v_{Ball}=v_t+v_0$

所以最终的$v-t$图象是：
![[train_and_ball_problem.png]]

## 5. 向上斜抛运动，计算水平位移
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

