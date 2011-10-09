#!/usr/bin/env python

print len(set(float(a)/b for b in range(5,12001) for a in range(2,b) if float(a)/b > float(1)/3 and float(a)/b < float(1)/2))
