---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: series_problem_03.28
created: 2026-03-28T21:11:00
modified:
---
# series_problem_03.28
[[Infinite Series]]

## Q1
>What are all values of $k$ for which the series $$\sum_{n=0}^\infty ((k^3+2)e^{-k})^n$$ converges

请更加熟练地使用图形计算器！

以$x$代替$k$作为自变量画出函数图形，并且找到零点$$abs(X³+2) * e^{(-X)} - 1$$

最终得出$$-1.314 < k < -1.198 \text{ and } k > 4.596$$

## Q2
>若$b_n$是一个序列，而$a_n=b_n-b_{n-1}$，那么对于$\sum^\infty_{n=1} a_n$
> (A) The series converges $\lim_{n\to\infty} a_n=0$
> (B) The series converges if $\lim_{n\to\infty} b_n$ is a finite real number
> (C) The series diverges if $lim_{n\to\infty} b_n\neq 0$
> (D) The series has $lim_{n\to\infty} b_n$ as its sum if $lim_{n\to\infty} b_n$ is a finite real number.

设部分和 $S_N = \sum_{n=1}^{N} a_n = \sum_{n=1}^{N} (b_n - b_{n-1})$

展开后中间项相互抵消：
$$S_N = (b_1 - b_0) + (b_2 - b_1) + \cdots + (b_N - b_{N-1}) = b_N -
b_0$$

因此$$\sum_{n=1}^{\infty} a_n = \lim_{N\to\infty} (b_N - b_0) =
\lim_{n\to\infty} b_n - b_0$$

应当选择**B**

## Q3
> 第 n 项判别法可以用于判断下列级数的发散性，除了
> (A) $\displaystyle \sum_{n=1}^{\infty} \arctan n$
> (B) $\displaystyle \sum_{n=1}^{\infty} \frac{1}{6^n}$
> (C) $\displaystyle \sum_{n=1}^{\infty} \frac{n(n+3)}{(n+4)^2}$
> (D) $\displaystyle \sum_{n=1}^{\infty} \ln n$

**解析**：第 n 项判别法（The *n*th term test）：若级数 $\sum a_n$ 收敛，则 $\lim_{n\to\infty} a_n = 0$。其逆否命题为：若 $\lim_{n\to\infty} a_n \neq 0$，则级数发散。

逐项分析：
- (A) $\lim_{n\to\infty} \arctan n = \frac{\pi}{2} \neq 0$，发散 ✓
- (B) $\lim_{n\to\infty} \frac{1}{6^n} = 0$，**无法用第 n 项判别法确定发散** ✗
- (C) $\lim_{n\to\infty} \frac{n(n+3)}{(n+4)^2} = \lim_{n\to\infty} \frac{n^2+3n}{n^2+8n+16} = 1 \neq 0$，发散 ✓
- (D) $\lim_{n\to\infty} \ln n = \infty \neq 0$，发散 ✓

**答案：B**（几何级数，实际上收敛于 $\frac{1/6}{1-1/6} = \frac{1}{5}$）

## Q4
> 积分判别法可以用于判断关于无穷级数 $\displaystyle \sum_{n=1}^{\infty} \frac{n}{n^2 + 1}$ 的下列哪个说法是正确的？
> (A) 级数收敛，且级数的通项极限为 0。
> (B) 级数发散，且级数的通项极限为 0。
> (C) 级数收敛，且级数的通项极限不为 0。
> (D) 级数发散，且级数的通项极限不为 0。

**解析**：使用积分判别法，设 $f(x) = \frac{x}{x^2+1}$

计算积分：
$$\int_1^{\infty} \frac{x}{x^2+1} \, dx = \frac{1}{2} \int_1^{\infty} \frac{2x}{x^2+1} \, dx = \frac{1}{2} \left[\ln(x^2+1)\right]_1^{\infty} = \infty$$

积分发散，故级数发散。

检查通项极限：
$$\lim_{n\to\infty} \frac{n}{n^2+1} = \lim_{n\to\infty} \frac{1}{n+\frac{1}{n}} = 0$$

**答案：B**（级数发散，且通项极限为 0）

