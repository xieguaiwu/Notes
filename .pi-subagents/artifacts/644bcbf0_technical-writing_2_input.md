# Task for technical-writing

Write the COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Trees, Bipartite & Eulerian Graphs.md

Based on Griffin Ch4. Cover:

1. Bipartite graphs: definition, characterization (no odd cycles), complete bipartite K_{m,n}, König's theorem, applications. Mermaid for 2-coloring and K_{3,3}.

2. Trees: definitions (forest, tree, leaf), 6 characterizations (Theorem 4.5: TFAE), properties (n≥2 has ≥2 leaves), Cayley's formula n^{n-2}, Prüfer sequence with Mermaid. Spanning trees with Mermaid matrix-tree theorem preview. Rooted trees and traversals.

3. Eulerian graphs: Königsberg reference, Eulerian trail/circuit definitions, Euler's Theorem (even degree condition) with proof sketch, Fleury's Algorithm flowchart, Hierholzer algorithm, applications (Chinese Postman, DNA sequencing).

Tags: [Math, GraphTheory, 定义性, 定理性].
LaTeX for all math. At least 6 Mermaid diagrams. Callouts for Theorem 4.2, 4.5, 4.11.
Links: [[Graph - Definations]], [[Graph - Walks, Cycles & Connectivity]], [[Graph - Adjacency Matrix & Spectrum]]
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