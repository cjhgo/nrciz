#include <stdio.h>
#include <stdint.h>

/*******************************************************

    @ File: 048-jyf.py
    @ Date: 2009-10-29
    @ Author: jyf
    @ Comment: This program is for ProjectEuler-048
    @ LICENSE: do what the fuck you want to do to it!

*******************************************************/
#define MAX 10000000000

int64_t sum10(int n);

int64_t sum10(int n){
    int64_t sum=1;
    int i;
    
    for(i=1;i<=n;i++){
        sum *=  n;
        sum = sum % MAX;
    }

    return sum;
}

int main(void){
    int64_t s=0;
    int i;
    
    for(i=1;i<=1000;i++){
        s += sum10(i);
        s = s % MAX;
    }
    printf("%lld\n",s);

    return 1;
}
