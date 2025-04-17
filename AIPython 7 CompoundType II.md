### Dict

*creating*. Using `{}` to build a dict, and an empty `{}` will be interpreted as dict, instead of set.
For building a set, just use `set()`. `{}` containing lots of single elem instead of pairs will also be interpreted as a set! And *similarly*, using `dict()` to build a dict is also optional.

*using `dict()`*.
```python
dict1 = dict()
dict2 = dict(dict1)
	** The underlying process is copying all elements from dict1 
	** to dict2
dict3 = dict([(key1, value1), (key2, value2)])
	** list containing tuples
dict4 = dict(([key1, value1], [key2, value2]))
	** tuple containing lists
dict5 = dict(
	key1 = value1
	key2 = value2
)
```
>Notice that commas are dispensable!
>Pair relationships must be explicit!

*Arguments passing based on dict*.
```python
def g(**kwargs):
	print(type(kwargs))
	print(kwargs)
g()
g(RUC = 'Renmin Univ of China', THU = 'Tsinghua Univ')
```

```
--dict
{}
--dict
{--content as desired}
```

*AcquireAllProperties*.
```python
dic.keys()
dic.values()
dic.items()
```

>The results of these expressions, will turn invalid after editing the list. 

*Using dict to calculate word frequency*.
```python
import jieba
txt = open('./gl.txt', 'r', encoding='utf-8').read()
words = jieba.lcut(txt)
counts = {}
for word in words:
	if len(word) == 1:
		continue
	else:
		counts[word] = counts.get(word, 0)+1
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse = True)
for i in range(15):
	word, count = items[i]
	print('{0:<10}{1:>5})'.format(word, count)
```
[[Metaso_GeneralPythonOutputFormat]]









