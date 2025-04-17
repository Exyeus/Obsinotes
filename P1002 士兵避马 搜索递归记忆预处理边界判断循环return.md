---
sr-due: 2025-07-13
sr-interval: 102
sr-ease: 270
---

#review 

[[LUOGU_TREE]]
## 我的代码
```cpp
#include <iostream>
#include <vector>
// Perhaps useless

using namespace std;

struct coord
{
    int x, y;
};

coord horse;

int span_range[8][2] = {{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},\
                        {-2, -1}, {-2, 1},{-1, 2}};
int recur(coord co)
{
    if ((co.x == 0 && co.y == 1) || (co.x == 1 && co.y == 0))
    {
        return 1;
    }
    // 如果遇到了马怎么办?我的意思是, 向左或者向上回退之后, 那个坐标是一个马
    // 不再调用两个回退方向的recur, 并且, return 一个 0, 表示去这个点有
    // 零种方案实现, return出来的零, 返回上面一级函数, 告诉它此路不通
    int lok = 1, uok = 1;
    coord backu;
    coord backl;
    
    if (co.x > 0)
    {
        //uok = 0;
        backu = {co.x - 1, co.y};
        for (int i = 0; i < 8; i++)
        {
            int horse_x = horse.x + span_range[i][0];
            int horse_y = horse.y + span_range[i][1];
            // 不可以同时判定, 因为一次循环中只会有一个点!
            /*if (backl.x == horse_x && backl.y == horse_y)
            {
                lok = 0;
            }*/
            if ((backu.x == horse_x && backu.y == horse_y)\
            || (backu.x == horse.x && backu.y == horse.y))
            {
                uok = 0;
            }
        }
    }
    else{uok = 0;}
    if (co.y > 0)
    {
        backl = {co.x, co.y - 1};
        for (int i = 0; i < 8; i++)
        {
            int horse_x = horse.x + span_range[i][0];
            int horse_y = horse.y + span_range[i][1];
            // 不可以同时判定, 因为一次循环中只会有一个点!
            if ((backl.x == horse_x && backl.y == horse_y)\
             || backl.x == horse.x && backl.y == horse.y)
            {
                lok = 0;
            }
            /*if (backu.x == horse_x && backu.y == horse_y)
            {
                uok = 0;
            }*/
        }
    }
    else
    {
    // 马的控制区域循环, 进行检查
    // 在这个函数的定义中, 它必须决定是否调用上面一级的函数.
       lok = 0; 
    }
    if (!lok && uok)// 左边不可以
    {
        return recur(backu);
    }
    else if (lok && !uok)
    {
        return recur(backl);
    }
    else if (!lok && !uok)
    {
        return 0;
    }
    return recur(backl) + recur(backu);
}

int main()
{
    int xb, yb, xh, yh;
    cin >> xb >> yb >> xh >> yh;
    horse.x = xh; horse.y = yh;
    coord B{xb, yb};
    cout << recur(B);
    return 0;
}
```

### 注意事项
>每次都要记得检查边界, 所有涉及数组的题都要去检查边界!
>注意return这个要求. 出现在条件作用域里面的东西, 拿去return都会出事
>条件作用域里面有return但是外面没有return, 也不行
>为了避免函数return导致提前终止, 必须对于所有情况进行限制, 例如, 这里对两个方向一共四种情况就进行了分别讨论, 虽然, 最后的讨论由一个直接的return给出.
## Copilot解答与GPT解释
这段代码的目标是解决一个网格路径问题，其中有一个“马”限制了部分路径的可行性。给定一个矩阵，我们的任务是计算从左下角到右上角的路径数量，路径可以向上和向右移动，但马的控制范围内的路径是不可行的。下面我会详细解析代码并讲解其中高效的技术和算法。

### 1. **问题背景**

- **输入**: 给定一个大小为 `bx * by` 的网格，起点为 `(0, 0)`，终点为 `(bx, by)`。马的位置为 `(mx, my)`，并且马能够控制其周围的 8 个点，这些点是障碍物。
	注意, 点的数量比格子的数量 多 1
    
- **目标**: 计算从 `(0, 0)` 到 `(bx, by)` 的路径数量。路径只能向右或者向上移动，并且马控制的点不可以经过。
    

### 2. **代码解析**

#### `init_horse_points` 函数

```cpp
void init_horse_points() {
    // 标记马本身位置
    blocked[mx][my] = true;
    
    // 标记马控制的8个点
    int dx[] = {-2,-2,-1,-1,1,1,2,2};
    int dy[] = {-1,1,-2,2,-2,2,-1,1};
    
    for(int i = 0; i < 8; i++) {
        int nx = mx + dx[i];
        int ny = my + dy[i];
        if(nx >= 0 && nx <= bx && ny >= 0 && ny <= by) {
            blocked[nx][ny] = true;
        }
    }
}
```

