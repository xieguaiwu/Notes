---
title: Real Field
tags:
  - Math
  - Calculus
  - 基本原理
  - 证明
created: 2026-06-16
modified:
---

# Real Field

> [!abstract] 概述
> **实数域 (Real Field)** 章节（Rudin §1.4）是整个数学分析的基石。前三个子节分别搭建了有序集、域和有序域，本节将它们融合为 $\mathbb{R}$ 的完整刻画：**$\mathbb{R}$ 是满足最小上界性质的有序域，并且 $\mathbb{Q}$ 作为其子域**。三大核心定理（1.19–1.21）完成了这一构建。

## 结构上下文

### Rudin Chapter 1 的搭建逻辑

```
集合论基础 (Def 1.1–1.4)
      ↓
   有序关系 (Def 1.5)      域公理 (Def 1.12)
      ↓                         ↓
   有序集 (Def 1.6)        域结构 (Def 1.12)
      ↓                         ↓
   最小上界性质 (Def 1.10)   有序域 (Def 1.17)
      ↓                         ↓
   └─────────┬─────────────────┘
              ↓
         The Real Field (§1.4)
    ℝ = 有序域 + 最小上界性质
```

> 前三个层次（有序集、域、有序域）的梳理见 [[Field]] 和 [[Density and Completeness]]，本节直接使用这些概念来刻画 $\mathbb{R}$ 的唯一性。

### 本节定位

| 之前 (Def 1.1–1.17) | 现在 (§1.4) | 之后 (§1.5–1.6) |
|:-------------------|:------------|:----------------|
| 搭建有序集、域、有序域的框架 | 断言 $\mathbb{R}$ 存在并证明其核心性质 | $\mathbb{C}$、欧氏空间 |
| $\mathbb{Q}$ 的不足（无 LUB）| $\mathbb{R}$ 填补了所有"空隙" | 将 $\mathbb{R}$ 的结构推广到 $\mathbb{R}^k$ |

---

## Theorem 1.19 — 实数系的存在性

> 存在一个具备**最小上界性质**的有序域 $\mathbb{R}$，且 $\mathbb{Q} \subset \mathbb{R}$ 为其子域。

### 含义

这是整个分析的**存在性基础**。Rudin 没有给出完整构造（放在 Chapter 1 Appendix），而是给出证明纲要：

#### 构造思路（Dedekind 分割）

实数被定义为有理数的**分割 (cut)**：$\mathbb{Q}$ 的一个子集 $\alpha$，满足：

1. $\alpha$ 非空，且 $\alpha \neq \mathbb{Q}$
2. 若 $p \in \alpha$ 且 $q < p$，则 $q \in \alpha$（向下封闭）
3. $\alpha$ 没有最大元

每个有理数 $r$ 对应一个分割 $r^* = \{p \in \mathbb{Q} \mid p < r\}$，无理数则对应没有有理端点的分割（如 $\sqrt{2}$ 对应 $\{p \in \mathbb{Q} \mid p^2 < 2\}$ 的正部）。

> [!tip] 分割的直观
> 每个"空隙"在 $\mathbb{Q}$ 中对应一个 Dedekind 分割——它是 $\mathbb{Q}$ 的一条"切割线"，完全确定了实数的位置。$\mathbb{R}$ 就是所有这样分割的集合。

#### 继承关系

| 性质 | $\mathbb{Q}$ | $\mathbb{R}$ (Dedekind 分割构造) |
|:----|:-------------|:-------------------------------|
| 域结构 | 通常加减乘除 | 分割上的运算定义 |
| 序结构 | 通常 $<$ | 分割的真子集关系 $\subsetneq$ |
| LUB 性质 | ❌ | ✅（分割的并集即为上确界） |
| 稠密性 | ✅ | ✅ |
| $\mathbb{Q}$ 嵌入 | — | $r \mapsto r^*$（保序域同构） |

---

## Theorem 1.20 — Archimedes 性质

