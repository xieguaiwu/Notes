# Task for technical-writing

Write COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Random Walks & PageRank.md

Based on Griffin Ch10.1-10.3 (Eigenvector Centrality, Markov Chains and Random Walks, PageRank).

**Tags**: [Math, GraphTheory, Probability, 概念性, 方法性]

**Content**:

1. **Eigenvector Centrality** (10.1):
   - Definition: x_i proportional to sum of neighbors' centralities => Ax = λx
   - Principal eigenvector gives scores
   - Perron-Frobenius ensures uniqueness for connected graphs
   - Comparison with degree centrality (Mermaid diagram)
   - Limitation: zero centrality for acyclic digraphs

2. **Markov Chains and Random Walks** (10.2):
   - Random walk on graph: from vertex i, choose neighbor uniformly at random
   - Transition matrix P = D^{-1}A (row-stochastic)
   - Markov chain properties: irreducible = connected, aperiodic = not bipartite
   - Stationary distribution π: πP = π
   - For undirected connected non-bipartite: π_i = deg(i)/(2|E|)
   - Mixing time and spectral gap
   - Mermaid: random walk example with probability transitions

3. **PageRank** (10.3):
   - Problem: dangling nodes, non-stationary PDF
   - PageRank model: random surfer with damping factor α (typically 0.85)
   - PageRank equation: r = αP^T r + (1-α)v (where v is teleportation vector)
   - Solution: iterative power method
   - Relationship to eigenvector centrality
   - Mermaid: PageRank computation flowchart
   - Mermaid: small web graph with PageRank scores

4. **Applications**:
   - Web search ranking
   - Recommendation systems
   - Network science (Google's original algorithm)

Tags: [Math, GraphTheory, Probability, 概念性, 方法性].
LaTeX: $P = D^{-1}A$, $\pi$, $\alpha$, $r = \alpha P^T r + (1-\alpha)\mathbf{v}$
Links: [[Graph - Adjacency Matrix & Spectrum]], [[Graph - Centrality Measures]], [[Graph - Laplacian & Spectral Clustering]]
Also link to [[Linear_Algebra/Eigenvalues and Eigenvectors]]
At least 4 Mermaid diagrams.
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