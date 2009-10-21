#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
    
def MaxPrimeFactor(n):
    i=2
    while True:
        if n % i == 0 and IsPrime(n/i):
            return n/i
        i+=1
            
print MaxPrimeFactor(600851475143)
