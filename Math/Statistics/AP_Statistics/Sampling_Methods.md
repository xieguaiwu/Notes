---
title: Sampling Methods
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Sampling Methods

Choosing how to select individuals from a population directly determines whether study results are trustworthy. A method is **biased** if it systematically favors certain outcomes.

### Probability Sampling Methods

These methods use chance to select individuals — each member of the population has a known, nonzero probability of being selected.

#### Simple Random Sample (SRS)

An SRS of size $n$ gives every group of $n$ individuals an equal chance of being chosen. This is the gold standard: it eliminates selection bias and makes statistical inference valid.

**How to implement:** Assign each individual a unique number, then use a random number generator (or a table of random digits) to pick $n$ of them.

#### Stratified Random Sample

1. Divide the population into **strata** — groups of similar individuals (e.g., by grade level, gender)
2. Take an SRS from *each* stratum

**Why use it?** Guarantees representation from each subgroup and can reduce sampling variability compared to an SRS of the same size, because individuals within a stratum tend to be homogeneous.

#### Cluster Sample

1. Divide the population into **clusters** — groups that are each representative of the population (e.g., homeroom classes in a school)
2. Randomly select one or more clusters
3. Include *all* individuals from the selected clusters

**Why use it?** Practical when the population is geographically spread out or when a complete list of individuals is unavailable. The key difference from stratification: strata are internally homogeneous, while clusters are internally heterogeneous.

#### Systematic Random Sample

Select a starting point at random, then pick every $k$-th individual. For example, interview every 30th customer entering a store. Valid **only if** the ordering has no pattern related to the variable of interest.

### Non-Probability Sampling (Biased)

| Method | How It Works | Problem |
|--------|-------------|---------|
| **Convenience sample** | Choose individuals easiest to reach | Over-represents accessible groups |
| **Voluntary response** | Individuals choose to participate | Only those with strong opinions respond |

> [!danger] AP Exam Warning
> Convenience and voluntary response samples are **always** biased. Do not use them unless the question specifically asks you to identify a biased method.

### Types of Bias

#### Sampling Bias (Selection Bias)
The method for choosing the sample systematically excludes part of the population. *Example:* A phone survey misses people without phones.

#### Nonresponse Bias
Individuals selected for the sample cannot be contacted or refuse to participate — and those who respond differ systematically from those who don't.

#### Response Bias
The survey itself influences answers. Sources include:
- **Question wording** ("Do you support killing innocent animals?" vs. "Do you support medical research using animal testing?")
- **Interviewer effect** (race, gender, or demeanor of the interviewer)
- **Social desirability** (respondents give "acceptable" rather than truthful answers)

#### Undercoverage
Some groups in the population are left out of the sampling frame entirely. *Example:* Using a list of registered voters misses unregistered adults.

> [!tip] Identifying Bias on the AP Exam
> When asked to describe a bias, name the **type** (sampling, nonresponse, response, undercoverage), explain **how** it arises from the study design, and state the **direction** of the bias (who is over- or under-represented).

### How to Reduce Bias

- Use a **random sampling** method — SRS is best when feasible
- Maximize **response rate** with follow-ups and incentives
- Write **neutral, clear questions** and pilot-test them
- Ensure the **sampling frame** matches the target population

---
Related: [[Unit_3_Collecting_Data]] | [[AP_Statistics_MOC]]
