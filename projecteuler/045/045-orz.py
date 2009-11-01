#!/usr/bin/python
import math
def p45():
    i = 166
    while True:
        t = i*(3*i-1)
        fl = int(math.floor(math.sqrt(t)))
        if (fl&1) == 1 and fl*(fl+1) == t:
            return ((fl*(fl+1))>>1)
        i+=1

print p45()