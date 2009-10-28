#!/usr/bin/env python

def p14 ():	
	d = {1:1}
	def f(n):
		if n in d:
			return d[n]
		else:
			if (n&1)==0:
				t = 1+f(n>>1)
			else:
				t = 1+f(3*n+1)
			d[n] = t
			return t

	for x in xrange(2,1000000):
		if x in d:
			continue
		else:
			f(x)
			continue
		#else:
			k = x
			cc = 0
			flag = True
			while k != 1:
				if (k&1) == 0:
					k>>=1
				else:
					k = (k<<1)+k+1
				cc+=1
				if k in d:
					d[x] = cc + d[k]
					flag = False
					break
			if flag:d[x] = cc
	max_v = 0
	res = -1
	for k,v in d.iteritems():
		if v > max_v:
			max_v = v
			res = k
	return res
print p14()
