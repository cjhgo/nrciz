#!/usr/bin/env python

def p48():
	return str(sum(i**i for i in xrange(1,1001)))[-10:]
print p48()
