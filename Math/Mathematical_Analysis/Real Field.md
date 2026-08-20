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
> **实数域 (Real Field)** 章节（Rudin §1.4）是整个数学分析的基石。前 3 个子节分别搭建了有序集、域和有序域，本节将它们融合为 $\mathbb{R}$ 的完整刻画：**$\mathbb{R}$ 是满足最小上界性质（LUB）的有序域，并且 $\mathbb{Q}$ 作为其子域**。4 个核心定理（1.19–1.22）完成这一构建。

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

每个有理数 $r$ 对应一个分割 $r^* = \{p \in \mathbb{Q} \mid p < r\}$，无理数则对应没有有理端点的分割。例如 $\sqrt{2}$ 对应：

$$\{p \in \mathbb{Q} \mid p < 0\} \cup \{p \in \mathbb{Q} \mid p \geq 0,\; p^2 < 2\}$$

即所有负有理数与平方小于 $2$ 的正有理数的并集，简洁写为 $\{p \in \mathbb{Q} \mid p < 0 \;\text{或}\; p^2 < 2\}$。

> [!tip] 分割的直观
> 每个"空隙"在 $\mathbb{Q}$ 中对应一个 Dedekind 分割——它是 $\mathbb{Q}$ 的一条"切割线"，完全确定了实数的位置。$\mathbb{R}$ 就是所有这样分割的集合。

#### 继承关系

| 性质 | $\mathbb{Q}$ | $\mathbb{R}$ (Dedekind 分割构造) |
|:----|:-------------|:-------------------------------|
| 域结构 | 通常加减乘除 | 分割上的运算定义 |
| 序结构 | 通常 $<$ | 分割的真子集关系 $\subsetneq$ |
| LUB 性质 | ❌ | ✅（分割的并集即为上确界） |
| 自身稠密（任意两点间有第三点） | ✅ | ✅ |
| $\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密 | — | ✅（Archimedes 性质推论） |
| $\mathbb{Q}$ 嵌入 | — | $r \mapsto r^*$（保序域同构） |

---

## Theorem 1.20 — Archimedes 性质与 $\mathbb{Q}$ 的稠密性

> [!note] Archimedean Property (Rudin Theorem 1.20)
> 设 $x, y \in \mathbb{R}$，且 $x > 0$。则：
> 
> (a) 存在正整数 $n$ 使得 $nx > y$（**Archimedes 性质**）
> 
> (b) 若 $x < y$，则存在 $p \in \mathbb{Q}$ 使得 $x < p < y$（**$\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密**）

Part (a) 称为 $\mathbb{R}$ 的 **Archimedes 性质**（archimedean property）；Part (b) 说 $\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密：任意两个实数之间都有有理数。

### 证明 (a) — 反证法 + LUB 性质

反设 $\forall n \in \mathbb{N},\; nx \leq y$。则集合 $A = \{nx \mid n \in \mathbb{N}\}$ 非空、上有界（$y$ 为上界）。由 $\mathbb{R}$ 的最小上界性质，令 $\alpha = \sup A$。

因为 $x > 0$，有 $\alpha - x < \alpha$，故 $\alpha - x$ 不是 $A$ 的上界。于是 $\exists m \in \mathbb{N}$ 使 $mx > \alpha - x$，从而：

$$(m+1)x = mx + x > (\alpha - x) + x = \alpha$$

但 $(m+1)x \in A$，这与 $\alpha$ 是 $A$ 的上界相矛盾。$\square$

### 推论 — $1/n$ 任意小

取 $y = 1$，则 $\exists n$ 使 $nx > 1$，两边同除以 $n$ 得 $x > 1/n$。$\square$

> [!warning] 直观意义
> Archimedes 性质说：**无论多小的正数 $x$，总存在正整数 $n$ 使 $1/n$ 比它还小**；**无论多大的 $y$，总能用 $x$ 的整数倍超过它**。它排除了"无穷小"和"无穷大"元素在 $\mathbb{R}$ 中的存在——$\mathbb{R}$ 中不存在非零"无穷小"，这是分析学可行性的核心保障。

