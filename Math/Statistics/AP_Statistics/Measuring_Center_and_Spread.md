---
title: Measuring Center and Spread
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Measuring Center and Spread

> **Summary statistics compress a distribution into a few numbers. Choose wisely, because they can mislead as much as they inform.**

Part of: [[AP_Statistics_MOC]].

## Measures of Center

### Mean

The **arithmetic mean** (average) is the sum of observations divided by the count.

**Sample mean:**
$$\bar{x} = \frac{\sum_{i=1}^{n} x_i}{n} = \frac{x_1 + x_2 + \cdots + x_n}{n}$$

**Population mean:**
$$\mu = \frac{\sum_{i=1}^{N} x_i}{N}$$

The mean is the **balance point** of the distribution — if you placed the data on a number line as physical weights, the mean is the fulcrum point where the line would balance.

The mean is **not resistant**. A single extreme value can dramatically shift it.

**Example:** The dataset $\{4, 5, 6, 7, 100\}$ has $\bar{x} = 24.4$, even though four of the five values are below 8. The mean fails to represent the "typical" observation.

### Median

The **median** is the midpoint: half the observations lie below it, half above. To find it:

1. Order the data from smallest to largest.
2. If $n$ is odd: median = the middle value at position $\frac{n+1}{2}$.
3. If $n$ is even: median = the average of the two middle values at positions $\frac{n}{2}$ and $\frac{n}{2} + 1$.

The median is **resistant**. For $\{4, 5, 6, 7, 100\}$, the median is 6 — a much better summary of the typical value.

### Mode

The **mode** is the most frequently occurring value. Distributions can be:

- **Unimodal** (one mode), **bimodal** (two), or **multimodal** (many).
- A distribution with no repeated values has **no mode**.
- The mode is the only appropriate measure of center for **categorical** data.

### Choosing Between Mean and Median

| Situation | Recommended |
|:---|:---|
| Symmetric, no outliers | Mean |
| Skewed or outliers present | Median |
| Categorical data | Mode |

> [!warning] Always Pair Correctly
> When reporting center and spread as a pair, report **mean with standard deviation** OR **median with IQR**. Never mix: "the mean is 72 with an IQR of 8" is incoherent because the IQR describes the middle 50%, not the average spread around the mean.

## Measures of Spread

### Range

$$\text{Range} = \max - \min$$

The range uses only two observations and is extremely **sensitive to outliers**. A single extreme value can make the range enormous. Rarely used as the sole measure of spread.

### Interquartile Range (IQR)

The IQR is the spread of the middle half of the data:

$$\text{IQR} = Q_3 - Q_1$$

- $Q_1$ is the **first quartile** (25th percentile): the median of the lower half of the data.
- $Q_3$ is the **third quartile** (75th percentile): the median of the upper half of the data.
- The IQR is **resistant** — outliers do not affect it.

**Finding quartiles:** After ordering the data, locate the median. Then find the median of the values below the overall median ($Q_1$) and above the overall median ($Q_3$). The overall median is not included in either half.

### Variance and Standard Deviation

**Variance** measures the average squared deviation from the mean.

**Sample variance:**
$$s^2 = \frac{\sum_{i=1}^{n} (x_i - \bar{x})^2}{n-1}$$

**Population variance:**
$$\sigma^2 = \frac{\sum_{i=1}^{N} (x_i - \mu)^2}{N}$$

Why divide by $n-1$ for the sample? This **Bessel's correction** makes $s^2$ an unbiased estimator of the population variance $\sigma^2$. Using $n$ would systematically underestimate the true variance.

**Standard deviation** is the square root of the variance:

$$s = \sqrt{s^2} = \sqrt{\frac{\sum_{i=1}^{n} (x_i - \bar{x})^2}{n-1}}$$

Standard deviation is measured in the **original units** of the data (unlike variance, which is in squared units). This makes $s$ the natural companion to the mean.

**Properties of $s$:**

- $s \geq 0$. $s = 0$ only when all observations are identical.
- $s$ is strongly affected by outliers (non-resistant).
- $s$ has the same units as the original data.
- Adding a constant to every observation does not change $s$. Multiplying every observation by a constant multiplies $s$ by the absolute value of that constant.

### Numerical Example

Consider the dataset: $\{2, 4, 6, 8, 10\}$

$$\bar{x} = \frac{2+4+6+8+10}{5} = 6$$

$$s^2 = \frac{(2-6)^2 + (4-6)^2 + (6-6)^2 + (8-6)^2 + (10-6)^2}{5-1} = \frac{16 + 4 + 0 + 4 + 16}{4} = 10$$

$$s = \sqrt{10} \approx 3.162$$

$$\text{Median} = 6, \quad Q_1 = 3, \quad Q_3 = 9, \quad \text{IQR} = 6$$

## Summary Table: Resistant vs. Non-Resistant

| Statistic | Resistant? | Best Used With |
|:---|:---:|:---|
| Mean $\bar{x}$ | No | Standard deviation |
| Median | **Yes** | IQR |
| Mode | **Yes** | Categorical analysis |
| Range | No | Quick descriptive |
| IQR | **Yes** | Median, boxplots |
| Standard Deviation $s$ | No | Mean, normal models |
| Variance $s^2$ | No | Theoretical derivations |

**Related:** [[Describing_Distributions]] | [[Unit_1_One-Variable_Data]] | [[Normal_Distributions]]
