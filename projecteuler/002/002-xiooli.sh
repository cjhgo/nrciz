#!/bin/bash
# Name:     002-xiooli.sh
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091024

n1=1
n2=2
fib=2
result=0
echo "从1开始，在小于4000000以内的所有Fib数中的偶数，求他们的和。--author"
while [ $fib -lt 4000000 ]; do
	if [ "$(($fib%2))" = 0 ]; then
		echo $fib
		result=$(($result+$fib))
	fi
	fib=$(($n1+n2))
	n1=$n2
	n2=$fib
done
echo result = $result


