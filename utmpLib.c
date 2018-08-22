#include "stdio.h"
#include "fcntl.h"
#include "sys/types.h"
#include "utmp.h"

#define NRECS 16
#define NULLUT ((struct utmp *)NULL)
#define UTSIZE (sizeof(struct utmp))

char utmpBuf[NRECS*UTSIZE];
int numRecs,curRec,fdUtmp=-1;

