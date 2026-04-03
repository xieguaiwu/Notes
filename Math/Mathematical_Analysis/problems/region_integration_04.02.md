---
tags:
  - Math
  - Exercise
  - 证明
title: region_integration_04.02
created: 2026-04-02T21:17:00
modified:
---
# region_integration_04.02
## Q1
>求出极坐标方程中间的小环所围成的面积的积分公式$$r=1+2\sin\theta$$

![[problem_0402.png]]

问题的关键在于**找到函数中间小环所对应的$\theta$取值区间**，得到区间后才能够使用[[极坐标求导与积分]]中的公式。

## 解答过程
### 第一步：确定小环对应的θ区间
小环的形成原因是 $r$ 在某些区间内取负值。首先求 $r=0$ 的点：$$1 + 2\sin\theta = 0 \implies \sin\theta = -\frac{1}{2}$$

在 $[-\pi, \pi]$ 范围内：$$\theta = -\frac{\pi}{6} \quad \text{或} \quad \theta = -\frac{5\pi}{6}$$

当 $\theta \in \left[-\frac{5\pi}{6}, -\frac{\pi}{6}\right]$ 时，$\sin\theta < -\frac{1}{2}$，此时 $r = 1 + 2\sin\theta < 0$。

当极径 $r < 0$ 时，点实际位于极角相反方向，这个区间就形成了中间的小环。

### 第二步：应用极坐标面积公式
极坐标面积公式为：$$A = \frac{1}{2}\int_{\alpha}^{\beta} r^2 \, d\theta$$

对于中间小环，$\theta$ 的范围是 $\left[-\frac{5\pi}{6}, -\frac{\pi}{6}\right]$，故：

$$A = \frac{1}{2}\int_{-\frac{5\pi}{6}}^{-\frac{\pi}{6}} (1+2\sin\theta)^2 \, d\theta$$

## Q2
>求出第一象限中被极坐标方程$r=4\cos\theta$和直线$\theta=1$夹在中间的区域的面积

![[problem_0402_2.jpg]]

被"夹在中间"的区域由以下边界围成：
1. 极轴（$\theta=0$）：从原点到 $(4,0)$
2. 圆弧 $r=4\cos\theta$：从 $\theta=0$ 到 $\theta=1$
3. 射线 $\theta=1$：从原点到圆上的点 $(4\cos 1, 1)$

因此，所求区域对应的参数范围为：
$$\theta \in [0, 1], \quad r \in [0, 4\cos\theta]$$

对于所求区域：$$A = \frac{1}{2}\int_{0}^{1} (4\cos\theta)^2 \, d\theta = 8\int_{0}^{1} \cos^2\theta \, d\theta$$

**仔细分析图象，不要直接将两个图象相减，而是规划好上下限**

## Q3
>对于两个极坐标方程图象$r=3$和$r=4\sin\theta$，找到$r=4\sin\theta$中未被小圆覆盖的部分的面积

![[problem_0402_3.png]]

求两圆交点对应的 $\theta$ 值：
$$r=3=r=4\sin\theta$$
$$3 = 4\sin\theta \implies \sin\theta = \frac{3}{4}$$

设 $\alpha = \arcsin\frac{3}{4}$，则交点对应的极角为：
$$\theta_1 = \alpha, \quad \theta_2 = \pi - \alpha$$

**分析覆盖关系：**
- 当 $\theta \in [\alpha, \pi-\alpha]$ 时：$4\sin\theta \geq 3$，小圆上的点在大圆外部
- 当 $\theta \in [0, \alpha] \cup [\pi-\alpha, \pi]$ 时：$4\sin\theta \leq 3$，小圆上的点在大圆内部

因此，$r=4\sin\theta$ 中未被 $r=3$ 覆盖的部分对应 $\theta \in [\alpha, \pi-\alpha]$。

所求面积为：
$$A = \frac{1}{2}\int_{\alpha}^{\pi-\alpha} \left[(4\sin\theta)^2 - 3^2\right] d\theta = \frac{1}{2}\int_{\alpha}^{\pi-\alpha} (16\sin^2\theta - 9) \, d\theta$$

## Q4
>找到两个极坐标函数所围成的面积：$$r=\cos^3(2\theta)+1$$
>$$r=1.25\theta (0\leq \theta\leq\frac{\pi}{2})$$

![[problem_0402_4.png]]

设交点为 $\theta = \alpha$，满足：
$$\cos^3(2\alpha) + 1 = 1.25\alpha$$

即求解方程：
$$\cos^3(2\alpha) + 1 - 1.25\alpha = 0$$

**数值求解：**
- 当 $\alpha = 0.8$ 时：$\cos^3(1.6) + 1 - 1 \approx -0.000024 + 1 - 1 \approx 0$
- 经数值计算得：$\alpha \approx 0.7998$ 弧度

**为何必须分成两部分计算？**

在极坐标中，两曲线 $r_1(\theta)$ 和 $r_2(\theta)$ 所围面积公式为：
$$A = \frac{1}{2}\int (r_{\text{外}}^2 - r_{\text{内}}^2) \, d\theta$$

关键在于：**两条曲线的"内外关系"在交点处发生了互换。**

| 区间 | $r_1 = \cos^3(2\theta) + 1$ | $r_2 = 1.25\theta$ | 外曲线 |
|------|------------------------------|---------------------|--------|
| $\theta \in [0, \alpha]$ | $r_1 > r_2$ | $r_2 < r_1$ | $r_1$ |
| $\theta \in [\alpha, \frac{\pi}{2}]$ | $r_1 < r_2$ | $r_2 > r_1$ | $r_2$ |

- **交点前**（$\theta < \alpha$）：$r_1$ 从 $r=2$ 出发（较远），$r_2$ 从 $r=0$ 出发（较近），$r_1$ 在外
- **交点后**（$\theta > \alpha$）：$r_1$ 趋近 $r=0$（较近），$r_2$ 到达 $r \approx 1.96$（较远），$r_2$ 在外

若不分两部分，直接写成 $\frac{1}{2}\int_{0}^{\frac{\pi}{2}} (r_1^2 - r_2^2) \, d\theta$，则在交点一侧被积函数为正、另一侧为负，两部分会相互抵消，得不到正确的面积值。

**结论：分两部分的目的是保证被积函数始终为"外² - 内²"，确保面积恒为正值。**

因此，两曲线所围成的面积分为两部分：
1. 当 $\theta \in [0, \alpha]$ 时：$r_1 > r_2$，$r_1$ 为外曲线
2. 当 $\theta \in [\alpha, \frac{\pi}{2}]$ 时：$r_2 > r_1$，$r_2$ 为外曲线

所求面积为：
$$A = \frac{1}{2}\int_{0}^{\alpha} [r_1^2 - r_2^2] \, d\theta + \frac{1}{2}\int_{\alpha}^{\frac{\pi}{2}} [r_2^2 - r_1^2] \, d\theta$$

$$A_1 = \frac{1}{2}\int_{0}^{\alpha} \left[(\cos^3(2\theta) + 1)^2 - (1.25\theta)^2\right] \, d\theta$$

$$A_2 = \frac{1}{2}\int_{\alpha}^{\frac{\pi}{2}} \left[(1.25\theta)^2 - (\cos^3(2\theta) + 1)^2\right] \, d\theta$$

设 $\alpha \approx 0.7998$，代入数值计算得：
$$A = A_1 + A_2 \approx 0.837$$
