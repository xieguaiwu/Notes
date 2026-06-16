---
title: Describing Distributions
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Describing Distributions

> **Core Skill:** For any distribution of a quantitative variable, answer: *Shape, Center, Spread, Outliers.*

Every data display tells a story. The **SOCS** framework (or **SOCS + Context**) gives us a systematic vocabulary to describe what we see.

Part of: [[AP_Statistics_MOC]].

## Shape

Shape is the first and most visually immediate characteristic.

### Modality

- **Unimodal:** A single prominent peak.
- **Bimodal:** Two peaks, often indicating two subgroups. For example, a histogram of heights with both men and women may be bimodal.
- **Uniform:** Roughly flat; all values appear equally often.
- **Multimodal:** Three or more peaks.

> [!note] Multimodality and Stemplots
> Stemplots and histograms both reveal modality. Boxplots **do not** — never use a boxplot as your sole display when exploring data.

### Symmetry and Skew

- **Symmetric:** The left and right sides are approximate mirror images. In a perfectly symmetric distribution, $\text{mean} = \text{median}$.
- **Skewed right (positively skewed):** The right tail is longer. The mean is pulled toward the tail, so $\text{mean} > \text{median}$. Examples: income, house prices, reaction times.
- **Skewed left (negatively skewed):** The left tail is longer. The mean is pulled left, so $\text{mean} < \text{median}$. Examples: exam scores with a ceiling effect, age at death from natural causes.

```
Symmetric:          Skewed Right:        Skewed Left:
    /‾\                 /‾\                  /‾\
   /   \               /   \__              /   \
  /     \             /       \          __/     \
 /_______\           /_________\        /________\
```

### Additional Shape Types

- **Bell-shaped:** A symmetric, unimodal distribution approximating the normal curve.
- **J-shaped:** Frequencies rise (or fall) sharply at one end.
- **U-shaped:** Frequencies are highest at the extremes and lowest in the middle.

## Center

The center locates the "typical" value. There are two primary measures:

| Measure | Definition | Resistant? |
|:---|:---|:---:|
| **Mean** $\bar{x}$ | Arithmetic average: $\bar{x} = \frac{\sum x_i}{n}$ | No |
| **Median** | Middle value when ordered; the 50th percentile | Yes |

- Use the **median** for skewed distributions or when outliers are present.
- Use the **mean** for roughly symmetric distributions without outliers.

> [!important] Resistant vs. Non-Resistant
> A **resistant** statistic is not strongly affected by extreme values. The median and IQR are resistant; the mean, range, and standard deviation are not. If Bill Gates walks into a room of 50 people, the mean income skyrockets, but the median barely moves.

## Spread (Variability)

Spread quantifies how tightly the data cluster around the center.

| Measure | Formula | Resistant? |
|:---|:---|:---:|
| **Range** | $\max - \min$ | No |
| **Interquartile Range (IQR)** | $Q_3 - Q_1$ | Yes |
| **Standard Deviation** $s$ | $s = \sqrt{\frac{\sum (x_i - \bar{x})^2}{n-1}}$ | No |
| **Variance** $s^2$ | $s^2 = \frac{\sum (x_i - \bar{x})^2}{n-1}$ | No |

- **IQR** measures the spread of the middle 50% of data. Always paired with the median.
- **Standard deviation** measures the typical distance of observations from the mean. Always paired with the mean.
- Larger spread = more variability = less consistency.

## Outliers

An observation is a **suspected outlier** if it falls more than $1.5 \times \text{IQR}$ below $Q_1$ or above $Q_3$:

$$\text{Lower fence} = Q_1 - 1.5 \times \text{IQR}$$
$$\text{Upper fence} = Q_3 + 1.5 \times \text{IQR}$$

Any point outside these fences is flagged as a potential outlier and plotted individually in a modified boxplot.

### What to Do With Outliers

1. **Check for data entry errors.** A height of 72 inches entered as 7.2 or 720.
2. **Investigate the context.** Was that test score from a student who was absent for weeks?
3. **Report analyses both with and without** the suspect point.
4. **Never delete an outlier** without a documented, non-statistical reason.

> [!warning] Outliers Can Be the Story
> In some disciplines (fraud detection, quality control, rare-disease screening), the outlier IS the signal. Do not automatically remove them.

## Putting It Together: The SOCS Framework

Given a distribution, describe it with **four components**:

1. **S**hape — symmetric? skewed left/right? unimodal/bimodal? any gaps or clusters?
2. **O**utliers — are there any? use the $1.5 \times \text{IQR}$ rule or look for isolated points on a dotplot.
3. **C**enter — report the appropriate measure (median for skewed, mean for symmetric).
4. **S**pread — report the companion measure (IQR with median, standard deviation with mean).

Always answer in **context**: *"The distribution of AP Statistics scores is roughly symmetric and unimodal, with a median of 3 and an IQR of 1. There are no apparent outliers."*

**Related:** [[Unit_1_One-Variable_Data]] | [[Measuring_Center_and_Spread]] | [[Normal_Distributions]]
