#!/usr/bin/env python

num = 0
s = set('123456789')
for n in range(1, 9999):
    digits = str(n)
    i = 2
    while len(digits) < 9:
        digits = digits + str(i * n)
        n += 1
    if len(digits) == 9 and set(digits) == s:
        num = max(num, int(digits))
print num
