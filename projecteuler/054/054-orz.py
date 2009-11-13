#!/usr/bin/python
def p54():
    def RF(ll,ls):
        return (len(set(ls)) == 1 and len(set(ll)) == 5 and ll[0] == 10 and ll[-1] == 14)
    def SF(ll,ls):
        return (len(set(ls)) == 1 and len(set(ll)) == 5 and ll[-1] - ll[0] == 4)
    def FK(ll,ls):
        return (len(set(ll)) == 2 and (ll.count(ll[0]) > 3 or ll.count(ll[-1]) > 3))
    def FH(ll,ls):
        return (len(set(ll)) == 2 and ll.count(ll[0]) * ll.count(ll[-1]) == 6)
    def F(ll,ls):
        return (len(set(ls)) == 1)
    def S(ll,ls):
        return (len(set(ll)) == 5 and ll[-1] - ll[0] == 4)
    def TK(ll,ls):
        return (len(set(ll)) == 3 and len([i for i in ll if ll.count(i) == 3]) > 0)
    def TP(ll,ls):
        return (len(set(ll)) == 3 and len(set([i for i in ll if ll.count(i) == 2])) == 2)
    def OP(ll,ls):
        return (len(set(ll)) == 4)
    mp={'T':10,'J':11,'Q':12,'K':13,'A':14}
    for i in range(1,11):
        mp[str(i)] = i
    def ParseCard(l):
        ll = [mp[c[0]] for c in l]
        ls = [c[1] for c in l]
        ll.sort()
        if RF(ll,ls):return [(9,-1)]
        elif SF(ll,ls):return [(8,ll[-1])]
        elif FK(ll,ls):return [(7,ll[0] if ll.count(ll[0]) == 4 else ll[-1])]
        elif FH(ll,ls):return [(6,ll[0] if ll.count(ll[0]) == 3 else ll[-1])]
        elif F(ll,ls): return [(5,ll[-i]) for i in range(0,5)]
        elif S(ll,ls): return [(4,ll[-1])]
        elif TK(ll,ls):return [(3,[i for i in ll if ll.count(i) == 3][0])]
        rank = 0
        if TP(ll,ls):
            rank = 2
        elif OP(ll,ls):
            rank = 1
        l = [(rank,i) for i in set(ll) if ll.count(i) == 2]
        for i in ll:
            if ll.count(i) == 1:
                l.append((0,i))
        l.sort(reverse=True)
        return l
    res = 0
    for l in open('poker.txt','r').readlines():
        s1 = l[:15]
        s2 = l[-16:]
        l1 = s1.split()
        r1 = ParseCard(l1)
        if 'A' in s1:
            r12 = ParseCard(s1.replace('A','1').split())
            if r12 > r1: r1 = r12
        l2 = s2.split()
        r2 = ParseCard(l2)
        if 'A' in s2:
            r22 = ParseCard(s2.replace('A','1').split())
            if r22 > r2: r2 = r22
        if r1 > r2:
            res += 1
    return res
print p54()


