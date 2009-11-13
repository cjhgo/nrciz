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
def IsPrime(n):
    if n == 1:return False
    elif n < 4: return True
    elif (n&1) == 0: return False
    elif n < 9 : return True
    elif (n%3) == 0: return False
    else:
        r = int(math.floor(math.sqrt(n)))
        f = 5
        while f <= r:
            if (n%f)==0:return False
            if (n%(f+2)) == 0:return False
            f+=6
    return True    
    
def p60():
    d,l = {},PrimeSieve(10000)
    for p in l:d[p] = set()
    for i,v in enumerate(l):
        for j in xrange(0,i):
            if IsPrime(int("%s%s"%(l[j],v))) and IsPrime(int("%s%s"%(v,l[j]))):
                d[l[j]].add(v)
                d[v].add(l[j])
    resl = []
    def R(kk,vv,resl):
        if len(kk) == 5:
            resl.append(kk)
            return
        for v in vv:
            if all(v > it for it in kk) and kk.issubset(d[v]):
                k = kk|set([v])
                R(k,vv&d[v],resl)
    for k,v in d.iteritems():
        R(set([k]),v,resl)
    return min(sum(rl) for rl in resl)
    
print p60()

