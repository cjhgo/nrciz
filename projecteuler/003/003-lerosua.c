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
#include <math.h>

#define MAX 1024
//#define DEBUG
/** 简单的素数集合*/
static int primum[MAX] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

static int count = 10;


/** 填加num以内的素数进素数数组*/
void fill_prime(int num)
{

	int i = 31;
	int j = 0;
	for (; i < num; i = i + 2) {
		int flag = 1;
		int m=sqrt(i)+1;
		//for (j = 0; j < count; j++) {
		for (j = 0; primum[j] < m; j++) {
			
			//if ((primum[j]>m || i % primum[j] == 0)) {
			if (( i % primum[j] == 0)) {
				flag = 0;
				break;
			}
		}
		if (flag)
			primum[count++] = i;

	}


}

int main(int argc, char *argv[])
{
	printf("求600851475143的最大质因数 --lerosua\n");
	int yin[256] = { 0 };

	int num = 10000;
	int i = 0;
	fill_prime(num);
#ifdef DEBUG
	printf(" %d 以内素数组为: \n", num);
	for (i = 0; i < count; i++)
		printf("%d ", primum[i]);
	printf("\n\n");
#endif

#if 1
	long long sum = 600851475143L;
	//long long sum = 8462696833;
	//long long sum=13195;

	int j = 0;
	for (i = 0; i < count; i++) {
		if (sum % primum[i] == 0) {
			sum = sum / primum[i];
			yin[j] = primum[i];
			j++;
		}


	}

#ifdef DEBUG
	printf(" %lld 以内素数组为: \n", sum);
	for (i = 0; i < j; i++)
		printf("%d ", yin[i]);

	printf("\n\n");
#endif
	printf("result = %d\n", yin[j - 1]);
#endif
	return 0;
}
