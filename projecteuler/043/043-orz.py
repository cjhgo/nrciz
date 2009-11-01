#!/usr/bin/python
def p43():
    def R(t,s,l,lf,pl,resl):
        for i,v in enumerate(l):
            if lf[i]:
                ss=s*10+v
                st = ss%1000
                if t > 2 and (st%pl[t-3]) != 0:
                    continue
                if t == 9:
                    resl.append(ss)
                    continue
                lf[i] = False
                R(t+1,ss,l,lf,pl,resl)
                lf[i] = True
  
    l = [i for i in range(10)]
    lf = [True]*10
    pl = (2,3,5,7,11,13,17)
    resl = []
    for i in range(1,10):
        lf[i] = False
        R(1,i,l,lf,pl,resl)
        lf[i] = True
    return sum(resl)

print p43()