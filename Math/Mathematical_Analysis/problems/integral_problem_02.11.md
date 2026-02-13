---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: integral_problem_02.11
created: 2026-02-11T17:37:00
modified:
---
# integral_problem_02.11
[[Indefinite Integration]]
>$$\int\ln (\frac{k+1}{k})dk$$
使用**分部积分法**，设：

$$
\begin{align}
u &= \ln\left(\frac{k+1}{k}\right) \\
dv &= dk\text{  (IMPORTANT)}
\end{align}
$$

首先计算 $u$ 的导数：

$$
\begin{align}
\frac{d}{dk}\left[\ln\left(\frac{k+1}{k}\right)\right] &= \frac{d}{dk}[\ln(k+1) - \ln k] \\
&= \frac{1}{k+1} - \frac{1}{k} \\
&= \frac{-1}{k(k+1)}
\end{align}
$$

应用分部积分公式 $\int u \, dv = uv - \int v \, du$：

$$
\begin{align}
\int \ln\left(\frac{k+1}{k}\right) dk &= k \ln\left(\frac{k+1}{k}\right) - \int k \cdot \frac{-1}{k(k+1)} dk \\
&= k \ln\left(\frac{k+1}{k}\right) + \int \frac{1}{k+1} dk \\
&= k \ln\left(\frac{k+1}{k}\right) + \ln|k+1| + C
\end{align}
$$

## 最终答案

**形式一：**

$$
\boxed{\int \ln\left(\frac{k+1}{k}\right) dk = k \ln\left(\frac{k+1}{k}\right) + \ln(k+1) + C}
$$

**形式二（更简洁）：**

$$
\boxed{\int \ln\left(\frac{k+1}{k}\right) dk = (k+1)\ln(k+1) - k \ln k + C}
$$


