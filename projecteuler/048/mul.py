#!/usr/bin/python2.6
# -*- coding: utf-8 -*-
# File: mul.py
# Date: 2009-10-30
# Author: jyf
# Comment: a test for n**n

total = 0
n_cache = []

def mul0(n,m):
    #print "%d * %d = %d " % (n,m,m*n)
    return (n*m)

def mul1(n,m):
    #print m
    global total
    total = total + 1
    if 0 == m:
        return n
    elif 1 == m:
        return mul0(n,n)
    else:
        return mul1(n,m-1)**2


def main(n,total):
    n_bin = bin(n)[2:]
    #print n_bin
    ct = len(n_bin) -1
    sum = 1
    for bit in n_bin:
        if '1' == bit:
            sum = sum*mul1(n,ct)
        ct = ct -1

    return repr(sum)[-11:]

n = 999

print repr(main(n,total))
print repr(total)
print repr(n**n)[-11:]
