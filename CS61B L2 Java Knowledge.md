---
sr-due: 2025-05-21
sr-interval: 27
sr-ease: 270
---

#review 

### Static vs Non-Static

If we only define a class, the program cannot run as we excepted. 
To realize what we desire for, adding a main method to `Dog` class or create a separate `DogLauncher` class will work.
```java
public class Dog {
    public static void makeNoise() {
        System.out.println("Bark!");
    }
}
```

```java
public class DogLauncher {
    public static void main(String[] args) {
        Dog.makeNoise();
    }
}
```

```
$ java DogLauncher
Bark!
```

*client*. A class that uses another class is sometimes called a "client" of *that class*. The two ways for implementation, have their own advantages under different cases.

### Constructor in Java Classes

Here, the instantiation is parameterized, saving us the time and messiness of manually typing out potentially many instance variable assignments. To enable such syntax, we need only add a "constructor" to our Dog class, as shown below:

```java
public class Dog {
    public int weightInPounds;

    public Dog(int w) {
        weightInPounds = w;
    }

    public void makeNoise() {
        if (weightInPounds < 10) {
            System.out.println("yipyipyip!");
        } else if (weightInPounds < 30) {
            System.out.println("bark. bark.");
        } else {
            System.out.println("woof!");
        }    
    }
}
```

*Using Arrays*.

```java
public class DogArrayDemo {
    public static void main(String[] args) {
        /* Create an array of two dogs. */
        Dog[] dogs = new Dog[2];
        dogs[0] = new Dog(8);
        dogs[1] = new Dog(20);

        /* Yipping will result, since dogs[0] has weight 8. */
        dogs[0].makeNoise();
    }
}
```

### Class Methods vs. Instance Methods

- Class methods, a.k.a. static methods
- Instance methods, a.k.a. non-static methods

*An direct example*.

```java
x = Math.sqrt(100)

Math m = new Math()
x = m.sqrt(100)
```

```
public static Dog maxDog(Dog d1, Dog d2) {
    if (d1.weightInPounds > d2.weightInPounds) {
        return d1;
    }
    return d2;
}
```

```
public Dog maxDog(Dog d2) {
    if (this.weightInPounds > d2.weightInPounds) {
        return this;
    }
    return d2;
}
```
### Static Variables

This can be accessed through classes. The way through instances is available but not plausible.

### `public static void main(String\[] args)`

With what we've learned so far, it's time to demystify the declaration we've been using for the main method. Breaking it into pieces, we have:

- `public`: So far, all of our methods start with this keyword.
    
- `static`: It is a static method, not associated with any particular instance.
    
- `void`: It has no return type.
    
- `main`: This is the name of the method.
    
- `String[] args`: This is a parameter that is passed to the main method.
    

**Command Line Arguments**

Since main is called by the Java interpreter itself rather than another Java class, it is the interpreter's job to supply these arguments. They refer usually to the command line arguments. For example, consider the program `ArgsDemo` below:

Copy

```
public class ArgsDemo {
    public static void main(String[] args) {
        System.out.println(args[0]);
    }
}
```

This program prints out the 0th command line argument, e.g.

```
> java ArgsDemo.java these are command line arguments
these
```










































