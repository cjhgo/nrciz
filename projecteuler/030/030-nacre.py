#!/usr/bin/env python

si = 0
for i in range(2, 360000):
    sum_fifth_power = sum(int(ch) ** 5 for ch in str(i))
    if sum_fifth_power == i:
        #print i
	si += i

print si
