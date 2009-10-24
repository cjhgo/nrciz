#!/bin/bash
# Name:     001-xiooli.sh
# Author:   xiooli
#           Email:  <xioooli[at]yahoo.com.cn>
#           Site:   http://joolix.com
# Licence:  GPLv3
# Version:  091024

sum=0
for i in `seq 1 1000`; do
	if [ "$(($i%3))" = 0 -o "$(($i%5))" = 0 ]; then
		sum=$(($sum+$i))
	fi
done
echo $sum