## Q5
> 积分判别法可以用于判断关于无穷级数 $\displaystyle \sum_{n=1}^{\infty} \frac{n}{e^n}$ 的下列哪个说法是正确的？
> (A) 级数收敛，且级数的通项极限为 0。
> (B) 级数发散，且级数的通项极限为 0。
> (C) 级数收敛，且级数的通项极限不为 0。
> (D) 级数发散，且级数的通项极限不为 0。

**解析**：使用积分判别法，设 $f(x) = \frac{x}{e^x} = xe^{-x}$

计算积分：
$$\int_1^{\infty} xe^{-x} \, dx$$

使用分部积分，设 $u = x$，$dv = e^{-x}dx$：
$$\int xe^{-x} \, dx = -xe^{-x} + \int e^{-x} dx = -xe^{-x} - e^{-x} = -e^{-x}(x+1)$$

因此：
$$\int_1^{\infty} xe^{-x} \, dx = \left[-e^{-x}(x+1)\right]_1^{\infty} = 0 - (-2e^{-1}) = \frac{2}{e}$$

积分收敛，故级数收敛。

检查通项极限：
$$\lim_{n\to\infty} \frac{n}{e^n} = 0$$

**答案：A**（级数收敛，且通项极限为 0）

## Q6
> 下列哪个级数可以用比值判别法证明其收敛？
> (A) $\displaystyle \sum_{n=1}^{\infty} \frac{\sqrt{n}}{n+10}$
> (B) $\displaystyle \sum_{n=1}^{\infty} \frac{n^{10}}{10^n}$
> (C) $\displaystyle \sum_{n=1}^{\infty} \frac{\ln(n)}{n^2}$
> (D) $\displaystyle \sum_{n=1}^{\infty} \frac{n+1}{n^4}$

**解析**：比值判别法计算 $L = \lim_{n\to\infty} \left|\frac{a_{n+1}}{a_n}\right|$，当 $L < 1$ 时级数收敛。

逐项分析：

**(A)** $a_n = \frac{\sqrt{n}}{n+10}$
$$\frac{a_{n+1}}{a_n} = \frac{\sqrt{n+1}/(n+11)}{\sqrt{n}/(n+10)} = \frac{\sqrt{n+1}}{\sqrt{n}} \cdot \frac{n+10}{n+11} \to 1$$
$L = 1$，比值判别法失效。

**(B)** $a_n = \frac{n^{10}}{10^n}$
$$\frac{a_{n+1}}{a_n} = \frac{(n+1)^{10}/10^{n+1}}{n^{10}/10^n} = \frac{(n+1)^{10}}{n^{10}} \cdot \frac{1}{10} \to 1 \cdot \frac{1}{10} = \frac{1}{10}$$
$L = \frac{1}{10} < 1$，**比值判别法可证明收敛** ✓

**(C)** $a_n = \frac{\ln n}{n^2}$
$$\frac{a_{n+1}}{a_n} = \frac{\ln(n+1)/(n+1)^2}{\ln n/n^2} = \frac{\ln(n+1)}{\ln n} \cdot \frac{n^2}{(n+1)^2} \to 1$$
$L = 1$，比值判别法失效。

**(D)** $a_n = \frac{n+1}{n^4}$
$$\frac{a_{n+1}}{a_n} = \frac{(n+2)/(n+1)^4}{(n+1)/n^4} = \frac{n+2}{n+1} \cdot \frac{n^4}{(n+1)^4} \to 1$$
$L = 1$，比值判别法失效。

**答案：B**（比值判别法适用，$L = \frac{1}{10} < 1$）

## Q7
> 下列哪些级数收敛？
> I. $\displaystyle \sum_{n=1}^{\infty} n\left(\frac{1}{e}\right)^n$
> II. $\displaystyle \sum_{n=1}^{\infty} \frac{n!}{100^n}$
> III. $\displaystyle \sum_{n=1}^{\infty} \frac{(n!)^2}{(2n)!}$
> 
> (A) 仅 I  
> (B) 仅 III  
> (C) 仅 I 和 II  
> (D) 仅 I 和 III

**解析**：使用比值判别法判断每个级数。

