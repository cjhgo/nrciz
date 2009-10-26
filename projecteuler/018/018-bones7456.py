#!/usr/bin/env python

def init(f="triangle.txt"):
    D=[]
    for line in open(f):
        D.append([int(i) for i in line.split()])
    return D
    
D = init()
maxline = len(D)
for i in range(maxline-1,0,-1):
    for j in range(i):
        D[i-1][j] += max(D[i][j], D[i][j+1])
print D[0][0]
