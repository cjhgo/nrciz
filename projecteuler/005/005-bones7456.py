#!/usr/bin/env python
N=20

from math import sqrt
def IsPrime(n):
    for i in range(2,int(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True
p=[n for n in range(2,N+1) if IsPrime(n)]
A={}
for x in p:
    A[x]=0
for i in range(2,N+1):
    n = i
    a={}
    for x in p:
        a[x]=0
    for t in p:
        while n % t == 0:
            a[t] += 1
            n /= t
    for x in p:
        A[x]=max(A[x],a[x])
R = 1
for x in p:
    R *= x**A[x]
print R
        



'''def isnot(n):
    for i in range(2,21):
        if n % i != 0:
            return True
    return False
n = 1;
while isnot(n):
    n += 1

print n
'''
'''
#!/usr/bin/env python

def delbart(t,n):
    if n > 0:
        if not (t%n):
            if delbart(t, n-1):
                return True
            else:
                return False
        else:
            return False
    else:
        return True

i = 20
while not delbart(i,20):
    i += 20

print i 
'''
