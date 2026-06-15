---
title: Two-Way Tables
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Two-Way Tables

> **When both variables are categorical, we organize data in a two-way (contingency) table and analyze distributions, not regression.**

Part of: [[AP_Statistics_MOC]].

## Structure of a Two-Way Table

A **two-way table** (or **contingency table**) summarizes the relationship between two categorical variables. Rows represent categories of one variable; columns represent categories of the other.

**Example:** 200 students classified by **Gender** (Male/Female) and **Handedness** (Right/Left/Ambidextrous).

| Gender | Right | Left | Ambi | **Total** |
|:---|:---:|:---:|:---:|:---:|
| Male | 82 | 12 | 6 | **100** |
| Female | 88 | 10 | 2 | **100** |
| **Total** | **170** | **22** | **8** | **200** |

The **marginal totals** are the row and column sums. They appear in the margins of the table and describe each variable independently.

## Marginal Distribution

The **marginal distribution** of a categorical variable is its distribution ignoring the other variable. It is computed from the marginal totals divided by the grand total.

**Marginal distribution of Handedness:**

- Right: $170/200 = 0.850$ (85.0%)
- Left: $22/200 = 0.110$ (11.0%)
- Ambi: $8/200 = 0.040$ (4.0%)

**Marginal distribution of Gender:**

- Male: $100/200 = 0.500$ (50.0%)
- Female: $100/200 = 0.500$ (50.0%)

These distributions answer: "What proportion of ALL students are left-handed?" without considering gender.

## Conditional Distribution

The **conditional distribution** describes the distribution of one variable **given** a specific value of the other variable.

**Conditional distribution of Handedness given Male:**

- Right: $82/100 = 0.820$ (82.0%)
- Left: $12/100 = 0.120$ (12.0%)
- Ambi: $6/100 = 0.060$ (6.0%)

**Conditional distribution of Handedness given Female:**

- Right: $88/100 = 0.880$ (88.0%)
- Left: $10/100 = 0.100$ (10.0%)
- Ambi: $2/100 = 0.020$ (2.0%)

> [!important] Conditional vs. Marginal
> The marginal distribution of handedness says 11% of students are left-handed *overall*. The conditional distributions reveal that left-handedness is slightly more common among males (12%) than females (10%). These comparisons — not the marginal distributions — are how we detect **association**.

### Computing Conditional Distributions

1. Identify the **conditioning variable** (e.g., gender).
2. For each category of the conditioning variable, divide **each cell count** by the **row total** (or column total, depending on direction) for that category.
3. Express as percentages.

If conditioning on **rows**, each row sums to 100%. If conditioning on **columns**, each column sums to 100%.

## Segmented (Stacked) Bar Charts

A **segmented bar chart** displays conditional distributions visually. Each bar represents 100% of one category of the conditioning variable, segmented by the response variable.

- If the segments have **similar proportions** across bars → little or no association.
- If the segments have **clearly different proportions** across bars → evidence of association.

Segmented bar charts are more informative than side-by-side pie charts because the aligned bars make it easy to compare segment lengths.

## Mosaic Plots

A **mosaic plot** is a graphical representation of a two-way table where each cell is a rectangle whose **area** is proportional to the cell frequency. The width of each column is proportional to the marginal total of the column variable.

- Like segmented bar charts, mosaic plots reveal associations through width × height variations.
- Mosaic plots are particularly effective for tables with more than two rows/columns, where segmented bar charts become cluttered.
- When there is **no association**, the dividing lines within each column align horizontally.

## Detecting Association

Two categorical variables are **associated** (dependent) if knowing the value of one changes the distribution of the other. In the table:

- If the conditional distributions of Handedness **given** Male and Female are identical → no association.
- If they differ (as they do above: 82%/12%/6% vs. 88%/10%/2%) → evidence of association.

> [!tip] Formal Check: Chi-Square
> The $\chi^2$ test for association (Unit 8) formally tests whether observed differences are statistically significant. Even without inference, comparing conditional distributions is the foundation.

### Simulating Independence

Under independence, the expected count for cell $(i, j)$ is:

$$\text{expected}_{ij} = \frac{(\text{row total}_i) \times (\text{column total}_j)}{\text{grand total}}$$

Comparing observed to expected counts reveals which cells contribute most to any association.

## Example: Simpson's Paradox Setup

A two-way table can conceal a lurking variable. Consider:

| Hospital | Survived | Died | Survival Rate |
|:---|:---:|:---:|:---:|
| A | 800 | 200 | **80%** |
| B | 900 | 100 | **90%** |

Hospital B appears superior. But disaggregating by patient condition:

**Good condition patients:**

| Hospital | Survived | Died | Rate |
|:---|:---:|:---:|:---:|
| A | 590 | 10 | **98%** |
| B | 870 | 30 | **97%** |

**Poor condition patients:**

| Hospital | Survived | Died | Rate |
|:---|:---:|:---:|:---:|
| A | 210 | 190 | **53%** |
| B | 30 | 70 | **30%** |

Hospital A outperforms B in **every** subgroup, yet B's overall rate is higher — because B treats mostly good-condition patients. This is [[Correlation_vs_Causation|Simpson's Paradox]].

**Related:** [[Unit_2_Two-Variable_Data]] | [[Correlation_vs_Causation]] | [[Unit_1_One-Variable_Data]]
