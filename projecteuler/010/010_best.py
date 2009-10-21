#!/usr/bin/env python
from math import sqrt
limit=2000000
sievebound = int((limit-1)/2)
crosslimit = int((sqrt(limit)-1)/2)
sieve=range(1,sievebound+1)
for i in range(1,crosslimit+1):
    if sieve[i]:
        for j in range(2*i*(i+1),sievebound,2*i+1):
            sieve[j]=0
res=2
for i in range(1,sievebound):
    if sieve[i]:
        res += 2*i+1
print res
