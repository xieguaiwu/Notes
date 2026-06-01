---
tags:
  - Python
  - Dataclasses
  - DataModeling
  - TypeSystem
  - 基础
  - 概念性
title: Python - Dataclasses
created: 2026-06-01
---

# Python - Dataclasses — Efficient Data Modeling

> [!abstract] Overview
> Dataclasses 是 Python 3.7 引入的 `@dataclass` 装饰器，用于自动生成 `__init__`、`__repr__`、`__eq__` 等 boilerplate 方法。它们让代码更简洁、更类型安全，特别适合数据载体（data carrier）场景——即主要职责是存储数据而非复杂行为的类。CTM 大量使用 dataclasses 管理训练结果、交易订单和账户状态。

Related: [[Python - Type Hints]] | [[Python - Generators]]

---

## 1. Dataclasses — Core Principles

### What & Why

传统 Python 的数据类需要手动编写大量模板代码：

```python
class TrainingResult:
    def __init__(self, best_sharpe, epochs_run, window_metrics):
        self.best_sharpe = best_sharpe
        self.epochs_run = epochs_run
        self.window_metrics = window_metrics

    def __repr__(self):
        return f"TrainingResult(best_sharpe={self.best_sharpe}, ...)"
```

`@dataclass` 自动完成这一切。等价代码缩减为：

```python
from dataclasses import dataclass

@dataclass
class TrainingResult:
    best_sharpe: float
    epochs_run: int
    window_metrics: list[dict]
```

Dataclass 自动生成的方法包括：

| 方法 | 作用 | 定制方式 |
|------|------|---------|
| `__init__` | 接收类型标注字段作为参数 | 字段顺序 = 类体中声明顺序 |
| `__repr__` | 输出 `ClassName(field1=val1, field2=val2, ...)` | `@dataclass(repr=False)` 禁用 |
| `__eq__` | 逐字段比较 | `@dataclass(order=True)` 还生成 `__lt__`/`__le__`/`__gt__`/`__ge__` |
| `__hash__` | 默认 None（可变对象不可哈希） | `frozen=True` 时自动生成 |

### field() — Fine-Grained Field Control

`field()` 函数提供细粒度字段控制：

```python
from dataclasses import field

@dataclass
class TrainingResult:
    best_sharpe: float
    epochs_run: int
    window_metrics: list[dict] = field(default_factory=list)
    ctm_sharpe: float | None = field(default=None)
    gbdt_ic: float | None = field(default=None)

    # 排除字段：不参与 __init__ 和 __repr__
    _internal_id: str = field(init=False, repr=False)
```

关键 `field()` 参数：

| 参数 | 用途 | 示例 |
|------|------|------|
| `default` | 不可变默认值 | `default=0` |
| `default_factory` | 可变默认值（函数/类型） | `default_factory=list` |
| `init=False` | 不作为 init 参数 | 计算得到的字段 |
| `repr=False` | 从 repr 中排除 | 敏感信息或长数据 |
| `compare=False` | 从比较中排除 | 元数据字段 |

> [!note] default vs default_factory
> 不要写 `window_metrics: list[dict] = []`——这会创建在实例间共享的同一个 list 对象。`default_factory=list` 确保每次实例化都创建新列表。

### Frozen Dataclasses — Immutability

```python
@dataclass(frozen=True)
class Position:
    symbol: str
    quantity: int
    avg_price: float
```

Frozen dataclass 创建后不可修改。任何试图修改字段的操作都会抛出 `FrozenInstanceError`。适合用作：

- 配置对象（不会意外被修改）
- 哈希键（frozen=True 自动生成 `__hash__`）
- 多线程共享数据

```python
pos = Position("AAPL", 100, 150.0)
pos.quantity = 200  # FrozenInstanceError: cannot assign to field 'quantity'
```

要"修改" frozen dataclass，使用 `dataclasses.replace()` 创建修改后的副本：

```python
from dataclasses import replace
new_pos = replace(pos, quantity=200)
```

### __post_init__ — Post-Initialization Logic

当字段需要验证、转换或派生值时使用：

```python
@dataclass
class Order:
    symbol: str
    side: str                    # "buy" / "sell"
    quantity: int
    price: float
    total_value: float = field(init=False)

    def __post_init__(self):
        self.total_value = self.quantity * self.price
        if self.side not in ("buy", "sell"):
            raise ValueError(f"Invalid side: {self.side}")
```

`__post_init__` 在自动生成的 `__init__` 末尾被调用，此时所有字段均已赋值。适用于：

- 字段验证（raise early, fail fast）
- 派生字段计算（配合 `init=False`）
- 字段转换（类型强制、格式化）

### Comparison: Dataclass vs Namedtuple vs Dict

| 特性 | `@dataclass` | `namedtuple` | `dict` |
|------|-------------|-------------|--------|
| 可读写 | 是（默认） | 否（不可变） | 是 |
| 类型标注 | 是（原生支持） | 否（通过 `NamedTuple` 有限支持） | 否 |
| 默认值 | 灵活（`field()`） | 通过 `defaults=` 参数 | 需手动处理 |
| 自定义方法 | 完整类能力 | 有限（继承 tuple） | 无 |
| 内存效率 | 中等 | 高（tuple 底层） | 中等 |
| 模式匹配支持 | 是（位置/关键字） | 是 | 是（但靠键名）|

