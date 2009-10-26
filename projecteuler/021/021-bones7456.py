#!/usr/bin/env python
from math import sqrt

def d(n):
    '''return sum of proper divisors of n'''
    r=1
    for i in range (2, int(sqrt(n)) ):
        if 0 == n % i:
            r += i + n /i
    if sqrt(n) == int(sqrt(n)):
        r += int(sqrt(n))
    return r
    
print sum([i for i in range(3,10000) if i!=d(i) and i==d(d(i))])
