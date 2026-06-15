---
title: Significance Tests for Proportions
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

# Significance Tests for Proportions

**Parent:** [[Unit_6_Inference_for_Proportions|Unit 6 — Inference for Proportions]]

---

## One-Proportion Z-Test

### Structure

| Component | Notation |
|-----------|----------|
| **Null hypothesis** | $H_0: p = p_0$ |
| **Alternative** (two-sided) | $H_a: p \neq p_0$ |
| **Alternative** (one-sided) | $H_a: p > p_0$ or $H_a: p < p_0$ |
| **Test statistic** | $z = \frac{\hat{p} - p_0}{\sqrt{\frac{p_0(1-p_0)}{n}}}$ |
| **$p$-value** | $P(Z \ge |z|)$ for two-sided; $P(Z \ge z)$ or $P(Z \le z)$ for one-sided |

### Conditions

| Condition | Check |
|-----------|-------|
| **Random** | SRS or randomized experiment |
| **10%** | $n \le 0.10N$ |
| **Large Counts** | $np_0 \ge 10$ and $n(1-p_0) \ge 10$ (use $p_0$, **not** $\hat{p}$) |

> [!warning] CI vs. Test — Different SEs
> - **Confidence interval** uses $SE = \sqrt{\hat{p}(1-\hat{p})/n}$
> - **Hypothesis test** uses $SE = \sqrt{p_0(1-p_0)/n}$
>
> Why? Under $H_0$, $p_0$ is the assumed truth. Plugging in $p_0$ gives the correct **null distribution**.

---

### $p$-Value Interpretation

> [!tip] $p$-Value Definition
> A **$p$-value** is the probability of observing a test statistic as extreme as (or more extreme than) the one observed, **assuming $H_0$ is true**.

| $p$-value | Evidence against $H_0$ |
|:---------:|:----------------------|
| $p > 0.10$ | Little to none |
| $0.05 < p \le 0.10$ | Suggestive (marginal) |
| $0.01 < p \le 0.05$ | Moderate — significant at $\alpha = 0.05$ |
| $p \le 0.01$ | Strong — significant at $\alpha = 0.01$ |

> ❌ **Common misinterpretation:** "The $p$-value is the probability that $H_0$ is true." — This is wrong. The $p$-value is calculated **assuming** $H_0$ is true.

---

### Decision Rule

$$
\text{If } p\text{-value} < \alpha \;\rightarrow\; \text{Reject } H_0 \text{ (statistically significant)}
$$

$$
\text{If } p\text{-value} \ge \alpha \;\rightarrow\; \text{Fail to reject } H_0 \text{ (not significant)}
$$

> [!key] Never "Accept $H_0$"
> We never **accept** $H_0$. We either **reject** or **fail to reject** it. Failing to reject means insufficient evidence, not proof that $H_0$ is true.

---

### Worked Example

**Problem:** A candidate claims 60% of voters support her. A poll of 500 voters finds 280 supporters. Is there evidence at $\alpha = 0.05$ that her claim is wrong?

**Step 1 — State:**
- $H_0: p = 0.60$
- $H_a: p \neq 0.60$ (two-sided — "wrong" means either direction)
- $\alpha = 0.05$

**Step 2 — Plan:**
- Random ✅ (assume SRS)
- $500 \le 0.10$ of all voters ✅
- $np_0 = 500(0.60) = 300 \ge 10$ ✅; $n(1-p_0) = 500(0.40) = 200 \ge 10$ ✅

**Step 3 — Do:**

$$
\hat{p} = \frac{280}{500} = 0.56
$$

$$
z = \frac{0.56 - 0.60}{\sqrt{\frac{0.60(0.40)}{500}}} = \frac{-0.04}{\sqrt{0.00048}} \approx \frac{-0.04}{0.0219} \approx -1.826
$$

$$
p\text{-value} = 2 \times P(Z \le -1.826) \approx 2 \times 0.0339 = 0.0678
$$

**Step 4 — Conclude:** Since $p = 0.0678 > \alpha = 0.05$, we **fail to reject** $H_0$. There is not sufficient evidence at the 5% level that the candidate's support differs from 60%.

---

## Two-Proportion Z-Test

### Hypotheses

- $H_0: p_1 = p_2$ (or $p_1 - p_2 = 0$)
- $H_a: p_1 \neq p_2$ (or $p_1 > p_2$, $p_1 < p_2$)

### Test Statistic

$$
z = \frac{\hat{p}_1 - \hat{p}_2}{\sqrt{\hat{p}_c(1-\hat{p}_c)\left(\frac{1}{n_1} + \frac{1}{n_2}\right)}}
$$

Where $\hat{p}_c$ is the **pooled proportion** (under $H_0$, both groups share the same $p$):

$$
\hat{p}_c = \frac{\text{successes}_1 + \text{successes}_2}{n_1 + n_2}
$$

### Conditions

| Condition | Check |
|-----------|-------|
| **Random** | Both samples independent SRSs or randomized experiment |
| **10%** | $n_1 \le 0.10N_1$, $n_2 \le 0.10N_2$ |
| **Large Counts** | $n_1\hat{p}_c \ge 10$, $n_1(1-\hat{p}_c) \ge 10$ and same for $n_2$ |

> [!summary] Choosing the Right Test
> | Scenario | Test |
> |----------|------|
> | One proportion vs. fixed $p_0$ | One-prop $z$-test |
> | Two independent proportions | Two-prop $z$-test |
> | Paired/matched data | McNemar's test (not on AP exam) |
>
> Related: [[Confidence_Intervals_Proportions|Confidence Intervals for Proportions]], [[Type_I_and_II_Errors|Type I & II Errors]]

---

[[AP_Statistics_MOC|← Back to AP Statistics MOC]]
