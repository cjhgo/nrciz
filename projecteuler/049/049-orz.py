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

def p49():
    def Check(a,b):
        return (set(str(a)) == set(str(b)))
    l = [i for i in range(1487+1,9999) if IsPrime(i)]
    for i,v in enumerate(l):
        for j in range(i+1,len(l)):
            if Check(v,l[j]):
                c = l[j]*2-v
                if c in l and Check(c,v):
                    return str(v)+str(l[j])+str(c)
print p49()