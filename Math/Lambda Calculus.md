---
tags:
  - Math
  - Logic
  - 定义性
  - ComputerScience
title: Lambda Calculus
created: 2026-03-19T12:00:00
modified:
---
# Lambda Calculus λ演算
**λ演算** (Lambda Calculus) 是一套从数学逻辑中发展, 以变量绑定和替换的规则, 来研究函数如何抽象化定义、函数如何被应用以及递归的形式系统。由逻辑学家 **Alonzo Church (阿隆佐·邱奇)** 在20世纪30年代提出。

λ演算是**图灵完备 (Turing Complete)** 的，与图灵机等价，是函数式编程语言的理论基础。

---

## 1. 基本语法
λ演算由三种基本元素构成：

| 名称 | 语法 | 示例 | 说明 |
|------|------|------|------|
| 变量 (Variable) | $\langle\text{变量名}\rangle$ | $x$ | 一个标识符 |
| 抽象 (Abstraction) | $\lambda x. M$ | $\lambda x. x$ | 函数定义，$x$是参数，$M$是函数体 |
| 应用 (Application) | $M \, N$ | $(\lambda x. x) \, y$ | 函数调用，将$N$应用到$M$ |

### 1.1 约定 (Conventions)
- **左结合 (Left Associative)**：$M \, N \, P$ 等价于 $((M \, N) \, P)$
- **抽象优先级高于应用**：$\lambda x. M \, N$ 等价于 $\lambda x. (M \, N)$
- **多参数简化**：$\lambda x. \lambda y. M$ 可简写为 $\lambda xy. M$

### 1.2 自由变量与约束变量 (Free and Bound Variables)
- **约束变量 (Bound Variable)**：在$\lambda$表达式中被绑定的变量
- **自由变量 (Free Variable)**：不在任何$\lambda$作用域内的变量

$$FV(x) = \{x\}$$
$$FV(\lambda x. M) = FV(M) \setminus \{x\}$$
$$FV(M \, N) = FV(M) \cup FV(N)$$

例如：在 $\lambda x. x \, y$ 中，$x$ 是约束变量，$y$ 是自由变量。

---

## 2. 规约规则 (Reduction Rules)
### 2.1 α转换 (Alpha Conversion)
**α转换 (Alpha Conversion)** 允许重命名约束变量，避免变量名冲突：

$$\lambda x. M \to_\alpha \lambda y. M[x := y]$$

条件：$y$ 不在 $M$ 中自由出现。

**示例**：
$$\lambda x. x \to_\alpha \lambda y. y$$

### 2.2 β规约 (Beta Reduction)
**β规约 (Beta Reduction)** 是函数应用的核心操作，将参数代入函数体：

$$(\lambda x. M) \, N \to_\beta M[x := N]$$

**示例**：
$$(\lambda x. x^2 + 1) \, 3 \to_\beta 3^2 + 1 = 10$$

$$(\lambda x. \lambda y. x \, y) \, a \, b \to_\beta (\lambda y. a \, y) \, b \to_\beta a \, b$$

### 2.3 η转换 (Eta Conversion)
**η转换 (Eta Conversion)** 表达函数外延性 (Extensionality)：若函数对任意输入产生相同输出，则两函数等价：

$$\lambda x. M \, x \leftrightarrow_\eta M$$

条件：$x$ 不在 $M$ 中自由出现。

**示例**：
$$\lambda x. f \, x \leftrightarrow_\eta f$$

---

## 3. Church编码 (Church Encoding)

在纯λ演算中没有内置的数据类型，但可以通过 **Church编码 (Church Encoding)** 表示数据。

### 3.1 布尔值 (Booleans)

$$\text{TRUE} = \lambda t. \lambda f. t$$
$$\text{FALSE} = \lambda t. \lambda f. f$$

**条件分支 (Conditional)**：
$$\text{IF} = \lambda b. \lambda t. \lambda f. b \, t \, f$$

验证：
$$\text{IF} \, \text{TRUE} \, a \, b = (\lambda b. \lambda t. \lambda f. b \, t \, f) \, (\lambda t. \lambda f. t) \, a \, b \to_\beta a$$

