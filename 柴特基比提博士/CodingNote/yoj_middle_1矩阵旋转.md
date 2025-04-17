```c
#include <stdio.h>
int main()
{
    int input[50][50] = {0};
    int output[50][50] = {0};
    int line = 0, column = 0;

    scanf("%d %d", &line, &column);

    // Now let us get all in
    int i = 0, j = 0, k = 0;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &k);
            input[i][j] = k;
        }
    }

    //  Now let us process the given angle
    long long angle = 0;
    int actual_pattern = 0;
    scanf("%lld", &angle);
    if (angle > 0)
    {
        actual_pattern = (angle / 90) % 4;// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // result : 1 2 3 4
    }
    else if (angle == 0)
        actual_pattern = 0;
    else
        actual_pattern = (4 + ((angle / 90) % 4))%4;
    // Let us create 3 function to done that work
    if (actual_pattern == 0)
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%d ", input[i][j]);
            }
            printf("\n");
        }
    }
    /////////////////////////////////////////////////////////////////////
    else if (actual_pattern == 1)
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                output[j][line - i - 1] = input[i][j];
                //First the whole column
            }
        }
        for (int k = 0; k < column; k++)
        {
            for (int m = 0; m < line; m++)
            {
                printf("%d ", output[k][m]);
            }
            printf("\n");
        }
    }
    ////////////////////////////////////////////////////////////////////
    else if (actual_pattern == 2)
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                output[line - i - 1][column - j - 1] = input[i][j];
            }
        }
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%d ", output[i][j]);
            }
            printf("\n");
        }
    }
    ////////////////////////////////////////////////////////////////////
    else if (actual_pattern == 3)
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                output[column - 1 - j][i] = input[i][j];
            }
        }
        for (int k = 0; k < column; k++)
        {
            for (int m = 0; m < line; m++)
            {
                printf("%d ", output[k][m]);
            }
            printf("\n");
        }
    }
    return 0;
}
```

打80分的原因就在于, 负数情况下模出零的时候, 得到的是一个4, 没有与之相关的命令可以执行.
总结经验:
1. [[数据违规]]
2. [[奇偶性分类讨论]][[lgP5719_分类求均]]给我狠狠地分类讨论!要把这些该死的题目当作高中数学来做!
3. [[观察测试点]]如果测试点是空的, 可以考虑这些代码没有受到执行. 尽管这里的错误输出就是正确答案. 其实这也是非常神奇的一点, 为什么是错的但是还是有输出?

后续优化:

1. 把模式判断归宗成为一个总体的
2. 熟练使用`malloc`
3. 要找到一些最简单的映射关系. 例如这里就可以考虑, 先写`input[i][j]` 放在右边, 然后再把基于映射规则的`output`表达式放在左边.