> [!note] Archimedean Property
> 设 $x, y \in \mathbb{R}$，且 $x > 0$。则：
> (a) 存在正整数 $n$ 使得 $nx > y$
> (b) 存在正整数 $n$ 使得 $0 < \frac{1}{n} < x$

### 证明 (a) — 反证法 + LUB 性质

反设 $\forall n \in \mathbb{N},\; nx \leq y$。则集合 $A = \{nx \mid n \in \mathbb{N}\}$ 非空、上有界（$y$ 为上界）。由 $\mathbb{R}$ 的最小上界性质，令 $\alpha = \sup A$。

因为 $x > 0$，有 $\alpha - x < \alpha$，故 $\alpha - x$ 不是 $A$ 的上界。于是 $\exists m \in \mathbb{N}$ 使 $mx > \alpha - x$，从而：

$$(m+1)x = mx + x > (\alpha - x) + x = \alpha$$

但 $(m+1)x \in A$，这与 $\alpha$ 是 $A$ 的上界相矛盾。$\square$

### 证明 (b) — 直接来自 (a)

取 $y = 1$，则 $\exists n$ 使 $n x > 1$，两边同除以 $n$ 得 $x > 1/n$。$\square$

> [!warning] 直观意义
> Archimedes 性质说：**无论多小的正数 $x$，总存在正整数 $n$ 使 $1/n$ 比它还小**；**无论多大的 $y$，总能用 $x$ 的整数倍超过它**。它排除了"无穷小"和"无穷大"元素在 $\mathbb{R}$ 中的存在——$\mathbb{R}$ 中不存在非零"无穷小"，这是分析学可行性的核心保障。

### 推论：$\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密

由 (b) 可证明：对任意 $x, y \in \mathbb{R}$ 且 $x < y$，存在 $p \in \mathbb{Q}$ 使 $x < p < y$。

