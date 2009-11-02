#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
2^(15) = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^(1000)?
=end

def sum_of_digits(n)
    s = 2**n
    sum = 0
    while s >= 1
        sum += s % 10
        s = s / 10
    end
    sum += s
end

p sum_of_digits(1000)
