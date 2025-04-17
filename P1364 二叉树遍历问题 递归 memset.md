---
sr-due: 2025-08-16
sr-interval: 128
sr-ease: 268
---
#review 
题目描述
设有一棵二叉树，如图：
![[Pasted image 20250224194003.png]]
其中，圈中的数字表示结点中居民的人口。圈边上数字表示结点编号，现在要求在某个结点上建立一个医院，使所有居民所走的路程之和为最小，同时约定，相邻接点之间的距离为 1。如上图中，若医院建在 1 处，则距离和 =4+12+2×20+2×40=136；若医院建在 3 处，则距离和 =4×2+13+20+40=81。
输入格式
第一行一个整数 n，表示树的结点数。
接下来的 n 行每行描述了一个结点的状况，包含三个整数 w,u,v，其中 w 为居民人口数，u 为左链接（为 0 表示无链接），v 为右链接（为 0 表示无链接）。
输出格式
一个整数，表示*最小距离和*。
输入输出样例
输入 # 1复制
5						
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
输出 # 1复制
81
说明/提示
数据规模与约定
对于 100% 的数据，保证 1≤n≤100，0≤u,v≤n，1≤w≤10 
5
[[LUOGU_TREE]]

```cpp
#include <iostream>
#include <cstring>
const int MAXN = 110;
using namespace std;
int n, ans = 0x7fffffff, vis[MAXN];

struct Node
{
    int left, right, father, value;
}t[MAXN];

int call(int x, int d)
{
    if (!x || vis[x]) return 0;
     如果, 这个x是0, 或者vis[x]已经被访问, 就不再操作, 直接返回
    vis[x] = 1;
     上面的假设都不成立, 那么现在就标记这个 visit_array 之中的东西已经被访问
    return  call(t[x].left, d+1) + 
     对于所有的受到波及的节点, 召唤它们的左节点
             call(t[x].right, d+1) + 
              召唤对于它们右节点的分析
              
             call(t[x].father, d+1) + 
             召唤对于它们父节点的分析
             
             t[x].value*d;  返回**当前**的 value 作为实际的递增4
              去到父节点又返回来怎么办?
              
             没事的, 已经受到标记, 再回来直接return 0;
              不仅没有任何加成, 这一个分支也会直接被终止
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i].value >> t[i].left >> t[i].right;
    }
     读取与建构, 没什么好说的
    for (int i = 1; i <= n; i++)
    {
        t[t[i].left].father = i;
        t[t[i].right].father = i;

         宣布自己是左右儿子的父亲
         这是树的建构的一部分

    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
         为了使用 call 扫描, 将 visit 清空
         
        ans = min(ans, call(i, 0));
    }
    cout << ans << endl;
    return 0;
}
```

#洛反思 

二叉树, 如何到处访问? 答案是可以给节点增设父节点.
因为二叉树只能有一个亲节点, 并且最多具有两个子节点, 因此最多只需要三个结构体的变量就可以建立起这个树里面所有的联系, 并且实现在整个树内部的查找.

如何增加一次打通的概率? 或许可以试着加大对 依赖项 这个思维模式的思考. 
- 一个功能需要怎样的依赖项才能正常运行? 
- 它运行完之后, 会对于这个依赖项产生什么作用? 
- 要采用什么办法, 来使得依赖项正常化, 能够完成下一次的调用?

具有分层, 累加的一个套路:
```java
int dfs(int level)
{
	......
	return dfs(level+1) + value_offered_by_current;
}
```
参见[[P1443 BFS马步数范围统计]]
`void` 类型函数也是有用的.
- 常用于对全局变量的操作修改之中
- 只是完成操作, 不需要报告什么结论

具有 `int` 类型的递归函数
- 注意在访问连续序号递增之数据类型的应用
	- 联想: 不连续的数据--迭代器 [[P1996 链表版约瑟夫环 迭代器的操作 回环实现]]
