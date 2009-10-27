#!/usr/bin/python
import math

def max_prime_factor(n):
    while n % 2 == 0:
        n /= 2

    i = 3
    sqrt_n = math.sqrt(n)
    while i < sqrt_n:
        if n % i == 0:
            n /= i
            sqrt_n = math.sqrt(n)
        else:
            i += 2

    return n

print max_prime_factor(600851475143)
