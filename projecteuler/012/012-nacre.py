#!/usr/bin/env python

import math

def get_list_factor(n):
    list = []
    power = 0
    while n % 2 == 0:
        n = n / 2
        power += 1
    if power != 0:
        list.append([2, power])
    i = 1
    sqrt_n = int(math.sqrt(n))
    while i <= sqrt_n:
        i += 2
        power = 0
        while n % i == 0:
            n = n / i
            power += 1
        sqrt_n = int(math.sqrt(n))
        if power != 0:
            list.append([i, power])
    if n != 1:
        list.append([n, 1])
    return list

def num_factor(n):
    num = 1
    list = get_list_factor(n)
    for i in xrange(len(list)):
        num = num * (list[i][1] + 1)
    return num

i = 1
while num_factor(i * (i + 1) / 2) < 500 :
    i += 1
print i * (i + 1) / 2
