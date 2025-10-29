---
tags:
  - Economics
  - 供需关系
  - 定义性
  - 决策
  - 证明
  - WelfareEconomics
title: Monopoly
created: 2025-10-16T07:42:00
modified:
---
# Monopoly 
与[[IMP Firms in Competitive Markets]]中的基本假设“竞争市场”不同，**垄断者不是price taker，它是price maker**，它也必须得决定自己的生产量，而无法像竞争市场那样跟着均衡价格走
垄断者可以控制自身产品的价格，但控制不了市场需求，因此其利润并不是无限的。

## 1. Cause
垄断的根本原因是除了垄断者以外的其他企业的**进入障碍 (barriers to entry)**
Barriers to Entry:
- Monopoly resources: 关键资源由一家企业拥有
- **Government regulation**: 政府给予企业排他性 (exclusive
right) 权利
- **The production process**: 垄断者的生产成本低于大多数企业

### Monopoly Resources
正如[[Public Goods and Common Resources]]的**1**所说，实际情况中自然资源往往不具有排他性，故垄断资源 (monopoly resources) 很少是垄断的成因

### Government Regulation
政府创造的垄断源自政府给予一个人或企业的**排他地生产的权利 (the exclusive
right to produce a good or service)**
>例如：
>专利和版权
>1. 制药公司为一款药物申请专利，于是创造了关于这款药物的市场的垄断
>2. 作者的版权能令其成为作品销售的垄断着

### Natural Monopolies
自然垄断源自造成垄断的第三种原因，即一个垄断企业能够以低于许多企业的成本进行生产。
只有在下图的这种情况下时（**平均总成本递减**），才可能会形成自然垄断：
![[natural_monopoly.png]]
当$ATC$随产量增加而递减时，说明**单个企业可以用最低的成本生产任何数量的商品**，此时**存在着规模经济 (economies of scale)**
除此之外，固定的市场规模对于自然垄断也十分重要。市场扩大时，自然垄断或许会变为竞争市场
正如[[Different Average Total Costs]]中的图象的最左侧的形状：
![[three_types_of_ATC.png]]
**自然垄断往往发生在public goods中**，这些商品**具有排他性但没有竞争性**，且**固定成本高、边际成本低的特性**，例如道路、桥梁之类的公共设施。
这些public goods需要极高的$FC$，但同时，在边际成本上：
$$MC=\frac{\Delta TC}{\Delta Q^s}$$
当$\Delta Q^s$有着增加时，$\Delta TC$非常小，故$MC$很小

会出现自然垄断的产品皆**缺乏弹性**

## 2. Decisions of Monopolies
因为垄断者是price maker，所以**垄断者的需求曲线就是市场的需求曲线**，而且它的需求曲线缺乏弹性（价格需求弹性在图象上是需求线斜率的倒数，详细见[[IMP Price Elasticity of Demand]]），如下所示：
![[monopolist's_demand_curve.png]]
反之，竞争市场中的企业自身无法影响价格，所以**竞争企业的需求曲线是一条水平线**：
![[competitive_firm_demand_curve.png]]
### 2.1 A Monopoly’s Revenue
正如[[IMP Price Elasticity of Demand]]中的**5.1**所说，对于缺乏弹性的商品，**盈利会随着价格的上升而上升**：
![[revenue_QP_1.png]]
除此之外，
$$MR=\frac{\Delta TR}{\Delta Q}=\frac{(P\times Q)'}{Q'}$$
我们把对垄断者边际收益的探究转换成了导数问题。根据[[differentiation]]的**4.2**，即导数的乘法法则：
$$MR=\frac{(P\times Q)'}{Q'}=\frac{P'Q+Q'P}{Q'}=Q\times\frac{P'}{Q'}+P$$
我们已经能够确定$|E_d|\in(0,1)$，而**价格需求弹性$E_d$又总是小于零**，因为需求反比于价格，那么就可以意识到：
$$\frac{P'}{Q'}=\frac{\Delta P}{\Delta Q}=\frac{1}{E_d}$$
$$\frac{P'}{Q'}<0\Rightarrow Q\times\frac{P'}{Q'}<0$$
那么就必然有：
$$MR=P(1+\frac{1}{E_d})$$
$$MR<P$$
所以，**垄断者的边际收益$MR$总是小于物品价格$P$**：
![[MR_and_price.png]]
那么当实现利润最大化条件$MC=MR$时，一定会有$MC<P$，因此企业将永远不能在最有效率的产能上生产

### 2.2 Profit Maximization
由于**垄断企业必须得自己决定生产量**，所以它需要根据需求曲线来找到让自身利润最大化的产量：
![[profit_maximization_for_monopolist.png]]
[[Consideration of Marginal Changes]]中提及的边际利润公式同样成立：
$$MP=MR-MC$$
对于垄断企业，同样有$MR=MC\Rightarrow\pi_{max}$

### 2.3 A Monopoly’s Profit
与[[IMP Firms in Competitive Markets]]相同，同样有：
$$\pi=TR-TC=(\frac{TR}{Q}-\frac{TC}{Q})\times Q=(P-ATC)\times Q$$
![[monopoly_profit.png]]

## 3. Monopoly and Deadweight loss

### 3.1 Cause
>补充：
>竞争市场中，**边际成本线就是供给线**（见[[补充：边际成本与价格供给弹性]]），很明显，由于边际成本同样能左右垄断企业的决策，对垄断企业来说，边际成本线就相当于它的供给线，尽管根据定义来看它并没有供给线。

首先见下图所体现的**有效产量 (efficient quantity)**，即企业边际成本线与买者的需求线的交点，与[[IMP Firms in Competitive Markets]]的**5.2**中的**efficient scale**同理：
![[efficient_price_of_monopoly.png]]
如图所示，价格高于有效产量时，$MC(Q)>Demand(Q)$，反之则$MC(Q)<Demand(Q)$，所以只有当$MC(Q)=Demand(Q)$时才能获得有效产量。

问题在于，**垄断企业只有在$Q^d>MC$时才能获得更大利润**，它的定价往往更高。我们用[[Economic Surplus]]的知识点来分析其**deadweight loss**：
![[deadweight_loss_of_monopoly.png]]
在福利经济学的角度，垄断无法总剩余最大化。首先，从图象上看，**供给曲线与价格相交所成的面积是生产者盈余**，且**需求曲线与价格相交形成的面积是消费者盈余**（见[[Economic Surplus]]**3**），而企业对价格的人为抬高则必然会造成无谓损失，**其效果与对消费者征税无异**

对于垄断下的deadweight loss的计算，见[[补充：应试中快速计算垄断的无谓损失]]
简单来说：
$$\text{Deadweight Loss}=\frac{1}{2}\times(P_m-MC(Q_m))\times(Q_c-Q_m)$$
其中，$P_m$指垄断价格，$Q_m$是垄断产量，$Q_c$则是前文提及过的有效产量
### 3.2 Other Possibilities
在一些企业为了利润最大化而实行的策略下，无谓损失也可以被减少，例如**价格歧视 (price discrimination)**
Price discrimination意味着企业**通过不同顾客的支付意愿来收取不同价格**，例如精装书和平装书、成人票和儿童票，甚至是私立学校的奖学金。
此时，尽管**消费者剩余没有增加**，但是**生产者剩余增加了**，从而减少了无谓损失。在理想情况下，假如企业真的能完美地预测消费意愿，那么将不会有无谓损失，市场的全部利润全部属于垄断企业：
![[price_discrimination.png]]
