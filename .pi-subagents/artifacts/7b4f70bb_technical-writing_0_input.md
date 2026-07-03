# Task for technical-writing

Write COMPLETE file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Linear Transformations as Graph Morphisms.md

**Tags**: [Math, GraphTheory, LinearAlgebra, CategoryTheory, 概念性, Idea]

This is Path C note #2 — extending the core idea that 'Every Matrix is a Graph' to transformations.

**Content**:

1. **核心思想**: Linear transformations between vector spaces can be viewed as morphisms between graphs. When we choose bases, a linear transformation T: V→W becomes a matrix M. That matrix M is a weighted directed bipartite graph. So T IS a graph homomorphism between the trivial complete graphs on the basis vectors.

2. **Basis Selection = Graph Representation**:
   - Choosing a basis for V and W is like choosing vertex labels
   - The matrix M_T = [T]_{basis} is the adjacency matrix of a bipartite graph
   - Change of basis = graph relabeling (isomorphism)
   - Similar matrices = isomorphic graphs (they represent the same linear transformation in different bases)
   - Mermaid: T: R^2 → R^3 with two different basis choices, showing the same T as two different bipartite graphs

3. **Kernel and Image Graphically**:
   - ker(T): vectors in domain that map to zero; in graph terms, these are weight assignments on left vertices such that the sum to each right vertex is zero
   - im(T): subspace of codomain reachable from left vertices
   - Rank-nullity theorem: sum of dimensions of left nullspace and image = dim(domain)
   - Mermaid: bipartite graph with kernel basis vectors shown as weight assignments

4. **Composition as Graph Composition**:
   - T: V→W, S: W→U => S∘T: V→U
   - In graph terms: compose two bipartite graphs, resulting in a new bipartite graph
   - Matrix multiplication (S∘T)_{ik} = Σ_j S_{ij} T_{jk} is path counting!
   - This is the SAME formula as counting walks in a 3-partite graph
   - Mermaid: composition of two linear transformations as a 3-layer graph

5. **Dual Space as Reversed Graph**:
   - T^T: W^* → V^* corresponds to reversing all edges in the bipartite graph
   - The transpose corresponds to reversing directions
   - If T is injective, T^T is surjective (graph-theoretic duality)
   - Mermaid: T and T^T as reversed bipartite graphs

6. **Spectral Theory as Graph Decomposition**:
   - A linear operator T: V→V is a single graph (not bipartite), i.e., a directed graph
   - Eigenvectors x with Tx = λx = self-loops with weight λ in the graph
   - Diagonalizable = graph decomposes into independent self-loops
   - Jordan blocks = paths in the graph (a Jordan chain is a directed path)
   - Mermaid: diagonalizable matrix as a set of self-loops

Links: [[Every Matrix is a Graph]], [[Graph - Adjacency Matrix & Spectrum]], [[Linear_Algebra/Linear Transformations]], [[Linear_Algebra/Vector Spaces and Subspaces]], [[Linear_Algebra/Rank and Nullity]], [[Linear_Algebra/Dual Space]], [[Category_Theory/Functor]]
At least 4 Mermaid diagrams.
Use LaTeX for all math.
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