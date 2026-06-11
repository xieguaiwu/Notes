---
tags:
  - Economics
  - Finance
  - FinancialModeling
  - 定义性
  - 概念性
  - 基本原理
title: Finance - Market Greeks
created: 2026-06-09
---

# Finance — Market Greeks

> [!abstract] 概述
> Greek 字母是金融衍生品定价与风险管理中度量各类风险暴露的敏感性指标。它们量化了期权价格（或其他衍生品）对标的资产价格、时间、波动率、利率等参数变动的敏感程度。理解 Greeks 是交易策略设计、对冲操作与量化风险管理的基石。

## 1. 核心 Greeks

### 1.1 Delta ($\Delta$) — 价格敏感度

> [!note] 定义
> Delta 度量衍生品价格对**标的资产价格**变动的敏感度，即价格的一阶偏导。

$$\Delta = \frac{\partial V}{\partial S}$$

| 头寸类型 | Delta 范围 | 含义 |
|:---------|:-----------|:-----|
| 看涨期权 (Call) | $0$ 到 $+1$ | 标的涨 1 元，期权涨 $\Delta$ 元 |
| 看跌期权 (Put) | $-1$ 到 $0$ | 标的涨 1 元，期权跌 $|\Delta|$ 元 |
| 标的资产 | $+1$ (多头) / $-1$ (空头) | 线性关系 |
| ATM 期权 | 约 $\pm 0.5$ | 对价格变动最敏感 |
| ITM 期权 | 接近 $\pm 1$ | 行为接近标的资产 |
| OTM 期权 | 接近 $0$ | 几乎不受标的价格影响 |

**Delta 对冲**: 持有一个期权 + 做空 $\Delta$ 份标的 → 瞬时 Delta 中性。即组合价值对微小价格变动不敏感：

$$\Pi = V - \Delta \cdot S \quad \Rightarrow \quad \frac{\partial \Pi}{\partial S} = 0$$

Black-Scholes 下 Call 的 Delta 解析式：

$$\Delta_{\text{call}} = N(d_1), \quad d_1 = \frac{\ln(S/K) + (r + \sigma^2/2)T}{\sigma\sqrt{T}}$$

其中 $N(\cdot)$ 为标准正态累积分布函数，$S$ 为标的价格，$K$ 为行权价，$r$ 为无风险利率，$\sigma$ 为波动率，$T$ 为到期时间。

### 1.2 Gamma ($\Gamma$) — Delta 的变化率

> [!note] 定义
> Gamma 是 Delta 对标的价格的二阶偏导，度量 Delta 随标的价格变动的速率。

$$\Gamma = \frac{\partial^2 V}{\partial S^2} = \frac{\partial \Delta}{\partial S}$$

| 特性 | 说明 |
|:-----|:-----|
| **凸性度量** | $\Gamma > 0$ 表示期权多头享有利好凸性（涨多跌少） |
| **ATM 附近最大** | 接近到期日的 ATM 期权 Gamma 急剧升高 (Gamma pin risk) |
| **对冲频率决定因素** | $\Gamma$ 越大，Delta 变化越快，需要更频繁地再平衡对冲 |
| **Call = Put** | 相同行权价的 Call 和 Put 具有相同的 Gamma |

**Gamma 的盈亏效应**（泰勒展开至二阶）：

$$\Delta V \approx \Delta \cdot \Delta S + \frac{1}{2} \Gamma \cdot (\Delta S)^2$$

- 多头 Gamma ($\Gamma > 0$)：无论标的方向，价格波动越大盈利越多 → "Long Gamma"
- 空头 Gamma ($\Gamma < 0$)：做空期权者暴露于尾部风险

### 1.3 Theta ($\Theta$) — 时间衰减

> [!note] 定义
> Theta 度量期权价格随**时间流逝**的衰减速率。

$$\Theta = \frac{\partial V}{\partial t}$$

| 特性 | 说明 |
|:-----|:-----|
| **通常为负** (多头) | 期权多头每天损失时间价值 |
| **临近到期加速** | ATM 期权在到期前最后几周 Theta 急剧增加 |
| **与 Gamma 的权衡** | $\Theta \approx -\frac{1}{2}\Gamma \sigma^2 S^2$（BS 偏微分方程关系） |
| **周末/节假日** | Theta 按**交易日**衰减，非日历日 |

> [!tip] 直观理解
> 卖出期权者赚取 Theta（时间价值衰减速率为正），但承担 Gamma 风险。Theta 和 Gamma 本质上是同一枚硬币的两面——你不能只要 Theta 而不承担 Gamma 风险。

