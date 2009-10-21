/*
 * =====================================================================================
 *
 *       Filename:  006-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 15时49分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
 
	int i;
	int sum1=0;
	int sum2=0;
	int cha=0;
	for(i=0;i<=100;i++){
		sum1+=i*i;
		sum2+=i;
	}

	cha = sum2*sum2-sum1;
	printf(" %d\n",cha);

	return 0;
}


