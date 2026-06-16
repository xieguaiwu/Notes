---
title: AP Statistics Formula Sheet
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

# AP Statistics Formula Sheet

> Quick-reference master formula sheet for exam review. See [[AP_Statistics_MOC]] for the full curriculum map.

---

## 1. Descriptive Statistics

**Measures of Center**
$$x̄ = \frac{\sum x}{n} \qquad \text{(sample mean)}$$
$$\text{Median} = \text{middle value (or avg of two middle values)}$$

**Measures of Spread**
$$s = \sqrt{\frac{\sum (x-x̄)^2}{n-1}} \qquad \text{(sample standard deviation)}$$
$$s^2 = \frac{\sum (x-x̄)^2}{n-1} \qquad \text{(sample variance)}$$
$$IQR = Q_3 - Q_1 \qquad \text{(interquartile range)}$$

**Position & Standardization**
$$z = \frac{x-μ}{σ} \qquad \text{(z-score — how many SDs from mean)}$$
$$\text{Percentile rank: proportion of data ≤ that value}$$

**Correlation & Regression**
$$r = \frac{1}{n-1}\sum\left(\frac{x-x̄}{s_x}\right)\!\left(\frac{y-ȳ}{s_y}\right) \qquad \text{(correlation coefficient)}$$
$$ŷ = b_0 + b_1x \qquad \text{(least-squares regression line)}$$
$$b_1 = r\frac{s_y}{s_x} \qquad \text{(slope)}$$
$$b_0 = ȳ - b_1x̄ \qquad \text{(intercept)}$$
$$r^2 = \text{coefficient of determination} \quad \text{(fraction of variance explained)}$$
$$s_e = \sqrt{\frac{\sum (y-ŷ)^2}{n-2}} \qquad \text{(standard error of the regression)}$$

---

## 2. Probability

**Basic Rules**
$$P(A^c) = 1 - P(A)$$
$$P(A \cup B) = P(A) + P(B) - P(A \cap B)$$
$$P(A \cap B) = P(A)P(B|A) \qquad \text{(general multiplication)}$$
$$P(A \cap B) = P(A)P(B) \qquad \text{if independent}$$
$$P(A|B) = \frac{P(A \cap B)}{P(B)}$$

**Law of Total Probability & Bayes**
$$P(B) = P(B|A)P(A) + P(B|A^c)P(A^c)$$
$$P(A|B) = \frac{P(B|A)P(A)}{P(B)}$$

**Random Variables**
$$μ_X = E[X] = \sum x·P(X=x) \qquad \text{(discrete mean)}$$
$$σ_X^2 = \sum (x-μ_X)^2·P(X=x) \qquad \text{(discrete variance)}$$
$$E[aX+b] = aE[X] + b$$
$$Var(aX+b) = a^2 Var(X)$$
$$E[X \pm Y] = E[X] \pm E[Y]$$
$$Var(X \pm Y) = Var(X) + Var(Y) \pm 2Cov(X,Y) \quad \text{(independent: } \pm 2Cov = 0)$$

**Binomial Distribution** $X \sim B(n,p)$
$$P(X=k) = \binom{n}{k}p^k(1-p)^{n-k} \qquad k = 0,1,\dots,n$$
$$μ_X = np \qquad σ_X = \sqrt{np(1-p)}$$
$$\text{Shape: right-skew if } p<0.5,\text{ left-skew if } p>0.5,\text{ symmetric if } p=0.5$$

**Geometric Distribution** $X \sim G(p)$
$$P(X=k) = (1-p)^{k-1}p \qquad k = 1,2,\dots$$
$$μ_X = \frac{1}{p} \qquad σ_X = \frac{\sqrt{1-p}}{p}$$

**Normal Distribution** $X \sim N(μ,σ)$
$$z = \frac{x-μ}{σ} \qquad \text{standardize to } N(0,1)$$
$$68\text{-}95\text{-}99.7\ \text{Rule: } μ \pm σ \approx 68\%, \ μ \pm 2σ \approx 95\%, \ μ \pm 3σ \approx 99.7\%$$

---

## 3. Sampling Distributions

**Proportions** $p̂$
$$μ_{p̂} = p$$
$$σ_{p̂} = \sqrt{\frac{p(1-p)}{n}}$$
$$\text{Conditions: random, independent (10\%), } np \ge 10,\ n(1-p) \ge 10$$

**Means** $x̄$
$$μ_{x̄} = μ$$
$$σ_{x̄} = \frac{σ}{\sqrt{n}}$$
$$\text{Conditions: random, independent (10\%), } n \ge 30\ \text{or population normal}$$

**Central Limit Theorem (CLT):** As $n$ grows, the sampling distribution of $x̄$ approaches a normal distribution (regardless of the population shape).

---

## 4. Inference — Proportions

**One Proportion**
$$CI: \ p̂ \pm z^*\sqrt{\frac{p̂(1-p̂)}{n}}$$
$$z\text{-test: } \ z = \frac{p̂-p_0}{\sqrt{\frac{p_0(1-p_0)}{n}}}$$
$$n = \left(\frac{z^*}{m}\right)^2 p̂^*(1-p̂^*) \qquad \text{(planning sample size)}$$

