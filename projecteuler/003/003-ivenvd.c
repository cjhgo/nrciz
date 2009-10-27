/*
 * =====================================================================================
 *
 *       Filename:  003-ivenvd.c
 *
 *    Description:  Find the largest prime factor of a composite number.
 *
 *        Version:  1.0
 *        Created:  2009年10月27日 10时29分05秒
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

#define	NUM 600851475143			/*  */

    static int
check_prime (long num)
{
    int i;
    static char flag = 0;                           /* 嵌套标志 */
    for (i = sqrt (num); i > 1; i--) {
        switch (i % 10) {
            case 1:	
            case 3:	
            case 7:	
            case 9:	
                if (num % i == 0) {
                    if (flag) {
                        flag = 0;
                        return 0;               /* 因子为和数 */
                    } else {
                        flag = 1;
                        if (check_prime (i)) {
                            return i;
                        }
                    }
                }
                break;
            default:	
                break;
        }				/* -----  end switch  ----- */
    }
    flag = 0;
    return 1;
}		/* -----  end of static function check_prime  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int factor = check_prime (NUM);
    if (factor == 1) {
        printf ("The number %ld is prime.\n", NUM, factor);
    } else {
        printf ("The largest prime factor of %ld is %d.\n", NUM, factor);
    }

	return 0;
}		/* ----------  end of function main  ---------- */

