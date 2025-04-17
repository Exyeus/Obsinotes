### Improving `addLast`

Due to the complexity increasing with the length of the object, we consider to use an implementation similar to `size`: adding a new attribute tracking the last element with each updating.

```java
public class SLList {
    private IntNode sentinel;
    private IntNode last;
    private int size;    

    public void addLast(int x) {
        last.next = new IntNode(x, null);
        last = last.next;
        size += 1;
    }
    ...
}
```

By implementing this, we can realize rapid `addLast` and `getLast`. But there no direct rapid `removeLast` from this edition, because getting the second to last is not easy.

>There no point in adding a getSecondToLast, because then the one before it is still hard to get.
>Idea: for the IntNode, add an attribute of the reference of the one before it. Then, if we want to remove the last one, we can operate the `second to last` through the attribute of the last one.

```java
public class IntNode {
    public IntNode prev;
    public int item;
    public IntNode next;
}
```

### Improvement 8: Sentinel Upgrade

After adding a prev pointer, the operation for `addLast` `removeLast` `getLast` have all turned to a constant time.
There is a subtle issue with this design where the `last` pointer sometimes *points at the sentinel node, and sometimes at a real node*. Just like the non-sentinel version of the `SLList`, this results in code with special cases that is much uglier than what we'll get after our 8th and final improvement.


![[Pasted image 20250401145330.png]]

### Generic that creates DLList

in 2004, the creators of Java added **generics** to the language, which will allow you to, among other things, create data structures that hold any reference type.

A generic `DLList` that can hold any type would look as below:

```java
public class DLList<BleepBlorp> {
    private IntNode sentinel;
    private int size;

    public class IntNode {
        public IntNode prev;
        public BleepBlorp item;
        public IntNode next;
        ...
    }
    ...
}
```

Now that we've defined a generic version of the `DLList` class, we must also use a special syntax to instantiate this class. To do so, we put the desired type inside of angle brackets during declaration, and also use empty angle brackets during instantiation.

```java
DLList<String> d2 = new DLList<>("hello");
d2.addLast("world");
```


Since generics only work with reference types, we cannot put primitives like `int` or `double` inside of angle brackets, e.g. `<int>`. Instead, we use the reference version of the primitive type, which in the case of `int` case is `Integer`, e.g.

```java
DLList<Integer> d1 = new DLList<>(5);
d1.insertFront(10);
```

Some rules of thumb:

- In the .java file implementing a data structure, specify your generic type name only *once* at the very top of the file after the class name.
- In *other* `.java` files, which use your data structure, specify the specific desired type during *declaration*, and use the *empty diamond operator* during instantiation.
- Using `Integer` `Double` `Character` `Boolean` `Long` `Short` `Byte` `Float`





















