#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
001:	
Add all the natural numbers below one thousand that are multiples of 3 or 5.
=end
sum = 0
1000.times do |i|
	if i % 3 == 0 or i % 5 == 0
		sum += i
	end
end

p sum
