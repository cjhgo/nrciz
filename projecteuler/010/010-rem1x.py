#!/usr/bin/env python

from math import sqrt

def is_prime(n):
    if n % 2 == 0: return False
    for i in range(3, int(sqrt(n)+1), 2):
        if n % i == 0: 
            return False
    return True

def sum_prime(n):
    prime=[2]

    for i in range(3, n+1, 2):
        if is_prime(i):
            prime.append(i)

    print sum(prime)

sum_prime(2000000)        
