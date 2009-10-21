/*
 * =====================================================================================
 *
 *       Filename:  003-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 11时37分49秒
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

#define MAX 1024000
/** 简单的素数集合*/
static long long primum[MAX] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

static long int count = 10;


/** 填加10001个素数进素数数组*/
void fill_prime(long long num)
{

	long long i = 31;
	long int j = 0;
	for (; i < num; i = i + 2) {
		int flag = 1;
		for (j = 0; j < count; j++) {
			if (i % primum[j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			primum[count++] = i;
			if(i>num)
				return;
		}
		if(count>MAX){
			printf("error%d\n",count);
			exit(1);
		}
	}


}

int main(int argc, char *argv[])
{

	int i;
	long long sum=0L;
	fill_prime(2000000);

	for(i=0;i<count;i++)
		if(primum[i]<2000000)
			sum+=primum[i];

	printf("count %d \n",count);
	printf("%lld\n",sum);
	//printf("%ld\n",primum[5]);
	return 0;
}
