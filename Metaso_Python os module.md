### Python `os` 模块超详细教程（2025 版）

---

#### 一、模块概述
`os` 模块是 Python 标准库中用于与操作系统交互的核心模块，提供 跨平台 的底层操作接口，涵盖 文件/目录管理、进程控制、环境变量操作、路径解析 等场景。其设计遵循 POSIX 标准，可在 Windows、Linux、macOS 等系统中无缝切换。

---

#### 二、核心功能分类与参数详解

---

##### 1. 路径与目录操作
###### 1.1 路径获取与切换
- `os.getcwd()`  
  - 功能：返回当前工作目录（Current Working Directory）的绝对路径。  
  - 参数：无  
  - 返回值：字符串（如 `'/home/user/projects'`）  
  - 场景：需要定位脚本运行路径时使用。  
  ```python
  print(os.getcwd())  # 输出: /home/user/projects
  ```


- `os.chdir(path)`  
  - 功能：切换当前工作目录至 `path`。  
  - 参数：  
- `path` (str)：目标目录路径。  
  - 返回值：无，失败时抛出 `FileNotFoundError`。  
  ```python
  os.chdir('/tmp')  # 切换到 /tmp 目录
  ```


###### 1.2 目录列表与遍历
- `os.listdir(path='.')`  
  - 功能：返回指定目录下的文件和子目录名列表（不递归）。  
  - 参数：  
- `path` (str, 可选)：目标目录路径，默认当前目录。  
  - 返回值：列表（如 `['file1.txt', 'subdir']`）。  
  ```python
  print(os.listdir('/var/log'))  # 输出: ['syslog', 'auth.log', ...]
  ```


- `os.walk(top, topdown=True, onerror=None)`  
  - 功能：递归遍历目录树，生成三元组 `(dirpath, dirnames, filenames)`。  
  - 参数：  
- `top` (str)：起始目录路径。  
- `topdown` (bool)：是否自上而下遍历（默认 `True`）。  
- `onerror` (function)：处理遍历错误的回调函数。  
  - 场景：批量处理文件或目录结构分析。  
  ```python
  for root, dirs, files in os.walk('/data'):
      print(f"当前目录: {root}, 子目录数: {len(dirs)}, 文件数: {len(files)}")
  ```


---

##### 2. 文件与目录管理
###### 2.1 创建与删除
- `os.mkdir(path, mode=0o777)`  
  - 功能：创建单层目录。  
  - 参数：  
- `path` (str)：目标路径。  
- `mode` (int)：目录权限（八进制，默认 `0o777`）。  
  - 异常：目录已存在时抛出 `FileExistsError`。  
  ```python
  os.mkdir('new_dir', mode=0o755)  # 创建权限为 rwxr-xr-x 的目录
  ```


- `os.makedirs(name, mode=0o777, exist_ok=False)`  
  - 功能：递归创建多级目录（类似 `mkdir -p`）。  
  - 参数：  
- `exist_ok` (bool)：若目录已存在是否报错（默认 `False`）。  
  - 场景：创建嵌套目录结构。  
  ```python
  os.makedirs('project/data/2025', exist_ok=True)  # 允许目录已存在
  ```


- `os.remove(path)` 与 `os.rmdir(path)`  
  - 功能：删除文件（`remove`）或空目录（`rmdir`）。  
  - 参数：  
- `path` (str)：目标路径。  
  - 注意：`rmdir` 仅能删除空目录，非空目录需用 `shutil.rmtree()`。  

###### 2.2 文件属性与状态
- `os.stat(path, *, dir_fd=None, follow_symlinks=True)`  
  - 功能：获取文件/目录的详细元数据。  
  - 参数：  
- `follow_symlinks` (bool)：是否追踪符号链接（默认 `True`）。  
  - 返回值：`os.stat_result` 对象，包含 `st_size`（大小）、`st_mtime`（修改时间）等属性。  
  ```python
  stat_info = os.stat('file.txt')
  print(f"文件大小: {stat_info.st_size} 字节，修改时间: {stat_info.st_mtime}")
  ```


- `os.utime(path, times=None, ns=None, dir_fd=None)`  
  - 功能：修改文件的访问和修改时间。  
  - 参数：  
- `times` (tuple)：`(atime, mtime)`，单位为秒。  
- `ns` (tuple)：`(atime_ns, mtime_ns)`，单位为纳秒。  
  - 场景：日志文件时间戳修复。  

---

##### 3. 进程管理与系统交互
###### 3.1 进程控制
- `os.system(command)`  
  - 功能：执行 shell 命令，返回退出状态码。  
  - 参数：  
- `command` (str)：要执行的命令字符串。  
  - 注意：输出直接显示在终端，无法捕获。  
  ```python
  exit_code = os.system('ls -l')  # 执行后输出到控制台
  ```


