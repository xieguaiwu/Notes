---
tags:
  - Physics
  - 定义性
  - Exercise
  - 证明
title: Circular Motion Problems
created: 2026-02-09T15:18:00
modified:
---
# Circular Motion Problems
[[Circular Motion & Gravitation]]
## 1.
>一枚硬币以恒定速度 $v_0$ 在圆锥内表面上沿圆形路径滚动，如图所示。硬币路径的曲率半径为 $r_0$，圆锥表面与水平面的夹角为 $\theta_0$。然后将硬币移到另一个圆锥，该圆锥表面与水平面的夹角为 $\theta_1$，使得$\tan\theta_1 = 9 \tan\theta_0$。且硬币以恒定速度 $v_1$ 沿曲率半径为 $r_1 = \dfrac{1}{4} r_0$ 的圆周运动。如何表示 $v_1$ 与 $v_0$ 的关系？

![[cone_cone_circular_motion.png]]
硬币在圆锥内壁做**匀速圆周运动**，受力包括：
- 重力 $mg$，竖直向下
- 法向支持力 $N$，垂直于锥面

设锥面与水平面的夹角为 $\theta$，则锥面法线与竖直方向的夹角也为 $\theta$。

支持力 $N$ 的分解：
- 竖直分量：$N \cos\theta$（向上）
- 水平分量（指向轴线）：$N \sin\theta$

由于运动是水平匀速圆周运动：

1. 竖直方向加速度为 0 ⇒ 竖直方向合力为 0：

$$
N \cos\theta = mg \quad \text{(1)}
$$

2. 水平方向合力提供向心力：

$$
N \sin\theta = \frac{m v^2}{r} \quad \text{(2)}
$$

将方程 (1) 代入方程 (2)：

$$\begin{aligned}
\frac{mg}{\cos\theta} \cdot \sin\theta &= \frac{m v^2}{r} \\
mg \tan\theta &= \frac{m v^2}{r} \\
v^2 &= g r \tan\theta
\end{aligned}$$

$$v_0^2 = g r_0 \tan\theta_0 \quad \text{(3)}$$

### 新情况

已知条件：
- $\tan\theta_1 = 9 \tan\theta_0$
- $r_1 = \dfrac{1}{4} r_0$

代入核心公式：

$$
\begin{aligned}
v_1^2 &= g r_1 \tan\theta_1 \\
      &= g \cdot \left(\frac{1}{4} r_0\right) \cdot \left(9 \tan\theta_0\right) \\
      &= \frac{9}{4} g r_0 \tan\theta_0
\end{aligned}
$$

由方程 (3)，$g r_0 \tan\theta_0 = v_0^2$，代入得：

$$
\begin{aligned}
v_1^2 &= \frac{9}{4} v_0^2 \\
v_1 &= \frac{3}{2} v_0 \quad \text{（取正值，因速度大小）}
\end{aligned}
$$

