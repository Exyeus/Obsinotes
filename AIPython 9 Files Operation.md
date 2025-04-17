---
sr-due: 2025-04-12
sr-interval: 3
sr-ease: 250
---

#review 
### 文件

对于存储形式的抽象。
任何类型的数据，都可以抽象成文件的形式，也就是计算机软件可以通过 打开 读写 之类的统一方式，来进行操作。
`open` `write` `read` `close` 
目的在于使应用程序能够访问外部的数据。

*两种类型*。文本文件和二进制文件
二进制文件
- 由比特1和比特0所组成，没有统一的字符编码，文件内部数据的组织格 式和文件用途有关
- 二进制文件与文本文件的主要区别在于是否有统一的字符编码
- 二进制是信息按照非字符但特定格式形成的文件，数字图像的JPEG和 PNG，数字音频的MP3和WAV等
- 由于二进制文件没有统一的字符编码，故只能当做字节流，而不能看做 是字符串
*编码*。

编码是信息从一种形式转换为另一种形式的过程
- ASCII编码、Unicode编码、UTF-8编码等
- Unicode编码
	- 跨语言、跨平台进行文本转换和处理
	- 对每种语言中字符设定统一且唯一的二进制编码 
	- 基本的Unicode字符有两个字节长，有65536个编码空间
- UTF-8编码
	- 可变长度的Unicode的实现方式
	- 使用奇妙的方法，使得绝大多数的英文和符号，能够仅使用接近 `ascii` 的编码长度进行编码。可以很大程度上节省空间。

![[Pasted image 20250317143052.png]]
### 文件的读写

打开、操作之后记得要关闭！
Python内置了 `open` 函数

绝对路径与相对路径： 
- 绝对路径：指向文件系统中某个固定位置的路径，不会因当前的工作目录而产生变化，包含根目录。
- 相对路径：以指定的工作目录作为基点，避开提供完整的绝对路径。
	- 例如：通过文件名在*当前工作目录*下找到文件！

|         |                                                             |
| -------- | ----------------------------------------------------------- |
| r只读。     | 如果文件不存在，则返回异常 w覆盖写。                                         |
| w覆盖写。    | 文件不存在则自动创建，存在则<span style="background:#d3f8b6">覆盖</span>原文件 |
| x创建写。    | 文件不存在则自动创建；存在则返回异常                                          |
| a追加写。    | 文件不存在则自动创建；存在则在原文件最后追加写                                     |
| b二进制文件模式 | 二进制文件模式t文本文件模式（默认）                                          |
| t        | 文本文件模式（默认）                                                  |
| +        | 与r/w/x/a一同使用，在原功能基础上增加同时读写功能                                |

*read*。

| Methods              | Explanation                                                  |
| -------------------- | ------------------------------------------------------------ |
| . read(size=-1)      | 根据给定的size参数，读取前size长度的字符串或字节流                                |
| . readline(size=-1)  | 根据给定的size参数，读取该行前size长度的字符串或字节流                              |
| . readlines(hint=-1) | 给定参数，从文件中读入前hint行，并以每行为元素形成<font color="#ffff00">一个列表</font> |
|                      |                                                              |
>注意换行符的存在。输出的时候注意 `print` 的换行效果加成。
>`close` 之后，修改才会得以从缓冲区正确地写入磁盘
>过于巨大的 `txt` 文件，可能需要分几次使用 `read` 来读入内容。

*`with... as` 语法*。
```python
with expression [as target]:
	code-block
```

你可以将这个视作，不管你有没有 `close` ，只要用了 `with` ，`close` 就会如同 `try except finally` 之中的 `finally` 一般，不管是正常执行，还是中途报错，都会有一个 `fileobject.close()`.

### The Formatization and Process of Multi-Dimensional Data

*The read and process of 2-dimensional data*.

*CSV*. The Comma Separated Values, is a generic and relatively simple file format.
The following rules lead to well-formed CSV files.
- Pure-text, using single encoding
- Using lines as units, no space at the beginning of each line.
- No blank line with in the lines
- Every line represents for a 1 dimensional data, and multi-lines represent for 2 dimensional lines.
- Using Commas to separate every *cloumn* of the data.
- If there is a missing data, the comma should *still* be preserved.
- For data in the table, *alias* is optional, if there it is, put it at the first *line* of the file

*concrete methods*.

Analysing it *line by line* is a option.

```python
ls = []
with open('txt' , 'r') as f:
	for line in f:
		line = line.replace("\n", "")
		ls.append(line.split(",")) 
		#This, using "," to split the string to a series of elements in a list.
print(ls)
```

Also, using built-in `CSV` lib is also a option.

```python
import csv
with open('txt') as f:
	f_csv = csv.reader(f)
	for row in f_csv:
		print(row)
```

*CSV reading*

*CSV processing by lines*

*Writing for CSV*
- based on list
- based on dict

### The os lib

The lib is introduced, for that python's operating on files is essentially interacting with the operating sys. Also, there are other operation that OS is involved.
OS offers the functinal interfaces of most OS. It can automatically adapt itself to different OS, and do operations accordingly.

```python
import os
os.name
os.uname
os.environ
os.environ.get('key')

os.path.abspath()
os.path.join()
>>> This is for the case that, Unix and Windows use different symbol to split
os.listdir(path='')

os.mkdir(path, mode = 0o777, dir_fd = None)
>>> 'mode' stands for the permission. 7 represents for complete permissions. 3 '7's stands for different parties working on this project--All, You, Group

os.path.split(path)
>>> decompose the dir to 2 parts, with the last being the terminal dir or filename
os.path.splitext(path)

```



























