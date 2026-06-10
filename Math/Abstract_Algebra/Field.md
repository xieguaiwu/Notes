---
title: Field
tags:
  - Math
  - AbstractAlgebra
  - 定义性
  - 基本原理
created: 2026-06-08
modified:
---

# Field

> [!abstract] 概述
> **域 (Field)** 是抽象代数中具有两种运算的代数结构：加法与乘法，满足通常算术的一切基本性质。域是群在结构上的自然扩展——一个域内部包含着两个阿贝尔群。

## 定义

设 $F$ 是一个非空集合，$+$ 和 $\times$ 是 $F$ 上的两种二元运算。$(F, +, \times)$ 称为一个**域**，若满足：

### A. 加法公理（$(F, +)$ 是阿贝尔群）

| 公理 | 内容 |
|:-----|:-----|
| 封闭性 | $\forall a, b \in F,\; a + b \in F$ |
| 交换律 | $\forall a, b \in F,\; a + b = b + a$ |
| 结合律 | $\forall a, b, c \in F,\; (a + b) + c = a + (b + c)$ |
| 零元 | $\exists 0 \in F,\; \forall a \in F,\; a + 0 = a$ |
| 负元 | $\forall a \in F,\; \exists -a \in F,\; a + (-a) = 0$ |

### B. 乘法公理（$F^\times$ 是阿贝尔群）

| 公理 | 内容 |
|:-----|:-----|
| 封闭性 | $\forall a, b \in F,\; a \times b \in F$ |
| 交换律 | $\forall a, b \in F,\; a \times b = b \times a$ |
| 结合律 | $\forall a, b, c \in F,\; (a \times b) \times c = a \times (b \times c)$ |
| 单位元 | $\exists 1 \in F,\; 1 \neq 0,\; \forall a \in F,\; a \times 1 = a$ |
| 逆元 | $\forall a \in F,\; a \neq 0,\; \exists a^{-1} \in F,\; a \times a^{-1} = 1$ |

### C. 分配律（连接两种运算）

$$\forall a, b, c \in F,\; a \times (b + c) = a \times b + a \times c$$

> [!tip] 群论视角
> 域的定义可以用群的语言精简为两句话：
> 1. $(F, +)$ 是**阿贝尔群**（加法群，单位元为 $0$）
> 2. $F^\times$（非零元构成的乘法群）是**阿贝尔群**，单位元为 $1$
> 3. 分配律将两个群联系起来
>
> 这正是"域 = 两个阿贝尔群 + 分配律"的含义。参见 [[Group]]。

## 基本推论

从域公理可直接导出以下性质（Rudin Proposition 1.14–1.16）：

- **消去律**：$a + b = a + c \implies b = c$
- **零乘性质**：$0 \times a = 0$
- **符号规则**：$(-a) \times b = -(a \times b)$，$(-a) \times (-b) = a \times b$
- **逆元唯一**：若 $a \neq 0$，则 $a^{-1}$ 唯一

> 这些性质在**任何**域中都成立，因此只需证明一次，就对 $\mathbb{Q}$、$\mathbb{R}$、$\mathbb{C}$、$\mathbb{F}_p$ 等全部适用——这正是 Rudin Remarks 1.13(c) 的用意。

## 示例

| 域 | 集合 | 加法 | 乘法 | 特征 | 备注 |
|:---|:-----|:-----|:-----|:-----|:-----|
| $\mathbb{Q}$ | 有理数 | 通常加法 | 通常乘法 | $0$ | 最小的特征 $0$ 域 |
| $\mathbb{R}$ | 实数 | 通常加法 | 通常乘法 | $0$ | 具有最小上界性质的有序域 |
| $\mathbb{C}$ | 复数 | 通常加法 | 通常乘法 | $0$ | 代数闭包，但**不能**成为有序域 |
| $\mathbb{F}_p$ | $\{0,1,\dots,p-1\}$ | 模 $p$ 加法 | 模 $p$ 乘法 | $p$ | 有限域，$p$ 为素数 |
| $\mathbb{Q}(\sqrt{2})$ | $\{a + b\sqrt{2} \mid a,b\in\mathbb{Q}\}$ | 通常加法 | 通常乘法 | $0$ | 有理数域的二次扩张 |

## 有序域 (Ordered Field)

