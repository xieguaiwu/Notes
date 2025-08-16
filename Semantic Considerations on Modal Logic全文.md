---
tags:
  - Kripke
  - ModalLogic
  - 论文
title: Semantic Considerations on Modal Logic 全文
created: 2025-08-15T1:24
modified: 2025-08-15T1:24
---
[[关于哲学命题的论域在模态逻辑语义扩展理论下的形式化的可能性]]
[[Kripke]]
[[Modal Logic]]

# Semantic Considerations on Modal Logic全文


---

### **标题页**  
**《芬兰哲学学报》第 16 卷 (1963), 83-94 页**  
**模态逻辑的语义考量**  
索尔·A·克里普克 (Saul A. Kripke)  

---

### **1. 引言**  
本文阐述模态逻辑语义理论$^1$的核心特征。针对 **S5 的量化扩展**，该理论已在[1]中提出，并于[2]中总结。本文将聚焦理论的**量化引入**（introduction of quantifiers），并主要限制于单一实现方法。论述重点为**纯语义学**（purely semantical），故省略对**语义表**（semantic tableaux）的讨论（完整理论见[1][11]），证明过程亦从简。

**四大模态系统**：公式 $A, B, C,\ldots$ 由原子公式 $P, Q, R,\ldots$ 经联结词 $\land$, $\sim$, $\square$ 构成：  
- **系统 M** 公理与规则：  
  - **A1.** $\square A \supset A$  
  - **A2.** $\square (A \supset B) \supset \square A \supset \square B$  
  - **R1.** $A, A \supset B / B$ （分离规则）  
  - **R2.** $A / \square A$ （必然化规则）  
- **S4** = M + $\square A \supset \square \square A$  
- **布劳威尔系统**（Brouwersche system） = M + $A \supset \square \bigcirc A$  
- **S5** = M + $\bigcirc A \supset \square \bigcirc A$  

> $^1$ 本理论与多位学者有交集（列表见[11]及 Hintikka[6]），最接近者为**欣蒂卡**（Hintikka）与**康格尔**（Kanger）。然本文的**量化处理**方法虽受普莱尔（Prior）与欣蒂卡启发，实属首创。

---

### **2. 模型结构与语义基础**  
**正规系统**（Normal systems）：闭包于 R1、R2 且包含 M 所有定理的模态系统。本文仅讨论正规系统（非正规系统如 Lewis 的 S2、S3 从略）。

**模型结构**（Model structure, m.s.）：有序三元组 $(G, K, R)$，其中：  
- $K$：**可能世界集合**（set of possible worlds）  
- $R$：$K$ 上的**自反关系**（reflexive relation）  
- $G \in K$：**现实世界**（real world）  

**直观解释**：  
- $H_1 R H_2$ 表示世界 $H_2$ **相对于** $H_1$ 可能（即 $H_2$ 中所有真命题在 $H_1$ 中可能）。  
- **自反性**（reflexivity）的合理性：任一世界 $H$ 相对于自身必然可能。  

**附加要求与对应系统**：  
- **S4-m.s.**：$R$ **传递**（transitive）  
- **布劳威尔-m.s.**：$R$ **对称**（symmetric）  
- **S5-m.s.**：$R$ **等价关系**（equivalence relation）  
- **M-m.s.**：无限制  

