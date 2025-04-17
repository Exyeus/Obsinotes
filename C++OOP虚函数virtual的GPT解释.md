---
sr-due: 2025-09-21
sr-interval: 165
sr-ease: 290
---

#review 

在C++中，**虚函数（Virtual Function）** 是面向对象编程中的一个重要概念，它允许派生类重写基类中的方法，并且通过基类的指针或引用来调用派生类的实现。这是实现**运行时多态**的核心机制。虚函数使得程序能够根据对象的实际类型而不是指针或引用的类型来调用正确的方法，从而实现灵活的行为和扩展。

### **虚函数是什么？**

虚函数是指在基类中使用`virtual`关键字声明的方法，它可以在派生类中被重写。通过基类指针或引用调用虚函数时，程序会根据对象的实际类型来决定调用哪个版本的函数，而不是根据指针或引用的类型决定。

**基本语法：**

```cpp
class Base {
public:
    virtual void foo() {
        std::cout << "Base class foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() override {  // 使用 override 来表示重写
        std::cout << "Derived class foo()" << std::endl;
    }
};
```

### **虚函数的作用**

1. **实现运行时多态**： 虚函数允许通过基类的指针或引用调用派生类中的重写方法。在运行时，程序能够动态决定调用哪一个函数，而不是在编译时就确定。
    
    **例子：**
    
    ```cpp
    class Animal {
    public:
        virtual void sound() {
            std::cout << "Animal sound" << std::endl;
        }
    };
    
    class Dog : public Animal {
    public:
        void sound() override {
            std::cout << "Bark" << std::endl;
        }
    };
    
    class Cat : public Animal {
    public:
        void sound() override {
            std::cout << "Meow" << std::endl;
        }
    };
    
    int main() {
        Animal* animal1 = new Dog();
        Animal* animal2 = new Cat();
    
        animal1->sound();  // 输出 "Bark"
        animal2->sound();  // 输出 "Meow"
    
        delete animal1;
        delete animal2;
    }
    ```
    
    在这个例子中，`sound()`方法是虚函数，根据对象的实际类型，程序分别调用`Dog`类和`Cat`类中的`sound()`方法，而不是基类`Animal`的版本。
    
2. **支持接口和抽象类**： 虚函数常用于定义接口类和抽象类，确保派生类提供对某些方法的具体实现。
    
3. **实现动态绑定**： 通过虚函数，C++实现了动态绑定，也就是在运行时决定调用哪个函数。相比之下，普通函数是在编译时静态绑定的。
    

### **虚函数的特性**

1. **虚函数表（VTable）**： C++使用虚函数表（VTable）来实现虚函数的动态绑定。每个包含虚函数的类会有一个虚函数表，表中存储了指向各个虚函数的指针。当通过基类指针或引用调用虚函数时，程序会查找对应的虚函数表并调用正确的函数。
    
2. **构造函数和虚函数**： 虚函数不能在构造函数中被调用。如果在基类构造函数中调用虚函数，实际上会调用基类的虚函数版本，而不是派生类的版本。这是因为在构造过程中，派生类的部分还没有构造完成。
    
    **例子：**
    
    ```cpp
    class Base {
    public:
        Base() {
            foo();  // 调用虚函数
        }
        virtual void foo() {
            std::cout << "Base class foo()" << std::endl;
        }
    };
    
    class Derived : public Base {
    public:
        void foo() override {
            std::cout << "Derived class foo()" << std::endl;
        }
    };
    
    int main() {
        Derived d;  // 输出 "Base class foo()"
    }
    ```
    
    在构造时，`foo()`会调用基类版本的`foo()`，而不是派生类版本。
    
3. **析构函数必须是虚函数（对于继承链中的对象销毁）**： 如果一个类作为基类被继承，并且有虚函数，那么基类的析构函数必须是虚函数。这样，派生类对象在销毁时，基类的析构函数会被调用，确保正确释放资源。
    
    **例子：**
    
    ```cpp
    class Base {
    public:
        virtual ~Base() {  // 必须是虚析构函数
            std::cout << "Base class destructor" << std::endl;
        }
    };
    
    class Derived : public Base {
    public:
        ~Derived() override {
            std::cout << "Derived class destructor" << std::endl;
        }
    };
    
    int main() {
        Base* obj = new Derived();
        delete obj;  // 输出 "Derived class destructor" 然后 "Base class destructor"
    }
    ```
    

### **使用虚函数的注意事项**

1. **避免在构造函数和析构函数中调用虚函数**： 如前所述，构造函数和析构函数中的虚函数调用会导致不期望的行为，通常应该避免在这些地方调用虚函数。
    
2. **虚函数的性能开销**： 使用虚函数会有一定的性能开销，主要体现在通过虚函数表查找正确的函数指针上。对于性能要求非常高的场景，可以尽量减少虚函数的使用。
    
3. **虚函数的覆盖**： 当子类重写基类的虚函数时，应该使用`override`关键字来标明这是对基类虚函数的重写。这样可以帮助编译器检查是否正确覆盖了虚函数，避免拼写错误或签名不匹配的问题。
    
    ```cpp
    class Base {
    public:
        virtual void foo() {
            std::cout << "Base foo" << std::endl;
        }
    };
    
    class Derived : public Base {
    public:
        void foo() override {  // 使用 override 关键字
            std::cout << "Derived foo" << std::endl;
        }
    };
    ```
    
4. **虚函数指针的注意**： 虚函数表与多态机制紧密相关。如果通过一个指向基类的指针调用虚函数，实际调用的是派生类的函数（如果有重写）。在设计时要明确多态的使用场景，以确保正确的函数被调用。
    

### 总结

- **虚函数**允许在基类中声明方法，并且让派生类可以重写这些方法，实现多态。
- 通过虚函数实现的**运行时多态**可以使得程序更加灵活，能够根据对象的实际类型调用适当的方法。
- 使用虚函数时需要注意虚函数表的开销、构造函数中的调用限制、以及虚析构函数的重要性。

虚函数是面向对象编程中的强大工具，但也需要合理使用，避免不必要的性能损失和复杂的错误。