- `os.execvp(file, args)`  
  - 功能：用新进程替换当前进程（执行可执行文件）。  
  - 参数：  
- `file` (str)：可执行文件名（在 `PATH` 中查找）。  
- `args` (list)：参数列表（`args[0]` 通常为文件名）。  
  - 场景：脚本链式调用。  
  ```python
  os.execvp('python', ['python', 'script.py', '--debug'])
  ```


###### 3.2 进程信息
- `os.getpid()` 与 `os.getppid()`  
  - 功能：获取当前进程 ID（`getpid`）及父进程 ID（`getppid`）。  
  - 返回值：整数。  
  ```python
  print(f"当前进程ID: {os.getpid()}, 父进程ID: {os.getppid()}")
  ```


---

##### 4. 环境变量与系统信息
###### 4.1 环境变量操作
- `os.environ`  
  - 功能：字典对象，包含所有环境变量。支持读写操作。  
  - 场景：配置参数传递或路径设置。  
  ```python
  os.environ['MY_VAR'] = 'value'  # 设置环境变量
  print(os.environ.get('PATH'))    # 读取 PATH 变量
  ```


- `os.getenv(key, default=None)`  
  - 功能：安全获取环境变量值，避免 `KeyError`。  
  - 参数：  
- `default`：变量不存在时的默认值。  
  ```python
  home_dir = os.getenv('HOME', '/default/home')
  ```


###### 4.2 系统信息查询
- `os.name`  
  - 功能：返回操作系统标识符（`'posix'`、`'nt'`、`'java'`）。  
  - 场景：跨平台代码的条件判断。  
  ```python
  if os.name == 'posix':
      print("运行在 Unix/Linux 系统")
  ```


- `os.cpu_count()`  
  - 功能：返回系统的逻辑 CPU 核心数。  
  - 返回值：整数（如 `8`）。  

---

##### 5. 高级文件操作
- `os.access(path, mode)`  
  - 功能：检查路径的访问权限。  
  - 参数：  
- `mode` (int)：权限标志（`os.F_OK` 存在性，`os.R_OK` 可读，`os.W_OK` 可写，`os.X_OK` 可执行）。  
  - 返回值：布尔值。  
  ```python
  if os.access('file.txt', os.R_OK):
      print("文件可读")
  ```


- `os.path` 子模块  
  - 功能：专用于路径解析的独立子模块，提供 `join()`, `basename()`, `exists()` 等函数。  
  ```python
  full_path = os.path.join('/var', 'log', 'syslog')  # 拼接路径
  ```


---

#### 三、跨平台兼容性注意事项
1. 路径分隔符：使用 `os.path.sep` 代替硬编码的 `/` 或 `\`。  
2. 行结束符：使用 `os.linesep` 代替 `\n` 或 `\r\n`。  
3. 权限模式：Windows 系统对 `mode` 参数的支持有限，需测试验证。  

---

#### 四、完整函数速查表

| 函数名                | 功能简述                     | 关键参数                     | 使用场景                     | 来源       |
|-----------------------|----------------------------|-----------------------------|----------------------------|------------|
| `os.rename(src, dst)` | 重命名文件/目录             | `src`原路径, `dst`新路径     | 文件批量重命名             |  |
| `os.symlink(src, dst)`| 创建符号链接                | `src`目标路径, `dst`链接路径 | 快捷方式管理               |      |
| `os.kill(pid, sig)`   | 向进程发送信号              | `pid`进程ID, `sig`信号类型   | 进程终止或重启             |  |
| `os.startfile(path)`  | 用关联程序打开文件（仅Windows）| `path`文件路径              | 快速启动文档或应用         |      |


---

#### 五、实战案例
###### 案例：批量修改文件扩展名
```python
import os

def batch_rename_ext(dir_path, old_ext, new_ext):
    for filename in os.listdir(dir_path):
        if filename.endswith(old_ext):
            base = os.path.splitext(filename)[0]
            old_path = os.path.join(dir_path, filename)
            new_path = os.path.join(dir_path, f"{base}{new_ext}")
            os.rename(old_path, new_path)
            print(f"Renamed: {filename} -> {base}{new_ext}")

# 使用示例
batch_rename_ext('/data/files', '.txt', '.md')
```


---

#### 六、延伸学习
- `subprocess` 模块：替代 `os.system` 的更强大进程管理工具。  
- `shutil` 模块：高阶文件操作（如压缩、递归删除）。  

---

以上教程基于 Python 3.10+ 版本验证，兼容主流操作系统环境。建议结合官方文档（`[https://docs.python.org/3/library/os.html](https://docs.python.org/3/library/os.html)`）深入探索高级用法。