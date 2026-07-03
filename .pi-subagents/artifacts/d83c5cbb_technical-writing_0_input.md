# Task for technical-writing

Create a comprehensive Obsidian markdown note file at: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Degree Sequences & Subgraphs.md

ABSOLUTE REQUIREMENTS — Follow these exactly:
1. Write the COMPLETE file content — do not truncate, do not use placeholders
2. Use ONLY the write tool to create the file
3. Output ONLY the final content, no commentary

CONTENT SPECIFICATION:

--- TAGS ---
title: Graph - Degree Sequences & Subgraphs
tags:
  - Math
  - GraphTheory
  - 定义性
  - 基本原理
created: 2026-07-03

--- BASED ON ---
Christopher Griffin, Applied Graph Theory (2023), Chapter 2: Degree Sequences and Subgraphs

--- CONTENT TO COVER ---

## 1. Degree Sequences
### 1.1 Definition of Degree Sequence
- Definition 2.1: degree sequence of G = nonincreasing list of vertex degrees
- Example: K_4 has degree sequence (3,3,3,3); path P_4 has (2,2,1,1)
- Include Mermaid diagram of example graphs

### 1.2 Handshaking Lemma
- Theorem 2.2 (Handshaking Lemma): sum of degrees = 2|E|
- Corollary: In any graph, number of odd-degree vertices is even
- Proof via double counting
- Show examples

### 1.3 Graphic Sequences
- Definition: a sequence is graphic if there exists a graph with that degree sequence
- Havel-Hakimi Theorem (Thm 2.3): characterization of graphic sequences
- Algorithm description with Mermaid flowchart
- Example: (3,3,2,2,2) is graphic? Walk through Havel-Hakimi

### 1.4 Regular Graphs
- Definition 2.5: k-regular graph (all vertices degree k)
- Examples: 0-regular (empty), 1-regular (matching), 2-regular (cycles)
- Complete graphs K_n are (n-1)-regular
- Mermaid: K_5 as 4-regular graph

## 2. Subgraphs
### 2.1 Definitions
- Definition 2.7: subgraph G' = (V', E') where V' ⊆ V, E' ⊆ E
- Spanning subgraph: V' = V
- Induced subgraph G[S]: V' = S, E' = all edges with both ends in S
- Include Mermaid diagrams showing subgraph extraction

### 2.2 Graph Operations
- Edge deletion, vertex deletion, edge contraction

## 3. Cliques, Independent Sets, Complements & Covers
### 3.1 Cliques
- Definition 2.11: clique = set of mutually adjacent vertices
- Maximum clique vs maximal clique
- Clique number ω(G)
- Example with Mermaid

### 3.2 Independent Sets
- Definition 2.14: independent set = no two adjacent vertices
- Independence number α(G)
- Relationship: S is clique in G iff S is independent in complement

### 3.3 Graph Complement
- Definition 2.16: complement G̅ has edge between non-adjacent vertices in G
- Include Mermaid: G and G̅ side by side

### 3.4 Vertex Covers
- Definition 2.18: vertex cover = set of vertices touching all edges
- Relation: S is vertex cover iff V\S is independent set
- König's theorem (for bipartite graphs): size of min vertex cover = size of max matching

## 4. Practice Examples
- Work through 2-3 examples connecting these concepts
- Include complete Mermaid visualizations

--- FORMATTING RULES ---
1. YAML front matter MUST use double-quoted strings or bare strings (no single quotes for tags)
2. All math MUST use proper LaTeX: $\deg(v)$, $\Delta(G)$, $\delta(G)$, $\omega(G)$, $\alpha(G)$, $\overline{G}$
3. Use === for Mermaid section headers when needed
4. Use > [!note], > [!tip], > [!warning] callouts appropriately
5. Internal links: [[Graph - Definations]], [[../Linear_Algebra/Linear_Algebra_MOC]], etc.
6. Add '## 符号速查' section at end with a table of symbols used
7. Add '## 相关链接' section with links to [[Graph - Definations]], [[Graph - Walks, Cycles & Connectivity]]
8. NO horizontal rules (---) except after YAML front matter
9. File location: /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/Graph - Degree Sequences & Subgraphs.md
10. Output the COMPLETE content - every section filled out completely

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