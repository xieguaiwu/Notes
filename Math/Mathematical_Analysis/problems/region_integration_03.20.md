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
可以判断出这属于垫圆法，具有内腔