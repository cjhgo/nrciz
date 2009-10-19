//#!/usr/bin/tcc -run
/**
    @File: gcd-jyf.c
    @Date: 2009-10-16
    @Author: jyf1987@gmail.com
    @Comment: This Program's target is to get the 
    @require: This program need a tinyCC as its interpreter
**/

#include <stdio.h>

int main(void){
    int bigger,smaller,lefter;

    bigger = 25;
    smaller = 15;

	printf("输入两个整数: ");
	scanf("%d %d",&bigger,&smaller);

    while( bigger % smaller ){
        bigger = bigger - smaller;
        
        if (bigger < smaller) {    
            bigger ^= smaller;
            smaller ^= bigger;
            bigger ^= smaller;
        }

    }

    printf("the result is %d \n", smaller);
    
    return 0;
}
