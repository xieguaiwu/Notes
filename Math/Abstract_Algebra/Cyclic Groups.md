---
title: Cyclic Groups
tags:
  - Math
  - AbstractAlgebra
  - 定义性
  - 定理性
created: 2026-06-25
---

# Cyclic Groups

## 定义

一个群 $G$ 称为**循环群**，如果存在一个元素 $g \in G$ 使得 $G = \langle g \rangle = \{ g^n \mid n \in \mathbb{Z} \}$。此时 $g$ 称为 $G$ 的一个**生成元**。

> 循环群是群论中最简单的非平凡结构——所有元素都是某个固定元素的幂，整个群被一个元素完全控制。

## 完全分类

这是群论中最漂亮的定理之一：**所有循环群在同构意义下只有两种**。

| 类型 | 同构于 | 例子 |
|------|--------|------|
| 无限循环群 | $(\mathbb{Z}, +)$ | $\langle 2 \rangle \subset \mathbb{Q}^\times$（$2$ 生成的乘法群） |
| $n$ 阶有限循环群 | $(\mathbb{Z}/n\mathbb{Z}, +)$ | $\mathbb{Z}/12\mathbb{Z}$，模 12 的剩余类加群 |

**定理（循环群的结构定理）：** 设 $G = \langle g \rangle$ 是循环群。
- 若 $|g| = \infty$，则 $G \cong \mathbb{Z}$，同构映射 $g^n \leftrightarrow n$。
- 若 $|g| = n < \infty$，则 $G \cong \mathbb{Z}/n\mathbb{Z}$，同构映射 $g^k \leftrightarrow k \pmod{n}$。

换句话说，同构意义下只有整数加群和模 $n$ 整数加群。这是群论中第一个"完全分类"的例子。

## 生成元

### $\mathbb{Z}$ 的生成元
$\mathbb{Z}$ 只有两个生成元：$1$ 和 $-1$（即 $1$ 的加法逆元）。

### $\mathbb{Z}/n\mathbb{Z}$ 的生成元

设 $g$ 是 $\mathbb{Z}/n\mathbb{Z}$ 的一个生成元（例如 $g = 1$）。则 $g^m$ 是生成元当且仅当 $\gcd(m, n) = 1$。

因此 $\mathbb{Z}/n\mathbb{Z}$ 有 $\varphi(n)$ 个生成元，其中 $\varphi$ 是欧拉函数。

**例子：** $\mathbb{Z}/12\mathbb{Z}$ 的生成元有 $\varphi(12) = 4$ 个：$1, 5, 7, 11$。
验证：$1\cdot5 = 5$, $5\cdot5 = 25 \equiv 1$, $7\cdot7 = 49 \equiv 1$, $11\cdot11 = 121 \equiv 1$（乘法口诀：$5^2=25\equiv1$, $7^2=49\equiv1$, $11^2=121\equiv1$ 说明它们都与 12 互质）。

## 子群结构

另一个优美结论：**循环群的子群仍为循环群**，且子群与阶数的因子一一对应。

### $\mathbb{Z}$ 的子群
$\mathbb{Z}$ 的所有子群形如 $n\mathbb{Z} = \{ nk \mid k \in \mathbb{Z} \}$（$n \geq 0$）。子群格同构于自然数按整除关系构成的偏序集。

### $\mathbb{Z}/n\mathbb{Z}$ 的子群
对 $n$ 的每个正因子 $d$，$\mathbb{Z}/n\mathbb{Z}$ 恰有一个 $d$ 阶子群：$\langle g^{n/d} \rangle = \{ 0, g^{n/d}, g^{2n/d}, \dots, g^{(d-1)n/d} \}$。

| $n=12$ 的因子 $d$ | $d$ 阶子群 | 生成元 |
|-------------------|------------|--------|
| 1 | $\{0\}$ | $0$ |
| 2 | $\{0, 6\}$ | $6$ |
| 3 | $\{0, 4, 8\}$ | $4$ |
| 4 | $\{0, 3, 6, 9\}$ | $3$ |
| 6 | $\{0, 2, 4, 6, 8, 10\}$ | $2$ |
| 12 | $\mathbb{Z}/12\mathbb{Z}$ | $1$ |

子群格同构于 $n$ 的因子格（按整除关系）。

## 例子

1. **$\mathbb{Z}$：** 唯一的无限循环群（加法）。
2. **$\mathbb{Z}/n\mathbb{Z}$：** 模 $n$ 剩余类加群，$n$ 阶循环群的标准模型。
3. **单位根群 $U(n)$：** $U(n) = \{ e^{2\pi i k/n} \mid k = 0, 1, \dots, n-1 \}$ 在复数乘法下构成 $n$ 阶循环群，生成元为 $e^{2\pi i / n}$。
4. **素数模乘法群：** 当 $p$ 为素数时，$(\mathbb{Z}/p\mathbb{Z})^\times$ 是循环群（定理），同构于 $\mathbb{Z}/(p-1)\mathbb{Z}$。例如 $(\mathbb{Z}/7\mathbb{Z})^\times = \{1,2,3,4,5,6\}$ 以 $3$ 为生成元：$3^1=3, 3^2=2, 3^3=6, 3^4=4, 3^5=5, 3^6=1$。

## 直积

**定理（中国剩余定理的群论版本）：**
$$\mathbb{Z}/m\mathbb{Z} \times \mathbb{Z}/n\mathbb{Z} \cong \mathbb{Z}/mn\mathbb{Z} \quad \iff \quad \gcd(m, n) = 1$$

**例子：**
- $\mathbb{Z}/3\mathbb{Z} \times \mathbb{Z}/4\mathbb{Z} \cong \mathbb{Z}/12\mathbb{Z}$（因为 $\gcd(3,4)=1$）
- $\mathbb{Z}/2\mathbb{Z} \times \mathbb{Z}/2\mathbb{Z} \not\cong \mathbb{Z}/4\mathbb{Z}$（因为 $\gcd(2,2)=2\neq 1$；前者 Klein 四元群，不是循环群）

## 自同构群

$$\operatorname{Aut}(\mathbb{Z}/n\mathbb{Z}) \cong (\mathbb{Z}/n\mathbb{Z})^\times$$

即 $\mathbb{Z}/n\mathbb{Z}$ 的自同构群同构于模 $n$ 的单位群（模 $n$ 的乘法群）。

- $|\operatorname{Aut}(\mathbb{Z}/n\mathbb{Z})| = \varphi(n)$
- $\operatorname{Aut}(\mathbb{Z}) \cong \mathbb{Z}/2\mathbb{Z}$（仅有的两个自同构：$n \mapsto n$ 和 $n \mapsto -n$）

**例子：** $\operatorname{Aut}(\mathbb{Z}/12\mathbb{Z}) \cong (\mathbb{Z}/12\mathbb{Z})^\times = \{1,5,7,11\}$，是 Klein 四元群（每个非恒等元阶为 2）。

## 核心连接

- [[Group]] — 循环群是群的一个基本例子，也是"自由群"在 1 个生成元下的退化情况
- [[Group Homomorphisms]] — 典范同态 $\mathbb{Z} \to \mathbb{Z}/n\mathbb{Z}$（$k \mapsto k \bmod n$）是同态基本定理的标准应用
- [[Cosets and Lagrange's Theorem]] — 循环群中元素的阶整除群的阶（Lagrange 定理的逆向在循环群中成立）
- [[Field]] — 有限域 $\mathbb{Z}/p\mathbb{Z}$ 的加法群是 $p$ 阶循环群，乘法群是 $p-1$ 阶循环群
