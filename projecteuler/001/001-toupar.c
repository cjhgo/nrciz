#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[1])
{
	int i,n;
	long sum;
	sum=0;

	sscanf(argv[1], "%d", &n);
	
	for(i=3;i<n;++i)
	{
		if(!(i%3)||!(i%5))
		{
			sum+=i;
		}
	}
	printf("小于%d的约数含3或5的所有的自然数和为:%d\n",n,sum);

}
