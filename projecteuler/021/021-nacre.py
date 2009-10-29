#!/usr/bin/env python

from math import sqrt

def sum_divisor(n):
    sum = 1 # 1 is always a proper divisor
    sqrt_n = int(sqrt(n))
    for i in range(2, sqrt_n + 1):
	if n % i == 0:
	    sum = sum + i + n / i
    if sqrt_n * sqrt_n == n:
	sum -= sqrt_n
    return sum

def is_amicable(n):
    n1 = sum_divisor(n)
    if n1 == n or n1 == 1:
	return 0
    elif n == sum_divisor(n1):
	return 1
    else:
	return 0

def sum_amicable(limit):
    sum = 0
    for i in range(3, limit + 1):
	if is_amicable(i):
	    sum += i
    return sum

print sum_amicable(10000)
