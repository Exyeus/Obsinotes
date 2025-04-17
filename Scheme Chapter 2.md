# 2.1 同Scheme交互
如你所见，Scheme 表达式可以跨越多行。Scheme 系统可以识别出没有闭合的双引号，括号。
```scheme
"hello" => "hello"
42 => 42
22/7 => 22/7
(/ 21 7) => 3
3.141592653 => 3.141592653
+ => #<procedure>
(+ 76 31) => 107
(* -12 10) => -120
'(a b c d) => (a b c d)
```
下面，我们尝试定义一个函数

```scheme
(define square
  (lambda (n)
    (* n n)))
```

这个函数计算 `n` 的平方。`define` 建立一个新的变量绑定，`lambda`创建了一个函数，`*`是乘法函数的名字。注意这些表达式的形式。所有结构形式包含在括号里面，并且写作“前缀”形式，即，操作符写在参数前面。

# 2.2 简单的表达式

最简单的 Scheme 表达式是*常量对象*（字面量），比如字符串，数字，符号及列表。Scheme 还支持别的对象类型，不过对大多数程序，这四种就足够了。
非精确数通表示浮点数，遵循 IEEE 浮点数标准。
Scheme 使用前缀表示法，甚至包括最常用的算术操作符在内，统统使用前缀表达式。
在大多数其它语言里，最基本的数据结构是数组。在 Scheme 里，*使用最多的是列表 (list)*。列表是由括号*包围起来的对象序列*，例如， `(1 2 3 4 5)` 是一个数字的列表， `("this" "is" "a" "list")`是一个字符串列表。列表里可以包含不同类型的对象， `(4.2 "hi")`; 列表还可以嵌套 `((1 2) (3 4))`.

