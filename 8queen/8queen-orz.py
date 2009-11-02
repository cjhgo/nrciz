#!/usr/bin/python
def p8queen():
    def R(t,mp):
        if t==8:
            yield mp
            return
        for i in range(0,8):
            f = True
            for j in range(0,t):
                if (i == mp[j]) or (abs(j-t) == abs(mp[j]-i)):
                    f = False
                    break
            if f:
                mp[t] = i
                mpt = mp[:]
                for r in R(t+1,mpt):
                    yield r
    mp = [0]*8
    return [x for x in R(0,mp)]  

l = p8queen()
print 'total solutions: ', len(l)


print '-- solutions --'
#for each solutions x
#put queen in mp[r][x[r]]  (0<=r<8)

#for x in l:print x  # uncomment this line output result
