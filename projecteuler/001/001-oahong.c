#include <stdio.h>
#define MAXNUM 1000

/*
  http://projecteuler.net/index.php?section=problems&id=1
  If we list all the natural numbers below 10 that are multiples of 3 or 5,
  we get 3, 5, 6 and 9. The sum of these multiples is 23.
  Find the sum of all the multiples of 3 or 5 below 1000.
 */

int main(void) {
  int n = 3, m=0;
  do {
    // 如果可以被3和5同时整除，不要重复＋了;
    if( n%3 == 0 )
      m+=n;
    else 
      if( n%5 == 0 )
	m+=n;
    n++;
  } while ( n < MAXNUM );
  
  printf("答案是： %d", m);
  return 0;
}
