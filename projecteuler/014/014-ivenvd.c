/*
 * =====================================================================================
 *
 *       Filename:  014-ivenvd.c
 *
 *    Description:  Find the longest sequence using a starting number under one million.
 *
 *        Version:  1.0
 *        Created:  2009年11月08日 02时26分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 
#include	<string.h>

#define	MAX_BUF 500000			/*  */
long buf[MAX_BUF];

    static int
cal (long n)
{
    if (n <= MAX_BUF) {
        if (buf[n - 1]) {
            ;
        } else if (n % 2) {
            buf[n - 1] = cal (n * 3 + 1) + 1;
        } else {
            buf[n - 1] = cal (n / 2) + 1;
        }
        return buf[n - 1];
    } else {
        if (n % 2) {
            return cal (n * 3 + 1) + 1;
        } else {
            return cal (n / 2) + 1;
        }
    }
}		/* -----  end of static function cal  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int i, length, max_length = 1, max_num;
    memset (buf, 0, MAX_BUF);
    buf[0] = 1;
    for (i = 0; i < 1000000; i++) {
        length = cal (i + 1);
        if (length > max_length) {
            max_length = length;
            max_num = i + 1;
        }
    }
    printf ("%d\n", max_num);

	return 0;
}		/* ----------  end of function main  ---------- */

