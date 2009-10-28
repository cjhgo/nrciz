#!/usr/bin/env python
def p15():
	N = 20 + 1
	mp = [[0]*N for i in range(N)]
	for i in range(N):
		mp[i][0] = mp[0][i] = 1
	for i in range(1,N):
		for j in range(1,N):
			mp[i][j] = mp[i-1][j]+mp[i][j-1]
	return mp[N-1][N-1]

print p15()
