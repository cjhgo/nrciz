#!/usr/bin/env python
print 1 + sum(8 * n * (n + 1) / 2 + 1 for n in range(1, 501)) * 4 - 12 * 500 * (500 + 1 ) / 2
#1 center
#+ right up conner * 4
#- left three conner between right up conner
