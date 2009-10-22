#!/usr/bin/env python

buf={1:1}
def GetCollatzLen(n):
    if n not in buf:
        if n % 2 == 0:
            buf[n]=GetCollatzLen(n/2)+1
        else:
            buf[n]=GetCollatzLen(3*n+1)+1
    return buf[n]
        
def GetMaxCollatz(N):
    maxlen, maxhead = 1, 1
    for i in range(1, N):
        if maxlen < GetCollatzLen(i):
            maxlen = GetCollatzLen(i)
            maxhead = i
    return maxhead
    
print GetMaxCollatz(1000000)
