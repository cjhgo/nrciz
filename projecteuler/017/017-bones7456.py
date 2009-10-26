#!/usr/bin/env python

n_1_9=[3,3,5,4,4, 3,5,5,4]
n_10_19=[3, 6,6,8,8,7, 7,9,8,8]
n_20_90=[6,6,5,5, 5,7,6,6]
n_hundred=7
n_and=3

r =sum(n_1_9) #1~9
r+=sum(n_10_19) #10~19
r+=sum(n_20_90) + sum(n_20_90)*len(n_1_9) + sum(n_1_9)*len(n_20_90) #20~99
t=r #1~99
r+=sum([i+n_hundred for i in n_1_9]) #100/200/../900
r+=sum([i+n_hundred+n_and for i in n_1_9]) * 99 + t * 9 #101~999 except up

r+=11 #1000

print r
