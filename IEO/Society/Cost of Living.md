---
tags:
  - WelfareEconomics
  - Economics
  - 定义性
  - Society
title: Cost of Living
created: 2025-10-30T12:59:00
modified:
---
# Cost of Living
与[[National Income]]中的**3.2**提及的通货膨胀率计算方法相比，consumer price index (CPI) 是更常用的通货膨胀衡量指标，因为它**能更好地反映消费者购买的物品和服务**。

## 1. Calculation of CPI
具体计算方法有以下几步：
1. 固定特定的商品/服务
2. 找到不同时间下这些商品/服务的价格
3. 计算费用
4. 选择基准年，计算指数
公式如下：
$$\text{CPI}=\frac{\text{Price of basket of goods and services in current year}}{\text{Price of basket in the base year}}\times 100$$

## 2. Calculate Inflation Rate with CPI
类似于[[National Income]]中的**3.2**：
$$\text{Inflation rate in year 2}=\frac{\text{CPI in year 2}-\text{CPI in year 1}}{\text{CPI in year 1}}\times 100$$
## 3. Problem With CPI
消费者物价指数有以下集中问题：
- Substitution Bias （替代偏向）：由于替代品效应（可以见[[IMP Price Elasticity of Demand]]），物价变化会改变对物品的需求量，**人们往往会直接对价格弹性高的物品选择替代品**，但统计时却仍旧以旧有的商品/服务作为统计对象，故最终**CPI衡量的生活成本增加大于实际增加**。
- Introduction of New Goods: 新商品的问世可能会增加消费者剩余，即以更小的成本达到与先前相同的生活水平，**但它们不会被统计入CPI中**，从而令CPI无法准确衡量消费者生活费用的变动
- Unmeasured Quality Change （无法衡量质量变化）

## 4. GDP Deflator  & CPI
GDP平减指数与消费者物价指数在衡量物价水平上有一些差别：
1. GDP反映国内生产的**所有物品/服务**的价格，**CPI只反映消费者购买的物品/服务的价格**
2. CPI只能体现固定种类的物品/服务价格，而GDP却只能体现现期生产的物品的价格，它们之间对不同商品的不同的加权方式会影响结果
下图有关美国经济的统计图体现了这种差别：
![[inflation_with_CPI_and_GDP.png]]

## 5. Dollar Figure
$$\text{Amount in today’s dollars}=\text{Amount in year T dollars}\times\frac{\text{Price Level Today}}{\text{Price Level in Year T}}$$

## 6. Indexation
vocab: indexation$\Leftrightarrow$指数化
正如费雪在《货币幻觉》中所说，indexation意味着根据CPI来根据物价调整工资

## 7. Real Interest Rates & Nominal Interest Rates
正因通货膨胀所造成的物价上涨，尽管储蓄账户所带来的利息会在名义上增加资产，但其购买力或许会因为物价上涨率高于利率而下降。故real interest rate的公式如下：
$$\text{Real interest rate}=\text{Nominal interest rate}-\text{Inflation rate}$$
下方关于美国经济的统计图能够体现这种差距：
![[nominal_and_real_interest_rate.png]]
