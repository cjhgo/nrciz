#!/usr/bin/env python

from math import sqrt

def output(n):
    x=1
    prime=[2]
    while len(prime) < n:
        x += 2
        tag = True
        mid = int(sqrt(x)+1)
        for i in prime:
            if i < mid:
                if x % i == 0:
                    tag = False
                    break
            else:
                break
        if tag == True:
            prime.append(x)

    print prime[-1]
    
output(10001)
