---
tags:
  - Languistics
  - 定义性
  - Math
  - Chomsky
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

