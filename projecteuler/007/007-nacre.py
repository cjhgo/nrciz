#!/usr/bin/python

import math

# \frac{n}{\ln n+2}\lt \pi(n)\lt \frac{n}{\ln n-4}, for x\ge 55
ubound = 500000
list_int = range(2, ubound)

for i in range(int(math.sqrt(ubound-1))):
    if list_int[i] != 0:
	for j in range(i+list_int[i], ubound-2, list_int[i]):
	    list_int[j] = 0

i = 0
numPrime = 0
while numPrime < 10001:
    if list_int[i] != 0:
	numPrime += 1
    i += 1

print list_int[i-1]
