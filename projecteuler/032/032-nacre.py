#!/usr/bin/env python

from itertools import permutations

def is_pandigital_product(s):
    if int(s[:2]) * int(s[2:5]) == int(s[5:]):
	return 1
    if int(s[0]) * int(s[1:5]) == int(s[5:]):
        return 1
    return 0

lp = []
for s in permutations('123456789'):
    s = reduce(lambda x, y: x + y, s)
    if is_pandigital_product(s):
        product = int(s[5:])
        if not(product in lp):
            lp.append(product)
print sum(lp)
