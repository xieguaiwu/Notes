---
tags:
  - MachineLearning
  - Architecture
  - SequenceModel
  - Math
  - LinearAlgebra
  - 定义性
  - ComputerScience
title: CTM - Mamba and S6 SSM
created: 2026-06-01
---

# CTM - Mamba and S6 SSM

*选择性状态空间模型 (Selective SSM / S6) 的理论原理与工程实现*

> [!abstract] 本文定位
> 本文阐述**选择性状态空间模型 (Selective State Space Model, S6)** 的核心理论——从标准 LTI SSM 到选择性 SSM 的演进、数学基础、扫描策略以及数值稳定性考量。CTM 项目的纯 PyTorch 实现作为案例，展示这些理论如何落地为实际代码。

## 1. 选择性状态空间模型——核心理论

### 从标准 SSM 到选择性 SSM

**标准 SSM：线性时不变系统 (LTI)**

状态空间模型将序列建模问题形式化为一个隐含状态 $h_t$ 的递推过程：

$$h_t = \bar{A} h_{t-1} + \bar{B} x_t, \quad y_t = C h_t + D x_t$$

其中 $\bar{A}, \bar{B}, C$ 是**与输入无关的固定参数矩阵**。这种线性时不变 (Linear Time-Invariant, LTI) 特性意味着：无论输入 $x_t$ 是什么，系统的动态行为完全由固定的参数决定。

LTI SSM 的根本局限：**无法根据输入内容选择性关注或忽略信息**。在处理文本时，LTI SSM 无法"记住"重要词汇同时"遗忘"停用词——它对所有输入一视同仁。

**选择性 SSM：线性时变系统**

Mamba (Gu & Dao, 2023) 的核心贡献是将 SSM 从 LTI 变为**线性时变 (Linear Time-Varying)** 系统：

$$h_t = \bar{A}_t \odot h_{t-1} + \bar{B}_t \cdot x_t, \quad y_t = C_t \cdot h_t + D \odot x_t$$

其中 $\bar{A}_t, \bar{B}_t, C_t$ 都是当前输入 $x_t$ 的函数。这个变化带来了根本性的能力提升：

| LTI SSM (传统) | 选择性 SSM (Mamba S6) |
|---------------|----------------------|
| 对所有输入使用相同的状态转移 | 根据输入内容决定如何更新状态 |
| 无法实现"选择性记忆" | 可以决定哪些信息保留、哪些遗忘 |
| 在内容感知任务上表达力有限 | 达到与 Transformer 相当的上下文感知能力 |
| 计算可高度并行 (卷积表示) | 需要顺序或关联扫描 (失去卷积表示) |

从 LTI 到选择性 SSM 的转变是**用并行性换取表达力**。LTI SSM 可以利用卷积表示实现训练并行化，而选择性 SSM 由于参数随输入变化，失去了这一特性，需要通过其他方式恢复并行性。

### 数学基础

**离散化 (Discretization)**

SSM 的核心是一个连续时间系统，需要离散化后才能应用于数字计算。最常用的方法是零阶保持 (Zero-Order Hold, ZOH)：

$$\bar{A} = \exp(\Delta A), \quad \bar{B} = (\exp(\Delta A) - I) A^{-1} B$$

其中 $\Delta$ 是步长参数 (step size)，控制离散化的时间分辨率。

在 Mamba S6 中，$\Delta$ 本身也是输入相关的：

$$\Delta_t = \text{Softplus}(x_t @ W_{\Delta} + b_{\Delta})$$

这意味着模型可以**根据输入内容自适应地调整时间分辨率**——对需要精细建模的输入使用小步长，对不重要内容使用大步长（近似忽略）。

**S6 参数化**

S6 架构的核心是实现选择性所需的输入依赖参数：

$$\bar{A}_t = \exp(\Delta_t \cdot A_{\text{log}})$$
$$B_t = x_t @ W_B, \quad C_t = x_t @ W_C$$

关键设计要点：

- $A$ 矩阵通过 $A_{\text{log}}$ (负对数) 参数化，确保 $\bar{A} \in (0, 1)$，这是系统稳定性的必要条件
- $\Delta$ 使用低秩分解：$d_{\text{inner}} \to dt_{\text{rank}} \to d_{\text{inner}}$，将参数量从 $O(d_{\text{inner}}^2)$ 降至 $O(d_{\text{inner}} \cdot dt_{\text{rank}})$
- $B$ 和 $C$ 通过独立的投影矩阵生成，分别控制输入选择和输出选择

> [!note] 理论连接
> S6 的选择性机制可以看作是将 **Attention 的内容感知能力**注入了 RNN 框架。Transformer 通过 $QK^T$ 实现内容感知的交互，S6 通过输入依赖的 $\Delta, B, C$ 实现类似的感知能力，但保持了 $O(T)$ 线性复杂度。

