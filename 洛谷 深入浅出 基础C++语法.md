# 知识
## 浮点
- 浮点型常量的标识: 加一个 .0 即可
- 使用 `1.66e+06` 表示浮点数 `1.6e - 7` 不可

## cmath
```cpp
#include <cmath>
double exp(double x) // e^x
double log(double x) // lnx
double fabs(double x)
double ceil(double x)
double floor(double x)
```

## 基本类型
- 大范围的数据类型, 运算速度会更慢
- `char` 输出它背后的数值, 可以赋值给 `int` 或者强制类型转换
- 四舍五入的手动实现 `int(a+0.5)`
- C++11 标准中, 提供了 `round` 来实现四舍五入之效
- `char` 一次只能读入一个字符, 因此大可借助 `char` 来实现翻转字符或者数字

## 占位符
`%nd`
`%0nd`

## algorithm 头文件
# 分支语句
### `switch case`
```cpp
switch (m){
	case 1 : case 3 : case 5 case 10 :
		cout<<31<<endl; break
}
多重 case, 列举每个月的天数
```

# 技巧
## 基准思想
```
计算从一天的 HH:MM 到 HH:MM 有多少分钟
```

## 优化计算
```cpp
当题目中保证, 涉及的数字是10的倍数
10*0.2
10/10*2
```

