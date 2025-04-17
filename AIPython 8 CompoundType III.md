### Higher-order operations

- `filter`
- `map`
- `reduce`
- List/Dict/Tuple Comprehension

The first two, please refer to [[CS61A 2.4 Mutable Data]]
As for `reduce`, its form:
```python
from functolls import reduce
reduce(function, iterable[? initializer])
```

It utilizes the function, to merge the elements of the iterable.
[[Metaso_PythonFunctionReduce]]

### Other Types

There are deque, Counter and defaultdict in the Module `collections`.

*Deque*.
```python
from collections import deque
x = deque([1, 2, 3])
x.append(4)
x.pop()
x.appendleft(0)
x.popleft()
```

>The advantage of this type, lies in that for traditional lists, if you try to add elements to its front, optional solutions are like:
>`x = [0] + x`, which actually creates a new list.

*Counter*.
A dict designed for conuting.
```python
data = [1, 1, 1, 2, 2, 3]
c = Counter(data)
```

The returned type of this function is a *dict*. For items in it, exact elems stands for keys, and the times they appear stand for the values.

*Defaultdict*.
A `try-except-finally`-like dict implementation for dict. To use this, we need to offer a function in constructing this:
```python
d = defaultdict(lambda : 'default value')
d.update(existing_dict)
	** this dict will be stored within the default dict
print(d['FDU'])
	** which actually doesnot exist
```

>The output will be default value.
>Meanwhile, the Pair 'FDU': 'default value' will be added to the dict
