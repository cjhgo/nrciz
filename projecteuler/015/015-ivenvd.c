/*
 * =====================================================================================
 *
 *       Filename:  015-ivenvd.c
 *
 *    Description:  Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?
 *
 *        Version:  1.0
 *        Created:  2009年11月08日 03时27分24秒
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
    /*-----------------------------------------------------------------------------
     *  排列组合问题 C^20_40 = 21*22*...*40/(1*2*...*20)
     *-----------------------------------------------------------------------------*/
	printf ("%ld\n", (long) 23 * 29 * 31 * 33 * 35 * 37 * 39 * 4);

	return 0;
}		/* ----------  end of function main  ---------- */

