# Task for technical-writing

Write COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Every Matrix is a Graph.md

This is the first of the unique perspective notes (Path C) — the user's core idea: using graph theory to understand linear algebra. This is NOT from the Griffin textbook; it's a synthesis perspective.

**Tags**: [Math, GraphTheory, LinearAlgebra, Idea, 概念性]

**Content**:

1. **核心思想 (The Core Insight)**:
   - Any matrix IS a directed bipartite graph (if rectangular) or directed graph (if square)
   - The non-zero entries define the edges
   - Conversely, any graph has an adjacency matrix
   - This duality is the bridge between combinatorial and algebraic thinking

2. **Every Matrix as a Bipartite Graph**:
   - An m×n matrix M can be represented as a weighted bipartite graph:
     - Left vertices: rows 1..m
     - Right vertices: columns 1..n
     - Edge from row i to column j with weight M_{ij} if M_{ij} ≠ 0
   - Mermaid: small 3×4 matrix and its bipartite graph side-by-side

3. **Square Matrices as Directed Graphs**:
   - n×n matrix A → directed graph on n vertices
   - Edge i→j exists iff A_{ij} ≠ 0, weight = A_{ij}
   - Mermaid: 3×3 matrix with its directed graph

4. **Matrix Multiplication as Path Counting**:
   - (AB)_{ij} = Σ_k A_{ik} B_{kj} = sum of paths of length 2 from i to j (through k)
   - A^k_{ij} = number of walks of length k from i to j
   - This is the FUNDAMENTAL connection: algebraic operation = combinatorial enumeration
   - Mermaid: path counting interpretation of (A²)_{ij}

5. **Rank and the Structure of Graphs**:
   - Rank of adjacency matrix A relates to graph properties
   - Relationship between rank and number of vertices (lower bounds)
   - Nullspace of A = vectors orthogonal to incident edges
   - Mermaid: visualizing nullspace vectors on a graph

6. **Transpose as Reversal**:
   - A^T corresponds to reversing all edge directions
   - A + A^T = symmetrization = underlying undirected graph
   - A - A^T = signed directed edges (skew-symmetric part)

7. **Spectral Decomposition = Graph Decomposition**:
   - A = Σ λ_i v_i v_i^T (spectral theorem for symmetric A)
   - Each eigenvector v_i defines a weighting on vertices
   - The eigenvalue λ_i measures how much the graph 'amplifies' along that direction
   - This is the deepest connection: eigenvectors are "natural modes" of the graph

Links: [[Graph - Adjacency Matrix & Spectrum]], [[Linear_Algebra/Matrix Operations]], [[Linear_Algebra/Rank and Nullity]], [[Linear_Algebra/Eigenvalues and Eigenvectors]], [[Graph - Laplacian & Spectral Clustering]]
Include 相关笔记 and 延伸阅读 sections.
At least 3 Mermaid diagrams.
Write COMPLETE file with write tool.

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