### 扫描策略 (Scan Strategies)

SSM 的递推结构 $h_t = f(h_{t-1}, x_t)$ 在数学上是一个前缀和 (prefix sum) 问题，这决定了可用的扫描策略。

**顺序扫描 (Sequential Scan)**

最直接的实现方式：显式 for 循环。

```python
for t in range(T):
    h = h * A_bar[:, t] + B_bar[:, t] * x_conv[:, t]
    y_t = h @ C_proj[:, t] + D * x_conv[:, t]
```

| 属性 | 值 |
|------|-----|
| 时间复杂度 | $O(T)$ 顺序 |
| 空间复杂度 | $O(1)$ (不保存中间结果) |
| 适用设备 | CPU / 串行计算 |
| 优点 | 实现简单、内存占用低 |
| 缺点 | 无法并行、GPU 利用率低 |

**并行关联扫描 (Parallel Associative Scan)**

利用前缀和的**结合律**，将 $O(T)$ 串行操作转化为 $O(\log T)$ 并行操作。Mamba-2 风格的计算公式：

$$h_t = \text{cp}[t] \cdot \sum_{k=1}^{t} \frac{\bar{B}_k \cdot x_k}{\text{cp}[k]}$$

其中 $\text{cp}[t] = \prod_{i=1}^{t} \bar{A}_i$ 是累积乘积 (cumulative product)。

```python
cp = torch.cumprod(A_bar, dim=1)          # (B, T, D), 累积乘积
weights = 1.0 / cp                        # 倒数
sum_term = torch.cumsum(B_bar_x * weights, dim=1)  # 累积求和
h = cp * sum_term                         # 最终隐藏状态
```

| 属性 | 值 |
|------|-----|
| 时间复杂度 | $O(T)$ 总操作，$O(\log T)$ 并行深度 |
| 空间复杂度 | $O(T)$ (需要保存所有中间结果) |
| 适用设备 | GPU (高并行度) |
| 优点 | 训练速度快、GPU 利用率高 |
| 缺点 | 内存占用大、数值稳定性更敏感 |

**策略对比**

| 策略 | 时间 (顺序) | 时间 (并行) | 内存 | 数值稳定性 |
|------|------------|------------|------|-----------|
| 顺序扫描 | $O(T)$ | — | $O(1)$ | 稳健 (逐步更新) |
| 关联扫描 | $O(T)$ | $O(\log T)$ | $O(T)$ | 敏感 ($1/\text{cp}$ 除零风险) |

> [!warning] 数值稳定性关键
> 并行关联扫描中的 $1/\text{cp}$ 操作是数值不稳定的主要来源。当 $\bar{A}_t$ 接近 1 时，累积乘积 $\text{cp}[t]$ 收敛缓慢。当 $\bar{A}_t$ 包含零或极小的值时，$\text{cp}[t]$ 的倒数可能溢出。实践中需要 clamp 或 epsilon 保护。

### 数值稳定性考量

任何 SSM 实现都绕不开三个数值问题。

| 问题 | 原因 | 缓解方案 |
|------|------|---------|
| **离散化稳定性** | $\Delta$ 过大导致 $\bar{A} = \exp(\Delta A)$ 接近 1 | Softplus 约束 $\Delta$ 为正，$A_{\text{log}}$ 初始化为负 |
| **梯度衰减/爆炸** | 深层递推中隐藏状态的指数行为 | 确保 $\bar{A} \in (0, 1)$ (通过 $A_{\text{log}}$ 参数化) |
| **关联扫描除零** | 累积乘积接近零时倒数溢出 | Epsilon guard ($\epsilon = 10^{-8}$) 或 clamp 操作 |

$$A_{\text{log}} = \text{nn.Parameter}(\text{torch.randn}(D, N))$$
$$\bar{A} = \exp(-\exp(A_{\text{log}}) \cdot \Delta) \in (0, 1)$$

这种双重指数参数化确保了 $\bar{A}$ 始终处于 $(0, 1)$ 区间，从根本上防止了梯度爆炸。

---

## 2. Case Study: CTM 纯 PyTorch 实现

CTM 项目实现了上述理论的一个完整参考实现，且**不依赖任何自定义 CUDA 内核**——全部基于 PyTorch 原语。

### 架构设计：模板方法模式

CTM 使用模板方法 (Template Method) 模式管理两个扫描变体：

```
BaseMambaBlock.forward():
    Step 1: Input Projection (2x expansion)     ← 共享
    Step 2: Causal Depthwise Conv1D              ← 共享
    Step 3: Selective Parameters (Δ, B, C)       ← 共享
    Step 4: Scan (abstract method)               ← 子类实现

MambaBlock:          MambaBlockParallel:
  for t in range(T)    cp = cumprod(A_bar)
  ...                   h = cp * cumsum(...)
```

