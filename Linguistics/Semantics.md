---
tags:
  - Linguistics
  - 定义性
  - 基本原理
  - Morpheme
title: Semantics
created: 2026-02-20T20:25:00
modified:
---
# Semantics
[[克里普克模态语义递归定义]]
## 1. 引言

语义学研究意义，与语音学、形态学、句法学不同：

| 学科 | 研究对象 |
|------|----------|
| 语音学/音系学 | 声音形式的变化 |
| 形态学 | 词的屈折和派生 |
| 句法学 | 词语组合成句子 |
| **语义学** | 词语的意义、词语组合形成新意义 |

### 1.1 语义学问题的特点

- 通常是**混乱-有序问题**（语料以随机顺序给出）
- 语料由词语（或2-3个词的组合）组成
- 这些词语不一定共享形态特征，而是共享语义特征（属于同一语义场）

### 1.2 身体部位词的隐喻

> **警告**：表示器官或身体部位的词最"危险"，它们的组合常超越语义场，具有意想不到的意义。

**喀麦隆皮钦语示例**：

| 复合词 | 直译 | 实际意义 |
|--------|------|----------|
| openhan | open + hand | 慷慨 |
| blakhat | black + heart | 邪恶 |
| bathat | bad + heart | 仇恨 |
| blakai | black + eye | 头晕 |
| draihan | dry + hand | 贫穷 |

身体部位常与情感/感觉相关联，需特别注意。

## 2. 图形方法（Graph Method）

图形方法是解决语义学问题的有效工具。

### 2.1 基本概念

| 元素 | 含义 |
|------|------|
| **节点（Node）** | 表示基础词 |
| **线条/箭头** | 表示词语组合 |
| **箭头方向** | 表示组合顺序 |
| **下划线** | 表示该词出现在语料中 |

### 2.2 示例

对于复合词 *blakai* 和 *blakhat*：

```
ai ──────→ blakai
    ↗
blak
    ↘
hat ──────→ blakhat
```

简化表示：
```
ai ←── blak ──→ hat
```

（横线表示该复合词在语料中给出）

### 2.3 解题步骤

| 步骤 | 操作 |
|------|------|
| **Step 1** | 为目标语言的所有词创建图形（不先看英语翻译） |
| **Step 2** | 为英语词创建部分图形（只包含确定的组合） |
| **Step 3** | 比较两个图形，寻找匹配点 |
| **Step 4** | 翻译已知内容，继续填充其余词语 |

## 3. Lango语示例

### 3.1 语料

| Lango | 英语翻译 |
|-------|----------|
| dyèɔ̀t, dyètyɛ̀n, gìn, gìnwìc, ɲíg, ɲígwàŋ, ɔ̀tcɛ̀m, wìcɔ̀t | eyeball, grain, roof, garment, floor, restaurant, sole of foot, hat |

### 3.2 图形分析

**Lango语图形**：
```
dyè ──→ ɔ̀t ──→ wìc ──→ gìn
          │
          └──→ cɛ̀m ──→ tyɛ̀n

ɲíg ──→ wàŋ
```

**英语部分图形**：
```
bottom ──→ house ──→ top ──→ garment
              │
              └──→ floor, roof, hat
```

### 3.3 对应关系

| Lango | 分析 | 英语 |
|-------|------|------|
| dyèɔ̀t | bottom + house | floor |
| dyètyɛ̀n | bottom + foot | sole of foot |
| gìn | - | garment |
| gìnwìc | garment + top | hat |
| ɲíg | - | grain |
| ɲígwàŋ | grain + eye | eyeball |
| ɔ̀tcɛ̀m | house + food | restaurant |
| wìcɔ̀t | top + house | roof |

### 3.4 基础词

| Lango | 英语 |
|-------|------|
| dyè | bottom |
| ɔ̀t | house |
| wìc | top |
| cɛ̀m | food |
| tyɛ̀n | foot |
| gìn | garment |
| ɲíg | grain |
| wàŋ | eye |

### 3.5 推导翻译

"window" = eye of house = wàŋ + ɔ̀t = **wàŋɔ̀t**

## 4. Guaraní语示例

### 4.1 语料

| Guaraní | 英语翻译（随机顺序） |
|---------|---------------------|
| jaxy, jaxy-tata, jaxyendy, kuãguaxu, kuãregua, py'a, py'aguaxu, tata, tataendy, tatarataxĩ, yeguaxu, yvyrataxĩ, yvyporã, yy | water, brave, thumb, liver/heart, fire, smoke, moonlight, ring, firelight, pregnant, good soil, dust, star, moon |

### 4.2 图形分析

**Guaraní语图形**（三个独立子图）：

```
子图1：jaxy ←──→ tata ──→ rataxĩ ←── yvy ──→ porã
                    │
                    └──→ endy

子图2：ye ──→ guaxu ←── kuã ──→ regua
                │
                └──→ py'a

子图3：yy（独立节点）
```

### 4.3 对应关系

| Guaraní | 分析 | 英语 |
|---------|------|------|
| jaxy | - | moon |
| jaxy-tata | moon + fire | star |
| jaxyendy | moon + light | moonlight |
| tata | - | fire |
| tataendy | fire + light | firelight |
| tatarataxĩ | fire + powder | smoke |
| yvyrataxĩ | soil + powder | dust |
| yvyporã | soil + good | good soil |
| kuãguaxu | finger + big | thumb |
| kuãregua | finger + jewellery | ring |
| py'a | - | liver, heart |
| py'aguaxu | liver/heart + big | brave |
| yeguaxu | belly + big | pregnant |
| yy | - | water |

### 4.4 基础词

| Guaraní | 英语 |
|---------|------|
| jaxy | moon |
| tata | fire |
| endy | light |
| rataxĩ | powder, particles |
| yvy | soil |
| porã | good |
| kuã | finger |
| guaxu | big |
| regua | jewellery, ornament |
| py'a | liver, heart |
| ye | belly, stomach |
| yy | water |

### 4.5 推导翻译

| 英语 | 分析 | Guaraní |
|------|------|---------|
| fog | water + powder | yyrataxĩ |
| calm | good + liver/heart | py'aporã |

## 5. 解题方法论

### 5.1 关键观察点

1. **寻找出现次数最多的词**：通常是核心概念
2. **识别独立子图**：帮助缩小匹配范围
3. **注意身体部位词**：常与情感相关
4. **利用语义关联**：如 fire-smoke, moon-moonlight

### 5.2 常见语义组合模式

| 模式 | 示例 |
|------|------|
| **身体部位 + 性质** | big + heart = brave |
| **物体 + 部位** | finger + big = thumb |
| **物质 + 属性** | fire + powder = smoke |
| **整体 + 部分** | house + top = roof |

### 5.3 注意事项

- 多个答案可能同等正确（如 *jewellery*、*ornament*、*circle*）
- 图形方法提供系统性分析框架
- 需要一定的语义直觉
- 没有绝对的解题方法
