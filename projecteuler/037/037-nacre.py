#!/usr/bin/env python

import math

def is_prime(n):
    if n <= 1:
        return 0
    elif n == 2:
        return 1
    
    if n % 2 == 0:
        return 0
    for i in xrange(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return 0
    else:
        return 1

def left_truncable(n):
    while n:
	if not(is_prime(n)):
	    return 0
	len = int(math.log10(n))
	n = n % (10 ** len)
    return 1

def right_truncable(n):
    while n:
	if not(is_prime(n)):
	    return 0
	n = n / 10
    return 1

def sum_both_truncable():
    sum = 0
    count = 0
    n = 7
    while count < 11 : # the last digit of n must be 3 or 7
	n = n + 6
	if left_truncable(n) and right_truncable(n):
	    count += 1
	    sum += n
	n = n + 4
	if left_truncable(n) and right_truncable(n):
	    count += 1
	    sum += n
    return sum

print sum_both_truncable()
