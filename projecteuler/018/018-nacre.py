#!/usr/bin/env python

m = []
with open('triangle.txt', 'r') as f:
    for line in f:
        m.append([int(s) for s in line.split()])

num_lines = len(m)
for i in range(num_lines - 1, 0, -1):
    for j in range(i):
	m[i - 1][j] = m[i - 1][j] + max(m[i][j], m[i][j + 1])

print m[0][0]