经验法则：

- **只读数据、小量级**：`namedtuple` 足够
- **复杂数据、需要逻辑**：`@dataclass`
- **临时传递、不做检查**：`dict` 快捷但易出错

---

## 2. Case Study: CTM Patterns

### How CTM Uses Dataclasses

CTM 的 dataclass 使用覆盖了从训练到交易的全流程：

```python
from dataclasses import dataclass, field
from typing import List, Optional

@dataclass
class TrainingResult:
    """Single window training outcome with ensemble support."""
    best_sharpe: float                        # 最佳验证 Sharpe
    epochs_run: int                           # 实际运行 epoch 数
    window_metrics: List[dict] = field(default_factory=list)

    # Ensemble 模式的组合字段
    ctm_sharpe: Optional[float] = None
    gbdt_ic: Optional[float] = None
    ensemble_sharpe: Optional[float] = None
    ctm_weight: Optional[float] = None
    gbdt_importance: Optional[float] = None

    def __post_init__(self):
        if self.best_sharpe < -10.0:
            raise ValueError(f"Suspicious Sharpe: {self.best_sharpe}")

    @property
    def is_ensemble(self) -> bool:
        return self.ensemble_sharpe is not None
```

**为什么 CTM 选择 dataclass 而非 namedtuple？**

1. `Optional` 字段有默认值 `None`，namedtuple 无法简洁表达
2. `__post_init__` 提供了验证入口（suspicious Sharpe 检查）
3. `@property` 方法可以与数据共存（`is_ensemble` 判断）
4. 类型标注与 Python 类型系统完全集成

### Order & Position — Trading Domain

```python
@dataclass(frozen=True)
class Order:
    symbol: str
    side: str                               # "buy" | "sell"
    quantity: int
    order_type: str = "market"              # "market" | "limit"
    limit_price: Optional[float] = None
    timestamp: Optional[int] = None

@dataclass(frozen=True)
class Position:
    symbol: str
    quantity: int
    avg_price: float

    @property
    def market_value(self, current_price: float) -> float:
        return self.quantity * current_price
```

这里 `frozen=True` 的选择是有意的：Order 和 Position 一旦创建就不应改变。所有变更都通过创建新的实例表达——这减少了共享可变状态带来的 bug。

### AccountInfo — Config as Dataclass

```python
@dataclass(frozen=True)
class AccountInfo:
    account_id: str
    initial_capital: float
    max_positions: int = 10
    commission_rate: float = 0.001
    slippage_model: str = "default"
```

配置对象天然适合 frozen dataclass：配置在系统启动后不应被修改。相比传统的 dict 配置，frozen dataclass 提供了 IDE 补全、类型检查、默认值集中管理三大好处。

### Design Decisions & Rationale

**1. 为什么 TrainingResult 不用 frozen？**

因为 `window_metrics` 需要在训练过程中增量追加——frozen 后无法 `metrics.append(...)`。如果既要增量更新又要不可变性，可以考虑使用 `__post_init__` + `list` 转换配合 builder 模式。

**2. 为什么 Position 用 frozen 但 TrainingResult 不用？**

Position 代表一个固定时间点的状态快照——创建后无变更语义。TrainingResult 代表一个持续累积的统计集合——需要逐步追加 epoch 记录。**不同用途选择不同可变性策略**，不必追求一刀切的 frozen。

**3. 为什么使用 `Optional[float]` 而非 `float = 0.0`？**

`None` 表达"尚未计算/不适用"语义，而 `0.0` 可能是一个真实的有效值。在 ensemble 场景中，`ctm_sharpe = None` 清晰表明"CTM 模型尚未参与组合"，而非"CTM Sharpe 正好为零"。

---

## 3. Key Takeaways

### When to Use Dataclasses

| 场景 | 推荐 | 理由 |
|------|------|------|
| 配置对象 | 是，frozen=True | 不可变、类型安全、默认值集中 |
| API 响应结构 | 是 | `__repr__` 自动生成便于调试 |
| 算法中间结果 | 是 | `field(default_factory=...)` 处理集合 |
| 高性能数值计算 | 否，考虑 `__slots__` 或 `numpy` | dataclass 有每实例 dict 开销 |
| 需要继承/多态 | 谨慎 | dataclass 继承设计需注意字段冲突 |

### Common Pitfalls to Avoid

- **可变默认值**：永远用 `default_factory` 而非 `= []` 或 `= {}`
- **Frozen 中的可变字段**：`frozen=True` 不阻止 list/dict 内容的修改，它只阻止字段重赋值。需要真正不可变时用 `tuple` 或 `deepcopy`
- **过度使用 dataclass**：2-3 个字段的简单数据用 `namedtuple` 或 `TypedDict` 更轻量
- **继承中的字段顺序**：父类字段先于子类字段被初始化，可能导致 `__post_init__` 中的依赖问题
- **忽略 `__post_init__` 性能**：每次实例化都会调用，不要在里面做重计算

### Related Concepts & Further Reading

- [[Python - Type Hints]] — Dataclass 的类型标注基础
- Python docs: `dataclasses` module — 完整 API 参考
- `attrs` 库 — dataclass 的前身，功能更丰富（验证器、转换器）
- `pydantic` — 带运行时验证的 dataclass 增强版，适合 API 和数据校验场景