> 详细证明见 [[Density and Completeness#1.2 有理数的稠密性]]。

### Archimedes 性质在证明中的典型用法

Archimedes 性质在 $\mathbb{R}$ 分析中是几乎每步都用到的基础工具：

| 用法 | 步骤 | 目的 |
|:----|:-----|:-----|
| 取 $\exists n$ 使 $1/n < \varepsilon$ | 用 $x = \varepsilon$ 代入 (b) | 极限定义中的 $\varepsilon$-$N$ 论证 |
| 取 $\exists n$ 使 $n > N$ | 用 $x = 1$ 代入 (a) | 自然数无上界 |
| 取 $\exists n$ 使 $n(y-x) > 1$ | 用 $x = y-x$ 代入 (a) | 稠密性证明 |

---

## Theorem 1.21 — $n$ 次根的存在性

> 对任意 $x > 0$ 和正整数 $n$，存在**唯一**的正实数 $y$ 满足 $y^n = x$。

记 $y = x^{1/n}$ 或 $y = \sqrt[n]{x}$。

### 证明概要

**存在性**：考虑集合

$$E = \{ t \in \mathbb{R} \mid t > 0,\; t^n < x \}$$

- $E$ 非空（取 $t = \frac{x}{1+x}$，可证 $t^n < x$）
- $E$ 上有界（若 $t \geq 1+x$，则 $t^n \geq t \geq 1+x > x$，故 $1+x$ 是上界）

由 LUB 性质，令 $y = \sup E$，目标是证明 $y^n = x$。

**关键论证**——反证法分两步：

1. **若 $y^n < x$**：利用 Archimedes 性质构造 $t > y$ 且 $t^n < x$，则 $t \in E$，与 $y = \sup E$ 矛盾
2. **若 $y^n > x$**：同样利用 Archimedes 性质构造 $t < y$ 且 $t^n > x$，则 $t$ 是 $E$ 的上界，与 $y = \sup E$（最小上界）矛盾

因此 $y^n = x$。

**唯一性**：若 $0 < y_1 < y_2$，则 $y_1^n < y_2^n$（单调性），故至多一个满足 $y^n = x$。

> [!tip] $n$ 次根存在的意义
> 此为 $\mathbb{R}$"无空隙"的终极体现：$\mathbb{Q}$ 中不存在 $\sqrt{2}$，但在 $\mathbb{R}$ 中不仅存在 $\sqrt{2}$，而且**任意正数的任意 $n$ 次根都存在**。这标志着从"有间隙的有序域"到"完备的有序域"的质变。

### 与 $\mathbb{Q}$ 的对比

| 方程 | $\mathbb{Q}$ 中解 | $\mathbb{R}$ 中解 |
|:----|:-----------------|:-----------------|
| $p^2 = 2$ | ❌ | ✅ $\pm\sqrt{2}$ |
| $p^2 = 3$ | ❌ | ✅ $\pm\sqrt{3}$ |
| $p^3 = 5$ | ❌ | ✅ $\sqrt[3]{5}$ |
| 一般 $p^n = a$ | 几乎总无解 | ✅ 总有唯一正解 |

> $\mathbb{Q}$ 在根号运算下不封闭——这正是它"不完整"的表现。$\mathbb{R}$ 的封闭性是 LUB 性质的直接推论。

---

## 三大定理的逻辑依赖

```
Theorem 1.19 (ℝ 存在)
    │
    ├── LUB 性质 ──→ Theorem 1.20 (Archimedes 性质)
    │                      │
    │                      └──→ ℚ 在 ℝ 中稠密
    │
    ├── LUB 性质 + Archimedes ──→ Theorem 1.21 (n 次根存在)
    │
    └── LUB 性质 ──→ Theorem 1.11 (LUB ⇒ GLB)
```

> [!note] 关键洞察
> **仅有 LUB 性质不足以证明 $n$ 次根存在**——Archimedes 性质是必需的。这说明 $\mathbb{R}$ 的"完备性"是一个复合性质：LUB 提供框架，Archimedes 提供"无限逼近"的执行能力。

---

## $\mathbb{R}$ 的唯一性（序同构意义下）

虽然 $\mathbb{R}$ 的构造有多种方式（Dedekind 分割、Cauchy 序列、十进制展开），**所有满足 LUB 性质的有序域都是序同构的**。

这意味着：无论你如何构造"实数"，得到的数学结构在本质上都是同一个——$\mathbb{R}$。

> [!tip] 唯一性的直观
> 可以这样理解：所有"完备的有序域"都包含 $\mathbb{Q}$，且 $\mathbb{Q}$ 在其中稠密；而有序域的运算由 $\mathbb{Q}$ 上的运算通过极限唯一确定。因此完备性完全决定了 $\mathbb{R}$ 的结构。

---

## 相关笔记的层次

当前笔记与已有笔记的关系：

```
本笔记 (Real Field)
  ├── 前置：[[Density and Completeness]]（LUB 性质、有序集基础）
  ├── 前置：[[Field]]（有序域公理）
  ├── 前置：[[Group]]（域的基本构件）
  ├── 延伸：[[Boundedness#3.0 序关系与有序集 (Def 1.5–1.6)]]（有界性定义）
  └── 延伸：后续分析学所有内容（极限、连续、微分、积分均依赖 ℝ 的完备性）
```

### 与 [[Density and Completeness]] 的分工

| 笔记 | 侧重 |
|:----|:------|
| [[Density and Completeness]] | 有序集基础、稠密性 vs 完备性的概念辨析、$\sqrt{2}$ 空隙例证 |
| **Real Field**（本篇） | **定理 1.19–1.21 的陈述与证明**、Archimedes 性质、$n$ 次根存在性、$\mathbb{R}$ 的唯一性 |

两者互为补充：前者提供"为什么需要 $\mathbb{R}$"的概念动机，后者提供"$\mathbb{R}$ 究竟是什么"的严格定理。

---

## 参考来源

- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., McGraw-Hill 1976. (§1.4 The Real Field, Theorems 1.19–1.21)
- Dedekind, R. *Stetigkeit und Irrationale Zahlen*, 1872.
- Spivak, M. *Calculus*, 4th ed., Publish or Perish 2008. (Chapter 1, Basic Properties of Numbers)
