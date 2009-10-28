#!/usr/bin/env python

def p22():
	f = open('names.txt','r')
	l = map(lambda s:s.strip('"'),f.readlines()[0].split(','))
	l.sort()
	su = 0
	for i,v in enumerate(l):
		su += sum(ord(s)-ord('A')+1 for s in v) * (i+1)
	return su
	
print p22()
