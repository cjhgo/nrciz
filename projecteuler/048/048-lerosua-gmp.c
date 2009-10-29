/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月29日 18时30分04秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <gmp.h>

/**
 * 此处用的是gmp的大数暴力求法
 * 编译时要加gmp库，gcc xxx.c -lgmp
 */
#define MAX 1000
int main(int argc,char *argv[])
{
	int i;
	  mpz_t res;
	  mpz_t res_src;
	  mpz_t sum;
	  mpz_t div;

          mpz_init (res);
	  mpz_init (sum);
	  mpz_init (res_src);
	  mpz_init_set_str(div,"10000000000",10);

	  //mpz_init_set_ui(res_src,2);
	  //mpz_pow_ui (res, res_src,3);

	  //mpz_out_str (stdout, 10, res);

/** 由于求的是最后10位数，1000**1000  这个数后面全是0,不求也罢*/
	  for(i=1;i<MAX;i++){
		  mpz_init (res);
		  mpz_init_set_ui(res_src,i);
		  mpz_pow_ui (res, res_src,i);
		  mpz_add(sum,sum,res);
		  mpz_mod(sum,sum,div);
	  }
	  mpz_out_str (stdout, 10, sum);
	  printf("\n");

	    return 0;
}

