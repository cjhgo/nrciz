#!/usr/bin/python
def p33():
    def GCD(a,b):
        if b==0:return a
        return GCD(b,a%b)
    def tf(i,j,u,v,x,y):
        return (j*10+v > i*10+u) and (x*(j*10+v) == y*(i*10+u))
    x,y = 1,1
    for i in range(1,10):
        for j in range(i,10):
            for u in range(1,10):
                for v in range(1,10):
                    if u == j and tf(i,j,u,v,i,v):
                        x,y = i*x,v*y
                    elif v == i and tf(i,j,u,v,u,j):
                        x,y = x*u,y*j
                    elif u == v and tf(i,j,u,v,i,j):
                        x,y = x*i,y*j
    return y/GCD(x,y)


print p33()
