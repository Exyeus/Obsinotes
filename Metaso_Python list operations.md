这张图片展示了Python中列表（list）的一些常用操作和方法。下面我将对每个操作进行讲解，并提供相应的代码示例。

### 1. `ls[i] = x`
**描述**: 替换列表`ls`第`i`个数据项为`x`。
**示例**:
```python
ls = [1, 2, 3]
ls[1] = 10
print(ls)  # 输出: [1, 10, 3]
```

### 2. `ls[i: j] = lt`
**描述**: 用列表`lt`替换列表`ls`中第`i`到`j`项数据（不含第`j`项）。
**示例**:
```python
ls = [1, 2, 3, 4, 5]
lt = [10, 20]
ls[1: 3] = lt
print(ls)  # 输出: [1, 10, 20, 4, 5]
```

### 3. `ls[i: j: k] = lt`
**描述**: 用列表`lt`替换列表`ls`中第`i`到`j`以`k`为步的数据。
**示例**:
```python
ls = [1, 2, 3, 4, 5]
lt = [10, 20]
ls[1: 4: 2] = lt
print(ls)  # 输出: [1, 10, 3, 20, 5]
```

### 4. `del ls[i: j]`
**描述**: 删除列表`ls`第`i`到`j`项数据，等价于`ls[i: j] = []`。
**示例**:
```python
ls = [1, 2, 3, 4, 5]
del ls[1: 3]
print(ls)  # 输出: [1, 4, 5]
```

### 5. `del ls[i: j: k]`
**描述**: 删除列表`ls`第`i`到`j`以`k`为步的数据。
**示例**:
```python
ls = [1, 2, 3, 4, 5]
del ls[1: 4: 2]
print(ls)  # 输出: [1, 3, 5]
```

### 6. `ls += lt` 或 `ls.extend(lt)`
**描述**: 将列表`lt`元素增加到列表`ls`中。
**示例**:
```python
ls = [1, 2, 3]
lt = [4, 5]
ls += lt
print(ls)  # 输出: [1, 2, 3, 4, 5]

# 或者使用 extend 方法
ls = [1, 2, 3]
lt = [4, 5]
ls.extend(lt)
print(ls)  # 输出: [1, 2, 3, 4, 5]
```

### 7. `ls *= n`
**描述**: 更新列表`ls`，其元素重复`n`次。
**示例**:
```python
ls = [1, 2, 3]
ls *= 2
print(ls)  # 输出: [1, 2, 3, 1, 2, 3]
```

### 8. `ls.append(x)`
**描述**: 在列表`ls`最后增加一个元素`x`。
**示例**:
```python
ls = [1, 2, 3]
ls.append(4)
print(ls)  # 输出: [1, 2, 3, 4]
```

### 9. `ls.clear()`
**描述**: 删除`ls`中所有元素。
**示例**:
```python
ls = [1, 2, 3]
ls.clear()
print(ls)  # 输出: []
```

### 10. `ls.copy()`
**描述**: 生成一个新列表，复制`ls`中所有元素。
**示例**:
```python
ls = [1, 2, 3]
new_ls = ls.copy()
print(new_ls)  # 输出: [1, 2, 3]
```

### 11. `ls.insert(i, x)`
**描述**: 在列表`ls`第`i`位置增加元素`x`。
**示例**:
```python
ls = [1, 2, 3]
ls.insert(1, 10)
print(ls)  # 输出: [1, 10, 2, 
```


```python
list.pop()
list.remove()
list.reverse()
```