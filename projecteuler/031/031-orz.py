#!/usr/bin/python

def p31():
    coin = (1,2,5,10,20,50,100,200)    
    l = [0]*201
    l[0] = 1
    for c in coin:
        for i in range(c,201):
            l[i] += l[i-c]
    return l[200]

print p31()

