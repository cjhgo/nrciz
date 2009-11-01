#!/usr/bin/python
import math
def PrimeSieve(n):
    if n < 2:return []
    sb = ((n-1)>>1)+1
    l = [0]*sb
    cn = (int(math.floor(math.sqrt(n))-1)>>1)
    for i in xrange(1,cn+1):
        if l[i] == 0:
            for j in xrange(2*i*(i+1),sb,2*i+1):
                l[j] = 1
    res = [2]
    for i in xrange(1,sb):
        if l[i] == 0:
            res.append(2*i+1)
    return res
def p46():
    ls = set(PrimeSieve(10000))
    x = 9
    while True:
        while x in ls:
            x+=2
        fl = int(math.floor(math.sqrt(x/2)))+1
        f = True
        for i in range(1,fl):
            if (x-2*i*i) in ls:
                f = False
                break
        if f:return x
        x+=2 

print p46()