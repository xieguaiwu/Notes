---
title: Chi-Square Tests for Homogeneity and Independence
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Overview

Both the **test of homogeneity** and the **test of independence** use a two-way (contingency) table and the same $\chi^2$ statistic. They differ in **design, sampling scheme, and interpretation**.

---

## The Chi-Square Statistic (Two-Way Table)

For a table with $R$ rows and $C$ columns:

$$ \chi^2 = \sum_{\text{all cells}} \frac{(O - E)^2}{E}, \quad \text{df} = (R-1)(C-1) $$

Expected count for each cell (under $H_0$):

$$ E = \frac{\text{row total} \times \text{column total}}{\text{grand total}} $$

---

## Test of Homogeneity

### When to Use
Two or more **independent groups** (populations, treatments) are compared on the same categorical variable. The question: "Do these groups have the **same distribution** across categories?"

### Design
- Multiple random samples, one from each population
- **Row totals fixed** by sample sizes

### Hypotheses
- **$H_0$:** The distribution of the categorical variable is the same across all groups.
- **$H_a$:** At least one group's distribution differs.

### Example
Compare the distribution of preferred phone brand (Apple, Samsung, Other) across three age groups (18–29, 30–49, 50+). Survey 100 people from each age group.

---

## Test of Independence

### When to Use
A **single sample** from one population is cross-classified by two categorical variables. The question: "Are these two variables **associated** (dependent) or not?"

### Design
- One random sample
- Only the **grand total** is fixed

### Hypotheses
- **$H_0$:** The two variables are independent.
- **$H_a$:** The two variables are associated (not independent).

### Example
Survey 300 adults and record both their education level (HS, College, Graduate) and whether they support a policy (Yes, No). Check if education and support are related.

---

## Comparison Table

| Feature | Homogeneity | Independence |
|---------|-------------|--------------|
| **Number of samples** | Two or more | One |
| **What is fixed** | Row totals (sample sizes) | Grand total |
| **Question** | Same distribution across groups? | Association between variables? |
| **$H_0$ wording** | Distributions are equal across groups | Variables are independent |
| **$H_a$ wording** | At least one distribution differs | Variables are associated |
| **Example** | Do men and women have the same party affiliation distribution? | Is party affiliation associated with gender in the US? |
| **Row totals** | Fixed by design | Random |
| **Same $\chi^2$ formula?** | Yes | Yes |
| **Same df?** | Yes ($(R-1)(C-1)$) | Yes |

---

## Conditions (Both Tests)

1. **Random** — Data from random samples or randomized experiments.
2. **Independence** — Each observation belongs to exactly one cell; no repeated measures.
   - 10% condition: $n < 0.10N$ if sampling without replacement.
3. **Large Expected Counts** — All $E \ge 5$.

---

## Example: Homogeneity

| | Support | Oppose | Undecided | Total |
|-----------|---------|--------|-----------|-------|
| Group A | 45 | 30 | 25 | 100 |
| Group B | 35 | 40 | 25 | 100 |
| Group C | 25 | 45 | 30 | 100 |

Expected for Group A, Support: $(105 \times 100) / 300 = 35$.

$$ \chi^2 = \frac{(45-35)^2}{35} + \frac{(30-35)^2}{35} + \cdots = 10.86 $$
$$ \text{df} = (3-1)(3-1) = 4 $$

$p \approx 0.028$ — reject $H_0$; the groups have different distributions of opinion.

---

## Example: Independence

Same table, different design: one sample of 300 adults, then asked group membership and opinion.

$$ \chi^2 = 10.86,\ \text{df} = 4,\ p \approx 0.028 $$

**Interpretation:** There is evidence of an association between group membership and opinion among these 300 adults.

---

## Standardized Residuals (Two-Way Tables)

After a significant $\chi^2$, examine:

$$ \text{residual} = \frac{O - E}{\sqrt{E}} $$

| | Support | Oppose | Undecided |
|-----------|---------|--------|-----------|
| Group A | 1.69 | −0.85 | −1.69 |
| Group B | 0 | 0.85 | −0.85 |
| Group C | −1.69 | 1.69 | 0 |

Group C has more Oppose and less Support than expected under $H_0$ — this drives the significance.

---

## Common Mistakes

| Mistake | Why it's wrong |
|---------|----------------|
| Saying "homogeneity" when the design is one sample | Look at how the data were collected |
| Claiming causation from independence test | Association ≠ causation; no temporal ordering |
| Using wrong df ($R \times C$ instead of $(R-1)(C-1)$) | df counts free cells after fixing margins |
| Computing $E$ incorrectly | Always $(\text{row} \times \text{col}) / \text{total}$ |
| Forgetting $E \ge 5$ condition | Check after computing expected counts |

---

## Which Test? Quick Checklist

- **One sample, two categorical variables** → Independence
- **Two or more independent samples, one categorical variable** → Homogeneity

On the AP exam, the distinction often comes down to how the data were collected — read the problem description carefully.

---

## Summary

| | Homogeneity | Independence |
|--|-------------|--------------|
| $H_0$ | $p_{1j} = p_{2j} = \cdots = p_{Rj}$ for all $j$ | $P(A \cap B) = P(A)P(B)$ |
| Chi-square | $\sum (O-E)^2/E$ | $\sum (O-E)^2/E$ |
| df | $(R-1)(C-1)$ | $(R-1)(C-1)$ |
| Key question | Same across groups? | Associated in population? |

See also: [[Chi-Square_Goodness_of_Fit]], [[Unit_8_Chi-Square_Tests]], [[AP_Statistics_MOC]]
