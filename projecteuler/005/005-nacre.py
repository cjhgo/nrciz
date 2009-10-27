#!/usr/bin/python

def gcd(m, n):
    if m < n:
	m, n = n, m
    while m % n != 0:
	m, n = n, m % n
    return n

def lcm(m, n):
    return m * n / gcd(m, n)

print reduce(lcm, range(1, 21))
