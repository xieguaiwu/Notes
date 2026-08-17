---
title: SAT RW 错题解析标准模板
tags:
  - SAT
  - Reading
  - 方法性
created: 2026-08-17
---

# SAT RW 错题解析标准模板

> [!abstract] 用途
> 这是所有 SAT RW 错题解析/错题积累笔记的**统一标准格式**（v3.3，对齐 `SAT_RW_Error_Checklist.tex` Chapter E 的样板）。每一道错题必须严格按以下 **7 步** 结构书写：**Task → Map → Mark → Source-check → Chain-check → Trap → Principle**。任何一篇错题笔记都不得再使用旧的「选项分析 / 解题思路 / 推理过程 / 解题策略」松散结构。
>
> 核心方法论：详见 [[SAT Reading - Analysis Principles]]（文本依据、逻辑优先、功能定位、中心问题四原则）与 `~/高一/英语/SAT/SAT_RW_Error_Checklist.tex` Chapter E 的四道样板题。

---

## 文件级结构

```
---
title / tags / created  (保留原 frontmatter)
---
# 标题
> [!abstract] 试卷信息
> - 试卷 / 来源 / 当前积累(错题数) / 薄弱技能 / 备注
> - 备注建议注明：按 v3.3 标准模板重塑
> [!danger] 分析原则
> 详见 [[SAT Reading - Analysis Principles]]。
## 目录
- [[#1. ...]]
- [[#2. ...]]
（每题一个一级标题）
## 积累小结（文件末尾）
| 题号 | 考点 | 我的答案 | 正确答案 | 错误类型 |
（表格汇总 + 1-3 条行动项）
```

---

## 每题结构（7 步标准）

每题一个 `#` 一级标题，格式：

```
# N. Module X QY — 考点短名

> [!info] 我的答案: X — 错误/正确 | 正确答案: **Y**

## Task（题干与选项）
（题干**完整原文**，逐字保留；选项 A/B/C/D 完整原文，逐字保留）

## Step 1 — Map（结构标注）
（阅读题：给每句标注职责：claim / evidence / contrast / conclusion / answer / set-up；
  语法题：标注句法结构，先找主句/从句的真正谓语）

## Step 2 — Mark（T / F / NG 判定）
（表格：选项 | 判定 | 依据）
- T = 选项每个元素都能在原文找到
- F = 与原文某句直接矛盾（要写出矛盾点）
- NG = 引入了原文从未出现的元素（写出缺失元素）
- 语法题：T/F 判定 + 语法规则依据（引用 Checklist A1.x / A2.x 规则）

## Step 3 — Source-check（溯源）
（对幸存的 T 选项：逐元素指出支撑它的原文句子；
  对每个 NG：命名它缺的到底是哪个元素；
  对每个 F：命名它矛盾的那句话）

## Step 4 — Chain-check（链条验证）
（把原文逻辑写成链：A → B → C（因果/转折/回答）；
  确认幸存选项是链上的一环，而不是跳链；
  语法题：验证"一个分句只有一个有限动词 / 边界测试"）

## Trap（陷阱命名）
> [!warning] 陷阱名
> 一句话规则 + 一句话防法。命名必须是可复用的模式名
> （如：范围缺口、程度夸大、set-up 当中心、话题偷换、双谓语、comma splice...）。

## Principle（对应原则）
（标注本题违反/应用了哪条核心原则：
  原则一 文本依据 / 原则二 逻辑优先 / 原则三 功能定位 / 原则四 中心问题；
  语法题为「结构优先」——逻辑优先的语法版）
```

---

## 阅读题样板（缩写版）

> [!example] E1 样板 —— Command of Evidence（范围匹配）
> **Task**: 生态学家目标 = 全球增加造礁珊瑚；工具仅在印度洋单一物种验证。问哪个发现支持"工具已具备支持目标范围的能力"。
> **Step 1 Map**: claim（worldwide 是 scope 词）→ evidence（仅 Porites lutea 印度洋）→ 缺口。
> **Step 2 Mark**: A=NG（稳定性是品质非范围）、B=T（新物种+新地区）、C=NG（仍在印度洋）、D=NG（同物种同地区）。
> **Step 3 Source-check**: B 的 Orbicella faveolata = 原文句1的加勒比珊瑚；outside the Indian Ocean = 回应 worldwide。
> **Step 4 Chain-check**: 目标(worldwide) → 工具须超出已验证范围 → B 是缺失的一环；A 是另一条链（耐久性）。
> **Trap — 范围缺口**: 工具的"品质"（稳定/耐用）不是范围扩展。圈出 scope 词再逐选项对位。
> **Principle**: 原则一 文本依据 + 原则二 逻辑优先。

## 语法题样板（缩写版）

> [!example] E4 样板 —— SEC（with 独立主格）
> **Task**: ...with executives rather than creatives ___ decision-making power. A have been given / B been given / C being given / D are being given。
> **Step 1 Map（结构）**: 主句谓语 = have seen；空格在 with + 名词 独立主格内 → 一个分句只能有一个有限动词。
> **Step 2 Mark**: A=F（with 后有限动词→双谓语）、B=F（缺 being 的裸过去分词）、C=T（with+名词+现在分词=独立主格）、D=F（有限动词→双谓语）。
> **Step 3 Source-check**: 规则依据 = Checklist A1.7（介词后非谓语化）。
> **Step 4 Chain-check（结构）**: 主句 → 独立主格；A/D 制造第二个谓语，B 结构不完整，C 补全结构。
> **Trap — with 后双谓语**: with/without/despite 后绝不可能是有限动词。
> **Principle**: 结构优先（逻辑优先的语法版）。

---

## 重塑清单（旧结构 → 新结构映射）

| 旧章节 | 新位置 |
|:---|:---|
| `## 题干` | `## Task（题干与选项）`（保留完整题干+选项） |
| `## 解题思路` / `## 推理过程` | 拆入 `Step 1 Map` + `Step 4 Chain-check` |
| `## 选项分析`（表格） | `Step 2 Mark`（补 T/F/NG 判定列） |
| `## 为什么 X 正确` | `Step 3 Source-check`（逐元素溯源） |
| `## 陷阱识别` | `## Trap`（压缩为一句话规则） |
| `## 解题策略` | 融入各 Step；可保留 1-2 条最关键的到 `Trap` 或文件级 `行动项` |
| `## 积累小结` | 保留，移到文件末尾 |

**铁律**：
1. 题干、选项、正确答案、我的答案——**逐字保留**，不得改写、缩写到失真。
2. 不得添加原笔记没有的新分析/新事实。
3. 每题的 Map / Mark / Source-check / Chain-check 四步必须全部出现，缺一不可。
4. Trap 必须是一个**可复用命名模式**，不能只是"这题做错了"。
5. Principle 必须明确标注四原则之一（语法题为「结构优先」）。
