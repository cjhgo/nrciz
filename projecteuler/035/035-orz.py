#!/usr/bin/python
import math
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
def PrimeSieve(n):
    lf = [0]*n
    res = []
    for i in xrange(2,n):
        if lf[i] == 0:
            res.append(i)
            j = i+i
            while j<n:
                lf[j] = 1
                j+=i
    return res

def p35():
    N = 1000000
    l = PrimeSieve(N)
    cc = 0
    for x in l:
        s = str(x)
        le = len(s)-1
        if le < 1:
            cc+=1
            continue
        s+=s
        f = True
        for i in range(le):
            if IsPrime(int(s[i+1:i+2+le])) is False:
                f = False
                break
        if f:
            cc+=1
    return cc

print p35()



