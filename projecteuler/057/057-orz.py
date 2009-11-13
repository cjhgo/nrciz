#!/usr/bin/python

def p57():
    res,a,b = 0,1,2
    for i in range(1000):
        a,b = b,a + (b<<1)
        res += 1 if len(str(a+b)) > len(str(b)) else 0
    return res
print p57()

