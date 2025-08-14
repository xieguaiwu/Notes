# Semantic Considerations On Modal Logic
tags: Kripke ModalLogic

[[Kripke]]
[[Modal Logic]]
**量化模型**（Quantificational model）形式定义：

**模型结构**（Model structure, m.s.）：有序三元组 (G,K,R)(G,K,R)，其中：

- KK：**可能世界集合**（set of possible worlds）
    
- RR：KK上的**自反关系**（reflexive relation）
    
- G∈KG∈K：**现实世界**（real world）


**直观解释**：

- H1RH2H1​RH2​ 表示世界 H2H2​ **相对于** H1H1​ 可能（即 H2H2​ 中所有真命题在 H1H1​ 中可能）。
    
- **自反性**（reflexivity）的合理性：任一世界 HH 相对于自身必然可能。


**附加要求与对应系统**：

- **S4-m.s.**：RR **传递**（transitive）
    
- **布劳威尔-m.s.**：RR **对称**（symmetric）
    
- **S5-m.s.**：RR **等价关系**（equivalence relation）
    
- **M-m.s.**：无限制
[[Reflexive Relation]]

**模型**（Model）定义：

- 函数 φ(P,H)φ(P,H) 为原子公式 PP 在世界 H∈KH∈K 赋真值 T/FT/F。
    
- **复合公式真值归纳定义**：
    
    - φ(A∧B,H)=Tφ(A∧B,H)=T 当且仅当 φ(A,H)=φ(B,H)=Tφ(A,H)=φ(B,H)=T
        
    - φ(∼A,H)=Tφ(∼A,H)=T 当且仅当 φ(A,H)=Fφ(A,H)=F
        
    - **必然性**：φ(□A,H)=Tφ(□A,H)=T 当且仅当对所有满足 HRH′HRH′ 的 H′H′，φ(A,H′)=Tφ(A,H′)=T
        

**完备性定理**（Completeness theorem）：  
⊢A⊢A 在M/S4/S5/布劳威尔系统当且仅当对任意对应模型结构 (G,K,R)(G,K,R) 上的模型 φφ，有 φ(A,G)=Tφ(A,G)=T。

> （证明见[11]*Kripke Semantical Analysis of Modal Logic*；此定理将语法可证性等价于语义有效性。）
- **量化模型**（Quantificational model）形式定义：  
- 令 $U = \bigcup_{\mathbf{H} \in \mathbf{K}} \psi(\mathbf{H})$ 为**全域个体集**。  
- 函数 $\varphi(P^n, \mathbf{H})$ 为 $n$ 元谓词字母指定：  
  - $n=0$：真值 $T/F$  
  - $n \geq 1$：$\mathbf{U}^n$ 的子集（即谓词在 $\mathbf{H}$ 中的**外延**）  
- **原子公式真值**：对赋值 $a_1,\ldots,a_n \in U$，  
  $\varphi(P^n(x_1,\ldots,x_n), \mathbf{H}) = T$ 当且仅当 $(a_1,\ldots,a_n) \in \varphi(P^n, \mathbf{H})$  
- **量词语义**：$\varphi((x)A(x), \mathbf{H}) = T$ 当且仅当对 **所有 $a \in \psi(\mathbf{H})$**，$\varphi(A(x), \mathbf{H}) = T$  
  > （量化仅针对 $\mathbf{H}$ 中存在的个体）
> 