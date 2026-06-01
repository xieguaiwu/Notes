---
tags:
  - Python
  - TypeHints
  - StaticAnalysis
  - Typing
  - TypeSafety
  - 基础
  - 概念性
title: Python - Type Hints
created: 2026-06-01
---

# Python - Type Hints — Static Typing for Dynamic Python

> [!abstract] Overview
> Type hints（类型标注）是 Python 3.5 引入的可选类型系统。它们不改变运行时行为，但让 IDE、linter 和静态类型检查器（如 mypy、pyright）能在"编译时"发现类型错误。对于中大型项目，类型标注带来的可维护性和代码可读性收益远大于书写成本。CTM 的所有代码强制使用完整类型标注。

Related: [[Python - Dataclasses]] | [[Python - Generators]]

---

## 1. Type Hints — Core Principles

### What & Why

动态类型是 Python 的核心特性——但也是大型项目中 bug 的主要来源。Type hints 在不牺牲动态特性的前提下，为开发者提供了一层安全网：

```python
# Without type hints — 调用者需要猜测参数结构
def calculate_sharpe(prices, risk_free):
    return (prices.mean() - risk_free) / prices.std()

# With type hints — 意图一目了然
def calculate_sharpe(prices: pd.Series, risk_free: float) -> float:
    return (prices.mean() - risk_free) / prices.std()
```

**Type hints 解决的问题：**

| 问题 | 无类型标注 | 有类型标注 |
|------|-----------|-----------|
| 函数签名意图模糊 | 需读文档或代码 | 参数/返回值类型直接表达 |
| 运行时类型错误 | 上线/测试才能发现 | IDE 实时警告 |
| 重构代价高 | 改签名需手动修改所有调用处 | IDE 自动跟踪变更 |
| API 文档维护负担 | 独立文档易过时 | 类型标注即文档 |

> [!note] Type hints 不会让你慢下来
> Python 完全忽略类型标注——它们只在静态分析阶段使用。运行时性能零影响。

### Basic Type Hints

```python
# 基本类型
name: str = "CTM"
epochs: int = 100
lr: float = 1e-3
is_trained: bool = False

# 集合类型（旧语法 vs 新语法）
# Python 3.8- : from typing import List, Dict, Tuple
prices: list[float] = [1.0, 2.0, 3.0]           # Python 3.9+
weights: dict[str, float] = {"ctm": 0.7, "gbdt": 0.3}
shape: tuple[int, int] = (252, 20)

# 函数签名
def train_model(
    model: torch.nn.Module,
    optimizer: torch.optim.Optimizer,
    epochs: int,
    verbose: bool = False,
) -> float:                # 返回训练 loss
    ...
```

### Optional, Union, Any

```python
from typing import Optional, Union, Any

# Optional[X] = X | None
def load_checkpoint(path: str) -> Optional[dict]:
    if not os.path.exists(path):
        return None
    return torch.load(path)

# Union — 多类型之一
def process_value(v: Union[int, float, str]) -> float:
    if isinstance(v, str):
        return float(v)
    return float(v)

# Python 3.10+ 可以使用 | 语法
def load_checkpoint(path: str) -> dict | None: ...
def process_value(v: int | float | str) -> float: ...

# Any — 关闭类型检查（慎用！）
def debug_hook(data: Any) -> Any:
    return data
```

| 类型工具 | 含义 | Python 3.10+ 等价 |
|---------|------|------------------|
| `Optional[X]` | `X` 或 `None` | `X \| None` |
| `Union[X, Y]` | `X` 或 `Y` | `X \| Y` |
| `Any` | 关闭检查 | 同上（无变化）|

### TypedDict — Typed Dictionary

`TypedDict` 为 dict 定义精确的键值类型结构：

```python
from typing import TypedDict

class WindowMetrics(TypedDict):
    window_idx: int
    train_sharpe: float
    val_sharpe: float
    epochs_run: int
    overfitting: bool          # 是否已过拟合

# 使用
metrics: WindowMetrics = {
    "window_idx": 0,
    "train_sharpe": 1.2,
    "val_sharpe": 0.8,
    "epochs_run": 45,
    "overfitting": False,
}
```

`TypedDict` 填补了 dataclass 和 dict 之间的空白——想要 dict 的灵活性但又不愿牺牲类型安全时使用。

