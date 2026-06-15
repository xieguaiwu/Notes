---
title: Binomial and Geometric Distributions
tags:
  - Statistics
  - 定理性
created: 2026-06-14
---

## Binomial and Geometric Distributions

Both the binomial and geometric distributions model settings with repeated independent trials that each yield a binary outcome: **success** or **failure**. They differ in what we count.

### The Binomial Setting (BINS)

A binomial random variable counts the number of successes in $n$ independent trials. Four conditions must be met:

| Letter | Condition | Meaning |
|--------|-----------|---------|
| **B** | Binary | Each trial has exactly two outcomes: success or failure |
| **I** | Independent | Trials are independent — the outcome of one does not affect another |
| **N** | Number fixed | The number of trials $n$ is fixed in advance |
| **S** | Same probability | Each trial has the same probability of success, $p$ |

> [!tip] Checking Independence
> When sampling without replacement, the 10% condition ensures approximate independence: the sample size must be less than 10% of the population. $n < 0.10N$.

### Binomial Probability Formula

If $X \sim B(n, p)$, the probability of exactly $k$ successes is:

$$
P(X = k) = \binom{n}{k} \, p^k \, (1-p)^{\,n - k}
$$

where $\binom{n}{k} = \frac{n!}{k!(n-k)!}$ counts the number of ways to choose $k$ successes among $n$ trials.

Each of the three factors has a meaning:
- $\binom{n}{k}$: number of arrangements with exactly $k$ successes
- $p^k$: probability of $k$ successes
- $(1-p)^{n-k}$: probability of $n-k$ failures

> [!example] On the Calculator
> Use `binompdf(n, p, k)` for $P(X = k)$ and `binomcdf(n, p, k)` for $P(X \leq k)$ — the cumulative probability.

### Binomial Mean and Standard Deviation

For $X \sim B(n, p)$:

$$
\mu_X = np \qquad \sigma_X = \sqrt{np(1-p)}
$$

### Normal Approximation to the Binomial

When $n$ is large, a binomial distribution is approximately normal. The rule of thumb:

$$
np \geq 10 \quad \text{and} \quad n(1-p) \geq 10
$$

If both conditions hold, then $X$ is approximately $N\big(np, \sqrt{np(1-p)}\big)$. Use this approximation to avoid computing large binomial coefficients by hand — it is the foundation for inference about proportions.

### The Geometric Setting

A geometric random variable counts the number of trials until the **first success**. The BINS conditions are modified:

| Condition | Difference from Binomial |
|-----------|--------------------------|
| Binary | Same |
| Independent | Same |
| **T**rials until success | No fixed $n$ — we stop at the first success |
| Same probability | Same |

The mnemonic is **BITS**: Binary, Independent, Trials until success, Same $p$.

### Geometric Probability Formula

If $X$ is geometric with probability of success $p$, the probability that the first success occurs on the $k$-th trial is:

$$
P(X = k) = (1-p)^{\,k-1} \cdot p
$$

This requires $k-1$ consecutive failures followed by one success.

### Geometric Mean

The expected number of trials to the first success is:

$$
\mu_X = \frac{1}{p}
$$

> [!example] Interpretation
> If a basketball player makes 80% of free throws ($p = 0.8$), the expected number of attempts until a miss (defining "success" as a miss) is $\frac{1}{0.2} = 5$ attempts.

### Geometric Cumulative Probability

The probability that more than $k$ trials are needed for the first success:

$$
P(X > k) = (1-p)^k
$$

This is simply the probability that all of the first $k$ trials are failures.

### Binomial vs. Geometric: When to Use Which

| Question | Distribution |
|----------|-------------|
| "What is the probability of exactly 3 successes in 10 trials?" | **Binomial** ($n = 10$ fixed) |
| "What is the probability that the first success occurs on the 4th trial?" | **Geometric** (no fixed $n$) |
| "What is the probability that it takes more than 5 trials to win?" | **Geometric** |

> [!danger] AP Exam Tip
> Always explicitly check and **name** the conditions (BINS or BITS) before applying these formulas. State: "This is a binomial setting because: Binary (two outcomes), Independent (trials are independent), Number fixed ($n =$ ...), Same probability ($p =$ ...)."

---
Related: [[Unit_4_Probability]] | [[Random_Variables]] | [[Central_Limit_Theorem]] | [[AP_Statistics_MOC]]
