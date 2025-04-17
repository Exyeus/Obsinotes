```
“冒泡法”将当前数组里最大的一个元素通过若干次相邻元素的交换，冒到顶部（即排到正确的位置）。然后将数组规模减小1，对这个子数组重复冒泡过程，执行n-1遍后当前数组即为有序数组。选择排序实际是对“冒泡法”的优化算法：每次只需一次交换就可以将一个元素放到正确的位置。对于当前数组，通过一次扫描，查找数组中的最小元素。然后将最小元素与当前数组中第一个元素交换。对从二个元素开始到最后元素结束的这个子数组重复这个过程。执行n-1遍后有序。这种排序与冒泡排序相似，对于n个元素的数组，要n-1遍，对每个子数组，要用n-1次比较以求得最小值。当处理包含一个元素的子数组时，数组已经排序完毕。编写递归程序，完成这个算法。   
输入格式
　　第一行：一个整数n（n<=100）  
　　第二行：n个整数a[i]（保证a[i]在int范围内）  
输出格式
　　按倒序（从最后一步到第一步）输出若干次交换步骤，以 i<->j:当前数组 的形式输出，i和j表示进行交换的两个元素在当前数组中的下标（从1开始，j是当前找到的最小元素的下标），每个步骤占一行；（如果a[i]本来就在正确的位置，则不需要交换）  
　　紧接一行：以Total steps:tot 的形式输出，tot表示总的交换次数；  
　　最后一行：以Right order:正确序列 的形式输出。  
输入样例
5  
3 1 2 4 5  

输出样例

2<->3:1 2 3 4 5  
1<->2:1 3 2 4 5  
Total steps:2  
Right order:1 2 3 4 5
```

```c
#include <stdio.h>

// 最大数组长度
#define MAXN 100

// 定义全局变量存储状态
static int number_array[MAXN] = {0};         // 原始数组
static int process_steps[MAXN][2] = {0};     // 每次交换的索引记录
static int state_history[MAXN][MAXN] = {0};  // 保存每次排序后的数组状态
static int process_times = 0;                // 交换次数计数器

// 检查数组是否有序
int checker(int length) {
    for (int k = 0; k < length - 1; k++) {
        if (number_array[k] > number_array[k + 1]) {
            return 0; // 如果有逆序对，则数组无序
        }
    }
    return 1; // 数组有序
}

// 递归选择排序
void sorter(int length, int prt) {
    // 递归终止条件
    if (prt >= length - 1 || checker(length)) {
        return; // 已完成排序或数组已完全有序
    }

    // 找到当前未排序部分的最小值及其位置
    int minimal = number_array[prt];
    int the_position = prt;
    for (int i = prt + 1; i < length; i++) {
        if (number_array[i] < minimal) {
            minimal = number_array[i];
            the_position = i;
        }
    }

    // 如果需要交换，执行交换并记录交换信息
    if (the_position != prt) {
        int temp = number_array[prt];
        number_array[prt] = number_array[the_position];
        number_array[the_position] = temp;

        // 保存交换的步骤
        process_steps[process_times][0] = prt + 1;          // 记录第一个位置（从 1 开始计数）
        process_steps[process_times][1] = the_position + 1; // 记录第二个位置
        // 保存当前数组状态
        for (int i = 0; i < length; i++) {
            state_history[process_times][i] = number_array[i];
        }
        process_times++; // 增加交换计数
    }
    // 递归调用处理剩余部分
    sorter(length, prt + 1);
}
int main() {
    int n = 0;

    // 输入数组长度
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        scanf("%d", &number_array[j]);
    }
    // 调用递归排序
    sorter(n, 0);

    // 倒序输出每次交换步骤及排序状态
    for (int i = process_times - 1; i >= 0; i--) {
        printf("%d<->%d:", process_steps[i][0], process_steps[i][1]);
        for (int j = 0; j < n; j++) {
            printf("%d", state_history[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    // 输出总步数
    printf("Total steps:%d\n", process_times);
    // 输出排序结果
    printf("Right order:");
    for (int i = 0; i < n; i++) {
        printf("%d", number_array[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
```
[[递归总思路]]

这里其中反应递归的一些思考方法。每次处理完后，需要排序的数组的大小都会减一，也就是所谓的规模变小，但是具体的方法还是一样的。同时，有题目可以读到这里的输出需要从最后还好的那一步，逐渐往下输出，直到第一步操作，结合一般的递归示意图就可以发现该把输出放在调用递归的后面确保越早处理的越晚输出。