这种设计的好处：确保两个变体共享完全相同的参数化方式（$\Delta$ 低秩分解、$A_{\text{log}}$ 初始化、卷积配置），唯一的差异在扫描策略。

### 完整计算步骤

```
输入 x: (B, T, d_model)

Step 1  输入投影
z = x @ W_in                              → (B, T, 2 * d_inner)
z1, z2 = split(z)                         → SSM 分支 / 门控分支

Step 2  因果卷积 (Causal Conv1D)
z1_padded = pad(z1, (d_conv - 1, 0))      → 左填充保证因果性
x_conv = SiLU(conv1d(z1_padded))           → 深度可分离卷积

Step 3  选择性参数
Δ = Softplus(x_conv @ W_down @ W_up)      → 低秩分解
B = x_conv @ W_B                           → 输入选择
C = x_conv @ W_C                           → 输出选择
Ā = exp(Δ · A)                             → 离散化

Step 4  扫描 (子类决定)
# MambaBlock: 顺序扫描
for t in range(T):
    h = h * Ā[:, t] + B[:, t] * x_conv[:, t]

# MambaBlockParallel: 关联扫描
cp = cumprod(Ā, dim=1)
h = cp * cumsum(B · x_conv / cp, dim=1)

Step 5  输出门控
y = h @ C + D * x_conv                     → SSM 输出
y = y * SiLU(z2)                           → 门控 (类似 GLU)
```

### 设计决策与原理

| 决策 | 选择 | 原理 |
|------|------|------|
| **内核选择** | `nn.Parameter` + `F.conv1d` 而非 `nn.Conv1d` | 对权重初始化和更新有完全控制权 |
| **低秩分解** | $d_{\text{inner}} \to dt_{\text{rank}} \to d_{\text{inner}}$ | 将 $\Delta$ 参数量从 $O(d^2)$ 降至 $O(d \cdot k)$ |
| **$A$ 参数化** | `A_log` 负对数存储 | 双重指数确保 $\bar{A} \in (0, 1)$ |
| **NaN 检测** | 每步扫描后检查 `torch.isnan` | 训练早期数值不稳定时及时恢复 |
| **深度可分离** | `groups = d_inner` 的 Conv1d | 降低参数量，通道间无交叉污染 |
| **采集方式** | `torch.stack` 收集时间步 | 保留完整计算图，支持反向传播 |

### 关键代码示例 (顺序扫描)

```python
# MambaBlock.forward 核心片段
for t in range(T):
    h = h * A_bar[:, t] + B_bar[:, t] * x_conv[:, t]
    y_t = h @ C_proj[:, t].transpose(-2, -1) + D * x_conv[:, t]
    ys.append(y_t)

y = torch.stack(ys, dim=1)         # (B, T, D)
y = self.check_nan(y, "ssm_scan")  # 数值稳定性守卫
```

> [!tip] 实现启示
> CTM 的纯 PyTorch 实现证明了 S6 SSM **不需要自定义 CUDA 内核即可正常工作**。对于快速原型验证，纯 PyTorch 实现完全足够；对于生产环境中极致性能，才需要优化到 CUDA。

---

## 3. Key Takeaways

### 何时使用选择性 SSM (S6)

- **需要线性复杂度的序列建模**：相比于 Transformer 的 $O(T^2)$，SSM 的 $O(T)$ 在长序列上优势明显
- **长序列场景**：当序列长度超过 1024 时，SSM 的优势开始显现
- **内容感知的序列处理**：需要根据输入内容选择性保留或遗忘信息
- **硬件受限环境**：S6 不需要注意力矩阵，显存占用远低于同等规模的 Transformer

### 常见陷阱

| 陷阱 | 表现 | 解决方案 |
|------|------|---------|
| **数值不稳定** | 关联扫描中 NaN 或 inf | 添加 epsilon guard + NaN 检测守卫 |
| **过度并行化** | 小批量下关联扫描反而比顺序扫描慢 | 根据序列长度和批量大小自动选择扫描策略 |
| **$\Delta$ 饱和** | $\Delta$ 始终趋近于 0 或始终过大 | 监控 $\Delta$ 分布，调整初始化或 Softplus 的 beta |
| **门控退化** | 门控分支主导输出，SSM 分支被忽略 | 正则化门控参数，或前期固定门控为 1.0 |

### 相关概念

- [[Mamba]] — Mamba 通用理论与参数表
- [[LSTM]] — 与 S6 的对比：门控机制 vs 选择性机制
- [[Transformer]] — $O(T^2)$ 注意力 vs $O(T)$ SSM
- [[State Space Model]] — 经典卡尔曼滤波与深度 SSM
- [[CTM - StockModel Architecture]] — S6 在完整模型管线中的位置
- [[CTM - Architecture Patterns]] — BaseMambaBlock 中的模板方法模式
