---
tags:
  - Math
  - GraphTheory
  - LinearAlgebra
  - 定理性
  - 概念性
title: Graph - Adjacency Matrix & Spectrum
created: 2026-07-03
modified:
---

# Graph — Adjacency Matrix & Spectrum

> [!info] Source
> Christopher Griffin, *Applied Graph Theory* (2023), Chapter 9: Adjacency Matrix and Graph Spectrum

> **Prerequisites**
> - [[Graph - Definitions]] — basic graph vocabulary
> - [[Linear_Algebra/Eigenvalues and Eigenvectors]] — eigenvalue basics
> - [[Linear_Algebra/Matrix Operations]] — matrix multiplication and transpose
>
> **Follow-ups**
> - [[Graph - Laplacian & Spectral Clustering]] — Laplacian matrix and spectral partitioning
> - [[Graph - Centrality Measures]] — eigenvector centrality, PageRank
> - [[Graph - Random Walks & PageRank]] — random walks on graphs

---

## 1. Matrix Representations of Graphs (Griffin §9.1)

Every graph $G = (V, E)$ with $|V| = n$ and $|E| = m$ can be represented by several matrices. The three fundamental ones are the **adjacency matrix**, the **incidence matrix**, and the **degree matrix**.

### 1.1 Adjacency Matrix $A$

**Definition (Adjacency Matrix).** Let $G = (V, E)$ be a simple graph with vertices labeled $V = \{v_1, v_2, \dots, v_n\}$. The **adjacency matrix** $A = A(G)$ is the $n \times n$ matrix with entries

$$
A_{ij} = \begin{cases}
1 & \text{if } \{v_i, v_j\} \in E,\\[2pt]
0 & \text{otherwise}.
\end{cases}
$$

For an **undirected** graph, $A$ is symmetric ($A^{\sf T} = A$). For a **directed** graph, $A_{ij} = 1$ if there is a directed edge $v_i \to v_j$; in general $A$ is not symmetric.

> [!example] Graph and its Adjacency Matrix
> Consider the path $P_4$ with vertices $1,2,3,4$ and edges $\{1,2\}, \{2,3\}, \{3,4\}$:
>
> ```mermaid
> graph LR
>     subgraph Graph["Graph G = P₄"]
>         direction LR
>         v1((1)) --- v2((2)) --- v3((3)) --- v4((4))
>     end
> ```
>
> $$
> A(P_4) = \begin{pmatrix}
> 0 & 1 & 0 & 0 \\
> 1 & 0 & 1 & 0 \\
> 0 & 1 & 0 & 1 \\
> 0 & 0 & 1 & 0
> \end{pmatrix}
> $$
>
> Symmetric, zero diagonal (simple graph), each row/column sum equals the degree of the corresponding vertex.

### 1.2 Incidence Matrix $M$

**Definition (Incidence Matrix).** Let $G = (V, E)$ be a graph with $n$ vertices and $m$ edges. The **incidence matrix** $M = M(G)$ is the $n \times m$ matrix with entries

$$
M_{v,e} = \begin{cases}
1 & \text{if vertex $v$ is incident to edge $e$},\\
0 & \text{otherwise}.
\end{cases}
$$

For an undirected graph, each column (corresponding to an edge) has exactly two 1's (the two endpoints). For a directed graph, we use $M_{v,e} = 1$ for tail, $-1$ for head, and $0$ otherwise.

> [!note] Relationship to Laplacian
> The incidence matrix satisfies $M M^{\sf T} = D + A$, where $D$ is the degree matrix (see below). For directed graphs with signed incidence, $M M^{\sf T}$ is the **Laplacian matrix** $L = D - A$.

### 1.3 Degree Matrix $D$

**Definition (Degree Matrix).** Let $G = (V, E)$ be a graph. The **degree matrix** $D = D(G)$ is the $n \times n$ diagonal matrix

