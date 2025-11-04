---
tags:
  - Economics
  - 定义性
  - 供需关系
  - MonetaryEconomics
  - Society
  - State
title: The Monetary System
created: 2025-11-02T20:38:00
modified:
---
# IMP The Monetary System 

## 1. The Functions of Money
货币主要有三种职能：
- medium of exchange
- unit of account
- store of value: 任何财富都是价值储蓄的总量，人们通过财富储蓄来把现在的购买力转换成未来的购买力
**作为medium of exchange，货币是最具有流动性 (liquidity) 的资产**

## 2. Classification
- 当货币不只具有交换价值，而且还具有内在价值时，它被称为**商品货币 commodity money**，例如黄金
- 无内在价值的货币是法定货币 (fiat money)

## 3. Money Stock
货币存量主要包括以下几种资产：
- 通货 (currency)：公众持有的钞票和铸币
- **活期存款 (demand deposits)**
- 储蓄存款 (savings deposits)、定期存款 (time deposits) 等
下图所展示的是常用的货币存量衡量指标$M_1$和$M_2$：
![[m1_and_m2.png]]

注意的是，借记卡和支票都会自动从活期存款中提取资金，所以它们的账户余额包含在货币存量中，而**信用卡却不算货币**。

## 4. Banks and the Money Supply

### 4.1
准备金 (reserves)：银行得到但没有贷出的存款，属于活期存款。
**如果银行用准备金形式持有全部存款，那么它将不影响货币供给**。

大多数银行都采用部分准备金制度 (fractional‑reserve banking)，其准备金率如此计算：
$$\text{Reserve Ratio}=\frac{\text{Reserves}}{\text{Total Deposites}}\times 100\%$$
如果储备金率是$10\%$，那么说明**银行将总存款的$90\%$都发放为贷款**。考虑到原先的存款者仍然在名义上掌管着$100\%$的存款，而获得了银行贷款的债务人又获得了这些存款的$90\%$，而这两部分都算作总货币量的组成部分，那么可以说，**当银行只把部分存款当成准备金时，银行创造了更多货币**
在这种情况下，尽管经济并没有更加富裕，但是**流动性增加了**

### 4.2 The Money Multiplier
假如在**5.1**的过程中出现了变数，即这笔贷款又被存入了另一家银行，而另一家银行则仍然仅仅只把部分存款当作储备金，从而发放出更多的贷款时，但这些更多的货币又被多家银行进一步吸收并发放成贷款时，我们会立刻见到货币量在不停上升。
如果许多银行通过这种方式将100元的准备金变成了1000元，那么货币乘数 (Money Multiplier) 就是十。

如果$R$是某一经济中所有银行的准备金率，**那么每1元准备金都能产生$\frac{1}{R}$货币**。故**货币乘数是准备金率的倒数**
$$\text{Money Multiplier}=\frac{1}{\text{Reserve Ratio}}=\frac{\text{Total Deposites}}{\text{Reserves}}$$
正因如此，在准备金不变时，我们可以直接认为货币乘数和货币量成正比

### 4.3 Bank Capital & Leverage
以书中所给出的资产负债表为例：
![[national_bank_balance_sheet_example.png]]
如图可知，这家银行的总资产 (assets) 是$\$1000$，其中包括储备金$\$200$，贷款$\$700$和有价证券$\$100$；另一方面，在负债和所有者权益 (liabilities and owner's equity) 中，可以看到其资本只有$\$50$，剩余部分中的存款和债务各占大头。

杠杆率：**资产 (assets) 与银行真正所拥有的资本 (capital) 的比率**；与此同时，这种资本也可以被视作是银行所有人的equity
首先得出杠杆率的计算公式
$$\text{Leverage Ratio}=\frac{\text{Total Assets}}{\text{Capital}}$$
例如，对这个例子而言，杠杆率就是$\frac{\$1000}{\$50}=20$
这意味着资产增值$n\%$会直接令所有者的equity增加$20n\%$，反之，资产的贬值则很有可能会直接出现资不抵债的情况
正因如此，银行管制者才会要求银行一定要持有一定量的资本，即**资本需要量 (capital requirement)**，以令其能够在一定程度下能够偿还储户的存款

### 4.4 Monetary Control of the Federal Reserve System
美联储主要有两项工作：
1. 管制银行，确保银行体系正常运行。这主要由地区联邦储备银行负责
2. **控制货币供给 (money supply)**：这主要通过买卖政府债券。从公众手上购买债券来增加货币供给，反之，出售债券则减少货币供给。
依靠控制货币量的方式，美联储会对长期内的通货膨胀率和短期内的失业率造成重要影响

美联储的货币管制手段：
1. 公开市场操作 (open-market operations)：正如上文所言，美联储通过买卖政府债券增加或减少货币供给
2. 给银行发放贷款 (Fed Lending to Banks)：银行用美联储的贷款增加准备金量，从而继续用这笔钱增加贷款。**这笔贷款的利率是discount rate（贴现率）**。美联储**通过调整贴现率来控制准备金量和货币供给量**。贴现率越低，准备金越多（但不会直接影响准备金率），货币供给量越多

美联储影响银行持有准备金意愿的手段：
1. 法定准备金 (reserve requirements)：法定准备金规定了银行所必须持有的最低准备金量。**法定准备金增加则提高准备金率，从而降低货币乘数，减少货币供给**。这种方案可能会干扰银行经营。
$$\text{Reserve Ratio}\uparrow=\frac{\text{Reserves}\uparrow}{\text{Total Deposites}}\times 100\%$$
$$\text{Money Multiplier}\downarrow=\frac{1}{\text{Reserve Ratio}\uparrow}$$
2. 支付准备金利息 (Interest on Reserves)：通过向银行的准备金支付利息的方式来鼓励银行持有更多准备金。如果成功令储备金率上升，那么货币乘数会下降，于是货币供给减少。

无论如何，都应当意识到以上所有这些调整货币量的手段**都无法调整社会的储蓄率**（关于总储蓄和总投资的关系$S=I$，见[[IMP Saving,Investment, and the Financial System]]）。假如出现了银行挤兑，那么存款量减少而货币量减少，与此同时，银行为了具有偿付能力则会提升准备金率，从而进一步减少货币量。银行挤兑就是在这两个方面减少总货币量，最终造成通货紧缩。

## 5. 补充：the Federal Funds Rate
前文所提及的discount rate为联邦基金率设定了标准，它们有着较强的关联
联邦基金利率是**银行互相贷款时**收取的短期利率