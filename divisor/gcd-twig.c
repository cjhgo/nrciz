// =====================================================================================
// 
//       Filename:  gcd-twig.c
// 
//    Description:  gcd
// 
//        Version:  1.0
//        Created:  10/16/2009 20:15:30 PM
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  twig (yang), NRCIZ@googlegroups.com
// 
// =====================================================================================

#include<stdio.h>

int getgcd(int a, int b)
{
	int arr[256] = {0};//32位整数最多计算步数？
	int i=0;
	arr[0]=arr[1]=a;
	(a<b)?(arr[0]=b):(arr[1]=b);
	while (arr[++i])
		arr[i+1] = arr[i-1] % arr[i];
	return arr[--i];
}
int main(int argc,char* argv[])
{
	int s1=1,s2=1;
	printf("输入两个整数: ");
	scanf("%i %i",&s1,&s2);
	printf("gcd=%i\n",getgcd(s1,s2));
	return 0;
}
//vim:ft=c;st=4;sw=4;ts=4;
