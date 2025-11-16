---
tags:
  - State
  - MonetaryEconomics
  - 定义性
  - 供需关系
  - Economics
title: Open-Economy Macroeconomics
created: 2025-11-06T09:37:00
modified:
---
# Open-Economy Macroeconomics
首先，正如[[National Income]]的**1.2**所说，有closed economy和open economy，其中现代经济是open economy，其$NX\neq 0$
## 1. The Flow of Goods
[[National Income]]的**1.23**聚焦于净出口，其公式如下：
$$\text{Net Exports}=\text{Value of Export}-\text{Value of Import}$$
- $\text{Net Export}>0\Rightarrow$**trade surplus**
- 反之，$\text{Net Export}<0\Rightarrow$**trade deficit**
- 而$\text{Net Export}=0\Rightarrow$**balanced trade**

## 2. The Flow of Financial Resources: Net Capital Outflow
资本净流出 (Net Capital Outflow)：由于本国居民可以购买外国资产，而外国人也会购买本国资产，所以会出现Capital Outflow。其公式如下：
$$\text{Net Capital Outflow}=\text{外国人购买的本国资产}-\text{本国人购买的外国资产}$$

将Net Capital Outflow和Net Exports分别简写为$NCO$和$NX$，在整个经济而言，会有以下等式恒成立：
$$NCO=NX$$
这是因为**一国资本净流出完全等于一国净出口的增加**
正因如此，
$$\text{Trade Surplus}\Rightarrow NCO>0$$
$$\text{Trade Deficit}\Rightarrow NCO<0$$
结合[[National Income]]的**1.2**中的公式和[[IMP Saving,Investment, and the Financial System]]中**3**的关于封闭经济的公式，可以得出，对于open economy：
$$S=I+NX$$
于是
$$S=I+NCO$$
总结：
![[international_flow_of_goods_and_capital.png]]

## 3. Problem of Trade Deficit
因为公式
$$S=I+NCO$$
所以如果一国出现了national saving减少的情况，就会有
$$S\downarrow = (I+NCO)\downarrow$$
这里有两种情况，**假如投资$I$不变甚至增加，那么问题并不会很大**。尽管会有贸易逆差，但**国外投资足以支持国内的投资**。
但是假如$I$减少，那么就意味着国内的生产增长已经受到了阻碍。

## 4. The Prices for International Transactions
当涉及到国际交易时，就会涉及到Exchange Rate，而正如[[IMP Money Growth and Inflation]]的**2**中所提及的，对于Exchange Rate也有Real Exchange Rate和Nominal Exchange Rate之分。
Nominal Exchange Rate即常识中的汇率，即一门货币换取另一门货币的官方比率
但是Real Exchange Rate的概念并不相同：
$$\text{Real Exchange Rate}=\frac{\text{Nominal exchange rate}\times\text{Domestic Price}}{\text{Foreign Price}}$$
这个公式的特点就在于考虑到了物价水平的问题，但是这个物价水平并非[[IMP Money Growth and Inflation]]的**3.1**中的货币流通公式里的Real GDP，而是[[Cost of Living]]里的CPI
$$\text{Real Exchange Rate}=\frac{e\times P}{P^*}$$
其中$e$指Nominal Exchange Rate，而$P$指国内的物价水平，$P^*$则是国外的物价水平，**它们都用CPI衡量**

## 5. Purchasing-Power Parity
### 5.1 Def
vocab: Purchasing-Power Parity即购买力平价理论，它认为**每单位货币都在其国家中有着真实价值**，即：
$$\frac{1}{P}=\frac{e}{P^*}$$
对于$\frac{1}{P}$，正如[[IMP Money Growth and Inflation]]的**1**所说，其所衡量的是一单位货币的真实价格
整理这个公式，可以得知：
$$1=\frac{eP}{P^*}$$
那么
$$e=\frac{P^*}{P}$$
则这意味着**两国货币的名义汇率必然反应物价水平**

### 5.2 Problems
购买力平价理论考虑不到的局限与CPI的局限高度相关，例如它无法考虑到很多时候不同商品之间没法直接相互替换，以及许多物品无法在所有国家都具有一样的流通性

## 6. On Loanable Funds Market
见[[IMP Saving,Investment, and the Financial System]]的**4**，对于可贷金市场的供需关系有下图：
![[market_of_loanable_funds.png]]
联系上之前的公式
$$S=I+NCO$$
在一个open economy中，可贷资金的需求方不仅可能会购买国内资产，也可能会选择购买国外资产，这样就拓展了[[IMP Saving,Investment, and the Financial System]]中的closed economy模型。
**在均衡利率时，储国内投资和资本流出量也达到了平衡的状态**

## 7. The Market for Foreign-Currency Exchange
回到**3**的公式：
$$NCO=NX$$
这二者可以说明外汇市场上的供需方。$NCO$是供给，$NX$是需求

**$NCO>0$即资本净流出时，就需要把本国货币换为外国货币，从而创造了外汇市场的供给**，另一方面，**净出口$NX>0$时，外国需要兑换本国货币来购买本国商品，从而创造外汇市场的需求**
而将外汇市场与[[Supply and Demand]]中的模型类比，外汇市场中的价格是**Real Exchange Rate**

外汇市场的供需图像如下：
![[market_of_foreign_currency.png]]

## 8. Equilibrium in the Open Economy
### 8.1 Def
$$\because S=I+NCO$$
$$\therefore NOC=S-I$$
结合可贷金市场的图象，意识到实际利率与存款的正相关性。
正如[[IMP Saving,Investment, and the Financial System]]的**4**所说，可贷金市场的供给端就是储蓄，即公式中的$S$。结合**4.1**的内容，我们可以意识到，**资本净流出的关键在于真实利率**
下方图象显示了Real Interest Rate和$NCO$的关联
![[NCO_and_real_interest_rate.png]]

结合所有这些图象，得出真实利率对于open economy的总体影响，以如下三个方面呈现：
![[open_economy_and_real_interest_rate.png]]

### 8.2 Shifts of the Total Graph
外部情况会影响到open economy
#### 8.21 Government Budget Deficit
这点曾在[[IMP Saving,Investment, and the Financial System]]的**3**和**4.13**讨论过，现在将政府财政赤字的影响扩展到一个更总体的范围内
![[open_economy_and_government_budget_deficit.png]]
如图所示，政府财政赤字**会增加Real Interest Rate，减少国内投资，引起货币升值，减少可贷资金供给、减少$NCO$和$NX$**

#### 8.22 Import Quotas
曾在[[Effect of Tariff]]中提及过作为贸易策略的进口限额，其效果类似于关税，同样是利好生产者而损害消费者福利。**它对于open economy的影响主要集中于外汇市场**
![[open_economy_and_import_quotas.png]]

#### 8.23 Capital Flight
**资本外逃会增加Real Interest Rate**，但国内投资反而减少，可贷金市场的资金需求上升，同时会另$NCO$增加
![[open_economy_and_capital_flight.png]]
