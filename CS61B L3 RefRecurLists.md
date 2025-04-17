### Walrus Problem

[Dynamic Demo](http://cscircles.cemc.uwaterloo.ca/java_visualize/#code=public+class+PollQuestions+%7B%0A+++public+static+void+main%28String%5B%5D+args%29+%7B%0A++++++Walrus+a+%3D+new+Walrus%281000,+8.3%29%3B%0A++++++Walrus+b%3B%0A++++++b+%3D+a%3B%0A++++++b.weight+%3D+5%3B%0A++++++System.out.println%28a%29%3B%0A++++++System.out.println%28b%29%3B++++++%0A%0A++++++int+x+%3D+5%3B%0A++++++int+y%3B%0A++++++y+%3D+x%3B%0A++++++x+%3D+2%3B%0A++++++System.out.println%28%22x+is%3A+%22+%2B+x%29%3B%0A++++++System.out.println%28%22y+is%3A+%22+%2B+y%29%3B++++++%0A+++%7D%0A+++%0A+++public+static+class+Walrus+%7B%0A++++++public+int+weight%3B%0A++++++public+double+tuskSize%3B%0A++++++%0A++++++public+Walrus%28int+w,+double+ts%29+%7B%0A+++++++++weight+%3D+w%3B%0A+++++++++tuskSize+%3D+ts%3B%0A++++++%7D%0A%0A++++++public+String+toString%28%29+%7B%0A+++++++++return+String.format%28%22weight%3A+%25d,+tusk+size%3A+%25.2f%22,+weight,+tuskSize%29%3B%0A++++++%7D%0A+++%7D%0A%7D&mode=edit)

### Bits

In Java, there are 8 primitive types: byte, short, int, long, float, double, boolean, and char. Each has different properties that we'll discuss throughout the course, with the exception of short and float, which you'll likely never use.

### The Golden Rule of Equals (GRoE)

Now armed with simplified box notation, we can finally start to resolve the Mystery of the Walrus.

It turns out our Mystery has a simple solution: When you write `y = x`, you are telling the Java interpreter to copy the bits from x into y. This Golden Rule of Equals (GRoE) is the root of all truth when it comes to understanding our Walrus Mystery.

Copy

```
int x = 5;
int y;
y = x;
x = 2;
System.out.println("x is: " + x);
System.out.println("y is: " + y);
```

This simple idea of copying the bits is true for ANY assignment using `=` in Java. To see this in action, click [this link](http://cscircles.cemc.uwaterloo.ca/java_visualize/#code=public+class+PollQuestions+%7B%0A+++public+static+void+main\(String%5B%5D+args%29+%7B%0A++++++int+x+%3D+5%3B%0A++++++int+y%3B%0A++++++y+%3D+x%3B%0A++++++x+%3D+2%3B%0A++++++System.out.println\(%22x+is%3A+%22+%2B+x%29%3B%0A++++++System.out.println\(%22y+is%3A+%22+%2B+y%29%3B++++++%0A+++%7D%0A%7D&mode=display&curInstr=0).

### Reference Types

This name suggests lots of valuable infomation. Reference means that the boundings lead to 2 names referring to the same object, so once we changed b, the attributes of a will be changed at the same time.
But meanwhile, vars of those primitive type, copy the targets' value while bounding. Therefore, if we bound x to y and change x, the value of y will not be changed.

8 primitive types and everything else belongs to `reference type`, which behave quite differently. *So there are 9 types in all*.

*Object Instantiation*.
`new` is used to instantiate an Object. And when we do this, Java first allocates a box *of size 64 bits* for each instance variable of the class, and fills them with a *default value*. Then, the `constructor` *usually* fills every box with some other value.
>Do you remember the construct function inside C++ classes?
>[[程序设计 20241203 面向对象初步]]

These bits can be set to either `null` or *the 64 bits size address*, which is returned by `new`.

*The GRoE*. When `=` is applied to primitive types, the whole value will be copied, while for reference types, the *64 bits size* address will be copied and bounded to the new name.
```
Given variables b and a:
b = a copies all bits from a into b
```
**Exercise 2.1.1**: Suppose we have the code below:

```java
public class PassByValueFigure {
    public static void main(String[] args) {
           Walrus walrus = new Walrus(3500, 10.5);
           int x = 9;

           doStuff(walrus, x);
           System.out.println(walrus);
           System.out.println(x);
    }

    public static void doStuff(Walrus W, int x) {
           W.weight = W.weight - 100;
           x = x - 5;
    }
}
```

`weight` will change, and x not change. *This need further explanation*！

*Making an array*
`new int[]{1,2,3,4}`
`a = new int[]{1,2,4}`, create a 64 bits address and store it at `a`

### `==` operator

Given 2 "boxes", comparing whether or not the two boxes "hold" the same thing! Therefore, `[1,2]` may not equal to `[1,2]`

Similar to =, we can think of the == operator in terms of bits. Whenever we write `x==y` we are asking Jafa to compare the literal bits in memory boxes `x` and `y`.

For example, suppose we have the code:
```
int[] x = new int[]{0, 1, 2, 95, 4};
int[] y = new int[]{0, 1, 2, 95, 4};
System.out.println(x == y); #false
```

This code will print false, since `x` and `y` each contain the 64 bit address of two different arrays in memory, albeit two arrays which happen to contain the same information. If we want to compare the two content of the two arrays, we can use Arrays.equals instead, e.g.
```
int[] x = new int[]{0, 1, 2, 95, 4};
int[] y = new int[]{0, 1, 2, 95, 4};
System.out.println(Arrays.equals(x, y)); #true
```

### IntList

please refer to [[CS61A 2.3 Sequences]]

































