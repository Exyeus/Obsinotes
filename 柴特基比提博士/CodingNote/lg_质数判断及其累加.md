```c
```c
#include <stdio.h>
int prime_judger(int num)
{
    int not_prime = 0;
    for (int index = 2; index*index <= num; index++)
    {
        if (num % index == 0)
        {
            not_prime = 1;
        }
    }
    return not_prime;
}
int  main()
{
    int lim = 0, prime_sum = 0, total_sum = 0;
    scanf("%d", &lim);
    for (int index = 2; total_sum <= lim - index; index++)
    {
        if (prime_judger(index) == 0)
        {
            printf("%d\n", index);
            prime_sum += 1;
            total_sum += index;
        }
    }
    printf("%d", prime_sum);
    return 0;
}
```
代码中有几个微妙之处
- `prime judger` 对于质数的判断，一定是`index*index <= num`, 否则就会有`25` `36`之辈成为漏网之鱼
- 我们知道, [[for循环]][[for中取值范围的问题]]的基本情况:
		第一条表达式, 是最开始执行一次
		第二条表达式, 是最开始的时候检查一次, 如果满足条件, 那么就开始执行循环体里面的内容
		第三条表达式是每次循环之后递增
	这样就会导致, 可能在最终循环之后, 所有质数的和实际上是大于Limitation的
		所以, 应当考虑在lim那里提前减去index, 这样就可以预判: 
		如果这一步本来不当被错误执行那就没有什么多说的;
		如果本应错误执行, 这里小于index直接就不能执行了!直接扼杀了这一步, 使得它不会发生!
- 注意审题, 一开始没有看到这里是需要质数之和加起来要小于`Upper_Limitation`
