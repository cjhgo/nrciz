#!/usr/bin/python

def p29():
    s = set()
    for a in range(2,101):
        for b in range(2,101):
            s.add(a**b)
    return len(s)
print p29()
