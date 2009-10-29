#!/usr/bin/python

def p26():
    def CycleL(n):
        l = []
        x = 1
        while x > 0:
            while x<n:
                x*=10
            if x not in l:l.append(x)
            else: return len(l) - l.index(x)
            x%=n
        return 0 
    #print CycleL(6),CycleL(7),CycleL(8),CycleL(9),CycleL(2)
    m_v = 0
    r = 0
    for x in range(1,1000):
        t = CycleL(x)
        if t > m_v:
            m_v = t
            r = x
    #print r,x
    return r



print p26()
