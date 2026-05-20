---
tags:
  - PhilosophyOfLogic
  - PossibleWorlds
  - Kripke
  - Lewis
  - Quine
  - Essentialism
  - Logic
title: Philosophy of Logic
created: 2026-05-20
modified: 2026-05-20
---

[[Modal Logic]]
[[克里普克模态语义递归定义]]
[[Kripke]]
[[Completeness in S5]]
[[Intuitionistic Logic]]

# 逻辑哲学

> [!quote]
> "A possible world is a way things could have been." -- Saul Kripke

## 可能世界的本体论

可能世界语义学引发了关于可能世界**本体论地位**的争论：

| 立场 | 代表人物 | 核心主张 |
|------|----------|----------|
| **极端实在论** | David Lewis | 可能世界与真实世界在本体论上对等，都是具体的时空整体 |
| **温和实在论/实际主义** | Saul Kripke | 可能世界是**抽象的状态描述**，不是另一个宇宙 |
| **组合主义** |  | 可能世界是现实世界中基本元素的重新组合 |

Lewis 的观点最为激进：所有可能世界都是真实存在的，现实世界只是"我们这个"可能世界。Kripke 则强调可能世界是规定性的（我们**规定**一种情景），而非发现性的。

> [!note]
> 模态逻辑的克里普克语义本身在数学上对本体论立场中立——你既可以做实在论者也可以做形式主义者，只要形式框架一致。

## 跨界同一性问题 (Trans-World Identity)

如果同一个体存在于多个可能世界，如何确定两个世界中的个体是"同一个"？

```mermaid
flowchart LR
    A["世界 w1<br/>亚里士多德是哲学家"] -- 同一关系？ --> B["世界 w2<br/>亚里士多德是诗人"]
    B -- 同一关系？ --> C["世界 w3<br/>亚里士多德从未出生"]
```

- **跨界同一性 (Trans-World Identity)**：个体可以**跨越**不同世界而保持同一（Kripke 立场）
- **对应体理论 (Counterpart Theory)**：个体只能存在于一个世界，其他世界中只有它的"对应体"（Lewis 立场）

## 本质主义 (Essentialism)

有些属性是个体**必然具有**的（本质属性），有些是偶然的。

Kripke 在《命名与必然性》中论证：
- **起源本质论**：一个个体的起源是其本质（例如：这张桌子不可能由不同的木头制成）
- **物质构成本质论**：物质来源是其本质

> [!quote]
> "If a material object has its origin from a certain hunk of matter, it could not have had its origin from any other matter." -- Kripke

## 严格指示词 (Rigid Designators)

专名（如"亚里士多德"）是**严格指示词**：在所有可能世界中指称同一个对象。而摹状词（如"亚历山大的老师"）是非严格的，在不同世界可能指称不同的人。

这解释了为何同一陈述可以是**后天必然真理**：例如"长庚星 = 启明星"是后天发现的，但一旦成立则在所有可能世界中成立。

## 奎因的批评

W.V.O. Quine 是模态逻辑最著名的批评者，主要论点：

1. **本质主义的承诺**：量化模态逻辑 ($\exists x \Box P(x)$) 承诺了本质主义，但本质主义在奎因看来是"暧昧的形上学"
2. **指称暧昧性**：在模态语境中，代入共指词项会失效（违反外延性原则）
3. **Aristotelian essentialism**：量化模态逻辑要求区分一个对象的本质属性与偶然属性，奎因认为这种区分无法成立

> [!warning]
> Quine 的批评虽然在 20 世纪中期极具影响力，但 Kripke 的严格指示词理论在很大程度上回应了这些批评。目前量化模态逻辑已是成熟的逻辑分支。
