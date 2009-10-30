#!/usr/bin/env python

def to_base2(n):
    if n == 0:
	return '0'
    s = ''
    while n != 0:
	s = str(n % 2) + s
	n = n / 2
    return s

def is_palindromic(s):
    if s[::-1] == s:
	return 1
    return 0

def sum_palindromic(ubound):
    sum = 0
    for i in range(1, ubound + 1):
	if is_palindromic(str(i)) and is_palindromic(to_base2(i)):
	    sum += i
    return sum

print sum_palindromic(1000000)
