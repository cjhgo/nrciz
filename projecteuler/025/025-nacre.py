#!/usr/bin/env python

i1, i2 = 1, 1

numTerm = 2
limit = 10 ** 999
while i2 < limit :
    i1, i2 = i2, i1 + i2
    numTerm += 1

print numTerm
