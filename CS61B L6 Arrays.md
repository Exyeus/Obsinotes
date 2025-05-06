---
sr-due: 2025-05-17
sr-interval: 23
sr-ease: 250
---

#review 

```Review
- How to harness recursive class definitions
- How to create an expandable list class
```

How to build a list class using `arrays`. Is `array` here a built-in type?
Arrays consist of:

- A fixed integer length, N. Just as those in C language.
- A sequence of N memory boxes (N = length) where all boxes are of the same type, and are numbered 0 through N - 1.

There are three valid notations for array creation. Try running the code below and see what happens. Click [here](http://pythontutor.com/iframe-embed.html#code=public%20class%20ArrayCreationDemo%20%7B%0A%20%20public%20static%20void%20main\(String%5B%5D%20args%29%20%7B%0A%20%20%20%20int%5B%5D%20x%3B%0A%20%20%20%20int%5B%5D%20y%3B%0A%20%20%20%20x%20%3D%20new%20int%5B3%5D%3B%0A%20%20%20%20y%20%3D%20new%20int%5B%5D%7B1,%202,%203,%204,%205%7D%3B%0A%20%20%20%20int%5B%5D%20z%20%3D%20%7B9,%2010,%2011,%2012,%2013%7D%3B%0A%09%7D%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=java&rawInputLstJSON=%5B%5D&textReferences=false) for an interactive visualization.
- `x = new int[3];`
- `y = new int[]{1, 2, 3, 4, 5};`
- `int[] z = {9, 10, 11, 12, 13};`

The third notation, used to declare **and** create `z`, has the same behavior as the second notation. The only difference is that it omits the usage of `new`, and can only be used when combined with a variable declaration.

```java
int[] z = null;
int[] x, y;

x = new int[]{1, 2, 3, 4, 5};
y = x;
x = new int[]{-1, 2, 5, 4, 99};
y = new int[3];
z = new int[0];
int xL = x.length;

String[] s = new String[6];
s[4] = "ketchup";
s[x[3] - x[1]] = "muffins";

int[] b = {9, 10, 11};
System.arraycopy(b, 0, x, 3, 2);
```

The only downside is that `arraycopy` is (arguably) harder to read. Note that Java arrays only perform bounds checking at runtime. That is, the following code compiles just fine, but will crash at runtime.

```java
System.arraycopy(source_array, souarr_startindex, target_array, tararr_startindex, itemsSum)
```
`System.arraycopy(b, 0, x, 3, 2) --> x[3:5] = b[0:2]`
### 2D Arrays in Java

```java
int[][] pascalsTriangle;
pascalsTriangle = new int[4][];
int[] rowZero = pascalsTriangle[0];

pascalsTriangle[0] = new int[]{1};
pascalsTriangle[1] = new int[]{1, 1};
pascalsTriangle[2] = new int[]{1, 2, 1};
pascalsTriangle[3] = new int[]{1, 3, 3, 1};
int[] rowTwo = pascalsTriangle[2];
rowTwo[1] = -5;

int[][] matrix;
matrix = new int[4][];
matrix = new int[4][4];

int[][] pascalAgain = new int[][]{{1}, {1, 1},
                                 {1, 2, 1}, {1, 3, 3, 1}};
```

![[Pasted image 20250401155203.png]]

>`...arraycopy(x[0],...)` Notice that the `x[0]` is essentially an array
>The items sum 3 is exactly the number of elements in each sub array.

### Arrays vs. Classes

- Similarity: can be used to organize a bunch of memory boxes, to some extent unchangeable.
- Difference: 
	- Access: using `[]` vs using `.`
	- Type: single vs unbounded.

### Examples and Notices

One particularly notable impact of these difference is that `[]` notation allows us to specify <span style="background:#d3f8b6">which index we'd like at runtime</span>. For example, consider the code below:

```java
int indexOfInterest = askUserForInteger();
int[] x = {100, 101, 102, 103};
int k = x[indexOfInterest];
System.out.println(k);
```

If we run this code, we might get something like:
```
$ javac arrayDemo
$ java arrayDemo
What index do you want? 2
102
```

By contrast, specifying fields in a class is not something we do at runtime. For example, consider the code below:

```java
String fieldOfInterest = "mass";
Planet p = new Planet(6e24, "earth");
double mass = p[fieldOfInterest];
```

If we tried compiling this, we'd get a syntax error.

```
$ javac classDemo
FieldDemo.java:5: error: array required, but Planet found
        double mass = earth[fieldOfInterest];        
                               ^
```
The same problem occurs if we try to use dot notation:

```java
String fieldOfInterest = "mass";
Planet p = new Planet(6e24, "earth");
double mass = p.fieldOfInterest;
```
Compiling, we'd get:

```
$ javac classDemo
FieldDemo.java:5: error: cannot find symbol
        double mass = earth.fieldOfInterest;        
                           ^
  symbol:   variable fieldOfInterest
  location: variable earth of type Planet
```