**模型**（Model）定义：  
- 函数 $\varphi(P, H)$ 为原子公式 $P$ 在世界 $H \in K$ 赋真值 $T/F$。  
- **复合公式真值归纳定义**：  
  - $\varphi(A \land B, H) = T$ 当且仅当 $\varphi(A, H) = \varphi(B, H) = T$  
  - $\varphi(\sim A, H) = T$ 当且仅当 $\varphi(A, H) = F$  
  - **必然性**：$\varphi(\square A, H) = T$ 当且仅当对所有满足 $H R H'$ 的 $H'$，$\varphi(A, H') = T$  

**完备性定理**（Completeness theorem）：  
$\vdash A$ 在 M/S4/S5/布劳威尔系统当且仅当对任意对应模型结构 $(G, K, R)$ 上的模型 $\varphi$，有 $\varphi(A, G) = T$。  
> （证明见[11]；此定理将语法可证性等价于语义有效性。）

---

### **3. 量化模态逻辑的语义扩展**  
**量化模型结构**（Quantificational model structure, q.m.s.）：  
在模型结构 $(\mathbf{G}, \mathbf{K}, \mathbf{R})$ 上增加函数 $\psi$，为每个 $\mathbf{H} \in \mathbf{K}$ 指定**个体域** $\psi(\mathbf{H})$（即存在于 $\mathbf{H}$ 中的个体集合）。  
- **关键特性**：不同世界的个体域可不同（如现实个体缺失或虚构个体如“飞马”出现）。

**自由变量的真值分配问题**：  
- **弗雷格-斯特劳森观点**（Frege-Strawson view）：若变量赋值为不在当前世界个体域中的个体（如“福尔摩斯是秃头”），则公式无真值。  
- **罗素观点**（Russell view）：此类公式有真值（但需处理空名问题）。  
> 本文选择**罗素路径**：约定含自由变量的公式在每个世界对任意赋值均有真值（避免修改模态命题逻辑或量化理论）。

**量化模型**（Quantificational model）形式定义：  
- 令 $U = \bigcup_{\mathbf{H} \in \mathbf{K}} \psi(\mathbf{H})$ 为**全域个体集**。  
- 函数 $\varphi(P^n, \mathbf{H})$ 为 $n$ 元谓词字母指定：  
  - $n=0$：真值 $T/F$  
  - $n \geq 1$：$\mathbf{U}^n$ 的子集（即谓词在 $\mathbf{H}$ 中的**外延**）  
- **原子公式真值**：对赋值 $a_1,\ldots,a_n \in U$，  
  $\varphi(P^n(x_1,\ldots,x_n), \mathbf{H}) = T$ 当且仅当 $(a_1,\ldots,a_n) \in \varphi(P^n, \mathbf{H})$  
- **量词语义**：$\varphi((x)A(x), \mathbf{H}) = T$ 当且仅当对 **所有 $a \in \psi(\mathbf{H})$**，$\varphi(A(x), \mathbf{H}) = T$  
  > （量化仅针对 $\mathbf{H}$ 中存在的个体）

---

### **4. 巴坎公式及其反例**  
**巴坎公式**（Barcan formula）及其逆命题：  
$$
\text{(BF): } (x) \square A(x) \supset \square (x)A(x) \quad ; \quad \text{(CBF): } \square (x)A(x) \supset (x) \square A(x)
$$

#### **反例构造**（基于 S5 模型结构 $\mathbf{K} = \{\mathbf{G}, \mathbf{H}\}$, $\mathbf{R} = \mathbf{K}^2$）  
1. **BF 反例**：  
   - $\psi(\mathbf{G}) = \{a\}$, $\psi(\mathbf{H}) = \{a,b\}$  
   - $\varphi(P, \mathbf{G}) = \{a\}$, $\varphi(P, \mathbf{H}) = \{a\}$  
   - 结果：$\mathbf{G}$ 中 $(x)\square P(x)$ 真，但 $\square (x)P(x)$ 假（因 $\mathbf{H}$ 中 $P(b)$ 假）。  
   - **修复条件**：要求 $\mathbf{H} R \mathbf{H}' \Rightarrow \psi(\mathbf{H}') \subseteq \psi(\mathbf{H})$  

2. **CBF 反例**：  
   - $\psi(\mathbf{G}) = \{a,b\}$, $\psi(\mathbf{H}) = \{a\}$  
   - $\varphi(P, \mathbf{G}) = \{a,b\}$, $\varphi(P, \mathbf{H}) = \{a\}$  
   - 结果：$\mathbf{G}$ 中 $\square (x)P(x)$ 真，但 $(x)\square P(x)$ 假（因 $\square P(b)$ 假）。  
   - **弗雷格-斯特劳森路径下**：若 $P(b)$ 在 $\mathbf{H}$ 中无真值，则 CBF 反例不成立（依普莱尔“NMN”必然性定义）。  
   - **修复条件**：要求 $\mathbf{H} R \mathbf{H}' \Rightarrow \psi(\mathbf{H}) \subseteq \psi(\mathbf{H}')$  

