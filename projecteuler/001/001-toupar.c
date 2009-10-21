#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[1])
{
	long sum,n,i;
	sum=0;
	
	while(argc!=2)
	{
		fprintf(stderr,"本程序需一个参数，格式如下:\n%s 参数\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	sscanf(argv[1], "%ld", &n);
	
	for(i=3;i<n;++i)
	{
		if(!(i%3)||!(i%5))
		{
			sum+=i;
		}
	}
	printf("小于%ld的数中约数含3或5的所有的数和为:%ld\n",n,sum);
	return 0;

}
