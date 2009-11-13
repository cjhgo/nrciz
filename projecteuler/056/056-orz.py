#!/usr/bin/python

def p56():
    res = 0
    for a in range(1,100):
        for b in range(1,100):
            r = sum(int(c) for c in str(a**b))
            res = r if r > res else res
    return res
print p56()
