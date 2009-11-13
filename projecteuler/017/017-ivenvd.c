/*
 * =====================================================================================
 *
 *       Filename:  017-ivenvd.c
 *
 *    Description:  How many letters would be needed to write all the numbers in words from 1 to 1000?
 *
 *        Version:  1.0
 *        Created:  2009年11月11日 15时46分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 

int num_0_1_9[]   = {-10, 3, 3, 5, 4, 4, 3, 5, 5, 4, 0};
int num_10_19[]   = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int num_0_20_90[] = {0, 6, 6, 5, 5, 5, 7, 6, 6};
int num_hundred   = 7;
int num_and       = 3;
int num_thousand  = 8;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int i, j, k, sum = 0;
    for (i = 0; i < 10; i++) {
        // 十位是 1 的情况
        for (j = 0; j < 10; j++) {
            sum += num_0_1_9[i] + num_hundred + num_and + num_10_19[j];
        }
        // 其他大部份数
        for (j = 0; j < 9; j++) {
            for (k = 1; k < 11; k++) {
                sum += num_0_1_9[i] + num_hundred + num_and + num_0_20_90[j] + num_0_1_9[k];
            }
        }
        // 个位和十位同时是零，去除 and
        if (i != 0) {
            sum -= num_and;
        }
    }
    // 加上“一千”
    sum += num_0_1_9[1] + num_thousand;

    printf ("%d\n", sum);
	return 0;
}		/* ----------  end of function main  ---------- */

