#!/usr/bin/python

def p25():
    a = 1
    b = 2
    cc = 4
    while True:
        a += b
        if len(str(a)) >= 1000:
            return cc
        a,b = b,a
        cc+=1

print p25()