域 $(F, +, \times)$ 同时是一个**有序集**（即定义了满足三分性和传递性的序关系 $<$，参见 [[Density and Completeness#0.2 有序集 (Ordered Set, Def 1.6)]]），且序与运算兼容：

1. **加法保序**：$y < z \implies x + y < x + z$
2. **正数乘法保序**：$x > 0,\; y > 0 \implies xy > 0$

则称 $F$ 为**有序域** (Rudin Def 1.17)。

> [!warning] 并非所有域都可成为有序域
> $\mathbb{C}$ 是域，但无法定义满足上述条件的序关系。这是因为若 $i > 0$ 则 $i^2 = -1 > 0$ 矛盾；若 $i < 0$ 则 $(-i) > 0$ 同样导致 $-1 > 0$。具体见 Rudin Exercise 1.8。

### 非有序域的例子

以下结构是**域**同时也是**有序集**，但排序与运算不兼容，因此**不是**有序域。

#### 1. $\mathbb{C}$ 上的字典序（最自然的例子）

$\mathbb{C}$ 是域。在 $\mathbb{C}$ 上定义**字典序** (lexicographic order)：

$$(a,b) < (c,d) \iff a < c,\; \text{或}\; a = c \land b < d$$

- 这是 $\mathbb{C}$ 上的一个序（满足三分性和传递性），故 $(\mathbb{C}, <)$ 是有序集
- $(\mathbb{C}, +, \times)$ 是域
- **但** $(\mathbb{C}, +, \times, <)$ **不是**有序域，因为第二条兼容公理被违反：

$$(0,1) > (0,0) \;\text{即}\; i > 0,\quad \text{但}\; i^2 = -1 < 0$$

> 正数乘法保序要求 $x > 0,\, y > 0 \implies xy > 0$，而这里 $i > 0$ 但 $i^2 < 0$。

#### 2. 有限域 $\mathbb{F}_p$ 上的自然序

设 $p$ 为素数，$\mathbb{F}_p = \{0,1,\dots,p-1\}$ 是**有限域**（模 $p$ 的整数）。

将整数的自然序 $0 < 1 < 2 < \dots < p-1$ 限制在 $\mathbb{F}_p$ 上：

- 这是 $\mathbb{F}_p$ 上的一个序（三分性 + 传递性），故 $(\mathbb{F}_p, <)$ 是有序集
- $(\mathbb{F}_p, +, \times)$ 是域
- **但** $(\mathbb{F}_p, +, \times, <)$ **不是**有序域，因为加法保序失败：

$$1 < 2,\quad \text{但}\; 1 + (p-1) = 0 > 2 + (p-1) = 1$$

更根本地，**任何有限域都不能成为有序域**（有序域必须特征 $0$ 且无穷），因为 $1 > 0$ 导致 $1+1+\cdots$ 无限递推。

#### 3. $\mathbb{R}$ 上的非标准序（通过置换构造）

$\mathbb{R}$ 是域，也是有序域（使用通常的 $<$）。但如果我们通过一个**不保序的双射**来定义一个新的序：

取双射 $\varphi: \mathbb{R} \to \mathbb{R}$，定义 $x <' y \iff \varphi(x) < \varphi(y)$（$<$ 为通常序）。

例如令 $\varphi$ 只交换 $1$ 和 $-1$，其余不动：

- $(\mathbb{R}, <')$ 是有序集（$\varphi$ 是双射，故三分性 + 传递性继承自 $\mathbb{R}$）
- $(\mathbb{R}, +, \times)$ 是域
- **但** $(\mathbb{R}, +, \times, <')$ **不是**有序域：$1 <' -1$，两边 $+1$ 得 $2 <' 0$，实际上 $2 > 0$，违反加法保序

> 这说明：**同一个域可以有不同的序结构，但只有与运算兼容的那个才是有序域**。$\mathbb{R}$ 的通常序恰好兼容，这是 $\mathbb{R}$ 的独特性质，而非平凡事实。

#### 小结：能不能成为有序域？

| 域 | 能成为有序域？ | 原因 |
|:---|:--------------|:-----|
| $\mathbb{Q}$ | ✅ | 通常序兼容 |
| $\mathbb{R}$ | ✅ | 通常序兼容 |
| $\mathbb{Q}(\sqrt{2})$ | ✅ | 可嵌入 $\mathbb{R}$ 继承序 |
| $\mathbb{C}$ | ❌ 不可能 | 任何序都会使 $i^2 < 0$ |
| $\mathbb{F}_p$（有限域） | ❌ 不可能 | 特征 $p > 0$，有限 |
| $\mathbb{R}(x)$（有理函数域） | ✅ | 有多种有序域结构 |

> [!tip] 直观理解
> 有序域要求**加法保序**和**正数乘正数得正数**。这两条看似简单，但排除了所有含 $i$ 的域（复数类）和所有有限域。$\mathbb{C}$ 之所以不能成为有序域，不是因为缺什么——它什么都有，只是 $i$ 的乘法性质与"正数乘正数得正数"天然冲突。这也正是分析学建立在 $\mathbb{R}$ 而非 $\mathbb{C}$ 上的原因之一：$\mathbb{R}$ 的序使我们可以谈论大小、区间、极限的单调性。

## 域与群的关系

| | 群 | 域 |
|:--|:----|:----|
| **运算数目** | 一种 | 两种（$+$ 和 $\times$） |
| **结构** | $(G, \cdot)$ | $(F, +, \times)$ |
| **内部群** | — | $(F, +)$ 和 $(F^\times, \times)$ |
| **连接公理** | — | 分配律 |
| **研究重点** | 对称性、分类 | 扩张、Galois 群、赋值 |

Galois 理论将二者深度连接：域扩张 $E/F$ 对应一个群 $\text{Aut}(E/F)$（称为 Galois 群），其子群结构与扩张的中间域一一对应。群成为研究域的**语言**。

## 相关链接

- [[Group]] — 群的定义，域的基础构件
- [[Density and Completeness#0.7 为什么还需要 Field？（从序到算术）]] — Rudin 引入 field 的动机
- [[Boundedness#3.1 有序集上的有界性 (Def 1.7)]] — 有序集的基本概念

## 参考来源

- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., McGraw-Hill 1976. (Def 1.12–1.17)
- Lang, S. *Algebra*, 3rd ed., Springer 2002.
- Dummit, D. & Foote, R. *Abstract Algebra*, 3rd ed., Wiley 2004.
