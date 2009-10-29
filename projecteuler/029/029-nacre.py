#!/usr/bin/env python

lp = []

for a in range(2, 101):
    for b in range(2, 101):
	n = b ** a
	if not(n in lp):
	    lp.append(n)

print len(lp)	
