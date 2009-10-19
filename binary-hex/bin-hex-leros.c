/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月16日 09时09分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (3 != argc) {
		printf("用法\n %s 原数字 目标进制\n", argv[0]);
		return -1;
	}
	int obase = atoi(argv[1]);
	int code= atoi(argv[2]);

	int all=obase;
	int i=0;
	int j=0;

	int num[512]={0};

	do{
		num[i]=obase%code;
		//printf("num[%d]=%d\n",i,num[i]);
		obase=obase/code;
		if(obase==0)
			break;
		i++;
	}while(obase>0);
 
	printf(" %d in %d 进制数为 \n",all,code);
	for(j=i;j>=0;j--)
		printf("%d",num[j]);
	printf("\n\n");

	return 0;
}
