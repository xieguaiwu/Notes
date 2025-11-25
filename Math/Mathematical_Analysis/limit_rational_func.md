---
attachments:
  - limit_rational_func.png
tags:
title: limit_rational_func
created: 2025-09-20
modified: 2025-09-20
---


# limit of rational function

## 1. Def
$$\\lim_{ x \to a } \frac{p(x)}{q(x)}$$ 

---

## 2. Two Kinds
### 1
$$\lim_{ x \to a } p(x)=0 \wedge q(x)=0$$
This is **indeterminate form**, where both $p(x)$ and $q(x)$ are not determinated.

### 2
$$\lim_{ x \to a } p(x)\neq 0 \wedge q(x)=0$$
This leads to these situations
![[limit_rational_func.png]]
#### 2.1
Take the function below as an example:
$$\lim_{ x \to 1 } \frac{2x^2-x-6}{x(x-1)^3} $$
On the  left side of $1$, the function is positive, whereas on the right side, the function is negative. Therefore, in this case there's a **difference in left and right limits**.
由于左右极限不相等，故极限并不存在

## 3. Limit with Absolute Value
Consider this:
>$$\lim_{x\to 0}\frac{|x|}{x}$$

我们会意识到其**左极限与右极限不同一**：
$$\lim_{x\to 0^+}\frac{|x|}{x}=\lim_{x\to 0^+}\frac{x}{x}=1$$
但是
$$\lim_{x\to 0^-}\frac{|x|}{x}=\lim_{x\to 0^-}\frac{-x}{x}=-1$$
因此：
$$\nexists\lim_{x\to 0}\frac{|x|}{x}$$
![[frac{abs(x)}{x}.png]]

