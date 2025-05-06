---
sr-due: 2025-06-24
sr-interval: 61
sr-ease: 292
---

#review 

```c
#include <string>
#include <stack>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <stdexcept>

好的，我来分析一下你最初的代码以及我做出的修改：

你最初的代码存在的问题：

运算符优先级处理不正确： 你的代码在没有括号的情况下，简单地从左到右进行计算，没有考虑运算符的优先级。
例如，p|!q&r 会被错误地计算。正确的优先级应该是 ! > & > | > > > -。
括号处理不完整： 你的代码在处理括号时，只是简单地替换括号内的子表达式的结果，没有正确地处理括号内的运算符优先级。
intToBinaryVector 函数的输出顺序： 虽然 intToBinaryVector 函数本身没有错误，但它返回的二进制向量的顺序是正确的（从高位到低位），这与题目要求的真值表输出顺序一致。
输出格式不完全符合题目要求： 虽然逻辑正确，但输出的格式（空格，换行）可能不完全符合题目严格的要求。
没有实现运算符优先级函数: 缺少运算符优先级函数，导致无法正确计算表达式。
我做出的修改：
实现了运算符优先级的处理我使用了两个栈，一个用于存储运算符 (ops)，另一个用于存储操作数 (vals)。我使用了一个 ops_precedence 函数来确定运算符的优先级。
在遇到运算符时，我会将它与栈顶的运算符进行比较，如果栈顶运算符的优先级更高或相等，则先计算栈顶的运算符，然后再将当前运算符入栈。
更正了括号的处理： 在遇到左括号时，我将其入栈。在遇到右括号时，我不断计算栈顶的运算符，直到遇到左括号，然后将左括号出栈。
修改了 direct_infix 函数的逻辑： 我完全重写了 direct_infix 函数，使其能够正确地处理运算符优先级和括号。
修改了输出格式： 确保输出的空格和换行符与题目要求完全一致。
添加了运算符优先级函数: 添加了ops_precedence函数，用于判断运算符优先级。
总结：

总的来说，你最初的代码的主要问题在于没有正确地处理运算符的优先级和括号。
我通过使用两个栈和一个运算符优先级函数，以及重写 direct_infix 函数，解决了这些问题。此外，我还确保了输出格式与题目要求完全一致。

using namespace std;

vector<char> letter_analysis(string expression)
{
    vector<char> base_list;
    for (int i = 0; i < expression.size(); i++)
    {
        if (isalpha(expression[i]) &&
            find(base_list.begin(), base_list.end(), expression[i]) == base_list.end())
        {
            base_list.push_back(expression[i]);
        }
    }
    sort(base_list.begin(), base_list.end());
    return base_list;
}
```

>上面这个函数，分析所给表达式有几个命题变项，给出其 `vector<char>` 类型的分析结果，既可以直接访问取得值，又可以使用 `size` 等方法获得数量用于循环分析。
>注意，`find` 和 `sort` 都来源于 `algorithm` ，并且需要圈定搜索范围，因此选择传入分析对象的 begin 和 end 两个类似 `@property` 的东西。

```cpp

int ops_precedence(char op);

string direct_infix(string expression, vector<char> base_list, vector<char> corresponding_value_list)
{
    vector<pair<char, char>> dictionary;
    for (int i = 0; i < base_list.size(); i++)
    {
        dictionary.push_back(make_pair(base_list[i], corresponding_value_list[i]));
    }
```

>由我制定，接收 `corresponding` 这个 `vector<char>` ，有助于在生成 $2^{n}$ 个样例进行测试的时候，每次调用这个函数并且传入不同的 0 1 序列。
>原理不再赘述

```cpp
    string temp_expression = expression;
    for (auto &pair : dictionary)
    {
        for (size_t i = 0; i < temp_expression.size(); ++i)
        {
            if (temp_expression[i] == pair.first)
            {
                temp_expression[i] = pair.second;
            }
        }
    }
```

