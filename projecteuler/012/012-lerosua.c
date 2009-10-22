/*
 * =====================================================================================
 *
 *       Filename:  012-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月22日 10时40分16秒
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
#include <math.h>

#define REQUEST 500
long long eum(int num)
{
	return (long long)(1+num)*num/2;
}
int debug_count_yinzi(long long num)
{
	long long m =(long long)sqrt(num)+1;
	int count=1;

	long long i;
	for(i=2;i<m;i++){
		if(num%i==0)
		{

			printf(" %lld ",(long long)num/i);
			count+=2;
		}
	}

	return count;
}
int count_yinzi(long long num)
{
	long long m =(long long)sqrt(num)+1;
	int count=1;

	long long i;
	for(i=2;i<m;i++){
		if(num%i==0)
			count+=2;
	}

	return count;
}
int main(int argc, char *argv[])
{
 
	int start=1000;
	//int start=59599;


	int count=0;
	
	long long sum=eum(start);
	printf("1+...+...+%d=%lld\n",start,sum);
	long long i;
	for(i=start;;i++){
		sum=eum(i);
		count=count_yinzi(sum);
		if(count>REQUEST){
			//debug_count_yinzi(sum);
			printf("count=%d\n",count);
			printf(" %lld\n",i);
			printf(" sum = %lld\n",sum);
			return 0;
		}
		//sum+=i;

	}
	//printf("test 28 =%d\n",count_yinzi(28));






	printf("\n");

	return 0;
}
