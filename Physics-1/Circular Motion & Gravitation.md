---
tags:
  - Physics
  - 定义性
  - Geometry
  - Dynamics
  - 证明
  - Calculus
title: Circular Motion & Gravitation
created: 2025-11-26T12:33:00
modified: 2025-11-27
---
[[limit]]
# Circular Motion & Gravitation
## 0. Preparation
### 0.1
在一个uniform circular motion中，当$\lim{\Delta t\to 0}$时
![[centripetal_movement.png]]
可以得到linear velocity的定义式：
$$v=\frac{\Delta l}{\Delta t}$$
其方向就是物体切线的方向

### 0.2
物体在一段时间内转过角度$\Delta\theta$时，可以得到angular velocity的定义式：
$$\omega =\frac{\Delta\theta}{\Delta t}$$
其中$\Delta\theta$ 的单位是radian，那么angular velocity的单位就是$rad/s$

### 0.3
考虑到线速度和角速度各自的定义式，考虑到$\Delta\theta$以radian为单位，所以可以写出
$$\Delta\theta=\frac{\Delta l}{r}$$
其中$r$就是半径
那么得出linear和angular velocity的关系：
$$v=\omega\cdot r$$

### 0.4
对于圆周运动的frequency $f$和其period $T$，有
$$T=\frac{1}{f}$$
其中$f$的单位是$rev/s$（即$Hz$），即每秒内旋转的圈数 (revolution)
另一方面，$T$则代表了完整旋转一圈所花费的时间，则其单位为$s$

## 1. Uniform Circular Motion
Uniform circular motion即物体速度大小不变（但方向改变）的圆周运动，其图示如下：
![[uniform_circular_motion.png]]
对于这种运动，其运动方向的变化就是其加速度，则加速度$\vec{a}$和$\Delta\vec{v}$方向相同，都是向运动中心的，所以称其为centripetal/radial acceleration（向心加速度），记作$\vec{a}_R$
（在Uniform Circular Motion中，**向心加速度和向心力都朝向运动中心**；另一方面，做圆周运动的物体**没有离心力**）

## 2. Centripetal Acceleration & Centripetal Force
为了计算$\vec{a}_R$，见下方的示意图
![[centripetal_movement.png]]
取一个足够小的$\Delta\theta$，于是从$A$点到$B$点的运动距离趋近于$\Delta l$
结合圆弧计算公式，可以知道
$$\Delta l=r\cdot\Delta\theta$$

考虑到$a=\frac{\Delta v}{\Delta t}$，需要想办法在圆周运动的模型中找到表示$\Delta v$和$\Delta t$的方式：
![[velocity_vectors_in_centripetal_movement.png]]
如图所示，两个速度向量之间的变化值近似于三角形的第三边，则$|\vec{v_1}|=|\vec{v_2}|=v$，故继续结合圆弧计算公式：
$$|\Delta \vec{v}|=2v\sin(\frac{\Delta\theta}{2})$$
将$\Delta\theta$视作瞬间的极小变化量（此时$\lim{\Delta t\to 0}$），那么
$$|\Delta \vec{v}|=v\cdot\Delta\theta$$

结合两式的形式，可以在$\lim{\Delta t\to 0}$时得出等式：
$$\frac{\Delta v}{v}=\frac{\Delta l}{r}$$
那么就得出$\Delta v$的表达式
$$\Delta v=\Delta l\cdot\frac{v}{r}$$
带入进$a_R=\frac{\Delta v}{\Delta t}$：
$$a_R=\frac{\Delta l}{\Delta t}\cdot\frac{v}{r}$$
由于根据线速度 (linear velocity) $v$的定义式
$$v=\frac{\Delta l}{\Delta t}$$
则最终得到向心加速度$a_R$ 的定义式
$$a_R=\frac{v^2}{r}=\omega^2r$$

考虑到牛顿第二定律$\sum F=m\cdot a$，故得出Centripetal Force（向心力）的定义式：
$$F_R=m\frac{v^2}{r}=m\omega^2r$$
（如果严格从一开始给出的定义出发，也可以这样推导[[Radial Acceleration Proof 2]]）

## 3. Nonuniform Circular Motion
只有当centripetal force直接面向运动中心时，才会有uniform circular motion，反之则是nonuniform circular motion，其centripetal force一般形式如下：
![[nonuniform_circular_motion.png]]
如图所示，它相较于uniform circular motion的最大区别是多出了$\vec{F}_{\tan}$，而指向运动中心的$\vec{F}_{R}$和它所带来的$\vec{a}_R$则仍旧存在：
![[acceleration_in_nonuniform_circular_motion.png]]
与**2**相同：
$$a_R=\frac{v^2}{r}=\omega^2r$$
$$F_R=m\frac{v^2}{r}=m\omega^2r$$
另一方面
$$a_{\tan}=\frac{\Delta v}{\Delta t}$$
于是自然
$$F_{\tan}=m\cdot a_{\tan}=m\frac{\Delta v}{\Delta t}$$
总加速度为：
$$a=\sqrt{a_{\tan}^2+a_R^2}$$
其中$a_{\tan}$和$a_R$**相互垂直**

## 4. Law of Universal Gravity
直接见纸质笔记

## 5. Weightlessness
继续见纸质笔记

## 6. Kepler's Laws
