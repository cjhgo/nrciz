#!/usr/bin/env python

def get_english_name(n):
    l1 = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', \
          'nine', 'ten', 'eleven', 'twelve', 'thirtenn', 'fourteen', \
          'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
    l2 = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', \
          'ninety', 'hundred']
    if n == 1000:
        return 'onethousand'
    elif n % 100 == 0: 
        return l1[n / 100] + 'hundred'
    elif n > 100:
        return l1[n / 100] + 'hundredand' + get_english_name(n % 100)
    elif n < 20:
        return l1[n]
    else:
        return l2[n / 10 - 2] + l1[n % 10]

num_letter = 0
for i in range(1, 1001):
    num_letter += len(get_english_name(i))
print num_letter
