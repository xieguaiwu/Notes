---
tags:
  - Calculus
  - Math
  - 证明
  - 定义性
title: Continuity and Boundedness
created: 2025-11-24T23:04:00
modified:
---
# Boundedness
## 1. Def
假如对于$f:A\to\mathbb{R}$
$$\exists M>0(M\in\mathbb{R})\forall x(x\in A)|f(x)|\leq M$$
则函数$f$是有界的
假如对于$\forall x\in A$同时有
$$f(x)\leq M$$
$$f(x)\geq m$$
则$f$同时有上界 (upper bound) 和下界 (lower bound)

## 2. Continuity & Boundedness
对于下方两个函数：
![[continuity_and_boundedness.png]]
此函数为$f(x)$，其中$x\neq 1$，但$\lim_{x\to 1}f(x)=0$

同时有$g(x)$
![[continuity_and_boundedness2.png]]
其为分段函数，当$x\leq 2$时$g(x)=1$，反之则$g(x)=-1$，这意味着$\neg\exists\lim_{x\to 2}g(x)$

考虑以下极限：
>$$\lim_{x\to 1}(f(x)\cdot g(x+1))$$


可以意识到不确定性，因为已知
$$\neg\exists\lim_{x\to 2}g(x)$$
但是根据**1**可知函数$g$有界
$$(\forall x)|g(x)|\leq 1$$

回到一开始的极限中，考虑到极限法则：
$$\lim_{x\to a}(f(x)\cdot g(x))=L\cdot M$$
而
$$\lim_{x\to 1}f(x)=0$$
那么原极限等同于
$$\lim_{x\to 1}(f(x)\cdot g(x+1)) = 0 \cdot M = 0$$
带入$M=1$后
$$\lim_{x\to 1}(f(x)\cdot g(x+1))=0\cdot 1=0$$

## 3. Rudin 体系中的有界性

以下内容整理自 Walter Rudin *Principles of Mathematical Analysis* (3rd ed.) 中的相关定义与定理。

### 3.0 序关系与有序集 (Def 1.5–1.6)

#### 序关系 (Order Relation, Def 1.5)

设 $S$ 是一个集合。$S$ 上的一个**序**是记作 $<$ 的关系，满足：

1. **三分性 (trichotomy)**：$\forall x,y \in S$，以下三式恰有一个成立：$x < y,\, x = y,\, y < x$。
2. **传递性 (transitivity)**：若 $x < y$ 且 $y < z$，则 $x < z$。

记号 $x \leq y$ 表示 $x < y$ 或 $x = y$，即 $x > y$ 的否定。

