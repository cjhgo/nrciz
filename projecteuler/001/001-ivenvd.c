/*
 * =====================================================================================
 *
 *       Filename:  001-ivenvd.c
 *
 *    Description:  Add all the natural numbers below one thousand that are multiples of 3 or 5.
 *
 *        Version:  1.0
 *        Created:  2009年10月26日 23时21分44秒
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

#define	SUM(start, end) ((start + end) * end / start / 2)			/*  */

	int
main (int argc, char *argv[])
{
	printf ("sum is: %d\n", SUM(5, 995) + SUM(3, 999) - SUM(15, 990));

	return 0;
}		/* ----------  end of function main  ---------- */

