再处理一些基本字符的时候，利用char之间的相减或者是直接以最小的那个为基底，然后加上一些相对的值来实现不同字符的转换。

例如
```c
'0' + 1;
'a' + 2
char ^ 32;
```

----
此外，
在 C 语言中，利用异或（`^`）运算符可以通过操作 ASCII 值来实现英文字符的大小写转换。英文字母的大小写之间有固定的差值：大写字母与小写字母的 ASCII 值相差 32。因此，通过对字母字符与 `0x20`（即 32 的十六进制表示）进行异或运算，可以在大写字母和小写字母之间进行转换。

### 代码示例：
```c
#include <stdio.h>

int main() {
    char ch;

    // 输入一个字符
    printf("请输入一个字符：");
    scanf("%c", &ch);

    // 使用异或运算转换大小写
    ch = ch ^ 0x20;

    // 输出转换后的字符
    printf("转换后的字符是：%c\n", ch);

    return 0;
}
```

### 原理：
- 大写字母的 ASCII 码范围是 `65 ('A')` 到 `90 ('Z')`。
- 小写字母的 ASCII 码范围是 `97 ('a')` 到 `122 ('z')`。
- 大小写字母之间的差值是 `32`，即 `0x20`。
- 异或运算的性质是：如果两个相同的位进行异或，结果为 `0`；如果不同，则为 `1`。因此，使用 `^ 0x20` 可以在字符是大写字母时转换为小写字母，反之亦然。

### 示例：
- 输入 `'A'`（ASCII: 65），异或 `0x20` 后得到 `'a'`（ASCII: 97）。
- 输入 `'a'`（ASCII: 97），异或 `0x20` 后得到 `'A'`（ASCII: 65）。

这种方法非常高效，且只适用于英文字母。如果输入字符是其他符号或数字，它们将保持不变。