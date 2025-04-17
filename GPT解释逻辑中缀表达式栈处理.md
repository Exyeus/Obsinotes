## 1. `direct_infix` 的输入与输出

输入：

- `expression`：一个布尔表达式（中缀表达式）。
- `base_list`：表达式中涉及的字母（变量）。
- `corresponding_value_list`：与 `base_list` 变量一一对应的布尔值（`0` 或 `1`）。

输出：

- 计算出的布尔值，以 `"0"` 或 `"1"` 形式返回。

---

## 2. 计算的核心步骤

`direct_infix` 计算布尔表达式的过程分为三大核心步骤：

1. 变量替换：用 `0` 或 `1` 替换表达式中的字母。
2. 运算符解析与处理：基于运算符优先级，使用栈（stack）解析布尔表达式并计算结果。
3. 返回最终计算结果。

---

## 3. 详细的执行流程

### Step 1：变量替换

```cpp
vector<pair<char, char>> dictionary;
for (int i = 0; i < base_list.size(); i++) {
    dictionary.push_back(make_pair(base_list[i], corresponding_value_list[i]));
}
```

这个部分建立了一个映射关系表 `dictionary`，用于存储 `base_list` 变量及其对应的 `0/1` 值。

然后，对 `expression` 进行替换：

```cpp
string temp_expression = expression;
for (auto &pair : dictionary) {
    for (size_t i = 0; i < temp_expression.size(); ++i) {
        if (temp_expression[i] == pair.first) {
            temp_expression[i] = pair.second;
        }
    }
}
```

此时，`temp_expression` 变成了只含 `0/1` 的布尔表达式，比如：

```
表达式： p & q | !r
替换后： 1 & 0 | !1
```

---

### Step 2：运算符解析与计算

使用 运算符栈 `ops` 和 值栈 `vals` 处理中缀表达式：

```cpp
stack<char> ops;
stack<bool> vals;
```

然后，逐个遍历 `temp_expression`：

```cpp
for (int i = 0; i < temp_expression.length(); ++i) {
    char c = temp_expression[i];
```

#### (1) 处理 `0` 或 `1`（操作数入栈）

```cpp
if (c == '0' || c == '1') {
    vals.push(c == '1');
}
```

直接把 `0/1` 转换为 `bool` 值，存入 `vals` 栈。

---

#### (2) 处理 `(`（左括号入栈）

```cpp
else if (c == '(') {
    ops.push(c);
}
```

左括号 `(` 代表新的一层运算，因此直接压入运算符栈。

---

#### (3) 处理 `)`（右括号运算）

```cpp
else if (c == ')') {
    while (!ops.empty() && ops.top() != '(') {
        char op = ops.top();
        ops.pop();
        bool val2 = vals.top(); vals.pop();
        bool val1 = vals.top(); vals.pop();

        if (op == '&') vals.push(val1 && val2);
        else if (op == '|') vals.push(val1 || val2);
        else if (op == '>') vals.push(!val1 || val2);
        else if (op == '-') vals.push(val1 == val2);
    }
    ops.pop(); // 弹出 '('
}
```

右括号 `)` 代表括号内的计算结束，需要弹出栈顶运算符并执行运算，直到遇到左括号 `(`。

---

#### (4) 处理 `!`（单目运算符入栈）

```cpp
else if (c == '!') {
    ops.push(c);
}
```

`!` 是单目运算符，优先级最高，先存入 `ops` 栈，等到合适时机再计算。

---

#### (5) 处理 `& | > -`（运算符入栈 + 计算）

```cpp
else if (c == '&' || c == '|' || c == '>' || c == '-') {
    while (!ops.empty() && ops_precedence(c) <= ops_precedence(ops.top())) {
        char op = ops.top();
        ops.pop();
        if (op == '!') {
            bool val = vals.top(); vals.pop();
            vals.push(!val);
        } else {
            bool val2 = vals.top(); vals.pop();
            bool val1 = vals.top(); vals.pop();

            if (op == '&') vals.push(val1 && val2);
            else if (op == '|') vals.push(val1 || val2);
            else if (op == '>') vals.push(!val1 || val2);
            else if (op == '-') vals.push(val1 == val2);
        }
    }
    ops.push(c);
}
```

这里会检查 当前运算符 `c` 的优先级 是否低于或等于栈顶运算符：

- 如果 `c` 的优先级低或相同，就先弹出栈顶运算符并执行计算（确保高优先级运算符先计算）。
- 否则，直接把 `c` 入栈。

---

### Step 3：最终计算

遍历完 `temp_expression` 后，可能 `ops` 栈里还剩运算符，因此需要继续计算：

```cpp
while (!ops.empty()) {
    char op = ops.top();
    ops.pop();
    if (op == '!') {
        bool val = vals.top(); vals.pop();
        vals.push(!val);
    } else {
        bool val2 = vals.top(); vals.pop();
        bool val1 = vals.top(); vals.pop();

        if (op == '&') vals.push(val1 && val2);
        else if (op == '|') vals.push(val1 || val2);
        else if (op == '>') vals.push(!val1 || val2);
        else if (op == '-') vals.push(val1 == val2);
    }
}
```

最终，`vals` 栈中应该只剩计算结果，返回 `"0"` 或 `"1"`：

```cpp
return vals.top() ? "1" : "0";
```

---

## 4. 总结：如何处理中缀布尔表达式？

1. 变量替换：将表达式中的变量替换成 `0/1`。
2. 利用栈处理中缀表达式：
    - 值栈 `vals` 存储 `0/1` 值。
    - 运算符栈 `ops` 处理 `& | > - !` 及 `()` 。
    - 优先级处理：确保 `! > & > | > > -`。
    - 括号匹配：`(` 入栈，`)` 触发计算直到 `(`。
3. 依次解析字符，逐步计算最终结果。

---

### 示例解析

输入表达式：

```
(p & q) | !r
```

假设 `p=1, q=0, r=1`，替换后：

```
(1 & 0) | !1
```

计算过程：

1. `1 & 0 = 0`
2. `!1 = 0`
3. `0 | 0 = 0` 最终返回 `"0"`。

这个思路适用于所有中缀布尔表达式的解析和计算，你可以用类似方法处理更复杂的逻辑表达式！