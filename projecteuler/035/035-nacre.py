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

def is_circular_prime(n):
    numRot = int(math.log10(n))
    n1 = n
    for i in range(numRot) : # all digits of n should be odd
	n1 = n1 / 10
	if n1 % 2 == 0:
	    return 0
    if not(is_prime(n)):
	return 0
    for i in range(numRot):
	n = rotation(n)
	if not(is_prime(n)):
	    return 0
    return 1

def rotation(n):
    n1 = n / 10
    n2 = n % 10
    return n2 * (10 ** int(math.log10(n))) + n1

def num_circular_prime(n):
    if n < 2:
	return 0
    num = 1
    for i in range(3, n + 1, 2):
	if is_circular_prime(i):
	    num += 1
    return num

print num_circular_prime(1000000)
