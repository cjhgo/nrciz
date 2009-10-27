#!/usr/bin/python

def num_solution(n):
    from itertools import permutations
    num = 0
    # p[i] = j means that the queen is on i-th row, j-th column
    for p in permutations(range(n)):
        if is_solution(p):
            num += 1
    return num

def is_solution(p):
    n = len(p)
    for i in range(n-1):
        for j in range(i+1, n):
            if abs(p[i]-p[j]) == j-i:
                return 0
    return 1

print num_solution(8)
