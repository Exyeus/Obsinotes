### Arguments in Passing

*Argus undefined in numbers*.
```python
def vfunc(a, *b):
	print(type(b))
	for n in b:
		a += n
	return a
vfunc(1, 2, 3, 4, 5)
```

```output
<class 'tuple'>
16
```

The parameters exceeding the total sum, will be packed in a tuple and passed into the function.

### Scope matters

```python
n = 1
def func(a, b):
	n = b
	return a*b
	
```