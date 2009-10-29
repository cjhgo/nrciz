#!/usr/bin/env python

def SumOfProperDivisors(n):
    def SumOfDivisors(n):
        sum = 1
        p = 2
        while p*p<=n and n>1:
            if (n%p)==0:
                j = p**2
                n /= p
                while (n%p)==0:
                    j*=p
                    n/=p
                sum*=(j-1)
                sum/=(p-1)
            if p == 2:
                p=3
            else:
                p+=2
        if n>1 :sum*=(n+1)
        return sum
    return SumOfDivisors(n) - n
    
def p23():
    magic_num = 28123 + 1
    la = [i for i in range(magic_num) if SumOfProperDivisors(i) > i]
    la.remove(0)
    res = magic_num*(magic_num-1)/2
    lf = [0] * magic_num
    le = len(la)
    for i in range(le):
        for j in range(i,le):
            t = la[i] + la[j]
            if t < magic_num:
                lf[t] = 1
            else: break
    return res - sum(i for i,v in enumerate(lf) if v == 1)

print p23()
