#include "stdio.h"
#include "head.h"

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
	putchar('v');
	return 0;
}
