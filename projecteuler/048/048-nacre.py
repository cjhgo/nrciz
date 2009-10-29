#!/usr/bin/env python

nd = 10
x = 10 ** nd

def sum10(base, power):
    if power == 1:
        return base
    elif power % 2 == 0:
        return (sum10(base, power / 2) ** 2) % x
    else:
        return (sum10(base, power / 2) ** 2 * base) % x

print sum(sum10(i, i) for i in range(1, 1001)) % x
