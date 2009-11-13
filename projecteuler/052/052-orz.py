#!/usr/bin/python

def p52():
    def Check(n):
        s = set(str(n))
        for i in range(2,7):
            if s != set(str(n*i)):
                return False
        return True

    x = 125875
    while True:
        if Check(x):
            return x
        x+=1
print p52()

