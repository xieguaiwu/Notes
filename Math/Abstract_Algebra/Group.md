---
title: Group
tags:
  - Math
  - AbstractAlgebra
  - 定义性
  - 基本原理
created: 2026-06-08
modified:
---

# Group

> [!abstract] 概述
> **群 (Group)** 是抽象代数中最基础的结构：一个集合配上一种二元运算，满足封闭性、结合律、单位元存在和逆元存在。群刻画了"对称性"的数学本质，也是域和环等更复杂结构的基本构件。

## 定义

设 $G$ 是一个非空集合，$\cdot$ 是 $G$ 上的二元运算。$(G, \cdot)$ 称为一个**群**，若满足以下四条**群公理**：

1. **封闭性 (Closure)**：$\forall a, b \in G,\; a \cdot b \in G$
2. **结合律 (Associativity)**：$\forall a, b, c \in G,\; (a \cdot b) \cdot c = a \cdot (b \cdot c)$
3. **单位元 (Identity)**：$\exists e \in G,\; \forall a \in G,\; e \cdot a = a \cdot e = a$
4. **逆元 (Inverse)**：$\forall a \in G,\; \exists a^{-1} \in G,\; a \cdot a^{-1} = a^{-1} \cdot a = e$

### 阿贝尔群 (Abelian Group)

若群 $(G, \cdot)$ 还满足**交换律**：

$$\forall a, b \in G,\; a \cdot b = b \cdot a$$

则称 $G$ 为**阿贝尔群**（或交换群）。

> [!note] 记号约定
> 群的运算未必是乘法。运算记号为 $+$ 时，群称为**加法群**，此时单位元记作 $0$，逆元记作 $-a$。运算记号为 $\cdot$ 时，群称为**乘法群**，单位元记作 $1$。

## 基本性质

以下性质可从群公理直接导出：

- **单位元唯一**：若 $e$ 和 $e'$ 都是单位元，则 $e = e'$
- **逆元唯一**：若 $a^{-1}$ 和 $b$ 都是 $a$ 的逆元，则 $a^{-1} = b$
- **消去律**：$a \cdot b = a \cdot c \implies b = c$（左消去），$b \cdot a = c \cdot a \implies b = c$（右消去）
- $(a^{-1})^{-1} = a$
- $(a \cdot b)^{-1} = b^{-1} \cdot a^{-1}$

## 示例

| 集合 | 运算 | 单位元 | 是否群 | 说明 |
|:----|:----|:------|:-------|:-----|
| $\mathbb{Z}$ | $+$ | $0$ | ✅ 阿贝尔群 | 整数加法群 |
| $\mathbb{Q}$ | $+$ | $0$ | ✅ 阿贝尔群 | 有理数加法群 |
| $\mathbb{Q} \setminus \{0\}$ | $\times$ | $1$ | ✅ 阿贝尔群 | 非零有理数乘法群 |
| $\mathbb{Z} \setminus \{0\}$ | $\times$ | $1$ | ❌ | 逆元不在 $\mathbb{Z}$ 中（如 $2^{-1}=1/2$） |
| $n \times n$ 可逆矩阵 | 矩阵乘法 | $I_n$ | ✅ | 一般线性群 $GL(n, \mathbb{R})$，**非阿贝尔**（$n \geq 2$） |
| $n$ 个元素的置换 | 复合 | 恒等置换 | ✅ | 对称群 $S_n$，**非阿贝尔**（$n \geq 3$） |

> [!tip] 非阿贝尔群的意义
> 并非所有群都交换。矩阵乘法不交换（$AB \neq BA$ 一般成立），置换也不交换。群论之所以丰富，正是因为**非交换性**的存在——它刻画了不对称的对称。

## 子群

$H \subset G$ 称为 $G$ 的**子群**，若 $H$ 在 $G$ 的运算下自身构成群。

**子群检验**：$H$ 非空且 $\forall a, b \in H,\; a \cdot b^{-1} \in H$。

## 与域的关系

群是域的基础。在域 $(F, +, \times)$ 中：

- $(F, +)$ 是一个**阿贝尔群**（加法群）
- $(F \setminus \{0\}, \times)$ 是一个**阿贝尔群**（乘法群）

也就是说，域的本质是"**两个阿贝尔群用分配律粘合**"。参见 [[Field]]。

> [!warning] 域与群的关键区别
> 域有两种运算，群只有一种。群的公理只涉及一个二元运算；域的加法群和乘法群通过分配律相互约束。

## 相关链接

- [[Field]] — 域的定义及其与群的关系
- [[Boundedness#3.3 有界序列 (Def 3.1 & Theorem 3.14)]] — 实数作为群的例子

## 参考来源

- Lang, S. *Algebra*, 3rd ed., Springer 2002.
- Dummit, D. & Foote, R. *Abstract Algebra*, 3rd ed., Wiley 2004.
- Rudin, W. *Principles of Mathematical Analysis*, 3rd ed., McGraw-Hill 1976. (Def 1.12 Field Axioms)
