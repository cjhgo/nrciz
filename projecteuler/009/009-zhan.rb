#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
A Pythagorean triplet is a set of three natural numbers, a < b < c, 
for which, a^(2) + b^(2) = c^(2)

For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
------
a<b<c so a < 333, c > 333, a<b<667-a
a^2+b^2 = c^2
(1000-c)^2 = (a+b)^2 <=> 1000000 + c^2 - 2000c = a^2+b^2+2ab
<=> ab / 1000 + c = 500 => c = 500 - ab/1000 >= 500 - (a+b)^2/4000
c >= 500 - 667^2/4000 > 388
...
=end

def square?(num)
    a = Math.sqrt(num)
    a * a == num
end

def find_triplet_1000
    1.upto 306 do |i|
        i.upto 612-i do |j|
            c = 1000 - i - j
            if c > 388
                squc = i*i + j*j
                if c * c == squc
                    return i*j*c
                end
            end
        end
    end
end

p find_triplet_1000
