/*
 * =====================================================================================
 *
 *       Filename:  016-ivenvd.c
 *
 *    Description:  What is the sum of the digits of the number 2^1000?
 *
 *        Version:  1.0
 *        Created:  2009年11月11日 14时14分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 
#include	<inttypes.h>

#define	MAX_NUM 1000000000			/*  */

    static void
mul (int32_t *a, int32_t b)
{
    int8_t i;
    int32_t tmp, carry = 0;
    for (i = 34; i >= 0; i--) {
        tmp = a[i] * b + carry;
        a[i] = tmp % MAX_NUM;
        carry = tmp / MAX_NUM;
    }
}		/* -----  end of static function mul  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int16_t i, j, sum;
    int32_t product[35];
    for (i = 0; i < 34; i++) {
        product[i] = 0;
    }
    product[34] = 1;
    for (i = 0; i < 1000; i++) {
        mul (product, 2);
    }
    for (i = 0; i < 35; i++) {
        for (j = 0; j < 10; j++) {
            sum += product[i] % 10;
            product[i] /= 10;
        }
    }
    printf ("%d\n", sum);
	return 0;
}		/* ----------  end of function main  ---------- */

