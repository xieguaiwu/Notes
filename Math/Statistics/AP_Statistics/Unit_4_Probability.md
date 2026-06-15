---
title: Unit 4 — Probability
tags:
  - Statistics
  - 原理性
created: 2026-06-14
---

## Unit 4: Probability, Random Variables, and Probability Distributions

**Exam Weight:** 10–20% of AP Statistics. Unit 4 covers the mathematical foundation of statistical inference — probability and its applications to random variables and sampling distributions.

### The Law of Large Numbers

As the number of repetitions of a random process increases, the **relative frequency** of an outcome approaches its true probability.

$$
\lim_{n \to \infty} \frac{\text{count of successes}}{n} = P(\text{success})
$$

> [!warning] Misconception Alert
> The Law of Large Numbers does **not** say that outcomes will "even out" in the short run. If you flip a fair coin 10 times and get 8 heads, the probability of heads on the next flip is still 0.5. There is no "law of averages" that forces compensation.

### Basic Probability Rules

For any random phenomenon, let $S$ be the sample space — the set of all possible outcomes. An **event** is any subset of $S$.

1. **Probability of an event:** $0 \leq P(A) \leq 1$ for any event $A$
2. **Probability of sample space:** $P(S) = 1$
3. **Complement rule:** $P(A^c) = 1 - P(A)$
4. **Addition rule (general):** For any two events $A$ and $B$:

   $$
   P(A \cup B) = P(A) + P(B) - P(A \cap B)
   $$

### Disjoint (Mutually Exclusive) Events

Two events are **disjoint** if they cannot occur simultaneously: $P(A \cap B) = 0$.

When events are disjoint, the addition rule simplifies:

$$
P(A \cup B) = P(A) + P(B) \quad \text{(disjoint only)}
$$

> [!tip] Venn Diagram Thinking
> Draw a Venn diagram whenever you are confused about probability relationships. The subtraction of $P(A \cap B)$ in the general addition rule prevents double-counting the overlapping region.

### Conditional Probability

The probability that event $A$ occurs **given** that event $B$ has occurred:

$$
P(A \mid B) = \frac{P(A \cap B)}{P(B)}, \quad P(B) > 0
$$

This is the single most important formula in Unit 4. It restricts the sample space to only those outcomes where $B$ has occurred, then finds the proportion where $A$ also occurs.

### Independence

Two events $A$ and $B$ are **independent** if knowing that one occurred does not change the probability of the other:

$$
P(A \mid B) = P(A) \quad \text{or equivalently} \quad P(A \cap B) = P(A) \cdot P(B)
$$

> [!danger] Independence ≠ Disjoint
> Disjoint events are **never** independent (except the trivial case where one has probability 0). If $A$ and $B$ are disjoint and $A$ occurs, then $B$ *cannot* occur — so knowing $A$ gives information about $B$, violating independence.

### Multiplication Rule

- **General:** $P(A \cap B) = P(A) \cdot P(B \mid A) = P(B) \cdot P(A \mid B)$
- **Independent events only:** $P(A \cap B) = P(A) \cdot P(B)$

### Probability Tree Diagrams

When a process has multiple stages, a tree diagram is often the clearest way to compute probabilities:

1. Label each branch with its probability (must sum to 1 at each node)
2. Multiply along branches to find the probability of a path: $P(A \cap B) = P(A) \cdot P(B \mid A)$
3. Add probabilities from all relevant paths for an "or" problem

### General Multiplication and the Chain Rule

For three events: $P(A \cap B \cap C) = P(A) \cdot P(B \mid A) \cdot P(C \mid A \cap B)$

### Two-Way Tables

A two-way table (contingency table) organizes counts by two categorical variables. From it you can compute:
- **Marginal probabilities:** row or column totals divided by grand total
- **Joint probabilities:** individual cell counts divided by grand total
- **Conditional probabilities:** cell count divided by row or column total

### Summary of Key Formulas

| Situation | Formula |
|-----------|---------|
| Complement | $P(A^c) = 1 - P(A)$ |
| General addition | $P(A \cup B) = P(A) + P(B) - P(A \cap B)$ |
| Disjoint addition | $P(A \cup B) = P(A) + P(B)$ |
| Conditional probability | $P(A \mid B) = \frac{P(A \cap B)}{P(B)}$ |
| General multiplication | $P(A \cap B) = P(A) \cdot P(B \mid A)$ |
| Independence (product) | $P(A \cap B) = P(A) \cdot P(B)$ |

---
Related: [[Random_Variables]] | [[Binomial_and_Geometric_Distributions]] | [[Central_Limit_Theorem]] | [[AP_Statistics_MOC]]
