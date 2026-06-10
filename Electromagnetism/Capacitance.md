---
tags:
  - Physics
  - 定义性
  - 方法性
title: Capacitance
created: 2026-06-10
modified: 2026-06-10
---

# Capacitance

> [!abstract] 电容
> 电容是导体储存电荷和电能能力的量度。电容器是电子电路中最基本的无源元件之一，广泛应用于滤波、耦合、储能等场合。

## 电容的定义

> [!note] 定义
> 电容 $C$ 定义为导体所带电荷量 $Q$ 与其电势 $V$ 的比值：
> $$C = \frac{Q}{V}$$
> 
> - 单位：$\text{F}$ (Farad, 法拉)
> - $1\,\text{F} = 1\,\text{C/V}$
> - 常用单位：$\mu\text{F}$、$\text{nF}$、$\text{pF}$
> - 电容只取决于导体的几何形状和介电性质，与电荷量无关

## 典型电容器

### 1. 平行板电容器

$$C = \varepsilon_0 \frac{A}{d}$$

- $A$：极板面积
- $d$：极板间距
- 电场（忽略边缘效应）：$E = \dfrac{\sigma}{\varepsilon_0} = \dfrac{Q}{\varepsilon_0 A}$
- 电势差：$V = Ed = \dfrac{Qd}{\varepsilon_0 A}$

### 2. 球形电容器

由两个同心球壳构成（内半径 $a$，外半径 $b$）：

$$C = 4\pi\varepsilon_0 \frac{ab}{b - a}$$

当 $b \to \infty$（孤立导体球）：
$$C = 4\pi\varepsilon_0 a$$

### 3. 圆柱形电容器

由两个同轴圆柱面构成（内半径 $a$，外半径 $b$，长度 $L$）：

$$C = 2\pi\varepsilon_0 \frac{L}{\ln(b/a)}$$

## 电容器的串并联

### 串联 (Series)

$$\frac{1}{C_{\text{eq}}} = \frac{1}{C_1} + \frac{1}{C_2} + \cdots + \frac{1}{C_n}$$

- 各电容器带电量相同
- 总电压为各电容器电压之和
- 等效电容**小于**任意单个电容

### 并联 (Parallel)

$$C_{\text{eq}} = C_1 + C_2 + \cdots + C_n$$

- 各电容器两端电压相同
- 总电荷量为各电容器电荷量之和
- 等效电容**大于**任意单个电容

## 电容器储能

> [!important] 储能公式
> 电容器中储存的电能（静电能）：
> $$U = \frac{1}{2}QV = \frac{1}{2}CV^2 = \frac{1}{2}\frac{Q^2}{C}$$

**推导**：将电荷 $dq$ 从负极板移到正极板所需的功：
$$dU = Vdq = \frac{q}{C}dq \implies U = \int_0^Q \frac{q}{C}dq = \frac{1}{2}\frac{Q^2}{C}$$

### 电场能量密度

从平行板电容器：
$$U = \frac{1}{2}CV^2 = \frac{1}{2}\left(\varepsilon_0\frac{A}{d}\right)(Ed)^2 = \frac{1}{2}\varepsilon_0 E^2 (Ad)$$

能量密度（单位体积内的电场能量）：
$$u_E = \frac{1}{2}\varepsilon_0 E^2$$

> [!tip] 普适性
> $u_E = \frac{1}{2}\varepsilon_0 E^2$ 不仅适用于平行板电容器，而是静电场的**普适结论**。

## 介电质 (Dielectrics)

插入介电质后，电容增大：
$$C = \kappa C_0$$

其中 $\kappa$ 是**相对介电常数**（dielectric constant），$C_0$ 是真空电容。

### 介电质的物理机制

> [!note] 极化 (Polarization)
> 介电质在电场中发生极化，产生极化电荷（束缚电荷），削弱了极板间的有效电场：
> $$E = \frac{E_0}{\kappa}$$
> 
> 因此在相同电荷量下，电势差降低，电容增大。

### 常见介电常数

| 材料 | $\kappa$ |
|-----|---------|
| 真空 | 1 |
| 空气 | 1.0006 |
| 纸 | 3.5 |
| 玻璃 | 4–7 |
| 陶瓷 | 6–12 |
| 水 (20°C) | 80 |
| 钛酸钡 | 1200–10000 |

## 相关链接

- [[Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Electromagnetism/Electric Potential|Electric Potential]]
- [[Electromagnetism/DC Circuits|DC Circuits]]
- [[Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 电容器的**耐压值**（额定电压）由介电质的击穿场强决定
2. 串联电容器的等效电容总是小于最小电容值
3. 介电质不仅增大了电容，还提高了耐压能力
4. 电场能量**储存在电场中**而非储存在极板上——这由能量密度的普适性公式所体现
