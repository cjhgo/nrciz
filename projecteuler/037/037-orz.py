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
def p37():
    def Check(n):
        s = str(n)
        for i in range(1,len(s)):
            if IsPrime(int(s[i:])) is False or IsPrime(int(s[:-i])) is False:
                return False
        return True
    cc = 0
    res = 0
    l = PrimeSieve(1000000)
    for x in l:
        if x > 10 and Check(x):
            cc+=1
            res+=x
            if cc == 11:
                break
    return res

print p37()
