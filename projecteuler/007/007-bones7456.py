#!/usr/bin/env python
from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
    
n,x = 1,1
while n < 10001:
    x+=2
    if IsPrime(x):
        n+=1
print x
