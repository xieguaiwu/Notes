---
tags:
  - Python
  - Generators
  - Iteration
  - LazyEvaluation
  - MemoryEfficiency
  - 基础
  - 概念性
title: Python - Generators
created: 2026-06-01
---

# Python - Generators — Lazy Iteration and Memory Efficiency

> [!abstract] Overview
> Generator 是 Python 中最优雅的惰性求值（lazy evaluation）工具。它们按需产生值，而非一次性计算完整序列，从而大幅降低内存占用。从简单的 `yield` 到复杂的 `yield from` 委托，generator 在数据处理管线、流式读取和迭代算法中无处不在。CTM 的 `walk_forward_windows()` 就是用 generator 实现高效数据切分的典型。

Related: [[Python - Type Hints]] | [[Python - Dataclasses]]

---

## 1. Generators — Core Principles

### What & Why

Generator 是返回迭代器的函数。与普通函数用 `return` 一次性返回值不同，generator 用 `yield` 暂停执行、返回一个值、并在下次请求时恢复：

```python
def simple_range(n):
    i = 0
    while i < n:
        yield i
        i += 1

for x in simple_range(5):   # 逐个生成，非一次性计算
    print(x)                # 0, 1, 2, 3, 4
```

**普通函数 vs Generator：**

| 特性 | 普通函数 | Generator |
|------|---------|-----------|
| 返回值 | `return value` | `yield value`（可多次）|
| 执行方式 | 一次运行到结束 | 每次 `yield` 暂停，`next()` 恢复 |
| 状态保持 | 不保持（调用栈清理） | 自动保持局部变量和指令指针 |
| 内存 | 返回完整数据结构 | 逐个产生，O(1) 内存 |
| 用途 | 计算结果 | 生成序列 / 流式数据 |

Generator 的核心优势在**大型或无限序列**中特别明显：读取 10GB 文件逐行处理不需要将整个文件装入内存。

### yield — The Core Mechanism

执行 flow 是理解 generator 的关键：

```python
def gen():
    print("step 1")
    yield "a"
    print("step 2")
    yield "b"
    print("step 3")

g = gen()            # 不会执行任何 print——只是创建 generator 对象
val1 = next(g)       # 执行到第一个 yield: 打印 "step 1"，返回 "a"
val2 = next(g)       # 从暂停点恢复: 打印 "step 2"，返回 "b"
next(g)              # 打印 "step 3"，然后抛出 StopIteration
```

Generator 的"暂停-恢复"能力来自 Python 的帧对象在执行后被保留而非销毁。这种机制使得生成器可以：

- 在迭代过程中维护复杂状态（如递归深度、累计值）
- 在不消耗额外内存的情况下表达无限序列
- 作为数据管线的中间节点，即产即消

```python
def fibonacci(limit):
    """Generator for Fibonacci sequence — 无限序列，有限消费。"""
    a, b = 0, 1
    for _ in range(limit):
        yield a
        a, b = b, a + b

for f in fibonacci(10):
    print(f)  # 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
```

### yield from — Generator Delegation

`yield from` 允许一个 generator 将部分工作委托给另一个 generator：

```python
def flatten(nested):
    for item in nested:
        if isinstance(item, (list, tuple)):
            yield from flatten(item)   # 递归委托
        else:
            yield item

nested = [1, [2, 3], [4, [5, 6]]]
list(flatten(nested))  # [1, 2, 3, 4, 5, 6]
```

`yield from` 本质上是以下操作的精简版：

```python
# yield from gen2()
for val in gen2():
    yield val
```

它还会将 `.send()`、`.throw()`、`.close()` 传递给子 generator，这在双向通讯场景中（如协程）至关重要。

### Generator Expressions

Generator expression 是列表推导式的惰性版本，使用圆括号而非方括号：

```python
# List comprehension — 立即生成所有数据
squares_list = [x*x for x in range(1000000)]   # 占用 ~28MB 内存

# Generator expression — 延迟按需生成
squares_gen = (x*x for x in range(1000000))    # 占用 ~56 字节

# 使用方式完全相同
sum_sq = sum(x*x for x in range(1000000))      # sum 接受任何可迭代对象
```

