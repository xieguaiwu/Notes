# Task for deep

生成一篇关于**拓扑学 (Topology) 点集拓扑**的Obsidian笔记，保存到 /home/xieguiawu/Documents/Obsidian Vault/Math/Topology/Topology.md

这是数学Vault中完全缺失的一个重要分支。请严格遵循以下要求：

## 格式规范
1. YAML front matter:
```yaml
---
title: Topology
tags:
  - Math
  - Topology
  - 定义性
  - 基本原理
created: 2026-07-03
---
```
- 标题使用英文Title Case
- 标签：学科标签 `Math`, `Topology`；功能标签用中文如 `定义性`, `基本原理`, `概念性`, `定理性`
- 优先复用 vault 已有的功能标签：`定义性`, `基本原理`, `证明`, `方法性`, `定理性`, `概念性`, `Exercise`

2. 数学公式全部使用 LaTeX（$...$ 行内, $$...$$ 块级），禁止任何 Unicode 数学符号替代
3. 使用 Mermaid 图表展示概念关系
4. 使用 Callout: >[!note], >[!definition], >[!example], >[!theorem], >[!warning], >[!tip]
5. 内部链接到已有笔记：[[Mathematical_Analysis/continuity]], [[Set_Theory/Cartesian product]], [[Category Theory]], [[Mathematical_Analysis/limit]]
6. 不要使用 `---` 水平分割线（YAML之后和大章节之间也不用）

## 内容要求
- 点集拓扑核心：拓扑空间定义、开集/闭集、邻域、闭包/内部/边界
- 连续性与同胚（连接[[Mathematical_Analysis/continuity]]）
- 紧致性与连通性
- 分离公理（T0-T4）
- 积拓扑与商拓扑
- 度量化定理（Urysohn）
- 至少10个例子（如：实数标准拓扑、离散拓扑、余有限拓扑、Sierpinski空间等）
- 深度中等，约1500-2500字，涵盖主要概念和定理

## 输出方式
使用 write 工具写入文件。

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