| 特性 | `TypedDict` | `@dataclass` |
|------|-------------|-------------|
| 访问方式 | `d["key"]` | `obj.key` |
| 序列化 | 原生 json 兼容 | 需额外处理（`asdict()` 或 `__dict__`）|
| 可选字段 | `total=False` 控制 | `Optional` + `None` 默认值 |
| 方法定义 | 否（只是 dict） | 是（完整类能力）|
| 运行时开销 | 无（纯 dict） | 构造/属性访问稍有 |

### Protocol — Structural Subtyping

`Protocol` 实现结构类型系统（structural subtyping），即"鸭子类型"的静态版本：

```python
from typing import Protocol

class Trainable(Protocol):
    """任何具有 train() 和 predict() 方法的对象。"""
    def train(self, data: list[float]) -> None: ...
    def predict(self, data: list[float]) -> list[float]: ...

def run_pipeline(model: Trainable, data: list[float]) -> list[float]:
    model.train(data)
    return model.predict(data)

# LSTM 模型 — 不需要显式实现 Trainable 接口
class LSTMModel:
    def train(self, data: list[float]) -> None: ...
    def predict(self, data: list[float]) -> list[float]: ...

run_pipeline(LSTMModel(), [1.0, 2.0, 3.0])  # OK: 结构匹配
```

`Protocol` 的优势在于**松耦合**。调用者定义"我需要什么"，提供者不需要知道 `Trainable` 的存在——只要结构匹配，类型检查就通过。

### @overload — Multiple Signatures

`@overload` 允许一个函数拥有多个类型签名：

```python
from typing import overload

@overload
def merge_results(a: TrainingResult, b: TrainingResult) -> TrainingResult: ...

@overload
def merge_results(a: list[TrainingResult], b: None) -> TrainingResult: ...

def merge_results(a, b):
    """实现体——不写类型标注。"""
    if isinstance(a, list):
        # 合并多个结果
        ...
    return ...
```

`@overload` 不实现逻辑——只是为类型检查器提供精确签名。实现体需要自己处理所有分支。

---

## 2. Case Study: CTM Patterns

### How CTM Uses Type Hints

CTM 的所有模块使用完整类型标注。这里是一个典型的训练模块：

```python
from typing import List, Optional, Tuple, Generator, TypedDict, overload
import torch
import pandas as pd

@dataclass
class TrainingResult:
    best_sharpe: float
    epochs_run: int
    window_metrics: List[dict]
    ctm_sharpe: Optional[float] = None
    ensemble_sharpe: Optional[float] = None

def train_window(
    model: torch.nn.Module,
    train_loader: torch.utils.data.DataLoader,
    val_loader: torch.utils.data.DataLoader,
    optimizer: torch.optim.Optimizer,
    scheduler: torch.optim.lr_scheduler.LRScheduler,
    epochs: int,
    patience: int = 10,
    grad_clip: float = 1.0,
) -> TrainingResult:
    """
    Full training loop for one walk-forward window.
    Every parameter is fully typed — no guessing required.
    """
    best_sharpe = float("-inf")
    no_improve = 0
    metrics: list[dict] = []

    for epoch in range(epochs):
        train_loss = train_epoch(model, train_loader, optimizer)
        val_sharpe = validate(model, val_loader)
        metrics.append({"epoch": epoch, "loss": train_loss, "sharpe": val_sharpe})

        if val_sharpe > best_sharpe:
            best_sharpe = val_sharpe
            no_improve = 0
        else:
            no_improve += 1
            if no_improve >= patience:
                break

        scheduler.step()

    return TrainingResult(
        best_sharpe=best_sharpe,
        epochs_run=epoch + 1,
        window_metrics=metrics,
    )
```

**类型标注带来的具体收益：**

1. **参数意图清晰**：`scheduler: torch.optim.lr_scheduler.LRScheduler` 明确要求传入的是 PyTorch 调度器，而非普通函数或 None
2. **返回值安全**：调用方知道 `train_window` 一定返回 `TrainingResult`，可用 `.best_sharpe`、`.epochs_run` 等属性
3. **重构保护**：修改 `TrainingResult` 字段时，所有构造和使用处会被 IDE 一并标记

### TypedDict in CTM

