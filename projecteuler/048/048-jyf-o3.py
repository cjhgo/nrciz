#!/usr/bin/env python2.6
# File: 048-jyf.py
# Date: 2009-10-30
# Author: jyf
# Comment: This program is for ProjectEuler-048,and it got a level 2 optimization
# LICENSE: do what the fuck you want to do to it!

x = 10**10
total = 0
n_cache = []
cache_tpl = []

for i in range(33):
    cache_tpl.append(0)

import sys
if len(sys.argv) > 1:
    N = int(sys.argv[1])
else:
    N = 1000   

def clear_cache():
    global n_cache
    n_cache = cache_tpl[:]

def mul0(n,m):
    return (n*m)

def mul1(n,m):
    #global total
    #total = total + 1
    global n_cache
    if 0 == m:
        return n
    elif 1 == m:
        return n**2%x
    else:
        if 0 == n_cache[m]:
            n_cache[m] = (mul1(n,m-1)**2)%x
        return n_cache[m]

def sum10(n):
    n_bin = bin(n)[2:]
    #print n_bin
    ct = len(n_bin) -1
    sum = 1
    for bit in n_bin:
        if '1' == bit:
            sum = sum*mul1(n,ct)
        ct = ct -1
    return sum%x


s = 0
for i in range(1,N+1):
    clear_cache()
    s = s + sum10(i)
    s = s%x


print repr(s)
print repr(total)
