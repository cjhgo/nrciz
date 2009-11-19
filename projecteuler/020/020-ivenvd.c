/*
 * =====================================================================================
 *
 *       Filename:  020-ivenvd.c
 *
 *    Description:  Find the sum of digits in 100!
 *
 *        Version:  1.0
 *        Created:  2009年11月19日 14时07分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

#include    <inttypes.h>

#define MAX_NUM 10000000          /*  */

    static void
mul (uint32_t *a, uint32_t b)
{
    int16_t i;
    uint32_t tmp, carry = 0;
    for (i = 29; i >= 0; i--) {
        tmp = a[i] * b + carry;
        a[i] = tmp % MAX_NUM;
        carry = tmp / MAX_NUM;
    }
}       /* -----  end of static function mul  ----- */

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
    uint32_t product[30];
    for (i = 0; i < 30; i++) {
        product[i] = 0;
    }
    product[29] = 1;
    for (i = 0; i < 100; i++) {
        mul (product, i + 1);
    }
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 8; j++) {
            sum += product[i] % 10;
            product[i] /= 10;
        }
    }
    printf ("%d\n", sum);
	return 0;
}		/* ----------  end of function main  ---------- */

