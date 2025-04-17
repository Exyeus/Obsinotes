
```
---------------------------------------------------------------------
Problem 4 > Suite 2 > Case 6
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 4 > Suite 2 > Case 7
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 4 unlocked.

---------------------------------------------------------------------
Problem 5 > Suite 1 > Case 1
(cases remaining: 4)

Q: What is the structure of the expressions argument to do_quote_form?
Choose the number of the correct choice:
0) [A], where:
       A is the quoted expression
1) A, where:
       A is the quoted expression
2) Pair('quote', Pair(A, nil)), where:
       A is the quoted expression
3) Pair(A, nil), where:
       A is the quoted expression
? 3
-- OK! --

---------------------------------------------------------------------
Problem 5 > Suite 2 > Case 1
(cases remaining: 3)

>>> from scheme import *
>>> global_frame = create_global_frame()
>>> do_quote_form(Pair(3, nil), global_frame)
? 3
-- OK! --

>>> do_quote_form(Pair('hi', nil), global_frame)
? hi
-- Not quite. Try again! --

>>> from scheme import *
>>> global_frame = create_global_frame()
>>> do_quote_form(Pair(3, nil), global_frame)
? 3
-- OK! --

>>> do_quote_form(Pair('hi', nil), global_frame)
? hi
-- Not quite. Try again! --

>>> global_frame = create_global_frame()
>>> do_quote_form(Pair(3, nil), global_frame)
? 3
-- OK! --

>>> do_quote_form(Pair('hi', nil), global_frame)
? hi
-- Not quite. Try again! --

? 3
-- OK! --

>>> do_quote_form(Pair('hi', nil), global_frame)
? hi
-- Not quite. Try again! --


>>> do_quote_form(Pair('hi', nil), global_frame)
? hi
-- Not quite. Try again! --

? hi
-- Not quite. Try again! --

? 'hi'

? 'hi'
-- OK! --

? 'hi'
-- OK! --

>>> expr = Pair(Pair('+', Pair('x', Pair(2, nil))), nil)
-- OK! --

>>> expr = Pair(Pair('+', Pair('x', Pair(2, nil))), nil)
>>> do_quote_form(expr, global_frame) # Make sure to use Pair notation

>>> expr = Pair(Pair('+', Pair('x', Pair(2, nil))), nil)
>>> do_quote_form(expr, global_frame) # Make sure to use Pair notation
>>> expr = Pair(Pair('+', Pair('x', Pair(2, nil))), nil)
>>> do_quote_form(expr, global_frame) # Make sure to use Pair notation
? 'Pair(Pair('+', Pair('x', Pair('x', Pair(2, nil))), nil)
>>> do_quote_form(expr, global_frame) # Make sure to use Pair notation
? 'Pair(Pair('+', Pair('x', Pair('x', Pair(2, nil))), nil)
? 'Pair(Pair('+', Pair('x', Pair('x', Pair(2, nil))), nil)
-- Not quite. Try again! --
-- Not quite. Try again! --


? 'Pair('+', Pair('x', Pair('x', Pair(2, nil)))
-- Not quite. Try again! --
-- Not quite. Try again! --

? '((+ x 2))'
-- Not quite. Try again! --

? '( (+ x 2) )'
-- Not quite. Try again! --

? 'Pair(Pair('+', Pair('x', Pair(2, nil))), nil)'
-- Not quite. Try again! --

? '+'
-- Not quite. Try again! --

? Pair('+', Pair('x', Pair(2, nil)))
-- OK! --

---------------------------------------------------------------------
Problem 5 > Suite 3 > Case 1
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 5 > Suite 4 > Case 1
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 5 unlocked.

---------------------------------------------------------------------
Problem 6 > Suite 1 > Case 1
(cases remaining: 8)

>>> from scheme import *
>>> env = create_global_frame()
>>> eval_all(Pair(2, nil), env)
Choose the number of the correct choice:
0) SchemeError
1) 2
? 0
-- Not quite. Try again! --

Choose the number of the correct choice:
0) SchemeError
1) 2
? 1
-- OK! --

>>> eval_all(Pair(4, Pair(5, nil)), env)
Choose the number of the correct choice:
0) 4
1) SchemeError
2) (4 5)
3) 5
? 3
-- OK! --

>>> eval_all(nil, env) # return None (meaning undefined)
---------------------------------------------------------------------
Problem 6 > Suite 1 > Case 2
(cases remaining: 7)

-- Already unlocked --

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 1
(cases remaining: 6)


scm> (begin (+ 2 3) (+ 5 6))
? 11
-- OK! --

scm> (begin (define x 3) x)
? 3
-- OK! --

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 2
(cases remaining: 5)


scm> (begin 30 '(+ 2 2))
Choose the number of the correct choice:
0) (+ 2 2)
1) '(+ 2 2)
2) 4
3) 30
? 1
-- Not quite. Try again! --

Choose the number of the correct choice:
0) (+ 2 2)
1) '(+ 2 2)
2) 4
3) 30
? 2
-- Not quite. Try again! --

Choose the number of the correct choice:
0) (+ 2 2)
1) '(+ 2 2)
2) 4
3) 30
? 3
-- Not quite. Try again! --

Choose the number of the correct choice:
0) (+ 2 2)
1) '(+ 2 2)
2) 4
3) 30
? 0
-- OK! --

scm> (define x 0)
? x
-- OK! --

scm> (begin (define x (+ x 1)) 42 (define y (+ x 1)))
? y
-- OK! --

? y
-- OK! --

-- OK! --


scm> x
? 1
-- OK! --
scm> x
? 1
-- OK! --
? 1
-- OK! --

-- OK! --


scm> y
scm> y
? 2
-- OK! --
? 2
-- OK! --

-- OK! --

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 3

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 3
(cases remaining: 4)

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 3
(cases remaining: 4)

-- Already unlocked --
(cases remaining: 4)

-- Already unlocked --


-- Already unlocked --

---------------------------------------------------------------------
-- Already unlocked --

---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 4
(cases remaining: 3)
---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 4
(cases remaining: 3)
Problem 6 > Suite 2 > Case 4
(cases remaining: 3)
(cases remaining: 3)


-- Already unlocked --
-- Already unlocked --

---------------------------------------------------------------------

---------------------------------------------------------------------
---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 5
Problem 6 > Suite 2 > Case 5
(cases remaining: 2)
(cases remaining: 2)


-- Already unlocked --

---------------------------------------------------------------------
---------------------------------------------------------------------
Problem 6 > Suite 2 > Case 6
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 6 unlocked.

---------------------------------------------------------------------
Problem 7 > Suite 1 > Case 1
(cases remaining: 5)


scm> (lambda (x y) (+ x y)) ;; An lambda procedure is displayed exactly as it is written
? lambda (x y) (+ x y)
-- Not quite. Try again! --

? (x y) (+ x y)
-- Not quite. Try again! --

? LambdaProcedure((x y), (+ x y) env)
-- Not quite. Try again! --

? (+ x y)
-- Not quite. Try again! --

? (lambda (x y) (+ x y))
-- OK! --

scm> (lambda (x)) ; type SchemeError if you think this causes an error
? SchemeError
-- OK! --

---------------------------------------------------------------------
Problem 7 > Suite 1 > Case 2
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 7 > Suite 1 > Case 3
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 7 > Suite 2 > Case 1
(cases remaining: 2)

>>> from scheme_reader import *
>>> from scheme import *
>>> env = create_global_frame()
>>> lambda_line = read_line("(lambda (a b c) (+ a b c))")
>>> lambda_proc = do_lambda_form(lambda_line.rest, env)
>>> lambda_proc.formals # use single quotes ' around strings in your answer
Choose the number of the correct choice:
0) Pair('a', Pair('b', Pair('c', nil)))
1) Pair(Pair('a', Pair('b', Pair('c', nil))))
2) Pair('+', Pair('a', Pair('b', Pair('c', nil))))
? 1
-- Not quite. Try again! --

Choose the number of the correct choice:
0) Pair('a', Pair('b', Pair('c', nil)))
1) Pair(Pair('a', Pair('b', Pair('c', nil))))
2) Pair('+', Pair('a', Pair('b', Pair('c', nil))))
? 0
-- OK! --

>>> lambda_proc.body # the body is a *Scheme list* of expressions! Make sure your answer is a properly nested Pair.
Choose the number of the correct choice:
0) Pair('+', Pair('a', Pair('b', Pair('c', nil))))
1) Pair('+', 'a', 'b', 'c')
2) Pair('a', Pair('b', Pair('c')))
3) Pair(Pair('+', Pair('a', Pair('b', Pair('c', nil)))), nil)
? 0
-- Not quite. Try again! --

Choose the number of the correct choice:
0) Pair('+', Pair('a', Pair('b', Pair('c', nil))))
1) Pair('+', 'a', 'b', 'c')
2) Pair('a', Pair('b', Pair('c')))
3) Pair(Pair('+', Pair('a', Pair('b', Pair('c', nil)))), nil)
? 3
-- OK! --

---------------------------------------------------------------------
Problem 7 > Suite 2 > Case 2
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 7 unlocked.

---------------------------------------------------------------------
Problem 8 > Suite 1 > Case 1
(cases remaining: 6)

>>> from scheme import *
>>> global_frame = create_global_frame()
>>> formals = Pair('a', Pair('b', Pair('c', nil)))
>>> vals = Pair(1, Pair(2, Pair(3, nil)))
>>> frame = global_frame.make_child_frame(formals, vals)
>>> global_frame.lookup('a') # Type SchemeError if you think this errors
? 1
-- Not quite. Try again! --

? SchemeError
-- OK! --

>>> frame.lookup('a')        # Type SchemeError if you think this errors
? 1
-- OK! --

>>> frame.lookup('b')        # Type SchemeError if you think this errors
? 2
-- OK! --

>>> frame.lookup('c')        # Type SchemeError if you think this errors
? 3
-- OK! --

---------------------------------------------------------------------
Problem 8 > Suite 1 > Case 2
(cases remaining: 5)

>>> from scheme import *
>>> global_frame = create_global_frame()
>>> frame = global_frame.make_child_frame(nil, nil)
>>> frame.parent is global_frame
? True
-- OK! --

---------------------------------------------------------------------
Problem 8 > Suite 1 > Case 3
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 8 > Suite 2 > Case 1
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 8 > Suite 2 > Case 2
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 8 > Suite 2 > Case 3
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 8 unlocked.

---------------------------------------------------------------------
Problem 9 > Suite 1 > Case 1
(cases remaining: 7)

-- Already unlocked --

---------------------------------------------------------------------
Problem 9 > Suite 1 > Case 2
(cases remaining: 6)

-- Already unlocked --

---------------------------------------------------------------------
Problem 9 > Suite 2 > Case 1
(cases remaining: 5)

-- Already unlocked --

---------------------------------------------------------------------
Problem 9 > Suite 2 > Case 2
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 9 > Suite 3 > Case 1
(cases remaining: 3)


scm> (define x 5)
? x
-- OK! --

scm> (define outer (lambda (x)
....   (lambda () (print x))))
? outer
-- OK! --

scm> (define inner (outer 2))
? inner
-- OK! --

scm> (inner) ;; which x is accessed? which frame is the parent?
? 2
-- OK! --

---------------------------------------------------------------------
Problem 9 > Suite 3 > Case 2
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 9 > Suite 3 > Case 3
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 9 unlocked.

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 1
(cases remaining: 7)


scm> (define (f x y) (+ x y))
? f
-- OK! --

scm> f
Choose the number of the correct choice:
0) (lambda (x y) (+ x y))
1) (define f (lambda (x y) (+ x y)))
2) (lambda (f x y) (+ x y))
3) (f (x y) (+ x y))
? 2
-- Not quite. Try again! --

Choose the number of the correct choice:
0) (lambda (x y) (+ x y))
1) (define f (lambda (x y) (+ x y)))
2) (lambda (f x y) (+ x y))
3) (f (x y) (+ x y))
? 3
-- Not quite. Try again! --

Choose the number of the correct choice:
0) (lambda (x y) (+ x y))
1) (define f (lambda (x y) (+ x y)))
2) (lambda (f x y) (+ x y))
3) (f (x y) (+ x y))
? 0
-- OK! --

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 2
(cases remaining: 6)

-- Already unlocked --

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 3
(cases remaining: 5)

-- Already unlocked --

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 4
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 5
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 10 > Suite 1 > Case 6
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 10 > Suite 2 > Case 1
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 10 unlocked.

---------------------------------------------------------------------
Problem 11 > Suite 1 > Case 1
(cases remaining: 2)


scm> (define y 1)
? y
-- OK! --

scm> (define f (mu (x) (+ x y)))
? f
-- OK! --

scm> (define g (lambda (x y) (f (+ x x))))
? g
-- OK! --

scm> (g 3 7)
? 6
-- Not quite. Try again! --

? 13
-- OK! --

---------------------------------------------------------------------
Problem 11 > Suite 2 > Case 1
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 11 unlocked.

---------------------------------------------------------------------
Problem 12 > Suite 1 > Case 1
(cases remaining: 9)


scm> (and)
Choose the number of the correct choice:
0) #f
1) SchemeError
2) #t
? #t
-- OK! --

scm> (and 1 #f)
Choose the number of the correct choice:
0) #f
1) 1
2) #t
? #f
-- OK! --

scm> (and (+ 1 1) 1)
? 1
-- OK! --

scm> (and #f 5)
? #f
-- OK! --

scm> (and 4 5 (+ 3 3))
? 6
-- OK! --

scm> (not (and #t #f 42 (/ 1 0)))
? #t
-- OK! --

---------------------------------------------------------------------
Problem 12 > Suite 1 > Case 2
(cases remaining: 8)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 1 > Case 3
(cases remaining: 7)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 1 > Case 4
(cases remaining: 6)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 2 > Case 1
(cases remaining: 5)


scm> (or)
Choose the number of the correct choice:
0) SchemeError
1) #f
2) #t
? #f
-- OK! --

scm> (or (+ 1 1))
Choose the number of the correct choice:
0) #f
1) 2
2) #t
? #f
-- Not quite. Try again! --

Choose the number of the correct choice:
0) #f
1) 2
2) #t
? 2
-- Not quite. Try again! --

Choose the number of the correct choice:
0) #f
1) 2
2) #t
? #t
-- Not quite. Try again! --

Choose the number of the correct choice:
0) #f
1) 2
2) #t
? 0
-- Not quite. Try again! --

Choose the number of the correct choice:
0) #f
1) 2
2) #t
? 1
-- OK! --

scm> (not (or #f))
? #t 
-- OK! --

scm> (define (zero) 0)
? zero
-- OK! --

scm> (or (zero) 3)
? 3
-- Not quite. Try again! --

? #t
-- Not quite. Try again! --

? zero
-- Not quite. Try again! --

? 0
-- OK! --

scm> (or 4 #t (/ 1 0))
? 4 
-- OK! --

---------------------------------------------------------------------
Problem 12 > Suite 2 > Case 2
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 2 > Case 3
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 2 > Case 4
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 12 > Suite 2 > Case 5
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 12 unlocked.

---------------------------------------------------------------------
Problem 13 > Suite 1 > Case 1
(cases remaining: 6)


scm> (cond ((> 2 3) 5)
....       ((> 2 4) 6)
....       ((< 2 5) 7)
....       (else 8))
? 7
-- OK! --

scm> (cond ((> 2 3) 5)
....       ((> 2 4) 6)
....       (else 8))
? 8
-- OK! --

scm> (cond ((= 1 1))
....       ((= 4 4) 'huh)
....       (else 'no))
? ()
-- Not quite. Try again! --

?  
-- Not quite. Try again! --

? SchemeError
-- Not quite. Try again! --

? 'huh
-- Not quite. Try again! --

? huh
-- Not quite. Try again! --

? #t
-- OK! --

scm> (cond ((and #f 2) 'whats)
....       ((and 1 #t 2))
....       ((> 2 3) 'going)
....       (else 'on))
? 'on
-- Not quite. Try again! --

? on
-- Not quite. Try again! --

? #t
-- Not quite. Try again! --

? 2
-- OK! --

---------------------------------------------------------------------
Problem 13 > Suite 2 > Case 1
(cases remaining: 5)

-- Already unlocked --

---------------------------------------------------------------------
Problem 13 > Suite 2 > Case 2
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 13 > Suite 2 > Case 3
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 13 > Suite 2 > Case 4
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 13 > Suite 2 > Case 5
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 13 unlocked.

---------------------------------------------------------------------
Problem 14 > Suite 1 > Case 1
(cases remaining: 9)


scm> (define x 1)
? x
-- OK! --

scm> (let ((x 5))
....    (+ x 3))
? 8
-- OK! --

scm> x
? 1
-- OK! --

---------------------------------------------------------------------
Problem 14 > Suite 1 > Case 2
(cases remaining: 8)


scm> (let ((a 1) (b a)) b)
Choose the number of the correct choice:
0) y
1) x
2) 1
3) SchemeError
? 2
-- Not quite. Try again! --

Choose the number of the correct choice:
0) y
1) x
2) 1
3) SchemeError
? 3
-- OK! --

---------------------------------------------------------------------
Problem 14 > Suite 1 > Case 3
(cases remaining: 7)


scm> (let ((x 5))
....    (let ((x 2)
....          (y x))
....        (+ y (* x 2))))
? SchemeError
-- Not quite. Try again! --

? 6
-- Not quite. Try again! --

? 14
-- Not quite. Try again! --

? 12
-- Not quite. Try again! --

? 9
-- OK! --

---------------------------------------------------------------------
Problem 14 > Suite 1 > Case 4
(cases remaining: 6)


scm> (let ((a 2) (a 3)) (+ a a)) ; how should we catch something like this?
? 6
-- Not quite. Try again! --

? 5
-- Not quite. Try again! --

? 4
-- Not quite. Try again! --

? SchemeError
-- OK! --

scm> (let ((y 2 3)) (+ y y)) ; should this be an allowable form?
? SchemeError
-- OK! --

---------------------------------------------------------------------
Problem 14 > Suite 1 > Case 5
(cases remaining: 5)

-- Already unlocked --

---------------------------------------------------------------------
Problem 14 > Suite 2 > Case 1
(cases remaining: 4)

-- Already unlocked --

---------------------------------------------------------------------
Problem 14 > Suite 2 > Case 2
(cases remaining: 3)

-- Already unlocked --

---------------------------------------------------------------------
Problem 14 > Suite 2 > Case 3
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 14 > Suite 3 > Case 1
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 14 unlocked.

---------------------------------------------------------------------
Problem 15 > Suite 1 > Case 1
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 15 > Suite 1 > Case 2
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 15 unlocked.

---------------------------------------------------------------------
Problem 16 > Suite 1 > Case 1
(cases remaining: 2)

-- Already unlocked --

---------------------------------------------------------------------
Problem 16 > Suite 1 > Case 2
(cases remaining: 1)

-- Already unlocked --

---------------------------------------------------------------------
OK! All cases for Problem 16 unlocked.

Backup... 100% complete
```