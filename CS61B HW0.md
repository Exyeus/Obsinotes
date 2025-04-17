# Homework 0A: Java Syntax

## [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#language-constructs)Language Constructs

Many Python fundamentals have a Java equivalent, such as loops and if statements. This section shows a direct comparison of the syntax.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#variable-declaration)Variable Declaration

|Python|Java|
|---|---|
|```<br>i = 0<br>```|```<br>int i = 0;<br>```|

- Just like Python, Java variables have _types_. In Java, to declare a variable, we have to explicitly say what type it is. A variable’s declared type can never change. Refer to Lecture 1 for more on “static typing.”
- We also have to put a semi-colon at the end of the statement.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#types)Types

|Python|Java|What?|
|---|---|---|
|`bool`|`boolean`|Python uses `True` and `False`; Java uses `true` and `false`.|
|`int`|`int`|While Python `int`s are unbounded, Java `int`s have a (large) max and min value.|
|`float`|`double`|Decimal values. Java `doubles` are again bounded.|
|`str`|`String`|Java `String`s use double quotes (`"`), and can be any text.|
|no equivalent|`char`|Java `char` represents a _single_ character, and uses single quotes (`'`).|

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#comments)Comments

|Python|Java|
|---|---|
|```<br># This is a single line comment.<br>```|```<br>// This is a single line comment.<br>```|

Java also has multi-line comments that are started by `/*` and ended by `*/`.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#while-loop)`while` Loop

|Python|Java|
|---|---|
|```<br>i = 0<br>while i < 10:<br>    print(i)<br>    i += 1<br><br>```|```<br>int i = 0;<br>while (i < 10) {<br>    System.out.println(i);<br>    i++;<br>}<br>```|

- The parentheses, `(` and `)` around the condition are required.
- In Java, `++` is often used instead of `+= 1`.
- We really do use `System.out.println` to print in Java. Sorry.
- Instead of indenting, we use curly braces, `{` and `}` to wrap the code that is part of the while loop. Java doesn’t require indenting, but it’s good style!

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#for-loop-counting-up)`for` Loop (counting up)

|Python|Java|
|---|---|
|```<br>for i in range(10):<br>    print(i)<br><br>```|```<br>for (int i = 0; i < 10; i ++) {<br>    System.out.println(i);<br>}<br>```|

In Java, the `for` loop has the syntax:

```
for (initialization; termination; increment) {
    // loop body
}
```

This is roughly equivalent to the while loops:

|Python|Java|
|---|---|
|```<br>initialization<br>while termination:<br>    # loop body<br>    increment<br><br>```|```<br>initialization<br>while (termination) {<br>    // loop body<br>    increment<br>}<br>```|

The `while` loops and the `for` loop exit when the termination condition is false. The `for` loops in the comparison table go “until” `i = 10`.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#for-loop-counting-down)`for` Loop (counting down)

|Python|Java|
|---|---|
|```<br>for i in range(9, -1, -1):<br>  print(i)<br><br>```|```<br>for (int i = 9; i >= 0; i --) {<br>  System.out.println(i);<br>}<br>```|

- Note the different “initialization”, “termination”, and “increment” blocks in the Java `for` loop.
- Similarly to `++`, `--` is often used instead of `-= 1`.
- The `for` loops in the comparison table go “until” `i < 0`.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#conditionals)Conditionals

|Python|Java|
|---|---|
|```<br>if i % 3 == 0 and i % 5 == 0:<br>    print("FizzBuzz")<br>elif i % 3 == 0:<br>    print("Fizz")<br>elif i % 5 == 0:<br>    print("Buzz")<br>else:<br>    print(i)<br><br>```|```<br>if (i % 3 == 0 && i % 5 == 0) {<br>    System.out.println("FizzBuzz");<br>} else if (i % 3 == 0) {<br>    System.out.println("Fizz");<br>} else if (i % 5 == 0) {<br>    System.out.println("Buzz");<br>} else {<br>    System.out.println(i);<br>}<br>```|

The boolean operators are as follows:

|Python|Java|
|---|---|
|`and`|`&&`|
|`or`|`\|`|
|`not`|`!`|
|`==`|`==`|

- Note the difference between `elif` and `else if`.
- NOTE: In Java, `==` is used for identity, and `.equals()` is used for equality. For primitive types, this means the same thing, but for reference types, it may be different. For this assignment, you do not need to know the difference; we’ll learn more about this later.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#exponentiation)Exponentiation

|Python|Java|
|---|---|
|```<br>x = 2**10<br>```|```<br>double x = Math.pow(2, 10);<br>```|

Note that `^` in Java is the “XOR” operator, not the exponentiation operation. That is, `2 ^ 10` is valid code, but it will return `8`, not `1024`.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#function-declaration-and-usage)Function Declaration and Usage

|Python|Java|
|---|---|
|```<br>def greet(name):<br>    return "Hello, " + name<br><br># Elsewhere...<br>print(greet("Josh"))<br>```|```<br>public static String greet(String name) {<br>    return "Hello, " + name;<br>}<br>// Elsewhere...<br>System.out.println(greet("Josh"));<br>```|

