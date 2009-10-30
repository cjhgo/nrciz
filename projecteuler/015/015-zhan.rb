#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
Starting in the top left corner of a 2×2 grid, 
there are 6 routes (without backtracking) to the bottom right corner.

How many routes are there through a 20×20 grid?
-----------
C(2n,n) = 2n*(2n-1)*...*(n+1)/(n*(n-1)*...*1)
---------
=end

def c_2n_n(n)
    fact = 1
    (n+1).upto(2*n) do |i|
        fact *= i
    end
    1.upto n do |j|
        fact /= j 
    end
    return fact
end

#p c_2n_n(2)
p c_2n_n(20)
