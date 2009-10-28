/*
 * =====================================================================================
 *
 *       Filename:  006-ivenvd.c
 *
 *    Description:  What is the difference between the sum of the squares and the square of the sums?
 *
 *        Version:  1.0
 *        Created:  2009年10月28日 18时13分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

#define	NUM 100			/*  */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int m = (1 + NUM) * NUM / 2;
    int n = NUM * (NUM + 1) * (2 * NUM + 1) / 6;
    printf ("Result: %d\n", m * m - n);

	return 0;
}		/* ----------  end of function main  ---------- */

