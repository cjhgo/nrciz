#!/usr/bin/env ruby
#-*- coding:utf-8 -*-
=begin
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
=end

def prime? (n)
	2.upto Math.sqrt(n).to_i do |div|
		if n % div == 0:
			return false
		end
	end
	return true
end

def getfactors(n)
	factors = []
	2.upto Math.sqrt(n).to_i do |div|
		if n % div == 0:
			factors << div
			if not factors.member?(n / div)
				factors << n / div
			end
		end
	end
	return factors
end

def max_prime_factor(n)
	factors = getfactors(n)
	factors.sort!
	max = 1
	while !factors.empty?
		max = factors.pop
		if prime? max
			break
		end
	end
	return max
end

p max_prime_factor(600851475143)
