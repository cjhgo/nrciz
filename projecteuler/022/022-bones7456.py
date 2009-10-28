#!/usr/bin/env python

names = open("names.txt").read()
names = eval("["+names+"]")
names.sort()
r = 0
for i, name in enumerate(names, 1):
    r += i * sum( ord(c) - 64 for c in name )
print r

