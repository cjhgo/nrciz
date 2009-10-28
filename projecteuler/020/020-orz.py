#!/usr/bin/env python
def p20():
	return sum(int(c) for c in str(reduce(lambda x,y:x*y,[i for i in range(1,101)])))
	
print p20()
