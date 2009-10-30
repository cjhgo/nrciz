#!/usr/bin/python
def p40():
    l = [0] + [i*(10**i-10**(i-1)) for i in range(1,10)]
    def DD(n):
        if n < 10: return n
        d = 0
        for i in range(10):
            if n > l[i]:
                n-=l[i]
            else:
                 d = i
                 break
        i = n/d
        if n%d == 0:i-=1
        return int(str(10**(d-1)+i)[n%d-1])
    return reduce(lambda x,y:x*y,[DD(10**i) for i in range(7)])

print p40()
