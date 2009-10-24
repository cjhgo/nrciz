#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Name:     004-xiooli.py
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091024

print max([ i*j for i in range(100,1000) for j in range(100,1000) if str(i*j) == str(i*j)[::-1]])

