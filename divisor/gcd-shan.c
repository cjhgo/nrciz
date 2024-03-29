/*
 * =====================================================================================
 *
 *       Filename:  gcd-shan.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月17日 21时46分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dxhn (Shan), dxhnyn@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int get_divisor(int x,int y)
{

	if (y > x)
		x ^= y, y ^= x, x ^= y;
	int d = 0;
	for (;;) {
		d = x % y;
		if (0 == d)
			return y;
		x = y, y = d;
	}
}

int main(int argc,char *argv[])
{
	int x,y,d=0;
	printf ("input integer for x and y. \n");
	char ic[11];
	scanf("%d,%d", &x, &y);
	printf(" x = %d, y = %d \n",x,y);
	scanf("%s",ic);
	d = get_divisor(x,y);
	printf("%d and %d common divisor is %d. \n",x,y,get_divisor(x, y));
	printf("%s",ic);	
	
	return 0;
}

