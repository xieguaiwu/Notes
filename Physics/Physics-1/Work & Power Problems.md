---
tags:
  - Physics
  - 证明
  - Exercise
title: Work & Power Problems
created: 2026-04-18T10:45:00
modified:
---
# Work & Power Problems

当仅仅分析单个物体时，不需要使用能量守恒，仅仅使用以下公式即可$$w=\Delta k$$

## 1 功率与速度
>两个相同的滑块在粗糙的水平表面上滑动一段距离D，如图所示。滑块A的初速度为 $v_0$，滑块B的初速度为 $\dfrac{v_0}{2}$。两个滑块在滑动距离D后仍在运动。以下哪项正确地表达了滑块A与表面之间摩擦力产生的功率 $P_\text{A}$ 与滑块B与表面之间摩擦力产生的功率 $P_\text{B}$ 之间的关系？

![[different_velocities_and_friction_power.png]]
由于两个滑块质量完全相同，且在同一粗糙表面上滑动，摩擦力大小相同：

$$f_A = f_B = f = \mu mg$$

摩擦力的功率定义为：$P = \vec{f} \cdot \vec{v}$

由于摩擦力方向与速度方向相反，功率为负值。但题目问的是功率的**大小关系**（或者说功率的代数值比较）。

$$P_A = -f \cdot v_A = -\mu mg \cdot v_A$$
$$P_B = -f \cdot v_B = -\mu mg \cdot v_B$$

因为 $v_A > v_B$，且摩擦力相同，所以：

$$|P_A| > |P_B|$$

但如果我们考虑功率的代数值（**均为负**）：

$$P_A = -\mu mg \cdot v_A$$
$$P_B = -\mu mg \cdot v_B$$

由于 $v_A > v_B > 0$，且两者前面都有负号，所以：

$$P_A < P_B$$

## 2 $W=\Delta K$
> 一个箱子在水平面上运动，受到变化的力，速度发生改变。图像显示了箱子速度随时间的变化。描述三个间隔中箱子做的净功 $W_{\text{net}}$：$[0,t_1]$, $[t_1,t_2]$, $[t_2,t_3]$

![[work_done_during_interval.png]]

$$W_{\text{net}} = \Delta K = \frac{1}{2}m(v_f^2 - v_i^2)$$

初速度 $v_i = -v$，末速度 $v_f = +v$

$$\Delta K = \frac{1}{2}m[(+v)^2 - (-v)^2] = \frac{1}{2}m(v^2 - v^2) = 0$$

**关键点**：动能是标量，只与速率平方有关，与速度方向无关。此段速率从 $v$ 变到 $v$，动能不变。

**步骤2：分析 $t_1 \to t_2$ 段**

速度恒为 $+v$，动能不变：
$$\Delta K = 0 \Rightarrow W_{\text{net}} = 0$$

**步骤3：分析 $t_2 \to t_3$ 段**

初速度 $v_i = +v$，末速度 $v_f = 0$：
$$\Delta K = \frac{1}{2}m(0^2 - v^2) = -\frac{1}{2}mv^2 < 0$$

## 3
>两个质量相等的学生从山的两侧跑到山顶，如图所示。每个学生到达山顶的时间相同，但**学生Y需要跑两倍的距** 
> 在学生跑上山的途中，地球对X学生做功的功率 $P_X$ 与地球对Y学生做功的功率 $P_Y$ 相比如何？

![[power_in_hill_climbing_with_different_distance.png]]

重力是保守里，**做功只与竖直高度有关，与路径无关。**

- 两个学生质量相等（$m_X = m_Y$），到达山顶的竖直高度 $h$ 相同，因此地球对两者做的功相等：$W_X = W_Y = mgh$。 
- 题目明确“每个学生到达山顶的时间相同”，根据功率公式 $P = \frac{W}{t}$，可得 $P_X = \frac{W_X}{t_X} = \frac{mgh}{t}$，$P_Y = \frac{W_Y}{t_Y} = \frac{mgh}{t}$，因此 $P_X = P_Y$。


