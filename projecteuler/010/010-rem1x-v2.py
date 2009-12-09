#!/usr/bin/env python
#coding:utf-8
#筛选法的效率比除余法要高

from math import sqrt

N=2000000
list=range(N+1)
list[1]=0

for i in xrange(2,int(sqrt(N)+1)):
    if list[i]:
        for j in xrange(i+i,N,i):
            list[j] = 0

print sum(list)
