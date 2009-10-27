#!/ur/bin/env ruby
# -*- coding: utf-8 -*-
=begin
The sum of the squares of the first ten natural numbers is,
1^(2) + 2^(2) + ... + 10^(2) = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^(2) = 55^(2) = 3025

Hence the difference between the sum of the squares of the first 
ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.

----
=end

def diff_sum(n)
    sum = 0
    1.upto n do |i|
        1.upto n do |j|
            if i != j
                sum += i * j
            end
        end
    end
    p sum
end

#diff_sum(10)
diff_sum(100)
