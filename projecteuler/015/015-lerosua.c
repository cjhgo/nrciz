/*
 * =====================================================================================
 *
 *       Filename:  015-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月26日 10时16分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>
#define NUM 20
long long grid[NUM+1][NUM+1];

int main(int argc, char *argv[])
{
	int i,j;

	for(i=0;i<NUM;i++)
		for(j=0;j<NUM;j++)
			grid[i][j]=1;
	for(i=0;i<NUM;i++)
		for(j=0;j<NUM;j++)
			grid[i+1][j+1]=grid[i+1][j]+grid[i][j+1];

	long long num=grid[NUM][NUM]+2;


	




 
	printf("%lld\n",num);
	return 0;
}

