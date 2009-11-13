#!/usr/bin/python

def p59():
    strl = " !\"'(),-.0123456789:;?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    l = [int(c) for c in open('cipher1.txt','r').readlines()[0].strip('\r\n').split(',')]
    for a in range(97,123):
        for b in range(97,123):
            for c in range(97,123):
                s,k = '',(a,b,c)
                for i,v in enumerate(l):
                    ch=chr(v^k[i%3])
                    if ch not in strl:break
                    s+=ch
                if len(s) == len(l): 
                    return sum(ord(c) for c in s)
                
print p59()
