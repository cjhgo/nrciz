/*
 * =====================================================================================
 *
 *       Filename:  004-ivenvd.c
 *
 *    Description:  Find the largest palindrome made from the product of two 3-digit numbers.
 *
 *        Version:  1.0
 *        Created:  2009年10月27日 16时05分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

#define	JOIN(A, B, C) (A * 100 + B * 10 + C)			/*  */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int i, j, k, m, num;
    for (i = 9; i > 0; i--) {
        for (j = 9; j >= 0; j--) {
            for (k = 9; k >= 0; k--) {
                num = JOIN(i, j, k) * 1000 + JOIN(k, j, i);
                for (m = 999; m > 99; m--) {
                    if (num % m == 0 && num / m < 1000) {
                        goto result;
                    }
                }
            }
        }
    }
result:
    printf ("The largest palindrome is %d.\n", num);
	return 0;
}		/* ----------  end of function main  ---------- */

