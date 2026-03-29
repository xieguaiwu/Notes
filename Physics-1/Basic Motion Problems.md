---
tags:
  - Physics
  - 定义性
  - 证明
  - Exercise
title: Basic Motion Problems
created: 2026-01-02T15:01:00
modified:
---
# Basic Motion Problems
## 0. 平衡力与相互作用力的区别
[[FBD Problems]]
[[Reference Frames Problems]]
[[Vector & Scalar Problems]]

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


## 4. IMP 不同的摩擦力导致不同运动时间 （最简洁的解法）
>木块在两个场景中受到不一样的摩擦力，但是其初始速度恒定。在图一中它需要$t_1$的时间来减速静止，在图二中则需要$t_2$，求$t_1$ & $t_2$的关系

![[different_frictions_different_times.png]]

匀减速运动中，平均速度 $\bar{v} = \frac{v_0-v}{2}$ 相同，由于$v=0$，那么平均速度是$\bar{v} = \frac{v_0}{2}$则：
 - $t_1 = \frac{D}{v_0/2} = \frac{2D}{v_0}$
 - $t_2 = \frac{4D}{v_0/2} = \frac{8D}{v_0}$

同样得 $t_1 : t_2 = 1 : 4$

## 5. 斜面摩擦系数
>一个物块以 $20 \, \text{m/s}$ 的初速度沿粗糙斜面向上滑动。物块滑动 $2.0 \, \text{s}$ 后瞬时静止。求物块与斜面之间的动摩擦因数。

![[kinetic_friction_of_a_ramp.png]]

沿斜面方向的分力：
 - 重力沿斜面分量：$mg\sin\theta$（沿斜面向下）
 - 摩擦力：$\mu_k mg\cos\theta$（沿斜面向下）

列牛顿第二定律方程
沿斜面方向（取沿斜面向下为正）：

$$mg\sin\theta + \mu_k mg\cos\theta = ma$$
$$g\sin\theta + \mu_k g\cos\theta = a$$

求解动摩擦因数
代入数值：

$$10 \times \sin 30^\circ + \mu_k \times 10 \times \cos 30^\circ = 10$$
$$\mu_k \times 5\sqrt{3} = 5$$
$$\mu_k = \frac{5}{5\sqrt{3}} = \frac{1}{\sqrt{3}} \approx 0.577 \approx 0.58$$

## 6. 渡河问题-最短时间，理清楚分量
>一艘船在静水中的最大速度为 $5 \, \text{km/h}$，河宽 $1 \, \text{km}$，水流速度为 $4 \, \text{km/h}$。若要到达正对岸，求最短渡河时间。

关键理解

题目要求到达正对岸（位移垂直于河岸），因此船的**合速度必须垂直于河岸**。

船速分解：
 - 垂直河岸方向：$v_\perp = 5\sin\alpha$
 - 沿河岸方向：$v_\parallel = 5\cos\alpha$

抵消水流条件：
$$5\cos\alpha = 4$$
$$\cos\alpha = \frac{4}{5}$$

求垂直分速度

由 $\cos\alpha = \frac{4}{5}$，得：
$$\sin\alpha = \sqrt{1 - \cos^2\alpha} = \sqrt{1 - \frac{16}{25}} = \frac{3}{5}$$

垂直河岸的分速度：
$$v_\perp = 5 \times \frac{3}{5} = 3 \, \text{km/h}$$

求渡河时间
$$t = \frac{\text{河宽}}{v_\perp} = \frac{1}{3} \, \text{h}$$
✦ > 注意区分：
  > - 若只求最短渡河时间（允许漂移）：船头垂直对岸，$t = \frac{1}{5} \, \text{h}$
  > - 若要求到达正对岸（合位移垂直）：$t = \frac{1}{3} \, \text{h}$

## IMP 7. 火箭的运动方程
>一枚模型火箭从地面竖直发射。火箭从静止开始，以加速度 $a$ 向上加速时间 $t$，然后发动机关闭，火箭继续向上运动。求火箭能达到的最大高度。

第一阶段：发动机工作

位移：
$$h_1 = \frac{1}{2}at^2$$

末速度：
$$v = v_0 + at = at$$

第二阶段：惯性上升

已知：
 - 初速度：$v = at$
 - 末速度：$v' = 0$（最高点）
 - 加速度：$-g$（仅受重力）

求附加高度：
$$0 - (at)^2 = 2(-g)h_2$$
$$h_2 = \frac{(at)^2}{2g} = \frac{a^2t^2}{2g}$$

总高度
$$h_{\max} = h_1 + h_2 = \frac{at^2}{2} + \frac{a^2t^2}{2g}$$

## 8. 较难的图像识别题目，将v-t graph转换成a-t graph
>根据给定的 $v\text{-}t$ 图像，判断正确的 $a\text{-}t$ 图像。

![[from_vt_graph_to_at_graph.png]]

**分段分析：**

| 时间段 | $v\text{-}t$ 特征 | 加速度 |
|---|---|---|
| $0 \leq t < 1$ s | 水平线，速度恒定 | $a = 0$ |
| $1 \leq t \leq 4$ s | 曲线下降，斜率为负 | $a < 0$ |
| $t > 4$ s | $v \approx 0$，静止 | $a = 0$ |


### 关键分析：$1 \sim 4$ s 段

加速度 $a = \dfrac{dv}{dt}$，即 $v\text{-}t$ 曲线的**切线斜率**。

观察 $v\text{-}t$ 曲线的变化趋势：
- $t = 1$ s：切线较陡，斜率为较大负值
- $t = 4$ s：切线趋于水平，斜率趋近于 0

**结论：加速度从较大负值逐渐增大到 0**

即 $a(t)$ 是**负值且单调递增**的函数。
![[from_vt_graph_to_at_graph2.png]]
