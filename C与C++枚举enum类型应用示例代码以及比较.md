
> [!NOTE] Title
> Contents
[[Enum枚举结构]]
C++中的`enum`（枚举类型）是一种用于表示一组常量值的用户定义类型。在C++中，`enum`的使用方式比C语言更为灵活，可以定义枚举类和作用域等。下面是C++中`enum`的几种常见用法示例：

### 1. 基本枚举（传统C风格）

```cpp
#include <iostream>
using namespace std;

enum Color {
    Red,    // 默认从0开始
    Green,  // 1
    Blue    // 2
};

int main() {
    Color color = Green;
    cout << "Color: " << color << endl;  // 输出: Color: 1
    return 0;
}
```

- 在这个示例中，`Color`是一个枚举类型，`Red`, `Green`, `Blue`是枚举的成员。
- 默认情况下，枚举成员从0开始递增，可以显式指定起始值。

### 2. 显式指定枚举值

```cpp
#include <iostream>
using namespace std;

enum Color {
    Red = 5,
    Green = 10,
    Blue = 15
};

int main() {
    Color color = Blue;
    cout << "Color: " << color << endl;  // 输出: Color: 15
    return 0;
}
```

- 你可以显式地指定枚举成员的值。
>以上内容的理解：
>类似于Python中的键值对，不必去顾虑那些具体的值，直接调用它们那用人话写的键就可以了！

### 3. 枚举类（C++11引入）

枚举类是C++11引入的特性，它使得枚举更加类型安全，避免了枚举值的隐式转换。

```cpp
#include <iostream>
using namespace std;

enum class Color {
    Red = 1,
    Green = 2,
    Blue = 3
};

int main() {
    Color color = Color::Green;
    // cout << color;  // 错误：不能直接输出枚举类的值

    // 使用 static_cast 转换为基础类型
    cout << static_cast<int>(color) << endl;  // 输出: 2
    return 0;
}
```

- 枚举类使用 `enum class` 声明，要求你在访问枚举成员时显式使用作用域运算符（`::`）。
- 这样做避免了传统枚举中常见的隐式转换错误。

### 4. 枚举作为位标志

有时我们会使用枚举类型来表示位标志（Bit Flags），这种方式特别适合于需要多个选项组合的场景。

```cpp
#include <iostream>
using namespace std;

enum class Permissions : unsigned int {
    Read = 1 << 0,   // 1
    Write = 1 << 1,  // 2
    Execute = 1 << 2 // 4
};

int main() {
    Permissions p = Permissions::Read | Permissions::Write;  // 组合权限
    cout << "Has read and write: " << static_cast<int>(p) << endl;
    return 0;
}
```

- 在这里，`Permissions`枚举定义了三种权限，每种权限使用位移操作符来表示二进制位。
- `Read`、`Write`和`Execute`可以通过按位或（`|`）组合。

### 5. 使用`enum`作为`switch`语句的条件

```cpp
#include <iostream>
using namespace std;

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

void move(Direction dir) {
    switch (dir) {
        case Direction::Up:
            cout << "Moving up" << endl;
            break;
        case Direction::Down:
            cout << "Moving down" << endl;
            break;
        case Direction::Left:
            cout << "Moving left" << endl;
            break;
        case Direction::Right:
            cout << "Moving right" << endl;
            break;
    }
}

int main() {
    Direction dir = Direction::Left;
    move(dir);
    return 0;
}
```

- 枚举常常和`switch`语句一起使用，用来控制流程。

### 总结

- `enum`是一个强大且灵活的工具，在C++中使用时，你可以选择不同的方式来提高代码的类型安全性、可读性和可维护性。
- C++11引入的`enum class`是一个更安全的替代方案，避免了传统枚举类型的隐式转换问题。