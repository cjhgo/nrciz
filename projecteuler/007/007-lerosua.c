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

#define MAX 10240
/** 简单的素数集合*/
static long long primum[MAX] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

static long int count = 10;


/** 填加10001个素数进素数数组*/
void fill_prime()
{

	long long i = 31;
	long int j = 0;
	//for (; i < num; i = i + 2) {
	while(1){
		int flag = 1;
		for (j = 0; j < count; j++) {
			if (i % primum[j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			primum[count++] = i;
		if(count>10001)
			break;
		i+=2;

	}


}

int main(int argc, char *argv[])
{

	fill_prime();

	printf("%lld\n",primum[10000]);
	//printf("%ld\n",primum[5]);
	return 0;
}
