#!/usr/bin/env python

def is_cancelable(p, q):
    strp = str(p)
    strq = str(q)
    # we assume that p and q both contain 2 digits, and \frac{p}{q}\lt 1
    # so the cancellation should take place on 1&2 or 2&1 digits of p&q
    if strp[1] == "0" or strq[1] == "0":
	return 0
    if strp[0] == strq[1]:
	if p * int(strq[0]) == q * int(strp[1]):
	    return 1
    elif strp[1] == strq[0]:
	if p * int(strq[1]) == q * int(strp[0]):
	    return 1
    return 0

def gcd(p, q):
    if p > q:
	return gcd(q, p)
    if p == 0:
	return q
    p, q = q % p, p
    return gcd(p, q)

product_p, product_q = 1, 1
for p in range(10, 100):
    for q in range(p + 1, 100):
        if is_cancelable(p, q):
       	    product_p = product_p * p
            product_q = product_q * q
print product_q / gcd(product_p, product_q)
