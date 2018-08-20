#include "stdio.h"
#include "head.h"
#define PAGELINE 20
#define LINELEN 100
int doMore(FILE *);
int seeMore();

#if 1

int main(int ac,char **av){
	if(ac==1){
		printf("usage:more [filename]");
		return 1;
	}
	FILE *fp;
	fp=fopen(*++av,"r");
	if(fp==NULL){
		printf("error in main:can't open file %s\n",*av);
		return 2;
	}
	doMore(fp);
	fclose(fp);
	return 0;
}

#endif

int doMore(FILE *fp){
	if(fp==NULL){
		printf("error in doMore:nothing to do!\n");
		return 1;
	}
	char line[LINELEN];
	int numOfLine=0;
	while(fgets(line,LINELEN,fp)){
		int repeat;
		if(numOfLine==PAGELINE){
			repeat=seeMore();
		}
		if(repeat){
			numOfLine-=repeat;
		}else{
			return 0;
		}
		if(fputs(line,stdout)==EOF){
			return 1;
		}
		numOfLine++;
	}
//	putchar('v');
	return 0;
}

int seeMore(){
	return PAGELINE;
}
