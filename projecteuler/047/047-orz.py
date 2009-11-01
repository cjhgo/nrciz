#!/usr/bin/python
def p47():
    N = 200000#evil
    l = [0]*N
    size = 4
    for i in xrange(2,N):
        if i > 1004 and l[i] == size:
            f = True
            for o in range(1,4):
                if size != l[i-o]:
                    f = False
                    break
            if f:return i-size+1
        if l[i] == 0:
            j = i+i
            while j<N:
                l[j]+=1
                j+=i
print p47()
