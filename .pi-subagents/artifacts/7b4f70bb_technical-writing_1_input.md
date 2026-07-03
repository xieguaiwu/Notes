# Task for technical-writing

Write COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Jordan Form through Graph Theory.md

**Tags**: [Math, GraphTheory, LinearAlgebra, 定理性, 概念性]

This is Path C note #3 — understanding Jordan Canonical Form through graph theory.

**Content**:

1. **核心思想**: The Jordan canonical form of a matrix is a decomposition of its associated directed graph into elementary 'chain' graphs. Each Jordan block J_k(λ) corresponds to a directed path of length k with self-loop weight λ.

2. **Jordan Block as Basic Graph**:
   - A Jordan block J_k(λ) = matrix with λ on diagonal, 1 on superdiagonal
   - Its directed graph: vertices v_1, v_2, ..., v_k
     - Each v_i has self-loop with weight λ
     - Each v_i has edge v_i → v_{i+1} with weight 1
   - This is a 'directed path with self-loops'
   - Mermaid: J_3(λ) as a 3-vertex directed graph

3. **Generalized Eigenvectors as Path Walks**:
   - (J_k(λ) - λI) is the 'shift' matrix: only the superdiagonal 1's remain
   - (J_k(λ) - λI)^2 has 1's on the second superdiagonal, etc.
   - (J_k(λ) - λI)^{k-1} ≠ 0 but (J_k(λ) - λI)^k = 0
   - This is exactly the path length in the graph!
   - A generalized eigenvector of rank r is a vertex at position r from the start of the chain
   - Mermaid: J_4(0) and its powers as walks

4. **Direct Sum as Disjoint Union**:
   - J = J_{k1}(λ_1) ⊕ J_{k2}(λ_2) ⊕ ... ⊕ J_{kr}(λ_r)
   - In graph terms: the graph is a DISJOINT UNION of path-graphs, each with self-loops of weight λ_i
   - Each component is a Jordan chain
   - Mermaid: direct sum of two Jordan blocks as disjoint graph components

5. **Algebraic vs. Geometric Multiplicity**:
   - Algebraic multiplicity of λ = sum of sizes of all Jordan blocks for λ = total number of vertices with self-loop λ
   - Geometric multiplicity of λ = number of Jordan blocks for λ = number of connected components with self-loop λ
   - Defect = difference = total missing edges to make full cycles
   - Mermaid: comparing algebraic and geometric multiplicity

6. **Nilpotent Operators as Directed Paths**:
   - A nilpotent N has all eigenvalues 0 => all self-loop weights 0 (essentially no self-loops)
   - N^k = 0 means the longest directed path has length k
   - Nilpotent graphs are DAGs (directed acyclic graphs), specifically disjoint unions of directed paths

7. **Minimal Polynomial as Graph Property**:
   - The exponent in the minimal polynomial for λ = size of the LARGEST Jordan block for λ = longest path length
   - The characteristic polynomial counts all vertices (paths) with self-loop λ

Links: [[Every Matrix is a Graph]], [[Linear Transformations as Graph Morphisms]], [[Linear_Algebra/Jordan Canonical Form]], [[Linear_Algebra/Eigenvalues and Eigenvectors]], [[Linear_Algebra/Diagonalization]], [[Graph - Adjacency Matrix & Spectrum]]
At least 4 Mermaid diagrams.
Use LaTeX for all math: $J_k(\lambda)$, $(J - \lambda I)^k$, etc.
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