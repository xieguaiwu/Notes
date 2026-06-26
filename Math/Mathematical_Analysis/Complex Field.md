---
title: Complex Field
tags:
  - Math
  - MathematicalAnalysis
  - 定义性
  - 基本原理
created: 2026-06-24
modified:
---

# Complex Field

> [!abstract] 概述
> **复数域 (Complex Field)** 章节（Rudin §1.6）在实数域 $\mathbb{R}$ 的基础上，将数系扩张到 $\mathbb{C}$。复数被定义为实数的有序对 $(a,b)$，通过精心设计的加法和乘法运算构成一个域。$\mathbb{R}$ 作为子域嵌入 $\mathbb{C}$（对应形如 $(a,0)$ 的元素），而虚数单位 $i = (0,1)$ 满足 $i^2 = -1$。本章建立了复数的共轭、绝对值等基本运算，并最终证明了 **Schwarz 不等式**，这是整个分析学中最重要的不等式之一。

## 结构上下文

### Rudin Chapter 1 的搭建逻辑

```
有序集 (Def 1.5)     域公理 (Def 1.12)
      |                    |
   有序域 (Def 1.17)      |
      |                    |
 The Real Field (S1.4) ---> Complex Field (S1.6) ---> Euclidean Spaces (S1.7)
 R = 有序域 + LUB 性质      C = R^2 上的域结构         R^k 上的度量结构
```

> 复数域的构造完全不依赖 $\mathbb{R}$ 的序结构——事实上 $\mathbb{C}$ **不能**成为有序域（见 Exercise 1.8），这解释了为何 $\mathbb{C}$ 的定义需要新的构造方法，而非简单继承 $\mathbb{R}$ 的序。

### 本节定位

| 之前 (§1.4–1.5) | 现在 (§1.6) | 之后 (§1.7) |
|:----------------|:------------|:------------|
| $\mathbb{R}$：完备的有序域 | $\mathbb{C}$：从 $\mathbb{R}$ 构造的域 | $\mathbb{R}^k$：欧氏空间 |
| 三大定理 (1.19–1.21) | 域验证 + 共轭 + 模长 + Schwarz 不等式 | 度量结构与拓扑 |
| $\mathbb{Q} \subset \mathbb{R}$ | $\mathbb{R} \subset \mathbb{C}$（作为子域） | $\mathbb{R}^k$ 的向量空间结构 |

---

## Definition 1.24 — 复数的定义

> 一个**复数**是实数的一个**有序对** $(a, b)$。这里"有序"意味着 $(a,b) \neq (b,a)$（当 $a \neq b$ 时）。

设 $x = (a,b),\; y = (c,d)$ 为两个复数，定义：

- **加法**：$x + y = (a + c,\; b + d)$
- **乘法**：$xy = (ac - bd,\; ad + bc)$

> [!tip] 乘法定义的来源
> 这并非随意定义。若将 $(a,b)$ 视为 $a + bi$，则自然乘法为：
> $$(a+bi)(c+di) = ac + ad\,i + bc\,i + bd\,i^2 = (ac - bd) + (ad + bc)i$$
> 这正是有序对乘法 $xy = (ac-bd,\; ad+bc)$。Rudin 有意先定义有序对运算，再证明 $i^2 = -1$——从而避免一开始就引入"$\sqrt{-1}$"的神秘性。

---

## Theorem 1.25 — $\mathbb{C}$ 构成域

> 上述加法和乘法定义使全体复数构成一个**域**，其中零元为 $(0,0)$，单位元为 $(1,0)$。

### 验证要点

| 公理 | 验证 |
|:-----|:------|
| 加法交换/结合 | 继承自 $\mathbb{R}$ 的交换/结合律 |
| 加法零元 | $(0,0)$ |
| 加法逆元 | $-(a,b) = (-a,-b)$ |
| 乘法交换/结合 | 直接计算验证 |
| 乘法单位元 | $(1,0)$ |
| 乘法逆元 | $\displaystyle\frac{1}{(a,b)} = \left(\frac{a}{a^2+b^2},\; \frac{-b}{a^2+b^2}\right)$，当 $(a,b) \neq (0,0)$ |
| 分配律 | 直接展开验证 |

> [!note] 关键观察
> 乘法逆元的定义依赖 $a^2 + b^2 > 0$，而这由 Proposition 1.18(d) 保证（$\mathbb{R}$ 中非零数的平方和为正）。这一特征在后续定义复数的**模**时再次出现。

### $\mathbb{R}$ 作为子域的嵌入

**Theorem 1.26**: $(a,0) + (b,0) = (a+b,0)$，$(a,0)(b,0) = (ab,0)$。

