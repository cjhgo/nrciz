#!/usr/bin/env python
def p4():
	max_v = 0
	for i in xrange(100,1000):
		for j in xrange(i,1000):
			s = str(i*j)
			if s == s[::-1]:
				if max_v < i*j: max_v = i*j
	return max_v
print p4()
