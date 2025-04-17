代码如下
![[Pasted image 20250317195825.png]]
```python
# 1. using os to read txt files in the direction, one by one
# 2. using jieba to tokenize all the content, each one by one
# 3. load the persons.txt into a Python dict
# 4. using general rank in frequency to determine their rank in rows
# 5. consider using Counter to simplify the process
# 6. every time launch a chapter, it represents a column
import os
import jieba
from collections import Counter
import csv

# 文件路径
maintext_dir = 'd:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\maintext'
persons_path = 'd:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\persons.txt'

# 加载自定义词典
jieba.load_userdict(persons_path)

# 读取目录下所有文件内容
def read_files(directory):
    texts = []
    for filename in os.listdir(directory):
        filepath = os.path.join(directory, filename)
        if os.path.isfile(filepath):
            with open(filepath, 'r', encoding='utf-8') as file:
                content = file.read().strip()
                if content:
                    texts.append(content)
    return texts

# 分词并统计词频
def get_word_frequency(texts, dict_words):
    word_counter = Counter()
    for text in texts:
        words = jieba.cut(text)
        filtered_words = [word for word in words if word in dict_words]
        word_counter.update(filtered_words)
    return word_counter

# 读取词典中的词
def load_dict_words(dict_path):
    with open(dict_path, 'r', encoding='utf-8') as file:
        return set(file.read().splitlines())

# 加载词典中的词
persons_words = load_dict_words(persons_path)
# 读取文本内容
texts = read_files(maintext_dir)
# 获取所有文本的综合词频统计
total_word_freq = get_word_frequency(texts, persons_words)
# 获取人物的综合频率排行
sorted_persons = [word for word, freq in total_word_freq.most_common()]

chapter_word_freq = []
for text in texts:
    chapter_word_freq.append(get_word_frequency([text], persons_words))

# 生成二维列表，人为行，每一章次数为列
result = []
for person in sorted_persons:
    row = [person]
    for chapter_freq in chapter_word_freq:
        row.append(chapter_freq[person])
    result.append(row)

csv_path = 'D:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\result.csv'
with open(csv_path, 'w', newline='', encoding='utf-8') as csvfile:
    writer = csv.writer(csvfile)
    # 写入表头
    header = ['人物'] + [f'第{i+1}章' for i in range(len(texts))]
    writer.writerow(header)
    # 写入数据
    writer.writerows(result)

print(f"结果已写入 {csv_path}")
```

```TerminalO
Building prefix dict from the default dictionary ...
Loading model from cache C:\Users\TJM\AppData\Local\Temp\jieba.cache
Loading model cost 0.393 seconds.
Prefix dict has been built successfully.
结果已写入 D:\Progarden\vscode\python\RUC\AIxpy\Assignments\assignment34\result.csv
```

此外，还在我自己创建的 `result.csv` 之中得到了想要的内容。

![[Pasted image 20250317194753.png]]

在 Excel 之中可视化查看 `csv`
![[Pasted image 20250317194925.png]]

![[Pasted image 20250317194858.png]]

