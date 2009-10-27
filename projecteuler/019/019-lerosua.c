/*
 * =====================================================================================
 *
 *       Filename:  019-lerosua.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月27日 14时17分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

/**
已知1900年一月一日是星期一，求从1901.1.1到2000.12.31这段时间，既是星期天又是一个月的第一天的日子有多少天？
*/

#include <stdio.h>

int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int week[7]={0,0,0,0,0,0,1};
int week_flag=0;
int counter=0;
int main(int argc, char *argv[])
{

	int year;
	int day=0;
	int leap=0;
	int i;
	for(year=1900;year<2001;year++)
	{
		if(year%4==0 || (year%100==0 && year%400==0))
			leap=1;
		else
			leap=0;
		
		for(i=0;i<12;i++){
			for(day=0;day<mon[i];day++){
				
				if(year>1900 && week[week_flag]==1 && day==0)
					counter++;
				week_flag++;
				if(week_flag>6)
					week_flag=week_flag-7;
				
				if(i==1 && day==27){
					week_flag=week_flag+leap;
					if(week_flag>6)
						week_flag=week_flag-7;

				}

			}


		}




	}

 

	printf("%d\n",counter);
	return 0;
}
