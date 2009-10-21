#!/usr/bin/env python
N=100

print ((1+N)*N/2)**2 - sum([i*i for i in range(1,N+1)])
