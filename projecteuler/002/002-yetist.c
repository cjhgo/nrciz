/* vi: set sw=4 ts=4: */
/*
 * 002-yetist.c: This file is part of ____
 *
 * Copyright (C) 2009 yetist <yetist@gmail.com>
 *
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */
#include <stdio.h>

//fn = f(n-2)+f(n-1)
int fib(int n)
{
	if (n == 2)
		return 2;
	else if (n == 1)
		return 1;
	else
		return fib(n-2) + fib(n-1);
}
/*这个公式不适合做这道题啊。 */

void fibs(int m)
{
	int a,b,n;
	int sum = a = b= 0;
	b = 1;
	for (;n<m;)
	{
		n = a+b;
		a = b;
		b = n;
		printf("%d ", n);
		if (n % 2 == 0)
			sum += n;
	}
	printf("\nresult = %d\n", sum);
}

int main(int argc, char** argv)
{
	printf("从1开始，在小于4000000以内的所有Fib数中的偶数，求他们的和。--yetist\n");
	fibs(4000000);
	return 0;
}

/*
vi:ts=4:wrap:ai:
*/
