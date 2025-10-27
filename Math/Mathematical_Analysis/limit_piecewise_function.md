#Calculus #Math #证明 
[[limit]]
对于任意分段函数
$$f(x)=\left\{
\begin{array}{rcl}
f_1(x)&&{x>a}\\
f_2(x)&&{x\leqslant a}
\end{array} \right. $$
如果它在$x=a$上的左右极限相同，即其处处连续（见[[continuity]]&[[Differentiability and Continuity]]）
$$\lim_{x\to a^+}f_1(x)=\lim_{x\to a^-}f_2(x)=f(a)=L$$
那么，定义导数$f_1(c)$：
$$f_1(c)=\frac{f(a+h)-f(a)}{h}$$
其中$c\in[a,a+h]$
那么，根据夹逼定理（[[squeeze_theorem]]），当$h\to 0^+$时，$c\to a^+$
$$\lim_{h\to 0^+}\frac{f(a+h)-f(a)}{h}=\lim_{h\to 0^+}f_1'(c)=\lim_{c\to a^+}f_1'(c)=L$$
同理，对于$f_2(c)$：
$$\lim_{h\to 0^-}\frac{f(a+h)-f(a)}{h}=\lim_{h\to 0^-}f_1'(c)=\lim_{c\to a^-}f_2'(c)=L$$
那么就可以证明，左右极限都等于$L$，
$$f'(a)=L$$