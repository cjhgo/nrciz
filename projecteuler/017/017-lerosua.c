/*
 * =====================================================================================
 *
 *       Filename:  017-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月26日 11时33分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

/**
 * 数字的计算直接取自bones的数据，
 * nnd，自己去算英文数字有多少个位，还得把这么英文一次写出来，太orz了
n_1_9=[3,3,5,4,4, 3,5,5,4]
n_10_19=[3, 6,6,8,8,7, 7,9,8,8]
n_20_90=[6,6,5,5, 5,7,6,6]
n_hundred=7
n_and=3

*/
int num1_9[]={3,3,5,4,4,3,5,5,4};
int num_10_19[]={3,6,6,8,8,7,7,9,8,8};
int num_20_90[]={6,6,5,5,5,7,6,6};
int num_hundred=7;
int num_and=3;
int num_thousand=11;

int main(int argc, char *argv[])
{
	int sum=0;

	int i;
	int j;
	int k;
	for(i=0;i<9;i++)
		sum+=num1_9[i];
	/** 99以内*/
	for(i=0;i<10;i++)
		sum+=num_10_19[i];
	for(i=0;i<8;i++)
		sum+=num_20_90[i];
	
	for(i=0;i<8;i++)
		for(j=0;j<9;j++)
			sum+=num_20_90[i]+num1_9[j];


	for(i=0;i<9;i++){
		sum+=(num1_9[i]+num_hundred);
		
		for(j=0;j<9;j++)
			sum+=(num1_9[i]+num_hundred+num_and+num1_9[j]);
		for(j=0;j<10;j++)
			sum+=(num1_9[i]+num_hundred+num_and+num_10_19[j]);
		for(j=0;j<8;j++)
			sum+=(num1_9[i]+num_hundred+num_and+num_20_90[j]);
		
		for(j=0;j<8;j++)
			for(k=0;k<9;k++)
				sum+=(num1_9[i]+num_hundred+num_and+num_20_90[j]+num1_9[k]);
	}
	sum+=11;

	printf("%d\n",sum);

 
	return 0;
}

