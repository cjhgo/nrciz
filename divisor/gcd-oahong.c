#include <stdio.h>  //sscanf
#include <stdlib.h> //exit
//#define DEBUG 

/*
  http://zhidao.baidu.com/question/433388.html
  辗转相除法,求得最小公约数:
 */
int gcd(int i, int j)
{
  while((i != 0) && (j != 0)) {
    if(i > j)
      i = i%j;
    else
      j = j%i;
  }
  
  return i!=0?i:j;
}

int main(int argc, char * argv[1])
{
  int n1, n2, n3;

  if(argc != 3) {
    fprintf(stderr, "该程序需要两个参数才能正常运行,格式如下:\n");
    fprintf(stderr, "%s 参数1 参数2\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // 参数 str -> int
  sscanf(argv[1], "%d", &n1);
  sscanf(argv[2], "%d", &n2);

  n3 = gcd(n1, n2);
#ifdef DEBUG
  printf("%d\t%d\t%d\n", n1, n2, n3);
#endif
  printf("%d 和 %d 的最大公约数为: %d\n", n1, n2, n3);
  exit(EXIT_SUCCESS);
}
    
