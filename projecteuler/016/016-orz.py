#!/usr/bin/env python

def p16():
	return sum(int(s) for s in str(2**1000))
	
print p16()
