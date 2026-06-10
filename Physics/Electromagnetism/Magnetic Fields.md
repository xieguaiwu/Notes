---
tags:
  - Physics
  - 定义性
  - 基本原理
title: Magnetic Fields
created: 2026-06-10
modified: 2026-06-10
---

# Magnetic Fields

> [!abstract] 磁场
> 磁场是运动电荷（电流）周围产生的物理场，对置于其中的其他运动电荷和磁矩施加力的作用。磁场是电磁场的另一基本组成部分。

## 磁感应强度 (Magnetic Flux Density)

> [!note] 定义
> 磁感应强度 $\vec{B}$ 是描述磁场强弱和方向的矢量场。
> - 单位：$\text{T}$ (Tesla, 特斯拉) 或 $\text{G}$ (Gauss, 高斯)
> - $1\,\text{T} = 10^4\,\text{G}$
> - 地球表面磁场约 $0.5\,\text{G} = 5 \times 10^{-5}\,\text{T}$

## 毕奥-萨伐尔定律 (Biot-Savart Law)

> [!important] 毕奥-萨伐尔定律
> 电流元 $I d\vec{l}$ 在空间某点产生的磁场：
> $$d\vec{B} = \frac{\mu_0}{4\pi} \frac{I d\vec{l} \times \hat{r}}{r^2}$$
> 
> 总磁场通过对整个电流回路积分得到：
> $$\vec{B} = \frac{\mu_0}{4\pi} \int \frac{I d\vec{l} \times \hat{r}}{r^2}$$
> 
> 其中 $\mu_0 = 4\pi \times 10^{-7}\,\text{T·m/A}$ 是真空磁导率。

### 典型电流分布的磁场

**无限长直导线**：
$$B = \frac{\mu_0 I}{2\pi r}$$

**圆环轴线（半径为 $R$，距中心 $x$）**：
$$B = \frac{\mu_0 I R^2}{2(x^2 + R^2)^{3/2}}$$

在圆心处（$x = 0$）：
$$B = \frac{\mu_0 I}{2R}$$

**长直螺线管内部**（单位长度匝数 $n$）：
$$B = \mu_0 n I$$

## 安培环路定律 (Ampere's Law)

> [!important] 安培环路定律
> $$\oint \vec{B} \cdot d\vec{l} = \mu_0 I_{\text{enc}}$$
> 
> 磁场沿任意闭合回路的线积分等于穿过该回路所围曲面的传导电流的 $\mu_0$ 倍。

### 微分形式

$$\nabla \times \vec{B} = \mu_0 \vec{J}$$

（在静磁情形下成立；变化电磁场下需加入位移电流修正）

### 安培定律的应用

| 对称性 | 安培环路 | 结果 |
|-------|---------|------|
| 无限长直导线 | 同心圆 | $B = \dfrac{\mu_0 I}{2\pi r}$ |
| 无限长圆柱导体 | 同心圆 | $B_{\text{内}} = \dfrac{\mu_0 I r}{2\pi R^2}$ |
| 螺线管 | 矩形环路 | $B = \mu_0 n I$ |
| 螺绕环 | 同心圆 | $B = \dfrac{\mu_0 N I}{2\pi r}$ |

## 磁通量 (Magnetic Flux)

> [!note] 定义
> $$\Phi_B = \int_S \vec{B} \cdot d\vec{A}$$
> 
> - 单位：$\text{Wb}$ (Weber, 韦伯)
> - $1\,\text{Wb} = 1\,\text{T·m}^2$

## 磁场的高斯定律

> [!note] 高斯磁定律
> $$\oint \vec{B} \cdot d\vec{A} = 0$$
> 
> 微分形式：
> $$\nabla \cdot \vec{B} = 0$$

> [!tip] 物理含义
> 与电场不同，磁场的散度处处为零——不存在**磁单极子**（磁荷）。磁力线永远是**闭合曲线**。

### 电场与磁场的对比

| 性质 | 电场 $\vec{E}$ | 磁场 $\vec{B}$ |
|-----|---------------|---------------|
| 源 | 电荷 | 运动电荷（电流） |
| 散度 | $\nabla \cdot \vec{E} = \rho/\varepsilon_0$ | $\nabla \cdot \vec{B} = 0$ |
| 旋度 | $\nabla \times \vec{E} = -\partial\vec{B}/\partial t$ | $\nabla \times \vec{B} = \mu_0\vec{J} + \mu_0\varepsilon_0\partial\vec{E}/\partial t$ |
| 力线 | 始于正电荷，终于负电荷 | 闭合曲线 |
| 单极子 | 存在（正负电荷） | 未发现 |

## 相关链接

- [[Physics/Electromagnetism/Magnetic Forces|Magnetic Forces]]
- [[Physics/Electromagnetism/Electromagnetic Induction|Electromagnetic Induction]]
- [[Physics/Electromagnetism/Maxwell's Equations|Maxwell's Equations]]
- [[Physics/Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 磁场是**无源有旋场**（$\nabla \cdot \vec{B} = 0$，$\nabla \times \vec{B} \neq 0$）
2. 毕奥-萨伐尔定律与库仑定律在形式上有对称性，但磁场由运动电荷产生
3. 安培环路定律的高斯面选取规则同高斯定律——需要足够对称性才能简化计算
4. $\mu_0$ 和 $\varepsilon_0$ 通过 $c = 1/\sqrt{\mu_0\varepsilon_0}$ 联系
