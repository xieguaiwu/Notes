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

## 2. 连接体+弹性势能
>如图所示，两个物块置于水平面上，由一根弹簧连接。一根绳子以恒定力拉动其中一个物块，且两个物块**具有相同的向右加速度**。弹簧的弹性势能是否为零？

![[spring_and_connected_object.png]]
首先使用牛顿第二定律进行分析，那么左侧木块**只受到弹簧的拉力**
$$F_{spring} = m_{left} \cdot a$$
由于物块向右加速（$a > 0$），所以 $F_{spring} > 0$
**结论：** 弹簧必须对左侧物块施加**向右的力**，故弹性势能一定**不为零**

## 3.
>在图1中，一个质量为 $m$ 的物块到达斜坡底部时的速度为 $v$。当物块到达斜坡顶部时，其高度增加了 $h$，物块-地球系统的重力势能改变了 $\Delta U_{g1}$
>在图2中，一个质量为 $2m$ 的物块到达同一斜坡底部时的速度为 $\frac{v}{2}$。当物块到达斜坡顶部时，其高度增加了 $h$，物块-地球系统的重力势能改变了 $\Delta U_{g2}$
>如何表达 $\Delta U_{g1}$ 与 $\Delta U_{g2}$ 的关系？

![[change_in_mass_and_speed_lead_to_change_in_UG.png]]
### 分析图1的情况
- 物块质量：$m$
- 高度增加量：$h$
$$\Delta U_{g1} = mgh$$
### 分析图2的情况
- 物块质量：$2m$
- 高度增加量：$h$
$$\Delta U_{g2} = (2m)gh = 2mgh$$
自然，
$$2\Delta U_{g1}=\Delta U_{g2}$$
重点在于屏蔽题干中的干扰项，$v$的大小不影响题目的结果

## 4. 
>两个相同的滑块在粗糙的水平表面上滑动一段距离D，如图所示。滑块A的初速度为 $v_0$，滑块B的初速度为 $\dfrac{v_0}{2}$。两个滑块在滑动距离D后仍在运动。以下哪项正确地表达了滑块A与表面之间摩擦力产生的功率 $P_\text{A}$ 与滑块B与表面之间摩擦力产生的功率 $P_\text{B}$ 之间的关系？

![[different_velocities_and_friction_power.png]]
由于两个滑块质量完全相同，且在同一粗糙表面上滑动，摩擦力大小相同：

$$f_A = f_B = f = \mu mg$$

摩擦力方向与运动方向相反，做负功。
由牛顿第二定律：

$$a = \dfrac{f}{m} = \mu g$$

两个滑块的加速度大小相同，方向都与速度方向相反。


使用速度-位移公式：$v^2 - v_0^2 = 2as$

其中 $a = -\mu g$，位移 $s = D$

**对于滑块A：**

$$v_A^2 = v_0^2 - 2\mu g D$$

$$v_A = \sqrt{v_0^2 - 2\mu g D}$$

**对于滑块B：**

$$v_B^2 = \left(\dfrac{v_0}{2}\right)^2 - 2\mu g D = \dfrac{v_0^2}{4} - 2\mu g D$$

$$v_B = \sqrt{\dfrac{v_0^2}{4} - 2\mu g D}$$

比较 $v_A$ 和 $v_B$：

由于 $v_0 > \dfrac{v_0}{2}$，滑块A的初始动能更大：
$$KE_{A0} = \dfrac{1}{2}mv_0^2$$
$$KE_{B0} = \dfrac{1}{2}m\left(\dfrac{v_0}{2}\right)^2 = \dfrac{1}{8}mv_0^2$$

摩擦力做的功相同：$W_f = -fD = -\mu mgD$

剩余动能：
$$KE_A = \dfrac{1}{2}mv_0^2 - \mu mgD$$
$$KE_B = \dfrac{1}{8}mv_0^2 - \mu mgD$$

摩擦力的功率定义为：$P = \vec{f} \cdot \vec{v}$

由于摩擦力方向与速度方向相反，功率为负值。但题目问的是功率的**大小关系**（或者说功率的代数值比较）。

$$P_A = -f \cdot v_A = -\mu mg \cdot v_A$$
$$P_B = -f \cdot v_B = -\mu mg \cdot v_B$$

因为 $v_A > v_B$，且摩擦力相同，所以：

$$|P_A| > |P_B|$$

但如果我们考虑功率的代数值（均为负）：

$$P_A = -\mu mg \cdot v_A$$
$$P_B = -\mu mg \cdot v_B$$

由于 $v_A > v_B > 0$，且两者前面都有负号，所以：

$$P_A < P_B$$

