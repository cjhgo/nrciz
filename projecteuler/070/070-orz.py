#!/usr/bin/env python
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

def p70():
    N = 10000000
    l,d = PrimeSieve(N+1),{}
    for p in l:d[p] = p-1
    def Cal(n):
        if n in d:return d[n]
        for p in l:
            if n%p == 0:
                nt = n/p
                d[n] = Cal(nt)*(p if nt%p == 0 else p-1)
                return d[n]
    rt,res = N,2
    for i in xrange(1000000,N):
        if i in d:continue
        t = Cal(i)
        if sorted(str(t)) == sorted(str(i)):
            t = i*1.0/t
            if rt > t:
                rt,res = t,i
    return res
print p70()
