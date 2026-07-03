# Task for deep

生成一篇关于**数论 (Number Theory) 初等数论**的Obsidian笔记，保存到 /home/xieguiawu/Documents/Obsidian Vault/Math/Number_Theory/Number_Theory.md

这是数学Vault中完全缺失的一个重要分支。请严格遵循以下格式规范：

## YAML front matter
```yaml
---
title: Number Theory
tags:
  - Math
  - NumberTheory
  - 定义性
  - 基本原理
created: 2026-07-03
---
```
- 标题英文Title Case
- 标签：`Math`, `NumberTheory`（学科标签），功能标签用中文：`定义性`, `基本原理`, `证明`, `方法性`, `定理性`, `概念性`
- 优先复用已有功能标签

## 格式要求
1. 数学公式全部 LaTeX（$...$ 行内, $$...$$ 块级），禁止任何Unicode数学符号
2. 使用Mermaid图表展示概念关系/分类
3. 使用Callout: >[!note], >[!definition], >[!example], >[!theorem], >[!warning], >[!tip]
4. 内部链接到已有笔记：[[Abstract_Algebra/Ring]], [[Abstract_Algebra/Field]], [[Abstract_Algebra/Group]], [[Boolean Algebra]], [[Linear_Algebra/Determinant]]
5. 不要使用 `---` 水平分割线
6. 文件路径已确定，用 write 写入

## 内容要求
- 整除性与带余除法、最大公因数与Euclid算法
- 素数（无限性证明、素数定理简述、素数分布）
- 算术基本定理
- 同余、同余方程、中国剩余定理
- 完全剩余系与简化剩余系、Euler函数 φ(n)
- Wilson定理、Fermat小定理、Euler定理
- 二次互反律（简述）
- 连分数与丢番图逼近（简介）
- 至少10个具体数例
- 深度中等，约1500-2500字

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