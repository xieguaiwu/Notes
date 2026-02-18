---
tags:
  - Linguistics
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

---

## 5. Phonetical Knowledge

### 一、声调系统

#### 1. 苗语的声调系统

根据题目和解答，苗语（Hmong Daw）有**四个声调**：

| 拉丁转写标记 | 声调符号 | 描述 |
|-------------|---------|------|
| **v** | ◌́（锐音符/acute）| 高升调 |
| **g** | ◌̈（分音符/diaeresis）| 中降调 |
| **s** | ◌̄（长音符/macron）| 低平调 |
| **∅（无标记）** | 无符号 | 平调 |

**关键发现**：
- 题目解答指出："无符号"在Shong Lue Yang文字中对应的是**v调**，而非真正的"无调"
- 这说明声调标记系统中存在**默认值**：当视觉上没有声调符号时，实际对应特定的声调

---

### 二、音节结构

#### 1. 音节的组成

音节通常分解为以下部分：

```
音节结构模型：
    ┌── 音节 (Syllable) ──┐
    │                     │
  首音 (Onset)     ┌─ 韵母 (Rhyme) ─┐
    │              │                 │
              核心 (Nucleus)    尾音 (Coda)
    │              │                 │
                元音              辅音
```

#### 2. 卢维语的音节结构

题目给出的规则：
- **位置1**：元音/元音丛（音节核，nucleus）
- **位置2**：辅音（音节首，onset）
- **位置3**：声调（可选）

**结构公式**：¹² 或 ¹²³

**重要特点**：书写顺序为**元音在前、辅音在后**，这是一种特殊的书写逻辑，不同于通常的"辅音+元音"口语顺序。

#### 3. 音节核 (Nucleus)

**音节核**是音节的必需要素，通常由**元音**或**元音丛**承担：

| 元音类型 | 卢维语例子 |
|---------|-----------|
| 单元音 | a, e, i, o, u, w |
| 元音丛 | ai, au, aw, ee, oo, ua |

**w 作为元音**：题目明确指出"w 代表特定的元音"，这在语言学上称为**半元音的元音用法**。

---

### 三、辅音系统

#### 1. 辅音的音系学特征

辅音由以下参数定义：

| 参数 | 说明 | 例子 |
|-----|------|-----|
| **发音部位** | 气流受阻碍的位置 | 双唇、齿龈、软腭等 |
| **发音方法** | 阻碍的方式 | 塞音、擦音、鼻音等 |
| **清浊** | 声带是否振动 | 清音 vs 浊音 |
| **送气** | 是否伴随气流 | 送气音 vs 不送气音 |

#### 2. 卢维语中的特殊辅音

题目列出了一些**复杂辅音**：

| 辅音 | 特点 |
|-----|------|
| **hl** | 清化边音，带喉音特征 |
| **nts** | 复辅音：鼻音+塞擦音组合 |
| **qh** | 送气小舌塞音 |

这些辅音体现了：
- **复辅音（Complex Consonant）**：多个辅音组合作为单个音位
- **送气特征**：作为区别性特征

---

### 四、元音系统

#### 1. 元音的分类

元音通常按以下维度分类：

```
          前元音    央元音    后元音
高元音      i                  u
中高元音    e                  o
中低元音                      ɔ
低元音               a
```

#### 2. 元音丛 (Vowel Cluster)

**元音丛**是两个或多个元音的组合，构成单个音节核：

| 类型 | 例子 | 分析 |
|-----|------|-----|
| 二合元音 | ai, au, aw | 两个元音滑动过渡 |
| 长元音 | ee, oo | 同一元音延长 |

**aw 的特殊性**：在苗语中，`aw` 被视为元音丛而非辅音结尾的音节，体现了语言的特定分析。

---

### 五、特征理论

#### 1. 特征的概念

**区别性特征（Distinctive Features）** 是音系学的基本单位，用于描述和区分音素。每个音素都可以分解为一组特征的集合。

#### 2. 本题中的特征应用

两道题都体现了**特征分解**的思想：

**苗语 Shong Lue Yang 文字**：
- 符号的**形状特征**对应语音的**音系特征**
- 这是一种**特征文字系统（Featural Script）**

**卢维语规则表**：
```
音节 = [±元音特征] + [±辅音特征] + [±声调特征]
```

#### 3. 主要特征类型

| 特征类别 | 具体特征 | 例子 |
|---------|---------|------|
| **调音部位** | [±唇]、[±舌冠]、[±软腭] | p/b（唇音）、t/d（舌冠音） |
| **调音方式** | [±塞音]、[±鼻音]、[±边音] | m/n（鼻音）、l（边音） |
| **声带状态** | [±浊音] | p（清）vs b（浊） |
| **气流机制** | [±送气] | p vs pʰ |

---

### 六、韵律特征

#### 1. 超音段音系学

**韵律特征**是叠加在音段之上的语音特征：

| 类型 | 说明 | 本题涉及 |
|-----|------|---------|
| **声调** | 音高变化模式 | ✓ 苗语四声、卢维语声调 |
| **重音** | 音强突出 | 题目中用符号标记 |
| **时长** | 音长差异 | ee、oo 等长元音 |

#### 2. 声调标记的跨语言差异

题目揭示了一个重要原则：
> **标记与无标记的关系因语言而异**

在苗语中：
- 书写上的"无符号"≠ 音系上的"无调"
- 无符号实际对应特定的 **v 调**

这体现了音系学中的**默认值原则**：某些特征可能是默认的，不需要显式标记。

---

### 七、音系分析与解题策略

根据官方解答，音系分析的关键方法：

#### 1. 频次分析法

> "Since the mark ¨ appears the greatest number of times, we can begin with it"

**原理**：高频元素往往是最基础的元素，分析它们可以快速建立假设。

#### 2. 对立分布法

通过比较**最小对立体（Minimal Pair）**（仅在一个特征上不同的词对）来识别区别性特征：
- 如：相同音节配不同声调 → 声调具有音位功能

#### 3. 分布分析法

观察元素出现的**分布环境**：
- 声调标记总是出现在音节末尾
- 元音总是在音节核心位置

---

### 八、知识体系总结

```
音系学 (Phonology)
│
├── 音段音系学 (Segmental Phonology)
│   ├── 元音系统
│   │   ├── 单元音
│   │   └── 元音丛/二合元音
│   └── 辅音系统
│       ├── 单辅音
│       └── 复辅音
│
├── 超音段音系学 (Suprasegmental Phonology)
│   ├── 声调系统
│   │   ├── 声调标记
│   │   └── 默认值
│   └── 韵律结构
│
└── 特征理论 (Feature Theory)
    ├── 区别性特征
    └── 特征分解
```

