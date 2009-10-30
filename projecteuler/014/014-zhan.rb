#!/usr/bin/env ruby
# -*- coding: gbk -*-
=begin
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) 
contains 10 terms. Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
=end

$hashed = {1=>1}
def facts_n(n)
    if $hashed.has_key?(n)
        return $hashed[n]
    else
        if n % 2 == 0
            test = facts_n(n/2) + 1
            $hashed[n] = test
            return test
        else
            test = facts_n(n * 3 + 1) + 1
            $hashed[n] = test
            return test
        end
    end
end

def longest(n)
    maxlen = 1
    maxnum = 1
    2.upto n do |i|
        if facts_n(i) > maxlen
            maxlen = facts_n(i)
            maxnum = i
        end
    end
    return maxnum
end

#p longest(10)
p longest(1000000)
