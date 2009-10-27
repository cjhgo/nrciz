#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
    
def GetFactors(n):
    r=[1]
    for i in range(2, int(sqrt(n))):
        if n % i == 0:
            r.append(i)
            r.append(n/i)
    if sqrt(n) == int(sqrt(n)):
        r.append(sqrt(n))
    r.sort(reverse=1)
    return r

for i in GetFactors(600851475143):
    if IsPrime(i):
        print i
        break
#print MaxPrimeFactor(600851475143)
