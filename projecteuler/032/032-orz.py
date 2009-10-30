#!/usr/bin/python
import math
def p32():
    sum = 0
    for x in range(1234,9876):
        ce = int(math.ceil(math.sqrt(x)))
        for i in range(2,ce):
            if x %i ==0:
                st = str(x)+str(i)+str(x/i)
                s = set(st)
                if len(st) == 9 and ('0' not in s) and len(s) == 9:
                    sum += x
                    break
    return sum
print p32()


