#!/usr/bin/python
def p62():
    x,d = 2,{}
    while True:
        y = ''.join(sorted(str(x*x*x)))
        c = d.get(y,[])
        c.append(x)
        if len(c) >= 5:
            return min(c)**3
        d[y] = c
        x+=1

print p62()