### 证明 (b) — $\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密

由于 $x < y$，$y - x > 0$。由 (a) 取正整数 $n$ 使

$$n(y-x) > 1$$

再用 (a) 取正整数 $m_1, m_2$ 使 $m_1 > nx$、$m_2 > -nx$，于是 $-m_2 < nx < m_1$。故存在整数 $m$（$-m_2 \leq m \leq m_1$）使

$$m - 1 \leq nx < m$$

合并不等式得 $nx < m \leq 1 + nx < ny$。因 $n > 0$，两边除以 $n$：

$$x < \frac{m}{n} < y$$

取 $p = m/n$ 即得。$\square$

> 证明分三步：先用 (a) 把间隔 $y-x$ 放大到 $>1$；再用 (a) 把 $nx$ 夹在两个整数之间；最后取整数 $m$ 使 $m/n$ 落进 $(x, y)$。每一步都依赖 Archimedes 性质——它是稠密性的燃料。

### Archimedes 性质在证明中的典型用法

Archimedes 性质在 $\mathbb{R}$ 分析中是几乎每步都用到的基础工具：

| 用法 | 步骤 | 目的 |
|:----|:-----|:-----|
| 取 $\exists n$ 使 $1/n < \varepsilon$ | 用 $x = \varepsilon$ 代入推论（(a) 取 $y=1$） | 极限定义中的 $\varepsilon$-$N$ 论证 |
| $\exists n$ 使 $n > N$ | 用 $x = 1$ 代入 (a) | 自然数无上界 |
| 取 $\exists n$ 使 $n(y-x) > 1$ | 用 $x = y-x$ 代入 (a) | 稠密性证明 |

---

## Theorem 1.21 — $n$ 次根的存在性

> 对任意 $x > 0$ 和正整数 $n$，存在**唯一**的正实数 $y$ 满足 $y^n = x$。

记 $y = x^{1/n}$ 或 $y = \sqrt[n]{x}$。

### 证明概要

**存在性**：考虑集合

$$E = \{ t \in \mathbb{R} \mid t > 0,\; t^n < x \}$$

- $E$ 非空（取 $t = \frac{x}{1+x}$，可证 $t^n < x$）
- $E$ 上有界：若 $t \geq 1+x$，则 $t^n \geq t \geq 1+x > x$，故 $t \notin E$，从而所有 $t \in E$ 均满足 $t < 1+x$，即 $1+x$ 是上界

由最小上界性质，令 $y = \sup E$，目标是证明 $y^n = x$。

**关键论证**——反证法分两步，核心是利用恒等式 $b^n - a^n = (b-a)(b^{n-1} + b^{n-2}a + \cdots + a^{n-1})$，得到不等式：

$$b^n - a^n < (b-a) \cdot n \cdot b^{n-1} \quad (0 < a < b)$$

1. **若 $y^n < x$**：选 $h$ 满足 $0 < h < 1$ 且 $h < \dfrac{x - y^n}{n(1+y)^{n-1}}$（由 Archimedes 性质确保这样的 $h$ 存在）。令 $t = y + h$，则 $t > y$ 且

   $$
   \begin{aligned}
   t^n - y^n &= (y+h)^n - y^n \\
   &< h \cdot n \cdot (y+h)^{n-1} \quad \text{（由上述不等式）} \\
   &< h \cdot n \cdot (1+y)^{n-1} \quad \text{（因 $y+h < 1+y$）} \\
   &< x - y^n \quad \text{（由 $h$ 的选择）}
   \end{aligned}
   $$

   故 $t^n < x$，即 $t \in E$，与 $y = \sup E$ 矛盾。

