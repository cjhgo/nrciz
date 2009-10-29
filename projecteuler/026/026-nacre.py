#!/usr/bin/env python

largestprocessed = 1
largestlength = 0
number = 1
for d in range(2,1000):
    while d % 2 == 0:
	d = d / 2
    while d % 5 ==0:
	d = d / 5
    if d > largestprocessed:
	length = 1
	while 10 ** length % d != 1:
	    length += 1
	if length > largestlength:
	    largestlength = length
	    number = d

print number
