---
title: Unit 2 — Exploring Two-Variable Data
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Unit 2 — Exploring Two-Variable Data

> **AP Exam Weight:** 5–7% | **Big Idea:** Patterns and Uncertainty

Unit 2 moves from describing a single variable to exploring the **relationship** between two quantitative variables. The core question: does knowing one variable help predict the other?

Part of: [[AP_Statistics_MOC]].

## Scatterplots

A **scatterplot** displays the relationship between two quantitative variables measured on the same individuals.

- **Explanatory variable (x):** The predictor or independent variable. Placed on the horizontal axis.
- **Response variable (y):** The outcome or dependent variable. Placed on the vertical axis.

### Describing a Scatterplot: D.O.F.S.

1. **D**irection — positive, negative, or no association.
2. **O**utliers — points that deviate from the overall pattern.
3. **F**orm — linear, curved, clustered?
4. **S**trength — how closely do the points follow a clear form?

A **positive association** means larger $x$ values tend to have larger $y$ values (e.g., height and weight). A **negative association** means larger $x$ values tend to have smaller $y$ values (e.g., speed and travel time).

## Correlation ($r$)

The **Pearson correlation coefficient** $r$ measures the **direction and strength** of a linear relationship:

$$r = \frac{1}{n-1} \sum_{i=1}^{n} \left(\frac{x_i - \bar{x}}{s_x}\right)\!\left(\frac{y_i - \bar{y}}{s_y}\right)$$

### Properties of $r$

- $-1 \leq r \leq 1$.
- $r > 0$ → positive linear association; $r < 0$ → negative; $r = 0$ → no **linear** association (but a curved relationship may still exist!).
- $r = 1$ or $r = -1$ → all points fall exactly on a straight line.
- $r$ has **no units** (it is dimensionless).
- $r$ is **not resistant** — a single outlier can dramatically change it.
- Swapping $x$ and $y$ does **not** change $r$.
- Linear transformations of $x$ or $y$ do not change $|r|$ (though they may flip the sign if multiplying by a negative).

> [!warning] Correlation ≠ Slope
> $r = 0.8$ does NOT mean that 80% of the points lie on a line. It means the linear association is strong and positive. For the proportion of variation explained, use $r^2$.

## Least-Squares Regression

The **least-squares regression line** (LSRL) is the line that minimizes the sum of the squared vertical distances (residuals) from the points to the line.

### The Equation

$$\hat{y} = a + bx$$

- $\hat{y}$ is the **predicted** response for a given $x$.
- $b$ is the **slope**: $b = r \cdot \frac{s_y}{s_x}$.
- $a$ is the **y-intercept**: $a = \bar{y} - b\bar{x}$.

> [!important] Interpreting Slope
> The slope $b$ is the predicted change in $y$ for a one-unit increase in $x$. **Always phrase in context:** "For each additional hour spent studying, the predicted exam score increases by 4.2 points."

> [!important] Interpreting Intercept
> The intercept $a$ is the predicted value of $y$ when $x = 0$. Only interpret it when $x = 0$ is plausible in context. An intercept predicting negative height makes no sense — it is simply an artifact of the fitted line.

### The Least-Squares Principle

Among all possible lines $\hat{y} = a + bx$, the LSRL minimizes:

$$\sum_{i=1}^{n} (y_i - \hat{y}_i)^2 = \sum_{i=1}^{n} (\text{residual})^2$$

The LSRL always passes through the point $(\bar{x}, \bar{y})$.

## Coefficient of Determination ($r^2$)

The **coefficient of determination** is the square of the correlation:

$$r^2 = \frac{\text{variation in } y \text{ explained by the LSRL}}{\text{total variation in } y}$$

Interpretation: "$r^2 \times 100\%$ of the variation in $y$ is explained by the linear relationship with $x$."

If $r = 0.8$, then $r^2 = 0.64$, meaning **64% of the variation in the response is accounted for by the linear model**. The remaining 36% is due to other factors or random variation.

## Residuals

A **residual** is the difference between an observed and predicted value:

$$\text{residual} = y - \hat{y} = \text{observed} - \text{predicted}$$

- A **positive residual** means the model **under-predicted** (the actual point lies above the line).
- A **negative residual** means the model **over-predicted** (the actual point lies below the line).

### Residual Plots

A **residual plot** graphs residuals (y-axis) against the explanatory variable or predicted values (x-axis). It is the most important diagnostic for regression:

- **Good fit:** Residuals are randomly scattered around 0 with no clear pattern. Approximately equal vertical spread across all $x$ values.
- **Curved pattern:** The relationship is not linear. Consider a transformation.
- **Fan shape (increasing spread):** Violation of **constant variance** (heteroscedasticity).
- **Outliers and influential points** become clearly visible.

### Standard Deviation of Residuals ($s_{\text{res}}$)

$$s_{\text{res}} = \sqrt{\frac{\sum (y_i - \hat{y}_i)^2}{n-2}}$$

This is the "typical" prediction error of the model. Dividing by $n-2$ reflects the two parameters ($a$ and $b$) estimated from the data.

## Outliers and Influential Points in Regression

- An **outlier** in regression is a point with a large residual (far from the fitted line vertically).
- An **influential point** is a point whose removal substantially changes the slope, intercept, or $r$. Influential points are often far from $\bar{x}$ in the horizontal direction (high **leverage**).
- Not all outliers are influential. Not all influential points are outliers.

To check influence: remove the point, recalculate the regression, and observe whether the slope changes meaningfully.

## Transformations for Nonlinear Data

When a scatterplot shows a curved pattern, transforming one or both variables can produce a linear relationship. Common transformations:

| Pattern | Transformation |
|:---|:---|
| Exponential growth ($y = ab^x$) | Take $\log(y)$ and regress on $x$ |
| Power law ($y = ax^b$) | Take $\log(y)$ and $\log(x)$ |
| Reciprocal ($y = a + b/x$) | Regress $y$ on $1/x$ |

After transformation, fit the linear model on the transformed scale, then back-transform predictions to the original scale. **Always check the residual plot** of the transformed model — it should now be patternless.

**Related:** [[Two-Way_Tables]] | [[Correlation_vs_Causation]] | [[Unit_1_One-Variable_Data]]
