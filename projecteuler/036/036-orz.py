#!/usr/bin/python

def p36():
    def BinPTest(n):
        s=''
        while n>0:
            if (n&1) == 0:
                s+='0'
            else:
                s+='1'
            n>>=1
        return (s[::-1] == s)
    res = 0
    for x in xrange(1,1000000,2):
        s = str(x)
        if s == s[::-1] and BinPTest(x):
            res += x
    return res

print p36()
