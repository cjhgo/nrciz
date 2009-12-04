#!/usr/bin/env python

def output(n):
    print ((1+n)*n/2)**2 - sum(i*i for i in range(1, n+1))

output(100)
