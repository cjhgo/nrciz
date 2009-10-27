#!/usr/bin/env python

import math

ubound = 2000000
list = range(2, ubound+1)

for i in range(int(math.sqrt(ubound))):
    if list[i] != 0:
	for j in range(i + list[i], ubound - 1, list[i]):
	    list[j] = 0

print sum(list)
