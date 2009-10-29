#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Name:     009-xiooli.py
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091028

print [ i*j*(1000-i-j) for i in range(1,999) for j in range(1,999) if i*i+j*j==(1000-i-j)*(1000-i-j) ][0]

