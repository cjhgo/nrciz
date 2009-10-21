/* vi: set sw=4 ts=4: */
/*
 * 001-yetist.c: This file is part of ____
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

int main(int argc, char** argv)
{
	int i, m=0;
	for (i=999; i>0; i--) /* 就说怎么总是和别人的值不一样，原来是要小于1000啊, 开始写成了i=1000 */
	{
		if (i % 3 == 0 || i % 5 == 0)
			m += i;
	}
	printf("sum is :%d\n", m);
	return 0;
}

/*
vi:ts=4:wrap:ai:
*/
