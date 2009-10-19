/*
 * =====================================================================================
 *
 *       Filename:  gcd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月15日 20时34分49秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

int mod(int a,int b)
{
	return a%b;
}

int gcd(int a,int b)
{
	int c=0;
	do{
		c=mod(a,b);
		if(c==0)
			return b;
		a=b;
		b=c;
	}while(c>0);

	return -1;
}

int main(int argc,char *argv[])
{
 
	int a=28;
	int b=14;
	printf("输入两个整数: ");
	scanf("%d %d",&a,&b);
	printf("\n");

	printf("最大公约数 gcd(%d,%d) = %d\n",a,b,gcd(a,b));

	    return 0;
}

