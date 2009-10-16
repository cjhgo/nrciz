#!/usr/bin/python
# Filename: gcd-bones7456.py
# Author: bones7456

def common_divisor(arg):
    """Get common divisor of Two-Number-List arg.
    """
    a, b = int(min(arg)), int(max(arg))
    while True:
        c = b % a
        if 0 == c:
            return a
        else:
            a, b = c, a

if __name__ == "__main__":
    import sys
    print "common divisor is:",common_divisor(sys.argv[1:3])
