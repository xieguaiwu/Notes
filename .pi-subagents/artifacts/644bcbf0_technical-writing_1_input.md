# Task for technical-writing

Write the COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Centrality Measures.md

Based on Griffin Ch3.4. Cover: (1) Why centrality, (2) Degree Centrality with Mermaid, (3) Closeness Centrality with Mermaid, (4) Betweenness Centrality with Mermaid (Brandes algorithm mention), (5) Eigenvector Centrality with comparison to degree, (6) Katz/PageRank preview, (7) Comparison table of all measures.

Use tags: [Math, GraphTheory, 概念性, 方法性].
LaTeX: $C_D(v)$, $C_C(v)$, $C_B(v)$, $C_E(v)$. At least 4 Mermaid diagrams. Callouts.
Links: [[Graph - Walks, Cycles & Connectivity]], [[Graph - Adjacency Matrix & Spectrum]], [[Graph - Random Walks & PageRank]], [[Graph - Laplacian & Spectral Clustering]]
Write COMPLETE file.

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