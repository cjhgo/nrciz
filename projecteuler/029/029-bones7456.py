#!/usr/bin/env python
A={}
for a in range(2, 101):
    for b in range(2, 101):
        A[a**b] = 1
print len(A)
#print len(set(a**b for a in xrange(2, 101) for b in xrange(2, 101)))