$$
D_{ij} = \begin{cases}
\deg(v_i) & \text{if } i = j,\\
0 & \text{otherwise}.
\end{cases}
$$

For the path $P_4$ above, $\deg(1)=1,\; \deg(2)=2,\; \deg(3)=2,\; \deg(4)=1$, so

$$
D(P_4) = \operatorname{diag}(1, 2, 2, 1) = \begin{pmatrix}
1 & 0 & 0 & 0 \\
0 & 2 & 0 & 0 \\
0 & 0 & 2 & 0 \\
0 & 0 & 0 & 1
\end{pmatrix}.
$$

---

## 2. Properties of the Adjacency Matrix

### 2.1 Walks and Powers of $A$ (Theorem 9.1)

The single most important property linking algebra to graph structure is that powers of $A$ count walks.

> [!abstract] Theorem 9.1 (Walk Counting)
> Let $G = (V, E)$ be a simple graph with adjacency matrix $A$. For any $k \ge 1$, the entry $(A^k)_{ij}$ equals the **number of walks of length $k$** from vertex $v_i$ to vertex $v_j$.

*Proof by induction on $k$.*

- **Base case $k = 1$:** $A_{ij} = 1$ iff $\{v_i, v_j\} \in E$, i.e., there is exactly one walk of length 1 from $i$ to $j$ (the edge itself), and 0 otherwise. ✓
- **Inductive step:** Assume the claim holds for $k$. Then
  $$
  (A^{k+1})_{ij} = \sum_{t=1}^{n} (A^k)_{it} \cdot A_{tj}.
  $$
  By the induction hypothesis, $(A^k)_{it}$ counts walks of length $k$ from $i$ to $t$. Multiplying by $A_{tj}$ selects those walks where the last step goes $t \to j$. Summing over all intermediate vertices $t$ gives the total number of walks of length $k+1$ from $i$ to $j$. ∎

> [!example] Walk Counting on a 3-Regular Graph
> Consider the complete graph $K_4$, which is **3-regular** (every vertex has degree 3):
>
> ```mermaid
> graph LR
>     subgraph K4["K₄ (3-regular)"]
>         direction LR
>         1((1)) --- 2((2))
>         1 --- 3((3))
>         1 --- 4((4))
>         2 --- 3
>         2 --- 4
>         3 --- 4
>     end
> ```
>
> $$
> A(K_4) = \begin{pmatrix}
> 0 & 1 & 1 & 1\\
> 1 & 0 & 1 & 1\\
> 1 & 1 & 0 & 1\\
> 1 & 1 & 1 & 0
> \end{pmatrix}
> $$
>
> Compute $A^2$:
>
> $$
> A^2 = \begin{pmatrix}
> 3 & 2 & 2 & 2\\
> 2 & 3 & 2 & 2\\
> 2 & 2 & 3 & 2\\
> 2 & 2 & 2 & 3
> \end{pmatrix}
> $$
>
> - **Diagonal** $(A^2)_{ii} = 3$: there are exactly 3 walks of length 2 from $i$ to $i$ (take any neighbor $j\neq i$ and come back: $i \to j \to i$).
> - **Off-diagonal** $(A^2)_{ij} = 2$ ($i \neq j$): there are exactly 2 walks of length 2 between distinct vertices (the two common neighbors; in $K_4$, every pair shares the other two vertices as common neighbors). E.g., $1 \to 3 \to 2$ and $1 \to 4 \to 2$ are the two walks from 1 to 2.

### 2.2 Trace Identities

The trace of $A$ and its powers encodes basic graph invariants.

