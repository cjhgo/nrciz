#!/usr/bin/env python2.5
# File: 048-jyf.py
# Date: 2009-10-29
# Author: jyf
# Comment: This program is for ProjectEuler-048
# LICENSE: do what the fuck you want to do to it!

x = 10**10

def sum10(n):
    
    sum = 1
    for i in range(1,n+1):
        sum = sum * n
        sum = sum%x
    #print sum
    return sum

s = 0
for i in range(1,10001):
    s = s + sum10(i)
    s = s%x

print repr(s)

