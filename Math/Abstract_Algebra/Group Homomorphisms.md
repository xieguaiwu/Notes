---
title: Group Homomorphisms
tags:
  - Math
  - AbstractAlgebra
  - 概念性
  - 定理性
created: 2026-06-25
modified: 2026-06-25
---

# Group Homomorphisms

> [!abstract] 概述
> **群同态 (Group Homomorphism)** 是保持群结构的映射：两个群之间的函数，使得运算在映射前后兼容。同态是"结构保持映射"这一统一概念在群论中的版本——与线性代数中的线性变换、环论中的环同态、模论中的模同态共享相同的精神。核、像、同构三大核心概念由此展开。

---

## 定义与基本性质

**定义.** 设 $(G, \cdot)$ 和 $(H, *)$ 是群，映射 $\varphi: G \to H$ 称为**群同态 (group homomorphism)**，若

$$\varphi(a \cdot b) = \varphi(a) * \varphi(b), \quad \forall a, b \in G.$$

即：**先运算再映射 = 先映射再运算**。

**基本性质.** 从定义可直接导出：

| 性质 | 公式 | 说明 |
|:---|:-----|:-----|
| 单位元保持 | $\varphi(e_G) = e_H$ | 群的"零点"不被移动 |
| 逆元保持 | $\varphi(a^{-1}) = \varphi(a)^{-1}$ | 逆的像等于像的逆 |
| 幂保持 | $\varphi(a^n) = \varphi(a)^n$ | 对任意 $n \in \mathbb{Z}$ 成立 |
| 复合 | $\psi \circ \varphi$ 仍是同态 | 若 $\varphi: G \to H$, $\psi: H \to K$ 是同态 |

> [!tip] 直觉
> 同态是"用另一种语言说同一件事"——它把 $G$ 中的运算翻译到 $H$ 中，且翻译结果与在 $H$ 中直接做运算一致。

---

## 核 (Kernel)

**定义.** $\ker \varphi = \{ g \in G \mid \varphi(g) = e_H \}$。

核是那些被同态"抹去"的元素——它们映射到目标群的单位元。

**核的性质：**

- $\ker \varphi$ 是 $G$ 的**子群**。
- $\ker \varphi$ 是 $G$ 的**正规子群 (normal subgroup)**——这是核最重要的性质之一，因为正规子群正是构造商群的基础。（[[Normal Subgroups and Quotient Groups]]）
- $\varphi$ 是**单射 (injective)** $\iff \ker \varphi = \{ e_G \}$。
  - 证明：$\varphi(a) = \varphi(b) \implies \varphi(ab^{-1}) = e_H \implies ab^{-1} \in \ker \varphi$；若核平凡，则 $a = b$。

---

## 像 (Image)

**定义.** $\operatorname{im} \varphi = \{ \varphi(g) \mid g \in G \} \subseteq H$。

**像的性质：**

- $\operatorname{im} \varphi$ 是 $H$ 的**子群**。
- $\varphi$ 是**满射 (surjective)** $\iff \operatorname{im} \varphi = H$。

---

## 同构 (Isomorphism)

**定义.** 若 $\varphi: G \to H$ 是**双射 (bijective)** 同态，则称 $\varphi$ 为**同构 (isomorphism)**，记作 $G \cong H$。

> [!important] 同构的意义
> 同构的群具有**完全相同的群论性质**——阶数、交换性、子群结构、中心等等。在同构意义下，群只依赖其结构，不依赖元素的具体表述。

例如 $(\mathbb{R}, +) \cong (\mathbb{R}^+, \times)$ 由指数映射给出（见下方例子），这告诉我们在加法实数群与正实数乘法群之间没有本质区别——它们只是同一群结构的不同"外衣"。

---

## 重要例子

