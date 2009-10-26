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
 *	在BOUNDXBOUND格的国际象棋上摆放八个皇后，使其不能互相攻击，
 *	即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define BOUND 8
#define START 3

/** 采用象棋中的棋盘结构，范围是从
 * board[3][3]     board[3][10]
 * board[10][3]    board[10]10]
 * 值的范围是
 * 0x33    0x3a
 * 0xa3    0xaa
 */
int board[16][16];

int counter=0;

/** queen 是皇后的位置
 *  enemy 是敌人的位置
 *  返回 敌人是否在皇后的攻击范围内
 *  1 则是，0表示不在
 */
int attack(int queen,int enemy)
{
	int q_x=queen&15;
	int q_y=queen>>4;
	int d_x=enemy&15;
	int d_y=enemy>>4;

	if( q_x  == (enemy&15))          /** 同一横线*/
		return 1;
	else if( q_y  == (enemy>>4))	/** 同一纵线*/
		return 1;
	else if( abs(q_x-d_x) == abs(q_y-d_y))   /** 同一斜线*/
		return 1;
	else 
		return 0;
}

void EQueen(int queen)
{
	int i,j;
	for(i=0;i<BOUND;i++)
		for(j=0;j<BOUND;j++){
			if(attack(queen,board[i+START][j+START]))
				counter++;
		}

}

int main(int argc, char *argv[])
{
	int i,j;

	for(i=0;i<16;i++)
		for(j=0;j<16;j++)
			board[i][j]=i+j;

	for(i=0;i<BOUND;i++)
		for(j=0;j<BOUND;j++){
			int queen_ = board[i+START][j+START];
			EQueen(queen_);
		}




 
	printf("%d\n",counter);
	return 0;
}
