#!/usr/bin/env python
def p9(n):
	for i in range(1,n+1):
		for j in range(i+1,n+1):
			k = n - i - j
			if k < j: break
			if i**2 + j**2 == k**2:
				return i*j*k
				
print p9(1000)
				