**Two Proportions** $p_1 - p_2$
$$CI: \ (p̂_1-p̂_2) \pm z^*\sqrt{\frac{p̂_1(1-p̂_1)}{n_1} + \frac{p̂_2(1-p̂_2)}{n_2}}$$
$$z\text{-test: } \ z = \frac{p̂_1-p̂_2}{\sqrt{p̂_c(1-p̂_c)\left(\frac{1}{n_1}+\frac{1}{n_2}\right)}} \qquad p̂_c = \frac{\text{total successes}}{\text{total }n}$$

---

## 5. Inference — Means

**One Mean** (use $t$-distribution when $σ$ unknown)
$$CI: \ x̄ \pm t^*\frac{s}{\sqrt{n}} \qquad df = n-1$$
$$t\text{-test: } \ t = \frac{x̄-μ_0}{s/\sqrt{n}} \qquad df = n-1$$

**Two Means** (independent) $μ_1-μ_2$
$$CI: \ (x̄_1-x̄_2) \pm t^*\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}$$
$$t\text{-test: } \ t = \frac{x̄_1-x̄_2}{\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}}$$
$$df = \text{Satterthwaite (min}(n_1-1,n_2-1)\ \text{is conservative)}$$

**Matched Pairs** (paired $t$-test)
$$CI: \ x̄_d \pm t^*\frac{s_d}{\sqrt{n}} \qquad df = n-1$$
$$t\text{-test: } \ t = \frac{x̄_d}{s_d/\sqrt{n}} \qquad df = n-1$$

---

## 6. Chi-Square Tests

**Chi-Square Test Statistic**
$$χ^2 = \sum\frac{(O-E)^2}{E}$$

**Goodness of Fit**
$$df = k-1 \qquad \text{(number of categories minus 1)}$$
$$E_i = n·p_i \qquad \text{(expected count under } H_0)$$

**Homogeneity / Independence**
$$df = (R-1)(C-1) \qquad \text{(rows minus 1)(cols minus 1)}$$
$$E_{ij} = \frac{(\text{row }i\text{ total})(\text{col }j\text{ total})}{n}$$

**Conditions:** random sample, all $E \ge 5$ (expected counts), independent observations

---

## 7. Inference for Slope (Linear Regression)

**Slope $β_1$**
$$t = \frac{b_1 - β_{10}}{SE_{b_1}} \qquad df = n-2$$
$$CI: \ b_1 \pm t^*·SE_{b_1} \qquad df = n-2$$
$$SE_{b_1} = \frac{s_e}{\sqrt{\sum (x-x̄)^2}} = \frac{\sqrt{\frac{\sum(y-ŷ)^2}{n-2}}}{\sqrt{\sum(x-x̄)^2}}$$

**Conditions:** linear relationship, independent residuals, constant variance, normal residuals (or $n \ge 30$)

---

## 8. Conditions Quick-Check Table

| Procedure | Random? | 10%? | Normality? |
|-----------|---------|------|------------|
| 1-proportion $z$ | ✅ SRS | ✅ $n \le 0.1N$ | ✅ $np_0 \ge 10,\ n(1-p_0) \ge 10$ |
| 2-proportion $z$ | ✅ SRS | ✅ both | ✅ Test: $n_i\hat{p}_c \ge 10,\ n_i(1-\hat{p}_c) \ge 10$ each; CI: $n_i\hat{p}_i \ge 10,\ n_i(1-\hat{p}_i) \ge 10$ each |
| 1-mean $t$ | ✅ SRS | ✅ $n \le 0.1N$ | ✅ $n \ge 30$ or pop. normal or no strong skew/outliers |
| 2-mean $t$ | ✅ SRS | ✅ both | ✅ both $\ge 30$ or pop. normal or no skew/outliers |
| Matched pairs $t$ | ✅ random assignment/pairs | — | ✅ $n_d \ge 30$ or diff. pop. normal |
| $χ^2$ GOF | ✅ random | — | ✅ all $E \ge 5$ |
| $χ^2$ homogeneity/indep | ✅ SRS | — | ✅ all $E \ge 5$ |
| Slope $t$ | ✅ random | — | ✅ linear, constant var., normal residuals |

---

## 9. Error & Power Quick Reference

$$α = P(\text{Type I error}) = \text{significance level}$$
$$β = P(\text{Type II error})$$
$$\text{Power} = 1-β = P(\text{reject } H_0 \mid H_0 \text{ false})$$

| Increase power by... | Mechanism |
|----------------------|-----------|
| ↑ sample size $n$ | ↓ standard error |
| ↑ significance level $α$ | wider rejection region |
| ↑ effect size (true diff) | greater separation |
| ↓ variability (better design) | ↓ standard error |

---

*Revision: 2026-06-14 — [[AP_Statistics_MOC]]*