- **功能**: 这部分代码标记了马的位置以及它控制的 8 个点。马控制的点是马能直接跳跃到的地方，并且这些点将被标记为“不可达”（`blocked`）。
    
- **效率**: 这是一次预处理步骤，时间复杂度为 O(1)，因为最多标记 8 个点。而且我们通过 `blocked` <font color="#31d83b">数组快速标记这些点</font>，使得后续的动态规划过程中能迅速判断某个点是否被马控制。
    

#### `solve` 函数

```cpp
long long solve(int x, int y) {
    // 基础情况
    if(x < 0 || y < 0) return 0;
    if(blocked[x][y]) return 0;
    if(x == 0 && y == 0) return 1;
    
    // 记忆化
    if(dp[x][y] != -1) return dp[x][y];
    
    // 计算从左边和上边来的路径数
    return dp[x][y] = solve(x-1, y) + solve(x, y-1);
}
```

- **功能**: `solve` 是一个递归函数，使用记忆化搜索（Memoization）计算从 `(x, y)` 到 `(0, 0)` 的路径数。
    
    - **基础情况**: 如果 `(x, y)` 超出了网格范围或者该点被马控制，则返回 0。
    - 如果 `(x, y)` 是起点 `(0, 0)`，则返回 1，因为这是唯一的一条路径。
    - **记忆化**: 如果当前点 `(x, y)` 的路径数量已经计算过（即 `dp[x][y]` 不等于 -1），则直接返回计算结果，避免重复计算。
    - **递归计算**: 从 `(x, y)` 点可以通过两条路径到达：
        - 从左边 `(x-1, y)`
        - 从上边 `(x, y-1)`
    - 递归计算这些路径的总和并保存结果。
- **效率**:
    
    - **记忆化**: `dp[x][y]` 数组用于缓存已经计算的结果，这样避免了重复的计算。在传统的递归方式中，每个子问题可能会被计算多次，而通过记忆化可以将计算次数降低到 O(bx * by)。
    - **时间复杂度**: 每个 `solve(x, y)` 的递归调用最多会被调用一次，因此整体时间复杂度为 O(bx * by)，其中 `bx` 和 `by` 是网格的大小。每个点的结果只会计算一次。

#### `main` 函数

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> bx >> by >> mx >> my;
    
    // 初始化dp数组
    memset(dp, -1, sizeof(dp));
    
    // 预处理马的控制范围
    init_horse_points();
    
    cout << solve(bx, by) << endl;
    return 0;
}
```

- **功能**:
    - 读取输入，包括网格的大小 `bx`, `by` 和马的位置 `mx`, `my`。
    - 初始化 `dp` 数组为 -1，表示所有点尚未计算过。
    - 调用 `init_horse_points` 函数标记马的位置和它控制的区域。
    - 调用 `solve` 函数计算从 `(0, 0)` 到 `(bx, by)` 的路径数。
- **效率**:
    - `ios::sync_with_stdio(false)` 和 `cin.tie(0)` 用于加速输入输出，这对程序的整体性能有帮助，尤其在需要频繁读写数据时。

### 3. **高效技术和算法分析**

- **动态规划（DP）**: 这是代码中最重要的技术之一。通过使用 `dp[x][y]` 来存储到达每个点的路径数，我们避免了重复的计算，使得问题可以在 O(bx * by) 的时间内解决。
    
- **记忆化搜索（Memoization）**: 通过记忆化递归结果，避免了子问题的重复计算。每个状态只会计算一次，并且之后通过 `dp` 数组缓存结果，从而提高效率。
    
- **预处理（Preprocessing）**: 在算法开始之前，标记马的控制区域，这是一个常见的优化策略，通过提前准备好数据，使得后续的计算过程能够快速判断某个点是否可达，避免了在递归中每次都进行复杂的判断。
    
- **输入输出优化**: 使用 `ios::sync_with_stdio(false)` 和 `cin.tie(0)`，这可以减少输入输出时的延迟，使得程序在大数据量时运行得更快。
    

### 4. **总结**

- **时间复杂度**: O(bx * by)，由于每个状态只会被计算一次，并且通过记忆化存储结果。
- **空间复杂度**: O(bx * by)，主要由 `dp` 和 `blocked` 数组占用。
- **技术要点**: 动态规划、记忆化搜索、预处理、输入输出优化。

这段代码的高效之处在于通过动态规划和记忆化搜索结合预处理，使得解决问题的时间复杂度降低到 O(bx * by)，避免了重复计算，同时对输入输出进行了优化。