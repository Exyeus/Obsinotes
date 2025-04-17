# 2.1 插入排序
### 以前的做法
每次从第`i`个元素开始遍历整个数组, 最后确认得到的最小值放到第`i`个元素那里去, 在这个过程之前, `i-1`个元素都是排好的
### 现在看到的做法
```cpp
for (int j = 2; j < sizeof(array)/sizeof(datatype); j++)
{
	dt key = array[j]; 取出来这个数字, 接下来就会被前一个数覆盖掉!
	i = j - 1;
	while (i > 0 && array[i] > key) // 在发现有一个比 key 更小之前
	{
		array[i + 1] = array[i]; 把这些数都往后挪, 占掉要插入的那个数字
		i -= 1; i每次减少1, 实现向前一位分析
	}
	array[i + 1] = key; 分析循环完毕, 结算, 将缓存的数字放入最后的位置.
	为什么是array[i+1] = key;? 因为由while循环条件知道, array[i]是小于key的
}
```

## 循环不变式
### 三条性质
- 初始化
- 保持
- 终止

# 算法分析
# 分治排序

分治法是一种常见的算法设计策略，它通过递归地将问题分解为更小的子问题，然后合并子问题的解来解决原问题。在排序算法中，分治策略的典型应用包括 **归并排序** 和 **快速排序**。以下是两种算法的简单实现和详细分析。

---

### 示例 1: 归并排序

#### 代码实现

```cpp
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) std::cout << num << " ";
    return 0;
}
```

#### 复杂度分析

1. **分解过程**: 每次递归将数组分成两部分，复杂度为 $O(\log n)$。
2. **合并过程**: 每次合并需要线性时间 $O(n)$。
3. **总复杂度**: $T(n) = 2T(n/2) + O(n)$，解得 $O(n \log n)$。

#### 分步说明

1. **分割**: 通过递归分割数组，直到每个子数组只有一个元素。
2. **合并**: 两两合并子数组，确保合并后的子数组有序。
3. **递归层数**: $\log_2 n$，每层的合并操作需要 $O(n)$，因此整体复杂度是 $O(n \log n)$。

---

### 示例 2: 快速排序

#### 代码实现

```cpp
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; 

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr) std::cout << num << " ";
    return 0;
}
```

#### 复杂度分析

1. **分解过程**: 每次选取一个基准（pivot），将数组划分为两部分，复杂度为 $O(\log n)$。
2. **划分过程**: 每次划分需要扫描整个数组，复杂度为 $O(n)$。
3. **总复杂度**:
    - 平均情况下: $T(n) = 2T(n/2) + O(n)$，解得 $O(n \log n)$。
    - 最坏情况下（不平衡划分）: $T(n) = T(n-1) + O(n)$，解得 $O(n^2)$。

#### 分步说明

1. **选择基准**: 通常选择最后一个元素作为基准。
2. **划分**: 将小于基准的元素放到基准左边，大于基准的元素放到右边。
3. **递归排序**: 对基准两侧的子数组递归排序。

---

### 总结对比

|**算法**|**时间复杂度（平均）**|**时间复杂度（最坏）**|**空间复杂度**|**稳定性**|
|---|---|---|---|---|
|**归并排序**|$O(n \log n)$|$O(n \log n)$|$O(n)$|稳定|
|**快速排序**|$O(n \log n)$|$O(n^2)$|$O(\log n)$|不稳定|

**练习建议**:

1. 从小规模数据入手，观察每步的变化。
2. 修改代码，例如在快速排序中尝试随机选择基准以优化最坏情况。
3. 添加打印语句，帮助理解递归调用和数组状态的变化。