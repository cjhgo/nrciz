#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
002:
Find the sum of all the even-valued terms in the Fibonacci sequence which 
do not exceed four million.
=end

def fibsum(n)
	sum = 0
	fib = [1,2]
	test = fib[-1]
	while test <= n:
		sum += test if test % 2 == 0
		fib << test + fib[-2]
		fib.shift
		test = fib[-1]
	end
	p sum
end

fibsum(4000000)
