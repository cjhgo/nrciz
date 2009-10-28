#!/usr/bin/python
import math
def isp(n):
	if (n&1) == 0:return False
	for i in range(3,int(math.sqrt(n)+1),2):
		if (n%i) == 0:return False
	return True
def p3():
	N = 600851475143
	sq = int(math.sqrt(N)+1)
	while sq > 2:
		if (N%sq)!=0:
			sq-=2
			continue
		if isp(sq):
			break;
		sq-=2
	return sq
	
print p3()
