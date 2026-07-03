# Task for technical-writing

Write the COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Walks, Cycles & Connectivity.md

Based on Griffin Ch3. Cover: (1) Paths, Walks, Cycles definitions with Mermaid, (2) Distance, Eccentricity, Diameter, Radius, Girth, Circumference with examples and Mermaid, (3) Connectedness, Components, Cut Vertices, Bridges with Mermaid, (4) k-Connectivity, Whitney's inequality κ(G) ≤ λ(G) ≤ δ(G), Menger's theorem, (5) Cuts.

Use tags: [Math, GraphTheory, 定义性, 基本原理].
LaTeX for all math. At least 5 Mermaid diagrams. Callout boxes for theorems.
Links: [[Graph - Definations]], [[Graph - Degree Sequences & Subgraphs]], [[Graph - Centrality Measures]], [[Graph - Trees, Bipartite & Eulerian Graphs]]
Include 符号速查 section.
Write COMPLETE file using write tool.

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