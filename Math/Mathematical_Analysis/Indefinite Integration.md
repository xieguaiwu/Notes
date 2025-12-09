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
$$\sum_{i=1}^n(2i-1)=n^2$$
$$\sum_{i=1}^n i^2=\frac{n(n+1)(2n+1)}{6}$$
$$\sum_{i=1}^n(3i^2-3i+1)=n^3$$
$$\sum_{i=1}^n i^3=\frac{n^2(n+1)^2}{4}$$

## 5. Summation and Area
### 5.1
对于求和与面积，引入下方的运动学例子
![[summation_and_area.png]]
可以看出在任何一个时间段$x$内的位移量可以用下方公式表示：
$$\Delta x=v_x(t_x-t_{x-1})$$
那么这段运动的总位移就可以用求和的形式写作：
$$\sum_{i=1}^nv_i(t_i-t_{i-1})$$
这对于方向不一的运动同样可行

### 5.2
若要求得连续函数（关于连续性的定义，见[[continuity]]）所成的面积： 
![[area_of_continuous_func.png]]
由于此时的因变量有连续的变化，而又希望延续先前的思路去衡量所成面积，所以构造出区间$[p,q]$，另其成矩形，设定其高为$v(c)$，其中$c\in[p,q]$
![[measure_integration_1.png]]
则可以单独地求出这个区间的面积，其为$(p-q)\times v(c)$
将这种方法应用于函数的定义域，那么如下图：
![[measure_integration_2.png]]
于是对于每个小区间$[t_{x-1},t_x]$，都会有一个拟订的常数$v(c_x)$，而$c_x\in [t_{x-1},t_x]$
那么此时，面积约等于这一系列矩形面积之和
$$\Delta x=\sum_{i=1}^n(v(c_i)\times (t_x-t_{x-1}))$$
在选取$v(c_i)$时，可能会有两种估计：
![[lower_and_upper_sum.png]]
其中
$$f(m_i)=f(x)_\min(x\in [t_{x-1},t_x])$$
$$f(M_i)=f(x)_\max(x\in [t_{x-1},t_x])$$
因此，选取不同的$c_i$就会估计出不同的面积：
$$\text{Lower Sum}=\sum_{i=1}^n(m_i\times (t_x-t_{x-1}))$$
$$\text{Upper Sum}=\sum_{i=1}^n(M_i\times (t_x-t_{x-1}))$$
于是会形成两种估计：
![[lower_and_upper_sum2.png]]
$$\text{Lower Sum}\leq\text{Real Area}\leq\text{Upper Sum}$$