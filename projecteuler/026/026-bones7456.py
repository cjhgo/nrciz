#!/usr/bin/env python

def GetCycleLen(n):
    buf ,i = [], 0
    while True:
        x, i = 10 ** i % n, i+1
        if 0 == x:
            return 0
        if x in buf:
            return len(buf) - buf.index(x)
        buf.append(x)
        
print max(range(1, 1001), key=GetCycleLen)

