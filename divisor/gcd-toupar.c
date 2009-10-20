#include<stdio.h>
#include<stdlib.h>

int gcd(int i,int j)
{
	int k;
	k=0;
	while(j!=0)
	{
		k=j;
		j=i%j;
		i=k;
		gcd(i,j);
	}
	return i;
}
int main(int argc,char *argv[1])
{
	int n1, n2, n3;

	if(argc != 3) 
	{
		fprintf(stderr, "该程序需要两个参数才能正常运行,格式如下:\n");
		fprintf(stderr, "%s 参数1 参数2\n", argv[0]);
		exit(EXIT_FAILURE);
	}  

	// 参数 str -> int
   sscanf(argv[1], "%d", &n1);
   sscanf(argv[2], "%d", &n2);

   n3 = gcd(n1, n2);
   //#ifdef DEBUG
   //printf("%d\t%d\t%d\n", n1, n2, n3);
   //#endif
   printf("%d 和 %d 的最大公约数为: %d\n", n1, n2, n3);
   exit(EXIT_SUCCESS);
}
