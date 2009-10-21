/*
 * =====================================================================================
 *
 *       Filename:  002-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 10时19分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long int fib(int num)
{
	if(num==0)
		return 0;
	else if(num==1)
		return 1;
	else if (num==2)
		return 2;
	return fib(num-1)+fib(num-2);
}

int main(int argc, char *argv[])
{
 
	long int num=4000000;
	int i=0;
	long int sum=0;
	long int out=0;
	printf("从1开始，在小于4000000以内的所有Fib数中的偶数，求他们的和。 --lerosua\n");

	do{
		out=fib(i);
		if(out%2==0)
			sum+=out;
		i++;
	}while(out<num);


	printf("結果为 %ld\n",sum);
	return 0;
}
