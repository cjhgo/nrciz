#!/usr/bin/env python

from math import sqrt

# We know that a Pythagorean triplet can be express as:
# m^2-n^2, 2mn, m^2+n^2, where m\gt n\gt 0.
# So the sum of the triplet is 2m(m+n), hence we have
def get_pythagorean_triplet(sum):
    for m in range(int(sqrt(sum / 4.0)) + 1, int(sqrt(sum / 2.0)) + 1):
        if sum % (2 * m) == 0:
            n = sum / 2 / m - m
            if n != 0:
                a, b, c = m * m - n * n, 2 * m * n, m * m + n * n
                return a, b, c

t = get_pythagorean_triplet(1000)
print t[0] * t[1] * t[2]
