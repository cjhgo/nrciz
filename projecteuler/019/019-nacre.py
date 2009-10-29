#!/usr/bin/env python

def get_days(year, month):
    if month == 2:
        if year % 4 != 0:
            return 28
        elif year % 100 != 0:
            return 29
        elif year % 400 != 0:
            return 28
        else:
            return 29
    elif month in (4, 6, 9, 11):
        return 30
    else:
        return 31

count = 0
num_days = 2
for year in range(1901, 2001):
    for month in range(1, 13):
        if num_days % 7 == 0:
            count += 1
        num_days += get_days(year, month)
print count
