#!/usr/bin/env python
def p12():
	def	CountOfDivisors(n):
		s = 1
		p = 2
		while p**2 <= n and n > 1:
			cc = 0
			if (n%p)==0:
				cc+=1
				n/=p
				while (n%p)==0:
					cc+=1
					n/=p
			if p == 2:p=3
			else: p+=2
			s*=(cc+1)
		if n > 1:s*=2
		return s
	#print CountOfDivisors(28)
	i = 8
	while True:
		n = (((1+i)*i)>>1)
		if CountOfDivisors(n) > 500:
			return n
		i+=1
print p12()
