#include "stdio.h"
#include "head.h"
#define PAGELINE 20
#define LINELEN 100
int doMore(FILE *);
int seeMore();

#if 1

int main(int ac,char **av){
	if(ac==1){
		doMore(stdin);
		return 0;
//		printf("usage:more [filename]");
//		return 1;
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
		if(fputs(line,stdout)==EOF){
                        return 0;
                }
                numOfLine++;

		int repeat;
		if(numOfLine>=PAGELINE){
			repeat=seeMore();
		
		if(repeat){
			numOfLine-=repeat;
		}else{
			return 0;
		}
		}
//		if(fputs(line,stdout)==EOF){
//			return 0;
//		}
//		numOfLine++;
	}
//	putchar('v');
	return 0;
}

int seeMore(){
	FILE *cmd;
	cmd=fopen("/dev/tty","r");
	if(cmd==NULL){
		return PAGELINE;
	}
	printf("\033[7m ([q]:quit;[SPACE]:next page;[ENTER]:next line):\033[m");
	int c;
	while((c=getc(cmd))!=EOF){
	if(c=='q'){
		return 0;
	}
	if(c==' '){
//		putchar('\n');
		return PAGELINE;
	}
	if(c=='\n'){
		return 1;
	}
	}
	return PAGELINE;
}
