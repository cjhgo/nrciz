#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
def GenPrime(n):
    i = 41
    while i <= n:
        if IsPrime(i):
            yield i
        i+=2
maxn, maxab = 0, 0
for b in GenPrime(1000):
    for a in range(-999, 1000, 2):
        n = 0
        while n * n + a * n + b > 0 and IsPrime(n * n + a * n + b):
            n += 1
        if n > maxn:
            maxn = n
            #print ">>", a, b, maxn
            maxab = a * b
print maxab
