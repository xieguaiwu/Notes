---
tags:
  - Economics
  - 定义性
  - 证明
title: Basic Finance
created: 2025-11-01T20:32:00
modified:
---
# Basic Finance
## 1. Present Value
此知识点首先与复合利息相关。设年利率为$r$，期限为$N$年，且已知$N$年过后会收到数额为$X$的货币，那么可以由此计算出这个未来价值的现值 (present value)：
$$\text{Present Value of }X=\frac{X}{(1+r)^N}$$
这个**寻找终值 (final value) 的现值的过程叫做贴现 (discounting)**

## 2. Rule of 7 in Compound Interest
所谓的七十法则意味着：
$$\text{本金翻倍所需年数}\approx\frac{70}{\text{年增长率（百分比）}}$$
**（其中年增长率不写成小数形式！）**

---

其数学证明如下：
首先写出复合利息的公式（$P$为本金，$A$是最终金额，$r$是年利率（写成小数形式），$n$是复利次数，$t$是年数）
$$A=P(1+\frac{r}{n})^{nt}$$
当$n\to\infty$时得到连续复利公式
$$A=Pe^{rt}$$
当金额翻倍时，$A=2P$，带入原式：
$$2P=Pe^{rt}$$
$$\Rightarrow 2=e^{rt}$$
同取自然对数
$$\ln(2)=rt$$
$$\Rightarrow t=\frac{\ln(2)}{r}$$
其中，$\ln(2)\approx 0.693$，而$r=\frac{\text{年增长率}}{100}$，那么：
$$\text{本金翻倍所需年数}\approx\frac{70}{\text{年增长率（百分比）}}$$
## 3. Managing Risk

### 3.1 Risk Aversion
vocab: risk aversion$\Leftrightarrow$风险厌恶
用[[Consideration of Marginal Changes]]中的边际效用递减法则来建立风险厌恶模型：
![[risk_aversion_model.png]]
可以看到，效用函数属于[[Higher Order Derivative]]中的凹函数，其特点在于二阶导小于零，说明边际效应在递减，而**失去财富的边际效应大于增加财富的边际效应**

### 3.2 Insurance
**保险的最重要作用就在于规避风险**

### 3.3 Diversification
正如[[IMP Saving,Investment, and the Financial System]]中的**2.2**所提及的共同基金的策略，**资产组合的多元化能够有效降低风险**
但是，这种多元化**能够降低的是企业特有风险 (firm-specific risk)**，即与特定某家企业相关的风险，而**不能消除市场风险**

### 3.4 The Trade-Off between Risk and Return
正如[[Trade-offs]]中的基本原理，风险与预期之间也存在着交替原则，高风险往往也意味着高收益

### 3.5 Asset Valuation
资产评估会决定投资者对每只股票的支付意愿
#### 3.51 Fundamental Analysis
基本面分析主要有以下两方面：
- Dividend（股息）：正如[[IMP Saving,Investment, and the Financial System]]的**1.2**所言，持有股票则有权获得企业的部分利润。**被拿来支付于股东的利润即股息**，剩下的利润则会用于企业投资
- Price-Earning Ratio（价格收益比）：可以简写为$P/E$，等同于**每股价格除以每股收益**
	- 高$P/E$：股价偏高，股票或许被高估了
	- 低$P/E$：股价偏低，股票或许被低估了

#### 3.52 The Efficient Markets Hypothesis
有效市场假说的关键组成在于：市场将立即反应新的信息，调整至新的价位，故价格变化是取决于新信息的发布，**股价呈随机走势**；另一方面，**投资者是理性且追求最大利润的**，而且每人对于股票分析都是独立的，不受相互影响

#### 3.53 Market Irrationality
市场非理性的观点认为资产市场是由投资者的本能冲动驱动的，这或许是因为股东对股票的不仅仅由分红决定，**也取决于对股票最终出售价格的心理预期**
