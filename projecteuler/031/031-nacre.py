#!/usr/bin/env python

def num_change(money, types_coin):
    list = [1, 2, 5, 10, 20, 50, 100, 200]
    if types_coin == 1:
	return 1
    else:
	sum = 0
	for i in range(money / list[types_coin - 1] + 1):
	    sum = sum + num_change(money - i * list[types_coin - 1], types_coin - 1)
	return sum

print num_change(200, 8)
