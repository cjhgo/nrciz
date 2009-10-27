#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
2520 is the smallest number that can be divided by each of the numbers 
from 1 to 10 without any remainder.

What is the smallest number that is evenly divisible by all of the numbers 
from 1 to 20?
=end

def gcd(a, b)
    if b == 0
        return a
    else
        return gcd(b, a % b)
    end
end



def lcm_to_num(n)
    lcm = 2
    3.upto n do |i|
      lcm = lcm * i / gcd(lcm, i)  
    end
    p lcm
end

#lcm_to_num(10)
lcm_to_num(20)
