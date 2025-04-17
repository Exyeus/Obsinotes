[[LUOGU_TREE]]

输入数字个数以及数字们, 找出里面最小的那个
```c
#include <stdio.h>
int main()
{
    int times = 0;
    scanf("%d", &times);
    int minimal = 0,tempo = 0;
    scanf("%d", &minimal);
    for (int i = 0; i < times - 1; i++)
    {
        scanf("%d", &tempo);
        if (minimal > tempo) minimal = tempo;
    }
    printf("%d", minimal);
    return 0;
}
```
写的时候出过几个问题
- 没有充分打草稿, 导致变量是乱的
- `tempo = minimal` 赋值的方向不正确!
- 最后没有`printf`好几次了, 有了结果还不知道输出!
[[输出函数]]