> [!warning] 这里的 `<` 不是算术"小于号"——它是抽象序关系
> 
> Rudin Def 1.5 中的 `<` **不是**基础算术中的数值小于号。它只是一个满足三分性和传递性的抽象二元关系，可以读作 "$x$ precedes $y$"（$x$ 先于 $y$）。任何满足这两条公理的集合 $S$ 都构成有序集，无论元素是不是数字。例如字母集 $\{a,b,c\}$ 上定义 $a<b<c$ 也同样合法。
>
> 算术 `<` 是 **Def 1.17 有序域**引入 $+,\times$ 兼容后才有的具体实例。参见 [[Density and Completeness#0.1 序关系 (Order Relation, Def 1.5)|完整对比]]。

#### 有序集 (Ordered Set, Def 1.6)

定义了序的集合 $S$ 称为**有序集**。

> 例：$\mathbb{Q}$ 中定义 $r < s$ 为 $s - r$ 是正有理数，则 $\mathbb{Q}$ 是有序集。

### 3.1 有序集上的有界性 (Def 1.7)

设 $S$ 是一个**有序集** (ordered set)，$E \subset S$。

- 若 $\exists \beta \in S$ 使得 $\forall x \in E$ 有 $x \leq \beta$，则称 $E$ **上有界** (bounded above)，$\beta$ 为 $E$ 的一个**上界** (upper bound)。
- **下界** (lower bound) 的定义类似（将 $\leq$ 换为 $\geq$）。

#### 上确界 / 下确界 (Def 1.8)

若 $E$ 上有界，且 $\alpha \in S$ 满足：
1. $\alpha$ 是 $E$ 的上界；
2. 若 $\gamma < \alpha$，则 $\gamma$ 不是 $E$ 的上界；

则称 $\alpha$ 为 $E$ 的**最小上界** (least upper bound) 或**上确界** (supremum)，记作 $\alpha = \sup E$。

**下确界** (infimum) $\alpha = \inf E$ 定义为 $\alpha$ 是 $E$ 的下界，且任何 $\beta > \alpha$ 都不是下界。

> **最小上界性质** (least-upper-bound property, Def 1.10)：若 $S$ 是有序集，且任一非空上有界子集 $E \subset S$ 都在 $S$ 中存在上确界，则称 $S$ 具有最小上界性质。$\mathbb{R}$ 具有此性质，而 $\mathbb{Q}$ 没有。

### 3.2 度量空间中的有界集 (Def 2.18(i))

设 $X$ 是度量空间 (metric space)，$E \subset X$。若存在实数 $M$ 和点 $q \in X$ 使得

$$\forall p \in E,\; d(p,q) < M$$

则称 $E$ 是**有界**的。

> 注：在 $\mathbb{R}^k$ 中，有界集等价于能被某个有限半径的球覆盖。

#### 相关定理

**Theorem 2.28**：设 $E$ 是 $\mathbb{R}$ 的非空上有界子集，$y = \sup E$。则 $y \in \overline{E}$（即 $y$ 是 $E$ 的闭包中的点）。特别地，若 $E$ 是闭集，则 $y \in E$。

**Theorem 2.41 (Heine-Borel)**：$\mathbb{R}^k$ 中的子集是紧致的 $\iff$ 它是闭且有界的。

### 3.3 有界序列 (Def 3.1 & Theorem 3.14)

序列 $(p_n)$ 称为**有界**的，当且仅当其值域 (range) 是有界集。

**Theorem 3.2(c)**：若 $(p_n)$ 收敛，则 $(p_n)$ 有界。但反之不真（有界序列不一定收敛）。

**Theorem 3.14（单调序列基本定理）**：设 $(s_n)$ 是单调序列，则 $(s_n)$ 收敛 $\iff$ $(s_n)$ 有界。

> 这是 $\mathbb{R}$ 中单调有界收敛定理的严格表述。证明利用了 $\mathbb{R}$ 的上确界性质：若 $s_n \leq s_{n+1}$ 且有界，令 $s = \sup E$（$E$ 为值域），则 $s_n \to s$。

#### 上极限与下极限 (Def 3.16)

设 $(s_n)$ 为实数列，$E$ 为所有子列极限（含 $\pm\infty$）的集合，则

$$\limsup_{n\to\infty} s_n = \sup E, \qquad \liminf_{n\to\infty} s_n = \inf E$$

**Theorem 3.17(b)**：若 $x > \limsup s_n$，则存在 $N$ 使得 $n \geq N$ 时 $s_n < x$。

### 3.4 有界函数 (Def 4.13)

映射 $f: E \to \mathbb{R}^k$ 称为**有界**的，若存在实数 $M$ 使得

$$\forall x \in E,\; |f(x)| \leq M$$

### 3.5 紧致性与有界性

**Theorem 4.15**：若 $f$ 是紧致度量空间 $X$ 到 $\mathbb{R}^k$ 的连续映射，则 $f(X)$ 是闭且有界的。因此 $f$ **有界**。

**Theorem 4.16（极值定理）**：若 $f$ 是紧致度量空间 $X$ 上的连续实函数，则 $f$ 在 $X$ 上取得最大值和最小值，即存在 $p,q \in X$ 使得

$$f(p) = \sup_{x\in X} f(x), \qquad f(q) = \inf_{x\in X} f(x)$$

**Theorem 4.20（紧致性不可缺）**：设 $E \subset \mathbb{R}^1$ 非紧致，则

1. 存在 $E$ 上的无界连续函数（如 $f(x) = 1/(x-x_0)$，其中 $x_0$ 是 $E$ 的极限点但 $x_0 \notin E$）；
2. 存在 $E$ 上的有界连续函数但没有最大值（如 $g(x) = 1/[1+(x-x_0)^2]$）；
3. 若 $E$ 还有界，则存在 $E$ 上不一致连续的函数。

> 这一定理深刻说明了：**有界性 + 连续性 $\neq$ 极值存在**，紧致性才是关键。

### 3.6 Riemann 积分与有界性 (Chapter 6)

在 Riemann-Stieltjes 积分理论中，被积函数 $f$ 的**有界性**是积分定义的前提：

对于每个分划 $P$，定义上下和：

$$L(P,f,\alpha) = \sum_{i=1}^n m_i \Delta\alpha_i, \quad U(P,f,\alpha) = \sum_{i=1}^n M_i \Delta\alpha_i$$

其中 $m_i = \inf f(x),\; M_i = \sup f(x)$ 在区间 $[x_{i-1}, x_i]$ 上。因为 $f$ 有界，$L$ 和 $U$ 才构成有界集，上下积分才得以定义。

### 小结：Rudin 中有界性的三个层次

| 层次 | 定义域 | 有界的含义 | 关键定理 |
|:----|:-------|:-----------|:---------|
| **有序集** | $S$ (ordered set) | $\exists \beta,\; \forall x\in E,\; x \leq \beta$ | 最小上界性质 (Def 1.10) |
| **度量空间** | $(X,d)$ | $\exists M,q,\; \forall p\in E,\; d(p,q) < M$ | Heine-Borel (Thm 2.41) |
| **函数/序列** | $f:E\to\mathbb{R}^k$ / $(p_n)$ | $\lVert f(x)\rVert \leq M$ / range bounded | Thm 4.15 (连续+紧致→有界) |

*参考：Walter Rudin, Principles of Mathematical Analysis, 3rd ed., McGraw-Hill 1976.*
