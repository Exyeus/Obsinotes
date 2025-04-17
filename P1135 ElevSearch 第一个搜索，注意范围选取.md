```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> floor_access;

int main()
{
    int floor, start, end;
    cin>>floor>>start>>end;

    vector<int> fl(floor, -1);
    // Clarify the order of the two parameters, first for size, second for value.
    // Record the access situation of those floors

    vector<int> access_range;
    // Save the movement range of elevators on each floor

    for (int i = 0; i < floor; i++)
    {
        int j;
        cin >> j;
        access_range.push_back(j);
    }
    // Now write a search process here, and we just 
    //access the end floor for the answer.
    floor_access.push(start - 1);
    fl[start-1] = 0;
    while (!floor_access.empty())
    {
        int start_point = floor_access.front();// start point has been substracted to suit the array language

        floor_access.pop();
        // search and analyse the two possible direction
        // of current situation

        int up = start_point + access_range[start_point];

        if (up <= floor - 1 && fl[up] == -1)
        {
            fl[up] = fl[start_point] + 1;
            floor_access.push(up);
        }
        int down = start_point - access_range[start_point];
        if (down >= 0 && fl[down] == -1)

// CAREFULLY THINK ABOUT THE RANGE BEFORE YOU TYPE THEM IN!!!!!

        {
            fl[down] = fl[start_point] + 1;
            floor_access.push(down);
        }
    }
    if (end == start)
    {
        cout << "0";
        return 0;
    }
    if (fl[end - 1] > 0)
        cout << fl[end - 1];
    else 
        cout << "-1";
    return 0;
}
```

注意以下几个编写之中出现的问题：
- 没有使用 `pop` 来删除. 暂时不知道改变当前的 `pop` 的位置会不会带来影响, 但是不用 `pop` 绝对有很大影响
- 搜索范围出错. 可以取零, 也可以取 `floor - 1` , 不要莫名其妙就不取了

### 应对自然数学语言描述的下标位置表示与数组语言的办法:
明确:
- 创建数组等需要具体大小的地方, 要用从1开始的计数
- 数组访问, 用的都是比其自然计数小1

考虑场景
- 访问数组, 减去1
- 存储访问数组的索引, 减去1
- 集中处理, 分成模块, 一部分用自然计数, 一部分用下标数组计数