### 3.2 逻辑运算 (Logical Operations)

$$\text{AND} = \lambda a. \lambda b. a \, b \, \text{FALSE}$$
$$\text{OR} = \lambda a. \lambda b. a \, \text{TRUE} \, b$$
$$\text{NOT} = \lambda a. a \, \text{FALSE} \, \text{TRUE}$$

### 3.3 Church数字 (Church Numerals)
$$0 = \lambda f. \lambda x. x$$
$$1 = \lambda f. \lambda x. f \, x$$
$$2 = \lambda f. \lambda x. f \, (f \, x)$$
$$3 = \lambda f. \lambda x. f \, (f \, (f \, x))$$

一般形式：
$$n = \lambda f. \lambda x. f^n \, x$$

其中 $f^n$ 表示 $f$ 的 $n$ 次复合应用 (Function Composition)。

### 3.4 后继运算 (Successor)
$$\text{SUCC} = \lambda n. \lambda f. \lambda x. f \, (n \, f \, x)$$

验证：
$$\text{SUCC} \, 1 = \lambda f. \lambda x. f \, ((\lambda f. \lambda x. f \, x) \, f \, x) \to_\beta \lambda f. \lambda x. f \, (f \, x) = 2$$

### 3.5 算术运算 (Arithmetic Operations)
**加法 (Addition)**：
$$\text{ADD} = \lambda m. \lambda n. \lambda f. \lambda x. m \, f \, (n \, f \, x)$$

**乘法 (Multiplication)**：
$$\text{MULT} = \lambda m. \lambda n. \lambda f. m \, (n \, f)$$

**乘方 (Exponentiation)**：
$$\text{POW} = \lambda b. \lambda e. e \, b$$

**前驱 (Predecessor)**（返回 $n-1$，若 $n=0$ 返回 $0$）：
$$\text{PRED} = \lambda n. \lambda f. \lambda x. n \, (\lambda g. \lambda h. h \, (g \, f)) \, (\lambda u. x) \, (\lambda u. u)$$

**减法 (Subtraction)**：
$$\text{SUB} = \lambda m. \lambda n. n \, \text{PRED} \, m$$

### 3.6 判断零 (Is Zero)
$$\text{ISZERO} = \lambda n. n \, (\lambda x. \text{FALSE}) \, \text{TRUE}$$

---

## 4. Y组合子 (Y Combinator)
### 4.1 不动点组合子 (Fixed-Point Combinator)
**不动点 (Fixed Point)**：若 $f(x) = x$，则 $x$ 是函数 $f$ 的不动点。

**不动点组合子 (Fixed-Point Combinator)** 是一个高阶函数 $Y$，满足：
$$Y \, F = F \, (Y \, F)$$

### 4.2 Y组合子定义 (Definition of Y Combinator)
$$Y = \lambda f. (\lambda x. f \, (x \, x)) \, (\lambda x. f \, (x \, x))$$

验证：
$$Y \, F = (\lambda f. (\lambda x. f \, (x \, x)) \, (\lambda x. f \, (x \, x))) \, F$$
$$\to_\beta (\lambda x. F \, (x \, x)) \, (\lambda x. F \, (x \, x))$$
$$\to_\beta F \, ((\lambda x. F \, (x \, x)) \, (\lambda x. F \, (x \, x)))$$
$$= F \, (Y \, F)$$

### 4.3 实现递归 (Implementing Recursion)
使用Y组合子实现阶乘 (Factorial)：

定义非递归版本：
$$G = \lambda f. \lambda n. \text{IF} \, (\text{ISZERO} \, n) \, 1 \, (\text{MULT} \, n \, (f \, (\text{PRED} \, n)))$$

则：
$$\text{FACT} = Y \, G$$

---

## 5. 组合子 (Combinators)
**组合子 (Combinator)** 是不含自由变量的λ表达式。

### 5.1 常用组合子 (Common Combinators)
**I (Identity)**：
$$I = \lambda x. x$$

**K (Constant)**：
$$K = \lambda x. \lambda y. x$$

