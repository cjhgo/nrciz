/*
 * =====================================================================================
 *
 *       Filename:  001-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月20日 18时22分06秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 *
 * =====================================================================================
 */

/**
 *
求小于1000的，能被3或5整除的，正整数之和
我的算法好傻，先用3的倍数相加，再用5的倍数相加，然后减去重叠的15的倍数

*/


#include <stdio.h>

int main(int argc,char *argv[])
{
	int thound=1000;
	int su1=3;
	int su2=5;
	int sum=0;
	int sum2=0;
	  printf("求%d 以下  %d  或 %d 的倍数的和\n",thound,su1,su2);

	int i;
	int add1=thound/su1;
	int add2=thound/su2;
	if( thound%su1==0)
		add1--;
	if( thound%su2==0)
		add2--;
	for(i=1;i<=add1;i++)
		sum +=i*su1;
	for(i=1;i<=add2;i++)
		sum+= i*su2;
	int su3=su1*su2;
	int add3=thound/su3;
	if( thound%su3==0)
		add3--;
	for(i=1;i<=add3;i++)
		sum -=i*su3;
	printf("结果是 %d\n",sum);
	
	/** 看了bones的code后才发现我傻啊*/
	for(i=1;i<1000;i++)
		sum2+=((i%3==0)||(i%5==0)?i:0);
	printf("结果是 %d\n",sum2);

	    return 0;
}
