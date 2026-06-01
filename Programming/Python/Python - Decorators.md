---
tags:
  - Python
  - DesignPatterns
  - Metaprogramming
  - 概念性
title: Python - Decorators
created: 2026-06-01
---

# Python - Decorators — Function Composition and Cross-Cutting Concerns

> [!abstract] Overview
> Python 装饰器（decorator）是一种函数式编程的语法糖，允许在不修改目标函数源码的前提下，在其执行前后注入额外逻辑。从日志记录到权限校验，从重试机制到缓存——装饰器是 Python 中最优雅的横切关注点（cross-cutting concern）解决方案。本文从基础语法到高级模式展开，以 CTM 的 `_retry_on_failure` 为案例，展示装饰器在金融交易系统中的实际应用。

Related: [[Python - Abstract Base Classes]] | [[PyTorch - Custom Gradients]]

---

## 1. Decorators — Core Principles

### What & Why

装饰器本质是一个**高阶函数**——接收一个函数，返回一个新函数：

```python
@decorator
def func():
    pass

# 等价于
func = decorator(func)
```

为什么需要装饰器？考虑一个需要重试逻辑的场景：

```python
# 无装饰器——重复代码
def place_order(order):
    for attempt in range(3):
        try:
            return api.execute(order)
        except ConnectionError:
            time.sleep(2 ** attempt)
    raise ConnectionError("Max retries exceeded")

def cancel_order(order_id):
    for attempt in range(3):
        try:
            return api.cancel(order_id)
        except ConnectionError:
            time.sleep(2 ** attempt)
    raise ConnectionError("Max retries exceeded")
```

重试逻辑在每个函数中重复。装饰器将其提取为**单一关注点**，函数本身只需关心业务逻辑。

### Mathematical / Theoretical Foundation

**装饰器与闭包**：装饰器依赖闭包（closure）机制——内部函数可以访问外部函数作用域中的变量：

```python
def retry(max_attempts):
    def decorator(func):
        def wrapper(*args, **kwargs):
            for attempt in range(max_attempts):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt == max_attempts - 1:
                        raise
                    time.sleep(2 ** attempt)
            return wrapper
        return decorator
```

嵌套层级：`retry(3)` → `decorator` → `wrapper`。每层都有独立的命名空间。

**functools.wraps**：不加 `wraps` 的装饰器会丢失原函数的元信息：

| 属性 | 无 wraps | 有 wraps |
|------|---------|---------|
| `__name__` | `wrapper` | `place_order` |
| `__doc__` | None | 原始 docstring |
| `__module__` | `__main__` | 原始模块 |
| `__annotations__` | `{}` | 原始签名 |

```python
from functools import wraps

def retry(max_attempts):
    def decorator(func):
        @wraps(func)                     # 复制 __name__, __doc__ 等
        def wrapper(*args, **kwargs):
            ...
        return wrapper
    return decorator
```

**装饰器分类**：

| 类型 | 语法 | 使用场景 |
|------|------|---------|
| 无参装饰器 | `@decorator` | 简单横切逻辑（计时、日志） |
| 有参装饰器 | `@decorator(args)` | 需配置的重试、缓存、鉴权 |
| 类装饰器 | `@dataclass` | 类变换、注册 |
| 方法装饰器 | `@property`, `@classmethod` | 方法语义转换 |

### Key Design Dimensions & Tradeoffs

| 设计维度 | 选项 | 取舍 |
|---------|------|------|
| **参数传递** | 有参 / 无参 | 有参灵活但三层嵌套；无参简洁但硬编码 |
| **元信息保留** | `@wraps` / 手动设置 | wraps 自动但需另导入；手动设置繁琐但可控 |
| **错误处理** | 吞异常 / 重抛 / 回调 | 重抛透明但丢失原始异常栈；回调灵活但侵入式 |
| **作用域** | 函数装饰器 / 类装饰器 | 函数装饰器通用；类装饰器可维护状态 |
| **组合顺序** | `@A @B` | A 在外层包裹 B，执行顺序：A 进入 → B 进入 → B 退出 → A 退出 |

---

## 2. Case Study: CTM Patterns

### How CTM Applies These Principles

CTM 的 `AlpacaBroker` 使用 `_retry_on_failure` 装饰器为所有 Broker API 调用添加指数退避重试。这是一个**有参装饰器**的最佳实践案例：

| 通用模式 | CTM 的具体实现 | 动机 |
|---------|---------------|------|
| **有参装饰器** | `@_retry_on_failure(max_retries=3, backoff_factor=2)` | 不同 API 需要不同的重试策略 |
| **@wraps** | 保留 `place_order` 的签名 | 便于调试和文档生成 |
| **异常过滤** | 仅捕获网络/限流异常 | 业务错误（如资金不足）不重试 |
| **指数退避** | `time.sleep(backoff_factor ** attempt)` | 避免 API 限流潮涌 |

**CTM 的 retry 装饰器**：

```python
import time
import logging
from functools import wraps
from typing import Callable, Type, Tuple

logger = logging.getLogger(__name__)

def _retry_on_failure(
    max_retries: int = 3,
    backoff_factor: float = 2.0,
    retryable_exceptions: Tuple[Type[Exception], ...] = (
        ConnectionError,
        TimeoutError,
        IOError,
    ),
) -> Callable:
    """
    指数退避重试装饰器。
    
    适用于 AlpacaBroker 等需要与外部 API 通信的 Broker 实现。
    仅重试网络/限流类异常，业务异常（InvalidOrder, InsufficientFunds）
    直接抛出。
    """
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            last_exception = None
            for attempt in range(max_retries):
                try:
                    return func(*args, **kwargs)
                except retryable_exceptions as e:
                    last_exception = e
                    if attempt < max_retries - 1:
                        wait = backoff_factor ** attempt
                        logger.warning(
                            f"{func.__name__} failed (attempt {attempt + 1}/"
                            f"{max_retries}), retrying in {wait:.1f}s: {e}"
                        )
                        time.sleep(wait)
                    else:
                        logger.error(
                            f"{func.__name__} failed after {max_retries} "
                            f"attempts: {e}"
                        )
            raise last_exception
        return wrapper
    return decorator
```

