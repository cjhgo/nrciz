/*
 * =====================================================================================
 *
 *       Filename:  004-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 14时04分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

int loop_three(int num)
{

	int i=0;
	for(i=100;i<1000;i++)
		if(num%i==0){
			int out=num/i;
			if(out>100&&out<1000){
				//printf("i=%d\n",i);
				return 1;
			}
		}
	return 0;


}


int main(int argc, char *argv[])
{
 
	int i=1;
	int j=0;
	int k=0;
	int sum=0;
	int count=0;
	int out;

	//printf("回环数: ");
	for(i=9;i>0;i--)
		for(j=9;j>=0;j--)
			for(k=9;k>=0;k--){
				sum = (i*100+j*10+k)*1000+k*100+j*10+i;
				if(loop_three(sum)==1){
					out=sum;
					//break;
					goto result;
				}
				count++;
				//printf(" %d ",sum);
			}
	//printf("共有%d个",count);
result:
	printf(" %d ",out);
	printf("\n\n");

	return 0;
}
