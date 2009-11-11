#! /usr/bin/env python
import sys,string

try:
    obase = int(sys.argv[2])
    num = int(sys.argv[1], obase)
    tbase = int(sys.argv[3])
except:
    print "parameter error."
    sys.exit(1)
digitals = map(str, range(10)) + list(string.uppercase)
r = ''
while num:
    num, i = divmod(num, tbase)
    r = digitals[i] + r
print r