>分析 [[C++ for (type val ：container)]]
>这里使用一个 `expression` 的 copy，来将命题变项都转化成为字符串的 0 和 1

```cpp
    stack<char> ops;
    stack<bool> vals;

    for (int i = 0; i < temp_expression.length(); ++i) {
    // 循环遍历分析
        char c = temp_expression[i];

        if (c == '0' || c == '1') {
            vals.push(c == '1');
        // 妙手！
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
        // End of scope detected, trace back and analyse
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                bool val2 = vals.top();
                vals.pop();
                bool val1 = vals.top();
                vals.pop();
                if (op == '&') vals.push(val1 && val2);
                else if (op == '|') vals.push(val1 || val2);
                else if (op == '>') vals.push(!val1 || val2);
                else if (op == '-') vals.push(val1 == val2);
            }
            ops.pop(); // Pop the '('
```

> 这里需要更多的分析和离散数学知识。
> 如何确保 `>` 等运算符不会引发错误？

```cpp
        } else if (c == '!') {
            ops.push(c);
        } else if (c == '&' || c == '|' || c == '>' || c == '-') {
            while (!ops.empty() && ops_precedence(c) <= ops_precedence(ops.top())) {
        不空，并且 c 的优先级小于 ops 最上面那一个
                char op = ops.top();
                ops.pop();
                if (op == '!') {
                    bool val = vals.top();
                    vals.pop();
                    vals.push(!val);
            换成一个相反的数值
                } else {
                    bool val2 = vals.top();
                    vals.pop();
                    bool val1 = vals.top();
                    vals.pop();
                    if (op == '&') vals.push(val1 && val2);
                    else if (op == '|') vals.push(val1 || val2);
                    else if (op == '>') vals.push(!val1 || val2);
                    else if (op == '-') vals.push(val1 == val2);
                }
            }
            ops.push(c);
        }
    }
```

>面对没有括号的公式部分进行操作

```cpp
    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        if (op == '!') {
            bool val = vals.top();
            vals.pop();
            vals.push(!val);
        } else {
            bool val2 = vals.top();
            vals.pop();
            bool val1 = vals.top();
            vals.pop();

            if (op == '&') vals.push(val1 && val2);
            else if (op == '|') vals.push(val1 || val2);
            else if (op == '>') vals.push(!val1 || val2);
            else if (op == '-') vals.push(val1 == val2);
        }
    }

    return vals.top() ? "1" : "0";
}

int ops_precedence(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    if (op == '>') return 0;
    if (op == '-') return 0;
    return -1;
}
```

优先级判定！根据 字符串 cases ，直接输出整数以利于比较！

```cpp
std::vector<char> intToBinaryVector(int num, int bit_length)
{
    if (bit_length <= 0 || bit_length > 32)
    {
        throw std::invalid_argument("Bit length must be between 1 and 32");
    }

    std::bitset<32> bs(num);
    std::vector<char> result;

    for (int i = bit_length - 1; i >= 0; --i)
    {
        result.push_back(bs[i] ? '1' : '0');
    }
    return result;
}

int main()
{
    string expression;
    cin >> expression;
    vector<char> base_list = letter_analysis(expression);
```

>以下，打印合规部分

```cpp
    for (int i = 0; i < base_list.size(); i++)
    {
        cout << base_list[i] << (i == base_list.size() - 1 ? " " : " ");
    }
    cout << expression << endl;

    int base_sum = base_list.size();
    for (int j = 0; j < pow(2, base_sum); j++)
    {
        vector<char> temp_dict = intToBinaryVector(j, base_sum);
        for (char value : temp_dict)
        {
            cout << value << " ";
        }
        vector<char> corresponding_values;
        for(char c : temp_dict){
            corresponding_values.push_back(c);
        }
        cout << direct_infix(expression, base_list, corresponding_values) << endl;
    }
    return 0;
}

```

[[GPT解释逻辑中缀表达式栈处理]]

