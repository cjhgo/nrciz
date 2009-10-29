#!/usr/bin/python
def p30():
    sum = 0
    for n in range(2,295245):
        s_t = 0
        for i in [ord(c)-ord('0') for c in str(n)]:
            s_t += i**5
        if n==s_t:
            sum+=n
    return sum
print p30()
