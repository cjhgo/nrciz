#!/usr/bin/env python
def Two3d():
    for i in range(999,99,-1):
        for j in range(i,99,-1):
            yield i,j

p=[]
for a,b in Two3d():
    s = str(a * b)
    if s == s[::-1]:
        p.append(a * b)
print max(p)
