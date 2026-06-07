---
title: Modal Logic - Kripke Semantics
tags:
  - Logic
  - ModalLogic
  - 定义性
  - 基本原理
created: 2026-06-03
---

# Modal Logic - Kripke Semantics

> [!abstract] 概述
> **克里普克语义学**（可能世界语义学）是模态逻辑的标准语义框架。其核心概念是可能世界集合 $W$ 和可达关系 $R \subseteq W \times W$，用于定义 $\Box$ 和 $\Diamond$ 的真值条件。该语义框架是理解模态坍塌（[[Modal Logic - Modal Collapse]]）必要的前置知识。

## 核心定义

- **框架** $\mathcal{F} = \langle W, R \rangle$
- **模型** $\mathcal{M} = \langle W, R, V \rangle$，其中 $V$ 是赋值函数
- $\Box\varphi$ 在 $w$ 真 $\iff \forall v(wRv \to \varphi[v])$
- $\Diamond\varphi$ 在 $w$ 真 $\iff \exists v(wRv \land \varphi[v])$

## 相关概念

- [[Modal Logic - Possible Worlds|可能世界]]
- [[Modal Logic - Axiom Systems|模态逻辑公理系统]]
- [[Modal Logic - Modal Collapse|模态坍塌]]
