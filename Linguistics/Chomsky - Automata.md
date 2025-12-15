---
tags:
  - Languistics
  - 定义性
  - Math
  - Chomsky
  - Logic
title: Chomsky - Automata
created: 2025-12-07T21:14:00
modified:
---
# Chomsky - Automata
## 1. General Def
在乔姆斯基的定义中，语言即由sentences或string组成的有限或无限集合$\mathbf{L}$，语言的主要刻画方法是**语法生成法**和**自动机法**
在语言中不包含任何符号的string，即empty string记作$\varepsilon$

语法集合记作$\mathbf{G}$，被它刻画的语言即为$\mathbf{L(G)}$
一个自动机（automata）即语言的识别程序 (recognizer)，记作$\mathbf{R}$

$V$表示vocabulary，它是**构成语言的有限个符号的集合**，由它其中的元素所构成的**所有句子**记作$V^*$，而$V^+$则是**不包含$\varepsilon$的所有句子的集合**
例如，若$V=\{a,b\}$，那么：
$$V^*=\{\varepsilon,a,b,aa,ab,ba,bb,\ldots\}$$
$$V^+=\{a,b,aa,ab,ba,bb,\ldots\}$$

## 2. Def - Grammar
语法被定义为四元组：
$$\mathbf{G}=(V_N,V_T,S,P)$$
其中$V_N$是非终极符号，不能处于生成过程的终点；$V_T$是终极符号，处于生成过程的终点。于是它们的交集则组成了$V$：
$$V=V_N\cup V_T$$
而必须保证
$$V_N\cap V_T=\emptyset$$

## 3. Def - Generation
在$V_N$中，$S$是起始符号，是生成过程的起点，而$P$则是重写规则，其一般形式是：
$$P:\phi\to\psi$$
其中
$$\phi\in V^+,\psi\in V^*$$
$$\Rightarrow\phi\neq\emptyset$$
另一方面，符号$\#$用来表示string的界限，于是可以这样描述迭代的重写过程：
$$\# S\#\to\#\phi_1\#$$
$$\#\phi_1\#\to\#\phi_2\#$$
$$\#\phi_2\#\to\ldots\to\#\phi_n\#$$
此处的$\#\phi_n\#$就是终极string

此处的$\to$并非逻辑学中的蕴含符号，而是重写符号，它有以下几条性质：
1. $\to$并不是自反的 (not reflexive)（见[[Reflexive Relation]]）
2. 不存在任何$\phi,\psi,\omega$（它们都是string）使得$\psi\emptyset\phi\to\psi\omega\phi$
3. 语法$G$必然包含有**能确定所有生成方式的有限个规则的个数的规则$\aleph_j\to\omega_j$**

在生成过程中，假如设定$Q$和$P$是从$S$生成出的句子，其中$P$是英语中的一个that从句，那么就有：
$$S\to Q$$
$$Q\to Q\textasciicircum R$$
其中$\textasciicircum$是毗邻符号，只要利用这两条规则就可以生成无限个that从句

这篇笔记所展示的是乔姆斯基理论的一般方法，特殊的语言会有特殊的语法，例如英语语法就有：[[Chomsky - Formal Grammar in English]]

## 4. Def - Language
下面通过上述规则给出$\mathbf{L(G)}$的定义
若重写规则有
$$P:\alpha\to\beta$$
$$\phi_1\phi_2\in V^*$$
应用重写规则的操作可以写成：
$$\phi_1\alpha\phi_2\Rightarrow_{\mathbf{G}}\phi_1\beta\phi_2$$
其中$\Rightarrow_{\mathbf{G}}$指推导关系
若$V^*=\{\alpha_1,\alpha_2,\ldots,\alpha_m\}$
就可以进一步将这个推导关系推广到整个$\mathbf{L(G)}$
其中，任意两两string间都有$\alpha_x\Rightarrow^*_{\mathbf{G}}\alpha_{x+1}$，由于这个推导关系仅仅针对于$V^*$，所以将之特别地写作$\Rightarrow^*_{\mathbf{G}}$，考虑到这种语法生成的递归性，最终有：
$$\alpha_1\Rightarrow^*_{\mathbf{G}}\alpha_m$$
于是写出语言集合的定义：
$$\mathbf{L(G)}=(W|W\in V^*_T\wedge S\Rightarrow^*_{\mathbf{G}}W)$$
所以说，只要一个string符合两个条件就一定属于$\mathbf{L(G)}$中
- string包括终极符号$P$
- string能从$S$中推导出来

若$$\mathbf{L(G_1)}=\mathbf{L(G_2)}$$
那么可以说$\mathbf{G_1}$等价于$\mathbf{G_2}$