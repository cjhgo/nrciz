#!/usr/bin/env python
def Fibonacci(n):
    a,b = 1,2
    while a < n:
        yield a
        a,b = b,a+b

print sum([i for i in Fibonacci(4000000) if i%2==0])

