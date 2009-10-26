#!/usr/bin/env python
buf={}
def GetPath(x, y):
    if (x, y) not in buf:
        if x > 0 and y > 0:
            buf[(x, y)] = GetPath(x-1, y) + GetPath(x, y-1)
        else:
            buf[(x, y)] = 1
    return buf[(x, y)]
    
print GetPath(20, 20)
