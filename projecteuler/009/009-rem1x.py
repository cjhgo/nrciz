#!/usr/bin/env python
# a+b+c   = 1000
# a*a+b*b = c*c
# c>a, c>b
def gg (n):
    for a in range(1,n+1):
        for b in range(a+1,n+1):
            c = n - a - b
            if  c < b: 
                break
            if a*a + b*b == c*c:
                print a*b*c

gg(1000)
