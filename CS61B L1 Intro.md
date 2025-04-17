### Features and Properties

All code must be in a class.
The codes seem to be quite verbose, but actually this is a significant property.
semicolons are required, just like C/C++
```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}
```

### Java WorkFlow

There are several reasons for the usage of `.class` files, which we will only cover briefly here. First of all, `.class` files are guaranteed to have been *type-checked*, making the distributed code safer. They are also more efficient to execute, and protect the actual source code in cases of *intellectual property*. We will not go into the details of `.class` files in this textbook beyond knowing that they are created after compilation.

![[1-2-compile-interpret.svg]]

### Basic Java Features

```java
public class HelloWorld{
	public static void main(String[] args)
	{
		System.out.println("Hello World");
		int x = 0;
		while (x < 10){
		 System.out.println(x + "");
		 x = x + 1;
		}
	}
}
```

- Our variable x must be declared before it is used, _and it must be given a type!
- Our loop definition is contained inside of curly braces, and the boolean expression that is tested is contained inside of parentheses.
- Our print statement is just `System.out.print` instead of `System.out.println`. This means we should *not include a newline* (a return).
- Our print statement adds a number to a space. This makes sure the numbers don't run into each other. Try removing the space to see what happens.
- When we run it, our prompt ends up on the same line as the numbers (which you can fix in the following exercise if you'd like).

### Defining Functions

Due to its property that all thins should exist in classes, functions should also be defined inside classes. Therefore, `function` and `method ` are interchangeable in this course.

```java
public class LargerDemo {
    public static int larger(int x, int y) {
        if (x > y) {
            return x;
        }
        return y;
    }

    public static void main(String[] args) {
        System.out.println(larger(8, 10));
    }
}
```

[style guide](https://sp19.datastructur.es/materials/guides/style-guide.html)








































