---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: region_integration_03.20
created: 2026-03-20T02:03:00
modified:
---
# region_integration_03.20
[[旋转体体积积分]]
![[problem_03.20.png]]
图中阴影面积为$y=6$和$y=2\sqrt{x}$围成的面积

## 1. 求阴影面积$R$
为了确认阴影面积，首先必须明白方向：**它是$x\in[0,9]$当中的积分，而不是$y$方向的积分**
### IMP 求反函数
$$y=2\sqrt{x}\to x = \frac{y^2}{4}$$
$$y=6\to x=0$$

### 进行积分
 $$\text{Area} = \int_0^6 \left(\frac{y^2}{4} - 0\right) dy = \int_0^6 \frac{y^2}{4} \, dy = \left[\frac{y^3}{12}\right]_0^6 =
  \frac{216}{12} = 18$$

## 2. 求$R$绕$y=7$旋转产生的体积

### 几何分析
旋转轴 $y=7$ 位于区域 $R$ 上方（区域最高点 $y=6$）。
- 外半径：从旋转轴 $y=7$ 到曲线 $y=2\sqrt{x}$ 的距离
  $$R_{外} = 7 - 2\sqrt{x}$$
- 内半径：从旋转轴 $y=7$ 到直线 $y=6$ 的距离
  $$R_{内} = 7 - 6 = 1$$

使用**垫圆法（Washer Method）**，积分区间 $x \in [0, 9]$：

### 计算过程

$$V = \pi \int_0^9 \left[(7-2\sqrt{x})^2 - 1^2\right] \, dx$$

展开被积函数：
$$\begin{aligned}
(7-2\sqrt{x})^2 - 1 &= 49 - 28\sqrt{x} + 4x - 1 \\
&= 48 - 28\sqrt{x} + 4x
\end{aligned}$$

积分：
$$\begin{aligned}
V &= \pi \int_0^9 (48 - 28\sqrt{x} + 4x) \, dx \\
&= \pi \left[48x - 28 \cdot \frac{2}{3}x^{3/2} + 2x^2\right]_0^9 \\
&= \pi \left[48x - \frac{56}{3}x^{3/2} + 2x^2\right]_0^9
\end{aligned}$$

代入上下限：
$$\begin{aligned}
V &= \pi \left(48 \cdot 9 - \frac{56}{3} \cdot 27 + 2 \cdot 81 - 0\right) \\
&= \pi \left(432 - 504 + 162\right) \\
&= \pi \cdot 90 \\
&= \boxed{90\pi}
\end{aligned}$$

---

**答案：**
- 阴影面积 $R = 18$
- 绕 $y=7$ 旋转的体积 $V = 90\pi$