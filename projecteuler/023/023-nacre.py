#!/usr/bin/env python

from math import sqrt

def sum_divisor(n) :
    sum = 1 # 1 is always a proper divisor
    sqrt_n = int(sqrt(n))
    for i in range(2, sqrt_n + 1) :
	if n % i == 0 :
	    sum = sum + i + n / i
    if sqrt_n * sqrt_n == n :
	sum -= sqrt_n
    return sum

def is_abundant(n) :
    if n < 12 :
	return 0
    if sum_divisor(n) > n :
	return 1
    else :
	return 0

def is_sum_2a(n, list_abundants) :
    if n < 24 :
	return 0
    for i in range(12, n / 2 + 1) :
	if list_abundants[i] and list_abundants[n - i] :
	    return 1
    return 0

def get_list_a(n) :
    list = [0] * (n + 1)
    for i in range(1, n + 1) :
	if is_abundant(i) :
	    list[i] = 1
    return list

def sum_not_sum_2a(limit) :
    sum = 0
    abundants = get_list_a(limit)
    for i in range(1, limit + 1) :
	if not is_sum_2a(i, abundants) :
	    sum += i
    return sum

print sum_not_sum_2a(28123)
