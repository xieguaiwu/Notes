---
title: Chi-Square Goodness-of-Fit Test
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Overview

The **chi-square goodness-of-fit (GOF) test** determines whether the observed distribution of a single categorical variable matches a hypothesized (claimed) distribution. It answers: "Is the sample consistent with the claimed population proportions?"

---

## Hypotheses

- **$H_0$:** The population follows the specified distribution (the proportions $p_1, p_2, \ldots, p_k$ are as claimed).
- **$H_a$:** At least one proportion differs from the claimed value.

The alternative is **always two-sided** in the sense that any deviation counts — there is no "direction" for GOF.

---

## Test Statistic

$$ \chi^2 = \sum_{i=1}^{k} \frac{(O_i - E_i)^2}{E_i}, \quad \text{df} = k - 1 $$

- $k$ = number of categories
- $O_i$ = observed count in category $i$
- $E_i = n \cdot p_i$ = expected count (under $H_0$)
- $n$ = total sample size

The $p$-value is $P(\chi^2_{k-1} \ge \chi^2_{\text{calc}})$.

### Key Properties

- $\chi^2$ is always **non-negative**.
- Larger values indicate **greater deviation** from $H_0$.
- Each term $\frac{(O-E)^2}{E}$ measures the **relative contribution** of that cell.

---

## Conditions

1. **Random** — Data from a random sample or randomized experiment.
2. **Independence** — Each observation belongs to exactly one category; observations are independent.
3. **Large Counts** — All expected counts $\ge 5$.

If an expected count is too small, consider combining adjacent categories (only if meaningful in context).

---

## Example: M&M Color Distribution

| Color | Claimed $p$ | Observed $O$ | Expected $E = 100 \times p$ | $(O-E)^2/E$ |
|-------|-------------|--------------|------------------------------|-------------|
| Blue | 0.24 | 28 | 24 | 0.667 |
| Orange | 0.20 | 22 | 20 | 0.200 |
| Green | 0.16 | 14 | 16 | 0.250 |
| Yellow | 0.14 | 12 | 14 | 0.286 |
| Red | 0.13 | 15 | 13 | 0.308 |
| Brown | 0.13 | 9 | 13 | 1.231 |

$$ \chi^2 = 0.667 + 0.200 + 0.250 + 0.286 + 0.308 + 1.231 = 2.942 $$
$$ \text{df} = 6 - 1 = 5 $$

$p \approx 0.71$ — insufficient evidence to reject the claimed distribution.

---

## Standardized Residuals

The **standardized residual** for each category is:

$$ \text{residual}_i = \frac{O_i - E_i}{\sqrt{E_i}} $$

- Residuals > 2 or < −2 suggest a **notable deviation** in that category.
- Residuals > 3 or < −3 are **strong evidence** of deviation in that cell.

In the M&M example, the largest |residual| is $\sqrt{1.231} = 1.11$ (Brown), well below 2 — no single cell drives the result.

---

## When the Test is Significant

If $p \le \alpha$:

- Conclude that at least one proportion differs from the claimed value.
- **Do not** conclude all proportions differ — identify which categories have large residuals.
- A follow-up analysis using standardized residuals pinpoints the source.

### Example

A genetics experiment tests $H_0: (9{:}3{:}3{:}1)$ dihybrid ratio. With df = 3 and $\chi^2 = 14.5$, $p \approx 0.002$. The largest residual might be in the "double recessive" category — that's where observed and expected diverge most.

---

## Relationship to the One-Proportion z-Test

When $k = 2$ (two categories), the GOF test is equivalent to a **two-sided one-proportion z-test**:

$$ \chi^2 = z^2, \quad \chi^2_{1, \alpha} = z^2_{\alpha/2} $$

The GOF test generalizes this to $k \ge 2$ categories.

---

## Common Mistakes

| Mistake | Why it's wrong |
|---------|----------------|
| Using counts where proportions are given | Expected counts must be $n \times p$, not just $p$ |
| Checking $O_i \ge 5$ instead of $E_i \ge 5$ | The condition is about **expected** counts |
| Interpreting $H_a$ directionally | Any deviation, in any category, counts against $H_0$ |
| Running GOF on numeric data | GOF requires categorical data; binning numeric data loses information |
| Using $\chi^2$ when expected counts < 5 | Test may not be valid; consider combining categories |

---

## Summary

1. State $H_0$ with the claimed proportions.
2. Compute expected counts $E_i = n \cdot p_i$.
3. Check conditions (Random, Independence, $E_i \ge 5$).
4. Calculate $\chi^2 = \sum (O-E)^2 / E$.
5. Find df = $k-1$, compute $p$-value.
6. If $p < \alpha$, examine standardized residuals to identify which categories differ.

See also: [[Unit_8_Chi-Square_Tests]], [[Chi-Square_Homogeneity_and_Independence]], [[AP_Statistics_MOC]]
