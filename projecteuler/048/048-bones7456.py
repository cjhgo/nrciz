#!/usr/bin/env python

a=10**10
print str(sum(pow(i,i,a) for i in range(1,1001)))[-10:]
