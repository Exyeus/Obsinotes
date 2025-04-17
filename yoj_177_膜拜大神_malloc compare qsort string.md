#qsort  #compare  #二维数组 #malloc 
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringanalyse(char *string)
{
    int result = 0;
    for (int i = 0; i < 10; i++) // 假设每个字符串长度为10
    {
        result += (int)(string[i] - '0');
    }
    return result;
}

int cmp(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b); // 使用strcmp比较字符串
}

int main()
{
    int men = 0, kk = 0;
    scanf("%d %d", &men, &kk);

    char **array = (char **)malloc(men * sizeof(char*));
    for (int h = 0; h < men; h++)
    {
        array[h] = malloc(11 * sizeof(char)); // 为每个字符串分配空间
    }

    char **result = malloc(men * sizeof(char*)); // 存储符合条件的学生学号
    int k = 0;

    for (int i = 0; i < men; i++)
    {
        scanf("%s", array[i]); // 输入学号
    }

    for (int j = 0; j < men; j++)
    {
        if (stringanalyse(array[j]) % kk == 0)
        {
            result[k++] = array[j]; // 将符合条件的学号存入 result
        }
    }

    qsort(result, k, sizeof(char*), cmp); // 对符合条件的学号排序

    printf("%d\n", k);
    for (int m = 0; m < k; m++)
    {
        printf("%s\n", result[m]); // 输出排序后的学号
    }

    // 释放内存
    for (int h = 0; h < men; h++) {
        free(array[h]);
    }
    free(array);
    free(result);

    return 0;
}
```
### 注意
- The unchangeable form in using qsort and compare
- The depth of pointers from variables and entities down
- The method to avoid a 0 at the beginning of each string
- The grasp of requirement in the problem
