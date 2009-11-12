/*
 * =====================================================================================
 *
 *       Filename:  gcd-shan.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年10月17日 21时46分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dxhn (Shan), dxhnyn@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getTime(char *time_str,int timezone)
{
	int clock;
	char c=:,t[1]='0';
	colck = strchr(time_str,c);
	colck = colck-2;
	strncpy(t1,time_str+colck,2);
	int timet = atoi(t1);
	int ntime = timet + timezone;
	if (ntime >=24) 
		ntime-=24;
	return ntime;

}
