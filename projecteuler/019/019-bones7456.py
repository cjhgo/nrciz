#!/usr/bin/env python

def isLeap(n):
    if 0 == n % 400:
        return True
    elif 0 == n % 100:
        return False
    elif 0 == n % 4:
        return True
    else:
        return False
def year_mouth_days(n):
    if isLeap(n):
        return [31,29,31,30,31,30,31,31,30,31,30,31]
    else:
        return [31,28,31,30,31,30,31,31,30,31,30,31]

f, r = 1, 0
for year in range(1900, 2001):
    for mouth in range(12):
        if 0 == f % 7 and year > 1900:
            r += 1
        f += year_mouth_days(year)[mouth]
print r
