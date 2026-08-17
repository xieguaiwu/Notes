---
title: SAT RW 2023年12月第一套 错题分析
tags:
  - SAT
  - Reading
  - 错题
created: 2026-07-22
---

# SAT RW 2023年12月第一套 错题分析

> [!abstract] 试卷信息
> - **试卷**: 2023年12月第一套 SAT Reading & Writing
> - **来源**: `~/高一/英语/SAT/0719hw/0719hw.md`
> - **本次错题**: 4 道（全部在 Module 2）
> - **薄弱技能**: Standard English Conventions（断句/标点）, Command of Evidence（图表推理、笔记综合）
> - **备注**: 按 v3.3 标准模板重塑（2026-08-17）

---

> [!danger] 分析原则
> 详见 [[SAT Reading - Analysis Principles]]。

## 目录

- [[#1. Module 2 Q12 — 图表推理（Lizard Escape Speed）]]
- [[#2. Module 2 Q17 — 语法：断句（Alma Lavenson）]]
- [[#3. Module 2 Q19 — 语法：分号 / Comma Splice（Canada; for example,）]]
- [[#4. Module 2 Q27 — 笔记综合：概括 + 支撑（Vexillology）]]

---

# 1. Module 2 Q12 — 图表推理

> [!info] 我的答案: `C` — 错误 | 正确答案: **B**

## Task（题干与选项）

**Number of Lizard Species by Average Percent of Maximal Speed Used When Pursuing Prey or Escaping Predators**

> [图表：横轴为 maximal speed 百分比区间，纵轴为 lizard species 数量，两组柱状图分别表示 escaping 和 pursuing。OCR 无法精确还原柱子高度，但关键分布模式可推断。]

It may seem that the optimal strategy for an animal pursuing prey or escaping predators is to move at maximal speed, but the energy expense of exploiting full speed capacity can disfavor such a strategy even in escape contexts, as evidenced by the fact that ___

Which choice most effectively uses data from the graph to complete the text?

- **A.** most lizard species use about the same percentage of their maximal speed when escaping predation as they do when pursuing prey.
- **B.** multiple lizard species move at an average of less than 90% of their maximal speed while escaping predation.
- **C.** more lizard species use, on average, 90%–100% of their maximal speed while escaping predation than use any other percentage of their maximal speed.
- **D.** at least 4 lizard species use, on average, less than 100% of their maximal speed while pursuing prey.

## Step 1 — Map（结构标注）

- **claim（set-up）**: It may seem that the optimal strategy for an animal pursuing prey or escaping predators is to move at maximal speed（看似最优策略 = 全速）
- **contrast（claim）**: but the energy expense of exploiting full speed capacity can disfavor such a strategy（能量消耗使全速策略失宠）
- **scope 词**: even in escape contexts —— 论证范围限定在**逃生场景**
- **缺口**: 论点需要图表证据支撑"逃生时也不全速"

## Step 2 — Mark（T / F / NG 判定）

| 选项 | 判定 | 依据 |
|:---|:---|:---|
| A | NG | 引入"逃生与捕食速度相近"的对比元素——原文论点谈的是"不全速"，与题干论证无关 |
| B | T | 直接证明：即使逃生也不全速（<90%）——多个物种在逃生时平均速度低于最大速度的 90% |
| C | F | 与"不全速"的论点方向相反：90–100% 区间物种最多 → 全速是主流，构成反向证据 |
| D | NG | 讨论 pursuing（捕食）而非 escaping（逃生）——题干论证限定 "even in escape contexts"，引入范围外元素 |

## Step 3 — Source-check（溯源）

- **B（T）逐元素溯源**: "multiple lizard species" = 图表中的多个物种；"less than 90% of their maximal speed" = 即并非全速（回应 full speed capacity 的论点）；"while escaping predation" = 回应 "even in escape contexts"。存在多个物种在逃生时也没有用全速，直接支撑"不全速"的论点。
- **C（F）溯源失败**: C 说"90–100% 区间物种最多"——意味着大部分物种在逃生时使用的是接近全速的速度。这对论点构成了**反向证据**：如果绝大多数物种逃生时都用 90–100% 速度，那"不全速"的论点反而缺乏数据支持。论点需要的是例外（不全速的案例），而不是主流趋势（全速是常态）。
- **D（NG）溯源失败**: 讨论的是 "pursuing prey"（捕食）而非 "escaping predation"（逃生）。题干论证明确限定在 "even in escape contexts"，捕食场景不在此论证范围内——虽然 D 在数据上可能正确，但无法支撑关于逃生行为的论点。
- **A（NG）溯源失败**: 论证的是"逃生和捕食速度相近"，与题干"不全速"无关。

## Step 4 — Chain-check（链条验证）

原文逻辑链：

> 看似最优 = 全速（set-up）→ **but** 能量消耗使全速失宠（论点）→ **even in escape contexts**（论证范围）→ 需证据：有物种逃生时不全速（缺口）→ **B** 提供该证据（链上缺失的一环）✅

- **C 是另一条链**: 全速区间的物种最多 → 支撑的是"全速是主流"——即被反驳的 set-up 方向，不是论点所需的链上环节 → 跳链。
- **A / D 在链外**: A 谈两场景速度相近（论证无关）；D 谈捕食场景（论证范围外）。

## Trap（陷阱命名）

> [!warning] 论点方向误判
> 题干论点是"不全速"（反面/例外论证），而不是"全速是主流"（正面/主流论证）——数据本身正确不等于支撑论点。防法：先确定论点方向，再看选项数据与论点的**逻辑关系方向**，而不是只看数据对错。

## Principle（对应原则）

原则二 逻辑优先（数据正确但方向相反 = 论点-证据逻辑关系判断错误）+ 原则一 文本依据（选项每个元素须逐一对位论点/图表）。

---

# 2. Module 2 Q17 — 语法：断句

> [!info] 我的答案: B (Lavenson titled) — 错误 | 正确答案: **A**

## Task（题干与选项）

Featured in *The New Woman Behind the Camera* (2021) is a photograph taken in 1932 by Alma ___ "Self-Portrait," Lavenson's image contributes to the exhibition's goal of showcasing the diverse, innovative, often aesthetically daring work of female photographers from the 1920s through the 1950s.

Which choice completes the text so that it conforms to the conventions of Standard English?

- **A.** Lavenson. Titled
- **B.** Lavenson titled
- **C.** Lavenson, titled
- **D.** Lavenson and titled

## Step 1 — Map（结构标注）

先找真正的谓语，确认句子边界：

- **句1（独立句）**: *Featured... is a photograph taken in 1932 by Alma ___* —— 真正谓语 = **is**（主语 a photograph）
- **句2（独立句）**: *___ "Self-Portrait," Lavenson's image contributes to...* —— 真正谓语 = **contributes**（主语 Lavenson's image）
- **空格位置**: 句1 的介词宾语收尾（by Alma ___）与句2 起点之间——即**独立句边界**，需要边界标点

两个分句各有完整主谓结构 → 中间不能用逗号连接，必须用句号（或分号）。

## Step 2 — Mark（T / F / NG 判定）

| 选项 | 判定 | 依据 |
|:---|:---|:---|
| A | T | 句号断句；"Titled" 作为过去分词短语修饰 "Lavenson's image"——两个独立句用句号正确分隔 |
| B | F | Comma splice + 歧义："is a photograph... by Alma Lavenson titled 'Self-Portrait'" 是完整独立句（主语 a photograph，谓语 is），后面 "Lavenson's image contributes" 是另一独立句，两个独立句之间只有一个逗号 |
| C | F | 同样产生 comma splice；逗号后 "titled 'Self-Portrait,' Lavenson's image contributes..." 两个独立句用逗号连接 |
| D | F | "and" 连接不对称成分，语法不通 |

## Step 3 — Source-check（溯源）

**规则依据（Comma Splice）**: 独立句之间不能用逗号连接，必须用句号（或分号）。

- **A（T）逐元素**: 句号明确分隔两个独立句，消除 comma splice ✓；句号后 "Titled" 没有主语，读者自然将其解读为过去分词短语，正确修饰紧随的名词短语 "Lavenson's image" ✓；不再有歧义 ✓。
- **B（F）双层问题**: ① Comma splice——"is a photograph... by Alma Lavenson titled 'Self-Portrait'" 是完整独立句，后面 "Lavenson's image contributes" 是另一个独立句，中间只有逗号。② 歧义——"Alma Lavenson titled 'Self-Portrait'" 读起来像 "Alma Lavenson 被命名为'自画像'"（title 作动词，Alma 作主语），读者可能误以为 Alma Lavenson 这个人被命名为 "Self-Portrait"，而非她的照片以此命名。
- **C（F）**: 在 "Lavenson" 后加逗号，同样面临 comma splice 问题；且连续两个逗号（"Lavenson, titled 'Self-Portrait,' Lavenson's image..."）使句子结构过于破碎。

## Step 4 — Chain-check（结构验证）

结构链（边界测试）：

> 句1（谓语 **is**）→ 句号边界 → 句2（谓语 **contributes**，句首过去分词短语 Titled 'Self-Portrait' 修饰主语 Lavenson's image）

- **A**: 边界正确 → 一个分句只有一个有限动词 ✓
- **B / C**: 逗号连接两个独立句 → 两个有限动词（is / contributes）落入同一边界内 → 双谓语 / comma splice ✗
- **D**: "and" 连接不对称成分，语法不通 ✗

## Trap（陷阱命名）

> [!warning] 分词结构误判
> 当 "titled" 作为过去分词修饰名词时，读者容易将其误认为谓语动词——本题关键在于识别句中存在**两个独立句**，需要用句号分隔。防法：先数出两个真正谓语（is / contributes），再验证边界标点；并检查 "by Alma Lavenson titled" 是否产生"人被命名"的歧义。

## Principle（对应原则）

结构优先（逻辑优先的语法版）。

---

# 3. Module 2 Q19 — 语法：分号 / Comma Splice

> [!info] 我的答案: A (Canada, for example,) — 错误 | 正确答案: **C**

## Task（题干与选项）

Photographer Maria Svarbova has reached audiences well beyond her home country of Slovakia. In 2021, her work was featured at Galerie LeRoyer in ___ the exhibited photographs, with their vivid pastel colors, overexposed tones, and mirrorlike symmetry, captivated audiences.

Which choice completes the text so that it conforms to the conventions of Standard English?

- **A.** Canada, for example,
- **B.** Canada, for example
- **C.** Canada; for example,
- **D.** Canada, for example;

## Step 1 — Map（结构标注）

- **句1（独立句）**: *In 2021, her work was featured at Galerie LeRoyer in Canada.* —— 主语：her work | 谓语：**was featured**
- **句2（独立句）**: *For example, the exhibited photographs, with their vivid pastel colors, overexposed tones, and mirrorlike symmetry, captivated audiences.* —— 主语：the exhibited photographs | 谓语：**captivated**

两个都是完整的独立句（independent clauses），各有自己的主语和谓语 → 两个独立句之间不能用逗号连接（comma splice），必须用句号或分号。

## Step 2 — Mark（T / F / NG 判定）

| 选项 | 判定 | 依据 |
|:---|:---|:---|
| A | F | Comma splice：两个独立句用逗号相连 |
| B | F | 缺少闭合逗号（"for example" 作插入语需要前后逗号），且仍为 comma splice |
| C | T | 分号正确分隔两个独立句；"for example" 后用逗号符合插入语规范 |
| D | F | 分号放在最后破坏了句子结构，且仍为 comma splice |

## Step 3 — Source-check（溯源）

**规则依据（Comma Splice）**: SAT 语法中，两个独立句之间不能用逗号连接——这是 comma splice，是 SAT 标点题的高频考点。

- **C（T）逐元素**: 分号 = 正确连接两个独立句（was featured... / the exhibited photographs... captivated）✓；"for example" 是插入语，前后标点正确（前有分号、后有逗号）✓。
- **A（F）**: "in Canada, for example, the exhibited photographs..." 读起来流畅，但逗号连接两个独立句 → comma splice。
- **B（F）**: 缺少 "for example" 后的闭合逗号（插入语应前后都有逗号），且仍为 comma splice。
- **D（F）**: 分号位置错误——插在 "for example" 和 "the exhibited photographs" 之间，破坏了句子结构。

## Step 4 — Chain-check（结构验证）

结构链（边界测试）：

> 句1（was featured in Canada）→ 分号边界 → 句2（For example, ... the exhibited photographs ... captivated audiences，举例说明句1）

- **C**: 分号正确切割 → 每个分句只有一个有限动词 ✓
- **A / B / D**: 两个有限动词（was featured / captivated）落入同一逗号边界内 → 双谓语 / comma splice ✗
- **补充（为什么学生可能选 A）**: A 看起来"流畅"——"in Canada, for example, the exhibited photographs..." 读起来不卡顿，在口语或非正式写作中这种用法可能被接受。但 SAT 语法对 comma splice 有严格的零容忍政策：两个独立句必须用句号或分号分隔，不能仅用逗号。

## Trap（陷阱命名）

> [!warning] 流畅性伪装
> 有些 comma splice 在口语中听起来自然（如 "I went to the store, I bought milk"），SAT 会利用这种流畅感设置陷阱——标准书面英语中，两个独立句永远不能只靠逗号连接。防法：检查逗号两侧是否各有完整的主谓结构 → 如果是 → 必须改用句号或分号。

## Principle（对应原则）

结构优先（逻辑优先的语法版）。

---

# 4. Module 2 Q27 — 笔记综合：概括 + 支撑

> [!info] 我的答案: `C` — 错误 | 正确答案: **D**

## Task（题干与选项）

While researching a topic, a student has taken the following notes:

- Vexillology is the study of flags.
- The flags of many countries include symbols like animals, plants, or landforms.
- These symbols often represent an aspect of the region's history, culture, or landscape.
- The flag of Slovakia includes the Tatra, Matra, and Fatra mountains.
- The flag of Kiribati includes a frigatebird.

The student wants to **make and support a generalization** about symbols on flags. Which choice most effectively uses relevant information from the notes to accomplish this goal?

- **A.** Vexillology is the study of flags; accordingly, vexillologists are interested in flags from around the world.
- **B.** Slovakia's flag includes the Tatra, Matra, and Fatra mountains, a symbol that is important to that country's national identity.
- **C.** Many countries feature symbols on their flags, and the study of these designs is known as vexillology.
- **D.** The flags of some countries include symbols of landform; Slovakia's, for example, includes the Tatra, Matra, and Fatra mountains.

## Step 1 — Map（结构标注）

- **任务动词**: make **AND** support a generalization —— 包含两个动作：① Make a generalization（提出概括性的陈述）② Support（用笔记中的具体信息支撑这个概括）
- **笔记分层**: 定义层（vexillology 是什么）｜概括素材（many countries include symbols / landforms）｜支撑素材（Slovakia 的山脉、Kiribati 的军舰鸟）
- **选项检查点**: 每个选项是否**完整覆盖**所有动作要求

## Step 2 — Mark（T / F / NG 判定）

| 选项 | 判定 | 依据 |
|:---|:---|:---|
| A | F | 仅定义 vexillology，既无概括也无支撑 |
| B | F | 只有具体例子，没有概括（缺少 generalization） |
| C | F | 前半句做了概括（many countries feature symbols），但后半句是定义而非支撑 |
| D | T | 概括（some include landforms）+ 支撑（Slovakia example）——完整满足 make and support |

## Step 3 — Source-check（溯源）

- **D（T）逐元素**: 前半句 "The flags of some countries include symbols of landform" ← 笔记 "The flags of many countries include symbols like animals, plants, or landforms"（landform 元素）→ 概括成立；后半句 "Slovakia's, for example, includes the Tatra, Matra, and Fatra mountains" ← 笔记 "The flag of Slovakia includes the Tatra, Matra, and Fatra mountains" → 举例支撑成立。
- **C（F）溯源失败**: 前半句 "Many countries feature symbols on their flags" ← 笔记 "The flags of many countries include symbols..."（概括成立）；但后半句 "the study of these designs is known as vexillology" ← 笔记定义，是术语**定义**，而不是对前半句概括的**支撑/举例**。**定义 ≠ 支撑**：支撑需要说明"为什么这个概括成立"或"举例说明这个概括"，而非"这个领域叫什么"。
- **A（F）**: 仅定义 vexillology（"Vexillology is the study of flags"），后半句引入笔记之外的元素（vexillologists 的兴趣），既无概括也无支撑。
- **B（F）**: 只有 Slovakia 的具体例子，没有概括（缺少 generalization）。

## Step 4 — Chain-check（链条验证）

任务链：

> make（概括）→ support（举例/论证）→ 完整结构 = 概括 + 举例支撑

- **D**: 概括（some flags include landforms）→ 举例（Slovakia's mountains）——链上完整 ✅
- **C**: 概括（many countries feature symbols）+ 定义（vexillology）——后半句是**链外环节**（定义），不是支撑环 → 跳链 ❌
- **判断方法**: 问自己"后半句是否让前半句的概括**更有说服力**？"——如果后半句只是补充信息而非论证或举例，则不构成 support。

## Trap（陷阱命名）

> [!warning] 定义伪装支撑
> 笔记综合题中，选项常在后半句放入"看起来相关但实际不构成支撑"的内容（如定义、背景信息、无关事实）——定义 ≠ 支撑。防法：问自己"后半句是否让前半句的概括更有说服力？"——如果后半句只是补充信息而非论证或举例，则不构成 support。

## Principle（对应原则）

原则二 逻辑优先（make and support 任务动词决定选项结构）+ 原则一 文本依据（支撑元素须来自笔记原文）。

---

## 积累小结

| # | 题目 | 模块 | 技能类别 | 学生错误 | 优先级 |
|:---|:---|:---:|:---|:---|:---:|
| 1 | Q12 Lizard Speed | Mod2 | Command of Evidence — 图表推理 | 选 C（全速区间物种最多）→ 论点方向误判 | ⭐⭐⭐ |
| 2 | Q17 Alma Lavenson | Mod2 | Standard English Conventions — 断句 | 选 B（Lavenson titled）→ comma splice + 歧义 | ⭐⭐⭐ |
| 3 | Q19 Canada Semicolon | Mod2 | Standard English Conventions — 分号 | 选 A（逗号）→ comma splice 未识别 | ⭐⭐ |
| 4 | Q27 Vexillology | Mod2 | Command of Evidence — 笔记综合 | 选 C（定义伪支撑）→ 未满足 "support" 要求 | ⭐⭐⭐ |

### 技能分布汇总（mermaid 图转文本）

- Command of Evidence（图表推理）: 1
- Command of Evidence（笔记综合）: 1
- Standard English Conventions（断句）: 1
- Standard English Conventions（分号）: 1

### 行动项

1. **Comma Splice 专项突破** — Q17 和 Q19 均涉及 comma splice，是 SAT 语法最高频考点之一
   - ⚠️ 同一错误模式在后续练习中反复出现：[[SAT RW Four Parts Practice Boundaries 错题分析#2. P2 Q18]]（Machu Picchu dating — `earlier, which in`）。跨卷已累计 3 次
   - 核心判断法：检查逗号两侧是否各有完整的主谓结构 → 如果是，必为 comma splice
   - 两种正确修复法：① 改逗号为句号（断句）、② 改逗号为分号
   - Q17 选用句号（因为前后句意群独立），Q19 选用分号（因为前后句有逻辑关联："for example"）
2. **Command of Evidence — 笔记综合** — Q27 暴露了对 "make AND support" 要求的不够敏感
   - 做笔记题时，先圈出题干中的动作要求（present/explain/make and support/emphasize 等）
   - 检查每个选项是否**完整覆盖**所有动作要求
   - "support" 必须有论证或举例功能，定义/背景信息不算
3. **Command of Evidence — 图表推理** — Q12 暴露了论点方向判断问题
   - 先明确题干的论点方向（正面论证 vs. 反面/例外论证）
   - 然后判断选项的数据是否与论点方向一致
   - 不要只关注数据"对错"，更要关注数据与论点的**逻辑关系方向**

### 待创建的相关笔记

- [[SAT Grammar - Comma Splice 与分号用法]]
- [[SAT Reading - 笔记综合题策略]]
- [[SAT Reading - 图表推理题解题方法]]
