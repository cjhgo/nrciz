#!/usr/bin/env python

num_lines = 1001

sum = 1
for i in range(2, (num_lines + 3) / 2) :
    sum += 3 + 3 * (2 * i - 2) * (2 * i - 2) + (2 * i - 1) * (2 * i - 1)

print sum
