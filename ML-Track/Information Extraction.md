---
tags:
  - MachineLearning
  - 定义性
title: Information Extraction
created: 2025-12-28T10:41:00
modified:
---
# Information Extraction
## 1. Def
从自然语言文本（**非结构化**文本）当中抽取指定事实信息，形成**结构化**数据输出
信息图谱$\Rightarrow$知识图谱

形如knowledge ontology (Thomas R. Gruber, 1993)，Information Extraction的基本元素是entity

## 2. Indicators
- **Precision**：$$\frac{正确知识数目}{所有知识数目}$$
- **Recall**：$$\frac{抽取出的正确数目}{正确的知识数目}$$
- **F值**：即Precision和Recall的加权几何平均值$$F=\frac{(1+\beta^2)\times\text{Recall}\times\text{Precision}}{\text{Recall}+\beta^2\times \text{Precision}}$$
$\beta$是recall&precision的相对权重
- $\beta>1\Rightarrow\text{Precision}$
- $\beta<1\Rightarrow\text{Recall}$

## 3. Methodology
### 3.1
- **实体名知识**：命名的规律性
- **上下文知识**
- **世界/常识知识**：在识别高歧义的entities时，这点或许是必要的

### 3.2 Named Entity Recognition (NER)
|                     | Regular NER               | Open NER                              |
| ------------------- | ------------------------- | ------------------------------------- |
| Typical Categlories | Person, Locations etc.    | Movie, Song etc.                      |
| Name Regularity     | 强规律entity type            | 无规律或弱规律entity type                    |
| Mention Coverage    | High mention Coverage     | New unseen mentions                   |
| Context Pattern     | Decent training instances | Fully-annotated training data is rare |

### 3.3 Different Methods
![[entity recognition methods.png]]

### 3.4 Traditional Machine Learning Methods
Hidden Markov Model/Conditional Random Field

- HMM: 只有两个矩阵建模，其作为**生成式模型**无法利用复杂特征
- CRF: 作为**判别式模型**，可以使用任意复杂特征，每个位置只有一个矩阵，其元素由权重计算和特征函数得到

如下图所示：
![[HMM vs. ME CRF in info extraction.png]]
对于其他的方法，见下图：
![[HMM-ME-CRF in info extraction.png]]

---

#### 3.41 CRF识别案例
见下图所示
![[CRF entity recognition example.png]]

---

传统方法缺乏泛化性
