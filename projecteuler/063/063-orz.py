#!/usr/bin/python
def p63():
    res = 0
    for i in range(1,10):
        for j in range(1,100):
            k = len(str(i**j))
            if j == k:
                res +=1
            elif k > j:break
    return res
print p63()
