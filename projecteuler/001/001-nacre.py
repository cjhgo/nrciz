#!/usr/bin/env python

def sum_multiple(feed, limit):
    return feed * ((limit - 1) / feed) * ((limit - 1) / feed + 1) / 2

sum = sum_multiple(3, 1000) + sum_multiple(5, 1000) - sum_multiple(3 * 5, 1000)
print sum
