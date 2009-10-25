/*
 * =====================================================================================
 *
 *       Filename:  bin-example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月25日 06时20分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dxhn (Shan), dxhnyn@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */
#include <stdio.h> 
#define BASE 8 //要转换成几进制数 
#define DIGIT 100 //转换数的位数 
int main(int argc,char *argv[]) 
{ 
int i,j,input; 
int x[DIGIT]; 
printf("Please enter(Enter q to quit) \n");
while(1==scanf("%d",&input)) 
{ 
for (i=0;0!=input;input/=BASE){
	x[i]=input%BASE;
	printf("%d",x[i]);
	i++;
	printf("i= %d ", i);}
for (;i>0;){
	printf(" %d ",x[i]);
	printf("i= %d",i);
	i--;}
}

return 0; 
} 


