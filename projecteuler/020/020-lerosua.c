/*
 * =====================================================================================
 *
 *       Filename:  013-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月24日 10时10分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

//#define DEBUG
/** 定位数位*/
#define NUM 1000

/** NUM位数的大数加法，类似sum+=num*/
void add(int sum[],int num2[]);
/** 大数复制*/
void copy(int dst[],int src[]);
/** 大数乘法，后面是乘数*/
void multipy(int num[],int mul);
/** 大数初始化*/
void init(int num[]);

void add(int sum[],int num2[])
{
	int i;
	int tmp;
	int flag=0;
	for(i=0;i<NUM;i++){
		tmp=sum[i]+num2[i]+flag;
		if(tmp>=10){
			sum[i]=tmp-10;
			flag=1;
		}else{
			sum[i]=tmp;
			flag=0;
		}
	}

}
void multipy(int num[],int mul)
{
	int sum[NUM]={0};
	int i;
	for(i=0;i<mul;i++)
		add(sum,num);
	copy(num,sum);
}
void copy(int dst[],int src[])
{
	int i;
	for(i=0;i<NUM;i++)
		dst[i]=src[i];
}

void init(int num[])
{
	int i;
	for(i=0;i<NUM;i++)
		num[i]=0;
}

int main(int argc, char *argv[])
{
	int i;
	int sum[NUM]={0};
	int result=0;
	init(sum);
	sum[0]=1;

	for(i=1;i<=100;i++)
		multipy(sum,i);


#ifdef DEBUG
	for(i=0;i<NUM;i++)
		printf("%d",sum[NUM-i-1]);
#endif
 
	for(i=0;i<NUM;i++)
		result+=sum[i];
	printf("%d",result);
	printf("\n");
	return 0;
}
