/*
 * =====================================================================================
 *
 *       Filename:  common_divisor.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月16日 09时31分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wind (xihe), xihels@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) do {a ^= b; b ^= a; a ^= b;}while(0)
int get_common_divisor(int a, int b)
{
	if (b > a)
		swap(a, b);
	int c = 0;
	for (;;) {
		c = a % b;
		if (0 == c)
			return b; 
		a = c;
		swap(a, b);
	}
}

int main ( int argc, char *argv[] )
{
	int a, b;
	scanf("%d, %d", &a, &b);
	printf("common divisor is %d\n", get_common_divisor(a, b));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