除非我们明确地告诉 Scheme 将一个列表视为数据，而不是函数调用，否则 Scheme 将把一个列表视为函数调用。我们可以使用“引用”(quote) 来做到这个点。因为`quote`很常用，Scheme 提供了另外一种简短的缩写，就是单引号 (')，
```
(quote (1 2 3 4 5)) => (1 2 3 4 5)
(quote ("this" "is" "a" "list")) => ("this" "is" "a" "list")
(quote (+ 3 4)) => (+ 3 4)
```
相同的表示法允许将 Scheme 代码表示为数据，可以简化解释器、编译器、编辑器以及其它工具的编写。

有两个过程分别用来获取列表的不同部分：`car`及`cdr`。`car`返回列表的第一个元素，而`cdr`返回列表中剩下的所有元素。（car 及 cdr 的名称起源自第一台在硬件上实现 Lisp 语言的机器，IBM 704）。它们都需要一个非空列表作为参数。
`cons`过程用来**构造列表**，它接受两个参数，第二个参数通常是一个列表。如果第二个参数是一个列表，那么 cons 也返回一个列表，它将第一个参数添加到第二个参数的头部，形成一个新的列表。

如果最后一个 cdr 不是空列表，那么这就不是一个合法的列表。空列表是一个合法的列表。任何列表，只要它的 cdr 部分是一个合法的列表，那么它就是一个合法的列表。

一个不合法的列表用*点对*来表示，元素之间用一个句点来隔开：

```
(cons 'a 'b) => (a . b)
(cdr '(a . b)) => b
(cons 'a '(b . c)) => (a b . c)
```

因为这种表示法，一个对偶经常被称作“点对”（又称点值对）。甚至于，一个合法的列表也可以用点对来表示

```
'(a . (b . (c . ()))) => (a b c)
```

`list`过程类似于`cons`，只不过它接受任意数量的参数，并且总是返回一个列表

```
(list 'a 'b 'c) => (a b c)
(list 'a) => (a)
(list) => ()
```
# 2.3 Scheme表达式求值

一个可能的求值规则是：

- 找到 `procedure` 的值
- 找到 _arg1_ 的值
- ......
- 找到 _argn_的值
- 将 `procedure` 的值应用到 _arg1 ... argn_ 的值上面
这个求值规则对函数调用有效，对`quote`表达式无效，因为`quote`不对它的子表达式求值。对`quote`表达式的求值类似于对常量的求值。

# 2.4 变量与Let表达式

假设`expr`是一个表达式，其中包含一个变量`var`，进一步，假设当我们对表达式`expr`求值的时候，`var`的值是`val`。比如，当我们计算 `(+ x 3)` 的时候，我们希望 `x` 的值为2, 或者，当我们计算 `(+ 2 y)` 的时候，希望 `y` 的值为 3. 下面的示例展示了如何利用 Scheme 的 `let` 语法形式做到这一点。

```
(let ((x 2))
  (+ x 3)) => 5

(let ((y 3))
  (+ 2 y)) => 5

(let ((x 2) (y 3))
  (+ x y)) => 5
```

`let` 语法结构包含一个由“变量-表达式”对构成的列表，后面跟着一系列的表达式，我们称之为 `let` 的 `body`。通用的 `let` 语法结构如下：

```
(let ((var expr) ...) body1 body2 ...)
```

经常用方括号代替括号来分隔 `let` 表达式之中的多个绑定
由 `let` 绑定的变量仅仅在 _body_ 部分可见. 这是幸运的，我们可不想在全局范围内将加法过程 `+` 给想修改成乘法 `*`

`let`表达式是可以嵌套的

```
(let ([a 4] [b 3])
  (let ([a-squared (* a a)]
        [b-squared (* b b)])
    (+ a-squared b-squared))) => 25
```

当我们在嵌套的`let`表达式里对相同的变更重复绑定，内在层的_body_里，只有内层的绑定是可见的。

```
(let ([x 1])
  (let ([x (+ x 1)])
    (+ x x))) => 4
```
我们说，内层的 `x` *遮蔽*了外层的绑定，一个`let`绑定，在它的整个 _body_ 里是完全可见的，除非它被遮蔽起来。<span style="background:#d3f8b6">变量可见的范围称作它的作用域</span>，在上面的代码里，第一个 x 的作用域是外层 let 的 body，它的 body 即内层的 let 表达式。在内层的 let 表达式里, 第一个 x 被第二个 x 给遮蔽了。这种作用域形式叫做“词法作用域”。每一个绑定的作用域可以从程序的文本直接了当地分析出来。

多说一句，与之对应的是“动态作用域”，早期的 Lisp 语言与现在的 Emacs Lisp 采用的就是动态作用域。

**练习 2.4.1** 重写下面的表达式，使用 let 去除共同的子表达式，以改善代码结构。注意，不要使用任何代数简化。

a. `(+ (- (* 3 a) b) (+ (* 3 a) b))`
```
(let ((x (* 3 a))) (+ (- x b)(+ x b)))
```

b. `(cons (car (list a b c)) (cdr (list a b c)))`
```
(let ((x list 'a 'b 'c)) (cons (car (x)) (cdr x)))
? (let((x list a b c)) (cons (car x)(cdr x)))
```
**练习 2.4.2** 判断下面的表达式的值，解释你是怎么推导出值的

```
(let ([x 9])
  (* x
     (let ([x (/ x 3)])
       (+ x x))))
```

**练习 2.4.3** 重写下面的表达式，给每个不同的 let 绑定变量不同的名字，使得没有变量被遮蔽，确认修改后的表达式的值与原来的表达式相同。

a.

```
(let ([x 'a] [y 'b])
  (list (let ([x 'c]) (cons x y))
        (let ([y 'd]) (cons x y))))
>(let ([x 'a] [y 'b])
    (list (let ([z 'c]) (cons z y))
          (let ([w 'd]) (cons x w))))
'((c . b) (a . d))
```

b.

```
(let ([x '((a b) c)])
  (cons (let ([x (cdr x)])
          (car x))
        (let ([x (car x)])
          (cons (let ([x (cdr x)])
                  (car x))
                (cons (let ([x (car x)])
                        x)
                      (cdr x))))))
```

### Section 2.5. Lambda Expressions

When the body of the `let` is complicated, however, having to repeat it can be inconvenient.
Instead, we can use the syntactic form *lambda* to create a new procedure that has x as a parameter and has the same body as the let expression.A procedure is just as much an object as a number, string, symbol, or pair.

The procedure is *the value of* `(lambda (x) (+ x x))`, and the only argument is the value of (* 3 4), or 12. The argument values, or _actual parameters_, are bound to the formal parameters within the body of the lambda expression in the same way as let-bound variables are bound to their values.
```

(let ([double (lambda (x) (+ x x))])  
  (list (double (* 3 4))  
        (double (/ 99 11))  
        (double (- 2 7))))
(24 18 -10)
```
Here, we establish a binding for double to a procedure, then use this procedure to double three different values.

The procedure expects its actual parameter to be a number, since it passes the actual parameter on to +. In general, the actual parameter may be any sort of object. Consider, for example, a similar procedure that uses cons instead of +.
```
(let ([double-cons (lambda (x) (cons x x))])  
  (double-cons 'a)) ![<graphic>]
(a . a)
```
Noting the similarity between double and double-cons, you should not be surprised to learn that they may be collapsed into a single procedure by adding an additional argument.

As with let expressions, lambda expressions become somewhat more interesting when *they are nested within other lambda or let expressions*.
```
(let ([x 'a])  
  (let ([f (lambda (y) (list x y))])  
    (f 'b))) => (a b)
```
The occurrence of x within the lambda expression refers to the x outside the lambda that is bound by the outer let expression. The variable x is said to _occur free_ in the lambda expression or to be a _free variable_ of the lambda expression. The variable y does not occur free in the lambda expression since it is bound by the lambda expression. A variable that occurs free in a lambda expression should be bound, e.g., by an enclosing lambda or let expression, unless the variable is (like the names of primitive procedures) bound outside of the expression, as we discuss in the following section.

### Section 2.6. Top-Level Definitions

Some items defined in the inner scope cannot be access else where in the program. Suppose you have created an object, perhaps a procedure, that must be accessible anywhere, like + or cons. What you need is a _top-level definition_, which may be established with `define`. Supported by most interactive Scheme systems, are visible in every expression you enter, except where shadowed by another binding.
```
(define double-any  
  (lambda (f x)  
    ((doubler f) x)))
```

### Section 2.7. Conditional Expressions

```
(define abs  
  (lambda (n)  
    (if (>= n 0)  
        n  
        (- 0 n))))  
  
(define abs  
  (lambda (n)  
    (if (not (< n 0))  
        n  
        (- 0 n))))  
  
(define abs  
  (lambda (n)  
    (if (or (> n 0) (= n 0))  
        n  
        (- 0 n))))  
  
(define abs  
  (lambda (n)  
    (if (= n 0)  
        0  
        (if (< n 0)  
            (- 0 n)  
            n))))  
  
(define abs  
  (lambda (n)  
    ((if (>= n 0) + -)  
     0  
     n)))

(define reciprocal  
  (lambda (n)  
    (and (not (= n 0))  
         (/ 1 n))))




```

The procedures =, <, >, <=, and >= are called _predicates_. A predicate is a procedure that answers a specific question about its arguments and returns one of the two values `#t` or `#f`. The names of most predicates end with a question mark ( ? );

To relieve the caller of this obligation, it is usually preferable to report the error, using assertion-violation, as follows.
```
(define reciprocal  
  (lambda (n)  
    (if (and (number? n) (not (= n 0)))  
        (/ 1 n)  
        (assertion-violation 'reciprocal  
          "improper argument"  
          n))))
```
```

(define sign  
  (lambda (n)  
    (if (< n 0)  
        -1  
        (if (> n 0)  
            +1  
            0))))

(sign -88.3)  -1  
(sign 0) ! 0  
(sign 333333333333)  1  
(* (sign -88.3) (abs -88.3)) -88.3
```
The two if expressions may be replaced by a single cond expression as follows.
```

(define sign  
  (lambda (n)  
    (cond  
      [(< n 0) -1]  
      [(> n 0) +1]  
      [else 0])))
```
A cond expression usually takes the form

(cond (_test_ _expr_) ... (else _expr_))

though the else clause may be omitted









