---
tags:
  - Math
  - Statistics
  - 定义性
  - 基本原理
title: Linear and Power Models
created: 2026-05-18T12:00:00
modified:
---
# Linear and Power Models 线性模型与幂函数模型

## 1. 一元线性回归模型 (Simple Linear Regression Model)

### 1.1 模型定义

一元线性回归模型描述一个**因变量 (Dependent Variable)** $Y$ 与一个**自变量 (Independent Variable)** $X$ 之间的线性关系：

$$Y = \beta_0 + \beta_1 X + \varepsilon$$

其中：
- $\beta_0$ — **截距 (Intercept)**，当 $X=0$ 时 $Y$ 的期望值
- $\beta_1$ — **斜率 (Slope)**，$X$ 每变化一个单位时 $Y$ 的平均变化量
- $\varepsilon$ — **随机误差项 (Random Error)**，满足 $\mathbb{E}(\varepsilon)=0$，$\text{Var}(\varepsilon)=\sigma^2$

### 1.2 基本假设 (Gauss-Markov Assumptions)

| 假设 | 含义 | 数学表达 |
|------|------|---------|
| **线性性 (Linearity)** | $Y$ 与 $X$ 的关系是线性的 | $Y = \beta_0 + \beta_1 X + \varepsilon$ |
| **独立性 (Independence)** | 各观测值相互独立 | $\varepsilon_i$ 独立 |
| **同方差性 (Homoscedasticity)** | 误差项的方差为常数 | $\text{Var}(\varepsilon_i) = \sigma^2$ |
| **正态性 (Normality)** | 误差项服从正态分布 | $\varepsilon_i \sim N(0, \sigma^2)$ |

### 1.3 参数估计：普通最小二乘法 (Ordinary Least Squares, OLS)

目标是找到 $\hat{\beta}_0, \hat{\beta}_1$ 使残差平方和 (Sum of Squared Residuals, SSR) 最小：

$$SSR = \sum_{i=1}^{n} (Y_i - \hat{\beta}_0 - \hat{\beta}_1 X_i)^2$$

通过求偏导并令其为零，得到OLS估计量：

$$\hat{\beta}_1 = \frac{\sum_{i=1}^{n} (X_i - \bar{X})(Y_i - \bar{Y})}{\sum_{i=1}^{n} (X_i - \bar{X})^2} = \frac{S_{XY}}{S_{XX}}$$

$$\hat{\beta}_0 = \bar{Y} - \hat{\beta}_1 \bar{X}$$

其中 $\bar{X} = \frac{1}{n}\sum X_i$，$\bar{Y} = \frac{1}{n}\sum Y_i$。

### 1.4 拟合优度：决定系数 $R^2$

$$R^2 = \frac{SSR}{SST} = 1 - \frac{SSE}{SST}$$

其中：
- $SST = \sum (Y_i - \bar{Y})^2$ — **总平方和 (Total Sum of Squares)**
- $SSR = \sum (\hat{Y}_i - \bar{Y})^2$ — **回归平方和 (Regression Sum of Squares)**
- $SSE = \sum (Y_i - \hat{Y}_i)^2$ — **残差平方和 (Error Sum of Squares)**

$R^2$ 的取值范围为 $[0, 1]$，越接近 $1$ 表示模型拟合效果越好。

### 1.5 相关系数 $r$

在一元线性回归中，$R^2$ 的平方根即为 Pearson 相关系数：

$$r = \frac{\sum (X_i - \bar{X})(Y_i - \bar{Y})}{\sqrt{\sum (X_i - \bar{X})^2 \sum (Y_i - \bar{Y})^2}} = \frac{S_{XY}}{\sqrt{S_{XX} S_{YY}}}$$

且有 $\hat{\beta}_1 = r \cdot \frac{S_Y}{S_X}$，其中 $S_X, S_Y$ 为样本标准差。

### 1.6 显著性检验

对斜率 $\beta_1$ 的 $t$ 检验：

$$H_0: \beta_1 = 0 \quad \text{vs} \quad H_1: \beta_1 \neq 0$$

$$t = \frac{\hat{\beta}_1}{\text{SE}(\hat{\beta}_1)} \sim t_{n-2}$$

