/*
 * =====================================================================================
 *
 *       Filename:  005-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月21日 14时35分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>

/**这题解得不爽，用的是暴力破解方法，一个一个来求是不是能被1-20整除*/

/**看看是不是能被1－20整除,是就返回1 */
int find_de(long int sum)
{
	int i;
	int flag=1;
	for(i=2;i<=20;i++){
		if(sum%i==0)
			continue;
		else{
			return 0;
			}
	}

	return flag;
}
int main(int argc, char *argv[])
{
	long int i;

	
	for(i=2;i<=1000000000L;i+=2){
		if(find_de(i)==1){
			printf("out = %ld\n",i);
			return 0;
			}
	}
 


	return 0;
}

