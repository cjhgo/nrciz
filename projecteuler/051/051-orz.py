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
def p51():
    l = PrimeSieve(1000000)
    ls,le = set(l),len(l)
    def GBP(n):
        ll,p = [],0
        while n>0:
            if (n&1)==1:ll.append(p)
            n >>= 1
            p+=1
        return ll
    def Check(n):
        sli = list(str(n))
        sl = len(sli)
        for i in xrange(3,(1<<sl)):
            pl = GBP(i)
            b,cc = 1 if (sl-1) in l else 0,0
            for j in range(b,10):
                slit = sli[:]
                for index in pl:
                    slit[sl-1-index] = str(j)
                st = reduce(lambda x,y:x+y,slit,'')
                if int(st) in ls:
                    cc+=1
                if cc + 10-j < 8:break
            if cc == 8:
                return True
        return False

    for i in xrange(l.index(120383)+1,le):
        if Check(l[i]):
            return l[i]
    return -1
    i = l[-1] + 2
    while True:
        if IsPrime(i) and Chedk(i):
            return n
        i+=2

print p51()
