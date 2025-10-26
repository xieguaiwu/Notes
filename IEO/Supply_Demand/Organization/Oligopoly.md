---
tags:
  - Economics
  - WelfareEconomics
  - 证明
  - 定义性
  - 决策
  - GameTheory
  - 供需关系
title: Oligopoly
created: 2025-10-21T12:38:00
modified:
---
# Oligopoly

## 1. Def
**不完全的市场竞争 (imperfectly competitive market) 导致寡头**，他们既不是一头垄断，也不是price taker。此时此刻，市场上任何卖者的决策都会影响其他卖者的利润。正因如此，博弈论与这种市场高度相关：
寡头市场如同一个$N$方博弈 ($n$-persons game)，其中$N\in(1,\infty)$。

## 2. Decision
- 勾结 (collusion)：寡头相互勾结，最终形成cartel，其决策行为与垄断者无异，形成市场失灵
- Equilibrium

### 2.1 Collusion
寡头各自之间都会希望占据更大的市场份额，这种勾结往往难以为继。从博弈论的视角来看，**这就像是一种囚徒困境**，因为对企业个体来讲，不遵守勾结来提高产量对自己总是有益，尽管这会因为价格效应而降低利润。
根据[[MR = Price Effect + Output Effect]]中关于价格效应的定义：在寡头市场中，**产量上升则价格下降，从而利润下降**，但与此同时，会看价格效应公式：
$$\text{Price Effect}=Q^d\times\frac{\Delta P}{\Delta Q^d}$$
其中，由于各个寡头企业的生产仍然会左右价格，所以仍然总是有
$$\Delta P\ne 0$$
所以
$$\frac{\Delta P}{\Delta Q^d}<0$$
因此即便价格因为囚徒困境而下降，我们仍然会看到
$$MR_{individual}<P$$
于是企业仍然不可能效率最大化：
$$MC_{individual}<P$$

### 2.2 The Equilibrium for an Oligopoly
寡头之间的博弈是一种非合作博弈 (Non-Cooperative Games)，最终达到的均衡状态正是一种**Nash Equilibrium**（其具体证明见[[Nash Equilibrium]]），但是，这种利己的选择最终**会令总产量增加，价格下降**，同时，寡头企业也**无法在平均总成本最低处上生产 (对于寡头企业，$P>MC$)**。与此同时，在垄断企业上也可以有$P>MC$，但在竞争企业上只有$P=MC$（见[[Monopoly]]和[[IMP Firms in Competitive Markets]]）。
换而言之，寡头市场会有规模不经济的现象（见[[Different Average Total Costs]]）

在价格上，**垄断价格大于寡头价格大于竞争企业价格**：
$$P_{monopoly}>P_{oligopoly}>P_{competitive}$$
同时：
$$P_{monopoly}>P_{oligopoly}>MC$$
同时，**垄断产量小于寡头产量小于竞争产量**：
$$Q^s_{competitive}>Q^s_{oligopoly}>Q^s_{monopoly}$$

## 3. Output Effect & Price Effect
- Output effect（产量效应$\pi\uparrow$）：指每多销售一单位产品所带来的额外收入
- Price effect（价格效应$\pi\downarrow$）：生产量上升则价格下降，从而利润下降
（在[[MR = Price Effect + Output Effect]]中可以见到对二者更详细的分析）

### 3.1 Price Effect
$$\text{Price Effect}=Q^d\times\frac{\Delta P}{\Delta Q^d}$$
其中的$Q^d$指的是企业在降价前的产量水平。根据价格效应，**如果寡头企业不降价就无法获得更高的产量**，所以$\Delta P<0$，故**对于寡头来说，价格效应是负的**
$$\text{Price Effect}<0$$
同时，
### 3.2 Output Effect
$$\text{Output Effect}=P$$

### 3.3 IMP寡头市场的规模不经济
对于边际利润$MP$来说：
$$MP=MR-MC$$
同时
$$MR=P+\text{price effect}=P+(Q^d\times \frac{\Delta P}{\Delta Q^d})$$
正如前文所言，寡头市场下的价格效应小于零，所以：
$$MR<P$$
与此同时，为了能让企业生存下去，必然有
$$MR\geq MC$$
（其中当$MR=MC$时实现均衡状态）
则
$$P>MC$$

### 3.4 从寡头市场到竞争市场
如前文所言，将寡头市场看作$N$方博弈，那么随着寡头数量的不断增多（$N\to\infty$）：
在价格效应中，**任何一个企业的生产变化对价格的影响越来越小**，即$Q^d\times\frac{\Delta P}{\Delta Q^d}$中，$\Delta P\to 0$，那么我们会意识到$\text{price effect}\to 0$，那么：
$$MR=\text{output effect}+0=P$$
于是当满足利润最大化条件$MR=MC$时，会有竞争市场下的：
$$P=MC=MR$$
于是寡头市场会因此变成竞争市场。