**I.** $\displaystyle \sum_{n=1}^{\infty} n\left(\frac{1}{e}\right)^n$

$$\frac{a_{n+1}}{a_n} = \frac{(n+1)(1/e)^{n+1}}{n(1/e)^n} = \frac{n+1}{n} \cdot \frac{1}{e} \to \frac{1}{e} < 1$$

**收敛** ✓

**II.** $\displaystyle \sum_{n=1}^{\infty} \frac{n!}{100^n}$

$$\frac{a_{n+1}}{a_n} = \frac{(n+1)!/100^{n+1}}{n!/100^n} = \frac{n+1}{100} \to \infty$$

**发散** ✗

**III.** $\displaystyle \sum_{n=1}^{\infty} \frac{(n!)^2}{(2n)!}$

$$\frac{a_{n+1}}{a_n} = \frac{((n+1)!)^2/(2n+2)!}{(n!)^2/(2n)!} = \frac{(n+1)^2}{(2n+2)(2n+1)} = \frac{(n+1)^2}{(2n+2)(2n+1)} = \frac{n+1}{2(2n+1)} \to \frac{1}{4} < 1$$

**收敛** ✓

**答案：D**（仅 I 和 III 收敛）

## Q8
> 考虑级数 $\displaystyle \sum_{n=1}^{\infty} (-1)^{n+1} a_n$，其中 $a_n > \dfrac{1}{n}$ 对所有 $n$ 成立，且序列 $\{a_n\}$ 递减并趋于 0。下列哪个说法是正确的？
> (A) 级数绝对收敛。
> (B) 级数条件收敛。
> (C) 级数发散。
> (D) 信息不足以判断级数收敛还是发散。

**解析**：

**条件收敛判断**（莱布尼茨判别法）：
- $\{a_n\}$ 递减 ✓
- $\lim_{n\to\infty} a_n = 0$ ✓

因此交错级数 $\sum (-1)^{n+1} a_n$ **收敛**。

**绝对收敛判断**：
由于 $a_n > \frac{1}{n}$，有：
$$\sum_{n=1}^{\infty} |(-1)^{n+1} a_n| = \sum_{n=1}^{\infty} a_n > \sum_{n=1}^{\infty} \frac{1}{n}$$

调和级数发散，由比较判别法，$\sum a_n$ 发散。

因此级数**条件收敛**。

**答案：B**（条件收敛）

## Q9
> 考虑幂级数 $\displaystyle \sum_{n=0}^{\infty} a_n (x - b)^n$，其中 $b$ 是整数。上表显示了级数在不同 $x$ 值处的收敛或发散情况。该幂级数的收敛区间是什么？

| $x$ | $\displaystyle \sum_{n=0}^{\infty} a_n (x - b)^n$ |
|-------|---------------------------------------------------|
| $-2$ | 发散 |
| $-1$ | 条件收敛 |
| $0$  | 绝对收敛 |
| $1$  | 绝对收敛 |
| $2$  | 绝对收敛 |
| $3$  | 发散 |

> (A) $(-2, 2]$  
> (B) $(-2, 3)$  
> (C) $[-1, 2]$  
> (D) $[-1, 3)$

**解析**：幂级数的收敛区间关于中心点 $b$ 对称，形式为 $(b-R, b+R)$ 或其端点的闭/半开形式。

**确定中心点 $b$**：

由表格分析：
- $x = -1$ 条件收敛（端点特征）
- $x = 0, 1, 2$ 绝对收敛（内部特征）
- $x = -2, 3$ 发散（外部特征）

若 $b = 1$，收敛半径 $R = 2$：
- 内部：$|x-1| < 2$，即 $-1 < x < 3$
- 左端点：$x = -1$，距离中心 2
- 右端点：$x = 3$，距离中心 2

**验证**：
- $x = 0, 1, 2$：都在 $(-1, 3)$ 内部，绝对收敛 ✓
- $x = -1$：在左端点，条件收敛 ✓
- $x = 3$：在右端点，发散 ✓
- $x = -2$：距离中心 3 > R = 2，发散 ✓

**答案：D**（收敛区间为 $[-1, 3)$，左端点条件收敛包含，右端点发散不包含）

