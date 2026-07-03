# Task for deep

生成一篇关于**数理逻辑 (Mathematical Logic)** 的Obsidian笔记，保存到 /home/xieguiawu/Documents/Obsidian Vault/Math/Mathematical_Logic/Mathematical_Logic.md

这是数学Vault中完全缺失的重要领域。请严格遵循以下格式规范：

## YAML front matter
```yaml
---
title: Mathematical Logic
tags:
  - Math
  - Logic
  - 定义性
  - 基本原理
created: 2026-07-03
---
```
- 标题英文Title Case
- 标签：`Math`, `Logic`（学科标签），功能标签用中文：`定义性`, `基本原理`, `证明`, `方法性`, `定理性`, `概念性`
- 优先复用已有功能标签

## 格式要求
1. 数学公式全部 LaTeX（$...$ 行内, $$...$$ 块级），禁止任何Unicode数学符号
2. 使用Mermaid图表展示概念关系
3. 使用Callout: >[!note], >[!definition], >[!example], >[!theorem], >[!warning], >[!tip]
4. 内部链接到已有笔记：[[Lambda Calculus]], [[Boolean Algebra]], [[Category Theory]], [[Set_Theory/Cartesian product]], [[Category Theory/Natural Transformation]], [[Boolean Algebra]]
5. 不要使用 `---` 水平分割线
6. 特别注意：模态逻辑算子必须用 $\Box$, $\Diamond$, $\lnot$, $\land$, $\lor$, $\to$, $\models$, $\vdash$，禁止ASCII替代
7. 文件路径已确定，用 write 写入

## 内容要求
- 命题逻辑：语法、语义、真值表、重言式
- 一阶逻辑：谓词、量词、Free/bound variables
- 语义与语法后承（$\models$ vs $\vdash$）
- Gödel完备性定理（陈述）
- Gödel不完备性定理（第一、第二，非正式陈述）
- 可计算性：图灵机、停机问题、判定问题
- 与[[Lambda Calculus]]的联系（λ演算与递归函数等价）
- 与[[Category Theory]]的联系（Curry-Howard对应）
- 深度中等，约1500-2500字
- 至少8个具体逻辑例子

输出方式：使用 write 工具写入文件。

## Acceptance Contract
Acceptance level: checked
Completion is not accepted from prose alone. End with a structured acceptance report.

Criteria:
- criterion-1: Implement the requested change without widening scope

Required evidence: changed-files, tests-added, commands-run, residual-risks, no-staged-files

Finish with a fenced JSON block tagged `acceptance-report` in this shape:
Use empty arrays when no items apply; array fields contain strings unless object entries are shown.
```acceptance-report
{
  "criteriaSatisfied": [
    {
      "id": "criterion-1",
      "status": "satisfied",
      "evidence": "specific proof"
    }
  ],
  "changedFiles": [
    "src/file.ts"
  ],
  "testsAddedOrUpdated": [
    "test/file.test.ts"
  ],
  "commandsRun": [
    {
      "command": "command",
      "result": "passed",
      "summary": "short result"
    }
  ],
  "validationOutput": [
    "validation output or concise summary"
  ],
  "residualRisks": [
    "none"
  ],
  "noStagedFiles": true,
  "diffSummary": "short description of the diff",
  "reviewFindings": [
    "blocker: file.ts:12 - issue found, or no blockers"
  ],
  "manualNotes": "anything else the parent should know"
}
```