/*
 * =====================================================================================
 *
 *       Filename:  gcd-shan.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月17日 21时46分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dxhn (Shan), dxhnyn@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char itoc(int v)
{
	if (v < 10)
	        return v + '0';
	else if (v < 36)
	        return v + 'A' - 10;
	else if (v < 62)
	        return v + 'a' - 36;
	else {
	        fprintf(stderr,"出错了\n");
	        exit (1);
	}
}

struct Stack{
	int *p;
	int *pend;
};

void initstack(struct Stack *s)
{
	s->p = (int*)malloc(1024 *  sizeof(int));
	s->pend = s->p + 1024;
}

int push (struct Stack *s, int var)
{
	if (s->p == s->pend)
		return 0;
	*(s->p)++ = var;
	return 1;
}

int stackempty(struct Stack *s)
{
	return s->pend - s->p == 1024;
}

void pop(struct Stack* s, int* var)
{
	s->p--;
	*var = *(s->p);
}

int main(int argc,char *argv[])
{
	if (4 != argc){
		printf ("\n 用法：%s 原数字 原进制 目标进制。\n", argv[0]);
		exit (1);
	}
		int sbin = atoi(argv[2]);
		int tbin = atoi(argv[3]);
		int sum = strtol(argv[1],NULL,sbin);
	if (sbin <= 0 || tbin <=0 || sum <=0){
		printf ("\n 请正确使用本程序，检查输入。\n");
		exit (1);
	}
		char buf[256];
		struct Stack S;
		//printf("sbin= %d,tbin= %d,sum= %d \n",sbin,tbin,sum);

		{
			initstack(&S);
			while(sum)
			{
				int c = sum % tbin;
				char x;
			        x = itoc(c);
				sum/=tbin;
				push(&S,x);
			}
			int j = 0;
			while (!stackempty(&S)){
				int e;
				pop(&S,&e);
				//buf[j] = e + '0';
				buf[j] = e ;
				j++;
			}
			buf[j] = 0;
		}

	printf("%s 进制数 %s 的 %s 进制为 %s 。\n",argv[2],argv[1],argv[3],buf);

	return 0;
}

