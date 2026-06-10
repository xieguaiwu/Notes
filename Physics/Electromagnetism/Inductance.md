---
tags:
  - Physics
  - 定义性
  - 方法性
title: Inductance
created: 2026-06-10
modified: 2026-06-10
---

# Inductance

> [!abstract] 电感
> 电感是电路元件储存磁场能量的量度。电感器（电感线圈）与电容器共同构成 LC/ RLC 电路，产生振荡和谐振现象。

## 自感 (Self-Inductance)

> [!note] 定义
> **自感系数** $L$ 定义为线圈中的磁链 $\Phi$ 与通过电流 $I$ 的比值：
> $$L = \frac{N\Phi_B}{I}$$
> 
> - 单位：$\text{H}$ (Henry, 亨利)
> - $1\,\text{H} = 1\,\text{Wb/A} = 1\,\text{V·s/A}$
> - 自感产生的**反电动势**：$\mathcal{E}_L = -L \dfrac{dI}{dt}$

### 螺线管的自感

$$L = \mu_0 n^2 A l = \mu_0 \frac{N^2}{l} A$$

其中 $n = N/l$ 是单位长度匝数，$A$ 是截面积，$l$ 是螺线管长度。

### 自感的物理意义

$L$ 越大，线圈"阻止电流变化"的能力越强。在电路暂态过程中，电感像"电惯性"。

## 互感 (Mutual Inductance)

> [!note] 定义
> 线圈 1 的电流变化在线圈 2 中产生的互感电动势：
> $$M_{21} = \frac{N_2 \Phi_{21}}{I_1}$$
> $$\mathcal{E}_2 = -M \frac{dI_1}{dt}$$
> 
> 其中 $M_{12} = M_{21} = M$（互易性）。

### 耦合系数

$$M = k\sqrt{L_1 L_2}$$

$k$ 为耦合系数，$0 \le k \le 1$：
- $k = 1$：**完美耦合**（理想变压器）
- $k = 0$：无耦合
- $0 < k < 1$：实际情况

## RL 电路暂态

### 电流增长（接通电源）

$$I(t) = \frac{V_0}{R}\left(1 - e^{-t/\tau}\right)$$

### 电流衰减（断开电源）

$$I(t) = I_0 e^{-t/\tau}$$

### 时间常数

> [!important] 时间常数
> $$\tau = \frac{L}{R}$$
> 
> - 单位：秒 (s)
> - $t = \tau$ 时，电流达到最终值的 $63.2\%$
> - 与 RC 电路 $(\tau = RC)$ 的时间常数**对偶**

| 时间 | 增长百分比 | 衰减剩余 |
|-----|-----------|---------|
| $0$ | $0\%$ | $100\%$ |
| $\tau$ | $63.2\%$ | $36.8\%$ |
| $2\tau$ | $86.5\%$ | $13.5\%$ |
| $3\tau$ | $95.0\%$ | $5.0\%$ |
| $5\tau$ | $99.3\%$ | $0.7\%$ |

## 电感储能

> [!important] 电感中的磁能
> $$U = \frac{1}{2} L I^2$$
> 
> 推导（将电荷 $dq$ 从电源输送到电感所需能量）：
> $$U = \int_0^I P\,dt = \int_0^I L\frac{di}{dt}\cdot i\,dt = \int_0^I Li\,di = \frac{1}{2}LI^2$$

### 磁场能量密度

从螺线管 $L = \mu_0 n^2 A l$ 和 $B = \mu_0 n I$ 可得：

$$U = \frac{1}{2}LI^2 = \frac{1}{2}\mu_0 n^2 A l \cdot \left(\frac{B}{\mu_0 n}\right)^2 = \frac{B^2}{2\mu_0}(Al)$$

储能体密度：

$$u_B = \frac{B^2}{2\mu_0}$$

> [!tip] 对偶性
> 电场能量密度：$u_E = \dfrac{1}{2}\varepsilon_0 E^2$
> 
> 磁场能量密度：$u_B = \dfrac{B^2}{2\mu_0}$

## LC 振荡电路

> [!important] LC 振荡
> 理想 LC 电路（无电阻）中，电能和磁能周期性地相互转换：
> $$f = \frac{\omega}{2\pi} = \frac{1}{2\pi\sqrt{LC}}$$
> 
> 电荷和电流随时间正弦变化：
> $$q(t) = Q_0 \cos(\omega t + \phi)$$
> $$i(t) = -\omega Q_0 \sin(\omega t + \phi)$$

```mermaid
flowchart LR
    A["电容放电<br/>电场能↓"] --> B["电感储能<br/>磁场能↑"]
    B --> C["电感释放<br/>磁场能↓"]
    C --> D["电容充电<br/>电场能↑"]
    D --> A
```

### RLC 电路

加入电阻 $R$ 后，振荡逐渐衰减（阻尼振荡），阻尼因子：

$$\alpha = \frac{R}{2L}$$

- $R^2 < 4L/C$：**欠阻尼**（振荡衰减）
- $R^2 = 4L/C$：**临界阻尼**（最快回到零）
- $R^2 > 4L/C$：**过阻尼**（缓慢趋近零）

## 电感与电容对比

| 性质 | 电容 $C$ | 电感 $L$ |
|-----|---------|---------|
| 定义 | $C = Q/V$ | $L = N\Phi/I$ |
| 储能 | $U = \frac{1}{2}CV^2$ | $U = \frac{1}{2}LI^2$ |
| 时间常数 | $\tau = RC$ | $\tau = L/R$ |
| 能量密度 | $u_E = \frac{1}{2}\varepsilon_0 E^2$ | $u_B = \frac{B^2}{2\mu_0}$ |
| 电压-电流关系 | $I = C\,\dfrac{dV}{dt}$ | $V = L\,\dfrac{dI}{dt}$ |
| 稳态 DC 特性 | 开路（隔直） | 短路（通直） |
| 暂态特性 | 电压不突变 | 电流不突变 |

## 相关链接

- [[Physics/Electromagnetism/Electromagnetic Induction|Electromagnetic Induction]]
- [[Physics/Electromagnetism/Magnetic Fields|Magnetic Fields]]
- [[Physics/Electromagnetism/DC Circuits|DC Circuits]]
- [[Physics/Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

## 注意事项

1. 电感中的电流**不能突变**——这是分析 RL 电路暂态的出发点
2. 断开电感电路时会产生高电压反冲（$V = L\,dI/dt$），需要续流二极管保护
3. LC 振荡频率由 $L$ 和 $C$ 决定，与初始条件无关
4. 磁能密度 $u_B = B^2/2\mu_0$ 与电能密度 $u_E = \varepsilon_0 E^2/2$ 在电磁波中恰好相等
