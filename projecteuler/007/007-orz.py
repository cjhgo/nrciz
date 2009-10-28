#!/usr/bin/env python
import math

def p7(n):
	l = [2]
	c = 3
	while len(l) < n:
		f = True
		m = int(math.sqrt(c)+1)
		for j in l:
			if j > m: 
				break
			if (c%j) == 0:
				f = False
				break
		if f:
			l.append(c)
		c+=2
	return l[-1]
	
print p7(10001)
