---
tags:
  - Math
  - Calculus
  - 基本原理
  - 概念性
title: Density and Completeness
created: 2026-06-08
modified:
---

# Density and Completeness

> [!abstract] 概述
> **稠密性 (Density)** 与 **完备性 (Completeness)** 是理解实数系 $\mathbb{R}$ 与有理数系 $\mathbb{Q}$ 根本差异的两个核心概念。$\mathbb{Q}$ 稠密但不完备，$\mathbb{R}$ 既稠密又完备——这一差异是整个数学分析（极限、连续、微分、积分）得以建立的基础。

## 0. Ordered Set 基础 (Rudin Def 1.5–1.10)

有序集 (ordered set) 是定义稠密性与完备性的底层框架。以下定义均来自 Rudin *Principles of Mathematical Analysis*。

### 0.1 序关系 (Order Relation, Def 1.5)

设 $S$ 是一个集合。$S$ 上的一个**序** (order) 是记作 $<$ 的关系，满足：

1. **三分性 (trichotomy)**：对任意 $x,y \in S$，以下三式恰有一个成立：
   $$x < y,\qquad x = y,\qquad y < x$$
2. **传递性 (transitivity)**：若 $x < y$ 且 $y < z$，则 $x < z$。

记号 $x \leq y$ 表示 $x < y$ 或 $x = y$，即 $x > y$ 的否定。

> [!warning] 这里的 `<` 不是算术"小于号"——它是抽象序关系
> 
> Rudin Def 1.5 中的 `<` **不是**基础算术中的数值小于号。它只是一个满足三分性和传递性的抽象二元关系，可以读作 "$x$ precedes $y$"（$x$ 先于 $y$）。
>
> | | 算术中的 `<` | Rudin Def 1.5 中的 `<` |
> |:--|:------------|:----------------------|
> | **定义方式** | 数值差为正 | 纯公理定义（三分性+传递性） |
> | **适用对象** | 仅数字（$\mathbb{R}, \mathbb{Q}$） | **任何集合** |
> | **额外性质** | 与加法乘法兼容（有序域公理） | 没有算术运算，只有序 |
> | **可以读作** | "小于" | "先于"、"排在前面" |
>
> 例：字母集 $S = \{a,b,c\}$ 上定义 $a < b < c$，这满足三分性和传递性——虽然 $\{a,b,c\}$ **根本不是数**，但 $<$ 在这里仍然是一个合法的序关系。
>
> `<` 直到 Def 1.17（有序域）才获得与 $+,\times$ 兼容的额外结构，变成你所熟悉的算术小于号。在此之前，它只是一个纯粹的**排序符号**。

### 0.2 有序集 (Ordered Set, Def 1.6)

定义了序的集合 $S$ 称为**有序集** (ordered set)。

> 例：$\mathbb{Q}$ 是有序集，其中 $r < s$ 定义为 $s - r$ 是正有理数。$\mathbb{R}$​ 也是有序集（见 Dedekind 分割构造）。

### 0.3 有界性 (Boundedness, Def 1.7)

设 $S$ 是有序集，$E \subset S$。

- 若 $\exists \beta \in S$ 使得 $\forall x \in E$ 有 $x \leq \beta$，则称 $E$ **上有界**，$\beta$ 为**上界**。
- **下界**定义类似（$\geq$ 取代 $\leq$）。

### 0.4 上确界与下确界 (Supremum & Infimum, Def 1.8)

若 $E$ 上有界，且 $\alpha \in S$ 满足：
1. $\alpha$ 是 $E$ 的上界；
2. 若 $\gamma < \alpha$，则 $\gamma$ 不是 $E$ 的上界；

则 $\alpha$ 称为 $E$ 的**最小上界** (least upper bound) 或**上确界** (supremum)，记作 $\alpha = \sup E$。

类似地，$\alpha = \inf E$ 表示 $\alpha$ 是 $E$ 的下界，且任何 $\beta > \alpha$ 都不是下界。

> **重要观察**：$\sup E$ 不一定属于 $E$（例如 $E = \{1/n \mid n = 1,2,3,\dots\}$，$\sup E = 1 \in E$ 但 $\inf E = 0 \notin E$）。

### 0.5 最小上界性质 (Least-Upper-Bound Property, Def 1.10)

有序集 $S$ 称为具有**最小上界性质**，若每个非空、上有界的子集 $E \subset S$ 在 $S$ 中都有上确界。

> $\mathbb{Q}$ **没有**此性质（见 §3 中 $A$ 与 $B$ 的例证），而 $\mathbb{R}$ **有**此性质——这正是 $\mathbb{R}$ 与 $\mathbb{Q}$ 的根本区别。

### 0.6 最小上界 ⇒ 最大下界 (Theorem 1.11)

若有序集 $S$ 具有最小上界性质，则它也同时具有**最大下界性质**：每个非空、下有界的子集 $B \subset S$ 均在 $S$ 中有下确界。

> 证明：设 $L$ 为 $B$ 的所有下界的集合，则 $L$ 非空、上有界，故 $\alpha = \sup L$ 存在；可证 $\alpha = \inf B$。

