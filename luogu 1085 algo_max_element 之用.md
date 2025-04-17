```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i < 7; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        v.push_back(num1 + num2);
    }
    // print the index of the maximum element
    // if the maximum element is greater than 8
    if (*max_element(v.begin(), v.end()) > 8)
        cout << max_element(v.begin(), v.end()) - v.begin() + 1 << endl;
    else cout << "0" << endl;
    return 0;
}
```

注意看, `max_element` 返回的是一个指针, 而 `vector` 的begin 和 end 也都会返回指针.
因此可以做以下操作"
1. 获得最大值所在地
2. 或者最大值, 注意 **解引用** !

书中思路更胜一筹:
两个变量: `max_value` `max_day` 一个用来记载最大值, 另外一个, 出在 if 语句之中, 只有当最大值被颠覆, 它才会相应地将数值, 改成这一层 `if` 所在的日期 !