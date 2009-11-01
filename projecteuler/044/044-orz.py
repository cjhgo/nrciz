#!/usr/bin/python
import math
def p44():
    def Check(n):
        fl = int(math.floor(math.sqrt(n*6)))
        return  (fl%3 == 2) and (fl*(fl+1) == 6*n)
    i,j = 1,2
    while True:
        i = 1
        while i < j:
            u,v = (i*((i<<1)+i-1)>>1),(j*((j<<1)+j-1)>>1)
            if Check(u+v) and Check(v-u):
                return v-u
            i+=1
        j+=1

print p44()