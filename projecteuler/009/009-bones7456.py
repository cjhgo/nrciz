#!/usr/bin/env python
def GenBA():
    for i in range(999,1,-1):
        for j in range(i,1,-1):
            yield i,j
print [a*b*(1000-a-b) for b,a in GenBA() if a*a+b*b==(1000-a-b)*(1000-a-b)][0]
