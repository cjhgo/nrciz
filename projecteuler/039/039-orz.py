#!/usr/bin/python
import math
def GCD(a,b):
    if b==0:return a
    return GCD(b,a%b)
def p39():
    def sol(s):
        cc = set()
        s2 = s/2
        mlimit = int(math.ceil(math.sqrt(s2)))
        for m in range(2,mlimit):
            if s2%m == 0:
                sm = s2/m
                while (sm&1) ==0:
                    sm>>=1
                if (m&1)==1:
                    k = m+2
                else:
                    k = m+1
                while k < (m<<1) and k <= sm:
                    if (sm%k)==0 and GCD(k,m)==1:
                        d = s2/(k*m)
                        n = k-m
                        a = d*(m*m-n*n)
                        b = 2*d*m*n
                        c = d*(m*m+n*n)
                        if a>b:a,b=b,a
                        if abs(a-b) < c and abs(a-c)<b and abs(b-c) < a and a+b>c and a+c >b and b+c>a:
                            cc.add((a,b,c))
                    k+=2
        return len(cc)

    l = [sol(i) for i in range(1001)]
    return l.index(max(l))

print p39()
