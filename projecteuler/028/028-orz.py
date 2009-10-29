#!/usr/bin/python

def p28():
    N = 1001+1
    sum = 1
    t = 1
    for n in range(3,N,2):
        sum+=(t<<2)+(n-1)*10
        t+=4*(n-1)
    return sum

print p28()