### 1.4 Vega ($\nu$) — 波动率敏感度

> [!note] 定义
> Vega 度量期权价格对**隐含波动率**变动的敏感度。注意：Vega 本身不是希腊字母，但业界约定俗成如此称呼。

$$\nu = \frac{\partial V}{\partial \sigma}$$

| 特性 | 说明 |
|:-----|:-----|
| **始终为正** (多头) | 波动率越高 → 期权越有价值 |
| **ATM 附近最大** | ATM 期权对波动率变化最敏感 |
| **期限越长 Vega 越大** | 长期限期权对波动率变化更敏感 |
| **Vega 曲面** | 不同行权价/期限对应不同 Vega — 构成波动率微笑的骨架 |

**波动率交易**: Vega 是波动率交易的核心指标。
- 买入跨式组合 (Long Straddle) → Long Vega + Long Gamma
- 卖出跨式组合 (Short Straddle) → Short Vega + Short Gamma
- 波动率套利：判断隐含波动率与已实现波动率的偏离

### 1.5 Rho ($\rho$) — 利率敏感度

> [!note] 定义
> Rho 度量期权价格对**无风险利率**变动的敏感度。

$$\rho = \frac{\partial V}{\partial r}$$

| 特性 | 说明 |
|:-----|:-----|
| Call: $\rho > 0$ | 利率上升 → Call 更有价值（远期价格更高） |
| Put: $\rho < 0$ | 利率上升 → Put 价值下降 |
| **影响通常较小** | 相比其他 Greeks，Rho 对短期期权影响较小 |
| **长期/深度 ITM 显著** | 长期深度实值期权对利率敏感 |

> [!warning] 注意
> 在利率极低或负利率环境中，Rho 的行为可能与传统直觉不同。

### 1.6 Alpha ($\alpha$) — 超额收益

> [!note] 定义
> Alpha（在 Greeks 语境之外更常用于投资组合管理）指**超过基准（Benchmark）或风险调整后预期收益的部分**。它度量的是策略或管理者产生的主动超额回报。

在 CAPM 框架下：

$$R_i - R_f = \alpha_i + \beta_i (R_m - R_f) + \varepsilon_i$$

- $\alpha_i > 0$：策略产生了超越市场风险补偿的正收益 → 有"Alpha"
- $\alpha_i = 0$：收益恰好等于风险暴露的补偿（有效市场）
- $\alpha_i < 0$：收益低于风险预期的应有水平

> [!tip] 量化交易视角
> 在量化交易中，"寻找 Alpha" 等同于寻找可预测的超额收益信号。Alpha 衰减（Alpha Decay）指信号在发现后逐渐被市场吸收而失效的过程，是量化策略面临的核心挑战。

### 1.7 Beta ($\beta$) — 市场系统性风险

> [!note] 定义
> Beta 度量资产收益对**市场整体收益**的敏感度，代表不可通过分散化消除的系统性风险。

$$\beta_i = \frac{\text{Cov}(R_i, R_m)}{\text{Var}(R_m)}$$

| $\beta$ 值 | 含义 |
|:-----------|:-----|
| $\beta = 1$ | 与市场同步波动（如指数基金） |
| $\beta > 1$ | 比市场更激进（如成长股、杠杆 ETF） |
| $0 < \beta < 1$ | 比市场更保守（如公用事业股） |
| $\beta = 0$ | 与市场不相关（真正的市场中性策略） |
| $\beta < 0$ | 与市场反向（如黄金在某些时期） |

**市场中性 (Market Neutral)** 策略：通过对冲消除 Beta 暴露，使得组合收益仅来源于 Alpha：

$$\Pi = \underbrace{\sum w_i^{\text{long}} R_i}_{\text{多头}} - \underbrace{\sum w_j^{\text{short}} R_j}_{\text{空头}}, \quad \text{约束 } \beta_{\Pi} \approx 0$$

## 2. 高阶 Greeks

### 2.1 Charm (Delta Decay)

$$\text{Charm} = \frac{\partial \Delta}{\partial t} = \frac{\partial^2 V}{\partial S \partial t}$$

度量 Delta 随时间衰减的速率。临近到期时 ATM 期权 Charm 变化剧烈。

### 2.2 Vanna

$$\text{Vanna} = \frac{\partial \Delta}{\partial \sigma} = \frac{\partial^2 V}{\partial S \partial \sigma}$$

