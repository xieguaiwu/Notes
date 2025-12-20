---
tags:
  - MachineLearning
  - 定义性
title: Language Models
created: 2025-12-20T09:06:00
modified:
---
# Language Models
## 1. n-gram
大规模语料库+统计学方法
一句话的概率等同于其组成单位的概率，使用条件概率而非独立概率：
$$p(s)=p(w_1)\times p(w_2|w_1)\times p(w_3|w_2w_1)\times\ldots$$
$$=\prod_{i=1}^m p(w_i|w_1\ldots w_{i-1})$$
为了保证概率在$i=1$时有意义，需要保证
$$\sum_sp(s)=1$$
其中语句$s$等于
$$s=w_1w_2\ldots w_m$$
对于中文，为了将句子分成这些元素的组合，需要先采用分词技术
![[n-gram word division.png]]

一个n-gram model会考虑前$n-1$个词的历史情况
就像[[Chomsky - Automata]]中的模型那样，字符串$s$有开始符号$\text{<BOS>}$和终止符$\text{<EOS>}$
![[n-gram example.png]]
