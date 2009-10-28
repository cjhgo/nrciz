#!/usr/bin/env python

def p19():
	def day_of_week(y,m,d):
		# 0 == Sunday,y>1752
		offset = (0,3,2,5,0,3,5,1,4,6,2,4)
		if m < 3:y-=1
		return (y+y/4-y/100+y/400+offset[m-1]+d)%7
	#print day_of_week(1900,1,1),day_of_week(2009,10,28)
	return sum(1 for i in range(1901,2001) for j in range(1,13) if day_of_week(i,j,1) == 0)

print p19()
