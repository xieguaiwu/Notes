---
tags:
  - Physics
  - 定义性
  - 证明
title: Electric Fields
created: 2026-06-10
modified: 2026-06-10
---

# Electric Fields

> [!abstract] 电场
> 电场是电荷周围存在的物理场，对置于其中的其他电荷施加力的作用。电场是电磁场的重要组成部分，是理解电磁学的核心概念。

## 电场强度 (Electric Field Intensity)

> [!note] 定义
> 电场强度定义为置于该点的**检验电荷** $q_0$ 所受电场力与其电荷量的比值：
> $$\vec{E} = \lim_{q_0 \to 0} \frac{\vec{F}}{q_0}$$
> 
> - 单位：$\text{N/C}$ 或 $\text{V/m}$
> - 方向：正电荷所受力的方向

### 点电荷的电场

$$\vec{E}(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \frac{q}{r^2} \hat{r}$$

### 电场叠加

$$\vec{E}(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \sum_{i=1}^n \frac{q_i}{|\vec{r} - \vec{r}_i|^2} \hat{\mathcal{R}}_i$$

## 电场线与电通量

### 电场线 (Electric Field Lines)

> [!tip] 电场线性质
> - 电场线从正电荷出发，终止于负电荷
> - 电场线的切线方向表示电场方向
> - 电场线的**密度**表示电场强度的大小
> - 电场线不会相交
> - 静电平衡时，电场线垂直于导体表面

```mermaid
graph TD
    subgraph "电场线示例"
        direction LR
        A[正电荷 +] --> B[负电荷 -]
    end
```

### 电通量 (Electric Flux)

> [!note] 定义
> 电通量是电场通过某一曲面的"流量"度量：
> $$\Phi_E = \int_S \vec{E} \cdot d\vec{A} = \int_S E\cos\theta \, dA$$
> 
> 其中 $d\vec{A}$ 的方向为曲面的法线方向。

## 特殊电场分布

### 1. 电偶极子的电场

在远离偶极子的区域（$r \gg d$），用球坐标表示：

$$E_r = \frac{1}{4\pi\varepsilon_0} \frac{2p\cos\theta}{r^3}$$
$$E_\theta = \frac{1}{4\pi\varepsilon_0} \frac{p\sin\theta}{r^3}$$

### 2. 均匀带电细杆

长度为 $L$、线密度为 $\lambda$ 的细杆，在垂直平分线上距杆 $x$ 处的电场：

$$E = \frac{1}{4\pi\varepsilon_0} \frac{\lambda L}{x\sqrt{x^2 + (L/2)^2}}$$

当 $L \to \infty$（无限长直导线）：
$$E = \frac{\lambda}{2\pi\varepsilon_0 x}$$

方向垂直于导线。

### 3. 均匀带电圆盘轴线

半径为 $R$、面密度 $\sigma$ 的圆盘轴线上的电场：

$$E = \frac{\sigma}{2\varepsilon_0}\left(1 - \frac{x}{\sqrt{x^2 + R^2}}\right)$$

> [!tip] 极限情况
> - $x \to 0$（靠近圆盘）：$E \to \sigma/(2\varepsilon_0)$，等价于无限大平面
> - $x \gg R$（远离圆盘）：$E \to \frac{1}{4\pi\varepsilon_0}\frac{Q}{x^2}$，等价于点电荷

## 相关链接

- [[Electromagnetism/Electrostatics|Electrostatics]]
- [[Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Electromagnetism/Electric Potential|Electric Potential]]
- [[Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 电场是**矢量场**，叠加时必须遵循矢量加法
2. 检验电荷必须足够小，以避免影响原电场分布
3. 电场**线不能相交**，否则会在交点处有多个切线方向
4. 静电平衡下，导体内部电场处处为零
