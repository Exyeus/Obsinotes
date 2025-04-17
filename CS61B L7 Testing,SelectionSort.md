---
sr-due: 2025-04-12
sr-interval: 4
sr-ease: 270
---

#review 
### Intro

In real world programming, there is no autograder. So a must is to write some code by yourself and test them.

### Practice

The logic behind the autograder, is that a program has *input*s, then uses the functions we write to process these inputs, and then cmp.

```java
public class TestSort {
    /** Tests the sort method of the Sort class. */
    public static void testSort() {
        String[] input = {"i", "have", "an", "egg"};
        String[] expected = {"an", "egg", "have", "i"};
        Sort.sort(input);
        for (int i = 0; i < input.length; i += 1) {
            if (!input[i].equals(expected[i])) {
                System.out.println("Mismatch in position " + i + ", expected: " + expected + ", but got: " + input[i] + ".");
                break;
            }
        }
    }

    public static void main(String[] args) {
        testSort();
    }
}
```

>Using a loop to check one by one instead of using `==` to judge, lies in that `==` judges whether or not the addresses the two respectively point to, are the same.
>`java.util.Arrays.equals` also works.


```java
import static com.google.common.truth.Truth.assertThat;
public class TestSort {
   /** Tests the sort method of the Sort class. */
   public static void testSort() {
       String[] input = {"cows", "dwell", "above", "clouds"};
       String[] expected = {"above", "clouds", "cows", "dwell"};
       Sort.sort(input);

       assertThat(input).isEqualTo(expected);
       
       ** This also reveals the OOP property of java
       ** Seemingly that `assertThat` creates objects
   }

   public static void main(String[] args) {
       testSort();
   }
}
```

### Selction Sort

- Find the smallest item.
- Move it to the front.
- Selection sort the remaining $N-1$ items (without touching the front item).
*Detailed Description of This Move Process*. Interchange the founded smallest one with the first one.

Be careful about the types in which the functions return, and the types our program framework desires.

Meanwhile, remember that iteration in designing certain code is quite common and acceptable, nvr sweat up to this mistks while writing code.

### Reflections

Rely on self-implemented tests!
Do not completely rely on autograder, which interrupts your workflow, and there are no autograders in real dev life.

*Test Driven Dev* TDD. 

1.   Identify a new feature.
2. Write a unit test for that feature.
3. Run the test. It should fail, *to prove your test works*.
4. Write code that passes the test. Yay!
5. Optional: refactor code to make it faster, cleaner, etc. Except now we have a reference to tests that should pass.



































