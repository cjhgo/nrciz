#!/usr/bin/python
import math
def p64():
    def CountOfContinuedFractions(n):
        x = int(math.floor(math.sqrt(n)))
        l,a,b,res = [x],1,x,1
        while b*b < n:
            r = (x+b)*a/(n-b*b)
            a = (n-b*b)/a 
            b = r*a-b
            res += 1
            #l.append(r)
            if a == 1 and b == x:
                break
        return res - 1 #,l 
    res = 0
    for i in xrange(2,10001):
        if (CountOfContinuedFractions(i)&1) == 1:
            res += 1
    return res
print p64()
