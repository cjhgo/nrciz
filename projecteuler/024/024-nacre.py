#!/usr/bin/env python

from math import factorial

facts = [factorial(9 - i) for i in range(10)]
list = range(10)

n = 1000000 - 1 # we start the numbering by 0

digits = ''
for i in range(10):
    r = n / facts[i]
    n = n % facts[i]
    list.sort()
    digits += str(list[r + i])
    list[r + i] = -1

print digits
