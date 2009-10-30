#!/usr/bin/python

def p34():
    fact = [reduce(lambda x,y:x*y,[j for j in range(1,i+1)],1) for i in range(10)]
    ss = sum(fact)
    res = 0
    for x in range(145,ss/10):
        v = 0
        for c in [ord(c)-ord('0') for c in str(x)]:
            v+=fact[c]
        if v == x:
            res += x
    return res
print p34()



