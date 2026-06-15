---
title: Matched Pairs t-Test
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Overview

A **matched pairs** (or **paired**) design controls for extraneous variability by pairing similar subjects or by taking two measurements on the same subject. The analysis focuses on the **differences within each pair**, reducing the analysis to a **one-sample problem** on those differences.

---

## When to Use a Paired Design

Two situations:

1. **Same subjects, two conditions** — Pre-test / post-test, before / after treatment, left vs right side.
2. **Matched subjects** — Twins, siblings, or subjects matched on key covariates (age, sex, baseline measure), then randomly assigned.

### Paired vs Two-Sample

| Aspect | Paired t-Test | Two-Sample t-Test |
|--------|---------------|-------------------|
| Data structure | Pairs of related observations | Two independent groups |
| What we analyze | Differences $d_i$ | Raw values in each group |
| Degrees of freedom | $n_{\text{pairs}} - 1$ | $\min(n_1-1, n_2-1)$ |
| Power | Higher (removes between-pair variability) | Lower |
| Example | Same students before vs after tutoring | Tutored group vs control group |

---

## Hypotheses

- $H_0: \mu_d = 0$ (mean difference is zero — no effect)
- $H_a: \mu_d \neq 0$ (two-sided), $\mu_d > 0$, or $\mu_d < 0$ (one-sided)

Where $\mu_d$ is the true mean of the population differences.

---

## Test Statistic

$$ t = \frac{\bar{x}_d}{s_d/\sqrt{n}}, \quad \text{df} = n - 1 $$

- $\bar{x}_d = \frac{1}{n} \sum d_i$ — mean of the differences
- $s_d = \sqrt{\frac{1}{n-1} \sum (d_i - \bar{x}_d)^2}$ — standard deviation of the differences
- $n$ = number of **pairs** (not individual measurements)

### Confidence Interval

$$ \bar{x}_d \pm t^*_{n-1} \cdot \frac{s_d}{\sqrt{n}} $$

---

## Conditions

1. **Random** — Pairs are a random sample from the population, or treatments are randomly assigned within each pair.
2. **Independence / 10%** — The pairs are independent of each other; fewer than 10% of all possible pairs if sampling without replacement.
3. **Nearly Normal** — The distribution of **differences** (not the original values) is approximately Normal. Check with a histogram or Normal probability plot of the $d_i$. For $n \ge 30$, the CLT applies.

**Key insight:** The original data can be skewed as long as the **differences** are roughly Normal.

---

## Examples

### Example 1: Pre-test / Post-test

Eight students take a practice exam, then a review course, then a post-test.

| Student | Pre | Post | $d$ (Post − Pre) |
|---------|-----|------|------------------|
| 1 | 72 | 78 | 6 |
| 2 | 65 | 68 | 3 |
| 3 | 80 | 85 | 5 |
| 4 | 74 | 72 | −2 |
| 5 | 68 | 75 | 7 |
| 6 | 70 | 71 | 1 |
| 7 | 82 | 88 | 6 |
| 8 | 76 | 80 | 4 |

$\bar{x}_d = 3.75$, $s_d = 3.01$, $n = 8$

$$ t = \frac{3.75}{3.01/\sqrt{8}} = \frac{3.75}{1.06} = 3.52, \quad \text{df} = 7 $$

$p \approx 0.010$ (two-sided) — strong evidence that scores increased on average.

### Example 2: Twin Study

10 pairs of identical twins are randomized: one twin receives a treatment, the other a placebo. Outcome measured on each.

The analysis proceeds identically: compute the difference (treated − placebo) for each twin pair, then run a one-sample t-test on those differences.

---

## Why Paired Tests Are More Powerful

A paired test removes the **between-pair** variability. The standard error of the two-sample test involves both $\sigma_1^2$ and $\sigma_2^2$, while the paired test's standard error involves only $\sigma_d^2$, which is typically much smaller.

However, pairing **reduces** degrees of freedom (pairs − 1 vs. $n_1 + n_2 - 2$), so the power gain comes from variance reduction, not from more information.

---

## Common Pitfalls

| Pitfall | Explanation |
|---------|-------------|
| Running two-sample test on paired data | Loses power, may obscure real effects, violates independence |
| Forgetting to check differences for Normality | The CLT applies to the differences, not the original variables |
| Incorrectly computing $d$ direction | Always be consistent about which direction is subtracted; document it |
| Using $n$ = total measurements instead of pairs | Doubles the sample size artificially; produces wrong df and SE |

---

## Paired t-Interval

The CI follows the same logic:

$$ \bar{x}_d \pm t^*_{n-1} \cdot \frac{s_d}{\sqrt{n}} $$

Interpretation: "We are $C\%$ confident that the true mean difference $\mu_d$ is between \_\_ and \_\_."

If the interval contains 0, the result is not statistically significant at level $\alpha = 1 - C$.

---

## Summary

Use a paired t-test when:
- Each observation in one group is **naturally paired** with one in the other
- The alternative is a two-sample test that would **ignore** the pairing

See also: [[Significance_Tests_Means]], [[Confidence_Intervals_Means]], [[Unit_7_Inference_for_Means]], [[AP_Statistics_MOC]]
