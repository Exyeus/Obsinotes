[[YOJ_TREE]]
这个问题可以通过图搜索算法来解决，尤其是 **BFS (广度优先搜索)**，因为它可以找到在所有路径中最短的那一条路径。在此问题中，地图上有多个重要的点（起点、目标点、一卡通点），需要依次经过这些点。

### 思路：

1. **地图表示**：我们有一个 `n x n` 的方阵地图，其中：
    
    - `0` 表示空地，表示可以通行。
    - `1` 表示障碍物，表示不能通行。
    - `2` 表示起点（东风六寝室楼）。
    - `3` 表示一卡通丢失的地方。
    - `4` 表示上课地点。
2. **问题目标**：
    
    - 从起点开始，先到达一卡通丢失地点（3），然后再到达上课地点（4），找出从起点到达上课地点的最短路径，并输出所需的时间。
3. **算法选择**：
    
    - 使用 **BFS** 进行广度优先搜索来计算最短路径。BFS 能保证在每次探索时，我们找到的是当前的最短路径。
    - BFS 会计算从起点到一卡通丢失地点，再从一卡通丢失地点到上课地点的最短路径。
4. **步骤**：
    
    - 使用 BFS 从起点 (2) 到达一卡通丢失地点 (3)。
    - 然后从一卡通丢失地点 (3) 到上课地点 (4)。
    - 总时间即为这两个 BFS 搜索结果的和。

### 代码实现：

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10;
const int dx[4] = {-1, 1, 0, 0};  // 上下左右四个方向
const int dy[4] = {0, 0, -1, 1};  // 上下左右四个方向

int n;
int grid[MAXN][MAXN];
pair<int, int> start, card, classroom;  // 起点、一卡通丢失地点、上课地点

// BFS算法，返回从start到end的最短路径长度
int bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, -1));  // -1表示不可达
    int x_start = start.first, y_start = start.second;
    q.push({x_start, y_start});
    visited[x_start][y_start] = true;
    dist[x_start][y_start] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        if (x == end.first && y == end.second) {
            return dist[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] != 1) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;  // 如果无法到达
}

int main() {
    cin >> n;
    
    // 读取地图并找到起点、一卡通丢失地点和上课地点
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) start = {i, j};       // 起点
            if (grid[i][j] == 3) card = {i, j};        // 一卡通丢失地点
            if (grid[i][j] == 4) classroom = {i, j};   // 上课地点
        }
    }

    // 计算从起点到一卡通丢失地点的最短路径
    int dist1 = bfs(start, card);
    if (dist1 == -1) {
        cout << -1 << endl;
        return 0;
    }

    // 计算从一卡通丢失地点到上课地点的最短路径
    int dist2 = bfs(card, classroom);
    if (dist2 == -1) {
        cout << -1 << endl;
        return 0;
    }

    // 总时间就是两段路径的和
    cout << dist1 + dist2 << endl;

    return 0;
}
```

### 解释：

1. **输入读取**：
    
    - 输入首先读取地图的大小 `n` 和地图本身。通过在读取地图时，记录下起点 `(2)`、一卡通丢失地点 `(3)` 和上课地点 `(4)` 的位置。
2. **BFS函数**：
    
    - `bfs` 函数计算从一个点到另一个点的最短路径。我们使用队列进行广度优先搜索，`visited` 数组避免重复访问，`dist` 数组存储每个点的最短距离。
    - 4个方向的移动是上下左右，每次移动都检查是否越界或者是否为障碍物。
3. **主逻辑**：
    
    - 使用 BFS 分别计算从起点到一卡通丢失地点的最短路径，再从一卡通丢失地点到上课地点的最短路径。
    - 如果任意一段路径不可达，则直接输出 `-1`。
    - 最终输出两段路径长度的总和，即为所需时间。

### 复杂度分析：

- **时间复杂度**：每次 BFS 搜索的时间复杂度为 `O(n^2)`，因此总时间复杂度是 `O(n^2)`。
- **空间复杂度**：空间复杂度是 `O(n^2)`，用于存储地图、距离和访问状态。

### 示例：

#### 输入1：

```
5
2 0 0 1 1
1 1 0 1 1
0 0 3 0 1
0 1 1 0 1
4 0 0 0 0
```

#### 输出1：

```
8
```

#### 输入2：

```
5
2 0 0 1 1
1 1 0 1 1
0 0 3 0 1
0 1 1 0 1
4 0 0 0 0
```

#### 输出2：

```
-1
```

### 结论：

这个解法通过 BFS 寻找最短路径，确保了从起点到一卡通丢失地点，再到上课地点的路径是最短的，并且避免了无效的路径计算。如果没有可行路径，程序会输出 `-1`。