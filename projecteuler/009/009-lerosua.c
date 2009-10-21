/*
 * =====================================================================================
 *
 *       Filename:  009-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 16时53分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

int pythagorean(int a,int b,int c)
{
	return (a*a+b*b)==c*c ;
}
int main(int argc, char *argv[])
{
 
	int a=1,b=1,c=1;
	int i,j;
	for(i=1;i<1000;i++)
		for(j=i+1;j<1000;j++){
			if(pythagorean(i,j,1000-j-i)){
			//	printf(" %d %d %d \n",i,j,1000-i-j);
				a=i;
				b=j;
				c=1000-i-j;
				
			}
		}

	printf("%d\n",a*b*c);
	

	return 0;
}
