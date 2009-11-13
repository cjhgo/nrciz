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
def p58():
    a,sl,pc,dpc = 1,1,0,1
    while True:
        sl,dpc = sl+2,dpc+4
        for i in range(4):
            a+=sl-1
            if IsPrime(a):pc+=1
        if pc*10 < dpc:break
    return sl
print p58()

