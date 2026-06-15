---
title: Confidence Intervals for Proportions
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

# Confidence Intervals for Proportions

**Parent:** [[Unit_6_Inference_for_Proportions|Unit 6 — Inference for Proportions]]

---

## One-Proportion Z-Interval

### Formula

$$
\hat{p} \pm z^* \sqrt{\frac{\hat{p}(1-\hat{p})}{n}}
$$

Where:
- $\hat{p}$ = sample proportion (point estimate)
- $z^*$ = critical value from $N(0,1)$ for desired confidence level $C$
- $SE = \sqrt{\hat{p}(1-\hat{p})/n}$ = standard error

### Common Critical Values

| Confidence Level $C$ | $z^*$ |
|:---:|:---:|
| 90% | 1.645 |
| 95% | 1.960 |
| 99% | 2.576 |

---

### Conditions

| Condition | Check |
|-----------|-------|
| **Random** | SRS or randomized experiment |
| **10%** | $n \le 0.10N$ (independence) |
| **Large Counts** | $n\hat{p} \ge 10$ and $n(1-\hat{p}) \ge 10$ |

Unlike the hypothesis test (where large counts use $p_0$), the CI uses $\hat{p}$ because the true $p$ is unknown.

---

### Interpretation

> **"We are $C\%$ confident that the interval from ___ to ___ captures the true population proportion $p$."**

> [!warning] Common Misinterpretations
> - ❌ "There is a $C\%$ probability that $p$ is in the interval." (Wrong — $p$ is fixed, the interval is random.)
> - ✅ "$C\%$ of all possible samples of size $n$ produce an interval that captures $p$."

---

### Margin of Error & Sample Size

**Margin of error:**

$$
ME = z^* \sqrt{\frac{\hat{p}(1-\hat{p})}{n}}
$$

**Planning sample size** (before collecting data):

$$
n = \left(\frac{z^*}{m}\right)^2 \cdot p^*(1-p^*)
$$

Where:
- $m$ = desired margin of error
- $p^*$ = guessed proportion (use $p^* = 0.5$ for maximum $n$, the most conservative choice)

> [!tip] Conservative $n$
> Using $p^* = 0.5$ maximizes $p^*(1-p^*)$ and gives the **largest** required sample size. This is the safe choice when you have no prior estimate of $p$.

---

## Two-Proportion Z-Interval

### Formula

$$
(\hat{p}_1 - \hat{p}_2) \pm z^* \sqrt{\frac{\hat{p}_1(1-\hat{p}_1)}{n_1} + \frac{\hat{p}_2(1-\hat{p}_2)}{n_2}}
$$

### Conditions

| Condition | Check |
|-----------|-------|
| **Random** | Both samples are SRS/randomized (or 2 independent treatments) |
| **10%** | $n_1 \le 0.10N_1$ and $n_2 \le 0.10N_2$ |
| **Large Counts** | $n_1\hat{p}_1 \ge 10$, $n_1(1-\hat{p}_1) \ge 10$ and same for $n_2$ |

### Interpretation

> **"We are $C\%$ confident that the true difference in proportions $(p_1 - p_2)$ is between ___ and ___."**

If the interval contains **0**, we cannot conclude $p_1 \neq p_2$ at the $C\%$ confidence level.

---

## Worked Example

**Problem:** A school surveys 200 randomly selected students; 140 say they support later start times. Construct a 95% CI for the true proportion.

**Step 1 — State:** Parameter $p$ = true proportion who support. CI level = 95%.

**Step 2 — Plan:**
- Random ✅
- $200 \le 0.10$ (all students) ✅
- $n\hat{p} = 140 \ge 10$, $n(1-\hat{p}) = 60 \ge 10$ ✅

**Step 3 — Do:**

$$
\hat{p} = \frac{140}{200} = 0.70
$$

$$
SE = \sqrt{\frac{0.70(0.30)}{200}} = \sqrt{\frac{0.21}{200}} \approx 0.0324
$$

$$
ME = 1.96 \times 0.0324 \approx 0.0635
$$

$$
\text{CI} = 0.70 \pm 0.0635 = (0.6365,\; 0.7635)
$$

**Step 4 — Conclude:** We are 95% confident that the true proportion of students who support later start times is between **63.7% and 76.4%**.

---

## Relationship to Hypothesis Tests

The **duality** between CIs and tests:

- If a two-sided $z$-test at $\alpha = 0.05$ rejects $H_0: p = p_0$, then $p_0$ lies outside the 95% CI.
- If $p_0$ is inside the 95% CI, the test fails to reject at $\alpha = 0.05$.
- This applies only to two-sided tests; one-sided tests and CIs have a modified relationship.

> [!summary] When to Use Which
> - Use a **CI** when the goal is estimation: "What range of values is plausible?"
> - Use a **test** when the goal is decision-making: "Is the evidence strong enough to reject a specific claim?"
> - For the latter, see [[Significance_Tests_Proportions|Significance Tests for Proportions]].

---

[[AP_Statistics_MOC|← Back to AP Statistics MOC]]