### 0.7 为什么还需要 Field？（从序到算术）

细心的读者会问：§0.1–0.6 只定义了序关系，但分析学涉及的不是排序，而是**加、减、乘、除**。为什么 Rudin 不直接从有序集跳到实数？

Rudin 引 field 的真正原因，恰恰在于其**内容的平凡性与形式上的不可或缺性**。

#### Field 公理——你所知的一切算术规则

域 (field) 是一组关于加法和乘法的公理（Def 1.12），共 **9 条**：

| 类别 | 公理 | 内容 |
|:----|:-----|:-----|
| 加法 | A1–A2 | 封闭性、交换律 |
| 加法 | A3    | 结合律 |
| 加法 | A4–A5 | 零元存在、负元存在 |
| 乘法 | M1–M2 | 封闭性、交换律 |
| 乘法 | M3    | 结合律 |
| 乘法 | M4–M5 | 单位元存在、逆元存在 |
| 分配 | D     | $x(y+z) = xy + xz$ |

Rudin  Remarks 1.13(c) 说得直白：

> *"It is worthwhile to prove that some of the familiar properties of Q are consequences of the field axioms; once we do this, we will not need to do it again for the real numbers and for the complex numbers."*

这正是"平凡性"的妙用——一次证明，三处适用。

#### 有序域定义 (Ordered Field, Rudin Def 1.17)

单独的有序集只能比较大小，不能做运算；单独的域能算数但不能比大小。**有序域**是二者的结合——它既是有序集（Def 1.6），又是域（Def 1.12），且序与运算必须兼容。

> [!note] 有序域 = 有序集 + 域 + 兼容公理
> 一个**有序域** $(F, +, \times, <)$ 满足三个条件：
> 1. **域结构**：$(F, +, \times)$ 是域（Def 1.12）——提供加法和乘法运算
> 2. **序结构**：$(F, <)$ 是有序集（Def 1.6）——提供大小比较
> 3. **兼容公理**：序与运算协调一致（见下方）

**兼容公理**（连接两个结构）：

1. **加法保序**：$y < z \implies x + y < x + z$（不等式两边可加同数）
2. **正数乘法保序**：$x > 0,\, y > 0 \implies xy > 0$（正数乘正数仍为正）

> 这两条公理确立了序关系 $<$ 与运算 $+,\times$ 之间的协调性。**缺少它们，集合就只是一个能算数但不能比大小的域（如 $\mathbb{C}$），或只能比大小但不能算数的有序集（如字母表）**。$\mathbb{C}$ 是域但**不能**成为有序域，因为 $i$ 的存在使第二条兼容公理无法满足（Exercise 1.8）。

#### 有序集 → 有序域：结构继承关系

有序域的定义可以拆解为三层继承：

```
有序集 (Def 1.6)           域 (Def 1.12)
  ┃ 三分性 + 传递性          ┃ (F,+) 和 (F\{0},×) 是阿贝尔群
  ┃ 提供 < 关系               ┃ 提供 + 和 × 运算
  ┗━━━━━━━━━━━━╋━━━━━━━━━━━━┛
               ┃
        兼容公理 (i)+(ii)
               ┃
         有序域 (Def 1.17)
         同时拥有 < 和 +,×
```

> 这种"先定义组件，再通过附加条件组合"的手法贯穿 Rudin 全书，是数学公理化搭建结构的典型方式。

这两条兼容公理看似"显然"，却排除了大量可能的代数结构（例：$\mathbb{C}$ 是域但**不能**成为有序域——见 Exercise 1.8）。

#### 为什么"平凡"反而是关键？

| 结构 | 有什么 | 缺什么 | 例子 |
|:----|:-------|:-------|:-----|
| 有序集 | 排序 | 没有算术 | 字母 $\{a,b,c\}$ |
| 域 | $+,\times$ | 没有排序 | $\mathbb{C}$ |
| 有序域 | 算术 + 排序 | 没有完备性 | $\mathbb{Q}$ |
| **$\mathbb{R}$** | 算术 + 排序 + **LUB** | 完备！ | $\mathbb{R}$ |

Rudin 的 Chapter 1 是一层一层搭建的：

```
     集合论 (Def 1.3–1.4)
        ↓
    有序关系 (Def 1.5)    ← 引理/工具
        ↓
    有序集 (Def 1.6)     ← 只能排序
        ↓
     域公理 (Def 1.12)   ← 只能算术    这两个平行，彼此独立
        ↓
    有序域 (Def 1.17)    ← 同时有算术和排序
        ↓
  最小上界性质 (Def 1.10) ← 完备性，从有序集中"借来"
        ↓
   ℝ 存在 (Theorem 1.19)  ← 唯一兼具三者
```


## 1. 稠密性 (Density)

### 1.1 定义

在一个有序集 $S$ 中，若对任意 $x, y \in S$ 且 $x < y$，总存在 $z \in S$ 使得 $x < z < y$，则称 $S$ 是**稠密的 (dense in itself)**。

### 1.2 有理数的稠密性

$\mathbb{Q}$ 是稠密的：若 $r < s$ 且 $r, s \in \mathbb{Q}$，则

