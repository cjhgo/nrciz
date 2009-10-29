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
def p27():
    max_v = 0
    ab = 0
    lb = [ i for i in range(2,1000) if IsPrime(i)]
    for a in range(-999,1000):
        for b in lb:
            cc = 0
            n = 0
            while True:
                t = n*(n+a)+b
                if t > 0 and IsPrime(t):
                    cc+=1
                else:
                    break
                n+=1
            if max_v < cc:
                max_v = cc
                ab = a*b
    return ab


print p27()
