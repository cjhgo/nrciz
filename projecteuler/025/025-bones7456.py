#!/usr/bin/env python
def Fibonacci_N(N):
    '''return the first Fibonacci item contain N digitals'''
    a,b,n = 1,2,2
    while True:
        if len(str(a)) >= N:
            return n
            break;
        a,b,n = b,a+b,n+1

print Fibonacci_N(1000)