**S (Substitution)**：
$$S = \lambda x. \lambda y. \lambda z. x \, z \, (y \, z)$$

### 5.2 SK组合子演算 (SKI Combinator Calculus)
SK组合子系统是图灵完备的：

$$I = S \, K \, K$$

验证：
$$S \, K \, K = (\lambda x. \lambda y. \lambda z. x \, z \, (y \, z)) \, K \, K$$
$$\to_\beta \lambda z. K \, z \, (K \, z)$$
$$\to_\beta \lambda z. z = I$$

---

## 6. 规约策略 (Reduction Strategies)
### 6.1 规范序 (Normal Order)
**最左最外优先**：先规约最左边的最外层 $\text{redex}$（可规约表达式，Reducible Expression）。

如果表达式有规范形 (Normal Form)，则规范序一定能找到。

### 6.2 应用序 (Applicative Order)
**最左最内优先**：先规约最左边的最内层 $\text{redex}$（参数先求值）。

可能导致无限循环，即使规范形存在。

### 6.3 示例 (Example)
考虑 $(\lambda x. y) \, ((\lambda z. z \, z) \, (\lambda z. z \, z))$：

- **规范序**：$\to_\beta y$（直接得到结果）
- **应用序**：先规约参数，产生无限循环

---

## 7. 类型化λ演算 (Typed Lambda Calculus)
### 7.1 简单类型λ演算 (Simply Typed Lambda Calculus, STLC)
类型语法：
$$\tau ::= \alpha \mid \tau_1 \to \tau_2$$

类型规则 (Typing Rules)：
$$\frac{x : \tau \in \Gamma}{\Gamma \vdash x : \tau} \quad \frac{\Gamma, x : \tau_1 \vdash M : \tau_2}{\Gamma \vdash \lambda x. M : \tau_1 \to \tau_2} \quad \frac{\Gamma \vdash M : \tau_1 \to \tau_2 \quad \Gamma \vdash N : \tau_1}{\Gamma \vdash M \, N : \tau_2}$$

### 7.2 重要性质 (Important Properties)
- **强正规化 (Strong Normalization)**：类型良好的项必定终止
- **类型推断 (Type Inference)**：Hindley-Milner 类型系统

---

## 8. Currying 柯里化
**Currying** 是将接受多个参数的函数转换为一系列接受单个参数的函数的过程。

### 8.1 定义 (Definition)
给定函数 $f : A \times B \to C$，其柯里化形式为：

$$\text{curry}(f) : A \to (B \to C)$$

使得：
$$\text{curry}(f)(a)(b) = f(a, b)$$

### 8.2 在λ演算中的表示 (Representation in Lambda Calculus)
多参数函数可通过嵌套抽象 (Nested Abstraction) 实现柯里化：

$$\lambda x. \lambda y. \lambda z. M \quad \text{对应于} \quad f(x, y, z) = M$$

**示例**：加法函数
$$\text{ADD} = \lambda x. \lambda y. x + y$$

部分应用 (Partial Application)：
$$\text{ADD} \, 3 = \lambda y. 3 + y$$

### 8.3 反柯里化 (Uncurrying)
将柯里化函数还原为多参数函数：

$$\text{uncurry}(g) : A \times B \to C$$
$$\text{uncurry}(g)(a, b) = g(a)(b)$$

### 8.4 性质 (Properties)
柯里化与反柯里化互为逆操作 (Inverse Operations)：

$$\text{uncurry}(\text{curry}(f)) = f$$
$$\text{curry}(\text{uncurry}(g)) = g$$

### 8.5 实际应用 (Practical Applications)

- **部分应用 (Partial Application)**：固定部分参数，生成新函数
- **函数组合 (Function Composition)**：简化高阶函数的定义
- **惰性求值 (Lazy Evaluation)**：参数可按需提供

---

## 9. Curry-Howard 同构 (Curry-Howard Isomorphism)
**Curry-Howard 同构 (Curry-Howard Isomorphism)**（又称 Curry-Howard 对应，Curry-Howard Correspondence）揭示了类型论 (Type Theory) 与逻辑学 (Logic) 之间的深刻联系：**类型即命题，程序即证明 (Types as Propositions, Programs as Proofs)**。