| Identity | Derivation |
|:---------|:-----------|
| $\operatorname{tr}(A) = 0$ | Simple graph has no loops ⇒ $A_{ii}=0$ for all $i$. |
| $\operatorname{tr}(A^2) = 2|E|$ | $(A^2)_{ii} = \sum_j A_{ij}A_{ji} = \sum_j A_{ij}^2 = \deg(v_i)$, so $\operatorname{tr}(A^2) = \sum_i \deg(v_i) = 2|E|$. |
| $\operatorname{tr}(A^3) = 6 \times (\# \text{ of triangles})$ | $(A^3)_{ii}$ counts closed walks of length 3, each triangle contributes 6 walks (3 starting points × 2 directions). |

### 2.3 Regular Graphs

**Theorem (Regular Graph Eigenvalue).** If $G$ is a **$k$-regular graph** (every vertex has degree $k$), then:

1. $k$ is an eigenvalue of $A$ with eigenvector $\mathbf{1} = (1, 1, \dots, 1)^{\sf T}$.
2. $|\lambda| \le k$ for every eigenvalue $\lambda$ of $A$.
3. $G$ is connected iff $k$ is a **simple** eigenvalue (multiplicity 1).

*Proof.* For a $k$-regular graph, each row of $A$ sums to $k$, so $A \mathbf{1} = k \mathbf{1}$. The remaining claims follow from the Perron–Frobenius theorem (see §3.3). ∎

---

## 3. Eigenvalues of the Adjacency Matrix (Griffin §9.2)

### 3.1 The Spectrum

**Definition (Spectrum).** Let $A$ be the adjacency matrix of $G$. The multiset of eigenvalues $\{\lambda_1, \lambda_2, \dots, \lambda_n\}$ of $A$ (including multiplicities) is called the **spectrum** of $G$, denoted $\operatorname{Sp}(G)$.

For undirected graphs, $A$ is **real symmetric**, so:
- All eigenvalues are real numbers.
- $A$ is diagonalizable by an orthogonal matrix ([[Linear_Algebra/Spectral Theorem]]).
- There exists an orthonormal basis of eigenvectors.

### 3.2 Spectral Radius and Bounds

**Definition (Spectral Radius).** The **spectral radius** of $G$ is the maximum absolute eigenvalue:

$$
\rho(G) = \max_{i} |\lambda_i|.
$$

**Theorem (Bounds on Spectral Radius).** For any graph $G$ with minimum degree $\delta(G)$ and maximum degree $\Delta(G)$:

$$
\delta(G) \le \rho(G) \le \Delta(G).
$$

Moreover, if $G$ is connected, then $\rho(G) < \Delta(G)$ **unless** $G$ is regular (in which case $\rho(G) = \Delta(G) = k$).

> [!example] Eigenvalue Distribution of $C_4$
> The 4-cycle $C_4$ has adjacency matrix:
>
> $$
> A(C_4) = \begin{pmatrix}
> 0 & 1 & 0 & 1\\
> 1 & 0 & 1 & 0\\
> 0 & 1 & 0 & 1\\
> 1 & 0 & 1 & 0
> \end{pmatrix}
> $$
>
> Its eigenvalues are $\{2, 0, 0, -2\}$. Here $\delta(G)=\Delta(G)=2$, so $\rho(G)=2 = \Delta(G)$ (regular graph).
>
> ```mermaid
> xychart-beta
>     title "Spectrum of C₄: {2, 0, 0, -2}"
>     x-axis ["-2", "0", "2"]
>     y-axis "Multiplicity" 0 --> 2
>     bar [1, 2, 1]
> ```
>
> The spectrum is symmetric about 0 — $C_4$ is bipartite (see §4.2).

### 3.3 Perron–Frobenius Theorem

The **Perron–Frobenius theorem** is the cornerstone of spectral graph theory. It governs the spectral properties of nonnegative matrices and, by extension, adjacency matrices of connected graphs.

> [!abstract] Perron–Frobenius Theorem
> Let $A$ be an $n \times n$ **nonnegative** ($A_{ij} \ge 0$) and **irreducible** matrix. Then:
>
> 1. **Spectral radius is an eigenvalue:** $\rho(A) > 0$ is an eigenvalue of $A$.
> 2. **Simplicity:** $\rho(A)$ is a **simple eigenvalue** (algebraic multiplicity 1).
> 3. **Positive eigenvector:** There exists an eigenvector $x > 0$ (all entries strictly positive) such that $A x = \rho(A) x$.
> 4. **Domination:** For any eigenvalue $\lambda$ of $A$, $|\lambda| \le \rho(A)$.
> 5. **Cyclicity:** If $A$ has $h$ eigenvalues of modulus $\rho(A)$, they are $\rho(A) \cdot e^{2\pi i k / h}$ for $k = 0, 1, \dots, h-1$. The integer $h$ is the **index of imprimitivity**.

> [!note] Why It Matters for Graphs
> For a **connected** graph $G$, the adjacency matrix $A$ is nonnegative and irreducible (irreducibility is equivalent to graph connectivity). Applying Perron–Frobenius:
> - $\rho(G)$ is a simple eigenvalue (the **Perron root** or **Perron–Frobenius eigenvalue**).
> - The Perron eigenvector $x > 0$ is called the **Perron vector**; its entries are positive for every vertex.
> - If $G$ is regular, the Perron vector is $\mathbf{1}$ and $\rho(G)=k$.
> - For a bipartite connected graph, the spectrum is symmetric about 0, and $h=2$ (exactly two eigenvalues have modulus $\rho(G)$: $+\rho(G)$ and $-\rho(G)$).

For a proof, see [[Abstract_Algebra/Group]] for the underlying matrix-theoretic concepts (irreducibility, primitivity).

---

## 4. Spectral Graph Properties

### 4.1 Basic Spectral Invariants

Let $\operatorname{Sp}(G) = \{\lambda_1, \dots, \lambda_n\}$. The following are immediate from trace identities and the definition of eigenvalues:

| Invariant | Formula | Explanation |
|:----------|:--------|:------------|
| Number of eigenvalues | $n = \|V\|$ | $A$ is $n \times n$. |
| Sum of eigenvalues | $\sum_{i=1}^n \lambda_i = 0$ | $\operatorname{tr}(A) = 0$ (no loops). |
| Sum of squares | $\sum_{i=1}^n \lambda_i^2 = 2\|E\|$ | $\operatorname{tr}(A^2) = 2\|E\|$. |
| Sum of cubes | $\sum_{i=1}^n \lambda_i^3 = 6 \times (\# \text{ triangles})$ | $\operatorname{tr}(A^3)$ counts directed 3-cycles. |
| Number of nonzero eigenvalues | $\le \operatorname{rank}(A)$ | Elementary linear algebra. |

### 4.2 Bipartite Graphs and Spectral Symmetry

**Theorem (Bipartite Spectrum).** A graph $G$ is **bipartite** iff its spectrum is **symmetric about 0**: i.e., $\lambda$ is an eigenvalue with multiplicity $m$ iff $-\lambda$ is an eigenvalue with the same multiplicity.

> [!example]
> The cycle $C_4$ is bipartite, with spectrum $\{2, 0, 0, -2\}$. The cycle $C_3$ (triangle) is not bipartite; its eigenvalues $\{2, -1, -1\}$ are not symmetric about 0.

*Proof sketch.* ($\Rightarrow$) If $G$ is bipartite with bipartition $V_1, V_2$, reorder vertices so $V_1$ comes first. Then $A$ has block form $\begin{pmatrix}0 & B \\ B^{\sf T} & 0\end{pmatrix}$. If $(\lambda, u)$ is an eigenpair, then $(-\lambda, u')$ is also an eigenpair where $u'$ flips the sign on one part. ($\Leftarrow$) If the spectrum is symmetric, then $\operatorname{tr}(A^{2k+1}) = 0$ for all $k$, implying no odd cycles ⇒ $G$ is bipartite. ∎

### 4.3 Cospectral Graphs

Two graphs are **cospectral** if they have the same spectrum but are **non-isomorphic**. Cospectrality shows that the spectrum alone does not determine a graph uniquely.

> [!example] A Minimal Cospectral Pair
> The graphs $C_4 \cup K_1$ (a 4-cycle plus an isolated vertex) and $K_{1,4}$ (the star with 4 leaves) are **cospectral** but **non-isomorphic**:
>
> ```mermaid
> graph LR
>     subgraph G1["G₁ = C₄ ∪ K₁"]
>         direction TB
>         c1((1)) --- c2((2))
>         c2 --- c3((3))
>         c3 --- c4((4))
>         c4 --- c1
>         iso((5))
>     end
>     subgraph G2["G₂ = K₁,₄ (Star)"]
>         direction TB
>         center((c)) --- l1((1))
>         center --- l2((2))
>         center --- l3((3))
>         center --- l4((4))
>     end
> ```
>
> Both share the spectrum $\{2, 0, 0, 0, -2\}$ and characteristic polynomial $\lambda^5 - 4\lambda^3$.
>
> | Graph | Components | Structure | Distinguishing invariant |
> |:------|:----------:|:----------|:-------------------------|
> | $C_4 \cup K_1$ | 2 components | One cycle (4 vertices) + isolated vertex | Contains a cycle |
> | $K_{1,4}$ | 1 component | Tree (no cycles) | Bipartite, no cycles |
>
> While they share the same spectrum, they differ in number of components, girth, and diameter — demonstrating that **spectrum ≠ isomorphism**.

### 4.4 Characteristic Polynomial

**Definition.** The **characteristic polynomial** of $G$ is

$$
\phi_G(\lambda) = \det(\lambda I - A) = \lambda^n + c_1 \lambda^{n-1} + c_2 \lambda^{n-2} + \cdots + c_n.
$$

Since $\operatorname{tr}(A)=0$, the coefficient $c_1 = -\operatorname{tr}(A) = 0$. The coefficients have graph-theoretic interpretations via **Sachs' theorem** (or the Harary–Sachs theorem): $c_k$ is determined by elementary subgraphs (disjoint unions of edges and cycles).

For common graphs:

| Graph | Characteristic Polynomial |
|:------|:--------------------------|
| $P_n$ (path) | $\prod_{j=1}^n \bigl(\lambda - 2\cos\frac{j\pi}{n+1}\bigr)$ |
| $C_n$ (cycle) | $\prod_{j=0}^{n-1} \bigl(\lambda - 2\cos\frac{2\pi j}{n}\bigr)$ |
| $K_n$ (complete) | $(\lambda - n+1)(\lambda + 1)^{n-1}$ |
| $K_{a,b}$ (bipartite complete) | $\lambda^{n-2}(\lambda^2 - ab)$ where $n = a+b$ |

---

## 5. Strongly Regular Graphs

Strongly regular graphs (SRGs) are the most constrained class of graphs for which the spectrum is fully determined by four integer parameters.

### 5.1 Definition and Parameters

**Definition (Strongly Regular Graph).** A $k$-regular graph $G$ with $n$ vertices is **strongly regular** with parameters $(n, k, \lambda, \mu)$ — denoted $\operatorname{SRG}(n, k, \lambda, \mu)$ — if:

1. Every pair of **adjacent** vertices has exactly $\lambda$ common neighbors.
2. Every pair of **non-adjacent** (distinct) vertices has exactly $\mu$ common neighbors.

> [!note] Parameter constraints
> For a non-trivial SRG (not complete or empty), the parameters must satisfy:
> - $k(k - \lambda - 1) = (n - k - 1)\mu$ (counting paths of length 2).
> - $0 \le \lambda \le k-1$, $1 \le \mu \le k$.

### 5.2 Eigenvalues of SRGs

The adjacency matrix of an $\operatorname{SRG}(n, k, \lambda, \mu)$ satisfies the quadratic relation:

$$
A^2 = kI + \lambda A + \mu(J - I - A)
$$

This yields three distinct eigenvalues:

| Eigenvalue | Value | Multiplicity |
|:-----------|:------|:-------------|
| $\lambda_1 = k$ (the **regular** eigenvalue) | $k$ | 1 |
| $\lambda_2 = r$ | $\frac{1}{2}\bigl[(\lambda - \mu) + \sqrt{(\lambda - \mu)^2 + 4(k - \mu)}\bigr]$ | $m_r$ |
| $\lambda_3 = s$ | $\frac{1}{2}\bigl[(\lambda - \mu) - \sqrt{(\lambda - \mu)^2 + 4(k - \mu)}\bigr]$ | $m_s$ |

where $r + s = \lambda - \mu$ and $rs = \mu - k$. The multiplicities satisfy:

$$
m_r + m_s = n - 1,\qquad k + m_r r + m_s s = 0.
$$

### 5.3 Example: The Petersen Graph

The **Petersen graph** is the canonical example of a strongly regular graph:

$$
\operatorname{Petersen} = \operatorname{SRG}(10, 3, 0, 1).
$$

- $n = 10$ vertices
- $k = 3$ (3-regular)
- $\lambda = 0$ (adjacent vertices share **no** common neighbors)
- $\mu = 1$ (non-adjacent vertices share exactly **1** common neighbor)

Using the eigenvalue formulas:

$$
r = \frac{1}{2}\bigl[(0-1) + \sqrt{1 + 4(3-1)}\bigr] = \frac{1}{2}[-1 + \sqrt{9}] = 1,
$$
$$
s = \frac{1}{2}\bigl[-1 - 3\bigr] = -2.
$$

Multiplicities: $m_r = 5$, $m_s = 4$. Thus the spectrum of the Petersen graph is:

$$
\operatorname{Sp}(\text{Petersen}) = \{3^1,\; 1^5,\; -2^4\},
$$

where superscripts indicate multiplicities.

> [!note] Uniqueness
> The Petersen graph is the **unique** $\operatorname{SRG}(10,3,0,1)$ up to isomorphism. Strongly regular parameters do not always determine a unique graph — there exist non-isomorphic SRGs with the same parameters, called **switching-equivalent** graphs.

---

## 6. 符号速查 (Symbol Reference)

| Symbol | Meaning | First Used |
|:-------|:--------|:-----------|
| $A$ | Adjacency matrix (size $n \times n$) | §1.1 |
| $M$ | Incidence matrix (size $n \times m$) | §1.2 |
| $D$ | Degree matrix (diagonal) | §1.3 |
| $\operatorname{Sp}(G)$ | Multiset of eigenvalues of $A(G)$ | §3.1 |
| $\rho(G)$ | Spectral radius, $\max_i \|\lambda_i\|$ | §3.2 |
| $\delta(G), \Delta(G)$ | Min degree, max degree | §3.2 |
| $\phi_G(\lambda)$ | Characteristic polynomial $\det(\lambda I - A)$ | §4.4 |
| $\operatorname{SRG}(n, k, \lambda, \mu)$ | Strongly regular graph parameters | §5.1 |
| $\mathbf{1}$ | All-ones vector $(1,1,\dots,1)^{\sf T}$ | §2.3 |
| $J$ | All-ones matrix (every entry $=1$) | §5.2 |

---

## 7. 相关链接 (Related Notes)

- [[Linear_Algebra/Eigenvalues and Eigenvectors]] — fundamental eigenvalue theory
- [[Linear_Algebra/Spectral Theorem]] — real symmetric matrix diagonalization
- [[Linear_Algebra/Diagonalization]] — matrix diagonalization in general
- [[Abstract_Algebra/Group]] — Perron–Frobenius concepts: irreducible matrices and primitivity
- [[Graph - Laplacian & Spectral Clustering]] — Laplacian matrix and spectral clustering
- [[Graph - Centrality Measures]] — eigenvector centrality uses the Perron vector
- [[Graph - Isomorphism & Automorphism]] — spectrum as a graph invariant
- [[Graph - Walks, Cycles & Connectivity]] — walks, trails, and connectedness
