#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
def GenPrime(n):
    i = 3
    while i <= n:
        if IsPrime(i):
            yield i
        i+=2
print sum([n for n in GenPrime(2000000)])+2
