---
tags:
  - Physics
  - 定理性
  - 基本原理
title: Maxwell's Equations
created: 2026-06-10
modified: 2026-06-10
---

# Maxwell's Equations

> [!abstract] 麦克斯韦方程组
> 麦克斯韦方程组是经典电磁理论的基石，统一了电场和磁场，预言了电磁波的存在，揭示了光的电磁本质。它被公认为物理学中最优雅的理论体系之一。

## 麦克斯韦方程组

### 积分形式

| # | 方程 | 名称 | 物理含义 |
|--|-----|-----|---------|
| 1 | $\oint \vec{E} \cdot d\vec{A} = \dfrac{Q_{\text{enc}}}{\varepsilon_0}$ | **高斯定律** | 电荷是电场的源 |
| 2 | $\oint \vec{B} \cdot d\vec{A} = 0$ | **高斯磁定律** | 无磁单极子 |
| 3 | $\oint \vec{E} \cdot d\vec{l} = -\dfrac{d\Phi_B}{dt}$ | **法拉第定律** | 变化磁场产生电场 |
| 4 | $\oint \vec{B} \cdot d\vec{l} = \mu_0 I + \mu_0\varepsilon_0\dfrac{d\Phi_E}{dt}$ | **安培-麦克斯韦定律** | 电流和变化电场产生磁场 |

### 微分形式

| # | 方程 | 名称 |
|--|-----|-----|
| 1 | $\nabla \cdot \vec{E} = \dfrac{\rho}{\varepsilon_0}$ | 高斯定律 |
| 2 | $\nabla \cdot \vec{B} = 0$ | 高斯磁定律 |
| 3 | $\nabla \times \vec{E} = -\dfrac{\partial \vec{B}}{\partial t}$ | 法拉第定律 |
| 4 | $\nabla \times \vec{B} = \mu_0 \vec{J} + \mu_0\varepsilon_0 \dfrac{\partial \vec{E}}{\partial t}$ | 安培-麦克斯韦定律 |

## 位移电流 (Displacement Current)

> [!important] 麦克斯韦的核心贡献
> 麦克斯韦在安培定律中加入了位移电流项 $\varepsilon_0 \dfrac{\partial \vec{E}}{\partial t}$，使方程组自洽。
> 
> **位移电流密度**：
> $$\vec{J}_d = \varepsilon_0 \frac{\partial \vec{E}}{\partial t}$$
> 
> 总的"电流"包括传导电流和位移电流。位移电流虽然不涉及电荷的实际运动，但在产生磁场方面与传导电流等价。

### 引入位移电流的背景

静磁学中的安培定律 $\nabla \times \vec{B} = \mu_0 \vec{J}$ 取散度得到：
$$\nabla \cdot (\nabla \times \vec{B}) = 0 = \mu_0 \nabla \cdot \vec{J}$$

但由连续性方程 $\nabla \cdot \vec{J} = -\partial\rho/\partial t$，对于**非稳态**情况：
$$\nabla \cdot \vec{J} \neq 0$$

矛盾！麦克斯韦引入位移电流项解决了这一矛盾。

## 连续性方程 (Continuity Equation)

从麦克斯韦方程组可推导出电荷守恒：

$$\nabla \cdot \vec{J} = -\frac{\partial \rho}{\partial t}$$

积分形式：
$$\oint \vec{J} \cdot d\vec{A} = -\frac{d}{dt}\int_V \rho \, dV$$

即：从闭合曲面流出的电流等于内部电荷量减少的速率。

## 电磁波预言

### 真空中的麦克斯韦方程组

在真空中（$\rho = 0, \vec{J} = 0$）：

$$\nabla \cdot \vec{E} = 0,\quad \nabla \cdot \vec{B} = 0$$
$$\nabla \times \vec{E} = -\frac{\partial \vec{B}}{\partial t},\quad \nabla \times \vec{B} = \mu_0\varepsilon_0\frac{\partial \vec{E}}{\partial t}$$

### 波动方程

对法拉第定律取旋度，利用恒等式 $\nabla \times (\nabla \times \vec{E}) = \nabla(\nabla \cdot \vec{E}) - \nabla^2\vec{E}$：

> [!note] 波动方程
> $$\nabla^2 \vec{E} = \mu_0\varepsilon_0 \frac{\partial^2 \vec{E}}{\partial t^2}$$
> $$\nabla^2 \vec{B} = \mu_0\varepsilon_0 \frac{\partial^2 \vec{B}}{\partial t^2}$$
> 
> 这是**波动方程**，波速为：
> $$c = \frac{1}{\sqrt{\mu_0\varepsilon_0}} \approx 3 \times 10^8 \,\text{m/s}$$

这正好是真空中的光速！这一结果让麦克斯韦断定**光就是电磁波**。

## 电磁场的对偶性

麦克斯韦方程组展示了电场和磁场的对称性（在真空中无源的情形下）：

| 电场 | 磁场 |
|-----|-----|
| $\nabla \cdot \vec{E} = 0$ | $\nabla \cdot \vec{B} = 0$ |
| $\nabla \times \vec{E} = -\partial\vec{B}/\partial t$ | $\nabla \times \vec{B} = \mu_0\varepsilon_0\,\partial\vec{E}/\partial t$ |

两者形式高度对称，唯一的区别是法拉第定律和安培-麦克斯韦定律中的负号和系数 $\mu_0\varepsilon_0$。

## 相关链接

- [[Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Electromagnetism/Electromagnetic Induction|Electromagnetic Induction]]
- [[Electromagnetism/Magnetic Fields|Magnetic Fields]]
- [[Electromagnetism/Electromagnetic Waves|Electromagnetic Waves]]
- [[Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 麦克斯韦方程组的积分形式适用于**宏观**电磁问题，微分形式适用于**局域**分析
2. 位移电流**不是真正的电流**，但它产生磁场的效果与传导电流相同
3. 麦克斯韦方程组在相对论下可以统一为**张量形式**（电磁场张量 $F_{\mu\nu}$）
4. 方程组在**真空中**和**介质中**的形式不同（需引入 $\vec{D}$ 和 $\vec{H}$ 场）
