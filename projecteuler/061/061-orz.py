#!/usr/bin/python
def p61():
    funcl =[lambda n:n*(n+1)//2,
            lambda n:n*n,
            lambda n:n*(3*n-1)//2,
            lambda n:n*(2*n-1),
            lambda n:n*(5*n-3)//2,
            lambda n:n*(3*n-2),]

    lr = []
    for j in range(len(funcl)):
        i,k = 1,1
        while funcl[j](k) < 1000:
            k+=1
        while funcl[j](i) < 10000:
            i+=1
        lr.append((k,i))
    pn = [[funcl[i](j) for j in xrange(lr[i][0],lr[i][1])] for i in range(6)]

    def R(t,l,pni):
        if t == 6:
            if (l[-1] % 100) == (l[0]/100):
                yield l
        if t == 0:
            for v in pn[0]:
                for r in R(1,[v],set([0])):
                    yield r
        else:
            for i in xrange(6):
                if i not in pni:
                    for j in pn[i]:
                        if j/100 == l[-1]%100:
                            for r in R(t+1,l[:]+[j],set([i])|pni):
                                yield r

    return sum([r for r in R(0,[],set())][0])
print p61()

