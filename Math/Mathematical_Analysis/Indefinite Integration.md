---
tags:
  - Math
  - Calculus
  - 定义性
  - 证明
title: Indefinite Integration
created: 2025-11-20T12:51:00
modified:
---
# Indefinite Integration

## 1. Antiderivatives
反导数即导数的逆运算，它正是不定积分：
$$\frac{d}{dx}F(x)=f(x)\Leftrightarrow\int f(x)=F(x)+C$$
其中$C$是常数，因为常数在被求导后会直接消除。正因如此，不定积分形如下图：
![[antiderivatives_intuition.png]]
同时，考虑到不定积分的定义和[[Higher Order Derivative]]的高阶导数知识点，可以意识到：
$$f'(x)=\int f''(x)dx+C$$

## 2. Rules of Antiderivatives
根据[[differentiation]]的**3.2**中的诸多导数规则，可以给出如下不定积分规则：
$$\int 0dx=C$$
$$\int kf(x) dx = k\cdot\int f(x) dx$$
$$\int[f(x)\pm g(x)]dx=\int f(x)dx\pm\int g(x)dx$$
下方的这条规则或许是最常用的：
$$\int x^ndx=\frac{x^{n+1}}{n+1}+C(n\neq 1)$$
下面则是三角函数的积分运算规则
$$\int\cos x\text{ }dx=\sin x +C$$
$$\int\sin x\text{ }dx=-\cos x +C$$
$$\int\sec^2 x\text{ }dx=\tan x +C$$
$$\int\sec x\tan x\text{ }dx=\sec x+C$$
$$\int\csc x\cot x\text{ }dx=-\csc x +C$$

## 3. Sum
求和运算的一般形式如下
$$\sum_{i=1}^na_i=a_1+a_2+\ldots+a_n$$
其中$i$是一个虚拟变量，即求和指数 (index of summation)。
联系到[[Boundedness]]，可知这个数列是有界的，且**其upper bound是$n$，其lower bound则是$1$**

求和运算有以下性质：
$$\sum_{i=1}^nka_i=k\cdot\sum_{i=1}^na_i$$
$$\sum_{i=1}^n(a_i\pm b_i)=\sum_{i=1}^na_i\pm\sum_{i=1}^nb_i$$

## 4. Sum techniques

### 4.1 Gaussian Summation
对于
$$\sum_{j=1}^{100}j$$
即计算从一加到一百的和，可以将它等同地写成另一种形式
$$\sum_{j=1}^{100}(101-j)$$
这样就是从一百加到一的和

令
$$S=\sum_{j=1}^{100}j=\sum_{j=1}^{100}(101-j)$$
那么可以意识到
$$2S=\sum_{j=1}^{100}j+\sum_{j=1}^{100}(101-j)$$
根据先前的求和运算性质，直接合并两段求和：
$$2S=\sum_{j=1}^{100}(j+101-j)$$
$$2S=101\times 100$$
$$\Rightarrow S=5050$$

### 4.2 Scaling Summation Method
对于形式如下的求和：
$$\sum_{j=a}^b(f(j)-f(j-1))=f(b)-f(a-1)$$
这是因为除$f(b)$和$f(a-1)$之外的项全部会被消除

### 4.3 Common Summations
$$\sum_{i=1}^nC=n\cdot C$$
$$\sum_{i=1}^n i=\frac{n(n+1)}{2}$$
$$\sum_{i=1}^n i^2=\frac{n(n+1)(2n+1)}{6}$$
$$\sum_{i=1}^n i^3=\frac{n^2(n+1)^2}{4}$$

## 5. Summation and Area

