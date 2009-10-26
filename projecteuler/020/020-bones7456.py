#!/usr/bin/env python
r=1
for i in range(1,101):
    r *= i
print sum([int(c) for c in str(r)])
