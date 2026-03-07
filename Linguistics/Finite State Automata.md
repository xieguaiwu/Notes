---
tags:
  - Linguistics
  - Math
  - 计算语言学
  - 形式语言
  - 定义性
title: Finite State Automata
created: 2026-03-07T11:00:00
modified:
---
# Finite State Automata
[[Chomsky - Automata]]
[[Computational Linguistics for IOLC]]

## 1. 引言

有限状态机（Finite State Automaton, FSA 或 FSM）是描述有限状态及其转移的数学模型，是形式语言理论中最基础的自动机类型，对应乔姆斯基层级中的**3型语言（正则语言）**。

| 性质 | 描述 |
|------|------|
| **表达能力** | 识别正则语言 |
| **记忆能力** | 无（无栈、无无限存储） |
| **应用场景** | 构词分析、音系规则、词法分析 |

---

## 2. 集合论预备知识

### 2.1 基本概念

| 概念 | 定义 | 示例 |
|------|------|------|
| **集合** | 无序、不重复元素的汇集 | $Q = \{q_0, q_1, q_2\}$ |
| **笛卡尔积** | 两集合元素的所有有序对 | $A \times B = \{(a,b) \mid a \in A, b \in B\}$ |
| **幂集** | 所有子集构成的集合 | $2^A = \{S \mid S \subseteq A\}$ |
| **函数** | 从一个集合到另一个集合的映射 | $f: A \to B$ |

### 2.2 字母表与字符串

**字母表**：有限非空符号集合
$$\Sigma = \{a, b, c, ...\}$$

**字符串**：字母表上符号的有穷序列
$$w = a_1 a_2 ... a_n, \quad a_i \in \Sigma$$

**克林星号（Kleene Star）**：
$$\Sigma^* = \{w \mid w \text{ 是 } \Sigma \text{ 上的有穷字符串}\}$$

**克林加号**：
$$\Sigma^+ = \Sigma^* - \{\varepsilon\}$$

**示例**：若 $\Sigma = \{a, b\}$，则：
$$\Sigma^* = \{\varepsilon, a, b, aa, ab, ba, bb, aaa, ...\}$$

---

## 3. 确定性有限状态机（DFA）

### 3.1 形式化定义

**确定性有限自动机（DFA）** 是一个五元组：
$$M = (Q, \Sigma, \delta, q_0, F)$$

| 元素 | 含义 | 数学约束 |
|------|------|----------|
| $Q$ | 有限状态集合 | $Q \neq \emptyset$，$|Q| < \infty$ |
| $\Sigma$ | 输入字母表 | $\Sigma \neq \emptyset$，$|\Sigma| < \infty$ |
| $\delta$ | 转移函数 | $\delta: Q \times \Sigma \to Q$ |
| $q_0$ | 初始状态 | $q_0 \in Q$ |
| $F$ | 接受状态集合 | $F \subseteq Q$ |

**确定性**：每个状态对每个输入符号**恰好有一个**转移目标。

### 3.2 转移函数的扩展

将 $\delta$ 扩展到字符串上：
$$\hat{\delta}: Q \times \Sigma^* \to Q$$

**递归定义**：
$$\hat{\delta}(q, w) = \begin{cases}
q & \text{if } w = \varepsilon \\
\delta(\hat{\delta}(q, u), a) & \text{if } w = ua, u \in \Sigma^*, a \in \Sigma
\end{cases}$$

### 3.3 语言接受

**被DFA接受的语言**：
$$L(M) = \{w \in \Sigma^* \mid \hat{\delta}(q_0, w) \in F\}$$

### 3.4 完整示例

**DFA**：接受以 $ab$ 结尾的所有字符串

$$M = (Q, \Sigma, \delta, q_0, F)$$

- $Q = \{q_0, q_1, q_2, q_3\}$
- $\Sigma = \{a, b\}$
- $q_0$ 为初始状态
- $F = \{q_2\}$

**转移函数表**：

| $\delta$ | $a$ | $b$ |
|----------|-----|-----|
| $q_0$ | $q_1$ | $q_3$ |
| $q_1$ | $q_1$ | $q_2$ |
| $q_2$ | $q_1$ | $q_3$ |
| $q_3$ | $q_3$ | $q_3$ |

**状态转移图**：

```
        a         b        a         b
     ┌─────┐  ┌─────┐  ┌─────┐  ┌─────┐
     │     ↓  │     ↓  │     ↓  │     ↓
    (q0)───→(q1)───→(q2)[接受]
     │b      │a      │b      │a,b
     │       │       │       │
     ↓       ↓       ↓       ↓
    (q3)←───────────────────
```

**验证**：$w = aab$

