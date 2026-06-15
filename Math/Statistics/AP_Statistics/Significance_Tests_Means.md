---
title: Significance Tests for Means
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Overview

Significance tests (hypothesis tests) for means evaluate evidence against a null hypothesis about $\mu$. All use the **t-statistic** with degrees of freedom determined by the design.

---

## One-Sample t-Test

Test whether the population mean $\mu$ equals a hypothesized value $\mu_0$.

### Hypotheses

- $H_0: \mu = \mu_0$
- $H_a: \mu \neq \mu_0$ (two-sided), $\mu > \mu_0$, or $\mu < \mu_0$ (one-sided)

### Test Statistic

$$ t = \frac{\bar{x} - \mu_0}{s/\sqrt{n}}, \quad \text{df} = n-1 $$

### Conditions

Same as for confidence intervals: Random, Independent (10%), Nearly Normal.

### p-value

- Upper-tailed: $P(T_{n-1} \ge t)$
- Lower-tailed: $P(T_{n-1} \le t)$
- Two-tailed: $2 \cdot P(T_{n-1} \ge |t|)$

### Example (One-Sample t-Test, 4-Step Process)

A teacher claims the mean score is 78. A random sample of 30 students has $\bar{x}=74.2$, $s=11.5$. Test at $\alpha = 0.05$.

**Step 1 — State:**
- $H_0: \mu = 78$ (the teacher's claim is correct)
- $H_a: \mu \neq 78$ (two-sided — the claim is wrong)
- $\alpha = 0.05$

**Step 2 — Plan:** One-sample t-test for $\mu$. Check conditions:
- Random ✅ (SRS of 30 students)
- 10% ✅ ($30 \le 0.10N$)
- Nearly Normal ✅ ($n = 30 \ge 30$, CLT applies)

**Step 3 — Do:**
$$ t = \frac{74.2 - 78}{11.5/\sqrt{30}} = \frac{-3.8}{2.10} = -1.81, \quad \text{df} = 29 $$
$$ p = 2 \cdot P(T_{29} \le -1.81) \approx 0.080 $$

**Step 4 — Conclude:** Since $p = 0.080 > \alpha = 0.05$, we **fail to reject** $H_0$. There is not sufficient evidence at the 5% level that the true mean score differs from 78.

---

## Two-Sample t-Test

Compare two population means using independent samples.

### Hypotheses

- $H_0: \mu_1 - \mu_2 = 0$ (or $\mu_1 = \mu_2$)
- $H_a: \mu_1 - \mu_2 \neq 0$ (or one-sided)

### Test Statistic

$$ t = \frac{(\bar{x}_1 - \bar{x}_2) - 0}{\sqrt{\frac{s_1^2}{n_1} + \frac{s_2^2}{n_2}}}, \quad \text{df} = \min(n_1 - 1,\ n_2 - 1) $$

### Additional Condition

**Independent groups** — the two samples are independent.

---

## Paired t-Test

For matched pairs or dependent samples. See [[Matched_Pairs_T_Test]] for full treatment.

### Hypotheses

- $H_0: \mu_d = 0$
- $H_a: \mu_d \neq 0$ (or one-sided)

### Test Statistic

$$ t = \frac{\bar{x}_d}{s_d/\sqrt{n}}, \quad \text{df} = n-1 $$

Where $\bar{x}_d$ and $s_d$ are the mean and standard deviation of the **differences** within each pair.

---

## Decision Flowchart

```mermaid
flowchart TD
    A[Significance test for mean] --> B{One or two<br>populations?}
    B -->|One| C{Paired data?}
    B -->|Two| D{Paired or<br>independent?}
    C -->|Yes| E[Paired t-test<br>H₀: μ_d = 0<br>df = n-1]
    C -->|No| F[One-sample t-test<br>H₀: μ = μ₀<br>df = n-1]
    D -->|Paired| E
    D -->|Independent| G[Two-sample t-test<br>H₀: μ₁ = μ₂<br>df = min(n₁-1, n₂-1)]
```

---

## Making a Decision

| Evidence | $p$-value | Conclusion |
|----------|-----------|------------|
| Weak against $H_0$ | $p > \alpha$ | Fail to reject $H_0$ — not enough evidence |
| Strong against $H_0$ | $p \le \alpha$ | Reject $H_0$ — statistically significant |

**Never say "accept $H_0$."** We only lack evidence to reject it.

---

## Relationship with Confidence Intervals

For a two-sided test at level $\alpha$:

- If $\mu_0$ is **inside** the $C = 1 - \alpha$ CI → fail to reject $H_0$
- If $\mu_0$ is **outside** the $C = 1 - \alpha$ CI → reject $H_0$

This duality provides a useful consistency check.

---

## Common Errors

| Error | Description |
|-------|-------------|
| **Type I** | Reject $H_0$ when $H_0$ is true (false positive). Probability = $\alpha$. |
| **Type II** | Fail to reject $H_0$ when $H_a$ is true (false negative). Probability = $\beta$. |
| **Power** | $1 - \beta$ — probability of correctly rejecting a false $H_0$. |

### Increasing Power

Increase sample size $n$, increase $\alpha$, reduce variability (better measurement, blocking).

---

## Practical vs Statistical Significance

A very large sample can detect a tiny, practically irrelevant difference. Always **interpret effect size** — a confidence interval helps assess practical significance.

See also: [[Confidence_Intervals_Means]], [[Matched_Pairs_T_Test]], [[Unit_7_Inference_for_Means]], [[AP_Statistics_MOC]]
