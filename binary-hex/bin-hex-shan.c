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
	     exit (1);}
}

void initstack(struct Stack *s);
{
s-> p = (int*)malloc(1024  sizeof(int));
s-> pend = p + 1024;
}

struct Stack{
       int *p;
       int *pend;
};

bool push (struct Stack *s, int var)
{
       if (s->p == s->pend)
	       return false;
       *(s->p)++ = var;
	       return true;
}

bool stackempty(struct Stack *s)
{
      return s->pend - s->p == 1024;
}

bool pop(struct Stack* s, int* var)
{
      s->p++;
      *var = *(s->p);
}

int main(int argc,char *argv[])
{
	if (4 != argc){
		printf ("\n 用法：%s 原数字 原进制 目标进制。\n", argv[0]);
		exit (1);}
int sbin = atoi(argv[2]);
int tbin = atoi(argv[3]);
int sum = strtol(argv[1],NULL,sbin);
char buf[256];
void initstack(int **p);

printf("sbin= %d,tbin= %d,sum= %d \n",sbin,tbin,sum);

if (sbin>tbin)
{
	initstack(S);
	while(sum)
       {
	   	push(S,sum%tbin);
		sum/=tbin;
	}
	while(!stackempty(S)){
	pop(S,e);
	buf = e;
	}
}
else
{
	initstack(S);
	while(sum){
		push(S,sum *= power(tbin,i));

	}
	while(!stackempty(S)){
	pop(S,e);
	buf = e;
	}
	printf("该程序只能大转小，请重新输入运行！ \n");
}

printf("%s 的 %s 进制数为 %s 。\n",argv[1],argv[3],buf);

return 0;
}

