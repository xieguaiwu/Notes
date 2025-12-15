---
tags:
  - Languistics
  - 证明
  - Exercise
title: Rossetta MSK 2003
created: 2025-12-10T09:12:00
modified:
---
# Rossetta MSK 2003
## 1. Problem
Hmong Daw language written in Shong Lue Yang’s script
![[rossetta_MSK_2003.png]]

---
## 2. Phonology
假设这种书写系统的顺序是从左往右$(a_1)$。

### 2.1
设定2和3中，左数第一个字符写作的一般形式写作$\Pi$，设定3的第二个字符写作$\Cup$
从字音处可以看到，被$\Pi$指涉的读音都包括$au$
其中：
$$_\circ\Pi\leftrightarrow auv$$
$$_\circ\ddot{\Pi}\leftrightarrow aug$$
于是首先推测这种语言是abugida systems$(a_2)$（见[[Writing Systems]]**5**）。
考虑到3中
$$_\circ\ddot\Pi\Cup\leftrightarrow raug$$
$$\bar{W^\circ}\Cup\leftrightarrow raws$$
那么
$$\Cup\leftrightarrow r(A_1)$$
假设$\Pi\leftrightarrow au(A_2)$，那么
$$(A_1\wedge A_2)\vdash_\circ\emptyset\leftrightarrow +v(A_3)$$
$$(A_1\wedge A_2)\vdash_\circ\ddot\emptyset\leftrightarrow +g(A_4)$$
设定2的第二个字符写作$\sqcap^\circ$，根据推断可知
$$(A_3)\vdash\sqcap^\circ\leftrightarrow h(A_5)$$

这意味着这种书写系统在每个语素上是从右往左的，但在句子的组成上却是从左往右的$(a_2)$

### 2.2
设定8中最右侧的字符写作$\eta$
$a_1\vdash$注意到$(5)\leftrightarrow hluav$可以直接用已知的一些音节拼成
在4里，设定4的第二个字符写作$\mathbb{4}$
$$^\circ W\mathbb{4}\leftrightarrow hloov$$
根据$A_3$可知：
$$A_3\vdash^\circ W\leftrightarrow oov$$
$$A_3\vdash W\leftrightarrow oo(A_6)$$
那么
$$\mathbb{4}\leftrightarrow hl(A_7)$$
另一方面，在5内
$$\dot{W}E\leftrightarrow qhua$$
根据$a_2$的推测，出现了与$A_6$相悖的情况：
$$a_2\vdash\dot{W}\leftrightarrow ua(A_8)$$
但是考虑到在读音上$oo\approx hu$，在一定程度上支持了$A_6$，那么得出新的推测
$$\dot{\emptyset}\leftrightarrow +a(A_9)$$
结合$A_3$
$$A_3\vdash ^\circ\dot{W}\leftrightarrow uav$$
于是可以解出第5题

### 2.3
现在解决第1题
设定1和6的最后一个字符写作$U$
$$a_2\vdash U\leftrightarrow n(A_{10})$$
另一方面：
$$(A_4\wedge A_6)\vdash ^\circ\ddot{W}\leftrightarrow oog(A_{11})$$
那么解出第1题
$$(A_{10}\wedge A_{11})\vdash ^\circ\ddot{W}U\leftrightarrow noog$$

### 2.4
解决第2题
根据3的最后一个单词和8的第二个单词
$$\forall\leftrightarrow c(A_{12})$$
根据7，设定7的第一个字符写作$\Gamma$
$$\Gamma\leftrightarrow kwv(A_{13})$$
$$(A_{12}\wedge A_{13})\vdash \dot{\Gamma}\forall\leftrightarrow ckwva$$

### 2.5
解决第三题
回到1的最后一个单词，设定1的倒数第二个单词写作$\dot{N}$
$$A_{10}\vdash\dot{N}\leftrightarrow o$$
另一方面，回看第3句最后一词，结合$A_{12}$
$$A_{12}\vdash\dot{N}\leftrightarrow o/ai$$
这或许是因为$\dot{N}$与不同字符结合时会出现的读音变化
结合$A_9$推断出的变形规则，找到这个字符的原型的读音：
$$(A_{12}\wedge A_9)\vdash N\leftrightarrow i(A_{14})$$
结合3，4，6，7中所有$\bar{\emptyset}$形式的字符，做出大胆的推测
$$\bar{\emptyset}\leftrightarrow +s(A_{15})$$
那么自然推算出第3题第一个字符的读音
$$(A_{14}\wedge A_{15})\vdash \bar{N}\leftrightarrow is$$
回到第3句的第一个单词，设定3的第一个字符写作$_\circ\ddot{\sqcap}$。根据先前的推断$A_1$
$$A_1\vdash_\circ\ddot{\sqcap}\leftrightarrow aug(A_{16})$$
结合$A_4$的变形规则：
$$(A_1\wedge A_4)\vdash_\circ\sqcap\leftrightarrow auv(A_{16})$$
（为方便证明而为两个推断设定同样的序号）
回到第2句，现在终于可以开始推算第三题的第二个字符的读音了。设定这个字符写作$\cap^\circ$
$$A_{16}\vdash\cap^\circ\leftrightarrow h$$
设定第3题的倒数第二个字符写作$\bar{\odot}$，它也是第4句的倒数第二个字符。结合$A_{15}$得出其读音：
$$a_2\vdash\bar{\odot}\leftrightarrow us$$
$$(a_2\wedge A_{15})\vdash\odot\leftrightarrow u(A_{17})$$
现在设定第6句的正数第四个字符写作$\bowtie$，考虑到它前方的字符使用了规则$A_{15}$，故一定至少占据两个音节，所以
$$(a_2\wedge A_{15})\vdash\bowtie\leftrightarrow l(A_{18})$$
于是终于可以完成第3题：
$$A_{14-18}\vdash\bar{N}\cap^\circ\text{ }\bar{\odot}\bowtie\leftrightarrow his\text{ }lus$$

