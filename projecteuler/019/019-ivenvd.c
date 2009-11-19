/*
 * =====================================================================================
 *
 *       Filename:  019-ivenvd.c
 *
 *    Description:  How many Sundays fell on the first of the month during the twentieth century?
 *
 *        Version:  1.0
 *        Created:  2009年11月18日 13时49分30秒
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
get_days (int year, int month)
{
    switch (month) {
        case 4:	
        case 6:	
        case 9:	
        case 11:	
            return 30;
        case 2:	
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                return 29;
            } else {
                return 28;
            }
        default:	
            return 31;
    }				/* -----  end switch  ----- */
}		/* -----  end of static function get_days  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int y, m, d = 1, n = 0;
    for (y = 1900; y < 2001; y++) {
        for (m = 1; m < 13; m++) {
            printf ("%d ", d);
            if (y > 1900 && d == 0) {
                n++;
            }
            d += get_days (y, m);
            d %= 7;
        }
    }
    printf ("%d\n", n);
	return 0;
}		/* ----------  end of function main  ---------- */