```python
class WindowMetrics(TypedDict, total=False):
    """Window-level training metrics."""
    window_idx: int
    train_sharpe: float
    val_sharpe: float
    train_loss: float
    val_loss: float
    epochs_run: int
    best_epoch: int

def collect_metrics(results: List[TrainingResult]) -> List[WindowMetrics]:
    """Convert TrainingResult list to serializable metrics."""
    return [
        {"window_idx": i, "train_sharpe": r.best_sharpe, ...}
        for i, r in enumerate(results)
    ]
```

`total=False` 表示所有字段都是可选的——适合 JSON 序列化的灵活结构。

### Protocol in CTM

```python
class FeatureTransform(Protocol):
    """Any feature transformation with fit/transform interface."""
    def fit(self, data: pd.DataFrame) -> None: ...
    def transform(self, data: pd.DataFrame) -> pd.DataFrame: ...

class Pipeline:
    def __init__(self, transforms: List[FeatureTransform]):
        self.transforms = transforms

    def run(self, data: pd.DataFrame) -> pd.DataFrame:
        for t in self.transforms:
            t.fit(data)
            data = t.transform(data)
        return data

# 任何满足 fit/transform 协议的类都可插入
class Normalizer:
    def fit(self, data: pd.DataFrame) -> None:
        self.mean = data.mean()
    def transform(self, data: pd.DataFrame) -> pd.DataFrame:
        return data - self.mean

Pipeline([Normalizer()]).run(data)  # OK
```

### Design Decisions & Rationale

**1. 为什么 CTM 全部使用完整类型标注而非部分标注？**

一致性很重要。部分标注的代码库中，开发者无法区分"未标注的参数是 `Any` 还是忘记标注"。全线标注消除了这种歧义。

**2. 为什么使用 `List[dict]` 而非 `List[WindowMetrics]`？**

`window_metrics` 中的 dict 键值取决于运行时加载的配置——使用 `TypedDict` 会因为部分配置不存在而导致类型检查失败。`dict` 在这里是对灵活性的务实妥协。

**3. 为什么 CTM 不使用 `Any`？**

`Any` 是类型系统的"逃生舱"。在 CTM 中，仅在以下情况使用：第三方库类型不完整时的临时绕过、动态代码生成、调试钩子。生产代码中 `Any` 的数量是需要警惕的信号。

---

## 3. Key Takeaways

### When to Use Type Hints

| 场景 | 推荐强度 | 理由 |
|------|---------|------|
| 函数签名（公开 API） | 必须 | 接口契约，调用者无歧义 |
| Dataclass 字段 | 必须 | 字段类型即数据模型定义 |
| 复杂嵌套类型 | 强烈推荐 | `dict[str, list[tuple[int, float]]]` 比注释准确 |
| 脚本/一次性代码 | 可选 | 快速原型可省略 |
| 动态类型依赖 | 配合 `Protocol` | Duck typing 的静态化 |

### Common Pitfalls to Avoid

- **过度泛型**：`def f(x: Union[int, float, str, bytes, list]) -> Any` 实际等于未标注。缩小类型范围或重构为重载
- **`Optional[X]` 误用**：`Optional[str]` 不是可选参数，是参数类型可为 str 或 None。可选参数用 `= None` 表示
- **类型标注过期**：重构时类型标注未同步更新。使用 mypy/pyright CI 检查强制一致性
- **运行时依赖类型**：不要写 `if isinstance(x, list[str]):`。泛型类型在运行时被擦除
- **牺牲可读性的精确**：`dict[str, Union[list[dict[str, float]], tuple[int, ...]]]` 不如定义一个 `TypedDict` 或 `@dataclass`

### Recommended Tooling

| 工具 | 用途 |
|------|------|
| `mypy` | 最成熟的静态类型检查器 |
| `pyright` / `basedpyright` | 微软出品，速度更快，Pylance 同款 |
| `pytype` | Google 出品，支持类型推断 |
| `beartype` | 运行时类型检查器（装饰器方式）|
| `pydantic` | 运行时类型验证，带解析和序列化 |

### Related Concepts & Further Reading

- [[Python - Dataclasses]] — 类型标注在数据建模中的典型应用
- [[Python - Generators]] — `Generator[Y, S, R]` 类型标注
- PEP 484 — Type Hints 规范
- PEP 544 — Protocols: Structural subtyping
- PEP 586 — Literal Types
- PEP 647 — User-Defined Type Guards
