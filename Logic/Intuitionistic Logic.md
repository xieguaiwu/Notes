---
tags:
  - IntuitionisticLogic
  - ModalLogic
  - Logic
title: Intuitionistic Logic
created: 2026-05-20
modified: 2026-05-20
---

[[Modal Logic]]
[[克里普克模态语义递归定义]]
[[System T]]
[[Philosophy of Logic]]

# 直觉主义逻辑

> [!quote] "The law of excluded middle is a principle of the finite, not of the infinite." -- L.E.J. Brouwer

## 核心特征

直觉主义逻辑拒绝**排中律 (LEM)**，即 $\lnot(P \lor \lnot P)$ 在该系统中不成立。这源于数学构造主义立场：一个命题为真当且仅当存在它的构造性证明。

| 性质 | 经典逻辑 | 直觉主义逻辑 |
|------|----------|--------------|
| 排中律 | $P \lor \lnot P$ 永真 | 不成立 |
| 双重否定消去 | $\lnot\lnot P \to P$ 有效 | 不成立 |
| 归谬法 | 有效 | 仅用于否定命题 |
| 存在性 | $\exists x P(x)$ 无需构造 | 需要显式构造 |

## BHK 解读

Brouwer-Heyting-Kolmogorov 为直觉主义逻辑提供了构造性语义：
- $P \land Q$：一个证明 = $P$ 的证明加上 $Q$ 的证明
- $P \lor Q$：一个证明 = $P$ 的证明或 $Q$ 的证明（附带选择信息）
- $P \to Q$：一个证明 = 将 $P$ 的证明转化为 $Q$ 的证明的**构造**
- $\lnot P$：一个证明 = $P \to \bot$，即从 $P$ 推出矛盾的构造

> [!note]
> 蕴涵 $A \to B$ 在直觉主义中不是真值函数，而是一种**构造性转换**。这与经典逻辑的实质蕴涵 ($\lnot A \lor B$) 有本质区别。

## 双重否定

在直觉主义逻辑中，$\lnot\lnot P$ 弱于 $P$。以下关系成立：
- $P \to \lnot\lnot P$ (成立)
- $\lnot\lnot\lnot P \to \lnot P$ (成立)
- $\lnot\lnot P \to P$ (不成立)

经典逻辑可以通过**哥德尔-根岑翻译**嵌入直觉主义逻辑：将 $\Box$ 解释为 S4 中的必然性算子。直觉主义逻辑等价于 S4 中 $\Box$ 翻译下的模态逻辑片段。

## 克里普克语义（知识阶段）

直觉主义逻辑也有克里普克语义，但可能世界被解释为"知识阶段"：

$$w \models A \to B \iff \forall v \ge w, (v \models A \Rightarrow v \models B)$$

可达关系 $R$ 是**偏序**（自反、传递、反对称）。知识只能增长，不会丢失：若 $w \models P$ 且 $wRv$，则 $v \models P$（单调性）。

> [!warning]
> 不要与模态逻辑的克里普克语义混淆。直觉主义的可达关系代表"知识的发展"，而非"可能性"。
