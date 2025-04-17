```cpp
#include <iostream>
#include <vector>

# [NOIP2015 提高组] 神奇的幻方

## 题目背景

NOIp2015 提高组 Day1T1

## 题目描述

幻方是一种很神奇的 $N\times N$ 矩阵：它由数字 $1,2,3,\cdots \cdots ,N \times N$ 构成，且每行、每列及两条对角线上的数字之和都相同。

当 $N$ 为奇数时，我们可以通过下方法构建一个幻方：

首先将 $1$ 写在第一行的中间。

之后，按如下方式从小到大依次填写每个数 $K \ (K=2,3,\cdots,N \times N)$ ：

1. 若 $(K-1)$ 在第一行但不在最后一列，则将 $K$ 填在最后一行， $(K-1)$ 所在列的右一列；
2. 若 $(K-1)$ 在最后一列但不在第一行，则将 $K$ 填在第一列， $(K-1)$ 所在行的上一行；
3. 若 $(K-1)$ 在第一行最后一列，则将 $K$ 填在 $(K-1)$ 的正下方；
4. 若 $(K-1)$ 既不在第一行，也不在最后一列，如果 $(K-1)$ 的右上方还未填数，则将 $K$ 填在 $(K-1)$ 的右上方，否则将 $K$ 填在 $(K-1)$ 的正下方。

现给定 $N$ ，请按上述方法构造 $N \times N$ 的幻方。

## 输入格式

一个正整数 $N$，即幻方的大小。

## 输出格式

共 $N$ 行，每行 $N$ 个整数，即按上述方法构造出的 $N \times N$ 的幻方，相邻两个整数之间用单空格隔开。

## 样例 #1

### 样例输入 #1
3
### 样例输出 #1
8 1 6
3 5 7
4 9 2
## 提示
对于 $100\%$ 的数据，对于全部数据， $1 \leq N \leq 39$ 且 $N$ 为奇数。

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    // Considering that N is odd number:
    static int x = 0;
    static int y = (N+1)/2 - 1;
    matrix[x][y] = 1;
    for (int i = 2; i < N*N + 1; i++)
    {
        if (x == 0 && y < N - 1 && y > -1)
        // First line, not last row
        {
            x = N - 1; y += 1;
        }
        else if (y == N - 1 && x > 0 && x < N)
        // Last cloumn but not first line
        {
            y = 0; x -= 1;
        }
        else if (x == 0 && y == N-1)
        // First line, last column
        {
            x += 1;
        }
        else if (x > 0 && y < N-1 && x < N && y > -1)
        {
            if (matrix[x-1][y+1] == 0)
            {
                x = x - 1; y = y + 1;
            }
            else{ x += 1;}
        }
        // Now the x y have been figured out
        matrix[x][y] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

> 数组, 是先放行再放列
> 往下, x++, 往右, y++
> 判断符, 要用 ==
> `if` 里面不要用分号