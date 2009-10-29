#!/usr/bin/env python

import string


with open('names.txt', 'r') as f:
    lname = f.read().split(',')

lname.sort()
score = 0
order = 0
for name in lname:
    order += 1
    score += order * sum(ord(ch) - ord('A') + 1 for ch in name[1:-1])
print score
