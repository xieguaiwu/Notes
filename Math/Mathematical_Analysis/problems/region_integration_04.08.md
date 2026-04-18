---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: region_integration_04.08
created:
modified:
---
# region_integration_04.08
## Q1
>下方图像由$r=1-\cos\theta$ & $r=1+\cos\theta$围成，求出面积

![[problem_0408.png]]

**分析曲线：**
- $r=1+\cos\theta$：心形线，开口向右（$\theta=0$ 时 $r=2$ 最大）
- $r=1-\cos\theta$：心形线，开口向左（$\theta=\pi$ 时 $r=2$ 最大）

**求交点：**
$$1-\cos\theta = 1+\cos\theta \Rightarrow \cos\theta = 0 \Rightarrow \theta = \frac{\pi}{2}, \frac{3\pi}{2}$$

交点为 $(r, \theta) = (1, \frac{\pi}{2})$ 和 $(1, \frac{3\pi}{2})$，对应直角坐标 $(0, \pm 1)$。

**利用对称性：** 区域关于 $x$ 轴对称，先计算上半部分（$\theta \in [0, \pi]$）：
- $\theta \in [0, \frac{\pi}{2}]$：外曲线是 $r=1+\cos\theta$
- $\theta \in [\frac{\pi}{2}, \pi]$：外曲线是 $r=1-\cos\theta$

**计算面积：**
$$A = \int_{0}^{\pi/2}(1+\cos\theta)^2 d\theta + \int_{\pi/2}^{\pi}(1-\cos\theta)^2 d\theta$$

## Q2
>下方图像是第一象限内由$y=4\cos(\frac{\pi x}{4})$和$y=(x-2)^2$围成，求其面积

![[problem_0408_2.png]]

**求交点：** 令 $4\cos\left(\frac{\pi x}{4}\right) = (x-2)^2$

- $x=0$：$4\cos 0 = 4$，$(0-2)^2 = 4$ ✓
- $x=2$：$4\cos\frac{\pi}{2} = 0$，$(2-2)^2 = 0$ ✓

交点为 $x=0$ 和 $x=2$。

**设置积分：** 在 $[0, 2]$ 上，$\cos$ 曲线在抛物线上方：

$$A = \int_{0}^{2}\left[4\cos\left(\frac{\pi x}{4}\right) - (x-2)^2\right] dx$$

