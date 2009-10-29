/*
 * =====================================================================================
 *
 *       Filename:  023-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月29日 20时04分26秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>

#define LIMIT 28123

int buf[LIMIT]={0};
int count=0;
/** 检测是不是过剩数
 * 是返回1，
 * 否返回0
 */
int guoshen(int num)
{
	int m=sqrt(num)+1;
	int i;
	int sum=1;
	for(i=2;i<m;i++){
		if(num%i==0){
			if(i!=num/i)
				sum+=(i+num/i);
			else
				sum+=i;
		}
	}

	return sum>num?1:0;


}

/** 过滤num是否是两个过剩数之和
 * 是返回1
 * 否返回0
 */
int foo(int num)
{
	int i;
	int j;
	int flag=0;

	for(i=0;i<count;i++){
		if(num<buf[i])
			return flag;
		int out=num-buf[i];
		for(j=0;j<count;j++)
			if(buf[j]==out){
				flag=1;
				return flag;
			}
	}

	return flag;

}

int main(int argc,char *argv[])
{
 
	int i;

	int sum=0;

	for(i=1;i<=LIMIT;i++){
		if(guoshen(i))
			buf[count++]=i;
	}
	for(i=1;i<=LIMIT;i++){
		if(!foo(i))
			sum+=i;
	}
	printf("%d\n",sum);


	    return 0;
}


