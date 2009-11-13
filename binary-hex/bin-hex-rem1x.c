# include <stdio.h> 
# include <stdlib.h>

char itoc(int v)
{
	if (v < 10)
		return v + '0';
	else if (v < 36)
		return v + 'A' - 10;
	else if (v < 62)
		return v + 'a' - 36;
	else {
		fprintf(stderr,"出错了\n");
		exit (1);
	}
}

int main(int argc, char* argv[]) 
{ 
    int i=0;
    int obase, tbase, onum;
    char tnum[512]={'\0'}; 
    
    if (4 != argc) {
        printf("用法: %s 原数字 原进制 目标进制\n", argv[0]);
        return -1;
    }
    obase = atoi(argv[2]);
    tbase = atoi(argv[3]);
    onum = strtol(argv[1], NULL, obase);
    
    for (i = 0; onum > 0; onum /= tbase) {
        tnum[i++] = itoc(onum % tbase);
    }
    for (; i > 0;)
        printf("%c", tnum[--i]); 
    printf("\n");
    return 0; 
} 

