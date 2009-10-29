/*
 * =====================================================================================
 *
 *       Filename:  007-ivenvd.c
 *
 *    Description:  Find the 10001st prime.
 *
 *        Version:  1.0
 *        Created:  2009年10月28日 18时46分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 
#include	<math.h>

#define	COUNT 10001			/*  */

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
    int i, n = 5, cnt = 3;
    int prime[COUNT] = {2, 3, 5};               /* 质数库 */
    while (n += 2) {                            /* 从 7 开始验证 */
        if (n % 5 == 0) {
            continue;
        }
        is_prime = 1;
        for (i = 0; prime[i] <= sqrt(n); i++) {
            if (n % prime[i] == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {                         /* 是质数 */
            prime[cnt++] = n;                   /* 存入质数库 */
            if (cnt == COUNT) {
                break;
            }
        }
    }
    printf ("%d\n", n);

	return 0;
}		/* ----------  end of function main  ---------- */

