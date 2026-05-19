---
tags:
  - Math
  - Statistics
  - Probability
  - 基本原理
title: Probability Basics
created: 2026-05-18T12:15:00
modified:
---
# Probability Basics 概率基础

概率论是统计学的理论基础。这份笔记覆盖理解线性回归模型所需的概率知识。

---

## 1. 随机变量 (Random Variable)

**随机变量**是一个取值由随机现象决定的变量，一般用大写字母 $X, Y$ 表示。

### 1.1 离散型 vs 连续型

| 类型 | 定义 | 取值 | 示例 |
|------|------|------|------|
| **离散型 (Discrete)** | 取值可数 | 有限个或可数无穷个 | 掷骰子的点数 $X \in \{1,2,3,4,5,6\}$ |
| **连续型 (Continuous)** | 取值不可数 | 某个区间内的任意实数 | 人的身高 $X \in [0, \infty)$ |

### 1.2 概率分布

- **离散型**：用**概率质量函数 (PMF)** 描述，$P(X = x)$
- **连续型**：用**概率密度函数 (PDF)** 描述，$f(x)$，满足 $\int_{-\infty}^{\infty} f(x) dx = 1$

累积分布函数 (CDF)：$F(x) = P(X \leq x)$

---

## 2. 期望 (Expected Value / Expectation)

**期望**是随机变量取值的加权平均，权重为概率。

### 2.1 定义

| 类型 | 公式 |
|------|------|
| 离散型 | $\mathbb{E}[X] = \sum_{i} x_i \cdot P(X = x_i)$ |
| 连续型 | $\mathbb{E}[X] = \int_{-\infty}^{\infty} x \cdot f(x) \, dx$ |

### 2.2 线性性质 (最重要)

对于任意常数 $a, b$ 和随机变量 $X, Y$：

$$\mathbb{E}[aX + b] = a\mathbb{E}[X] + b$$

$$\mathbb{E}[X + Y] = \mathbb{E}[X] + \mathbb{E}[Y]$$

### 2.3 在回归中的应用

线性模型假设 $\mathbb{E}[\varepsilon] = 0$，这意味着：

$$\mathbb{E}[Y] = \mathbb{E}[\beta_0 + \beta_1 X + \varepsilon] = \beta_0 + \beta_1 X + \mathbb{E}[\varepsilon] = \beta_0 + \beta_1 X$$

即 $Y$ 的期望值正好落在回归直线上。

---

## 3. 方差 (Variance)

**方差**衡量随机变量取值与其期望的偏离程度。

$$\text{Var}(X) = \mathbb{E}[(X - \mathbb{E}[X])^2]$$

### 3.1 计算公式

$$\text{Var}(X) = \mathbb{E}[X^2] - (\mathbb{E}[X])^2$$

### 3.2 重要性质

$$\text{Var}(aX + b) = a^2 \text{Var}(X)$$

$$\text{Var}(X + Y) = \text{Var}(X) + \text{Var}(Y) + 2\text{Cov}(X, Y)$$

若 $X, Y$ 独立，则 $\text{Var}(X + Y) = \text{Var}(X) + \text{Var}(Y)$。

**标准差** (Standard Deviation)：$\text{SD}(X) = \sqrt{\text{Var}(X)}$，与 $X$ 同量纲。

### 3.3 在回归中的应用

线性模型假设 $\text{Var}(\varepsilon) = \sigma^2$（**同方差性**），即误差的波动程度不随 $X$ 变化。

---

## 4. 正态分布 (Normal Distribution)

### 4.1 定义

正态分布是最重要的连续概率分布，记作 $X \sim N(\mu, \sigma^2)$：

$$f(x) = \frac{1}{\sqrt{2\pi\sigma^2}} \exp\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)$$

其中：
- $\mu$ — **均值** (Mean)，决定分布的中心位置
- $\sigma$ — **标准差** (Standard Deviation)，决定分布的宽窄

### 4.2 标准正态分布

当 $\mu = 0, \sigma = 1$ 时，称为**标准正态分布** $Z \sim N(0, 1)$：

$$f(z) = \frac{1}{\sqrt{2\pi}} e^{-z^2/2}$$

任何正态分布可通过标准化转换为标准正态分布：

$$Z = \frac{X - \mu}{\sigma} \sim N(0, 1)$$

### 4.3 68-95-99.7 法则

在正态分布中：
- $\mu \pm \sigma$ 覆盖约 **68%** 的数据
- $\mu \pm 2\sigma$ 覆盖约 **95%** 的数据
- $\mu \pm 3\sigma$ 覆盖约 **99.7%** 的数据

### 4.4 在回归中的应用

线性模型的**正态性假设**要求 $\varepsilon \sim N(0, \sigma^2)$，这是 $t$ 检验和小样本推断的基础。

---

## 5. 独立同分布 (i.i.d.)

**独立同分布 (independent and identically distributed, i.i.d.)** 是统计学中最常见的假设：

- **独立 (Independent)**：一个变量的取值不影响另一个变量的取值
- **同分布 (Identically Distributed)**：所有变量来自同一个概率分布

在线性回归中，假设误差项 $\varepsilon_1, \varepsilon_2, \ldots, \varepsilon_n$ 是 i.i.d. 的。

### 独立性的数学定义

两个随机变量 $X, Y$ 独立，当且仅当：

$$P(X \leq x, Y \leq y) = P(X \leq x) \cdot P(Y \leq y)$$

等价地，$\mathbb{E}[XY] = \mathbb{E}[X]\mathbb{E}[Y]$（若期望存在）。

---

## 6. 协方差 (Covariance)

**协方差**度量两个随机变量一起变化的程度：

$$\text{Cov}(X, Y) = \mathbb{E}[(X - \mathbb{E}[X])(Y - \mathbb{E}[Y])] = \mathbb{E}[XY] - \mathbb{E}[X]\mathbb{E}[Y]$$

性质：
- $\text{Cov}(X, Y) > 0$：$X$ 增大时 $Y$ 倾向于增大
- $\text{Cov}(X, Y) < 0$：$X$ 增大时 $Y$ 倾向于减小
- $\text{Cov}(X, Y) = 0$：$X, Y$ 不相关（但不一定独立）

若 $X, Y$ 独立，则 $\text{Cov}(X, Y) = 0$（反之不成立）。

---

## 7. 线性回归中的概率语言

| 笔记中的符号 | 含义 |
|------------|------|
| $\varepsilon$ | 随机误差项，是一个随机变量 |
| $\mathbb{E}(\varepsilon)=0$ | 误差的平均值为 0 |
| $\text{Var}(\varepsilon)=\sigma^2$ | 误差的方差是常数 $\sigma^2$ |
| $\varepsilon \sim N(0, \sigma^2)$ | 误差服从均值为 0、方差为 $\sigma^2$ 的正态分布 |
| $\varepsilon_i$ 独立 | 不同观测的误差互不影响 |
