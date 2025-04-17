**Code and output**
```python
# 1. using os to read all txt files in the direction
# 2. using jieba to tokenize all the content
# 3. load the costomized words into a Python dict
# 4. for and compare to get the frequency of each
# 5. consider using Counter to simplify the process
#
import os
import jieba
from collections import Counter
# 文件路径
maintext_dir = 'd:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\maintext'
dict_path = 'd:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\dict.txt'
persons_path = 'd:\\Progarden\\vscode\\python\\RUC\\AIxpy\\Assignments\\assignment34\\persons.txt'
# maintext_dir = os.path.join('assignment34', 'maintext')
# dict_path = 'dict.txt'
# persons_path = 'persons.txt'
# 加载自定义词典
jieba.load_userdict(dict_path)
jieba.load_userdict(persons_path)

# 读取目录下所有文件内容
def read_files(directory):
    texts = []
    for filename in os.listdir(directory):
        filepath = os.path.join(directory, filename)
        if os.path.isfile(filepath):
            with open(filepath, 'r', encoding='utf-8') as file:
                content = file.read().strip()
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
dict_words = load_dict_words(dict_path)
persons_words = load_dict_words(persons_path)
all_dict_words = dict_words.union(persons_words)

# 分词并统计词频

# 读取文本内容
texts = read_files(maintext_dir)

# 获取词频统计（人物词典、综合词典、二者的混合）
word_freq = [get_word_frequency(texts, dict_words), get_word_frequency(texts, persons_words), get_word_frequency(texts, all_dict_words)]
# 输出出现频率最高的词

most_common_words = [x.most_common(3) for x in word_freq]
print("出现频率最高的词：")
for freq_set in most_common_words:
    for word, freq in freq_set:
        print(f"{word}: {freq}")
```

```output1
Building prefix dict from the default dictionary ...
Loading model from cache C:\Users\TJM\AppData\Local\Temp\jieba.cache
Loading model cost 0.378 seconds.
Prefix dict has been built successfully.
出现频率最高的词：
郭靖: 3337
黄蓉: 2450
洪七公: 1040
郭靖: 3337
黄蓉: 2450
洪七公: 1040
郭靖: 3337
黄蓉: 2450
洪七公: 1040
```

在 `dict.txt` 之中去掉一骑绝尘的 `郭靖` 和 `黄蓉`以及大部分人名 ，得到结果如下：

```output2
出现频率最高的词：
桃花岛: 199
九阴真经: 190
丐帮: 179
郭靖: 3319
黄蓉: 2434
洪七公: 1040
郭靖: 3319
黄蓉: 2434
洪七公: 1040
```

**分析与思考**

1. 出现最高的是人名；
2. 能够反映主角是郭靖和黄蓉还有洪七公；
3. 构建更加全面，并且分类的词典，例如分为人物、地点、物品、技术等，可以分别进行词频统计，从各个角度感受文章，而不是让其他关键信息被像这里的人名一样的高频词掩盖。