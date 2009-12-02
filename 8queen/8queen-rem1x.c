#include <stdio.h>
#include <stdlib.h>

#define QUEENS 8

int chess[QUEENS];
int count=0;

void result() {
    int i;
    for (i = 0; i < QUEENS; i++) {
        printf("%d",chess[i]);
    }
    printf("\n");
}

int check(int n) {
    int i;
    //当前列放置的棋子与前n-1个棋子在行上或对角线上是否重叠
    for (i = 0; i < n; i++) {
        if(chess[i] == chess[n] || abs(chess[i]-chess[n])==abs(i-n))
            return 1;
    }
    return 0;
}

void queen(int n){
    int i;
    if (n==QUEENS) {
        //result();
        count++;
        return;
    }

    for (i = 1; i <= QUEENS; i++) {
        chess[n] = i;
        if (!check(n))
            queen(n+1);
    }
}

int main(int argc, char **argv) {
    queen(0);
    printf("解法:%d\n",count);
    return 0;
}
