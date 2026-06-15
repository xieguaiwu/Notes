---
title: Normal Distributions
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Normal Distributions

> **Density Curves → Normal Curves → Standard Normal → z-Scores → Probability**

The normal distribution is the most important continuous probability model in statistics. Many natural phenomena are approximately normal; more critically, the **Central Limit Theorem** guarantees that sample means tend toward normality regardless of the population shape.

Part of: [[AP_Statistics_MOC]].

## Density Curves

A **density curve** is a smooth curve that describes the overall pattern of a distribution. It must satisfy:

1. Always on or above the horizontal axis: $f(x) \geq 0$ for all $x$.
2. Total area under the curve equals exactly 1: $\int_{-\infty}^{\infty} f(x)\,dx = 1$.

The **median** of a density curve is the equal-areas point (50% to the left, 50% to the right). The **mean** is the balance point — in a symmetric density curve, mean = median.

## Properties of the Normal Curve

A **Normal distribution** $N(\mu, \sigma)$ is a density curve with these properties:

- **Symmetric** and **bell-shaped**.
- **Unimodal** — the peak occurs at the mean $\mu$.
- **Mean = Median = Mode** at the center.
- The **standard deviation** $\sigma$ controls the spread. Larger $\sigma$ → flatter and wider curve.
- The curve approaches but never touches the horizontal axis (asymptotic).
- **Inflection points** occur at $\mu \pm \sigma$ — this is where the curvature changes direction.

The probability density function is:

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}\, e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

You will never need to compute this by hand on the AP exam. Instead, use the **Empirical Rule** and **z-scores**.

## The Empirical Rule (68–95–99.7 Rule)

For data that are approximately normal:

| Interval | Approximate Proportion |
|:---|:---:|
| $\mu \pm 1\sigma$ | **68%** |
| $\mu \pm 2\sigma$ | **95%** |
| $\mu \pm 3\sigma$ | **99.7%** |

```
        ┌─────────────────────────────────────────┐
        │           ┌─────────────────┐           │
        │           │     ┌─────┐     │           │
        │           │     │68%  │     │           │
        │           │     │     │     │           │
        │           │ 95% │     │ 95% │           │
        │           │     │     │     │           │
        │   99.7%   │     └─────┘     │   99.7%   │
        │           └─────────────────┘           │
        └─────────────────────────────────────────┘
       μ-3σ      μ-2σ     μ-σ     μ    μ+σ     μ+2σ    μ+3σ
```

### Applying the Rule: An Example

IQ scores are approximately $N(100, 15)$.

- 68% of people have IQs between **85 and 115**.
- 95% of people have IQs between **70 and 130**.
- 99.7% of people have IQs between **55 and 145**.
- What percentage have IQs above 130? Since 95% fall within $\pm 2\sigma$, the remaining 5% is split equally in the two tails: **2.5%** above 130.

## Standardizing with z-Scores

A **z-score** measures how many standard deviations an observation is from the mean:

$$z = \frac{x - \mu}{\sigma}$$

- $z = 0$ → the observation equals the mean.
- $z = +2$ → the observation is 2 standard deviations above the mean.
- $z = -1.5$ → the observation is 1.5 standard deviations below the mean.

z-scores have no units — they are **dimensionless**. This makes them useful for comparing values from different distributions (e.g., comparing an SAT math score to an ACT math score).

### The Standard Normal Distribution

When we transform any $N(\mu, \sigma)$ variable to z-scores, the resulting distribution is the **standard normal** $N(0, 1)$ with mean 0 and standard deviation 1.

To find the proportion of observations below a given value $x$:

1. Compute $z = \frac{x - \mu}{\sigma}$.
2. Look up the cumulative probability in the **Standard Normal Table** (Table A).
3. Interpret: the table gives the area to the **left** of $z$.

For areas to the **right**, use $1 - \text{table value}$.
For areas **between** two z-scores, subtract the smaller table value from the larger.

> [!tip] Which Table?
> The AP Stats formula sheet provides areas to the **left** of $z$. If you need the area to the right of $z = 1.25$, find the table entry for $z = 1.25$ (approximately 0.8944) and compute $1 - 0.8944 = 0.1056$.

### Checking the Standard Normal Table

Given $z = 1.00$, the table gives approximately 0.8413. This means about 84.13% of observations in a standard normal distribution fall below $z = 1.00$. Equivalently, $P(Z < 1.00) \approx 0.8413$.

## Assessing Normality

### Normal Probability (Quantile) Plots

A **normal probability plot** plots the sorted data against the **expected z-scores** they would have if the data were exactly normal.

- If the points fall roughly along a **straight diagonal line** → data are approximately normal.
- **Systematic curvature** (bending, S-shape) → data are not normal.
- No formal hypothesis test is required — judge by eye.

### Additional Checks

- Compare $\bar{x}$ and $s$ to the empirical rule expectations.
- Look for symmetry and unimodality in a histogram.
- Check for outliers (normal distributions have very few).

> [!important] Normality and Inference
> Many inference procedures (one-sample t-tests, ANOVA) assume that the **population** is normal. We check this assumption by examining the **sample** distribution. Even moderate departures from normality are often acceptable when $n$ is large, thanks to the Central Limit Theorem.

**Related:** [[Describing_Distributions]] | [[Measuring_Center_and_Spread]] | [[Unit_1_One-Variable_Data]]
