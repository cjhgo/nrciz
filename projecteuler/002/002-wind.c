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

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("从1开始，在小于4000000以内的所有Fib数中的偶数，求他们的和。--wind\n");
	int a = 0;
	int b = 1;
	int c;
	int result = 0;
	while (b < 4000000) {
		c = a + b;
		if ( 0 != c % 2 )
			result += c;
		a = b;
		b = c;
	}
	printf("result = %d\n", result);
	return 0;
}

