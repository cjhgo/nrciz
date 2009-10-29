#!/usr/bin/env python

from math import sqrt

def is_prime(n):
    if n <= 1:
        return 0
    elif n == 2:
        return 1
    
    if n % 2 == 0:
        return 0
    for i in xrange(3, int(sqrt(n)) + 1, 2):
        if n % i == 0:
            return 0
    else:
        return 1

def num_consecutive_prime(a, b):
    n = 0
    while 1: 
	if not(is_prime(n * n + a * n + b)):
	    return n
	n +=1

max_num = 0
for a in range(-1000, 1001):
    for b in range(-1000, 1001):
        num = num_consecutive_prime(a, b)
        if num > max_num:
    	    max_num = num
    	    product = a * b
print product
