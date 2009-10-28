/* vi: set sw=4 ts=4: */
/*
 * 003-yetist.c: This file is part of ____
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
#include <sys/types.h>

int main(int argc, char** argv)
{
	
	printf("求600851475143的最大质因数 --yetist\n");
	u_int64_t v, num = 600851475143L;

	for(v=2;v<=num;v++) 
	{ 
		while(num != v) 
		{ 
			if(num % v ==0) 
			{ 
				num=num/v; 
			} 
			else 
				break; 
		} 
	} 
	printf("result = %llu\n", num);
	return 0;
}
/*
vi:ts=4:wrap:ai:
*/