**在 AlpacaBroker 中的使用**：

```python
class AlpacaBroker(BaseBroker):
    @_retry_on_failure(max_retries=3, backoff_factor=2.0)
    def place_order(self, order: Order) -> OrderResult:
        return self.api.submit_order(
            symbol=order.symbol,
            qty=order.quantity,
            side=order.side,
            type=order.type,
            time_in_force="day",
        )

    @_retry_on_failure(max_retries=5, backoff_factor=1.5)
    def get_positions(self) -> List[Position]:
        return self.api.list_positions()
```

`place_order` 使用 3 次重试（指数退避：1s, 2s, 4s），`get_positions` 使用 5 次重试（1.5s, 2.25s, 3.375s...）。不同 API 的重试策略独立配置，但重试逻辑完全复用。

### Design Decisions & Rationale

**1. 为什么 retryable_exceptions 可配置而非硬编码？**

```python
# 硬编码——不灵活
except (ConnectionError, TimeoutError):

# 可配置——调用方决定哪些异常可重试
@_retry_on_failure(retryable_exceptions=(ConnectionError, RateLimitError))
```

不同 broker（Alpaca, IBKR, Binance）对"可重试异常"的定义不同。Alpaca 的 `RateLimitError` 应重试，`InvalidOrder` 不应重试。通过参数化 `retryable_exceptions`，装饰器可以跨 broker 复用。

**2. 为什么用 @wraps？**

在金融系统中，Broker 方法被监管合规需求追踪。`place_order.__name__` 应该在日志和监控系统中显示实际方法名。没有 `@wraps`，所有被装饰的函数都会显示为 `wrapper`，使日志分析变得困难。

**3. 为什么 logging 放在 wrapper 内而非外部？**

```python
# 错误写法——日志在装饰器创建时初始化
logger.info(f"Retry decorator created for {func.__name__}")

# 正确写法——日志在 wrapper 执行时记录
def wrapper(*args, **kwargs):
    logger.info(f"{func.__name__} failed, retrying...")
```

装饰器的 `decorator(func)` 在模块导入时执行，`wrapper()` 在函数调用时执行。日志应该在被调用时输出，而不是在导入时。

> [!note] 与 Python - Abstract Base Classes 的关系
> AlpacaBroker 继承自 `BaseBroker(ABC)`（见 [[Python - Abstract Base Classes]]），装饰器 `_retry_on_failure` 是 `BaseBroker` 子类的标准设施——所有 Broker 实现共享重试逻辑，但各自的 `retryable_exceptions` 和 `max_retries` 可以不同。装饰器与抽象基类的组合构成了 CTM 的 Strategy 模式核心：接口由 ABC 定义，行为增强由装饰器注入。

### 装饰器组合：链式应用

```python
@log_execution_time
@_retry_on_failure(max_retries=3)
def place_order(self, order: Order) -> OrderResult:
    ...
```

执行顺序：`log_execution_time(_retry_on_failure(3)(place_order))`。调用时：先进入计时器，再进入重试，执行真实函数，退出重试，退出计时器。

---

## 3. Key Takeaways

### When to Use These Techniques

| 模式 | 适用场景 |
|------|---------|
| **无参装饰器 + @wraps** | 简单横切逻辑（执行时间、日志、输入验证）|
| **有参装饰器** | 需运行时配置的模式（重试、缓存 TTL、鉴权策略）|
| **类装饰器** | 注册类到工厂、添加 dunder 方法、实现单例 |
| **装饰器组合** | 关注点正交时（计时 + 重试 + 日志 互不影响）|
| **装饰器 + ABC** | `BaseBroker(ABC)` 定义接口 + `_retry_on_failure` 注入增强 |

### Common Pitfalls to Avoid

- **忘记 @wraps**：导致 `help(func)` 显示 `wrapper`，Pydantic/FastAPI 的签名校验失效。总是加 `@wraps(func)`
- **可变默认参数**：`def wrapper(*args, kwargs={})` 中的 `kwargs` 在装饰器定义时创建一次，所有调用共享。改为 `**kwargs`
- **返回类型标注**：装饰器返回 `wrapper` 的类型是 `Callable`，即使原函数标注了具体返回类型。用 `ParamSpec` 和 `TypeVar` 保留签名信息（Python 3.10+ 的 `typing.ParamSpec`）
- **异常栈截断**：`raise last_exception` 丢失原始异常栈。在重试坑中应使用 `raise last_exception from original_exception` 或直接 `raise`
- **装饰器执行时机理解不清**：`@decorator` 在 import 时执行，被装饰函数在调用时执行。不要在装饰器层做运行时操作（如打开文件、创建网络连接）

### Related Concepts & Further Reading

- [[Python - Abstract Base Classes]] — ABC + Decorator 的组合模式（Strategy Pattern 的双重实现）
- [[PyTorch - Custom Gradients]] — PyTorch 中的 @torch.no_grad() 等效于装饰器的梯度控制
- Python `functools.wraps` 官方文档
- Python `typing.ParamSpec` — 保留装饰器泛型签名的现代方式
- *Design Patterns: Elements of Reusable Object-Oriented Software* — Decorator Pattern 的 OOP 版本
