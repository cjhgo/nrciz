#!/usr/bin/python
import math
import itertools
def IsPrime(n):
    if n == 1:return False
    elif n < 4: return True
    elif (n&1) == 0: return False
    elif n < 9 : return True
    elif (n%3) == 0: return False
    else:
        r = int(math.floor(math.sqrt(n)))
        f = 5
        while f <= r:
            if (n%f)==0:return False
            if (n%(f+2)) == 0:return False
            f+=6
    return True

def p41():    
    l = '987654321'
    for i in range(7,0,-1):# no 8/9-digit
        for j in itertools.permutations(l[9-i:]):
            s = reduce(lambda x,y:x+y,j,'')
            if IsPrime(int(s)):
                return s
print p41()
