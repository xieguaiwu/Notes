---
tags:
  - State
  - 供需关系
  - 决策
  - 定义性
  - Economics
  - MonetaryEconomics
  - 证明
title: How do Monetary & Fiscal Policy influence Aggregate Demand
created: 2025-11-16T11:56:00
modified:
---
# How do Monetary & Fiscal Policy influence Aggregate Demand
## 1. The Theory of Liquidity Preference
流动性偏好理论来自凯恩斯的《就业、利息和货币通论》，它用来解释利率的决定因素。在他看来，利率会令货币供给与货币需求达到平衡。
回到[[IMP Saving,Investment, and the Financial System]]中对market of loanable funds的说明，以及[[IMP The Monetary System]]中对于货币体系的说明，见下图：
![[equilibrium_in_money_market.png]]
- 货币供给量：正如[[IMP The Monetary System]]的**4.4**所说，federal reserve system控制了货币的供给，正是因为这个供给量的人为性，**货币供给量才并不取决于利率**
- 货币需求量：正如[[IMP Money Growth and Inflation]]所说，货币是流通性最强的资产，这种流通性（同时也指向了货币作为medium of exchange的属性）解释了货币的需求。**利率是持有货币的机会成本** ([[Opportunity Cost]])，因为持有现金而非债券就意味着损失利息，正因如此，**利率上升增加了持有货币的成本，减少了货币的需求量**，反之则会减少持有成本，增加货币需求量。

回到图中，当利率高于均衡水平，位于图中的$r_1$时，民众希望持有的货币量$M^d_1$小于货币供给量$M^S$，所以**持有比较多货币的人会倾向于购买债券或进行储蓄**。随着对债券或储蓄的需求增多，则债券发行者和银行则更愿意支付**更低的利率**，最终令人们更倾向于持有货币，直至达到均衡状态下的利率。

相反，当利率低于均衡水平，位于图中$r_2$时同样如此。利率最终也会回落到均衡状态。

**货币供给量增加则利率降低**，反之则等同于利率增加

## 2. Liquidity Trap
正如前文末尾所言，当Federal Reserve希望增加货币供给量时，利率会降低，但当利率已经降至零时，又要如何刺激经济呢？
在这种流动性陷阱 (liquidity trap)下，**人们宁可持有先进也不会以负利率发放贷款**。这个时候，尽管公众的资产的流动性已经非常高了，但是却起不到任何效果。
不过，正如[[IMP Money Growth and Inflation]]的**5**所言，费雪效应指出：
$$\text{真实利率}=\text{名义利率}-\text{通货膨胀率}$$
故当名义利率降至零时，**如果有一定的通货膨胀率，那么真实利率完全可以小于零**。正因如此，**适度的通货膨胀率降低了陷入liquidity trap的风险**

## 3. How Fiscal Policy Influences Aggregate Demand
vocab: Fiscal Policy$\Leftrightarrow$政府购买（见[[IMP Saving,Investment, and the Financial System]]的**3**）和税收总水平的选择

### 3.1 Changes in Government Purchases
当政府下订单时，总需求会随之移动，但**总需求变动量不会等于政府购买**，这是因为两种宏观经济学效应：
- 乘数效应 (The Multiplier Effect)：令总需求变化量大于政府购买
- 挤出效应 (The Crowding-Out Effect)：反之，令总需求变化量小于政府购买

#### 3.11 Multiplier Effect
当政府购买增加时，生产方可能会扩大雇员数量，并且利润或许会随产量增加而增加，于是又刺激了消费支出，总而令总需求大大增加：
![[mutiplier_effect_from_government_purchase.png]]
如图所示，从$AD_1$增加到$AD_2$的量正好是政府购买的直接影响，而随后从$AD_2$到$AD_3$则是multiplier effect的影响。
这种**投资需求的正反馈就是投资加速数 (investment accelerator)**

边际消费倾向 (marginal propensity to consume)，写作$MPC$：家庭中额外收入用于消费而非储蓄的比例
假如总体的$MPC$恒定，而政府购买是$x$元，这笔钱全部支付给了工人和公司所有者：
第一轮消费变动会是$MPC\cdot x$，这些钱又流向了其他行业的劳动者，最终造成了第二轮消费变动$MPC^2\cdot x$、第三轮消费变动$MPC^3\cdot x$等等
这是一个数学上的无穷级数：
$$\text{Mutiplier}=1+MPC+MPC^2+MPC^3+\ldots$$
于是
$$\text{Mutiplier}=\frac{1}{1-MPC}$$
故**边际消费倾向越大，乘数效应越大**

#### 3.12 The Crowding-Out Effect
另一方面，当政府购买刺激了总需求时，**它也会使利率上升**，这又会减少投资支出：
![[crowding_out_effect_and_government_purchase.png]]
如图所示，当$AD$上升时，由于货币供给量恒定，则货币需求$MD$也上升，推动利率$r$上升
利率上升反而减少了物品/服务的需求量，令总需求量从$AD_2$回落到$AD_3$，最终的增加量仅仅是从$AD_1$到$AD_3$

正因如此，**政府购买对总需求的影响取决于乘数效应和挤出效应的大小**

