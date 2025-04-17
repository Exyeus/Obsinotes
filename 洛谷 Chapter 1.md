# 简单技巧
- 调用浮点数升格运算，而不用`float`之, 可以使用`cout<<500.0/3<<endl`
- 对于char类型, 如果需要显示其背后整数, 可以将其赋值给 `int` , 或者直接 `(int)`之
```cpp
char chara = 'A';
int ich = chara;
printf("%d", (int)chara);
```
- 四舍五入
```cpp
int a; a=(a+0.5)/1;
```