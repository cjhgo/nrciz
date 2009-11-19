/*
 * =====================================================================================
 *
 *       Filename:  010-ivenvd.c
 *
 *    Description:  Calculate the sum of all the primes below two million.
 *
 *        Version:  1.0
 *        Created:  2009年10月31日 03时37分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

#define	MAX 2000000			/*  */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    char is_prime;
    register int i, n, cnt = 3;
    int prime[MAX / 2] = {2, 3, 5};               /* 质数库 */
    unsigned long sum = 10;
    for (n = 7; n < MAX; n += 2) {              /* 从 7 开始验证 */
        if (n % 5 == 0) {
            continue;
        }
        is_prime = 1;
        for (i = 0; prime[i] * prime[i] <= n; i++) {
            if (n % prime[i] == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            prime[cnt++] = n;                   /* 存入质数库 */
            sum += n;
        }
    }
    printf ("%ld\n", sum);

	return 0;
}		/* ----------  end of function main  ---------- */

