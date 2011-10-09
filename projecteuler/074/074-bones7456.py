#!/usr/bin/env python

from math import factorial
def next(n):
#    return sum(factorial(int(i)) for i in str(n))  # slow
    t = 0
    while n >= 10:
        t += factorial(n % 10)
        n = n / 10
    t += factorial(n)
    return t

n = 0
for i in range(1, 1000001):
    A = {i : 1}
    while True:
        i = next(i)
        if i in A:
            break
        else:
            A[i] = 1
    if len(A) == 60:
        n += 1
print n
