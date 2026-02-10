---
tags:
title: Gravitation Problems
created: 2026-02-10T19:43:00
modified:
---
# Gravitation Problems

## 1. IMP Three-Body Gravitation
>计算一个三体系统的引力势能：
- $\textbf{行星}（Planet）$：质量 $M_P$
- $\textbf{月球}（Moon）$：质量 $M_m$，位于行星右侧，距离行星中心为 $r$
- $\textbf{恒星}（Star）$：质量 $M_s$，位于月球右侧，与行星中心的距离为 $D$

![[three_body_gravity_problem.png]]
关键知识点在于引力势能公式，其推导过程见[[Gravitational Potential Energy]]：
对于两个质量分别为 $m_1$、$m_2$，相距为 $d$ 的质点，其引力势能为：
$$U = -\frac{G m_1 m_2}{d}$$

多体系统的总引力势能等于所有$**无序对**的引力势能之和（每对只计算一次）。
对于 $n$ 个质点的系统，共有 $\dfrac{n(n-1)}{2}$ 对相互作用。
在题目中：
- 行星 $\leftrightarrow$ 月球 $U_{Pm} = -\dfrac{G M_P M_m}{r}$
- 行星 $\leftrightarrow$ 恒星$U_{Ps} = -\dfrac{G M_P M_s}{D}$ 
- 月球 $\leftrightarrow$ 恒星$U_{ms} = -\dfrac{G M_m M_s}{D-r}$
$$U_{\text{total}} = U_{Pm} + U_{Ps} + U_{ms}$$
$$U_{\text{total}} = -\frac{G M_P M_m}{r} - \frac{G M_P M_s}{D} - \frac{G M_m M_s}{D-r}$$
