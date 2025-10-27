---
tags:
  - Math
  - Calculus
  - Economics
  - 证明
title: MC函数与ATC函数相切的解释
created: 2025-10-27T11:09:00
modified:
---
# MC函数与ATC函数相切的解释
MC与ATC相切时，**企业经济零利润**，所以
![[monopolistic_competitor_in_long_run.png]]
$$P_{max}=ATC(Q_{max})$$
$$MC(Q_{max})=MR(Q_{max})$$
另一方面，根据需求曲线，也可以得出$Demand(Q_{max})=P_{max}$
说明此时也有
$$Demand(Q_{max})=ATC(Q_{max})$$
因为
$$ATC=\frac{TC}{Q}$$
---

所以开始计算需求函数和平均总成本函数在$Q_{max}$上的斜率
$$\frac{dATC}{dQ}=\frac{d}{dQ}(\frac{TC}{Q})$$
考虑到
$$MC=\frac{dTC}{dQ}$$
利用[[differentiation]]中的product rule求导
$$\frac{d}{dQ}(\frac{TC}{Q})=\frac{MC(Q)\times Q-TC(Q)}{Q^2}$$
$$\lim_{Q\to Q_{max}}\frac{dATC(Q)}{dQ}=\frac{MC(Q_{max})\times Q_{max}-TC(Q_{max})}{Q_{max}^2}$$
由于
$$P(Q_{max})=ATC(Q_{max})=\frac{TC(Q_{max})}{Q_{max}}$$
$$TC(Q_{max})=P(Q_{max})\times Q_{max}$$
带入进求导式
$$\lim_{Q\to Q_{max}}\frac{dATC}{dQ}=\frac{MC(Q_{max})\times Q_{max}-P(Q_{max})\times Q_{max}}{Q_{max}^2}$$
最终得到平均总成本函数在$Q_{max}$上的导数的最简式
$$\lim_{Q\to Q_{max}}\frac{dATC}{dQ}=\frac{MC(Q_{max})-P(Q_{max})}{Q_{max}}$$
而正如前文所言，在$Q_{max}$上$MC(Q_{max})=MR(Q_{max})$
$$\lim_{Q\to Q_{max}}\frac{dATC}{dQ}=\frac{MR(Q_{max})-P(Q_{max})}{Q_{max}}$$

---

另一方面，来看需求函数的斜率
$$\lim_{Q\to Q_{max}}\frac{dP}{dQ}=\frac{P'Q_{max}-Q_{max}'P}{Q_{max}^2}$$
根据[[Consideration of Marginal Changes]]和[[MR = Price Effect + Output Effect]]：
$$MR=\frac{TR}{Q}=Q\times\frac{dP}{dQ}+P$$
在$Q_{max}$这点上：
$$MR(Q_{max})=Q_{max}\times\lim_{Q\to Q_{max}}\frac{dP(Q_{max})}{dQ_{max}}+P(Q_{max})$$
整理后易得出需求函数的斜率
$$\Rightarrow\lim_{Q\to Q_{max}}\frac{dP(Q)}{dQ}=\frac{MR(Q_{max})-P(Q_{max})}{Q_{max}}$$
---

最后我们能发现在$Q_{max}$上，$ATC$和需求曲线的斜率相同，且它们都交与一点$(Q_{max},P_{max})$上：
$$\frac{dATC(Q_{max})}{dQ_{max}}=\frac{dP(Q_{max})}{dQ_{max}}=\frac{MR(Q_{max})-P(Q_{max})}{Q_{max}}$$
所以**它们的图象必定会在经济零利润且边际利润为零时相切**
