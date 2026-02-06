---
tags:
  - Math
  - Calculus
  - 定义性
title: Infinite Series
created: 2026-02-06T18:50:00
modified:
---
# Infinite Series

## 1. 无穷级数基本概念

### 1.1 无穷级数的定义
无穷级数是指无限多个数相加的表达式：
$$\sum_{n=1}^{\infty} a_n = a_1 + a_2 + a_3 + \cdots$$

其中 $a_n$ 称为级数的第 n 项或通项。

### 1.2 部分和与级数收敛

**部分和**：前 n 项的和称为部分和，记为 $S_n$：
$$S_n = \sum_{k=1}^{n} a_k = a_1 + a_2 + \cdots + a_n$$

**级数收敛**：如果部分和数列 $\{S_n\}$ 收敛于某个有限值 S，则称级数 $\sum_{n=1}^{\infty} a_n$ 收敛，且和为 S：
$$\lim_{n \to \infty} S_n = S \quad \Rightarrow \quad \sum_{n=1}^{\infty} a_n = S$$

**级数发散**：如果部分和数列 $\{S_n\}$ 不收敛，则称级数发散。

### 1.3 收敛的必要条件

如果级数 $\sum_{n=1}^{\infty} a_n$ 收敛，则：
$$\lim_{n \to \infty} a_n = 0$$

**注意**：这是必要条件而非充分条件。即如果 $\lim_{n \to \infty} a_n \neq 0$，则级数一定发散；但如果 $\lim_{n \to \infty} a_n = 0$，级数仍可能发散。

[[limit]]
[[Indefinite Integration]]

## 2. 特殊级数

### 2.1 几何级数

**定义**：$\sum_{n=0}^{\infty} ar^n = a + ar + ar^2 + ar^3 + \cdots$

**收敛条件**：当 $|r| < 1$ 时收敛，当 $|r| \geq 1$ 时发散。

**收敛时的和**：
$$\sum_{n=0}^{\infty} ar^n = \frac{a}{1 - r}, \quad |r| < 1$$

**例子**：
- $\sum_{n=0}^{\infty} \left(\frac{1}{2}\right)^n = \frac{1}{1 - 1/2} = 2$
- $\sum_{n=0}^{\infty} 3(-1)^n$ 发散（因为 $|r| = 1$）

### 2.2 调和级数

**定义**：
$$\sum_{n=1}^{\infty} \frac{1}{n} = 1 + \frac{1}{2} + \frac{1}{3} + \frac{1}{4} + \cdots$$

**结论**：调和级数发散（尽管 $\lim_{n \to \infty} \frac{1}{n} = 0$）

### 2.3 p-级数

**定义**：
$$\sum_{n=1}^{\infty} \frac{1}{n^p}$$

**收敛条件**：
- 当 $p > 1$ 时收敛
- 当 $p \leq 1$ 时发散

**特例**：
- $p = 1$ 时为调和级数，发散
- $p = 2$ 时，$\sum_{n=1}^{\infty} \frac{1}{n^2} = \frac{\pi^2}{6}$（收敛）

## 3. 级数收敛判别法

### 3.1 积分判别法

**条件**：设 $f(x)$ 是一个正值、连续、递减的函数，且 $f(n) = a_n$，则级数 $\sum_{n=1}^{\infty} a_n$ 与积分 $\int_1^{\infty} f(x) \, dx$ 同敛散。

**例子**：判断 $\sum_{n=1}^{\infty} \frac{1}{n^2}$ 的收敛性
- 取 $f(x) = \frac{1}{x^2}$
- $\int_1^{\infty} \frac{1}{x^2} \, dx = \left[-\frac{1}{x}\right]_1^{\infty} = 1$（收敛）
- 因此 $\sum_{n=1}^{\infty} \frac{1}{n^2}$ 收敛

### 3.2 比较判别法

**直接比较判别法**：
设 $0 \leq a_n \leq b_n$ 对所有 n 成立
- 如果 $\sum b_n$ 收敛，则 $\sum a_n$ 收敛
- 如果 $\sum a_n$ 发散，则 $\sum b_n$ 发散

**例子**：判断 $\sum_{n=1}^{\infty} \frac{1}{n^2 + 1}$ 的收敛性
- $\frac{1}{n^2 + 1} < \frac{1}{n^2}$
- $\sum \frac{1}{n^2}$ 收敛
- 因此 $\sum \frac{1}{n^2 + 1}$ 收敛

### 3.3 极限比较判别法

**条件**：设 $a_n > 0$，$b_n > 0$，计算：
$$L = \lim_{n \to \infty} \frac{a_n}{b_n}$$

- 如果 $0 < L < \infty$，则 $\sum a_n$ 和 $\sum b_n$ 同敛散
- 如果 $L = 0$ 且 $\sum b_n$ 收敛，则 $\sum a_n$ 收敛
- 如果 $L = \infty$ 且 $\sum b_n$ 发散，则 $\sum a_n$ 发散

