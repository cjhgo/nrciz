#! /usr/bin/env python
# -*- encoding:utf-8 -*-
# FileName: 015-yetist.py

"This file is part of ____"
 
__author__   = "yetist"
__copyright__= "Copyright (C) 2009 yetist <yetist@gmail.com>"
__license__  = """
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
研究了一下算法，得出公式如下: f(n) = 组合Cn/2n，但是速度依然不快。
"""
def factorial(n):
    result=0
    if n <= 0:
        return 1;
    else:
        result = n * factorial(n - 1)
    return result

def func(x):
    r = factorial(x)
    n = factorial(x*2)
    return n/(r**2);

if __name__=="__main__":
    print func(20)
