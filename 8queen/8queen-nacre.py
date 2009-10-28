#!/usr/bin/python

def get_solution(n):
    from itertools import permutations
    vp, up = [], []
    pass_count = 0
    # p[i] = j means that the queen is on i-th column, j-th row
    for p in permutations(range(n)):
        if pass_count:
            pass_count -= 1
            pass
        else:
            flag, pass_count = is_solution(p)
            if flag:
                vp.append(list(p))
    cp = vp[:]
    while len(cp) != 0:
        p = cp[0]
        up.append(p)
        for mp in (p, t(p), t(t(p)), t(t(t(p))), r(p), t(r(p)), t(t(r(p))), t(t(t(r(p))))):
            try:
                cp.remove(mp)
            except ValueError:
                pass
    return vp, up

def is_solution(p):
    from math import factorial
    n = len(p)
    for i in range(1, n):
        for j in range(i):
            if abs(p[i] - p[j]) == i - j:
                return 0, factorial(n - 1 - i) - 1
    return 1, 0

# transpose
def t(p):
    n = len(p)
    tp = [0] * n
    for i in range(n):
        tp[p[i]] = n - i - 1
    return tp

# reflect
def r(p):
    n = len(p)
    rp = [0] * n
    for i in range(n):
        rp[p[i]] = i
    return rp

n = 8
vp, up = get_solution(n)
print n, "queens problem"
print "number of valid solutions ", len(vp)
print "number of unique solutions", len(up)
