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

#define DEBUG
/** 定位数位*/
#define NUM 4000

/** NUM位数的大数加法，类似sum+=num*/
void add(int sum[],int num2[]);
/** 大数复制*/
void copy(int dst[],int src[]);
/** 大数乘法，后面是乘数*/
void multipy(int num[],int mul);
/** 大数初始化*/
void init(int num[]);

/** 大数指数运算*/
void cube(int num[],int class);
/** 把大数表示的转换成int，用于较小数时,走出int范围会溢出，注意*/
int switch_to_int(int num[]);
/** 把小数转成大数*/
void switch_to_big(int num[],int nint);

void switch_to_big(int num[],int nint)
{

	/** 其实也转不了多少位*/
	int i;

	int wei=10;
	for(i=0;i<10;i++){
		num[i]=nint%wei;
		nint=nint/wei;
	}


}

int switch_to_int(int num[])
{
	int i=1;
	int result=0;
	int wei=1;
	result+= num[0];
	for(i=1;i<NUM;i++){
		wei=wei*10;
		result+= num[i]*wei;
	}
	return result;


}
void cube(int num[],int class)
{
	int index=switch_to_int(num);
	int i;
	for(i=1;i<class;i++)
		multipy(num,index);

}
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
	//int result=0;
	init(sum);
	sum[0]=0;
	int tmp[NUM]={0};
#if 0
	int j;
	switch_to_big(tmp,1987);
	for(j=0;j<10;j++)
		printf("%d",tmp[10-j-1]);
	int out=switch_to_int(tmp);
	printf("switch to int %d\n",out);
#endif
	for(i=1;i<1001;i++){
	//for(i=1;i<11;i++){
		init(tmp);
		switch_to_big(tmp,i);
		cube(tmp,i);
		/**
		printf(" %d**%d = ",i,i);
		for(j=0;j<10;j++)
			printf("%d",tmp[10-j-1]);
		*/
		add(sum,tmp);
	}


#ifdef DEBUG
	for(i=0;i<NUM;i++)
		printf("%d",sum[NUM-i-1]);
#endif
	 
	printf("\n");
	return 0;
}