**何时用哪种？**

| 场景 | 推荐 | 原因 |
|------|------|------|
| 数据小或需要多次遍历 | List comprehension | 速度快、可索引 |
| 数据大或仅需遍历一次 | Generator expression | 内存效率高 |
| 作为函数参数 | Generator expression | 省略括号更简洁 |
| 需要随机访问 | List comprehension | Generator 不支持索引 |

> [!note] Generator 的单次消费
> Generator 是消费型迭代器——遍历一次后耗尽。如果需要重复使用，要么用 `list()` 物化保存，要么重新创建 generator。

### Lazy Evaluation & Memory Efficiency

Lazy evaluation（惰性求值）的含义是"计算推迟到需要结果的那一刻"。在 Python 中，generator、`range`、`map`、`filter` 都是惰性的。

**内存对比：数据管线**

假设处理 100 万条日志记录，每条需解析、过滤、转换：

```python
# Eager approach — 每步都生成完整列表
lines = read_all_lines("log.txt")            # 100 万字符串
parsed = [parse(line) for line in lines]     # 100 万 dicts
filtered = [p for p in parsed if p["level"] > 2]  # 又一个列表
result = [transform(p) for p in filtered]    # 又一个列表
# 峰值内存：多个完整列表共存

# Lazy approach — 链式 generator，逐个处理
lines = read_lines_lazy("log.txt")           # generator
parsed = (parse(line) for line in lines)     # generator
filtered = (p for p in parsed if p["level"] > 2)
result = (transform(p) for p in filtered)

for r in result:                             # 唯一一次遍历
    process(r)
# 峰值内存：仅一个对象
```

Lazy 管线的内存优势随数据量线性增长。在处理超出 RAM 大小的数据集时，惰性方案是唯一可行方案。

---

## 2. Case Study: CTM Patterns

### walk_forward_windows() — Streaming Data Splits

CTM 的 walk-forward validation 需要将时间序列划分为多个训练/验证窗口。`walk_forward_windows()` 用 generator 实现按需生成窗口：

```python
from typing import Generator, Tuple
import pandas as pd

def walk_forward_windows(
    df: pd.DataFrame,
    window_size: int,
    step_size: int,
    min_train_len: int = 252,      # 最少 1 年训练数据
) -> Generator[Tuple[pd.DataFrame, pd.DataFrame], None, None]:
    """
    Generate train/validation splits lazily.

    Yields:
        Tuple of (train_df, val_df), one per window.
    """
    n = len(df)
    start = 0
    while start + window_size + min_train_len < n:
        train_end = start + min_train_len
        val_end = train_end + window_size

        # Train: 从 start 到 min_train_len
        train_df = df.iloc[start:train_end].copy()
        # Valid: 紧随其后的 window_size 长度
        val_df = df.iloc[train_end:val_end].copy()

        yield train_df, val_df

        # 步进
        start += step_size
```

**为什么用 Generator？**

1. **内存效率**：一次只产生一个窗口的数据，而非全部窗口的列表。假设 10 年日频数据以月为单位滑动，会产生约 100 个窗口——每个窗口的 DataFrame 都是完整的副本。用 generator 避免所有窗口同时存在于内存。
2. **灵活性**：调用者可以在任意点停止迭代（例如验证 Sharpe 达标后 break），不会浪费后续窗口的计算。
3. **组合性**：generator 可以与其他惰性操作链式组合——如 `take_while`、`filter`、`map`—形成完整的数据管线。

### Pipeline Composition with Generators

CTM 可以使用 generator chain 组合完整的数据处理流程：

