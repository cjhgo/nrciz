#!/usr/bin/env python

def p18():
	f = open('triangle.txt','r')
	d = [] 
	for l in f.readlines(): 
		d.append(map(lambda c:int(c), [c for c in l.strip().split(' ')]) )
	ld = len(d)
	for i in range(ld-1,0,-1):
		for j in range(i):
			d[i-1][j] = max(d[i][j]+d[i-1][j],d[i][j+1]+d[i-1][j])
	return d[0][0]
	
print p18()
