#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

#define BUFFSIZE 4096
#define COPYMODE 0644

void oop(char *s1,char *s2);

int main(int ac,char **av){
	char buff[BUFFSIZE];
	int sFd,tFd,numRead;

	if(ac!=3){
		printf("error in usage!");
		return 1;
	}

	if((sFd=open(*++av,O_RDONLY))<0){
		oop("can't open",*av);
		return 1;
	}

	if((tFd=creat(*++av,COPYMODE))<0){
		oop("can't creat",*av);
		return 1;
	}

	while((numRead=read(sFd,buff,BUFFSIZE))>0){
		if(numRead!=write(tFd,buff,numRead)){
			oop("can't write to",*av);
			return 1;
		}
	}
	close(sFd);
	close(tFd);

	return 0;
}

void oop(char *s1,char *s2){
	perror("Error:");
	perror(s1);
	perror(s2);
	
}
