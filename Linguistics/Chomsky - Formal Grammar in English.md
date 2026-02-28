---
tags:
  - Linguistics
  - Logic
  - 定义性
  - Chomsky
title: Chomsky - Formal Grammar in English
created: 2025-12-08T12:46:00
modified:
---
# Chomsky - Formal Grammar in English
[[Noun and noun phrase]]
[[Verb and verb phrase]]
在乔姆斯基的理论中，英语的语法如下，此处以句子"the boy hit the ball"的生成过程为例：
## 1. Def
$$G=(V_N,V_T,S,P)$$
$$V_N=\{NP,VP,T,N,V\}$$
$$V_T=\{\text{the, boy, hit, the, ball}\}$$
$$S=S$$
$P$的规则如下：
1. $$S\to NP\textasciicircum VP$$
2. $$NP\to T\textasciicircum N$$
其中$T$指定冠词，$N$指名词，$V$指动词
3. $$VP\to V\textasciicircum NP$$
4. $$T\to\text{the}$$
5. $$N\to\text{boy, ball}$$
6. $$V\to\text{hit}$$

## 2. Derivational History
推导史 (derivational history) 展示了从规则到具体语句的生成过程，其中需要特别标明每一步迭代所应用的规则
$$S$$
$$NP\textasciicircum VP (1)$$
$$T\textasciicircum N\textasciicircum VP(2)$$
$$T\textasciicircum N\textasciicircum V\textasciicircum NP(3)$$
$$\text{the}\textasciicircum N\textasciicircum V\textasciicircum NP(4)$$
$$\text{the}\textasciicircum\text{boy}\textasciicircum V\textasciicircum NP(5)$$
$$\text{the}\textasciicircum\text{boy}\textasciicircum\text{hit}\textasciicircum NP(6)$$
$$\text{the}\textasciicircum\text{boy}\textasciicircum\text{hit}\textasciicircum T\textasciicircum N(2)$$
$$\text{the}\textasciicircum\text{boy}\textasciicircum\text{hit}\textasciicircum\text{the}\textasciicircum N(4)$$
$$\text{the}\textasciicircum\text{boy}\textasciicircum\text{hit}\textasciicircum\text{the}\textasciicircum\text{ball}(5)$$

