/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年06月18日 14时46分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<stdio.h> 
#include	<stdlib.h>
#include	<string.h>

struct _ln {
    int sum;
    char str[10];
} names[6000];				/* ----------  end of struct ln  ---------- */
typedef struct _ln ln;

    static int
read_file ()
{
    int i = 0, j = 0 , sum = 0;
    char c;
    FILE *fp = fopen("names.txt", "r");
    while (fp != NULL && (c = fgetc(fp)) != EOF) {
        switch (c) {
            case '"':	
                if (j != 0) {
                    names[i].str[j] = 0;
                    names[i++].sum = sum;
                    j = 0;
                    sum = 0;
                }
                break;
            case ',':	
                break;
            default:	
                names[i].str[j++] = c;
                sum += c - 'A' + 1;
                break;
        }				/* -----  end switch  ----- */
    }
    fclose(fp);
    return i;
}		/* -----  end of static function read_file  ----- */

    static int
cmp_str (const void *a, const void *b)
{
    return strcmp(((ln *)a)->str, ((ln *)b)->str);
}		/* -----  end of static function cmp_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main (int argc, char *argv[])
{
    int i, count, sum = 0;
    count = read_file();
    qsort(names, count, sizeof(names[0]), cmp_str);
    for (i = 0; i < count; i++) {
        sum += names[i].sum * (i + 1);
    }
    printf("%d\n", sum);

	return 0;
}		/* ----------  end of function main  ---------- */

