#!/usr/bin/env ruby
# -*- coding: utf-8 -*-
=begin
Work out the first ten digits of the sum of the following one-hundred 
50-digit numbers.

please refer to file "digs" for the numbers
=end

def read_digits(fname)
    fp = File.new(fname, "r")
    digs = fp.readlines()
    fp.close
    
    digs=digs.join("\n").split("\n\n")
    return digs
end

def first_10_digits
    digs = read_digits("digs")
    inc = [0,0]
    sum = []
    49.downto 0 do |j|
        dsum = 0
        100.times do |i|
            dsum += digs[i][j] - 48
        end
        dsum += (inc[0] * 10 + inc[1])
        inc[0] = dsum / 100
        inc[1] = (dsum - 100 * inc[0])/ 10
        sum << dsum - inc[0] * 100 - inc[1] * 10
    end
    sum << inc[1] << inc[0]
    return sum[-10..-1].join('').reverse
end

puts first_10_digits
