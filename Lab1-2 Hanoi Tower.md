```python
def move_stack(start, end):
    def stack_sum(n):
        def find_missing_pillar(a, b):
            return (set(['A','B','C']) - {a,b}).pop()
  
        def innervoice(sum, rod1, rod2, rod3):
            if sum == 1:
               print("Move the top disk from rod {} to rod {}".format(rod1, rod3))
                return
            elif sum > 1:
                innervoice(sum-1, rod1, rod3, rod2)
                innervoice(1, rod1, rod2, rod3)
                innervoice(sum-1, rod2, rod1, rod3)
        innervoice(n, start, find_missing_pillar(start, end), end)
    return stack_sum

operator = move_stack('A', 'C')
print("\n2:")
operator(2)
print("\n3:")
operator(3)
print("\n4:")
operator(4)
print("\n6:")
operator(6)
```

```Result
2:
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C

3:
Move the top disk from rod A to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod C

4:
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C

6:
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod C to rod A
Move the top disk from rod C to rod B
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
Move the top disk from rod B to rod A
Move the top disk from rod C to rod A
Move the top disk from rod B to rod C
Move the top disk from rod A to rod B
Move the top disk from rod A to rod C
Move the top disk from rod B to rod C
```
