---
tags:
  - Physics
  - 定义性
  - 基本原理
title: Electrostatics
created: 2026-06-10
modified: 2026-06-10
---

# Electrostatics

> [!abstract] 静电学
> 静电学研究静止电荷之间的相互作用力与能量。其核心是库仑定律和叠加原理，整个静电学体系由此演绎而来。

## 基本概念

### 1. 电荷 (Electric Charge)

电荷是物质的基本属性之一，分为正电荷和负电荷。

> [!note] 电荷的性质
> - **同号相斥，异号相吸**
> - **电荷守恒定律**：孤立系统的总电荷量保持不变
> - **电荷量子化**：电荷量是分立的，$q = n e$，其中 $e = 1.602 \times 10^{-19}\,\text{C}$ 是元电荷
> - 单位：库仑 (Coulomb, C)

### 2. 库仑定律 (Coulomb's Law)

> [!important] 库仑定律
> 真空中两个静止点电荷之间的作用力，大小与电荷量的乘积成正比，与距离的平方成反比，方向沿连线方向：
> 
> $$\vec{F}_{12} = k \frac{q_1 q_2}{r_{12}^2} \hat{r}_{12} = \frac{1}{4\pi\varepsilon_0} \frac{q_1 q_2}{r_{12}^2} \hat{r}_{12}$$
> 
> 其中：
> - $k = 8.988 \times 10^9 \,\text{N·m}^2/\text{C}^2$ — 库仑常数
> - $\varepsilon_0 = 8.854 \times 10^{-12} \,\text{C}^2/(\text{N·m}^2)$ — 真空介电常数
> - $\hat{r}_{12}$ — 从 $q_1$ 指向 $q_2$ 的单位矢量

### 3. 叠加原理 (Superposition Principle)

> [!note] 叠加原理
> 多个点电荷对某一点电荷的总静电力等于每个点电荷单独作用时静电力的**矢量和**：
> 
> $$\vec{F} = \sum_{i=1}^n \vec{F}_i = \frac{q_0}{4\pi\varepsilon_0} \sum_{i=1}^n \frac{q_i}{r_{i}^2} \hat{r}_i$$

## 连续电荷分布

实际带电体可视为无限多个电荷元 $dq$ 的集合。

| 分布类型 | 电荷密度 | 电荷元 |
|---------|---------|-------|
| 体分布 | $\rho(\vec{r}')$ | $dq = \rho\,dV'$ |
| 面分布 | $\sigma(\vec{r}')$ | $dq = \sigma\,dA'$ |
| 线分布 | $\lambda(\vec{r}')$ | $dq = \lambda\,dl'$ |

### 连续分布的电场

$$\vec{E}(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \int \frac{dq}{|\vec{r} - \vec{r}'|^2} \hat{\mathcal{R}}$$

其中 $\hat{\mathcal{R}} = \frac{\vec{r} - \vec{r}'}{|\vec{r} - \vec{r}'|}$ 是从源点到场点的单位方向矢量。

## 典型电荷分布

### 1. 电偶极子 (Electric Dipole)

两个等量异号电荷 $\pm q$ 相距 $d$ 构成电偶极子。

**电偶极矩（Dipole Moment）**：
$$\vec{p} = q \vec{d} \quad (\text{方向从负电荷指向正电荷})$$

**轴线上的电场**（远离偶极子，$r \gg d$）：
$$E = \frac{1}{2\pi\varepsilon_0} \frac{p}{r^3}$$

### 2. 均匀带电圆环轴线上

$$E = \frac{1}{4\pi\varepsilon_0} \frac{Qx}{(x^2 + R^2)^{3/2}}$$

其中 $Q$ 为总电荷，$R$ 为圆环半径，$x$ 为轴线上距圆环中心的距离。

### 3. 无限大均匀带电平面

$$E = \frac{\sigma}{2\varepsilon_0}$$

方向垂直于平面。这说明无限大均匀带电平面产生的电场与距离无关。

## 关键公式总结

| 公式 | 说明 |
|-----|------|
| $\vec{F} = \frac{1}{4\pi\varepsilon_0} \frac{q_1 q_2}{r^2} \hat{r}$ | 库仑定律 |
| $\vec{E} = \frac{1}{4\pi\varepsilon_0} \frac{q}{r^2} \hat{r}$ | 点电荷电场 |
| $\vec{F} = q\vec{E}$ | 电场力 |
| $\tau = \vec{p} \times \vec{E}$ | 电偶极子在电场中的力矩 |
| $U = -\vec{p} \cdot \vec{E}$ | 电偶极子在电场中的势能 |

## 相关链接

- [[Physics/Electromagnetism/Electric Fields|Electric Fields]]
- [[Physics/Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Physics/Electromagnetism/Electric Potential|Electric Potential]]
- [[Physics/Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]
- [[Math/Linear_Algebra/Vector and Matrix|向量分析]]

## 注意事项

1. 库仑定律只适用于**点电荷**和**静止**条件
2. 叠加原理是电磁学的基本原理之一，适用于电场和磁场
3. 电偶极子的场强 $E \propto 1/r^3$ 比点电荷的 $E \propto 1/r^2$ 衰减更快
