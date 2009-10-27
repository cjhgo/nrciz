/*
 * =====================================================================================
 *
 *       Filename:  BOUNDqueen-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月26日 17时00分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 *	在8x8格的国际象棋上摆放八个皇后，使其不能互相攻击，
 *	即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define BOUND 8
#define XSTART 3
#define YSTART 3

/** 采用象棋中的棋盘结构，范围是从
 * board[4][3]     board[4][10]
 * board[11][3]    board[11]10]
 * 值的范围是
 * 0x33    0x3a
 * 0xa3    0xaa
 */
int board[16][16];

int counter=0;
/**8个皇后放置的位置*/
int qbuf[8]={0};

/** queen 是皇后的位置
 *  enemy 是敌人的位置
 *  返回 敌人是否在皇后的攻击范围内
 *  1 则是，0表示不在
 */
int attack(int queen,int enemy)
{
	int q_x=queen&0xf;
	int q_y=queen>>4;
	int d_x=enemy&0xf;
	int d_y=enemy>>4;

	if( q_x  == d_x)          /** 同一横线*/
		return 1;
	else if( q_y  == d_y)	/** 同一纵线*/
		return 1;
	else if( abs(q_x-d_x) == abs(q_y-d_y))   /** 同一斜线*/
		return 1;
	else 
		return 0;
}

/** queen 皇后的位置
 * 目前是第几个皇后
 */
void EQueen(int queen,int num)
{
	int i,j;
	int k;
	int count=num+1;
	for(i=0;i<BOUND;i++)
		for(j=0;j<BOUND;j++){
			int flag=1;
			for(k=0;k<count;k++)
				if(attack(qbuf[k],board[i+XSTART][j+YSTART]))
				{
					//printf("attack-%x   ",qbuf[k]);
					flag=0;
				}
			if(flag){
				qbuf[count++]=board[i+XSTART][j+YSTART];
			}
		}

	if(count>7){
		counter++;
		int m;
		for(m=0;m<BOUND;m++)
			printf(" %2x ",qbuf[m]);
		printf("\n");
	}

}
void jEQueen(int queen,int num)
{
	int i,j;
	int k;
	//int count=num+1;
	int count=num;

	


	for(i=0;i<BOUND;i++)
		for(j=0;j<BOUND;j++){
			int queen_ = board[i+XSTART][j+YSTART];
			//qbuf[count]=queen_;

			int flag=1;
			for(k=0;k<count;k++)
				if(attack(qbuf[k],board[i+XSTART][j+YSTART]))
				{
					//printf("attack-%x   ",qbuf[k]);
					flag=0;
				}
			if(flag){
				qbuf[count++]=board[i+XSTART][j+YSTART];
				//printf("qbuf[%d] = %2x ",count-1,qbuf[count-1]);
				if(count==BOUND){
					counter++;
					int m;
					for(m=0;m<BOUND;m++)
					printf(" %2x ",qbuf[m]);
					printf("\n");
					return;
				}
				//printf("attack-%x   ",qbuf[num]);
				jEQueen(queen_,count);
			}

		}
}
void dEQueen(int num)
{
	if(num==BOUND){
		counter++;
#ifdef DEBUG
		int m;
		for(m=0;m<BOUND;m++)
		printf(" %2x ",qbuf[m]);
		printf("\n");
#endif
		return;
	}

	int i,k;
	for(i=0;i<BOUND;i++){
		int queen_ = board[i+XSTART][num+YSTART];
		int flag=1;
		for(k=0;k<num;k++)
			if(attack(qbuf[k],queen_))
				flag=0;
		if(flag){
			qbuf[num]=queen_;
			//qbuf[num++]=queen_;
			//if(num==7)
			//	printf(" %2x ",qbuf[num-1]);
			dEQueen(num+1);
			//dEQueen(num);
		}
	}

}

int main(int argc, char *argv[])
{
	int i,j;
	//int k;

	for(i=0;i<16;i++){
		for(j=0;j<16;j++)
		{
			board[i][j]=i*16+j;
#ifdef DEBUG
			if(i>2&&i<11&& j>2&&j<11)
			printf( "%2x ",board[i][j]);
#endif
		}
#ifdef DEBUG
		printf("\n");
#endif
	}

	dEQueen(0);
#if 0
	for(i=0;i<BOUND;i++)
		for(j=0;j<BOUND;j++)
		{
			//for(k=0;k<BOUND;k++){
				int queen_ = board[i+XSTART][j+YSTART];
				qbuf[0]=queen_;
				//printf("qbuf[0] = %2x ",qbuf[0]);
				jEQueen(queen_,1);
			//}
		}

#endif
	

 
	printf("%d\n",counter);
	return 0;
}



