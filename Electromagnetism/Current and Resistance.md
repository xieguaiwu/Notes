---
tags:
  - Physics
  - 定义性
  - 基本原理
title: Current and Resistance
created: 2026-06-10
modified: 2026-06-10
---

# Current and Resistance

> [!abstract] 电流与电阻
> 电流是电荷的定向运动，电阻是导体对电流的阻碍作用。欧姆定律是电路分析的基础，描述了电压、电流和电阻之间的线性关系。

## 电流 (Electric Current)

> [!note] 定义
> 电流是单位时间内通过导体横截面的电荷量：
> $$I = \frac{dQ}{dt}$$
> 
> - 单位：$\text{A}$ (Ampere, 安培) $= \text{C/s}$
> - 方向：正电荷流动的方向（实际电子流动方向相反）
> - 电流是标量，但习惯上标注方向

### 电流密度 (Current Density)

$$\vec{J} = \frac{I}{A} \hat{n}$$

对于微观描述：

$$\vec{J} = n q \vec{v}_d$$

其中：
- $n$：载流子数密度
- $q$：载流子电荷量
- $\vec{v}_d$：漂移速度 (drift velocity)

> [!tip] 漂移速度
> 金属中电子的漂移速度约为 $10^{-4}\,\text{m/s}$ 量级，远慢于电子热运动速度（约 $10^6\,\text{m/s}$）。

## 电阻与欧姆定律

### 电阻 (Resistance)

> [!note] 定义
> 电阻是导体两端电压与通过电流的比值：
> $$R = \frac{V}{I}$$
> 
> - 单位：$\Omega$ (Ohm, 欧姆) $= \text{V/A}$

### 欧姆定律 (Ohm's Law)

$$V = IR$$

> [!important] 欧姆定律的微观形式
> 对于欧姆材料，电流密度与电场强度成正比：
> $$\vec{J} = \sigma \vec{E}$$
> 
> 其中 $\sigma$ 是**电导率** (conductivity)，$\rho = 1/\sigma$ 是**电阻率** (resistivity)。

### 电阻与几何的关系

$$R = \rho \frac{L}{A}$$

其中 $L$ 是导体长度，$A$ 是横截面积。

## 电阻率的温度依赖性

> [!note] 公式
> $$\rho(T) = \rho_0 [1 + \alpha(T - T_0)]$$
> 
> 对应地：
> $$R(T) = R_0 [1 + \alpha(T - T_0)]$$
> 
> 其中 $\alpha$ 是**电阻温度系数**。

| 材料 | $\rho$ ($\Omega\cdot\text{m}$) | $\alpha$ ($\text{K}^{-1}$) |
|-----|------------------------------|---------------------------|
| 银 | $1.59 \times 10^{-8}$ | $0.0038$ |
| 铜 | $1.68 \times 10^{-8}$ | $0.0039$ |
| 铝 | $2.65 \times 10^{-8}$ | $0.0039$ |
| 铁 | $9.71 \times 10^{-8}$ | $0.0050$ |
| 金 | $2.44 \times 10^{-8}$ | $0.0034$ |
| 碳 (石墨) | $3.5 \times 10^{-5}$ | $-0.0005$ |

> [!warning] 超导体
> 某些材料在低温下电阻突降为零（超导现象），此时 $\rho = 0$。临界温度 $T_c$ 以上则恢复为正常导体。

## 电功率与焦耳热

> [!important] 功率公式
> 电流通过导体时的功率损耗（焦耳热）：
> $$P = IV = I^2 R = \frac{V^2}{R}$$
> 
> - 单位：$\text{W}$ (Watt, 瓦特)
> - 焦耳定律：单位时间内产生的热量 $P = I^2 R$

**微观解释**：电子在电场中加速获得动能，与晶格碰撞时将能量传递给晶格，表现为热能。

## 导电机制

### 金属导电

自由电子模型——金属中的自由电子在外加电场作用下定向漂移：

$$\vec{v}_d = -\frac{e\vec{E}\tau}{m}$$

其中 $\tau$ 是弛豫时间（平均自由程 / 费米速度）。

### 电导率与弛豫时间

$$\sigma = \frac{ne^2\tau}{m}$$

## 基尔霍夫电流定律 (KCL)

> [!note] KCL
> 节点处电流的代数和为零：
> $$\sum I_{\text{in}} = \sum I_{\text{out}}$$

这是电荷守恒定律的直接推论。详见 [[Electromagnetism/DC Circuits|DC Circuits]]。

## 相关链接

- [[Electromagnetism/DC Circuits|DC Circuits]]
- [[Electromagnetism/Capacitance|Capacitance]]
- [[Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 欧姆定律并非普遍规律——**半导体**、**PN 结**、**气体电离**等不遵循欧姆定律
2. 电流方向定义为正电荷运动方向，与电子实际运动方向相反
3. 电阻是导体的本征属性，不依赖电压或电流（欧姆材料）
4. 电流密度 $\vec{J}$ 是矢量，而电流 $I$ 是标量
