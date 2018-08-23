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
