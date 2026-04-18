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

**相关笔记：**
- [[AP 1 Simple Harmonic Motion - Complete Review]] - 简谐振动完整复习笔记
- [[Simple Harmonic Motion]] - 简谐振动详解
- [[Simple Pendulum]] - 单摆详解
- [[Pendulum Problems]] - 单摆问题集
- [[Oscillation Problems]] - 振动问题集

---

弹力做功: 当物块**远离平衡位置**（位移方向背离$x=0$）时，弹力指向平衡位置，与位移方向相反，**做负功**；当物块**向平衡位置**（位移方向指向$x=0$）运动时，弹力与位移方向相同，**做正功**。  

## 1 IMP 速度与振幅
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

## 2 （基本读图题）
>一个物体被连接在弹簧上做简谐运动，请找到与其位置图对应的能量图

![[pos_change_and_ke_change.png]]

问题的关键是要注意到**物体在一开始时是处于平衡态的**，只有**当位置小于振幅才会有能量**

另一方面，尽管位置有正有负，但是能量始终$\geq 0$

能量图如下：
![[pos_change_and_ke_change2.png]]

## 3 简谐运动负功
>一个物块连接在弹簧上，在$x = +A$和$x = -A$之间做简谐运动。物块的位置$x$随时间$t$变化的图像如上所示。求在$t_A$, $t_B$, $t_C$, $t_D$中的哪个标记的时间，弹簧对物块做负功？

![[negative_work_done_in_simple_hermonic_motion.png]]

弹簧对物块做功的符号由**弹力与位移的方向关系**决定：当弹力与位移方向相反时，做负功；相同时做正功。简谐运动中，弹力$F = -kx$（指向平衡位置$x=0$），位移方向由$x-t$图像的斜率（速度$v$）决定。  

- **各时间点分析**：  
  - $t_A$：$x$在$0$和$-A$之间，曲线下降（斜率为负，速度$v$为负），物块向$x$更负的方向运动（远离平衡位置）。弹力$F = -kx$（$x$负，$F$正，指向平衡位置），与位移（负）方向相反，做正功
  - $t_B$：$x = -A$（最低点），速度$v=0$，位移为0，做功为0。  
  - $t_C$：$x$在$0$和$A$之间，曲线上升（斜率为正，速度$v$为正），物块向$x$正的方向运动（远离平衡位置）。弹力$F = -kx$（$x$正，$F$负，指向平衡位置），与位移（正）方向相反，做负功。  
  - $t_D$：$x = A$（最高点），速度$v=0$，位移为0，做功为0。  

关键逻辑：当物块**远离平衡位置**（如$t_C$时向$A$运动）时，弹力阻碍运动，做负功。因此$t_C$时弹簧对物块做负功。  


