#!/usr/bin/env python

def palindromic():
	max_v = 0
	for i in xrange(1000, 100, -1):
		for j in xrange(1000, i, -1):
			s = str(i*j)
			if s == s[::-1]:
				if max_v < i*j: max_v = i*j
	return max_v

print palindromic()
