---
tags:
  - ML
  - 定义性
  - 基本原理
title: Per-Seed Concept
created: 2026-04-27
modified: 2026-04-27
---

# Per-Seed Concept

> [!abstract] Per-Seed 概念解释
> **Per-Seed**（按种子/每种子）是指在机器学习实验中，针对**每个随机种子**分别进行实验和分析的方法。

## 1. 核心含义

| 概念 | 说明 |
|------|------|
| **随机种子 (Random Seed)** | 控制随机数生成器的初始状态，确保实验可复现 |
| **Per-Seed** | 对于每个不同的种子值，独立运行实验并记录结果 |

## 2. 为什么需要 Per-Seed 分析？

> [!important] 三大理由
> 1. **消除随机性影响**：单次实验结果可能受随机初始化、数据 shuffle 等因素影响
> 2. **统计显著性**：多个种子下的结果可以计算均值、标准差、置信区间
> 3. **公平比较**：不同方法/条件在相同种子下对比，控制变量

## 3. 示例代码

```python
seeds = [42, 123, 456, 789, 1024]  # 5个不同种子
results = []

for seed in seeds:
    set_seed(seed)
    model = train_model()
    metric = evaluate(model)
    results.append(metric)

# Per-Seed 分析
mean = np.mean(results)              # 均值
std = np.std(results)                # 标准差
ci = confidence_interval(results)     # 置信区间
```

## 4. 在 T-test 分析中的应用

在 T-test 分析中（比较 natural vs parity/reversed 等），Per-Seed 分析的典型应用：

- 每个种子运行一次实验 → 得到一组 (natural, parity, reversed) 结果
- 多个种子 → 多组配对数据
- 配对 T-test 检验差异是否显著

> [!tip] 这样可以回答："natural 语言与 impossible 语言的学习差异是否具有统计学意义"。

## 5. 相关统计方法

| 方法 | 说明 |
|------|------|
| **配对样本 T 检验** | 同一种子下不同条件的配对比较 |
| **Welch's T 检验** | 不假设方差相等的 T 检验 |
| **置信区间** | 量化结果的不确定性范围 |

---

## 相关笔记

- [[Per-Seed Concept]] - 本笔记