$$\hat{\delta}(q_0, aab) = \delta(\hat{\delta}(q_0, aa), b) = \delta(\delta(\hat{\delta}(q_0, a), a), b) = \delta(\delta(q_1, a), b) = \delta(q_1, b) = q_2 \in F$$

$\therefore aab \in L(M)$ ✓

---

## 4. 非确定性有限状态机（NFA）

### 4.1 形式化定义

**非确定性有限自动机（NFA）** 是一个五元组：
$$M = (Q, \Sigma, \delta, q_0, F)$$

与DFA的区别在于转移函数：
$$\delta: Q \times (\Sigma \cup \{\varepsilon\}) \to 2^Q$$

**非确定性**：一个状态对同一输入可以转移到**多个状态**。

### 4.2 NFA示例

**NFA**：接受包含子串 $ab$ 的所有字符串

**转移函数表**：

| $\delta$ | $a$ | $b$ | $\varepsilon$ |
|----------|-----|-----|---------------|
| $q_0$ | $\{q_0, q_1\}$ | $\{q_0\}$ | $\emptyset$ |
| $q_1$ | $\emptyset$ | $\{q_2\}$ | $\emptyset$ |
| $q_2$ | $\emptyset$ | $\emptyset$ | $\emptyset$ |

**状态图**：

```
        a,b
     ┌──────┐
     │      ↓
    (q0)──a──→(q1)──b──→(q2)[接受]
```

### 4.3 NFA的扩展转移函数

$$\hat{\delta}: Q \times \Sigma^* \to 2^Q$$

**递归定义**：
$$\hat{\delta}(q, w) = \begin{cases}
\{q\} & \text{if } w = \varepsilon \\
\bigcup_{p \in \hat{\delta}(q, u)} \delta(p, a) & \text{if } w = ua
\end{cases}$$

### 4.4 DFA与NFA对比

| 特性 | DFA | NFA |
|------|-----|-----|
| **转移目标** | 唯一确定 | 可能有多个 |
| **$\varepsilon$-转移** | 不允许 | 允许 |
| **表达能力** | 相同 | 相同 |
| **实现效率** | $O(n)$ | 需转换为DFA |
| **建模便捷性** | 较复杂 | 较简单 |

---

## 5. DFA与NFA的等价性

### 5.1 核心定理

**定理**：对于任意NFA $M$，存在DFA $M'$ 使得 $L(M) = L(M')$。

### 5.2 子集构造法

设 NFA $M = (Q, \Sigma, \delta, q_0, F)$

构造 DFA $M' = (Q', \Sigma, \delta', q_0', F')$：

| DFA元素 | 构造方法 |
|---------|----------|
| $Q'$ | $2^Q$（$Q$ 的幂集） |
| $q_0'$ | $\{q_0\}$ |
| $F'$ | $\{S \subseteq Q \mid S \cap F \neq \emptyset\}$ |
| $\delta'(S, a)$ | $\bigcup_{q \in S} \delta(q, a)$ |

### 5.3 示例转换

**原NFA**：

| $\delta$ | $a$ | $b$ |
|----------|-----|-----|
| $q_0$ | $\{q_0, q_1\}$ | $\{q_0\}$ |
| $q_1$ | $\emptyset$ | $\{q_2\}$ |
| $q_2$ | $\emptyset$ | $\emptyset$ |

**转换为DFA**：

| $\delta'$ | $a$ | $b$ |
|-----------|-----|-----|
| $\{q_0\}$ | $\{q_0, q_1\}$ | $\{q_0\}$ |
| $\{q_0, q_1\}$ | $\{q_0, q_1\}$ | $\{q_0, q_2\}$ |
| $\{q_0, q_2\}$ | $\{q_0, q_1\}$ | $\{q_0\}$ |
| $\emptyset$ | $\emptyset$ | $\emptyset$ |

> 接受状态：所有包含 $q_2$ 的集合

---

## 6. 正则语言

### 6.1 定义

**正则语言**是能够被DFA（或NFA）识别的语言。

### 6.2 正则语言的封闭性

| 运算 | 封闭性 | 证明思路 |
|------|--------|----------|
| **并** $L_1 \cup L_2$ | ✓ | 并行构造NFA |
| **连接** $L_1 \cdot L_2$ | ✓ | $\varepsilon$-转移连接 |
| **克林星号** $L^*$ | ✓ | 添加回路 |
| **补** $\bar{L}$ | ✓ | 交换接受/非接受状态 |
| **交** $L_1 \cap L_2$ | ✓ | 积构造 |
| **差** $L_1 - L_2$ | ✓ | $L_1 \cap \bar{L_2}$ |

### 6.3 正则表达式

**正则表达式递归定义**：
$$\begin{align}
\emptyset &\text{ 是正则表达式} \\
\varepsilon &\text{ 是正则表达式} \\
a &\text{ 是正则表达式（} a \in \Sigma\text{）} \\
(r_1 \cup r_2), (r_1 \cdot r_2), r^* &\text{ 是正则表达式}
\end{align}$$

