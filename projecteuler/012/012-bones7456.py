#!/usr/bin/env python
from math import sqrt
n=5
def divisors(N):
	a=0
	for i in range(2,int(sqrt(N))):
		if N%i==0:
			a+=1
	a=a*2+1
	if int(sqrt(N))==sqrt(N):
		a+=1
	return a
#divisors(28)
while True:
	n+=1
	N=(1+n)*n/2
	if divisors(N)>=500:
		print N
		break
