#!/usr/bin/env python

def Permutations(iterable, r=None):
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = range(n)
    cycles = range(n, n-r, -1)
    yield tuple(pool[i] for i in indices[:r])
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield tuple(pool[i] for i in indices[:r])
                break
        else:
            return

def p68():
    l1,l2 = [1,2,3,4,5],[6,7,8,9,10]
    res,rs = 6,''
    for i in Permutations(l2):
        for j in Permutations(l1):
            if len(set([i[k] + j[k] + j[(k+1)%5] for k in range(5)])) == 1:
                t = ''.join([str(i[k])+str(j[k])+str(j[(k+1)%5]) for k in range(5)])
                if len(rs) == 0:
                    res,rs = i[0],t
                elif i[0] == res:
                    if t > rs:rs = t
                elif i[0] < res:
                    res,rs = i[0],t
    return rs
print p68()
