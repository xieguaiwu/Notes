---
title: AP Statistics Formula Sheet
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

# AP 统计学公式速查表

> 考前快速参考总公式表。完整课程地图见 [[AP_Statistics_MOC]]。

## 1. 描述性统计

**中心度量**
$$\bar{x} = \frac{\sum x}{n} \qquad \text{（样本均值）}$$
$$\text{中位数} = \text{排序后的中间值（或两个中间值的平均）}$$

**离散程度度量**
$$s = \sqrt{\frac{\sum (x-\bar{x})^2}{n-1}} \qquad \text{（样本标准差）}$$
$$s^2 = \frac{\sum (x-\bar{x})^2}{n-1} \qquad \text{（样本方差）}$$
$$IQR = Q_3 - Q_1 \qquad \text{（四分位距）}$$

**位置与标准化**
$$z = \frac{x-\mu}{\sigma} \qquad \text{（z 分数——距均值多少标准差）}$$
$$\text{百分位数：} \leq \text{该值的数据比例}$$

**相关与回归**
$$r = \frac{1}{n-1}\sum\left(\frac{x-\bar{x}}{s_x}\right)\!\left(\frac{y-\bar{y}}{s_y}\right) \qquad \text{（相关系数）}$$
$$\hat{y} = b_0 + b_1x \qquad \text{（最小二乘回归线）}$$
$$b_1 = r\frac{s_y}{s_x} \qquad \text{（斜率）}$$
$$b_0 = \bar{y} - b_1\bar{x} \qquad \text{（截距）}$$
$$r^2 = \text{决定系数} \quad \text{（被解释的方差比例）}$$
$$s_e = \sqrt{\frac{\sum (y-\hat{y})^2}{n-2}} \qquad \text{（回归标准误）}$$

## 2. 概率

**基本法则**
$$P(A^c) = 1 - P(A)$$
$$P(A \cup B) = P(A) + P(B) - P(A \cap B)$$
$$P(A \cap B) = P(A)P(B|A) \qquad \text{（一般乘法）}$$
$$P(A \cap B) = P(A)P(B) \qquad \text{（独立时）}$$
$$P(A|B) = \frac{P(A \cap B)}{P(B)}$$

**全概率公式与贝叶斯**
$$P(B) = P(B|A)P(A) + P(B|A^c)P(A^c)$$
$$P(A|B) = \frac{P(B|A)P(A)}{P(B)}$$

**随机变量**
$$\mu_X = E[X] = \sum x \cdot P(X=x) \qquad \text{（离散均值）}$$
$$\sigma_X^2 = \sum (x-\mu_X)^2 \cdot P(X=x) \qquad \text{（离散方差）}$$
$$E[aX+b] = aE[X] + b$$
$$Var(aX+b) = a^2 Var(X)$$
$$E[X \pm Y] = E[X] \pm E[Y]$$
$$Var(X \pm Y) = Var(X) + Var(Y) \pm 2Cov(X,Y) \quad \text{（独立时: } \pm 2Cov = 0)$$

**二项分布** $X \sim B(n,p)$
$$P(X=k) = \binom{n}{k}p^k(1-p)^{n-k} \qquad k = 0,1,\dots,n$$
$$\mu_X = np \qquad \sigma_X = \sqrt{np(1-p)}$$
$$\text{形状：} p<0.5 \text{ 右偏, } p>0.5 \text{ 左偏, } p=0.5 \text{ 对称}$$

**几何分布** $X \sim G(p)$
$$P(X=k) = (1-p)^{k-1}p \qquad k = 1,2,\dots$$
$$\mu_X = \frac{1}{p} \qquad \sigma_X = \frac{\sqrt{1-p}}{p}$$

**正态分布** $X \sim N(\mu,\sigma)$
$$z = \frac{x-\mu}{\sigma} \qquad \text{标准化为 } N(0,1)$$
$$68\text{-}95\text{-}99.7\ \text{法则：} \mu \pm \sigma \approx 68\%, \ \mu \pm 2\sigma \approx 95\%, \ \mu \pm 3\sigma \approx 99.7\%$$

## 3. 抽样分布

**比例** $\hat{p}$
$$\mu_{\hat{p}} = p$$
$$\sigma_{\hat{p}} = \sqrt{\frac{p(1-p)}{n}}$$
$$\text{条件：随机、独立（10%）、} np \ge 10,\ n(1-p) \ge 10$$

**均值** $\bar{x}$
$$\mu_{\bar{x}} = \mu$$
$$\sigma_{\bar{x}} = \frac{\sigma}{\sqrt{n}}$$
$$\text{条件：随机、独立（10%）、} n \ge 30 \text{ 或总体正态}$$

**中心极限定理（CLT）：** 随着 $n$ 增大，$\bar{x}$ 的抽样分布趋近正态分布（与总体形状无关）。

## 4. 推断——比例

**单比例**
$$CI: \ \hat{p} \pm z^*\sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$$
$$z\text{ 检验：} \ z = \frac{\hat{p}-p_0}{\sqrt{\frac{p_0(1-p_0)}{n}}}$$
$$n = \left(\frac{z^*}{m}\right)^2 \hat{p}^*(1-\hat{p}^*) \qquad \text{（规划样本量）}$$

