#!/usr/bin/env python

from math import sqrt

def is_prime(num):
    for i in range(2, int(sqrt(num)+1)):
        if num % i == 0:
            return False
    return True

def factors():
    N = 600851475143
    num = int(sqrt(N)+1)
    while num >= 2:
        if (N%num) != 0: 
            num -= 2
            continue
        if is_prime(num):
            break
        num -= 2

    return num

print factors()

