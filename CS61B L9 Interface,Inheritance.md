#review 
## Inheritance I
### Problem

2 Classes have methods similar to each other.
*One way*. methods overriding. 2 methods with slight difference in their function signatures merely, are allowed to coexist in a class.
But there are also drawbacks for this:
- repetitive and ugly.
- more code to maintain
- you have to copy implemented code into every new *list class*.

### Definitions as abstraction

*Hypernym*.
*Hyponym*
Dog is the hypernym of husky, malamute
Husky and malamute are hyponyms of Dog

![[Pasted image 20250412220850.png]]

To express the hierarchy above, there are 2 steps:

1. Define a type for the general list *hypernym*.
2. Specify that some *list*s are hyponyms of this type.

The hypernym ca be called an *interface*. It is a contract that *specifies* what a list *must be able to do*, but not providing any *implementation* for those behaviors.

```java
public interface List61B<Item> {
    public void addFirst(Item x);
    public void add Last(Item y);
    public Item getFirst();
    public Item getLast();
    public Item removeLast();
    public Item get(int i);
    public void insert(Item x, int position);
    public int size();
}
```

`implements List61B<Item>` is essentially a promise. AList is saying "I promise I will have and define all the attributes and behaviors specified in the List61B interface"

### Overriding

When you do this, be sure to include the `@Override` tag right on top of the method signature.

```java
@Override
public void addFirst(Item x) {
    insert(x, 0);
}
```

This is not technically madatory. But this will help the compiler inform you about errors when compiling. Whereas if you include the tag, the compiler will *stop* and prompt you to fix your mistakes before your programs even *runs*.

### Interface Inheritance

*A relationship*, in which a subclass inherits all the methods and behaviors of the superclass.
*Interfaces* includes all the method *signatures*. But specific implementations should be done by *subclasses*.
This is *multi-generational*. A class will inherit from all classes above it.

### Recapping GRoE

Recall the Golden Rule of Equals we introduced in the first chapter. This means whenever we make an assignment `a = b` , we copy the bits from b into a, with the requirement that b is the same type as a.

### Implementation Inheritance

*What we have done*. We have understood that when there's inheritance between 2 classes, the superclass's attributes will be passed to the subclass.
Also, the *interface* is a relatively superclasses that define what its subclasses should implement.

But, in the *class as an interface*, it may have some implemented methods by those act as its superclasses, `a.k.a` hypernyms.

We use `default` to mark in this case.

```java
default public void print() {
    for (int i = 0; i < size(); i += 1) {
        System.out.print(get(i) + " ");
    }
    System.out.println();
}
```

However, this implementation is relatively verbose, for the calls for `get(i)`. If we can remove the calls for `get(i)`, the efficiency will be greatly improved.

*Recall*: The *Override Operation*.

```java
@Override
public void print() {
    for (Node p = sentinel.next; p != null; p = p.next) {
        System.out.print(p.item + " ");
    }
}
```

>`@Override` is not mandatory, but it will be useful when there is really some errors.
>The compiler will check them out, and prompt the users.

*Dynamic Method Selection*. The way through which java is able to know which method to call when call statements appear.

`List61B<String> lst = new SLList<String>()`

lst is of type `List61B`. This is called the *static type*.
However, objects themselves have types as well. It is type `SLList` that `lst` points to. *But*, it is meanwhile a `List61B`.

>Recall: `is-a` relationship! This makes the statement legal!
>But this assignment cannot be *reversed* !

*Dynamic Type*. This object is instantiated by the *constructor* of `SLList`. So it has `SLList` as its dynamic type.

When Java runs a method that is overriden, it searches for the appropriate method signature in it's **dynamic type** and runs it.

Aside: the name “dynamic type” is actually quite semantic in its origin! Should lst be reassigned to point to an object of another type, say a AList object, lst’s dynamic type would now be AList and not SLList! It’s dynamic because it changes based on the type of the object<font color="#ffff00"> it's currently referring to.</font>

Interface inheritance (what): Simply tells what the subclasses should be able to do.
- EX) all lists should be able to print themselves, how they do it is up to them.
Implementation inheritance (how): Tells the subclasses how they should behave.
- EX) Lists should print themselves exactly this way: by getting each element in order and then printing them.

## Inheritance II

2 ways to attain generity:
- Polymorphism
- Function Passing

Intro with Python
```python
class Dog:
	def __init__(self, name, size):
		self.name = name
		self.size = size
	def __gt__(self, other):
		return self.size > other.size

def get_the_max(x):
	max_value = x[0]
	for item in x:
		if item > max_value:
			max_value = item
	return max_value

max_dog = get_the_max(doglist)
```

>Operator overloading is a form of *polymorphism*
>*Polymorphism*: the ability in programming to present the same *programming interface* for differing underlying forms.

![[Pasted image 20250416223242.png]]

*Static Method System*.























