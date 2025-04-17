#malloc #指针 #多维数组
[[YOJ_TREE]] [[qsort-compare]] [[qsort 使用及compare写法及传值规则]] 
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-10
注意这里的浮点数表示法以及用宏来使得阅读更加方便
#define DIM 8 // 新娘数据维度

// 计算相似度
double similarity(double a[], double b[], int n) {
    double dot_product = 0, norm_a = 0, norm_b = 0;
    for (int i = 0; i < n; i++) {
        dot_product += a[i] * b[i];
        norm_a += a[i] * a[i];
        norm_b += b[i] * b[i];
    }
使用循环来计算这个点积，比我堆表达式更加优越，虽然只是在阅读上更优
    if (norm_a < EPSILON || norm_b < EPSILON) {
        return 0.0; // 避免除以零
    }
    return dot_product / (sqrt(norm_a) * sqrt(norm_b));
直接return，少建立一个变量来存储这些东西
}

// 排序函数：相似度降序；相同相似度按身份证号升序
int compare(const void *a, const void *b) {
经典compare函数定义头，void指针传入配上后面的强制转换，如果是1就把后面的那个参数放到前面去！这里是二维数组，一个数组含有若干控制另外的数组的指针，只需要对这些指针排序就能够实现最后的打印输出！
    double *row_a = *(double **)a;
    double *row_b = *(double **)b;

    // 按相似度降序排序
    double diff = row_b[8] - row_a[8];
    if (fabs(diff) >= EPSILON) { // 相似度不同
        return (diff > 0) ? 1 : -1;
    }
审题，记得是大于等于，因为一旦小于epsilon，就要被判定为相等。而且这里只有一次计算，不需要像for循环那样避免用 小于等于 或者 大于等于！

    // 相似度相等，按身份证号升序排序
    long long id_a = (long long)row_a[0];
    long long id_b = (long long)row_b[0];
    return (id_a > id_b) ? -1 : (id_a < id_b) ? 1 : 0;
}
nimd 坑中之坑！为什么其他的测试点都不检验这个啊！
int main() {
    int men, nicemen;
    scanf("%d %d", &men, &nicemen);

    // 读取新娘数据
    double bride[DIM];
    for (int i = 0; i < DIM; i++) {
        scanf("%lf", &bride[i]);
    }

    // 分配二维数组存储所有人的数据
    double **array = malloc(men * sizeof(double *));
malloc管二维数组的好表达式！甚至N维数组也可以这么玩！
    if (!array) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    for (int i = 0; i < men; i++) {
        array[i] = malloc((DIM + 2) * sizeof(double)); // 包括相似度列
        if (!array[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            return -1;
        }
    }

    // 读取每个人的数据并计算相似度
    for (int i = 0; i < men; i++) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",
              &array[i][0], &array[i][1], &array[i][2], &array[i][3],
              &array[i][4], &array[i][5], &array[i][6], &array[i][7],
              &array[i][8]);

        array[i][8] = similarity(bride, &array[i][1], DIM); // 计算相似度存储在第9列
    }

    // 排序
    qsort(array, men, sizeof(double *), compare);
qsort的使用：处理的数组(必须是一维数组)，要排序的数量，排序的对象(double指针)，选择的调用函数，这里也是指针指向函数的案例！
    // 输出结果
    for (int i = 0; i < nicemen; i++) {
        printf("%.0f", array[i][0]); // 输出身份证号
        if (i < nicemen - 1) {
            printf(" "); // 中间用空格分隔
        }
    }
    printf("\n");

    // 释放内存
    for (int i = 0; i < men; i++) {
        free(array[i]);
    }
    free(array);
用完malloc记得复原，防止memory leakage！
    return 0;
}

```