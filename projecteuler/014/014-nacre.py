#!/usr/bin/env python

dic_len = {1:1}
def get_seq_len(n):
    if n in dic_len:
        return dic_len[n]
    elif n % 2 == 0:
        dic_len[n] = get_seq_len(n / 2) + 1
        return dic_len[n]
    else:
        dic_len[n] = get_seq_len(3 * n + 1) + 1
        return dic_len[n]

def get_max_seq_len(ubound):
    n, max_seq_len = 1, 1
    for i in range(1, ubound):
        if get_seq_len(i) > max_seq_len:
            n, max_seq_len = i, get_seq_len(i)
    return n, max_seq_len

print get_max_seq_len(1000000)
