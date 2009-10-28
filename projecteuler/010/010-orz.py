#!/usr/bin/env python
import math
def IsPrime(n):
	if n == 1:return False
	elif n < 4: return True
	elif (n&1) == 0: return False
	elif n < 9 : return True
	elif (n%3) == 0: return False
	else:
		r = int(math.floor(math.sqrt(n)))
		f = 5
		while f <= r:
			if (n%f)==0:return False
			if (n%(f+2)) == 0:return False
			f+=6
	return True
def p10():
	sum = 2+3
	f =	5 
	while f < 2000000:
		if IsPrime(f):
			sum += f
		f+=2
		if IsPrime(f):
			sum += f
		f+=4
	return sum
	
print p10()
