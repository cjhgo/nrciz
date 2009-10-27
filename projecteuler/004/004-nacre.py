#!/usr/bin/env python

maxnum = 0
for i in range(990, 99, -11):
    for j in range(999, i, -1):
	num = i * j
    	if num <= maxnum:
	    break
	else:
	    strnum = str(num)
	    if strnum == strnum[::-1]:
		maxnum = num
		break
print maxnum
