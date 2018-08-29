#include "stdio.h"
#include "fcntl.h"
#include "sys/types.h"
#include "utmp.h"

#define NRECS 16
#define NULLUT ((struct utmp *)NULL)
#define UTSIZE (sizeof(struct utmp))

char utmpBuf[NRECS*UTSIZE];
int numRecs,curRec,fdUtmp=-1;

int utmpOpen(char *filename){
	if((fdUtmp=open(filename,O_RDONLY))==-1){
		perror(filename);
	}
	numRecs=curRec=0;
	return fdUtmp;
}

struct utmp *utmp_next(){
	struct utmp *recp;

	if(fdUtmp<0){
		return NULLUT;
	}
	if((numRecs==curRec)&&utmpReload()==0){
		return NULLUT;
	}

	recp=(struct utmp *)&utmpBuf[curRec*UTSIZE];
	curRec++;

	return recp;

}

int utmpReload(){
	int amtRd;
	amtRd=read(fdUtmp,utmpBuf,UTSIZE*NRECS);
	numRecs=amtRd/UTSIZE;
	curRec=0;
	return numRecs;
}

void utmpClose(void){
	if(fdUtmp!=-1){
		close(fdUtmp);
	}
}