**例子**：判断 $\sum_{n=1}^{\infty} \frac{n}{n^3 + 1}$ 的收敛性
- 与 $\sum \frac{1}{n^2}$ 比较
- $\lim_{n \to \infty} \frac{n/(n^3 + 1)}{1/n^2} = \lim_{n \to \infty} \frac{n^3}{n^3 + 1} = 1$
- $\sum \frac{1}{n^2}$ 收敛
- 因此 $\sum \frac{n}{n^3 + 1}$ 收敛

### 3.4 比值判别法

**计算**：
$$L = \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_n}\right|$$

- 如果 $L < 1$，级数绝对收敛
- 如果 $L > 1$（或 $L = \infty$），级数发散
- 如果 $L = 1$，判别法失效

**例子**：判断 $\sum_{n=1}^{\infty} \frac{n!}{10^n}$ 的收敛性
- $\frac{a_{n+1}}{a_n} = \frac{(n+1)!/10^{n+1}}{n!/10^n} = \frac{n+1}{10}$
- $\lim_{n \to \infty} \frac{n+1}{10} = \infty > 1$
- 因此级数发散

### 3.5 根值判别法

**计算**：
$$L = \lim_{n \to \infty} \sqrt[n]{|a_n|}$$

- 如果 $L < 1$，级数绝对收敛
- 如果 $L > 1$（或 $L = \infty$），级数发散
- 如果 $L = 1$，判别法失效

**例子**：判断 $\sum_{n=1}^{\infty} \left(\frac{n}{2n+1}\right)^n$ 的收敛性
- $\sqrt[n]{a_n} = \frac{n}{2n+1}$
- $\lim_{n \to \infty} \frac{n}{2n+1} = \frac{1}{2} < 1$
- 因此级数收敛

### 3.6 交错级数判别法（莱布尼茨判别法）

**条件**：对于交错级数 $\sum_{n=1}^{\infty} (-1)^{n-1} b_n$（其中 $b_n > 0$），如果：
1. $b_{n+1} \leq b_n$ 对所有 n 成立（递减）
2. $\lim_{n \to \infty} b_n = 0$

则级数收敛。

**例子**：判断 $\sum_{n=1}^{\infty} \frac{(-1)^{n-1}}{n}$ 的收敛性
- $b_n = \frac{1}{n}$，$b_{n+1} = \frac{1}{n+1} < \frac{1}{n} = b_n$（递减）
- $\lim_{n \to \infty} \frac{1}{n} = 0$
- 因此级数收敛

## 4. 绝对收敛与条件收敛

### 4.1 绝对收敛

**定义**：如果 $\sum_{n=1}^{\infty} |a_n|$ 收敛，则称 $\sum_{n=1}^{\infty} a_n$ 绝对收敛。

**性质**：绝对收敛的级数一定收敛。

**例子**：$\sum_{n=1}^{\infty} \frac{(-1)^n}{n^2}$ 绝对收敛（因为 $\sum \frac{1}{n^2}$ 收敛）

### 4.2 条件收敛

**定义**：如果 $\sum_{n=1}^{\infty} a_n$ 收敛，但 $\sum_{n=1}^{\infty} |a_n|$ 发散，则称 $\sum_{n=1}^{\infty} a_n$ 条件收敛。

**例子**：$\sum_{n=1}^{\infty} \frac{(-1)^{n-1}}{n}$ 条件收敛（级数收敛，但 $\sum \frac{1}{n}$ 发散）

## 5. 幂级数

### 5.1 幂级数的定义

幂级数是指形如：
$$\sum_{n=0}^{\infty} c_n (x - a)^n = c_0 + c_1(x - a) + c_2(x - a)^2 + \cdots$$

的级数，其中 $c_n$ 是系数，$a$ 是中心点。

### 5.2 收敛半径与收敛区间

**收敛半径 R**：幂级数在 $|x - a| < R$ 时绝对收敛，在 $|x - a| > R$ 时发散。

**收敛半径的计算**（使用比值判别法）：
$$R = \lim_{n \to \infty} \left|\frac{c_n}{c_{n+1}}\right| \quad \text{或} \quad R = \lim_{n \to \infty} \frac{1}{\sqrt[n]{|c_n|}}$$

**收敛区间**：
- 开区间：$(a - R, a + R)$
- 需要单独检验端点 $x = a - R$ 和 $x = a + R$

**例子**：求 $\sum_{n=0}^{\infty} \frac{x^n}{n!}$ 的收敛区间
- $\frac{c_{n+1}}{c_n} = \frac{1/(n+1)!}{1/n!} = \frac{1}{n+1}$
- $\lim_{n \to \infty} \frac{1}{n+1} = 0$
- 收敛半径 $R = \infty$
- 收敛区间：$(-\infty, \infty)$

### 5.3 幂级数的运算

**逐项求导**：
$$\frac{d}{dx}\left[\sum_{n=0}^{\infty} c_n (x - a)^n\right] = \sum_{n=1}^{\infty} n c_n (x - a)^{n-1}$$

**逐项积分**：
$$\int \left[\sum_{n=0}^{\infty} c_n (x - a)^n\right] dx = \sum_{n=0}^{\infty} \frac{c_n}{n+1} (x - a)^{n+1} + C$$

## 6. 泰勒级数与麦克劳林级数

### 6.1 泰勒级数

