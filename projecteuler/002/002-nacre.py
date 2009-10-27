#!/usr/bin/python

def fib(n):
    a, b = 1, 2
    while a < n:
        yield a
        a, b = b, a + b

print sum(i for i in fib(4000000) if i%2 == 0)
