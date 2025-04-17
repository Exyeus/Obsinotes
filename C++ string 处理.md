```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int is_positive = (number > 0)? 1: 0;
    string str = to_string(number);
    reverse(str.begin(), str.end());
    while (*str.begin() == '0')
    {
        str.erase(str.begin());
    }
    switch (is_positive)
    {
    case 1:
        cout<<str;
        break;
    case 0:
        str.pop_back();
        cout<<"-"<<str;
    default:
        break;
    }
    return 0;
}
```

## 操作:
```cpp
object.reverse
object.erase
```
