### 一、内置函数
#### 1. `hasattr(object, name)`  
   - 用途：检查对象是否包含指定名称的属性或方法。  
   - 参数：  
- `object`：目标对象或类  
- `name`：属性名（字符串形式，如`"title"`）  
   - 返回：布尔值（存在为`True`，否则为`False`）  
   - 示例：  
     ```python
     class User:
         name = "Alice"
     user = User()
     print(hasattr(user, "name"))   # True
     print(hasattr(user, "age"))    # False
     ```


#### 2. `getattr(object, name[, default])`  
   - 用途：获取对象的属性或方法。若属性不存在，返回`default`值（未指定则抛出`AttributeError`）。  
   - 参数：  
- `object`：目标对象或类  
- `name`：属性名（字符串形式）  
- `default`（可选）：默认返回值  
   - 示例：  
     ```python
     value = getattr(user, "name", "Unknown")  # "Alice"
     method = getattr(user, "run", None)       # 获取方法引用
     ```


#### 3. `setattr(object, name, value)`  
   - 用途：设置或修改对象的属性值。若属性不存在，则动态添加新属性。  
   - 参数：  
- `object`：目标对象或类  
- `name`：属性名（字符串形式）  
- `value`：属性值（可以是普通值或方法引用）  
   - 示例：  
     ```python
     setattr(user, "age", 30)           # 添加新属性
     setattr(user, "run", lambda: "OK") # 动态添加方法
     ```


#### 4. `delattr(object, name)`  
   - 用途：删除对象的属性。若属性不存在，抛出`AttributeError`。  
   - 参数：  
- `object`：目标对象或类  
- `name`：属性名（字符串形式）  
   - 示例：  
     ```python
     delattr(user, "name")  # 删除已有属性
     delattr(user, "addr")  # AttributeError
     ```


#### 5. `dir([object])`  
   - 用途：返回对象的所有属性和方法名称列表（包括继承的成员）。  
   - 参数：  
- `object`（可选）：目标对象或类（默认为当前作用域）  
   - 示例：  
     ```python
     print(dir(user))  # 输出包含`name`, `age`, `run`等的列表
     ```


#### 6. `vars([object])`  
   - 用途：返回对象的`__dict__`属性（仅包含实例属性，不包含类属性）。  
   - 参数：  
- `object`（可选）：目标对象或类  
   - 示例：  
     ```python
     print(vars(user))  # {'name': 'Alice', 'age': 30}
     ```


---

### 二、特殊方法（魔术方法）
#### 1. `__getattr__(self, name)`  
   - 用途：当访问不存在的属性时触发，用于自定义属性查找逻辑。  
   - 参数：  
- `self`：实例对象  
- `name`：被访问的属性名（字符串形式）  
   - 示例：  
     ```python
     class Proxy:
         def __getattr__(self, name):
             return f"Missing: {name}"
     proxy = Proxy()
     print(proxy.data)  # "Missing: data"
     ```


#### 2. `__getattribute__(self, name)`  
   - 用途：拦截所有属性访问（包括存在的属性），需谨慎使用以避免递归。  
   - 注意：必须显式调用父类方法（如`super().__getattribute__()`）或操作`self.__dict__`。  
   - 示例：  
     ```python
     class LoggedAccess:
         def __getattribute__(self, name):
             print(f"Accessing {name}")
             return super().__getattribute__(name)
     ```


#### 3. `__setattr__(self, name, value)`  
   - 用途：拦截属性赋值操作（包括初始化中的赋值）。  
   - 注意：直接操作`self.__dict__`避免递归。  
   - 示例：  
     ```python
     class ValidatedUser:
         def __setattr__(self, name, value):
             if name == "age" and value < 0:
                 raise ValueError("Age cannot be negative")
             self.__dict__[name] = value
     ```


#### 4. `__delattr__(self, name)`  
   - 用途：拦截属性删除操作。需处理属性不存在的情况。  
   - 示例：  
     ```python
     class ProtectedUser:
         def __delattr__(self, name):
             if name == "id":
                 raise PermissionError("Cannot delete ID")
             super().__delattr__(name)
     ```


#### 5. `__dir__(self)`  
   - 用途：自定义`dir()`的输出内容，返回属性名列表。  
   - 示例：  
     ```python
     class CustomDir:
         def __dir__(self):
             return ['name', 'age']
     ```


---

### 三、高级应用场景
#### 1. 动态属性管理  
   通过`setattr()`和`getattr()`实现插件系统、配置加载等动态行为：  
   ```python
   config = {}
   for key in ["host", "port"]:
       setattr(config, key, os.getenv(key.upper()))
   ```


#### 2. 代理模式  
   利用`__getattr__()`委托属性访问到其他对象：  
   ```python
   class Proxy:
       def __init__(self, target):
           self._target = target
       def __getattr__(self, name):
           return getattr(self._target, name)
   ```


#### 3. 数据验证与拦截  
   通过`__setattr__()`实现属性赋值时的自动验证：  
   ```python
   class Temperature:
       def __setattr__(self, name, value):
           if name == "celsius" and value < -273.15:
               raise ValueError("Below absolute zero")
           self.__dict__[name] = value
   ```


#### 4. 兼容性处理  
   使用`hasattr()`和`getattr()`处理不同版本API的兼容性：  
   ```python
   if hasattr(requests, "Session"):
       session = getattr(requests, "Session")()
   ```


---

### 四、注意事项
1. 性能开销：频繁使用反射（如`getattr()`）可能降低性能，优先考虑静态属性访问。  
2. 递归陷阱：在`__setattr__()`中直接使用`self.name = value`会导致无限递归，需操作`self.__dict__`。  
3. 属性覆盖：动态添加的属性可能覆盖类定义中的同名属性。  
4. 异常处理：使用`getattr()`时建议指定`default`参数，避免`AttributeError`。  

---

### 五、总结对比表

| 方法/函数                | 用途                          | 触发条件                  | 是否动态操作 |
|-------------------------|-------------------------------|--------------------------|-------------|
| `hasattr()`             | 检查属性是否存在              | 显式调用                 | 是          |
| `getattr()`             | 获取属性值                    | 显式调用                 | 是          |
| `setattr()`             | 设置属性值                    | 显式调用                 | 是          |
| `delattr()`             | 删除属性                      | 显式调用                 | 是          |
| `__getattr__()`         | 拦截未定义属性访问            | 访问不存在的属性时       | 自动        |
| `__getattribute__()`    | 拦截所有属性访问              | 访问任何属性时           | 自动        |
| `__setattr__()`         | 拦截属性赋值                  | 赋值操作时               | 自动        |
| `__delattr__()`         | 拦截属性删除                  | 删除操作时               | 自动        |


通过合理组合这些方法，可以实现高度动态的类行为，适用于元编程、框架开发、数据驱动设计等复杂场景。