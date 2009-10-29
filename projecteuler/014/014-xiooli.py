#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Name:     014-xiooli.py
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091029

fnc = lambda x: ( x%2 == 0 and x/2 ) or x*3+1

dic={1:1}
def get_len(n):
    if n not in dic:
        dic[n]=get_len(fnc(n))+1
    return dic[n]

lnm,N = 0,13
for n in xrange(N,1000000):
    ln = get_len(n)
    if lnm < ln:
        lnm = ln
        N = n
print N
