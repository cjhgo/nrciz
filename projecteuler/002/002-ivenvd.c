/*
 * =====================================================================================
 *
 *       Filename:  002-ivenvd.c
 *
 *    Description:  Find the sum of all the even-valued terms in the Fibonacci sequence which do not exceed four million.
 *
 *        Version:  1.0
 *        Created:  2009年10月27日 10时02分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int a = 1, b = 2, c, sum = 0;
    while (b < 4000000) {
        sum += b;
        c = a;
        a = c + 2 * b;
        b = 2 * c + 3 * b;
    }
	printf ("sum = %d\n", sum);

	return 0;
}		/* ----------  end of function main  ---------- */

