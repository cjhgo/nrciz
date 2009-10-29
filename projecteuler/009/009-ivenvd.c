/*
 * =====================================================================================
 *
 *       Filename:  009-ivenvd.c
 *
 *    Description:  Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.
 *
 *        Version:  1.0
 *        Created:  2009年10月28日 21时28分48秒
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

#define	SUM 1000			/*  */
#define	POW5(N) (N * N * N * N * N)			/*  */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int m, n;
    /*-----------------------------------------------------------------------------
     *  a = m * m - n * n
     *  b = 2 * m * n
     *  c = m * m + n * n
     *  m >= n
     *  a + b + c = 1000 = 2 * m * (m + n)
     *  => 2 * m * (m + 0) < 1000; 2 * m * (m + m) > 1000;
     *  a * b * c = 2 * (m ^ 5) * n - 2 * m * (n ^ 5)
     *
     *  From 009-narce.py
     *-----------------------------------------------------------------------------*/
    for (m = sqrt (SUM / 4) + 1; 2 * m * m < SUM; m++) {
        if (1000 / 2 % m == 0) {
            n = 1000 / 2 / m - m;
            break;
        }
    }
    printf ("%d\n", 2 * POW5(m) * n - 2 * m * POW5(n));

	return 0;
}		/* ----------  end of function main  ---------- */

