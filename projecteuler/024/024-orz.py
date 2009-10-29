#!/usr/bin/python

def p24():
    def Factorial(n):
        return reduce(lambda x,y:x*y,[i for i in range(1,n+1)],1)
    N = 10 
    M = 1000000
    fact = [Factorial(i) for i in range(N)]
    l = [i for i in range(N)]
    k = M - 1
    ll = []
    for i in range(N):
        if fact[N-1-i] > k:
            ll.append(l[i])
        else:
            break
    l = [ x for x in l if x not in ll]
    while k > 0:
        if fact[len(l)-1] <= k:
            t = k/fact[len(l)-1]
            ll.append(l[t])
            k%=fact[len(l)-1];
        else:
            ll.append(l[0])
        l = [ x for x in l if x not in ll]
    ll += l
    #print ll
    return reduce(lambda x,y:x*10+y,ll,0)

print p24()
