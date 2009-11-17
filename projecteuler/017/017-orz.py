#!/usr/bin/env python

def p17():
    def gl(n):
        l = ([0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8],[6, 6, 5, 5, 5, 7, 6, 6, 7])
        if n == 1000:return 11
        elif n%100 == 0:return l[0][n/100]+7
        elif n > 100:return l[0][n/100]+10+gl(n%100)
        elif n < 20:return l[0][n]
        else: return l[1][n/10-2]+l[0][n%10]
    return sum(gl(i) for i in range(1,1001))

print p17()
