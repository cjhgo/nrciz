#!/usr/bin/python

def p55():
    def Check(n):
        r = n
        sr = str(r)[::-1]
        for i in range(50):
            r += int(sr) 
            s = str(r)
            sr = s[::-1]
            if s == sr:return False
        return True
    res = 0
    for x in range(1,10000):
        if Check(x):res+=1
    return res

print p55()

