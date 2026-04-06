---
tags:
  - Exercise
  - Math
  - Calculus
  - 证明
title: series_problem_04.06
created: 2026-04-06T15:11:00
modified:
---
# series_problem_04.06
## 1 快速判断类似于调和级数的级数的收敛性
对于以下级数：$$\sum_{n=1}^\infty \frac{1}{n+1}$$
$$\sum_{n=1}^\infty \frac{1}{n+2}\ldots$$

可以意识到，它们都属于**调和级数的变形** ([[Infinite Series]])

由于**改变级数的有限项，不会改变级数的敛散性**，所以可以把它们写成调和级数的平移：$$\sum_{n=1}^\infty \frac{1}{n}=1+\frac{1}{2}+\frac{1}{3}\ldots$$
$$\sum_{n=1}^\infty \frac{1}{n+1}=\frac{1}{2}+\frac{1}{3}\ldots$$

这对于其他类似的级数也都是同理

由于调和级数 $\sum_{n=1}^\infty \frac{1}{n}$ 是发散的，因此上述级数也都是**发散**的。

## 2 判断收敛半径
>$$\sum_{n=1}^\infty \frac{(x+4)^n}{n\cdot 5^{n+1}}$$

这是一个形如 $\sum_{n=1}^\infty a_n(x-x_0)^n$ 的幂级数，其中 $x_0=-4$，$a_n=\frac{1}{n\cdot 5^{n+1}}$。
$$\left|\frac{a_{n+1}}{a_n}\right|=\left|\frac{\frac{1}{(n+1)\cdot 5^{n+2}}}{\frac{1}{n\cdot 5^{n+1}}}\right|=\frac{n\cdot 5^{n+1}}{(n+1)\cdot 5^{n+2}}=\frac{n}{5(n+1)}$$

当 $n\to\infty$ 时：
$$\lim_{n\to\infty}\left|\frac{a_{n+1}}{a_n}\right|=\frac{1}{5}$$

因此收敛半径 $R=\frac{1}{1/5}=5$。

### 收敛区间

收敛区间为：
$$(-4-R,-4+R)=(-4-5,-4+5)=(-9,1)$$

### 端点收敛性判断

**当 $x=1$ 时：**
$$\sum_{n=1}^\infty \frac{(1+4)^n}{n\cdot 5^{n+1}}=\sum_{n=1}^\infty \frac{5^n}{n\cdot 5^{n+1}}=\frac{1}{5}\sum_{n=1}^\infty \frac{1}{n}$$

这是调和级数，**发散**。

**当 $x=-9$ 时：**
$$\sum_{n=1}^\infty \frac{(-9+4)^n}{n\cdot 5^{n+1}}=\sum_{n=1}^\infty \frac{(-5)^n}{n\cdot 5^{n+1}}=\frac{1}{5}\sum_{n=1}^\infty \frac{(-1)^n}{n}$$

这是交错级数，由**莱布尼茨判别法**：
- $u_n=\frac{1}{n}$ 单调递减
- $\lim_{n\to\infty}\frac{1}{n}=0$

故该级数**收敛**。

## 3 判断条件收敛

>下列哪些级数是条件收敛的？
>
>I. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{n!}$
>
>II. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{\sqrt{n}}$
>
>III. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{n + 2}$
>

### 逐项分析

**I. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{n!}$**

使用比值判别法判断绝对收敛性：
$$\lim_{n\to\infty} \left| \frac{a_{n+1}}{a_n} \right| = \lim_{n\to\infty} \frac{1/(n+1)!}{1/n!} = \lim_{n\to\infty} \frac{1}{n+1} = 0 < 1$$

因此 $\sum \frac{1}{n!}$ **绝对收敛**。

⇒ 不是条件收敛。❌

**II. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{\sqrt{n}}$**

这是交错 $p$-级数。由**莱布尼茨判别法**：
- $b_n = \frac{1}{\sqrt{n}} > 0$
- 单调递减
- $\lim_{n\to\infty} b_n = 0$

⇒ 级数**收敛**。

但 $\sum \frac{1}{\sqrt{n}} = \sum n^{-1/2}$ 是 $p$-级数，$p=\frac{1}{2}<1$，**发散**。

⇒ **条件收敛**。✅

**III. $\displaystyle \sum_{n=1}^{\infty} \frac{(-1)^n}{n + 2}$**

由**莱布尼茨判别法**，令 $b_n = \frac{1}{n+2}$：
- $b_n > 0$，单调递减
- $\lim_{n\to\infty} b_n = 0$

⇒ 级数**收敛**。

但 $\sum \frac{1}{n+2}$ 是调和级数去掉前两项，仍**发散**。

⇒ **条件收敛**。✅

### 结论

- I：绝对收敛 → ❌ 不是条件收敛
- II：条件收敛 → ✅
- III：条件收敛 → ✅

## 4 Maclaurin 级数复合函数求系数

>函数 $f$ 的 Maclaurin 级数为 $2 + 3x + x^2 + \frac{1}{3}x^3 + \cdots$，且该级数对所有实数 $x$ 收敛于 $f(x)$。若 $g(x) = e^{f(x)}$，求 $g$ 的 Maclaurin 级数中 $x^2$ 项的系数。

### 从 Maclaurin 级数读取导数值

由 $f(x) = 2 + 3x + x^2 + \frac{1}{3}x^3 + \cdots$ 可知：
- $f(0) = 2$（常数项）
- $f'(0) = 3$（$x$ 的系数）
- $f''(0) = 2! \cdot 1 = 2$（$x^2$ 的系数 $\times 2!$）

### 用链式法则求 $g(x) = e^{f(x)}$ 的导数

$$g'(x) = f'(x) \cdot e^{f(x)}$$

$$g''(x) = f''(x) \cdot e^{f(x)} + f'(x) \cdot f'(x) \cdot e^{f(x)} = \left[f''(x) + (f'(x))^2\right] e^{f(x)}$$

### 代入 $x=0$ 计算

$$g''(0) = \left[f''(0) + (f'(0))^2\right] e^{f(0)} = (2 + 3^2) \cdot e^2 = 11e^2$$

### 求 $x^2$ 的系数

$$[x^2]\,g(x) = \frac{g''(0)}{2!} = \frac{11e^2}{2}$$


