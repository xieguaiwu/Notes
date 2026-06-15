---
title: Unit 3 — Collecting Data
tags:
  - Statistics
  - 方法性
created: 2026-06-14
---

## Unit 3: Collecting Data

**Exam Weight:** 12–15% of AP Statistics. Unit 3 covers how to properly gather data so that conclusions are valid — the foundation of statistical inference.

> [!info] Why This Matters
> No statistical technique can rescue poorly collected data. A biased sample or a confounded experiment yields conclusions that are worse than useless — they are misleading.

### Core Vocabulary

| Term | Definition |
|------|------------|
| **Population** | The entire group of individuals we want information about |
| **Sample** | A subset of the population from which we actually collect data |
| **Parameter** | A number that describes a population (e.g., $\mu$, $p$) |
| **Statistic** | A number that describes a sample (e.g., $\bar{x}$, $\hat{p}$) |
| **Census** | Attempting to collect data from every individual in the population |
| **Bias** | Systematic error that consistently over- or under-estimates the true value |

The relationship is simple: we use a **statistic** from a **sample** to estimate a **parameter** about a **population**. The quality of that estimate depends entirely on how the sample was collected.

### Study Design Classification

```mermaid
flowchart TD
    A[Study Design] --> B{Was a treatment<br/>imposed?}
    B -->|Yes| C[Experiment]
    B -->|No| D[Observational Study]
    C --> E["Can establish<br/>cause and effect"]
    D --> F[Sample Survey]
    D --> G[Observational<br/>(no survey)]
    F --> H["Uses random<br/>sampling?"]
    H -->|Yes| I["Generalizable to<br/>population"]
    H -->|No| J["Not generalizable"]
```

### Observational Study vs. Experiment

- **Observational Study:** Observe individuals and measure variables of interest without imposing any treatment. Can reveal **associations**, but not causation.
- **Experiment:** Deliberately impose a treatment on individuals to measure their response. With proper design, can establish **cause and effect**.

The fundamental advantage of experiments is that randomization controls for lurking variables by making treatment groups roughly equal on all variables except the treatment itself.

### Random Sampling → Generalizability

If a sample is **randomly selected** from the population, the results can be **generalized** back to that population. If the sample is biased (convenience, voluntary response), generalizability is lost.

### Random Assignment → Causation

If subjects are **randomly assigned** to treatment groups in an experiment, we can draw **causal conclusions**. Without random assignment, an experiment is little better than an observational study.

> [!warning] Common Confusion
> **Random sampling** deals with who is *in* the study (generalizability). **Random assignment** deals with which treatment they *receive* (causation). A study can have one without the other.

### The Ideal: Random Sampling + Random Assignment

A well-designed survey uses random sampling to generalize to a population. A well-designed experiment uses random assignment to establish causation — and random sampling to generalize those causal conclusions.

### Key Takeaways

1. **Population** → **Parameter**; **Sample** → **Statistic**
2. Observational studies show association; experiments (with randomization) show causation
3. The sampling method determines whether conclusions generalize
4. [[Sampling_Methods|Sampling Methods →]]
5. [[Experimental_Design|Experimental Design →]]

---
Related: [[AP_Statistics_MOC]]
