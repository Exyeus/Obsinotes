### SLLists

Intlist in Cpt3 is awkward to use. Its a [[Naked Recursive Data Structure]].

Our first step will be to simply rename everything and throw away the helper methods. This probably doesn't seem like progress, but trust me, I'm a professional.

### Improvement 2 Bureaucracy

The term actually means administrating or managing.

```
public class IntNode {
    public int item;
    public IntNode next;

    public IntNode(int i, IntNode n) {
        item = i;
        next = n;
    }
}
```

```
public class SLList {
    public IntNode first;

    public SLList(int x) {
        first = new IntNode(x, null);
    }
}
```
The `SLList` hides the detail that there exists a null link from the user.

```
public class SLList {
    public IntNode first;

    public SLList(int x) {
        first = new IntNode(x, null);
    }

    /** Adds an item to the front of the list. */
    public void addFirst(int x) {
        first = new IntNode(x, first);
    }
}
/** Retrieves the front item from the list. */
public int getFirst() {
    return first.item;
}
```

Essentially, the `SLList` class acts as a middleman between the list user and the naked recursive data structure. As suggested above in the `IntList` version, there is a potentially undesireable possibility for the `IntList` user to have variables that point to the middle of the `IntList`. As Ovid said: [Mortals cannot look upon a god without dying](https://en.wikipedia.org/wiki/Semele), so perhaps it is best that the `SLList` is there to act as our intermediary.

### Improvement 3 Public vs. Private

Open access to data type may cause unexcepted errors.
For example, `first` and `next` are public, therefore it is possible that users establish loop connection to these elements on their own, therefore causing fatal error!
Private variables and methods can only be accessed by code inside the same `.java` file, e.g. in this case `SLList.java`.

### Improvement 4 Nested Classes

```
public class SLList {
       public class IntNode {
            public int item;
            public IntNode next;
            public IntNode(int i, IntNode n) {
                item = i;
                next = n;
            }
       }

       private IntNode first; 

       public SLList(int x) {
           first = new IntNode(x, null);
       } 
```

no meaningful effect on code performance, and is simply a tool for keeping code organized.
This saves a bit of memory, because each `IntNode` no longer needs to keep track of how to access its enclosing `SLList`.
![[Pasted image 20250331095042.png]]
*`addLast()` and `size()`*

From this, we can see some common patterns in data structure implementation. 

```java
/** Adds an item to the end of the list. */
public void addLast(int x) {
    IntNode p = first;

    /* Advance p to the end of the list. */
    while (p.next != null) {
        p = p.next;
    }
    p.next = new IntNode(x, null);
}
```

>Pay attention to the `IntNode p`. Due to java's trait of *reference type*, it serves just like a pointer in C!

### Improvement 5: Caching

Practice of saving important data to speed up retrieval is sometimes known as **caching**.

Put it simply, maintain a `size` variable that changes with every changes in the elements of the list.

```java
public class SLList {
    ... /* IntNode declaration omitted. */
    private IntNode first;
    private int size;

    public SLList(int x) {
        first = new IntNode(x, null);
        size = 1;  *********************************
    }

    public void addFirst(int x) {
        first = new IntNode(x, first);
        size += 1; *********************************
    }

    public int size() {
        return size;
    }
    ...
}
```

### Improvement 6: The Empty List

>Recalling those in CS61A.
>Empty list is represented, using class nil and its instance.
>Empty list must be the only one.
>Python's property of stress reference more than copy helps to implement this: once a nil instance is created, it can represent empty list all over the program.

*Solution*. Adding a special case for the *empty*.
```java
if (first == null){
	first = IntNode(x, null);
	return;
}
```

>for `void` type functions, `return;` is still available for exiting directly without executing following code.

This solution works, but special case code like that shown above should <span style="background:#d3f8b6">be avoided when necessary</span>. Human beings only have so much working memory, and thus we want to keep complexity under control wherever possible. For a simple data structure like the `SLList`, the number of <span style="background:#d3f8b6">special cases is small</span>. More complicated data structures like trees can get much, much uglier.

A cleaner, though less obvious solution, is to make it so that all `SLLists` <span style="background:#d3f8b6">are the "same"</span>, even if they are empty.
We can do this by creating a special node that is always there, which we will call a <span style="background:#d3f8b6">sentinel node</span>. The sentinel node will hold a value, which we won't care about.

```
In this context, the word "yield" means "to produce" or "to result in." 
It is used to indicate that removing the special case from the addLast method will lead to a specific outcome or a new version of the method.
```

![[Pasted image 20250331154251.png]]

In the figures above, the **lavender ?? value** indicates that we don't care what value is there. Since Java does not allow us to fill in an integer with question marks, we just pick some abitrary value like -518273 or 63 or anything else.

Since a `SLList` without a sentinel has no special cases, we can simply delete the special case from our `addLast` method, yielding:
[[Deepseek_ExplanationForSentinelNodes]]
[[Gemini_ExplanationForSentinelNodes]]


### Invariants

A `Single Linked List` with a sentinel node has at least the following invariants:
- The `sentinel` reference always points to a sentinel node.
- The front item, if exists, is always at `sentinel.next.item`.
- The `size` variable is always the total num of items that have been added. Then why it belongs to the class of invariants?

Invariants make it easier to reason about code, and also give you specific goals to strive for in making sure your code works.

“Guaranteed to be true” 表示在正常情况下，某个性质或条件始终成立。它强调的是在符合设计要求和前提条件的情况下，该性质不会被违反。这与布尔值始终为true 不完全相同，因为布尔值只是逻辑状态的一种表示，而“guaranteed to be true” 更多的是关于逻辑条件或性质的保证。

希望这个解释能帮助你更好地理解“guaranteed to be true” 的含义！



















