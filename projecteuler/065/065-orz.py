#!/usr/bin/python
def p65():
    l = [2] + reduce(lambda x,y:x+y,[[1,i+i,1] for i in range(1,34)],[])
    N = 99
    a,b = 1,l[N]
    for i in range(N-1,0,-1):
        a,b = b,l[i]*b+a
    return sum(int(c) for c in str(b*2+a))

print p65()
