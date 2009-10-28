#!/usr/bin/python
#
#

F=[1,2]
L=[2]
while F[-1]<4000000:
	F.append(F[-1]+F[-2])
	if F[-1]%2==0 :
		L.append(F[-1])
print F[-1],F[-2],L[-1]
print sum(n for n in L)
	
