#!/usr/bin/python

n = 100
print sum(i for i in range(n+1))**2 - sum(i*i for i in range(n+1))
