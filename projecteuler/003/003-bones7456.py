#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
    
def MaxPrimeFactor(n):
    for i in range(int(sqrt(n)),2,-1):
        if n % i == 0 and IsPrime(i):
            return i
            
print MaxPrimeFactor(600851475143)
