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

long int fib_sum(int num)
{
	long int second=2;
	long int sum=1;
	int i=1;

	while(i<num)
	{
	sum+=second;
	second=sum;
	i++;
	}
	return sum;
}
int main(int argc, char *argv[])
{
 
	int num=4000000;
	if(argc==2)
		num=atoi(argv[1]);
	printf("求fibonacci数列%d个元素的和 --lerosua\n",num);

	printf("結果为 %ld\n",fib_sum(num));
	return 0;
}
