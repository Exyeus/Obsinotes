---
sr-due: 2025-09-07
sr-interval: 146
sr-ease: 290
---

#review 

#CIO  [[LUOGU_TREE]]

## 题目描述

一般的手机的键盘是这样的：

![](https://cdn.luogu.com.cn/upload/image_hosting/yq2orii6.png)

要按出英文字母就必须要按数字键多下。例如要按出 $\tt x$ 就得按 $9$ 两下，第一下会出 $\tt w$，而第二下会把 $\tt w$ 变成 $\tt x$。$0$ 键按一下会出一个空格。

你的任务是读取若干句只包含英文小写字母和空格的句子，求出要在手机上打出这个句子至少需要按多少下键盘。

##### 输入格式

一行句子，只包含英文小写字母和空格，且不超过 200 个字符。

##### 输出格式

一行一个整数，表示按键盘的总次数。

##### 输入输出样例 #1
##### 输入 #1
```
i have a dream
```
##### 输出 #1
```
23
```
---

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence;
    
    getline(cin, sentence);
    //cin >> sentence;
    int total_num = 0;
    int length = sentence.size();
    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == ' ')
        {
            total_num += 1;
        }
        else if (sentence[i] == 'z' || sentence[i] == 's')
        // Having not use "==" makes a big difference.
        {
            total_num += 4;
        }
        else if (sentence[i] <= 'r' && sentence[i] >= 'a')
        {
            total_num += (sentence[i] - 'a')%3 + 1;
        }
        else if (sentence[i] >= 't' && sentence[i] <= 'y')
        {
            total_num += (sentence[i] - 't')%3 + 1;
        }
    }
    // Why the result doubled?I am counting the times to press the key,
    // when I am using a 9-key keyboard.
    // The reason is that I count the space as well.
    // So I should add 1 to the total_num.
    cout << total_num << endl;
    // Type in "i have a dream" and the output is 23.
    // But why did i actually got 21?
    // The reason is that I did not count the space.
    // So I should add 1 to the total_num.

    return 0;
}
```

### #洛反思

- 不要只会用 `cin` , `getline` 是用于获取带有空格的字符串行的利器. 注意, `getline` 会把 `\n` 也读入字符串之中.
- 注意，是 `getline(cin, container)` 而不是 `getline(container, cin)`
- 读题还要更细. pqrs 四个也是占了一个按键, 所以 `s` 之后的*就不能减去前面的字符再取模来求得了* !事实上我愿称之为本题 MVP

关于求模, 或许可以试着使用 `advance` 来进行运算并且求得, 反正其处理的也是数字, 直接把数字那个参数变成递增 + 取模所得指针差