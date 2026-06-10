---
tags:
  - Physics
  - 定义性
  - 基本原理
title: Electric Potential
created: 2026-06-10
modified: 2026-06-10
---

# Electric Potential

> [!abstract] 电势
> 电势是描述电场中能量性质的标量场。电势差是电场力移动电荷做功的量度，也是电路分析的基础。

## 电势能与电势

### 1. 电势能 (Electric Potential Energy)

电荷 $q$ 在静电场 $\vec{E}$ 中从 $a$ 点移动到 $b$ 点时，电场力做的功：

$$W_{a \to b} = \int_a^b \vec{F} \cdot d\vec{l} = q \int_a^b \vec{E} \cdot d\vec{l}$$

与该路径对应的电势能变化：

$$\Delta U = U_b - U_a = -W_{a \to b} = -q \int_a^b \vec{E} \cdot d\vec{l}$$

### 2. 电势 (Electric Potential)

> [!note] 定义
> 电势是单位正电荷在电场中某点的电势能：
> $$V(\vec{r}) = \frac{U(\vec{r})}{q}$$
> 
> - 单位：$\text{V}$ (Volt) $= \text{J/C}$
> - 电势是**标量**，无方向
> - 电势的零点具有任意性（通常取无穷远处或接地于零）

### 3. 电势差

$$V_{ab} = V_a - V_b = \int_a^b \vec{E} \cdot d\vec{l}$$

> [!important] 静电场的保守性
> 静电场中，电场力做功与路径无关，只取决于起点和终点。因此：
> $$\oint \vec{E} \cdot d\vec{l} = 0$$
> 
> 静电场的**旋度为零**：$\nabla \times \vec{E} = 0$

这意味着静电场是**保守场**（无旋场），可以定义标量势函数。

## 点电荷的电势

在真空中，距离点电荷 $q$ 为 $r$ 处的电势：

$$V(r) = \frac{1}{4\pi\varepsilon_0} \frac{q}{r}$$

（取无穷远处为零势点）

## 电势叠加原理

电势是标量，所以多个点电荷的总电势是**代数和**（而非矢量和）：

$$V(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \sum_{i=1}^n \frac{q_i}{|\vec{r} - \vec{r}_i|}$$

对于连续分布：

$$V(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \int \frac{dq}{|\vec{r} - \vec{r}'|}$$

## 电场与电势的关系

### 由电势求电场

$$\vec{E} = -\nabla V = -\left( \frac{\partial V}{\partial x}\hat{x} + \frac{\partial V}{\partial y}\hat{y} + \frac{\partial V}{\partial z}\hat{z} \right)$$

在一维情况下：

$$E_x = -\frac{dV}{dx}$$

> [!tip] 直观理解
> 电场指向电势**降低最快**的方向，且与等势面**垂直**。

### 由电场求电势

$$V(\vec{r}) = -\int_{\infty}^{\vec{r}} \vec{E} \cdot d\vec{l}$$

## 等势面 (Equipotential Surfaces)

> [!note] 等势面性质
> - 等势面上所有点电势相同
> - 电场线**处处垂直**于等势面
> - 电场线指向电势降低的方向
> - 等势面密集处电场强度大

```mermaid
graph LR
    subgraph "等势面与电场线"
        direction TB
        A["+ 等势面<br/>----<br/>" " "]
        B["↓ 电场线↓"]
        C["− 等势面<br/>----"]
    end
```

## 典型电荷分布的电势

| 分布 | 电势 |
|-----|------|
| 点电荷 | $V(r) = \dfrac{q}{4\pi\varepsilon_0 r}$ |
| 电偶极子（远场） | $V(r,\theta) = \dfrac{p\cos\theta}{4\pi\varepsilon_0 r^2}$ |
| 均匀带电圆环轴线 | $V(x) = \dfrac{Q}{4\pi\varepsilon_0\sqrt{x^2 + R^2}}$ |
| 均匀带电圆盘轴线 | $V(x) = \dfrac{\sigma}{2\varepsilon_0}\left(\sqrt{x^2 + R^2} - x\right)$ |
| 无限长线电荷 | $V(r) = -\dfrac{\lambda}{2\pi\varepsilon_0}\ln r + C$（无绝对零点） |

## 相关链接

- [[Physics/Electromagnetism/Electrostatics|Electrostatics]]
- [[Physics/Electromagnetism/Electric Fields|Electric Fields]]
- [[Physics/Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Physics/Electromagnetism/Capacitance|Capacitance]]
- [[Math/Mathematical_Analysis/differentiation|微积分 — 微分]]

## 注意事项

1. 电势是**标量**，叠加计算比电场矢量和简单得多
2. 电势差具有绝对意义，而具体某点的电势值取决于零势点的选取
3. $\nabla \times \vec{E} = 0$ 仅在**静电场**成立，变化磁场会破坏这一关系（法拉第定律）
4. 对于分布到无穷远的电荷（如无限长导线），不能取无穷远处为零势点
