---
title: Random Variables
tags:
  - Statistics
  - 概念性
created: 2026-06-14
---

## Random Variables

A **random variable** is a numerical outcome of a random phenomenon. Instead of describing every possible outcome of a sample space in words, we assign a number to each outcome and analyze its distribution.

### Discrete vs. Continuous Random Variables

| Type | Values | Probability Assignment |
|------|--------|----------------------|
| **Discrete** | Countable set (e.g., 0, 1, 2, ...) | Lists probabilities for each value: $P(X = x)$ |
| **Continuous** | Any value in an interval | Describes density; $P(X = x) = 0$ for any single point |

For discrete random variables, the **probability distribution** (or probability mass function) lists all possible values and their probabilities:

| $x$ | 0 | 1 | 2 | 3 |
|-----|---|---|---|---|
| $P(X=x)$ | 0.125 | 0.375 | 0.375 | 0.125 |

**Requirements for a valid discrete probability distribution:**
1. $0 \leq P(X = x) \leq 1$ for every value $x$
2. $\sum P(X = x) = 1$

### Expected Value (Mean) of a Discrete Random Variable

The expected value $E(X)$ or $\mu_X$ is the long-run average:

$$
E(X) = \mu_X = \sum x \cdot P(X = x)
$$

Multiply each value by its probability, then sum. This is a weighted average — values with higher probability contribute more.

> [!tip] Interpretation
> $E(X)$ is what we "expect" on average over many, many repetitions. It does not need to be a possible value of $X$. For example, the expected value of a fair die roll is 3.5, which is not a possible outcome.

### Variance and Standard Deviation

The variance measures the average squared deviation from the mean:

$$
\text{Var}(X) = \sigma_X^2 = \sum (x - \mu_X)^2 \cdot P(X = x)
$$

**Computational shortcut** (often easier):

$$
\text{Var}(X) = \left(\sum x^2 \cdot P(X = x)\right) - \mu_X^2
$$

The standard deviation is the square root: $\sigma_X = \sqrt{\text{Var}(X)}$.

### Linear Transformations of Random Variables

If $Y = a + bX$, where $a$ and $b$ are constants:

**Mean:**
$$
\mu_Y = E(a + bX) = a + b \cdot \mu_X
$$

**Variance:**
$$
\sigma_Y^2 = \text{Var}(a + bX) = b^2 \cdot \sigma_X^2
$$

**Standard deviation:**
$$
\sigma_Y = |b| \cdot \sigma_X
$$

> [!warning] Adding a Constant
> Adding $a$ shifts the mean by $a$ but has **no effect** on the variance or standard deviation. Only multiplication by $b$ changes the spread.

### Combining Independent Random Variables

For independent random variables $X$ and $Y$, and constants $a$, $b$:

**Mean of a sum or difference:**
$$
E(X \pm Y) = E(X) \pm E(Y) = \mu_X \pm \mu_Y
$$

**General linear combination:**
$$
E(aX + bY) = a\mu_X + b\mu_Y
$$

**Variance of a sum or difference** (independence required for these):

$$
\text{Var}(X \pm Y) = \text{Var}(X) + \text{Var}(Y) = \sigma_X^2 + \sigma_Y^2
$$

> [!danger] Extremely Important
> The variance of a sum is the sum of the variances — **always addition**, even for $X - Y$. The formula is $\sigma_X^2 + \sigma_Y^2$, not $\sigma_X^2 - \sigma_Y^2$.

**General linear combination:**
$$
\text{Var}(aX + bY) = a^2\sigma_X^2 + b^2\sigma_Y^2
$$

### Continuous Random Variables

For a continuous random variable, probability is represented by the area under a **probability density curve**. The total area is exactly 1. The probability that $X$ falls in an interval $[a, b]$ is:

$$
P(a \leq X \leq b) = \int_a^b f(x) \, dx
$$

The mean and variance are defined analogously using integrals instead of sums. The **normal distribution** is the most important continuous distribution — it is the foundation of inference.

### Why Random Variables Matter

Every statistic we compute — $\bar{x}$, $\hat{p}$, $s$, the slope of a regression line — is itself a random variable when the data come from a random sample. Understanding their probability distributions enables us to quantify uncertainty through confidence intervals and significance tests.

---
Related: [[Unit_4_Probability]] | [[Binomial_and_Geometric_Distributions]] | [[AP_Statistics_MOC]]
