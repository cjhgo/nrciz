#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
=end

def prime? (num)
    2.upto Math.sqrt(num).to_i do |div|
        if num % div == 0
            return false
        end
    end
    return true
end

def sum_of_prime(n)
    sum = 2
    num = 3
    while num <= n
        if prime? num
            sum += num
        end
        num += 2
    end
    return sum
end

#def sum_of_prime_2(n)
#	sum = 17
#    primes = []
#    11.upto n do |i|
#		if (i % 2 != 0) && (i % 3 !=0) && (i % 5 != 0) && (i % 7 !=0)
#			primes << i
#		end 
#    end
#	while primes.length >= 1
#		head = primes.shift
#		sum += head
#		if not primes.empty?
#			times = (primes[-1] / head).to_i + 1
#			2.upto times do |j|
#				primes.delete(head * j)
#			end
#		end
#	end
#	return sum
#end
#p sum_of_prime(10)
p sum_of_prime(2000000)
