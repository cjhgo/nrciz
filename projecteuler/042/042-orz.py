#!/usr/bin/python
import math
def p42():
    res = 0
    for w in [w.strip('"') for w in open('words.txt','r').readlines()[0].split(',')]:
        ct = 0
        for c in w:
            ct+=ord(c)-ord('A')+1
        ct<<=1
        q = int(math.floor(math.sqrt(ct)))
        if q*(q+1) == ct:
            res+=1
    return res

print p42()