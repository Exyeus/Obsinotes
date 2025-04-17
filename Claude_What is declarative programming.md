# Introduction to Declarative Programming

Declarative programming is a programming paradigm that expresses the logic of computation without describing its control flow. Unlike imperative programming, which focuses on how to achieve a result through a sequence of statements that change program state, declarative programming focuses on what the program <span style="background:#d3f8b6">should accomplish</span>.

## Core Concepts

Declarative programming is built on several fundamental principles:

1. **Expressing what, not how**: Programs specify the desired result rather than the step-by-step instructions to achieve it.

2. **Immutability**: Data is typically treated as immutable, meaning once created, it cannot be changed.

3. **Absence of side effects**: Functions don't modify state outside their scope, making programs easier to reason about.

4. **Declarative syntax**: The code resembles a description of the problem domain rather than computational steps.

## Main Paradigms of Declarative Programming

### 1. Functional Programming

Functional programming treats computation as the evaluation of mathematical functions and avoids changing state and mutable data. It emphasizes:

- **First-class functions**: Functions can be assigned to variables, passed as arguments, and returned from other functions.
- **Pure functions**: Functions that given the same input, always return the same output without side effects.
- **Higher-order functions**: Functions that take other functions as parameters or return functions.

```haskell
-- Example in Haskell: computing the sum of squares of even numbers
sumOfSquaresOfEvens xs = sum (map (^2) (filter even xs))
```

### 2. Logic Programming

Logic programming expresses programs as a set of logical relations rather than a sequence of operations. Key aspects include:

- **Relations**: Programs define relationships between entities rather than computations.
- **Unification**: The process of finding substitutions that make logical expressions identical.
- **Backtracking**: Automatically exploring multiple solution paths.

```prolog
% Example in Prolog: defining family relationships
parent(john, mary).
parent(john, tom).
parent(jane, mary).
parent(jane, tom).

grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
```

### 3. Database Query Languages

SQL is a classic example of declarative programming:

```sql
-- Finding all students with a GPA above 3.5
SELECT name, major FROM students WHERE gpa > 3.5 ORDER BY name;
```

The query describes what data to retrieve without specifying how to perform the search or sorting.

## Advantages of Declarative Programming

1. **Conciseness**: Programs are often shorter and more readable.
2. **Easier reasoning**: Simpler to verify correctness when state changes are minimized.
3. **Parallelization**: Absence of side effects makes parallelization more straightforward.
4. **Higher abstraction**: Focuses on the domain problem rather than computational details.

## Examples in Modern Programming

### React.js (Declarative UI)

```javascript
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}
```

Here, the component declares what the UI should look like without directly manipulating the DOM.

### SQL vs. Imperative Data Processing

Declarative (SQL):
```sql
SELECT department, AVG(salary) 
FROM employees 
GROUP BY department;
```

Imperative equivalent would require loops, counters, and explicit aggregation logic.

## Relation to Computer Science Theory

Declarative programming connects to several theoretical CS concepts:

- **Lambda calculus**: The mathematical foundation of functional programming.
- **Relational algebra**: The theoretical basis for database query languages.
- **Logic and proof systems**: Underpinning logic programming languages.

## Conclusion

Declarative programming represents a higher level of abstraction in software development, allowing programmers to focus on what needs to be computed rather than how to compute it. While imperative programming remains important for system-level programming and performance-critical applications, declarative approaches are gaining popularity for their readability, maintainability, and suitability for parallel computation.

This paradigm shift aligns with the evolution of computer science toward higher abstractions that hide implementation details and allow programmers to express solutions in terms closer to the problem domain.