因此可以将 $(a,0)$ 与实数 $a$ 等同。$\mathbb{R}$ 作为 $\mathbb{C}$ 的子域嵌入。

```
                    ℂ
                   ╱
            ╲    ╱
             ℝ ———
            ╱
           ℚ
```

---

## 虚数单位 $i$ 与标准表示

### Definition 1.27

$$i = (0,1)$$

### Theorem 1.28 — $i^2 = -1$

$$i^2 = (0,1)(0,1) = (-1,0) = -1$$

### Theorem 1.29 — 有序对与 $a+bi$ 的等价性

$$(a,b) = a + bi$$

其中 $a$ 为**实部** (real part)，$b$ 为**虚部** (imaginary part)：

$$\operatorname{Re}(z) = a,\qquad \operatorname{Im}(z) = b$$

> [!tip] 构造的意义
> Rudin 的构造完全避免了 $\sqrt{-1}$ 的神秘性。复数被直接定义为实数的有序对，这是 $\mathbb{C}$ 作为 $\mathbb{R}^2$ 上的代数结构的自然呈现。$i^2 = -1$ 是**定理**而非定义，它从有序对的乘法中推导出来。

---

## 共轭 (Conjugate)

### Definition 1.30

$$z = a + bi \quad\Longrightarrow\quad \overline{z} = a - bi$$

### Theorem 1.31 — 共轭的性质

| 性质 | 公式 |
|:----|:-----|
| (a) 和的共轭 | $\overline{z + w} = \overline{z} + \overline{w}$ |
| (b) 积的共轭 | $\overline{zw} = \overline{z} \cdot \overline{w}$ |
| (c) 实部与虚部 | $z + \overline{z} = 2\operatorname{Re}(z)$，$z - \overline{z} = 2i\operatorname{Im}(z)$ |
| (d) 模平方 | $z\overline{z} = a^2 + b^2$（正实数，$z \neq 0$ 时为正） |

#### 证明 (d)

设 $z = a + bi$，则 $z\overline{z} = (a+bi)(a-bi) = a^2 + b^2$（由乘法定义直接计算）。

---

## 绝对值（模）

### Definition 1.32

$$|z| = (z\overline{z})^{1/2} = \sqrt{a^2 + b^2}$$

$|z|$ 的存在性和唯一性由 Theorem 1.21（$n$ 次根的存在性）保证。当 $z = x \in \mathbb{R}$ 时，$|x| = \sqrt{x^2}$，与实数的绝对值一致。

### Theorem 1.33 — 模的性质

| 性质 | 公式 |
|:----|:-----|
| (a) 正定性 | $|z| > 0$ 除非 $z=0$，$|0| = 0$ |
| (b) 共轭的模 | $|\overline{z}| = |z|$ |
| (c) 积的模 | $|zw| = |z|\,|w|$ |
| (d) 实部控制 | $|\operatorname{Re}(z)| \leq |z|$ |
| (e) **三角不等式** | $|z + w| \leq |z| + |w|$ |

#### 三角不等式的证明

$$\begin{aligned}
|z+w|^2 &= (z+w)(\overline{z}+\overline{w}) \\
&= z\overline{z} + z\overline{w} + \overline{z}w + w\overline{w} \\
&= |z|^2 + 2\operatorname{Re}(z\overline{w}) + |w|^2 \\
&\leq |z|^2 + 2|z\overline{w}| + |w|^2 \\
&= |z|^2 + 2|z||w| + |w|^2 = (|z| + |w|)^2
\end{aligned}$$

两边取平方根即得。这里利用了 $|z\overline{w}| = |z||w|$（由 (c)）和 $\operatorname{Re}(z\overline{w}) \leq |z\overline{w}|$（由 (d)）。

> [!tip] 几何直观
> 在复平面上，复数 $z = a+bi$ 对应点 $(a,b)$，$|z|$ 是该点到原点的距离。三角不等式正是几何中"三角形两边之和大于第三边"的代数表达。

---

## Schwarz 不等式

### Theorem 1.35

设 $a_1,\dots,a_n$ 和 $b_1,\dots,b_n$ 为复数，则

$$\left|\sum_{j=1}^n a_j \overline{b_j}\right|^2 \leq \left(\sum_{j=1}^n |a_j|^2\right) \left(\sum_{j=1}^n |b_j|^2\right)$$

等号成立当且仅当 $(a_1,\dots,a_n)$ 与 $(b_1,\dots,b_n)$ 线性相关（即存在 $\lambda \in \mathbb{C}$ 使 $a_j = \lambda b_j$ 对所有 $j$ 成立）。

#### 证明概要

