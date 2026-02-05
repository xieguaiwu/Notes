---
tags:
  - Linguistics
  - Chomsky
  - Logic
  - 定义性
title: Different Types of Language & Constraint
created: 2025-12-08T13:29:00
modified: 2026-02-04
---
# Chomsky - Different Types of Language & Constraint

## 乔姆斯基层级（Chomsky Hierarchy）- 语言类型与语法约束

乔姆斯基层级定义了四种类型的语法，每种类型对应不同的计算能力和语言类。

### 1. Type 0 - 无限制语法（Unrestricted Grammar）
- **定义**：没有特殊限制的语法，任何形如 $\alpha\to\beta$ 的产生式都是允许的（除了 α 不能是空串）
- **对应自动机**：图灵机（Turing Machine）
- **生成语言**：递归可枚举语言（Recursively Enumerable Languages）
- **特点**：能生成所有可计算的语言类

### 2. Type 1 - 上下文敏感语法（Context-Sensitive Grammar）
- **定义**：所有产生式形如 $\alpha A\beta\to\alpha\gamma\beta$，其中 $A$ 是非终结符，$\alpha,\beta,\gamma$ 是string且 $\gamma$ 非空
- **长度约束**：在一般形式下，每个产生式 α → β 满足 |α| ≤ |β|（除非 α → ε 是开始符号 S 且 S 不出现在任何产生式右侧）
- **对应自动机**：线性有界自动机（Linear-Bounded Automaton，一种受限的图灵机）
- **生成语言**：上下文敏感语言（Context-Sensitive Languages）
- **应用**：可以处理自然语言中的长距离依赖现象，如某些语言的达成分关系

### 3. Type 2 - 上下文无关语法（Context-Free Grammar）（见[[Chomsky - Automata]]）
- **定义**：所有产生式形如 $A\to\gamma$，其中 $A$ 是单个非终结符，$\gamma$ 是终结符和非终结符的任意串
- **对应自动机**：非确定性下推自动机（Non-deterministic Pushdown Automaton）
- **生成语言**：上下文无关语言（Context-Free Languages）
- **应用**：大多数编程语言的语法基础，自然语言句法结构的重要模型

### 4. Type 3 - 正则语法（Regular Grammar）
- **定义**：所有产生式必须是右线性（$A\to a$ 或 $A\to aB$）或左线性（$A \to a$ 或 $A \to Ba$），其中 $A,B$ 是非终结符，$a$ 是终结符
- **对应自动机**：有限状态自动机（Finite-State Automaton）
- **生成语言**：正则语言（Regular Languages）
- **应用**：词法分析器、正则表达式、模式匹配的基础

## 语言类的包含关系

四种语言类之间存在严格的包含关系：
$$\text{Type 3} \subset \text{Type 2} \subset \text{Type 1} \subset \text{Type 0}$$

即：
- 正则语言 ⊂ 上下文无关语言 ⊂ 上下文敏感语言 ⊂ 递归可枚举语言

## 各类型语法的特征对比

| 语法类型   | 产生式形式                     | 对应自动机   | 语言类     | 典型应用          |
| ------ | ------------------------- | ------- | ------- | ------------- |
| Type 0 | $α\to\beta$               | 图灵机     | 递归可枚举语言 | 可计算函数/所有可判定语言 |
| Type 1 | $αA\beta\to α\gamma\beta$ | 线性有界自动机 | 上下文敏感语言 | 自然语言的某些结构     |
| Type 2 | $A\to\gamma$              | 下推自动机   | 上下文无关语言 | 编程语言语法、句法分析   |
| Type 3 | $A\to a$ 或 $A\to aB$      | 有限状态自动机 | 正则语言    | 词法分析、模式匹配     |

## 补充说明

- **确定性与非确定性**：对于Type 2和Type 3，确定性自动机的能力小于非确定性自动机
- **自然语言处理**：自然语言通常被认为超出了上下文无关语言的范围，可能需要更强大的语法类来完全描述
- **计算复杂性**：从Type 3到Type 0，语言的判定问题复杂性递增，Type 1及以上的语言存在不可判定问题

## 泵引理（Pumping Lemma）- 证明语言非正则性的重要工具

泵引理（也称为泵引理或抽引理）是形式语言理论中的一个重要工具，特别用于证明某些语言不是正则语言（即不是有限状态自动机可识别的语言）。

### 正则语言的泵引理

**定理陈述：**
如果 $\mathbf{L}$ 是一个正则语言，那么存在一个常数 $p$ (称为"泵长度")，使得对于 $\mathbf{L}$ 中任何长度至少为 $p$ 的字符串 $w$，都可以将 $w$ 分解为三个部分 $w = xyz$，满足以下条件：

1. 对于所有 $i\geq 0$，字符串 $xy^i z$ 都在 $\mathbf{L}$ 中
2. $|y| > 0$（$y$ 部分非空）
3. $|xy| \leq p$

### 直观理解

这个引理基于有限状态自动机的性质：如果一个字符串足够长（长度 $\geq p$，其中 $p$ 是自动机状态数），那么在处理该字符串时，自动机至少会重复进入某个状态。**重复的状态之间的部分（对应 $y$）可以"泵"任意次（重复任意多次），而结果字符串仍然会被接受**。

### 使用泵引理证明语言不是正则的

要证明一个语言 $\mathbf{L}$ 不是正则的，我们使用反证法：

1. 假设 $\mathbf{L}$ 是正则语言
2. 根据泵引理，存在泵长度 $p$
3. 选择一个字符串 $s\in\mathbf{L}$，使得 $|s|\geq p$
4. 证明对于 $s$ 的任何可能的分解 $s = xyz$（满足 $|xy|\leq p$ 和 $|y| > 0$），都存在某个 $i\geq 0$ 使得 $xy^i z \notin\mathbf{L}$
5. 这与泵引理相矛盾，因此 $\mathbf{L}$ 不是正则的

### 经典例子：证明 $\mathbf{L} = \{a^n b^n | n \geq 0 \}$ 不是正则语言

**证明：**

1. 假设 $\mathbf{L}$ 是正则语言
2. 根据泵引理，存在泵长度 $p$
3. 选择字符串 $s = a^p b^p$，显然 $s\in\mathbf{L}$ 且 $|s| = 2p\geq p$
4. 根据泵引理，$s$ 可以分解为 $s = xyz$，满足：
   - $|xy|\leq p$
   - $|y| > 0$
   - 对所有 $i\geq 0$，$xy^i z\in\mathbf{L}$

1. 由于 $|xy|\leq p$ 且 $s$ 的前 $p$ 个字符都是 $a$，所以 $x$ 和 $y$ 完全由 $a$ 组成。
   因此：$x = a^j, y = a^k$, $z = a^(p-j-k) b^p$，其中 $k > 0$
2. 考虑 $i = 2$ 的情况：
   $xy^2 z = a^j a^k a^k a^(p-j-k) b^p = a^(p+k) b^p$
3. 由于 $k > 0$，所以 $p+k\neq p$，因此 $xy^2 z = a^(p+k) b^p\notin\mathbf{L}$
4. 这与泵引理矛盾，所以 $\mathbf{L}$ 不是正则语言

### 泵引理的局限性

需要注意的是，泵引理只能用来证明语言不是正则的，不能用来证明语言是正则的。也就是说，如果一个语言满足泵引理的条件，它不一定是正则的；但如果一个语言不满足泵引理的条件，那它肯定不是正则的。

泵引理是证明语言层次分类的重要工具，在计算理论和形式语言理论中有着基础性的作用。
