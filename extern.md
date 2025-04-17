在 C 语言中，`extern` 关键字用于声明一个变量或函数的**外部链接**，即表示该变量或函数在当前文件中未定义，而是定义在**其他文件**中。这样做的目的是在多个源文件之间共享变量或函数。
[[static]][[数据类型]]
### 使用场景

通常，我们在一个文件中定义变量或函数，然后在另一个文件中使用 `extern` 声明，以便在多个文件中访问它。例如，假设你有两个源文件 `file1.c` 和 `file2.c`：

#### 例子
1. **在 `file1.c` 中定义变量：**

   ```c
   // file1.c
   #include <stdio.h>

   int globalVar = 42; // 定义全局变量

   void printGlobalVar() {
       printf("globalVar = %d\n", globalVar);
   }
   ```

2. **在 `file2.c` 中使用 `extern` 引用该变量：**

   ```c
   // file2.c
   #include <stdio.h>

   extern int globalVar; // 声明外部变量

   void modifyGlobalVar() {
       globalVar = 100;
   }
   ```

3. **在主文件中调用（例如 `main.c`）：**

   ```c
   // main.c
   #include <stdio.h>

   extern int globalVar;       // 声明外部变量
   void printGlobalVar();      // 声明外部函数
   void modifyGlobalVar();     // 声明外部函数

   int main() {
       printGlobalVar();       // 输出 42
       modifyGlobalVar();      // 修改 globalVar 的值
       printGlobalVar();       // 输出 100
       return 0;
   }
   ```

### 总结

- **`extern` 的作用**：告知编译器变量或函数在别的文件中定义，让编译器知道它们是外部链接的符号。
- **适用场景**：用于跨文件共享变量或函数。