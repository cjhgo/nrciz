#!/usr/bin/env python

from math import sqrt

def has_solution(c, aPb):
    for a in range(max(1, aPb - c), aPb / 2 + 1):
	b = aPb - a
	if a * a + b * b == c * c:
	    return 1
    return 0

def num_solution(p):
    num = 0
    cmin = int(p / (1 + sqrt(2)))
    for c in range(cmin, p / 2 + 1):
	num = num + has_solution(c, p - c)
    return num

pmax = 0
nmax = 0
for p in range(2, 1000, 2) : # the perimeter is always even
    n = num_solution(p)
    if n > nmax:
        pmax = p
        nmax = n
print pmax