$$
\frac{r + s}{2} \in \mathbb{Q}, \quad r < \frac{r+s}{2} < s
$$

更强地，Rudin 定理 1.20(b) 指出 $\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密：对任意 $x, y \in \mathbb{R}$ 且 $x < y$，总存在 $p \in \mathbb{Q}$ 使得 $x < p < y$。

> [!tip] 直观理解
> 稠密性意味着集合中任意两点之间总有第三个点，不存在"相邻"的元素。你可以无限"放大"任意区间，总能找到其中的有理数。

## 2. 完备性 (Completeness)

### 2.1 定义（最小上界性质）

一个有序集 $S$ 称为**完备的**，若它满足**最小上界性质 (Least-Upper-Bound Property)**：每个非空、有上界的子集 $E \subset S$ 在 $S$ 中都有上确界 $\sup E$。

### 2.2 实数的完备性

Rudin 定理 1.19 断言：**存在一个具有最小上界性质的有序域 $\mathbb{R}$，且 $\mathbb{Q} \subset \mathbb{R}$ 作为子域。**

## 3. Rudin 经典例证：$\sqrt{2}$ 处的"空隙"

Rudin 在《Principles of Mathematical Analysis》第一章引言中给出了一个精妙的例证，同时展示了 $\mathbb{Q}$ 的稠密性和不完备性。

### 3.1 问题：$p^2 = 2$ 无有理数解

设 $p = m/n$（$m, n$ 不同时为偶数），则

$$
p^2 = 2 \quad\Longrightarrow\quad m^2 = 2n^2 \tag{1.2}
$$

- $m^2$ 为偶数 $\Rightarrow$ $m$ 为偶数 $\Rightarrow$ $m^2$ 被 4 整除
- $2n^2$ 被 4 整除 $\Rightarrow$ $n^2$ 为偶数 $\Rightarrow$ $n$ 为偶数
- 与"不同时为偶数"矛盾 $\Rightarrow$ 无有理数 $p$ 满足 $p^2 = 2$

**含义**：$\sqrt{2}$ 这个"位置"在 $\mathbb{Q}$ 中不存在，是有理数系的一个**空隙 (gap)**。

### 3.2 构造 $A$ 与 $B$

定义两个集合：

$$
\begin{aligned}
A &= \{ p \in \mathbb{Q}^+ \mid p^2 < 2 \} \\
B &= \{ p \in \mathbb{Q}^+ \mid p^2 > 2 \}
\end{aligned}
$$

Rudin 构造了一个精妙的变换：

$$
q = p - \frac{p^2 - 2}{p + 2} = \frac{2p + 2}{p + 2} \tag{1.3}
$$

其性质为：

$$
q^2 - 2 = \frac{2(p^2 - 2)}{(p + 2)^2} \tag{1.4}
$$

### 3.3 结论

- **$A$ 中无最大元素**：$\forall p \in A,\ \exists q \in A$ 使得 $q > p$
- **$B$ 中无最小元素**：$\forall p \in B,\ \exists q \in B$ 使得 $q < p$

这意味着 $A$ 在 $\mathbb{Q}$ 中**没有上确界**（它的上确界应为 $\sqrt{2} \notin \mathbb{Q}$），$B$ 在 $\mathbb{Q}$ 中**没有下确界**。

> [!warning] 关键洞察
> 尽管 $\mathbb{Q}$ 是稠密的（任意两个有理数之间总有另一个有理数），$A$ 和 $B$ 之间却存在一个"空隙"——$\sqrt{2}$。$\mathbb{Q}$ 稠密但**不完备**。

## 4. 稠密性 vs 完备性：关系图解

| 性质 | 稠密性 | 完备性 |
|------|--------|--------|
| **核心问题** | 两点之间有无元素？ | 每个有界集合有无确界？ |
| **$\mathbb{Q}$** | ✅ 是 | ❌ 否 |
| **$\mathbb{R}$** | ✅ 是 | ✅ 是 |
| **本质** | 序的**局部**性质 | 序的**整体**性质 |
| **直观** | 沙子铺满桌面 | 桌面没有裂缝 |

> [!note] 核心辨析
> **稠密 $\neq$ 无空隙**。$\mathbb{Q}$ 虽有稠密性，但 $\sqrt{2}$ 处存在空隙——因为没有有理数的平方等于 2。**完备性**才是"无空隙"的确切数学表述。实数系的构造（Dedekind 分割）正是通过填补所有这类空隙来建立 $\mathbb{R}$。

## 5. 为什么这对分析学至关重要

如果没有完备性：

- **极限可能不存在**：有理数序列 $1, 1.4, 1.41, 1.414, \dots$ 在 $\mathbb{Q}$ 中不收敛（它应该趋向 $\sqrt{2}$）
- **介值定理不成立**：连续函数 $f(x) = x^2$ 在 $1$ 和 $2$ 之间取不到值 $2$
- **单调有界序列可能无极限**

完备性保证了所有 Cauchy 序列收敛、有界集合有确界——这些是微积分学的基石。

## 相关链接

- [[Boundedness]]
- [[limit]]
- [[continuity]]

## 参考来源

- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., Chapter 1, Introduction
