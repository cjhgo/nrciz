/*
 *
 *  Portions Copyright (C) 2009 wind (xihels@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 *
求小于1000的，能被3或5整除的，正整数之和
我的算法好傻，先用3的倍数相加，再用5的倍数相加，然后减去重叠的15的倍数

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//printf("求 1000 以下 3 或 5 的倍数的和\n");
	int sum1 = 0;
	int sum2 = 0;

	int i;
	for (i = 3; i < 1000; i += 3) {
		sum1 += i;
	}

	for ( i = 5; i < 1000; i += 5) {
		if (i % 3)
			sum2 += i;
	}

	printf("结果是 %d\n",sum1 + sum2);
	return 0;
}