度量 Delta 如何随隐含波动率变化，也等于 Vega 对标的价格的敏感度。用于管理波动率微笑风险。

### 2.3 Vomma / Volga

$$\text{Vomma} = \frac{\partial \nu}{\partial \sigma} = \frac{\partial^2 V}{\partial \sigma^2}$$

Vega 对波动率的二阶敏感度（Vega 的凸性）。高 Vomma 意味着 Vega 对冲不够稳定。

### 2.4 Speed ($\partial^3 V / \partial S^3$)

$$\text{Speed} = \frac{\partial \Gamma}{\partial S} = \frac{\partial^3 V}{\partial S^3}$$

Gamma 变化的速度，用于监控 Delta-Gamma 对冲在大幅价格变动下的解体速度。

### 2.5 高阶 Greek 速查表

| Greek | 公式 | 物理直觉 | 交易用途 |
|:------|:-----|:---------|:---------|
| Charm | $\partial \Delta / \partial t$ | Delta 的时间衰减 | 管理临近到期的 Delta 漂移 |
| Vanna | $\partial \Delta / \partial \sigma$ | Delta 的波动率依赖 | 波动率微笑 / 偏斜对冲 |
| Vomma | $\partial \nu / \partial \sigma$ | Vega 的凸性 | 大波动率变动下的 Vega 对冲 |
| Speed | $\partial \Gamma / \partial S$ | Gamma 的变化率 | 监控 Delta-Gamma 对冲稳定性 |
| Ultima | $\partial \text{Vomma} / \partial \sigma$ | Vomma 的变化率 | 极端波动率事件下的高阶监控 |

## 3. Greeks 与风险管理

### 3.1 组合 Greeks 的叠加

Greeks 在组合层面是**线性可加**的：

$$\Delta_{\Pi} = \sum_i w_i \Delta_i, \quad \Gamma_{\Pi} = \sum_i w_i \Gamma_i, \quad \nu_{\Pi} = \sum_i w_i \nu_i$$

### 3.2 希腊字母中性化层级

| 中性化层级 | 对冲内容 | 工具 |
|:-----------|:---------|:-----|
| Delta 中性 | 消除标的方向风险 | 标的资产 / 期货 |
| Gamma 中性 | 消除 Delta 漂移 | 额外的期权 |
| Vega 中性 | 消除波动率风险 | 不同行权价/期限的期权 |
| Theta 中性 | 消除时间衰减 | 日历价差 |
| Rho 中性 | 消除利率风险 | 利率衍生品 |

### 3.3 现实中的 Greeks 管理

> [!warning] 注意
> - Greeks 是**瞬时量**：大变动下需要高阶 Greeks 修正
> - BS 模型假设经常不成立：波动率非恒定、跳跃风险、流动性风险
> - 对冲需要交易成本：过度对冲可能损失比风险本身更多
> - 尾部风险来自 Gamma/Vega 的空头敞口：2018 年 Volmageddon、2020 年 3 月等极端事件

## 4. 相关链接

- [[Finance - Quantitative Trading Fundamentals]] — 量化交易核心概念
- [[Finance - Efficient Market Hypothesis]] — 有效市场假说（EMH）
- [[Finance - Stable Paretian Distribution]] — 股票收益的稳定帕累托分布
- [[ML-Track/CTM - Feature Engineering]] — 金融特征工程
- [[ML-Track/CTM - MultiAsset Model]] — 多资产建模与交叉注意力
- [[ML-Track/CTM - Trading Execution]] — 交易系统架构
- [[ML-Track/CTM - Loss Functions]] — 量化交易损失函数

## 5. 关键公式总结

$$
\begin{aligned}
\Delta &= \frac{\partial V}{\partial S} & \text{— 价格敏感度（一阶）} \\[4pt]
\Gamma &= \frac{\partial^2 V}{\partial S^2} & \text{— 价格凸性（二阶）} \\[4pt]
\Theta &= \frac{\partial V}{\partial t} & \text{— 时间衰减} \\[4pt]
\nu &= \frac{\partial V}{\partial \sigma} & \text{— 波动率敏感度} \\[4pt]
\rho &= \frac{\partial V}{\partial r} & \text{— 利率敏感度} \\[4pt]
\alpha &= R_i - [R_f + \beta_i(R_m - R_f)] & \text{— 超额收益} \\[4pt]
\beta &= \frac{\text{Cov}(R_i, R_m)}{\text{Var}(R_m)} & \text{— 系统性风险}
\end{aligned}
$$