**双比例** $p_1 - p_2$
$$CI: \ (\hat{p}_1-\hat{p}_2) \pm z^*\sqrt{\frac{\hat{p}_1(1-\hat{p}_1)}{n_1} + \frac{\hat{p}_2(1-\hat{p}_2)}{n_2}}$$
$$z\text{ 检验：} \ z = \frac{\hat{p}_1-\hat{p}_2}{\sqrt{\hat{p}_c(1-\hat{p}_c)\left(\frac{1}{n_1}+\frac{1}{n_2}\right)}} \qquad \hat{p}_c = \frac{\text{总成功数}}{\text{总 }n}$$

## 5. 推断——均值

**单均值**（$\sigma$ 未知时用 $t$ 分布）
$$CI: \ \bar{x} \pm t^*\frac{s}{\sqrt{n}} \qquad df = n-1$$
$$t\text{ 检验：} \ t = \frac{\bar{x}-\mu_0}{s/\sqrt{n}} \qquad df = n-1$$

**双均值**（独立）$\mu_1-\mu_2$
$$CI: \ (\bar{x}_1-\bar{x}_2) \pm t^*\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}$$
$$t\text{ 检验：} \ t = \frac{\bar{x}_1-\bar{x}_2}{\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}}$$
$$df = \text{Satterthwaite（保守取 min}(n_1-1,n_2-1))$$

**配对**（配对 $t$ 检验）
$$CI: \ \bar{x}_d \pm t^*\frac{s_d}{\sqrt{n}} \qquad df = n-1$$
$$t\text{ 检验：} \ t = \frac{\bar{x}_d}{s_d/\sqrt{n}} \qquad df = n-1$$

## 6. 卡方检验

**卡方检验统计量**
$$\chi^2 = \sum\frac{(O-E)^2}{E}$$

**拟合优度**
$$df = k-1 \qquad \text{（类别数减 1）}$$
$$E_i = n \cdot p_i \qquad \text{（} H_0 \text{ 下的期望计数）}$$

**齐性 / 独立性**
$$df = (R-1)(C-1) \qquad \text{（行数减 1）（列数减 1）}$$
$$E_{ij} = \frac{(\text{行 }i\text{ 合计})(\text{列 }j\text{ 合计})}{n}$$

**条件：** 随机样本、所有 $E \ge 5$（期望计数）、观测独立

## 7. 斜率推断（线性回归）

**斜率 $\beta_1$**
$$t = \frac{b_1 - \beta_{10}}{SE_{b_1}} \qquad df = n-2$$
$$CI: \ b_1 \pm t^* \cdot SE_{b_1} \qquad df = n-2$$
$$SE_{b_1} = \frac{s_e}{\sqrt{\sum (x-\bar{x})^2}} = \frac{\sqrt{\frac{\sum(y-\hat{y})^2}{n-2}}}{\sqrt{\sum(x-\bar{x})^2}}$$

**条件：** 线性关系、残差独立、方差齐性、残差正态（或 $n \ge 30$）

## 8. 条件速查表

| 程序 | 随机？ | 10%？ | 正态性？ |
|-----------|---------|------|------------|
| 单比例 $z$ | ✅ SRS | ✅ $n \le 0.1N$ | ✅ $np_0 \ge 10,\ n(1-p_0) \ge 10$ |
| 双比例 $z$ | ✅ SRS | ✅ 两者 | ✅ 检验：各 $n_i\hat{p}_c \ge 10,\ n_i(1-\hat{p}_c) \ge 10$；CI：各 $n_i\hat{p}_i \ge 10,\ n_i(1-\hat{p}_i) \ge 10$ |
| 单均值 $t$ | ✅ SRS | ✅ $n \le 0.1N$ | ✅ $n \ge 30$ 或总体正态或无强偏斜/离群值 |
| 双均值 $t$ | ✅ SRS | ✅ 两者 | ✅ 两者 $\ge 30$ 或总体正态或无偏斜/离群值 |
| 配对 $t$ | ✅ 随机分配/配对 | — | ✅ $n_d \ge 30$ 或差值总体正态 |
| $\chi^2$ 拟合优度 | ✅ 随机 | — | ✅ 所有 $E \ge 5$ |
| $\chi^2$ 齐性/独立 | ✅ SRS | — | ✅ 所有 $E \ge 5$ |
| 斜率 $t$ | ✅ 随机 | — | ✅ 线性、方差齐性、残差正态 |

## 9. 错误与检验力速查

$$\alpha = P(\text{第一类错误}) = \text{显著性水平}$$
$$\beta = P(\text{第二类错误})$$
$$\text{检验力} = 1-\beta = P(\text{拒绝 } H_0 \mid H_0 \text{ 为假})$$

| 提高检验力的方法 | 机制 |
|----------------------|-----------|
| ↑ 样本量 $n$ | ↓ 标准误 |
| ↑ 显著性水平 $\alpha$ | 更宽的拒绝域 |
| ↑ 效应量（真实差异） | 更大的分离度 |
| ↓ 变异（更好的设计） | ↓ 标准误 |

---

*修订：2026-06-14 — [[AP_Statistics_MOC]]*