先上自己的代码 存在一些问题  ???? 但是好像莫名其妙就又 ACCEPTED 了??
```c
# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    // 分执行完的环数的奇数偶数之分,来进行下一轮执行.
    int (**matrix) = malloc(sizeof(int *) * (n+1));
    for (int i = 0; i < n; i++)
        matrix[i] = malloc(sizeof(int) * (n+1));
    matrix[0][0] = 1;
    int xp = 0, yp = 0, fill_in_number = 2;
    // 已经加了, 以后也是先用再加
    for (int circle_time = 2; circle_time < n+1; circle_time++)
    {
        // 接下来分奇数和偶数执行
        if (circle_time % 2 == 1)//刚刚执行完的是奇数 换之前打印出转置矩阵!!!!!!!!!!!!
        {
            xp += 1;
            matrix[xp][yp] = fill_in_number++;
            for (int do_times = 0; do_times < circle_time - 1; do_times++)
            {
                yp++;
                matrix[xp][yp] = fill_in_number++;
            }
            // 到达最低点, 现在需要向左走
            for (int do_times = 0; do_times < circle_time - 1; do_times++)//!!!!!!!!!!!!!!!!!!!!!!!
            {
                xp--;
                matrix[xp][yp] = fill_in_number++;
            }
        }
        // 分析完毕, 接下来分析执行完偶数
        else if (circle_time % 2 == 0)
        {
            yp += 1;
            matrix[xp][yp] = fill_in_number++;
            for (int do_times = 0; do_times < circle_time - 1; do_times++)
            {
                xp++;
                matrix[xp][yp] = fill_in_number++;
            }
            for (int do_times = 0; do_times < circle_time - 1; do_times++)
            {
                yp--;
                matrix[xp][yp] = fill_in_number++;
            }
        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
```

### 早期的shabby代码
```c
# include <stdio.h>
int main(){
    unsigned int ring_number;
    scanf("%u", &ring_number); // ==6
    unsigned int number_matrix[ring_number][ring_number];
    unsigned int original_x = 0, original_y = 0; // Here we defined where 1 is
    unsigned int first_number = 1;
/*
{1, 1, 1, 1}
{1, 1, 1, 1}
{1, 1, 1, 1}
{1, 1, 1, 1}
*/
    number_matrix[0][0] = 1; // Here we place 1
    printf("number_matrix[%u][%u] = %u;", original_y, original_x, first_number);
    for (int original_place = 1; original_place < ring_number; original_place ++ ){// Original_Place 系所围成的环数, with an original value of 1
        if (original_place % 2 == 1){ // 环数是奇数, 那么先右,再下,再左. Here we have had 1 as the first ring value
            original_x ++;
            first_number ++;
            number_matrix[original_y][original_x] = first_number;
            printf("number_matrix[%u][%u] = %u;\n", original_y, original_x, first_number);
            for (int step = 0; step < original_place - 1; step ++){ // 坐标要改, 输入值也要改 Do 1 time
                // 现在已经发生必然为1的移动, 接下来向下移动
                original_y ++;
                first_number ++;
                number_matrix[original_y][original_x] = first_number;
                printf("number_matrix[%u][%u] = %u\n;", original_y, original_x, first_number);
            }
            for (int step = 0; step < original_place - 1; step ++ ){/////????????????
                original_x --;
                first_number ++;
                number_matrix[original_y][original_x] = first_number;
                printf("number_matrix[%u][%u] = %u\n;", original_y, original_x, first_number);
            }
            original_place ++;
        }
        else{ // 环数是偶数, 那么先下,再右,再上
            original_y ++;
            first_number ++;
            number_matrix[original_y][original_x] = first_number;
            printf("number_matrix[%u][%u] = %u\n;", original_y, original_x, first_number);
            for ( int step = 0; step < original_place - 1; step ++){
                original_x ++;
                first_number ++;
                number_matrix[original_y][original_x] = first_number;
                printf("number_matrix[%u][%u] = %u\n;", original_y, original_x, first_number);
            }
            for (int step = 0; step < original_place - 1; step ++){
                original_y --;
                first_number ++;
                number_matrix[original_y][original_x] = first_number;
                printf("number_matrix[%u][%u] = %u\n;", original_y, original_x, first_number);
            }
            original_place ++;

        }
    }
    // Now let's print it out !
    for (int i1 = 0; i1 < ring_number; i1 ++){
        for (int i2 = 0; i2 < ring_number; i2 ++){
            printf("%u ", number_matrix[i1][i2]);
        }
        printf("\n");
    }
   for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("number_matrix[%u][%u] = %u\n", i, j, number_matrix[i][j]);
        }
    }

    return 0;
}
```

#### 批斗一下:
- 没有约定好, 到底从哪里开始一轮循环, 在哪里结束一轮循环
- 没有考虑到, 怎样的循环, 能够做到善始善终, 能够以自身为周期, 最大程度地填满整个生成数字的过程
- 表达不够简洁, 没有注意到 可以有 左表达式 = 右边表达式[[i++]], 这样十分简洁, 可以供下次取用
- 有事没事用unsigned, 实在无聊. 又不是什么极限范围[[数据类型]]