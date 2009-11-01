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
def p50():
    N = 1000000
    l = PrimeSieve(N)
    le = len(l)
    ls = set(l)
    max_v = 1
    res = 0
    for i in xrange(le):
        j = i+1
        ln = 1
        cc = l[i]
        while j < le:
            cc+=l[j]
            ln += 1
            if cc >= N:break
            if cc in ls:
                if max_v < ln:
                    max_v = ln
                    res = cc
            j+=1
    return res

print p50()