---
tags:
  - Physics
  - 定义性
  - 证明
title: Magnetic Forces
created: 2026-06-10
modified: 2026-06-10
---

# Magnetic Forces

> [!abstract] 磁力
> 磁场对运动电荷和载流导体施加力的作用。洛伦兹力统一描述了电场力和磁场力，是电动力学的基本方程之一。

## 洛伦兹力 (Lorentz Force)

> [!important] 洛伦兹力公式
> 电荷 $q$ 以速度 $\vec{v}$ 在电磁场中运动时受到的合力：
> $$\vec{F} = q(\vec{E} + \vec{v} \times \vec{B})$$
> 
> - 电场力 $\vec{F}_E = q\vec{E}$：与电荷速度无关
> - 磁场力 $\vec{F}_B = q\vec{v} \times \vec{B}$：垂直于速度和磁场方向

### 磁场力的性质

> [!note] 关键特点
> - **方向**：始终垂直于 $\vec{v}$ 和 $\vec{B}$ 所确定的平面（右手定则）
> - **大小**：$F = qvB\sin\theta$，其中 $\theta$ 是 $\vec{v}$ 与 $\vec{B}$ 的夹角
> - **做功**：磁场力**不做功**（因为 $\vec{F}_B \perp \vec{v}$）
> - 磁场只改变速度方向，不改变速度大小

## 载流导线的受力

### 安培力 (Ampere Force)

磁场对载流导线段的作用力：

$$d\vec{F} = I d\vec{l} \times \vec{B}$$
$$\vec{F} = I \int (d\vec{l} \times \vec{B})$$

对于均匀磁场中的直导线：
$$F = I L B \sin\theta$$

### 平行导线间的力

> [!note] 安培定义的基础
> 两条无限长平行直导线（相距 $d$，电流 $I_1$、$I_2$）间的相互作用力：
> $$\frac{F}{L} = \frac{\mu_0 I_1 I_2}{2\pi d}$$
> 
> - 同向电流**相吸**
> - 反向电流**相斥**

## 载流线圈的磁矩与力矩

### 磁偶极矩 (Magnetic Dipole Moment)

$$\vec{\mu} = I \vec{A}$$

其中 $\vec{A}$ 是线圈面积矢量，方向由右手定则确定。

### 磁场中的力矩

$$\vec{\tau} = \vec{\mu} \times \vec{B}$$

$$\tau = \mu B \sin\theta$$

其中 $\theta$ 是 $\vec{\mu}$ 与 $\vec{B}$ 的夹角。

### 磁偶极子在磁场中的势能

$$U = -\vec{\mu} \cdot \vec{B} = -\mu B\cos\theta$$

## 带电粒子在磁场中的运动

### 均匀磁场中的圆周运动

当 $\vec{v} \perp \vec{B}$ 时，粒子做匀速圆周运动：

$$r = \frac{mv}{qB} \quad \text{（回旋半径）}$$
$$\omega = \frac{qB}{m} \quad \text{（回旋角频率 / 回旋频率）}$$
$$f = \frac{\omega}{2\pi} = \frac{qB}{2\pi m}$$

### 螺旋运动

当 $\vec{v}$ 与 $\vec{B}$ 有夹角 $\theta$ 时：

- **垂直分量** $v_\perp = v\sin\theta$：产生圆周运动
- **平行分量** $v_\parallel = v\cos\theta$：产生沿磁力线的匀速直线运动
- 合成轨迹为**螺旋线**

$$p = v_\parallel T = v_\parallel \frac{2\pi m}{qB} \quad \text{（螺距）}$$

### 磁镜效应 (Magnetic Mirror)

在非均匀磁场中，带电粒子的磁矩 $\mu$ 近似守恒。当粒子进入强磁场区，$v_\perp$ 增大，根据能量守恒 $v_\parallel$ 减小，最终可能被反射回来。

```mermaid
graph TD
    subgraph "磁镜"
        A["弱磁场区"] --> B["强磁场区"]
        B --> C["反射点"]
        C --> D["反向运动"]
    end
```

## 霍尔效应 (Hall Effect)

> [!note] 霍尔效应
> 在通有电流 $I$ 的导体上加垂直于电流方向的磁场 $B$，会在垂直于 $I$ 和 $B$ 的方向上产生电势差：
> $$V_H = \frac{IB}{nqt}$$
> 
> 其中 $t$ 是导体厚度，$n$ 是载流子数密度，$q$ 是载流子电荷。

**用途**：
- 判断载流子类型（正或负）
- 测量磁场强度（霍尔探头）
- 测量载流子浓度

## 电场力与磁场力对比

| 性质 | 电场力 $\vec{F} = q\vec{E}$ | 磁场力 $\vec{F} = q\vec{v} \times \vec{B}$ |
|-----|----------------------------|------------------------------------------|
| 依赖速度 | 否 | 是 |
| 做功 | 做功，改变动能 | 不做功，只改变方向 |
| 方向 | 沿电场方向 | 垂直于 $\vec{v}$ 和 $\vec{B}$ |
| 作用对象 | 静止或运动电荷 | 仅运动电荷 |
| 力的方向与场方向 | 平行或反平行 | 垂直 |

## 相关链接

- [[Electromagnetism/Magnetic Fields|Magnetic Fields]]
- [[Electromagnetism/Electromagnetic Induction|Electromagnetic Induction]]
- [[Electromagnetism/Maxwell's Equations|Maxwell's Equations]]
- [[Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 洛伦兹力中磁场部分**不对带电粒子做功**，这是区分电场力和磁场力的关键
2. 回旋频率 $\omega = qB/m$ 与粒子速度**无关**——这是回旋加速器的基本原理
3. 霍尔电压的符号可以判断载流子类型（电子 vs 空穴）
4. 安培力实质上是洛伦兹力在宏观导体上的集体表现
