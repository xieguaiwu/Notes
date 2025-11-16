---
tags:
  - Economics
  - MonetaryEconomics
  - Society
  - 定义性
  - 供需关系
  - WelfareEconomics
  - 决策
title: IMP Money Growth and Inflation
created: 2025-11-04T15:48:00
modified:
---
# Money Growth and Inflation
## 1. Money Supply, Money Demand, and Monetary Equilibrium
首先，根据[[Cost of Living]]中CPI的公式，假如设$P$是total price of goods in a basket，即用$P$单位货币才能买到一定数量的商品/服务，那么可以说**1单位货币能够买到的商品/服务是$\frac{1}{P}$**。
所以可以意识到**货币的价值和物价成反比**

### 1.1 Money Supply
正如[[IMP The Monetary System]]的**4**所说，**货币供给由美联储和银行体系共同决定**，货币乘数是一个关键的影响因子

### 1.2 Money Demand
见[[IMP The Monetary System]]的**1**，人们持有货币是因为它的三种属性，其中最重要的是因为货币是medium of exchange，故**物价水平上升会增加名义上的货币需求**，反之则会减少货币需求

### 1.3 Equilibrium
![[monetary_equilibrium.png]]
如图所示，由于货币量是被人为控制的，所以在图中呈现为竖直直线。另一方面，正如前文所言，由于货币价值与物价成反比，所以需求函数是递减的。
假如注入了货币，那么货币量自然上升，图象发生变化：
![[monetary_equilibrium_rising.png]]
货币量上升则物价上升，货币价值下降

但是参考[[Production and Growth]]中的生产函数，货币量的增加并没有引起其中任意变量的改变。货币量的增加并不会直接促进经济的生产能力。

## 2. The Classical Dichotomy and Monetary Neutrality
vocab: dichotomy$\Rightarrow$二分法
这一节涉及名义变量nominal variables和真实变量real variables，正如[[National Income]]中**2**关于名义和真实GDP的知识点。
对于GDP，只有涉及到通货膨胀的GDP才是real GDP。对应到价格上，**只有relative price才是real variables**

由于企业常常无法快速变更价格，所以**relative price可能会被通货膨胀率影响**，故令市场配置无法达到帕累托最优（见[[Pareto Efficiency]]）

正因如此，古典二分法 (Classical Dichotomy) 才会认为**货币供给的变化只影响名义变量**，所以其认为**货币中性 (Monetary Neutrality)**
这对长期来说是正确的，但在短期范围内并不一定

## 3. Velocity and the Quantity Equation

### 3.1 Def
正如[[IMP Saving,Investment, and the Financial System]]所言，货币是流通性最强的资产。
一种货币的流通性被称为the velocity of money
货币流通性的计算公式如下：
$$V=\frac{(P\times Y)}{M}$$
其中$V$表示货币流通性，$P$表示物价水平（用GDP Deflator衡量，因为正如[[Cost of Living]]的**4**所说，**只有GDP deflator才能衡量所有物品/服务的价格**），$Y$表示产量（用Real GDP或者Production Function衡量，见[[Production and Growth]]），$M$则表示货币量（货币量的公式见[[IMP The Monetary System]]）
公式在变形之后即可成为费雪在《货币幻觉》《繁荣与萧条》中都提及过的货币经济学公式：
$$M\times V=P\times Y$$
这个方程式被称作Quantity Equation，因为它将货币量与名义产出价值nominal value of ouput（即$P\times Y$）联系了起来

### 3.2 IMP Properties
关于货币流通速度，见下图真实的统计数据：
![[Nominal_GDP_Quantity_and_Velocity_Of_Money.png]]
1. **货币流通速度一直较为稳定**
2. 货币量改变时，**nominal value of output等比例改变**
$$M\uparrow\times V^{-}=(P\times Y)\uparrow$$
这说明假如$Y$变化不大，则**货币量上升必定引发物价上升，则通货膨胀率上升**，反之则下降。
$$M\uparrow\times V^{-}=P\uparrow\times Y^{-}$$

## 4. The Inflation Tax
当政府需要增加财政预算时，它可以如[[Tax Incidence]]里那样选择征税，但是它也可以选择印刷更多货币来增加收入。这种货币量增加的政策会推动物价上升，所以**inflation tax等同于向每一个持有货币的人征税**

## 5. Fisher effect
这段内容是费雪的代表作《利息理论》中出现的。
正如前文所说，有real variable和nominal variable的分别。[[Cost of Living]]的**7**涉及到了Real Interest Rates和Nominal Interest Rates，其公式如下：
$$\text{Real interest rate}=\text{Nominal interest rate}-\text{Inflation rate}$$
将之写成
$$\text{Nominal interest rate}=\text{Real interest rate}+\text{Inflation rate}$$
由于Real Interest Rate在一段时期内的变化并不会太大，所以通货膨胀率越高，名义利率越高。**当货币量增加且通货膨胀率增加时，名义利率也会水涨船高**。

反而言之，适当的通货紧缩会令$\text{Nominal interest rate}=\text{Real interest rate}$，这就是**弗里德曼规则 (Friedman rule)**

如下图所见，名义利率和通货膨胀率有着很高的相关性：
![[nominal_interest_rate_and_inflation.png]]

## 6. The Costs of Inflation
### 6.1 Inflation and the Cost of Living
如果相信大多数人都依靠在当下出售商品/服务获得收入，那么**收入上涨与通货膨胀率同步，则通货膨胀率本身不会降低人们的实际购买力**

### 6.2 Avoiding Inflation
正如前文的**4**所言，Inflation Tax是通过通货膨胀率对所有货币持有者征税。为了规避Inflation Tax，一种做法是**减少货币持有量**，由于这需要频繁地去银行，所以它被称为皮鞋成本**Shoeleather Cost**

### 6.3 Menu Costs
企业不会频繁地改变定价，尽管经济状况可能会有波动。这是因为**变换定价会承担菜单成本 (menu costs)**，故企业在宣布更换价格时往往会慎重考虑，以致有[[Aggregate Demand & Aggregate Supply]]的**4.2**中的sticky-price theory

## 7. The Dark Side of Inflation
### 7.1 Tax Distortions
这归根结底还是因为**税收不考虑实际购买力**，以名义价格为准绳来征税常常会因为通货膨胀造成的实际购买力的下降而增加实际的税收负担。

### 7.2 Arbitrary Redistributions of Wealth
正如《货币幻觉》中关于一战后伴随着高通货膨胀率的各国政府应对战争贷款的行为的例子那样，**预期之外的通货膨胀可能会在债务人和债权人之间进行财富再分配**。
- **通货紧缩损害债务人 (debtors)，利好债权人 (creditors)**
- 反之，通货膨胀率利好债务人，令债权人蒙受损失
