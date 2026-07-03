# Task for deep

生成一篇关于**复分析 (Complex Analysis)** 的Obsidian笔记，保存到 /home/xieguiawu/Documents/Obsidian Vault/Math/Complex_Analysis/Complex_Analysis.md

这是数学Vault中缺失的重要领域。已有 [[Mathematical_Analysis/Complex Field]] 但内容很浅。请严格遵循以下格式规范：

## YAML front matter
```yaml
---
title: Complex Analysis
tags:
  - Math
  - ComplexAnalysis
  - 定义性
  - 基本原理
created: 2026-07-03
---
```
- 标题英文Title Case
- 标签：`Math`, `ComplexAnalysis`（学科标签），功能标签用中文：`定义性`, `基本原理`, `证明`, `方法性`, `定理性`, `概念性`
- 优先复用已有功能标签

## 格式要求
1. 数学公式全部 LaTeX（$...$ 行内, $$...$$ 块级），禁止任何Unicode数学符号
2. 使用Mermaid图表展示概念关系/分类
3. 使用Callout: >[!note], >[!definition], >[!example], >[!theorem], >[!warning], >[!tip]
4. 内部链接到已有笔记：[[Mathematical_Analysis/Complex Field]], [[Mathematical_Analysis/Differentiability and Continuity]], [[Mathematical_Analysis/Definite Integrals]], [[Linear_Algebra/Bilinear Forms]]
5. 不要使用 `---` 水平分割线
6. 文件路径已确定，用 write 写入

## 内容要求
- 复变函数基础：复平面、复函数、极限、连续性
- 解析函数与Cauchy-Riemann方程
- 初等多值函数（对数、幂函数、复指数）
- 复积分与Cauchy积分定理
- Cauchy积分公式及其推论（Liouville定理、代数基本定理的复证明）
- 留数定理与实积分的计算
- Taylor展开与Laurent展开
- 孤立奇点分类
- 深度中等，约1500-2500字
- 至少8个具体函数例子

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