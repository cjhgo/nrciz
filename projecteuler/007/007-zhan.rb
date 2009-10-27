#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
we can see that the 6^(th) prime is 13.

What is the 10001^(st) prime number?
=end

def prime? (num)
    2.upto Math.sqrt(num).to_i do |div|
        if num % div == 0
            return false
        end
    end
    return true
end

def the_nst_prime(n)
    num = 3
    primes = [2]
    while primes.length < n
        primes << num if prime? num 
        num += 2
    end
    p primes[-1]
end

#the_nst_prime(6)
the_nst_prime(10001)
