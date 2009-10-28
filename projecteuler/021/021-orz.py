#!/usr/bin/env python
#import math

def SumOfProperDivisors(n):
	def SumOfDivisors(n):
		sum = 1
		p = 2
		while p*p<=n and n>1:
			if (n%p)==0:
				j = p**2
				n /= p
				while (n%p)==0:
					j*=p
					n/=p
				sum*=(j-1)
				sum/=(p-1)
			if p == 2:
				p=3
			else:
				p+=2
		if n>1 :sum*=(n+1)
		return sum
	return SumOfDivisors(n) - n 

#print ' SumOfProperDivisors -->>', SumOfProperDivisors(72)
def p21 ():	
	N = 10000
	d = {}
	for i in range(1,N):
		d[i] = [1]
	for i in range(2,N):
		j = i+i
		while j < N:				
			d[j].append(i)
			j+=i
		d[i] = sum(d[i])
	d[1] = 1
	#print d[220],d[284]
	s = set()
	res = 0
	for i in range(1,N):
		#if i in s:continue		
		su = d[i]
		if su <= i or su >= N:continue		
		if i == d[su]:
			s.add(i)
			s.add(su)
			res += (i + su)
	return res
			
def p21_2():
	sum = 0
	for x in range(1,10000):
		y = SumOfProperDivisors(x)
		if y > x:
			if x == SumOfProperDivisors(y):
				sum += x+y
	return sum
	
print p21()
#print p21_2()	
