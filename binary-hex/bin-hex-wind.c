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
#include <string.h>

int main(int argc, char* argv[])
{
	if (4 != argc) {
		printf("用法\n %s 原数字 原进制 目标进制\n", argv[0]);
		exit (1);
	}

	int obase = atoi(argv[2]);
	int tbase = atoi(argv[3]);

	int sum = strtol(argv[1], NULL, obase);

	char buf[256];
	char* p = buf;
	while (sum) {
		int c = sum % tbase;
		sprintf(p++, "%x", c);
		sum /= tbase;
	}

	if (p != buf) {
		p--;
		char* p1 = buf;
		while(p > p1) {
			char c = *p;
			*p = *p1;
			*p1 = c;
			p--;
			p1++;
		}
	}
	printf("%s\n", buf);

	return 0;
}

