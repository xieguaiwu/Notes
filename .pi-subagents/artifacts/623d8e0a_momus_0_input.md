# Task for momus

审查以下4篇Obsidian数学笔记的质量。请严格检查以下几方面，并以结构化报告呈现发现的问题和修复建议。

## 待审查文件

1. Topology: /home/xieguiawu/Documents/Obsidian Vault/Math/Topology/Topology.md
2. Number Theory: /home/xieguiawu/Documents/Obsidian Vault/Math/Number_Theory/Number_Theory.md
3. Mathematical Logic: /home/xieguiawu/Documents/Obsidian Vault/Math/Mathematical_Logic/Mathematical_Logic.md
4. Complex Analysis: /home/xieguiawu/Documents/Obsidian Vault/Math/Complex_Analysis/Complex_Analysis.md

## 审查标准

### 数学正确性 (权重最高)
- 概念定义是否准确？
- 定理表述是否精确？
- 是否存在数学错误或误导性表述？

### 格式合规性
- YAML front matter是否符合 vault 规范？（标签：学科用英文首字母大写驼峰，功能用中文）
- 数学公式是否全部用 LaTeX（$...$/$$...$$），无 Unicode 数学符号替代？（如 $\to$ 正确，→ 错误；$\forall$ 正确，∀ 错误；$\in$ 正确，∈ 错误等）
- Mermaid 图表是否渲染有效？
- Callout 语法是否正确？
- 内部链接是否指向确实存在或合理应存在的笔记？

### 内容完整性
- 覆盖深度是否合理？
- 例子数量是否充足（要求≥8个）？
- 与其他笔记的交叉引用是否充分？

## 输出要求
- 对每篇笔记给出独立评价
- 列出具体问题（如果有）并附上行号或位置
- 按严重度分级：Critical（必须修复）/ Minor（建议修复）/ Nitpick（可忽略）
- 最后给出整体综合评价和优先修复建议

使用 read 工具读取文件内容进行审查。

## Acceptance Contract
Acceptance level: attested
Completion is not accepted from prose alone. End with a structured acceptance report.

Criteria:
- criterion-1: Return a concise result and residual risks when applicable

Required evidence: manual-notes, residual-risks

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