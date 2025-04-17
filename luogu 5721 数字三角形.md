[[C++ cout 格式化数字输出]]
# 通过的代码
```cpp
#include <iostream>
#include <iomanip>
  
int main()
{
    int n, mani = 1;
    std::cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << std::setfill('0') << std::setw(2) << mani;
            mani++;
        }
        std::cout << std::endl;
    }
    return 0;
}
```
怎么知道, 这里就是需要用这个两层循环?
- 输出每一行, 是一层循环
- 输出每一行的大量的, 有规律的数字, 又是一层循环

此外, 关注各种控制符
```cpp
#include <iomanip>
setw
setfill
setprecision
fixed
```