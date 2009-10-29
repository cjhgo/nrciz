#!/usr/bin/env python

facts = [362880, 40320, 5040, 720, 120, 24, 6, 2, 1, 1]
list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

n = 1000000 - 1 # we start the numbering by 0

for i in range(10) :
    r = n / facts[i]
    n = n % facts[i]
    list.sort()
    print list[r + i],
    list[r + i] = -1
