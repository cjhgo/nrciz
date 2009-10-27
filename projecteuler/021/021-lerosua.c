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


int qinghe(int num)
{
	int m =(int)sqrt(num)+1;
	int sum=1;

	int i;
	for(i=2;i<m;i++){
		if(num%i==0){
			sum+=i;
			/**防止加了完全平方数*/
			if(i != num/i)
				sum+=num/i;
		}
	}
	return sum;
}

int main(int argc, char *argv[])
{
 
	int i=0;
	int sum=0;
	int num=0;

	for(i=2;i<10000;i++){
		num=qinghe(i);
		if(i==qinghe(num)){
			/** 亲和数原来不包含自己*/
			if(i!=num)
				sum+=i;
			}
	}


	printf("%d\n",sum);

	return 0;
}