### 9.1 基本对应 (Basic Correspondence)
| 逻辑 (Logic) | 类型论 (Type Theory) |
|------|--------|
| 命题 $P$ (Proposition) | 类型 $T$ (Type) |
| $P \to Q$（蕴含，Implication） | $A \to B$（函数类型，Function Type） |
| $P \land Q$（合取，Conjunction） | $A \times B$（积类型，Product Type） |
| $P \lor Q$（析取，Disjunction） | $A + B$（和类型，Sum Type） |
| $\forall x. P(x)$（全称量化，Universal Quantification） | $\forall x : A. B$（依赖积/Π类型，Dependent Product/Π-Type） |
| $\exists x. P(x)$（存在量化，Existential Quantification） | $\exists x : A. B$（依赖和/Σ类型，Dependent Sum/Σ-Type） |
| 证明 $p$ (Proof) | 程序 $M$ (Program/Term) |
| 证明 $P \to Q$ | 函数 $f : A \to B$ |

### 9.2 命题即类型 (Propositions as Types)
**命题 $P$ 为真** $\Leftrightarrow$ **类型 $T$ 有 inhabitants**（即存在类型为 $T$ 的项，Inhabited Type）

**命题 $P$ 为假** $\Leftrightarrow$ **类型 $T$ 为空类型 (Empty Type/Void)**（无 inhabitants）

### 9.3 推理规则对应 (Inference Rule Correspondence)
**Modus Ponens（肯定前件，Modus Ponens）**：

$$\frac{\Gamma \vdash P \quad \Gamma \vdash P \to Q}{\Gamma \vdash Q}$$

对应函数应用 (Function Application)：

$$\frac{\Gamma \vdash M : A \quad \Gamma \vdash N : A \to B}{\Gamma \vdash N \, M : B}$$

**蕴含引入 (Implication Introduction)**：

$$\frac{\Gamma, P \vdash Q}{\Gamma \vdash P \to Q}$$

对应函数抽象 (Function Abstraction)：

$$\frac{\Gamma, x : A \vdash M : B}{\Gamma \vdash \lambda x. M : A \to B}$$

### 9.4 示例：恒等函数即恒等命题 (Identity Function as Identity Proposition)
**恒等命题 (Identity Proposition)**：$P \to P$

**证明**（λ项）：
$$\lambda x. x : A \to A$$

类型为 $A \to A$ 的恒等函数就是命题 $P \to P$ 的证明。

### 9.5 示例：合取消去 (Conjunction Elimination)
**逻辑规则 (Logical Rules)**：
$$\frac{\Gamma \vdash P \land Q}{\Gamma \vdash P} \quad \frac{\Gamma \vdash P \land Q}{\Gamma \vdash Q}$$

**类型规则**（投影函数，Projection Functions）：
$$\pi_1 : A \times B \to A$$
$$\pi_2 : A \times B \to B$$

其中 $\pi_1 = \lambda p. p \, (\lambda x. \lambda y. x)$，$\pi_2 = \lambda p. p \, (\lambda x. \lambda y. y)$。

### 9.6 意义 (Significance)
- **构造性证明 (Constructive Proof)**：证明一个命题 = 构造一个程序
- **程序验证 (Program Verification)**：类型检查 = 证明验证
- **逻辑系统设计 (Logic System Design)**：设计类型系统 = 设计逻辑系统
- **定理证明助手 (Theorem Prover/Proof Assistant)**：Coq、Agda、Lean 等基于此原理

---

## 10. 与其他理论的联系 (Relations to Other Theories)
- **[[Chomsky - Automata]]**：λ演算与递归可枚举语言 (Recursively Enumerable Languages) 的关系
- **[[Logic]]**：Curry-Howard 同构建立了逻辑与计算的桥梁
- **函数式编程 (Functional Programming)**：Haskell、ML 等语言的语义基础
- **定理证明 (Theorem Proving)**：Coq、Agda、Lean 等证明助手 (Proof Assistants) 的理论基础

---
