#!/usr/bin/env python

from math import factorial

facts = [factorial(i) for i in range(10)]

sum = 0
for i in range(3, facts[9] * 7):
    sum_fact = 0
    i2 = i
    while i2 != 0:
	sum_fact = sum_fact + facts[i2 % 10]
	i2 = i2 / 10
    if sum_fact == i:
	sum = sum + i

print sum
