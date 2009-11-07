/*
 * =====================================================================================
 *
 *       Filename:  012-ivenvd.c
 *
 *    Description:  What is the value of the first triangle number to have over five hundred divisors?
 *
 *        Version:  1.0
 *        Created:  2009年11月07日 23时28分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

    static int
divisors (int sum)
{
    int i, count = 0;
    for (i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            count++;
            if (count >= 250) {
                if (i * i == sum) {
                    continue;
                }
                return 1;
            }
        }
        if (sum % 2) {
            i++;
        }
    }
    return 0;
}		/* -----  end of static function divisors  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int n = 2;
    while (n++) {
        if (divisors (n * (n + 1) / 2)) {
            break;
        }
    }
    printf ("%d\n", n * (n + 1) / 2);
	return 0;
}		/* ----------  end of function main  ---------- */

