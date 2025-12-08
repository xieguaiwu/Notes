---
tags:
  - Math
  - Calculus
  - 定义性
title: L'Hospital's rule
created: 2025-10-27T16:01:00
modified:
---
# L'Hospital's rule
## 1. Indeterminate Form
对于不定式（见[[limit_rational_func]]**2**）有如下洛必达法则：
$$\lim_{x\to a}\frac{f(x)}{g(x)}=\lim_{x\to a}\frac{f'(x)}{g'(x)}$$

## 2. Transform to Indeterminate Form
### 2.1
若是这样的极限
$$\lim_{x\to a}(f(x)-g(x))=\pm(\infty-\infty)$$
那通过同分或同时乘或除以一个共轭式来转换为indeterminate form

例如：
$$\lim_{x\to a}(f(x)-g(x))=\lim_{x\to a}\frac{f^2(x)-g^2(x)}{f(x)+g(x)}$$
此时的再将它视作不定式的形式来进行洛必达法则

### 2.2
$$\lim_{x\to a}f(x)\cdot g(x)=0\times\pm\infty$$
将其中形式更为简单的一个换作分子，转换为不定式即可进行洛必达法则：
$$\lim_{x\to a}f(x)\cdot g(x)=\lim_{x\to a}\frac{g(x)}{\frac{1}{f(x)}}$$

## 3. Power Form
形如
$$\lim_{x\to a}f(x)^{g(x)}$$
取对数后则有
$$\lim_{x\to a}\ln(f(x)^{g(x)})=\lim_{x\to a}g(x)\cdot\ln(f(x))=L$$

则原式解为：
$$\lim_{x\to a}f(x)^{g(x)}=e^L$$
