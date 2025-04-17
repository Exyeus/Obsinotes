# Hanoi Tower
```
典中典的问题！
汉诺塔的关键，在于发现其操作是十分僵化，有迹可循的。甚至每一次的起始杆，中介杆，目标杆，
都可以经由上一次操作确定下来！
```

```python
def print_move(origin, destination):
    """Print instructions to move a disk."""
    # 打印移动指令
    print("Move the top disk from rod", origin, "to rod", destination)

def move_stack(n, start, end):
    """
    >>> move_stack(1, 1, 3)
    Move the top disk from rod 1 to rod 3
    >>> move_stack(2, 1, 3)
    Move the top disk from rod 1 to rod 2
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 2 to rod 3
    >>> move_stack(3, 1, 3)
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 1 to rod 2
    Move the top disk from rod 3 to rod 2
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 2 to rod 1
    Move the top disk from rod 2 to rod 3
    Move the top disk from rod 1 to rod 3
    """
    assert 1 <= start <= 3 and 1 <= end <= 3 and start != end, "Bad start/end"
    "*** YOUR CODE HERE ***"
    def find_missing_number(a, b):
        return (set([1,2,3]) - {a,b}).pop()

    def innervoice(sum, rod1, rod2, rod3):
        if sum == 1:
            print("Move the top disk from rod {} to rod {}".format(rod1, rod3))
            return
        elif sum > 1:
            innervoice(sum-1, rod1, rod3, rod2)
            innervoice(1, rod1, rod2, rod3)
            innervoice(sum-1, rod2, rod1, rod3)
    innervoice(n, start, find_missing_number(start, end), end)

```

#cssl
>[[python print 格式化输出]]：
```python
print("var1 = {}, var2 = {}".format(rod1, rod3))
print("var1 = ", rod1, ",var2 = ", rod2)

>>> print("a={}, while b={}".format(a, b))
a=1, while b=2
>>> print("a=",a,",while b=",b)
a= 1 ,while b= 2
>>> print("a=",a,",while b=",b,",")
a= 1 ,while b= 2 ,
>>> print("a=\{\}, while b=\{\}")
<python-input-7>:1: SyntaxWarning: invalid escape sequence '\{'
  print("a=\{\}, while b=\{\}")
a=\{\}, while b=\{\}
>>> print("a={}, while b={}")
a={}, while b={}
>>>
```
注意，`format`输出的内容似乎存在变量前后默认的一个空格！
此外，`{}`的生效需要字符串之后, `.format`的存在，因此不需要对`{}`用`\`来进行转义！

# 等额找零钱
```python
def next_smaller_dollar(bill):
    """Returns the next smaller bill in order."""
    # 如果bill等于100，返回50
    if bill == 100:
        return 50
    # 如果bill等于50，返回20
    if bill == 50:
        return 20
    # 如果bill等于20，返回10
    if bill == 20:
        return 10
    # 如果bill等于10，返回5
    elif bill == 10:
        return 5
    # 如果bill等于5，返回1
    elif bill == 5:
        return 1
    else:
        return 0

def count_dollars(total):
    """Return the number of ways to make change.

    >>> count_dollars(15)  # 15 $1 bills, 10 $1 & 1 $5 bills, ... 1 $5 & 1 $10 bills
    6
    >>> count_dollars(10)  # 10 $1 bills, 5 $1 & 1 $5 bills, 2 $5 bills, 10 $1 bills
    4
    >>> count_dollars(20)  # 20 $1 bills, 15 $1 & $5 bills, ... 1 $20 bill
    10
    >>> count_dollars(45)  # How many ways to make change for 45 dollars?
    44
    >>> count_dollars(100) # How many ways to make change for 100 dollars?
    344
    >>> count_dollars(200) # How many ways to make change for 200 dollars?
    3274
    >>> from construct_check import check
    >>> # ban iteration
    >>> check(HW_SOURCE_FILE, 'count_dollars', ['While', 'For'])
    True
    """
    "*** YOUR CODE HERE ***"
    def helper(amount, largest_bill):
        # 基本情况: 金额为0时找到一种有效组合
        if amount == 0:
            return 1
        # 基本情况: 金额小于0或没有可用面额时表示无效组合
        if amount < 0 or largest_bill == 0:
            return 0
            
        # 递归情况: 
        # 1. 不使用当前面额，尝试下一个较小面额
        # 2. 使用当前面额，金额减少但仍可继续使用当前面额
        ways_without = helper(amount, next_smaller_dollar(largest_bill))
        ways_with = helper(amount - largest_bill, largest_bill)
        return ways_without + ways_with
        #========================================================
    if total == 0:
        return 0
    return helper(total, 100)  # 从最大面额100开始
```

>我们面向的是在货币体系中被支持的面额，而不是给予剩下的钱可以被怎么扣。
>我们在实践中可以发现，想要找到当前剩下的钱里面能够用于组合的最大面额，是非常麻烦的，并且题目中预先定义的函数并没有给出类似的功能，我们也不应该只把这一个next small只是用来参考有哪些货币的面额.
>此外，在进行递减的时候，也可以发现，将钱进行一个划分形成树的结构，并不能使我们在每一个节点处都加一，这个是非常复杂的。

>当这些作业和cS 61 cS 70放在一起看的时候，就会发现我纳法真的是递归的一个数学思想根源。在进行递归的时候，一个极大的问题就在于base case的确定，以及这个问题的分类讨论下的进一步简化，这也是数学归纳法中的hypothesis induction步骤。

[[python functools]]