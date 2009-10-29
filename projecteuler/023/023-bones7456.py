#!/usr/bin/env python
from math import sqrt

N = 28123
def d(n):
    '''return sum of proper divisors of n'''
    r=1
    for i in range (2, int(sqrt(n))+1 ):
        if 0 == n % i:
            r += i + n /i
    if sqrt(n) == int(sqrt(n)):
        r -= int(sqrt(n))
    return r
def abundant_numbers(n):
    A=[]
    for i in range(12, n):
        if d(i) > i:
            A.append(i)
    return A
    
a_nums = abundant_numbers( N+1 )

s = [ num1 + num2 
    for num2 in a_nums
    for num1 in a_nums if num2 + num1 < N ]
s = set(s)
print sum(i for i in range(N) if i not in s)

'''r = 0
for num in range(1, N+1):
    for i in a_nums:
        if i > num/2:
            print num,"*"
            r += num
            break
        if num - i in a_nums:
            print num,"-"
            break
print r'''
