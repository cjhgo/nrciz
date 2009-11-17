#!/usr/bin/python
import math
"""
more detail in
http://www.ams.org/notices/200202/fea-lenstra.pdf
http://mathworld.wolfram.com/PellEquation.html
"""
def p66():
    def ContinuedFractions(n,term = -1):
        x = int(math.floor(math.sqrt(n)))
        l,a,b,term = [x],1,x,term+term
        while b*b < n:
            r = (x+b)*a/(n-b*b)
            a = (n-b*b)/a 
            b = r*a-b
            l.append(r)
            if term > 0:
                if r == term:
                    l.pop()
                    break
            elif b == x:
                break
        return l 
    def Cal(d,l):
        a,b = 1,l[-1]
        for i in range(len(l)-2,-1,-1):
            a,b = b,l[i]*b+a
        return a,b,b*b-d*a*a
    res,rd = 2,2
    for i in range(2,1001):
        l = ContinuedFractions(i)
        a,b,t = Cal(i,l)
        if t == 0:continue
        elif t == 1:pass
        elif t != -1:
            l = ContinuedFractions(i,l[0])
            a,b,t = Cal(i,l)
        if t == -1:
            b,a = b*b+a*a*i,2*b*a
        if b > res:
            res,rd = b,i
    return rd

print p66()