其中 $\text{SE}(\hat{\beta}_1) = \sqrt{\frac{\hat{\sigma}^2}{\sum (X_i - \bar{X})^2}}$，$\hat{\sigma}^2 = \frac{SSE}{n-2}$。

---

## 2. 幂函数非线性模型 (Power Function Model)

### 2.1 模型定义

幂函数模型描述 $Y$ 与 $X$ 之间的**幂律关系 (Power Law Relationship)**：

$$Y = a X^b \cdot e^{\varepsilon}$$

其中：
- $a$ — **尺度参数 (Scale Parameter)**，$a > 0$
- $b$ — **幂指数 (Power Exponent)**，决定了曲线的形状
- $\varepsilon$ — 随机误差项，$\varepsilon \sim N(0, \sigma^2)$

### 2.2 不同 $b$ 值的曲线形态

| $b$ 的范围 | 曲线形态 | 含义 |
|-----------|---------|------|
| $b > 1$ | 凸增长 (Convex) | $Y$ 随 $X$ 加速增长 |
| $b = 1$ | 线性 (Linear) | $Y = aX$，退化为正比关系 |
| $0 < b < 1$ | 凹增长 (Concave) | $Y$ 随 $X$ 减速增长（边际递减） |
| $b = 0$ | 常数 (Constant) | $Y = a$，与 $X$ 无关 |
| $b < 0$ | 递减 (Decreasing) | $Y$ 随 $X$ 增加而减少 |

### 2.3 线性化：对数变换 (Log Transformation)

对幂函数模型两侧取自然对数：

$$\ln Y = \ln a + b \ln X + \varepsilon$$

令：
- $Y' = \ln Y$
- $X' = \ln X$
- $\beta_0 = \ln a$
- $\beta_1 = b$

则模型转化为一元线性回归形式：

$$Y' = \beta_0 + \beta_1 X' + \varepsilon$$

### 2.4 参数估计步骤

1. **数据变换**：对原始数据 $(X_i, Y_i)$ 计算 $(\ln X_i, \ln Y_i)$
2. **线性回归**：对变换后的数据使用 OLS 估计 $\hat{\beta}_0, \hat{\beta}_1$
3. **还原参数**：
   $$\hat{a} = e^{\hat{\beta}_0}, \quad \hat{b} = \hat{\beta}_1$$

### 2.5 弹性的解释 (Elasticity Interpretation)

幂函数模型的一个重要性质：**$b$ 就是弹性 (Elasticity)**。

$$b = \frac{d(\ln Y)}{d(\ln X)} = \frac{dY/Y}{dX/X}$$

即 $X$ 每变化 $1\%$，$Y$ 平均变化 $b\%$。这一性质在经济学中广泛应用（如 Cobb-Douglas 生产函数、需求的价格弹性等）。

### 2.6 与其他非线性模型的比较

| 模型 | 形式 | 线性化变换 | 适用场景 |
|------|------|-----------|---------|
| **幂函数模型** | $Y = aX^b$ | $\ln Y = \ln a + b \ln X$ | 弹性恒定、尺度关系 |
| **指数模型** | $Y = ae^{bX}$ | $\ln Y = \ln a + bX$ | 增长率恒定 |
| **对数模型** | $Y = a + b\ln X$ | 直接回归 $Y$ 对 $\ln X$ | 边际递减效应 |
| **双曲模型** | $Y = a + b/X$ | 直接回归 $Y$ 对 $1/X$ | 渐近行为 |

---

## 3. 模型选择指南

| 数据类型 | 推荐模型 | 理由 |
|---------|---------|------|
| 散点图呈直线趋势 | 一元线性模型 | 直接适用 OLS，解释直观 |
| 散点图呈曲线但增长/递减幅度不大 | 对数模型 $Y = a + b\ln X$ | 简单，边际效应递减 |
| 散点图呈明显的幂律分布 | 幂函数模型 $Y = aX^b$ | 对数-对数尺度下呈直线 |
| 数据在双对数坐标下呈直线 | 幂函数模型 | 弹性恒定，易于解释 |