**定义**：函数 $f(x)$ 在 $x = a$ 处的泰勒级数为：
$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(a)}{n!}(x - a)^n$$

其中 $f^{(n)}(a)$ 表示 $f(x)$ 在 $x = a$ 处的 n 阶导数。

### 6.2 麦克劳林级数

当 $a = 0$ 时，泰勒级数称为麦克劳林级数：
$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!}x^n$$

### 6.3 常见函数的麦克劳林级数

| 函数 | 麦克劳林级数 | 收敛区间 |
|------|------------|---------|
| $e^x$ | $\sum_{n=0}^{\infty} \frac{x^n}{n!} = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \cdots$ | $(-\infty, \infty)$ |
| $\sin x$ | $\sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!} = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \cdots$ | $(-\infty, \infty)$ |
| $\cos x$ | $\sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{(2n)!} = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \cdots$ | $(-\infty, \infty)$ |
| $\frac{1}{1-x}$ | $\sum_{n=0}^{\infty} x^n = 1 + x + x^2 + x^3 + \cdots$ | $(-1, 1)$ |
| $\ln(1+x)$ | $\sum_{n=1}^{\infty} \frac{(-1)^{n-1} x^n}{n} = x - \frac{x^2}{2} + \frac{x^3}{3} - \cdots$ | $(-1, 1]$ |
| $\arctan x$ | $\sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{2n+1} = x - \frac{x^3}{3} + \frac{x^5}{5} - \cdots$ | $[-1, 1]$ |

### 6.4 拉格朗日余项

泰勒级数的误差估计：
$$R_n(x) = \frac{f^{(n+1)}(c)}{(n+1)!}(x - a)^{n+1}$$

其中 c 介于 a 和 x 之间。

## 7. AP微积分BC考试重点

1. **级数收敛判别法**：熟练掌握各种判别法的使用条件和步骤
2. **几何级数与 p-级数**：记住收敛条件和求和公式
3. **收敛半径与收敛区间**：能够计算幂级数的收敛半径并确定收敛区间
4. **泰勒级数展开**：能够求函数的泰勒级数或麦克劳林级数
5. **常见函数的级数展开**：记住 $e^x$、$\sin x$、$\cos x$ 等的麦克劳林级数
6. **绝对收敛与条件收敛**：能够判断级数的收敛类型
7. **幂级数运算**：掌握幂级数的逐项求导和逐项积分
8. **级数的应用**：使用泰勒级数进行函数近似计算

## 8. 典型例题

### 8.1 判断级数收敛性

**题目**：判断 $\sum_{n=1}^{\infty} \frac{(-1)^n n}{n^2 + 1}$ 的收敛性（绝对收敛还是条件收敛）。

**解**：
- 判断绝对收敛：$\sum_{n=1}^{\infty} \left|\frac{(-1)^n n}{n^2 + 1}\right| = \sum_{n=1}^{\infty} \frac{n}{n^2 + 1}$
- 与 $\sum \frac{1}{n}$ 比较：
  $\lim_{n \to \infty} \frac{n/(n^2 + 1)}{1/n} = \lim_{n \to \infty} \frac{n^2}{n^2 + 1} = 1$
- $\sum \frac{1}{n}$ 发散，因此 $\sum \frac{n}{n^2 + 1}$ 发散
- 不是绝对收敛
- 判断条件收敛：使用莱布尼茨判别法
  - $b_n = \frac{n}{n^2 + 1}$，当 n 增大时递减
  - $\lim_{n \to \infty} \frac{n}{n^2 + 1} = 0$
- 因此原级数条件收敛

### 8.2 求收敛半径

**题目**：求 $\sum_{n=1}^{\infty} \frac{(x - 2)^n}{n \cdot 3^n}$ 的收敛半径和收敛区间。

**解**：
- $c_n = \frac{1}{n \cdot 3^n}$
- $\left|\frac{c_{n+1}}{c_n}\right| = \frac{1/(n+1) \cdot 3^{n+1}}{1/n \cdot 3^n} = \frac{n}{3(n+1)}$
- $\lim_{n \to \infty} \frac{n}{3(n+1)} = \frac{1}{3}$
- 收敛半径 $R = \frac{1}{1/3} = 3$
- 收敛区间：$|x - 2| < 3$，即 $(-1, 5)$
- 检验端点：
  - $x = -1$：$\sum \frac{(-3)^n}{n \cdot 3^n} = \sum \frac{(-1)^n}{n}$ 收敛
  - $x = 5$：$\sum \frac{3^n}{n \cdot 3^n} = \sum \frac{1}{n}$ 发散
- 收敛区间：$[-1, 5)$

### 8.3 泰勒级数展开

**题目**：求 $f(x) = e^{-x^2}$ 在 $x = 0$ 处的麦克劳林级数。

**解**：
- $e^u = \sum_{n=0}^{\infty} \frac{u^n}{n!}$
- 令 $u = -x^2$：
- $e^{-x^2} = \sum_{n=0}^{\infty} \frac{(-x^2)^n}{n!} = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{n!} = 1 - x^2 + \frac{x^4}{2!} - \frac{x^6}{3!} + \cdots$
