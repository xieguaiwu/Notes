---
title: Correlation vs. Causation
tags:
  - Statistics
  - 定义性
created: 2026-06-14
---

# Correlation vs. Causation

> **"Correlation does not imply causation."** — The most important sentence in introductory statistics.

Observing that two variables move together does not prove that one causes the other. This note explains why, and catalogues the alternative explanations you must consider in every data analysis.

Part of: [[AP_Statistics_MOC]].

## The Fundamental Distinction

| Term | Meaning |
|:---|:---|
| **Association** | Two variables are related in a systematic way. Knowing one helps predict the other. |
| **Causation** | Changing one variable **produces** a change in the other. Requires a mechanism, not just a pattern. |

A strong correlation ($|r|$ near 1) does **not** establish causation. It merely tells us the variables tend to move together. Establishing causation requires a **controlled experiment** with random assignment — not an observational study.

> [!warning] The Most Common AP Exam Trap
> Free-response questions often describe observational studies with strong correlations and ask for a conclusion. The correct answer almost always includes: "No, we cannot conclude causation because this is an observational study. There may be lurking or confounding variables."

## Lurking Variables

A **lurking variable** is a variable not included in the study that affects both the explanatory and response variables, creating a spurious association.

**Classic example:** Ice cream sales and drowning deaths are positively correlated. Does ice cream cause drowning? No. The lurking variable is **temperature** (summer weather): hot weather increases both ice cream consumption and swimming activity, which increases drowning risk.

**Another example:** A study finds that people who drink more coffee have lower rates of heart disease. The lurking variable could be **overall health consciousness** — people who avoid coffee might also smoke more, exercise less, or have poorer diets.

### How to Address Lurking Variables

- **Measure them** and include them in the analysis (multiple regression or stratification).
- **Randomize** in an experiment so that lurking variables are balanced across treatment groups.
- Acknowledge them in the discussion section when they cannot be eliminated.

## Confounding

**Confounding** occurs when the effects of two variables on a response cannot be separated. A variable is a **confounder** if:

1. It is associated with the explanatory variable.
2. It is a risk factor for the response variable.
3. It is not on the causal pathway between them.

> [!important] Lurking vs. Confounding
> These terms are closely related. A **lurking variable** is a potential confounder that was not measured. A **confounding variable** is a variable whose effect is mixed with the effect of the explanatory variable. In practice, AP Exam readers largely treat them as synonyms, but "confounding" implies that the mixing of effects has actually occurred.

### Example

Suppose we observe that students who take AP Statistics have higher college GPAs. Is AP Stats causing higher GPAs?

- **Confounder:** Academic motivation. Motivated students are more likely to take AP Stats AND more likely to earn high GPAs regardless. The effect of the course and the effect of motivation are confounded.

## Common Response

**Common response** is a special case where both the explanatory and response variables are caused by a third variable.

```
    Lurking Variable Z
         ↙        ↘
   Variable X    Variable Y
   (observed)    (observed)
```

X and Y appear associated, but only because they share a common cause Z. This is the causal structure behind most spurious correlations.

**Example:** Cities with more police officers have higher crime rates. The common cause is **city size** — larger cities have more police AND more crime. The correlation does not mean police cause crime.

## Simpson's Paradox

**Simpson's Paradox** occurs when the direction of an association reverses when data are aggregated versus when they are disaggregated by a third variable.

### Classic Example: UC Berkeley Graduate Admissions (1973)

Aggregated data appeared to show **gender bias against women**:

| Gender | Applicants | Admitted | Rate |
|:---|:---:|:---:|:---:|
| Men | 8,442 | 3,738 | **44%** |
| Women | 4,321 | 1,494 | **35%** |

But disaggregating by **department** revealed that women applied disproportionately to **more competitive departments** with lower overall admission rates. Within most individual departments, women were admitted at *equal or higher* rates than men.

The lurking variable — **department competitiveness** — reversed the apparent direction of association.

### Why Simpson's Paradox Occurs

1. The grouping variable is associated with both the explanatory and response variables.
2. The group sizes are unbalanced (different numbers of observations in subgroups).
3. The relationship within each subgroup is homogeneous but differs from the overall (marginal) relationship.

**Always ask:** Could there be a lurking categorical variable that, if used to stratify the data, would change the conclusion?

## Establishing Causation

Correlation alone cannot establish causation, but several lines of evidence together can build a strong case:

### 1. Randomized Controlled Experiment

The **gold standard**. Random assignment of subjects to treatment groups ensures that, on average, all other variables (known and unknown) are balanced. Any systematic difference in response can then be attributed to the treatment.

### 2. Bradford Hill Criteria (Epidemiology)

When experiments are unethical or impractical (e.g., smoking and lung cancer), epidemiologists use these criteria:

- **Strength** of association (large effect size).
- **Consistency** (replicated across many studies and populations).
- **Specificity** (one cause → one effect).
- **Temporality** (cause precedes effect in time).
- **Biological gradient** (dose-response relationship).
- **Plausibility** (mechanism makes biological sense).
- **Coherence** (consistent with existing knowledge).
- **Experiment** (experimental evidence when available).
- **Analogy** (similar to other established causal relationships).

### 3. Natural Experiments and Causal Inference Methods

Modern causal inference uses:
- **Instrumental variables** (a variable that affects the treatment but not the outcome directly).
- **Regression discontinuity** (exploit a cutoff threshold in treatment assignment).
- **Difference-in-differences** (compare changes over time between treated and untreated groups).
- **Propensity score matching** (match treated and untreated units on observed covariates).

> [!tip] On the AP Exam
> The AP Exam tests your ability to recognize that **observational studies cannot establish causation**. You do not need to know the Bradford Hill criteria or advanced causal inference methods. Simply state: "Because this is an observational study, we cannot conclude that [explanatory variable] causes [response variable]. There may be lurking or confounding variables such as [give a plausible example]."

## Summary: Interpreting Association

| If you see... | You can conclude... |
|:---|:---|
| Strong $r$ in an experiment | Evidence for causation (with caveats) |
| Strong $r$ in an observational study | Association only. Causation cannot be established. |
| $r$ close to 0 | No linear association. (A curved relationship may still exist — always check the scatterplot.) |
| Association disappears after controlling for $Z$ | $Z$ was a confounder; the original association was spurious. |
| Association reverses after stratifying by $Z$ | Simpson's Paradox. $Z$ is a critical contextual variable. |

**Related:** [[Unit_2_Two-Variable_Data]] | [[Two-Way_Tables]] | [[Unit_1_One-Variable_Data]]
