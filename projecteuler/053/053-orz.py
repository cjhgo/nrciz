#!/usr/bin/python

def p53():
    res = 0
    N = 1000000
    fact = {0:1}
    fx = 1
    for n in range(1,101):
        fx*=n
        fact[n] = fx
        for r in range(1,n+1):
            t = fx/(fact[r]*fact[n-r])
            if t > N:
                res+=1
    return res

print p53()

