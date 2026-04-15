---
tags:
  - Physics
  - Exercise
  - 证明
title: Simple Harmonic Motion Problems
created: 2026-04-07
modified: 
---
# Simple Harmonic Motion Problems
## Q1
> 当物块位于位置 $x = 0$ 时，弹簧-物块系统处于平衡状态，如图1所示。然后将物块向左推，使弹簧压缩距离 $x = 0.5 \, \text{m}$，如图2所示。物块从静止释放，做简谐运动。振动过程中，物块的最大速度为 $v_{\max}$ 
> 物块的速度大小为 $\dfrac{v_{\max}}{2}$ 时的位置在哪里？

![[max_speed_in_simple_harmonic_motion.png]]

- 振幅 $A = 0.5 \, \text{m}$（从 $x = -0.5 \, \text{m}$ 释放）
- 平衡位置 $x = 0$
- 最大速度 $v_{\max} = A\omega$

简谐运动中，速度大小与位移的关系（由能量守恒推导）：$$v = \omega\sqrt{A^2 - x^2}$$

或写成：$$|v| = v_{\max}\sqrt{1 - \left(\frac{x}{A}\right)^2}$$

设 $|v| = \dfrac{v_{\max}}{2}$，代入公式：$$\frac{v_{\max}}{2} = v_{\max}\sqrt{1 - \left(\frac{x}{A}\right)^2}$$
$$\left(\frac{x}{A}\right)^2 = \frac{3}{4}$$
$$|x| = A \cdot \frac{\sqrt{3}}{2} = 0.5 \times \frac{\sqrt{3}}{2} = \frac{\sqrt{3}}{4} \approx 0.433 \, \text{m}$$

## Q2 （基本读图题）
>一个物体被连接在弹簧上做简谐运动，请找到与其位置图对应的能量图

![[pos_change_and_ke_change.png]]

问题的关键是要注意到**物体在一开始时是处于平衡态的**，只有**当位置小于振幅才会有能量**

另一方面，尽管位置有正有负，但是能量始终$\geq 0$

能量图如下：
![[pos_change_and_ke_change2.png]]