2. **若 $y^n > x$**：令 $k = \dfrac{y^n - x}{n y^{n-1}}$。由 $y^n > x$ 得 $k > 0$；又 $k < \dfrac{y^n}{n y^{n-1}} = \dfrac{y}{n} < y$，故 $0 < k < y$。令 $t = y - k$，则 $0 < t < y$ 且

   $$
   \begin{aligned}
   y^n - t^n &= y^n - (y-k)^n \\
   &< k \cdot n \cdot y^{n-1} \quad \text{（由上述不等式，取 $a = y-k,\, b = y$）} \\
   &= y^n - x
   \end{aligned}
   $$

   故 $t^n > x$，即 $t$ 是 $E$ 的上界，与 $y = \sup E$（最小上界）矛盾。

因此 $y^n = x$。

> 上述构造同时使用两条工具：最小上界性质给出 $y = \sup E$（存在性），Archimedes 性质保证可选到足够小的正数 $h$（扰动可行性）——而后者本身也是最小上界性质的推论（定理 1.20）。这说明 $\mathbb{R}$ 的完备性如何层层"派生"出执行能力。

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

## Theorem 1.22 — 小数表示

> 对每个 $x > 0$，存在十进制展开 $n_0.n_1n_2n_3\cdots$，使 $x$ 等于其所有截断数 $n_0 + \frac{n_1}{10} + \cdots + \frac{n_k}{10^k}$（$k = 0, 1, 2, \dots$）组成的集合 $E$ 的上确界。反之，每个无限小数展开都对应一个实数——即其截断集的上确界。

### 构造（贪心逐位）

1. $n_0$ = 满足 $n_0 \leq x$ 的最大整数。**存在性依赖 Archimedes 性质**——否则"最大整数"不保证存在；
2. 已选 $n_0, \dots, n_{k-1}$ 后，$n_k$ = 使 $n_0 + \frac{n_1}{10} + \cdots + \frac{n_k}{10^k} \leq x$ 的最大数字（$n_k \in \{0, \dots, 9\}$）。

截断和从左边逼近 $x$，故 $x = \sup E$。

### 反向

任意小数展开 $n_0.n_1n_2\cdots$ 的截断集 $E$ 有上界（如 $n_0 + 1$），由最小上界性质 $\sup E$ 存在，该展开就是 $\sup E$ 的十进制展开。

> [!tip] 桥梁作用
> 1.22 把公理化构造的 $\mathbb{R}$ 与日常的十进制表示接轨：小数只是"从左边逼近 $x$ 的有理数阶梯"的极限。Rudin 明确说全书不再使用小数，故只给构造不给细节。注意 $0.9999\cdots$ 与 $1.0000\cdots$ 对应同一个上确界——十进制表示不唯一，Rudin 未讨论这一点。

---

## 四个定理的逻辑依赖

```
Theorem 1.19 (ℝ 存在)
    │
    ├── LUB 性质 ──→ Theorem 1.20 (Archimedes 性质)
    │                      │
    │                      └──→ ℚ 在 ℝ 中稠密
    │
    ├── LUB 性质 + Archimedes ──→ Theorem 1.21 (n 次根存在)
    │
    ├── Archimedes 性质 ──→ Theorem 1.22 (小数表示)
    │
    └── LUB 性质 ──→ Theorem 1.11 (LUB ⇒ GLB)
```

> [!note] 关键洞察
> 1.21 的证明同时调用两条工具：最小上界性质给出 $y = \sup E$（存在性），Archimedes 性质保证能选到足够小的 $h$（扰动可行性）——而 Archimedes 性质本身也是 1.19 的推论。完备性不是单一公理，而是一台层层派生工具的"存在机器"。

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
| **Real Field**（本篇） | **定理 1.19–1.22 的陈述与证明**、Archimedes 性质、$n$ 次根存在性、小数表示、$\mathbb{R}$ 的唯一性 |

两者互为补充：前者提供"为什么需要 $\mathbb{R}$"的概念动机，后者提供"$\mathbb{R}$ 究竟是什么"的严格定理。

---

## 参考来源

- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., McGraw-Hill 1976. (§1.4 The Real Field, Theorems 1.19–1.22)
- Dedekind, R. *Stetigkeit und Irrationale Zahlen*, 1872.
- Spivak, M. *Calculus*, 4th ed., Publish or Perish 2008. (Chapter 1, Basic Properties of Numbers)
