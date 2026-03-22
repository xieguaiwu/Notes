---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: series_problem_03.22
created: 2026-03-22T13:05:00
modified:
---
# series_problem_03.22
>确定级数是绝对收敛、条件收敛还是发散：$$\sum^\infty_{n=1}\frac{(-1)^n}{e^n\cdot f(n)}=\sum^\infty_{n=1}\frac{(-1)^n(n^2+9)}{e^n}$$

## 解答

### 第一步：判断绝对收敛性

考察原级数的绝对值级数：
$$\sum^\infty_{n=1}\left|\frac{(-1)^n(n^2+9)}{e^n}\right|=\sum^\infty_{n=1}\frac{n^2+9}{e^n}$$

使用**比值判别法**：

设 $a_n = \frac{n^2+9}{e^n}$，则：

$$\frac{a_{n+1}}{a_n}=\frac{(n+1)^2+9}{e^{n+1}}\cdot\frac{e^n}{n^2+9}=\frac{(n+1)^2+9}{e(n^2+9)}$$

计算极限：
$$\begin{aligned}
\lim_{n\to\infty}\frac{a_{n+1}}{a_n}&=\lim_{n\to\infty}\frac{(n+1)^2+9}{e(n^2+9)}\\
&=\lim_{n\to\infty}\frac{n^2+2n+10}{e(n^2+9)}\\
&=\frac{1}{e}\lim_{n\to\infty}\frac{n^2+2n+10}{n^2+9}\\
&=\frac{1}{e}\lim_{n\to\infty}\frac{1+\frac{2}{n}+\frac{10}{n^2}}{1+\frac{9}{n^2}}\\
&=\frac{1}{e}\cdot\frac{1+0+0}{1+0}\\
&=\frac{1}{e}
\end{aligned}$$

由于 $e\approx 2.718 > 1$，所以 $\frac{1}{e} < 1$。

根据比值判别法，当 $\lim_{n\to\infty}\frac{a_{n+1}}{a_n} < 1$ 时，级数收敛。

因此，$\sum^\infty_{n=1}\frac{n^2+9}{e^n}$ **收敛**。

### 第二步：结论

- 原级数的绝对值级数收敛
- 故原级数 $\sum^\infty_{n=1}\frac{(-1)^n(n^2+9)}{e^n}$ **绝对收敛**

> **注**：绝对收敛蕴含收敛，所以原级数必收敛。无需再使用莱布尼茨判别法判断条件收敛性。