#### **形式系统修正**  
- **公理系统**（量化 M）：以下图式的**闭包**（closure）为公理：  
  (0) 真值函数重言式  
  (1) $\square A \supset A$  
  (2) $\square (A \supset B) \supset \square A \supset \square B$  
  (3) $A \supset (x)A$ （$x$ 不在 $A$ 中自由出现）  
  (4) $(x)(A \supset B) \supset (x)A \supset (x)B$  
  (5) $(y)((x)A(x) \supset A(y))$  
- **推理规则**：实质蕴涵分离（Detachment）  
- **优势**：  
  1. 保持模态命题逻辑与量化理论原貌  
  2. 无限制替换规则  
  3. BF 与 CBF 均不可证  

---

### **5. 可证性解释**（Provability Interpretations）  
#### **S5 解释（基于皮亚诺算术 PA）**  
- **模型结构**：  
  - $K$：PA 的所有可数模型  
  - $G$：PA 的标准模型（自然数模型）  
  - $R = K^2$ （S5-m.s.）  
- **原子公式**：PA 的闭公式  
- **真值定义**：$\varphi(P, H) = T$ 当且仅当 $P$ 在模型 $H$ 中为真  
- **必然性**：$\varphi(\square P, G) = T$ 当且仅当 $P$ 在 PA 中**可证**  
  > 例：若 $P$ 为哥德尔不可判定公式，则 $\square P \lor \square \sim P$ 在 $G$ 中假（反例排中律）。

#### **S4 解释（基于 PA 扩展）**  
- **模型结构**：  
  - $K$：有序对 $(E, \alpha)$，其中 $E$ 为 PA 的一致扩展，$\alpha$ 为 $E$ 的模型  
  - $G = (\text{PA}, \alpha_0)$（$\alpha_0$ 为标准模型）  
  - $(E, \alpha) R (E', \alpha')$ 当且仅当 $E'$ 扩展 $E$  
- **必然性**：$\varphi(\square P, (E, \alpha)) = T$ 当且仅当 $P$ 在 $E$ 中可证  

#### **直觉主义逻辑解释**  
- **验证条件**（对 PA 的一致扩展 $E$）：  
  - $A \land B$ 在 $E$ 中验证当且仅当 $A$ 与 $B$ 均在 $E$ 中验证  
  - $A \lor B$ 在 $E$ 中验证当且仅当 $A$ 或 $B$ 在 $E$ 中验证  
  - $\neg A$ 在 $E$ 中验证当且仅当 $E$ 无一致扩展验证 $A$  
  - $A \supset B$ 在 $E$ 中验证当且仅当所有验证 $A$ 的 $E$ 一致扩展 $E'$ 也验证 $B$  
> 直觉主义逻辑定律在 PA 中可验证，但 $A \vee \neg A$ 不可（若 $A$ 哥德尔不可判定）。

---

### **参考文献**（References）  
[1] KRIPKE, S. A. 《模态逻辑的完备性定理》. *符号逻辑杂志* 24 (1959), 1–15.  
[2] KRIPKE, S. A. 《模态逻辑的语义分析（摘要）》. *符号逻辑杂志* 24 (1959), 323–324.  
[3] FREGE, G. 《论涵义与指称》. *哲学与哲学批评杂志* 100 (1892), 25–50.  
[4] STRAWSON, P. F. 《论指称》. *心灵* 59 (1950), 320–344.  
[5] RUSSELL, B. 《论指示》. *心灵* 14 (1905), 479–493.  
[6] HINTIKKA, J. 《模态与量化》. *Theoria* 27 (1961), 119–128.  
[7] PRIOR, A. N. 《时间与模态》. 牛津大学出版社, 1957.  
[11] KRIPKE, S. A. 《模态逻辑的语义分析 I》. *数理逻辑与数学基础杂志* 9 (1963), 67–96.  
[12] KLEENE, S. C. 《元数学导论》. 范诺斯特兰德出版社, 1952.  
[15] QUINE, W. V. O. 《数理逻辑》. 哈佛大学出版社, 1951.  

---