| 同态 | 映射规则 | 核 | 像 | 说明 |
|:---|:---------|:--|:---|:-----|
| $\det: GL_n(\mathbb{R}) \to \mathbb{R}^\times$ | $A \mapsto \det A$ | $SL_n(\mathbb{R})$（特殊线性群） | $\mathbb{R}^\times$（满射） | 行列式保持矩阵乘法 |
| $\operatorname{sgn}: S_n \to \{\pm 1\}$ | $\sigma \mapsto \operatorname{sgn}(\sigma)$ | $A_n$（交错群） | $\{\pm 1\}$（满射） | 置换的奇偶性 |
| $\exp: (\mathbb{R}, +) \to (\mathbb{R}^+, \times)$ | $x \mapsto e^x$ | $\{0\}$ | $\mathbb{R}^+$（满射） | **同构**，$e^{x+y}=e^x e^y$ |
| $\pi_n: \mathbb{Z} \to \mathbb{Z}_n$ | $k \mapsto k \bmod n$ | $n\mathbb{Z}$ | $\mathbb{Z}_n$（满射） | 模 $n$ 同态 |
| $i: H \hookrightarrow G$ | $h \mapsto h$ | $\{e\}$ | $H$ | 包含映射是**单同态 (monomorphism)** |

---

## 自同态与自同构

- $\operatorname{End}(G)$：$G$ 到自身的所有同态构成的集合，在复合运算下形成**幺半群 (monoid)**。
- $\operatorname{Aut}(G)$：$G$ 到自身的所有同构构成的集合，在复合运算下形成**群**，即 $G$ 的**自同构群 (automorphism group)**。

> [!example] 内自同构
> 对任意 $g \in G$，共轭映射 $\gamma_g: x \mapsto gxg^{-1}$ 是 $G$ 的自同构，称为**内自同构 (inner automorphism)**。所有内自同构构成 $\operatorname{Aut}(G)$ 的正规子群，记作 $\operatorname{Inn}(G)$。

---

## Cayley 定理

> [!theorem] Cayley 定理
> 每个群 $G$ 同构于某个置换群的子群。换言之，**置换群包含了所有可能的群结构**。

**证明思路（左乘作用）：**
定义映射 $L: G \to S_G$，其中 $L(g) = L_g: G \to G$ 为左乘映射 $L_g(x) = gx$。

1. 每个 $L_g$ 是 $G$ 上的**置换**（双射）。
2. $L_{gh} = L_g \circ L_h$，故 $L$ 是**同态**。
3. $\ker L = \{ g \in G \mid L_g = \operatorname{id}_G \} = \{ e \}$，故 $L$ 是**单射**。

因此 $G \cong \operatorname{im} L$，而 $\operatorname{im} L \leq S_G$。

> [!tip] 意义
> Cayley 定理将看似无限的群分类问题**归约**到置换群这一具体对象上。研究有限群只需研究 $S_n$ 的子群。

---

## 核心连接

- [[Group]] — 群的定义与公理
- [[Permutation Groups]] — Cayley 定理将群与置换群连接
- [[Normal Subgroups and Quotient Groups]] — 核是正规子群，商群的第一同构定理
- [[Isomorphism Theorems]] — 第一、第二、第三同构定理
- [[Linear Transformations]] — 同态在线性代数中的对应概念（见下方类比）

---

## 类比：群同态 ↔ 线性变换

| 群论概念 | 线性代数对应 | 共同结构 |
|:---------|:-------------|:---------|
| 群同态 $\varphi: G \to H$ | 线性变换 $T: V \to W$ | 保持代数结构的映射 |
| $\ker \varphi$ | $\ker T$ | 映射到零的元素 |
| $\operatorname{im} \varphi$ | $\operatorname{im} T$ | 实际到达的象 |
| 单同态 ($\ker = \{e\}$) | 单射线性变换 ($\ker = \{0\}$) | 核平凡 |
| 满同态 ($\operatorname{im} = H$) | 满射线性变换 ($\operatorname{im} = W$) | 像满 |
| 同构 $G \cong H$ | 可逆线性变换 | 双射保持结构 |
| $G/\ker \varphi \cong \operatorname{im} \varphi$ | $V/\ker T \cong \operatorname{im} T$ | 第一同构定理 |

> [!quote] 核心理念
> 无论是群还是向量空间，"结构保持映射"都遵循同一模式：核——度量映射丢失的信息；像——度量映射保留的信息；同构——结构完全相同。**群论是穿上了非交换外套的线性代数，而同态是其通用的翻译工具。**

---

## 参考来源

- Lang, S. *Algebra*, 3rd ed., Springer 2002.
- Dummit, D. & Foote, R. *Abstract Algebra*, 3rd ed., Wiley 2004.
- Herstein, I. N. *Topics in Algebra*, 2nd ed., Wiley 1975.
