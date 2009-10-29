#!/usr/bin/env python

sum = 0
with open('digs', 'r') as f:
    for line in f:
        sum += int(line)
print str(sum)[:10]