```python
def add_features(df: pd.DataFrame) -> pd.DataFrame:
    """Feature engineering step."""
    df = df.copy()
    df["returns"] = df["close"].pct_change()
    df["volatility"] = df["returns"].rolling(20).std()
    return df

def filter_low_volatility(df: pd.DataFrame, threshold: float = 0.01):
    """Filter out low-volatility windows."""
    if df["volatility"].mean() > threshold:
        return df
    return None  # Signal to skip this window

# Generator pipeline
windows = walk_forward_windows(data, window_size=60, step_size=20)
featured = (add_features(train) for train, _ in windows)        # 惰性：逐个处理
valid = (w for w in featured if filter_low_volatility(w))       # 惰性：逐个过滤

for i, train_df in enumerate(valid):
    model = train_model(train_df)
    # 每个窗口的 train_df 只在当前循环中存在
```

每个 generator 转换都是一个独立的 lazy step，不产生中间列表。每一步的输出即被下一步消耗，数据像流水线一样流过。

### Generator Type Annotations

CTM 风格严格标注 generator 类型：

```python
# Generator[YieldType, SendType, ReturnType]
def batch_iterator(
    data: list[float],
    batch_size: int,
) -> Generator[list[float], None, None]:
    """Generate batches from a list lazily."""
    for i in range(0, len(data), batch_size):
        yield data[i : i + batch_size]

# 对于只负责 yield 的标准 generator
def metrics_stream() -> Generator[dict, None, None]:
    ...
```

| 类型参数 | 含义 | CTM 中常见值 |
|----------|------|-------------|
| `YieldType` | Generator 产出的值类型 | `Tuple[DataFrame, DataFrame]`, `dict`, `float` |
| `SendType` | `.send()` 传入的值类型（无则为 `None`）| 绝大多数为 `None` |
| `ReturnType` | `StopIteration.value` 类型（无则为 `None`）| 绝大多数为 `None` |

### Design Decisions & Rationale

**1. 为什么 walk_forward_windows 用 generator 而非返回 list？**

如果返回 list，所有窗口的 DataFrame 同时存在于内存。对于 20 年数据、月频滑动（约 240 个窗口），每个窗口 60 天的 OHLCV 数据大约几 MB，240 个窗口同时存在就是几百 MB——完全没有必要，因为训练循环在任意时刻只关心一个窗口。

**2. 为什么不用 iterator class 而用 generator function？**

Generator function 更简洁：局部变量自动保持状态，不需要维护 `__iter__` 和 `__next__` 方法。只有在需要额外状态管理（如重置、多步预读）时才考虑自定义 iterator class。

---

## 3. Key Takeaways

### When to Use Generators

| 场景 | 推荐 | 原因 |
|------|------|------|
| 大型文件逐行处理 | 是 | 内存 O(1)，不加载全文 |
| 无限序列 | 是 | 数学序列、事件流 |
| 数据管线/流水线 | 是 | 惰性组合，链式变换 |
| 递归树遍历 | 是 | `yield from` 简洁表达 |
| 小数据多遍遍历 | 否，用 list | generator 单次消费 |
| 随机访问 / 索引 | 否，用 list/array | generator 不支持索引 |

### Common Pitfalls to Avoid

- **Generator 耗尽后重用**：generator 是单次的。需要重复遍历时，考虑用 `itertools.tee()` 或转为 list
- **在 generator 内保留昂贵资源**：generator 可能在 `yield` 处暂停很长时间。资源获取应在每次 `yield` 前完成，或在 `try/finally` 中配合 `close()` 做清理
- **`yield from` 与 `return` 混淆**：generator 中 `return value` 将值存入 `StopIteration.value`，调用者需要捕获异常或使用 `yield from` 间接获取
- **不必要的惰性**：数据量小于几千元素时，list comprehension 更快——generator 的单次 yield 有固定开销
- **忘记标注 `Generator` 返回类型**：没有类型标注的 generator 难以阅读，尤其当 `YieldType` 是复杂元组时

### Related Concepts & Further Reading

- [[Python - Type Hints]] — Generator 类型标注 `Generator[Y, S, R]`
- `itertools` 模块 — `chain`, `islice`, `takewhile`, `cycle`, `tee` 等 generator 工具
- `contextlib.contextmanager` — 基于 generator 的上下文管理器
- PEP 380 — `yield from` 语法规范
- PEP 289 — Generator Expressions 规范