- In Java, functions have a specific return type that comes before the function name. Functions also specify their arguments’ types.
    - When a function returns nothing, it has a return type of `void`.
- For now, all our functions will have `public static` in front. We’ll learn what these mean later.
- Calling a function looks the same as in Python.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#strings)Strings

|Python|Java|
|---|---|
|```<br>s = "hello"<br>s += " world"<br>s += str(5)<br>s_length = len(s)<br>substr = s[1:5]<br>c = s[2]<br>if "hello" in s:<br>    print("\"hello\" in s")<br><br>for letter in s:<br>    print(letter)<br><br>```|```<br>String s = "hello";<br>s += " world";<br>s += 5;<br>int sLength = s.length();<br>String substr = s.substring(1, 5);<br>char c = s.charAt(2);<br>if (s.indexOf("hello") != -1) {<br>    System.out.println("\"hello\" in s");<br>}<br>for (int i = 0; i < s.length(); i++) {<br>    char letter = s.charAt(i);<br>    System.out.println(letter);<br>}<br>```|

- In Java, `String`s are not directly iterable. We either iterate over an index and use `charAt`, or we convert it to an array (coming soon).
- In Java, you can add anything to a `String`s, and it will be implicitly converted to a `String` without needing to explicitly cast.

## [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#programs)Programs

Now that we’ve covered individual language constructs, let’s look at some Java programs that use them. Here are some simple ones that you might find yourself referring to if you forget how to do something.

### [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#hello-world)Hello World

|Python|Java|
|---|---|
|```<br>print("Hello World")<br>```|```<br>public class HelloWorld {<br>    public static void main(String[] args) {<br>        System.out.println("Hello World");<br>    }<br>}<br>```|

- All Java code must be in a **class**. We’ll learn more about classes later.
- When a Java program is executed, it runs the **`public static void main(String[] args)`** method. This is different from Python, where code can be executed outside of a function.

## [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#exercises)Exercises

**Make sure you have completed Lab 1 before continuing on.**

UW has a large collection of introductory Java exercises on a site called Practice-It that we will be borrowing. For HW 0A, we’ve picked a few of these exercises for you to complete!

Note: the University of Washington has limited access to Practice-It and is planning on discontinuing the service. **You are not required (or expected) to log in to Practice-It to complete this assignment.** See the Deliverables section for explicit instructions on how to complete HW 0A.

- Self-Check 1.26: Confusing
- Exercise 2.5: `starTriangle`
- Self-Check 2.25: `numberTotal`
- Exercise 3.23: `printIndexed`
- Exercise 4.17: `stutter`
- Self-Check 4.5: `ifElseMystery1`
- Exercise 4.19: `quadrant`

We have provided some skeleton code to get you started. To obtain the skeleton code, follow the [normal assignment workflow](https://sp25.datastructur.es/resources/guides/assignment-workflow/).

Once you have the skeleton code, open it in IntelliJ. You will find problem descriptions for each of the tasks in the comment above the corresponding method signature. You are required to complete `starTriangle`, `printIndexed`, `stutter`, and `quadrant` for full credit. We encourage you to complete `Confusing`, `numberTotal`, and `ifElseMystery1` as well, but we won’t be grading these.

If you run into trouble with the exercises, one strategy could be solving in Python first, then translating that to Java. If you’re having trouble with solving in Python, that’s fine, and not the point of this exercise. If you’d like to reference Python solutions, see the dropdowns below.

`starTriangle`

`printIndexed`

`stutter`

`quadrant`

## [](https://sp25.datastructur.es/homeworks/hw0/hw0a/#deliverables)Deliverables

You have two options for receiving credit on this assignment.

- Submit a working implementation to Homework 0A: Code
- Submit a screenshot to Homework 0A: Screenshots

**If you are completing HW 0A for the first time,** you must complete the exercises in the skeleton files. Once you have commited and pushed your work to your remote repository, you can submit your code to Homework 0A: Code on Gradescope. If you pass all of the autograder tests, you have finished the assignment!

**If you’ve already done HW 0A previously before** (e.g. you enrolled in 61B in an earlier semester but dropped it), you can submit the screenshot you used previously showing earlier completion dates for the Practice-It exercises. You don’t need to do anything else, but we highly encourage to redo any exercises that you are unfamiliar with to brush up.

Note: If you are having trouble getting your screenshot into the PDF format required by Gradescope, try using [this converter](https://png2pdf.com/).

Congratulations! You’re prepared for the next few lectures, and have completed HW 0. After Lecture 2, you’ll be ready to read HW0B, but you can get a head start now if you’d like.

A programming language is not too different from a spoken language – in particular, you will get better the more code you write. The PracticeIt site has **many** problems available, and you should feel free to attempt more. (Their progression doesn’t exactly match ours, though – if you see a `Scanner` or need to generate a random number, you can skip that problem.)

We also recommend [https://codingbat.com/java/AP-1](https://codingbat.com/java/AP-1), which has more advanced Java problems.