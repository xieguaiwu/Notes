---
tags:
  - Physics
  - 证明
  - 基本原理
title: Energy & Work Problems
created: 2026-01-05T22:59:00
modified:
---
# Energy & Work Problems

最重要的问题是：当只有conservative force做功时，**只看最初和最终状态即可展开分析**

## 1. 基本的斜面+物体模型
第一个情况下，物体没有重力势能，此时其**动能最大**
![[slide_model_ke_max.png]]
设定此时的速度为$v_0$，那么总机械能就是
$$ME=\frac{1}{2}mv_0^2$$

此时物体在最高点，达到**静止状态**（$v_f=0$），因此**动能全部转化为重力势能**
![[slide_model_pge_max.png]]
若此时速度为$v_f$：
$$\frac{1}{2}mv_f^2=mgh$$
$$v_f=\sqrt{2gh}$$

此时物体在运动中，其**同时受到摩擦力、动能和重力势能**
![[slide_model_ke_middle.png]]
设定此刻高度为$h_1$，且在斜面上运动的距离是$d$，设定此刻的速度是$v_1$，得到总机械能
$$ME=\frac{1}{2}mv_1^2+mg\cos\theta\cdot d+mgh_1$$
其中$mg\cos\theta\cdot d$是**摩擦力做功**，设定倾斜角为$\theta$
代入初始情景下得到的数值，即$$ME=\frac{1}{2}mv_0^2$$
得到：
$$\frac{1}{2}mv_0^2=\frac{1}{2}mv_1^2+mg\cos\theta\cdot d+mgh_1$$