### 2.6
现在解决第4题
设定第6中的第一个和第三个字符分别写作$\ddot{\Re}$和$\bar{\Re}$，于是结合两个变形规则$A_4$和$A_{15}$就可以快速推断出：
$$(a_2\wedge A_4\wedge A_{15})\vdash\Re\leftrightarrow o(A_{19})$$
根据第5句和$A_8$，推断出第5句的第二个字符$E$的发音
$$A_8\vdash E\leftrightarrow qh(A_{20})$$
对于第4题的第三个字符$\ddot{W}$，或许无法直接应用规则$A_4$。回到第1句的第二个字母$\bar{W}$，考虑到变形规则$A_{15}$，可以给出以下可能性：
$$A_{15}\vdash W\leftrightarrow ua/sua/tsua$$
考虑$A_6$已经做出过的推断，可以认为
$$(A_6\wedge A_{15})W\leftrightarrow oo/ua$$
那么
$$(A_6\wedge A_4\wedge A_{15})\vdash\ddot{W}\leftrightarrow uag(A_{21})$$
现在设定问题4第四个字符写作$\Game$，它只在第4句末尾出现过一次。根据$A_{17}$可知
$$A_{17}\vdash\Game\leftrightarrow m(A_{22})$$
最后，根据变形规则$A_{15}$，设定第四题最后一个字符写作$\Delta$，那么它在第8句开头就写作$\bar{\Delta}$，现在得出它的读音：
$$A_{15}\vdash\Delta\leftrightarrow i(A_{23})$$
现在完成第四题
$$(A_{19-23})\vdash\Re E\text{ }\ddot{W}\Game\text{ }\Delta \leftrightarrow qho\text{ }muag\text{ }i$$

### 2.7
现在解决第六题
根据$A_{18}$可知
$$\bowtie\leftrightarrow l$$
根据$A_{23}$则可推出答案的第二个字符，根据$A_{12}$可以推出答案的第三个字符
对于答案的下一个字符，回到第6句，见$A_{10}$的推论，设定第6句倒数第二个字符写为$\ddot{\Theta}^\circ$，由于第6句的最后一个单词只包含这两个字符，且对应了三个音节，那么
$$(a_2\wedge A_{10})\vdash\Theta\leftrightarrow a(A_{24})$$
于是最终解决了问题：
$$(a_2\wedge A_{10}\wedge A_{12}\wedge A_{18}\wedge A_{23-24})\vdash \Delta\bowtie\text{ }\bar{\Theta}\forall\leftrightarrow li\text{ }cas$$

### 2.8
开始解决第七题
首先根据$A_{10}$得出第一个字符：
$$U\leftrightarrow n(A_{10})$$
设定第7题倒数第二个字符写作$\bar{\aleph}$，根据$A_{15}$就可以推断
$$(a_2\wedge A_{15})\vdash\aleph\leftrightarrow e(A_{25})$$
根据$A_{21}$以及第1句第二个单词可以推测出
$$A_{21}\vdash K\leftrightarrow nt(A_{26})$$
另一方面，根据第8句第二个单词和$A_{12}$推断
$$A_{12}\vdash\ddot{H}_\circ\leftrightarrow eg$$
考虑到$A_4$
$$(A_{12}\wedge A_4)\vdash H_\circ\leftrightarrow e$$

### 2.9
现在解决最后一题
根据$A_{25}$可以证明
$$A_{25}\vdash W^\circ\leftrightarrow y(A_{27})$$
根据$A_{24}$可以找到$\Theta\leftrightarrow a$
设定第3句第三个字符写作$\bar{\Phi}$，考虑规则$A_{15}$，那么：
$$(a_2\wedge A_{15})\vdash\Phi\leftrightarrow aw(A_{28})$$
最终完成这道题
$$(a_2\wedge A_{27-28})\vdash\ddot{\Phi}W^\circ\leftrightarrow yawg$$

---

## 3. Answer
1. $$^\circ\ddot{W}U\leftrightarrow noog$$
2. $$\dot{\Gamma}\forall\leftrightarrow ckwva$$
3. $$\bar{N}\cap^\circ\text{ }\bar{\odot}\bowtie\leftrightarrow his\text{ }lus$$
4. $$\Re E\text{ }\ddot{W}\Game\text{ }\Delta \leftrightarrow qho\text{ }muag\text{ }i$$
5. $$^\circ\dot{W}\mathbb{4}\leftrightarrow hluav$$
6. $$\Delta\bowtie\text{ }\bar{\Theta}\forall\leftrightarrow li\text{ }cas$$
7. $$\ddot{\aleph}U\text{ } H_\circ\bar{K}\leftrightarrow neeg\text{ }ntse$$
8. $$\ddot{\Phi}W^\circ\leftrightarrow yawg$$

---

## 4. Standard Solution
![[rossetta_MSK_2003_solution.png]]
![[rossetta_MSK_2003_solution2.png]]