**等价性定理**：
$$L \text{ 是正则语言} \Leftrightarrow L \text{ 可用正则表达式描述} \Leftrightarrow L \text{ 可被FSM识别}$$

---

## 7. Pumping引理

### 7.1 定理陈述

**Pumping引理**：设 $L$ 是正则语言，则存在常数 $n$（泵长度），使得对于任意 $w \in L$ 且 $|w| \geq n$，可将 $w$ 分解为 $w = xyz$，满足：

1. $|xy| \leq n$
2. $|y| > 0$
3. 对于所有 $k \geq 0$，$xy^kz \in L$

### 7.2 直观理解

```
正则语言的FSM只有有限状态n
当字符串长度 > n 时，必然重复访问某状态
该重复部分就是可以"泵"的部分
```

### 7.3 应用：证明某语言不是正则语言

**示例**：证明 $L = \{a^n b^n \mid n \geq 0\}$ 不是正则语言

**证明**：
1. 假设 $L$ 是正则语言，泵长度为 $n$
2. 取 $w = a^n b^n \in L$，且 $|w| = 2n \geq n$
3. 由条件1、2，$y$ 只能由 $a$ 组成，即 $y = a^m$，$m > 0$
4. 取 $k = 2$，则 $xy^2z = a^{n+m} b^n \notin L$
5. 矛盾！$\therefore L$ 不是正则语言

### 7.4 常见非正则语言

| 语言 | 原因 |
|------|------|
| $\{a^n b^n \mid n \geq 0\}$ | 需要计数匹配 |
| $\{ww \mid w \in \Sigma^*\}$ | 需要记忆前半部分 |
| $\{a^{n^2} \mid n \geq 0\}$ | 指数增长 |
| $\{a^p \mid p \text{ 是素数}\}$ | 无法用有限状态描述 |

---

## 8. 最小化DFA

### 8.1 等价状态

两状态 $p, q$ **等价**（记作 $p \equiv q$）当且仅当：
$$\forall w \in \Sigma^*: \hat{\delta}(p, w) \in F \Leftrightarrow \hat{\delta}(q, w) \in F$$

### 8.2 最小化算法（Hopcroft算法）

```
初始化：将状态分为接受状态组和非接受状态组

迭代：
  对于每个状态组 P 和每个输入符号 a
    检查 P 中的状态在 a 上是否转移到不同的组
    若是，则分裂 P

直到：无法再分裂
```

### 8.3 唯一性定理

**定理**：对于任意正则语言 $L$，存在唯一（同构意义下）的最小状态DFA。

---

## 9. 语言学应用

### 9.1 构词一致性检测

将构词规则建模为FSM，验证新词是否合法。

**示例**：CVC结构的词根 + 后缀

```
状态定义：
  q0: 起点
  q1: 辅音后
  q2: 元音后（CVC词根完成）
  q3: 后缀后（接受）

转移：
  δ(q0, C) = q1
  δ(q1, V) = q2
  δ(q2, S) = q3
```

### 9.2 音系规则形式化

**规则**：$k \to g \ / \ V\_$ （元音后k浊化）

```
状态：
  q0: 默认状态
  q1: 元音后状态

转移：
  δ(q0, V) = q1
  δ(q0, 其他) = q0
  δ(q1, k) = q0, 输出 g
  δ(q1, 其他) = q0
```

---

## 10. 总结

### 10.1 核心概念速查

| 概念 | 数学表达 |
|------|----------|
| **DFA** | $M = (Q, \Sigma, \delta, q_0, F)$，$\delta: Q \times \Sigma \to Q$ |
| **NFA** | $M = (Q, \Sigma, \delta, q_0, F)$，$\delta: Q \times \Sigma \to 2^Q$ |
| **接受语言** | $L(M) = \{w \mid \hat{\delta}(q_0, w) \in F\}$ |
| **正则语言** | 能被DFA/NFA识别的语言 |
| **Pumping引理** | $w = xyz$，$xy^kz \in L$ |

### 10.2 关键定理

| 定理 | 内容 |
|------|------|
| **等价性定理** | DFA $\Leftrightarrow$ NFA $\Leftrightarrow$ 正则表达式 |
| **Pumping引理** | 正则语言的必要条件 |
| **最小化定理** | 每个正则语言有唯一最小DFA |

### 10.3 状态转移表模板

| $\delta$ | $a_1$ | $a_2$ | ... | $a_n$ |
|----------|-------|-------|-----|-------|
| $q_0$ | ... | ... | ... | ... |
| $q_1$ | ... | ... | ... | ... |
| ... | ... | ... | ... | ... |
| $q_m$ | ... | ... | ... | ... |
