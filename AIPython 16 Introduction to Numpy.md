---
sr-due: 2025-04-18
sr-interval: 4
sr-ease: 270
---

#review 

### Installation

*Edition Issue*. 
Download different editions into the same env may cause errors.

*Caution*.
The target installed place is the current env you are running pip.
```cmd
pip -h -----------------list some commands
pip install
pip download -----------download but not install
    uninstall
    list
    freeze -------------
		PS D:\Progarden\vscode\python> pip freeze
		accelerate==1.3.0
		aiofiles==24.1.0
		aiohappyeyeballs==2.5.0
		aiohttp==3.11.13
		aiolimiter==1.2.1
		aiosignal==1.3.2
		annotated-types==0.7.0
		anthropic==0.49.0
		anyio==4.8.0
		asttokens @file:///home/conda/
			feedstock_root/build_artifacts/asttokens_1733250440834/work
		attrs==25.1.0
		backoff==2.2.1
	search -------------search online
pip install -U pip -----upgrade itself
```

Some code not compiled, may cause errors in downloading and unpacking.

美国加州大学尔湾分校提供了一个页面，帮助用 户获得Windows 可直接安装的第三方库文件，链接地址如下： http://www.lfd.uci.edu/~gohlke/pythonlibs/

### Reasons

Martices promotes more complex logics in scientific computation.
Built-in python *array* type supports fewer data types and methods, not suitable for heavy work in practice.


*Efficiency*. numpy has higher *memory efficiency*, and is more *convenient to use*. All elements in *numpy* array must be in the same type, and they are continuous in memory, instead of discrete distribution of python *built-in list*.

while for python original list, various types in a list lead to *rebundant judges*, though the list is made up of integers of floats.

### Numpy Array : ndarray

Supports storage and access for multi-dimensional array, `aka` TENSOR.
```python
x = np.arange(12).reshape((4, 3))
```

>arange(12) represents generating 12 numbers within the range.
>reshape((4, 3)) represents the changes in columns and rows.

*Ways to create*.

*Attributes*.

*Operation on  morph*.

*Index and Slice*

*Arithmetic Operation*

*Comparison*

*Matrix Computation*

*Other Math Operation*

*Data Storage*

### Linear Regression

*Mean Square Error*.
$$L=\frac{1}{N}\sum_{i=1} ^{N} (\hat{y_{i} }-y_{i}   )^{2} $$
This defines the average of square distances as the *Loss Function*.

















