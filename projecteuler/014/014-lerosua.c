/*
 * =====================================================================================
 *
 *       Filename:  014-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月22日 11时52分33秒
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
inline int loop(int num)
{
	int count=0;

	while(1){

		if(num%2==0){
			num=num>>1;
		}else{
			num=num*3+1;
			count++;
#ifdef DEBUG
			printf(" --> %d ",num);
#endif
			continue;
		}
#ifdef DEBUG
		printf(" --> %d ",num);
#endif
		count++;
		if(num==1){
			//break;
#ifdef DEBUG
			printf("\n\n");
#endif
			return count;
		}

	}

}
unsigned long reloop(unsigned long num)
{
	if(num%2==0)
		return num>>1;
	else
		return num*3+1;
}
int main(int argc, char *argv[])
{

	//printf("%d \n",	loop(13));
	int start=13;
	int end=1000000;
//	int start=1;
//	int end=14;

	unsigned long i;
	unsigned long max=0;
	unsigned long mark=0;
	unsigned long out;
	for(i=start;i<end;i+=2){
		out=i;
		int count=0;
		while( (out = reloop(out))>1)
			count+=1;

		if(count>max){
			max=count;
			mark=i;
		}
	}

	printf(" %ld %ld\n",mark,max);



 
		printf("\n");
		return 0;
}
