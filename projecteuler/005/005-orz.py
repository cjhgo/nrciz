#!/usr/bin/env python
import math
def p5():
	l = [2,3,5,7,11,13,17,19]
	ca = [0]*21
	for i in range(1,21):
		for j in l:
			ca[j] = max(ca[i],int(math.floor(math.log(i)/math.log(j))))
	res =1
	for i,v in enumerate(ca):
		res*=i**v
	return res

print p5()
