#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
A palindromic number reads the same both ways. The largest palindrome made 
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

=end
def palindromic? (n)
    n.to_s.reverse == n.to_s    
end


def max_threedigits_pal
    pals = []
    999.downto 101 do |i|
        999.downto i do |j|
            if pals.max && i * 999 < pals.max
                return pals.max
            end
            num = i * j
            if palindromic? num
                pals << num
            end
        end
    end
end

p max_threedigits_pal