记 $A = \sum|a_j|^2$，$B = \sum|b_j|^2$，$C = \sum a_j \overline{b_j}$。

- 若 $B = 0$，则所有 $b_j = 0$，不等式平凡成立。
- 若 $B > 0$，考虑 $\sum|Ba_j - Cb_j|^2 \geq 0$，展开得：

$$
\sum|Ba_j - Cb_j|^2 = B^2 A - B|C|^2 = B(AB - |C|^2) \geq 0
$$

由于 $B > 0$，得 $AB - |C|^2 \geq 0$，即 $|C|^2 \leq AB$。$\square$

> [!warning] 为何 $\overline{b_j}$？
> 这里 $a_j \overline{b_j}$ 比 $a_j b_j$ 更自然，因为它保证了当 $a_j = \lambda b_j$ 时内积 $\sum a_j \overline{b_j} = \lambda \sum|b_j|^2$ 非负，且 Schwarz 不等式中左边为 $|\sum a_j \overline{b_j}|$——这与欧氏空间 $\mathbb{R}^k$ 中的点积 $\mathbf{a}\cdot\mathbf{b} = \sum a_j b_j$ 一致，推广到复向量需要取共轭。

#### Schwarz 不等式的核心地位

Schwarz 不等式是整个分析学和线性代数中**最重要**的不等式之一。以下是它的常见应用：

| 领域 | 应用 |
|:----|:-----|
| 欧氏空间 | $|\mathbf{a}\cdot\mathbf{b}| \leq \|\mathbf{a}\|\|\mathbf{b}\|$（Cauchy-Schwarz 不等式） |
| 内积空间 | $|\langle x,y\rangle| \leq \|x\|\|y\|$ |
| 三角不等式 | 由 Schwarz 不等式可证 $\|x+y\| \leq \|x\| + \|y\|$ |
| $L^2$ 空间 | $\left|\int f\overline{g}\right| \leq \left(\int|f|^2\right)^{1/2} \left(\int|g|^2\right)^{1/2}$ |
| 概率论 | $|\operatorname{Cov}(X,Y)| \leq \sqrt{\operatorname{Var}(X)\operatorname{Var}(Y)}$ |

---

## 结构总结

```
有序对 $(a,b) \in \mathbb{R}^2$
      |
      |--- 加法: $(a,b)+(c,d) = (a+c,b+d)$
      |--- 乘法: $(a,b)(c,d) = (ac-bd,ad+bc)$
      |--- 零元: $(0,0)$, 单位元: $(1,0)$
      |--- 嵌入 $\mathbb{R}$: $(a,0) \leftrightarrow a$
      |
      |--- $i = (0,1),\; i^2 = -1$
      |--- 表示: $(a,b) = a+bi$
      |
      |--- 共轭: $a+bi = a-bi$
      |--- 模: $|z| = \sqrt{a^2+b^2}$
      |
      |--- Schwarz: $\bigl|\sum a_j \overline{b_j}\bigr|^2 \leq (\sum|a_j|^2)(\sum|b_j|^2)$
```

### $\mathbb{C}$ 与 $\mathbb{R}$ 的关键差异

| 性质 | $\mathbb{R}$ | $\mathbb{C}$ |
|:-----|:------------|:------------|
| 域结构 | ✅ | ✅ |
| 有序域 | ✅ | ❌（任何序都会使 $i^2 < 0$） |
| 最小上界性质 | ✅ | ❌（序不存在，LUB 无定义） |
| 代数封闭性 | ❌（$x^2+1=0$ 无解） | ✅（代数学基本定理，Chapter 8） |
| 子域 | $\mathbb{Q} \subset \mathbb{R}$ | $\mathbb{R} \subset \mathbb{C}$ |

> $\mathbb{C}$ 虽无序结构，却因代数封闭而成为许多数学分支的天然工作域——复分析、调和分析、量子力学等。

---

## 相关笔记

- [[Real Field]] — $\mathbb{R}$ 的构造与完备性，$\mathbb{C}$ 的构建基础
- [[Field]] — 域的抽象定义，$\mathbb{C}$ 作为域的例子
- [[Inner Product and Norm]] — 从 $|z|$ 推广到一般内积空间
- [[n-dimensional Euclidean space]] — $\mathbb{R}^k$ 上的度量结构
- [[Density and Completeness]] — $\mathbb{Q}$ 与 $\mathbb{R}$ 的差异，为何需要数系扩张

---

## 参考来源

- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., McGraw-Hill 1976. (§1.6 The Complex Field, Definitions 1.24–1.35)
- Ahlfors, L. *Complex Analysis*, 3rd ed., McGraw-Hill 1979.
- Needham, T. *Visual Complex Analysis*, Oxford University Press 1997.
