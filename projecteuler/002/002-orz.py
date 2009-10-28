#!/usr/bin/python
def p2():
	a = 1
	b = 2
	sum = 0
	while b < 4000000:
		if (b&1) == 0:
			sum += b
		a += b
		a,b = b,a
	return sum
	
print p2()
