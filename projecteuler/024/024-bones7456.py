#!/usr/bin/env python

def factorial(n):
    r = 1
    for i in range(1, n+1):
        r *= i
    return r

digital, goal, n, x, r = range(10), 1000000, 9, 0, ''
while digital:
    if goal > factorial(n):
        goal -= factorial(n)
        x += 1
    else:
        r += str(digital[x])
        del digital[x]
        x = 0
        n -= 1
print r
