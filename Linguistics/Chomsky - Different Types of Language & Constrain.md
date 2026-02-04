---
tags:
  - Languistics
  - Chomsky
  - Logic
  - 定义性
title: Different Types of Language & Constrain
created: 2025-12-08T13:29:00
modified:
---
# Chomsky - Different Types of Language & Constrain
## 1. 几种限制
- 限制1（type 1 grammar/context-sensitive grammar）：如果$\phi\to\psi$，那么$\exists A, \phi_1,\phi_2,\omega$，以令$$\phi=\phi_1 A\phi_2,\phi_1\omega\phi_2$$
- 限制2（type 2 grammar/context-free grammar）：在限制1的基础上：$$A\to\omega$$
- 限制3（type 3 grammar/regular grammar）：在限制2的基础上，有$\omega =aQ$或者$\omega =a$，因此$$A\to aQ$$或着$$A\to a$$
限制1（finite-state automaton，即有限自动机）：能够生成所有递归可枚举语言（见[[Chomsky - Automata]]）。更宽松的约束（限制1）可以处理一些跨序列依赖关系，如某些自然语言中的**长距离依赖现象**。若用$|\psi|$和$|\phi|$分别表示两个string的长度，则必然有
$$|\psi|\geq |\phi|$$
限制2：是大多数编程语言语法的基础，也是自然语言句法结构的重要模型，可以处理句子的句法结构
限制3：对应正则语言，是词法分析器和模式匹配的基础，可以处理词法规则，如单词构成

若没有这三种限制，则是type 0 grammar