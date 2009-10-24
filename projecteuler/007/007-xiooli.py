#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Name:     007-xiooli.py
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091024

prime=[2]
def is_prime(prm,i):
    j=0
    while prm[j]*prm[j] <= i:
        if i%prime[j] == 0:
            return False
        j+=1
    return True

k=3
while len(prime) < 10001:
    if is_prime(prime,k):
        prime.append(k)
    k+=2
print prime[-1]
