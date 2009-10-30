#!/usr/bin/python
def p38():
    res = 0
    for i in xrange(9999,0,-1):
        s = ''
        for j in range(1,10):
            s+=str(i*j)
            if len(s) > 9:break
            if len(s) == 9 and '0' not in s and len(set(s)) == 9:
                res = max(res, int(s))
    return res
print p38()
