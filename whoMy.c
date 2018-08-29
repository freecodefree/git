#include "stdio.h"
#include "stdlib.h"
#include "utmp.h"
#include "fcntl.h"
#include "unistd.h"
int showInfo(struct utmp *);

#if 1
int main(){
	struct utmp currentRecord;
	int fpUtmp;
	int utmpSize=sizeof(currentRecord);

	fpUtmp=open(UTMP_FILE,O_RDONLY);
	if(fpUtmp==-1){
		perror(UTMP_FILE);
		exit(1);
	}
	while(read(fpUtmp,&currentRecord,utmpSize)==utmpSize){
		showInfo(&currentRecord);
	}
	close(fpUtmp);
	return 0;

}
#endif

#if 1
int main(){
	struct utmp * ut;

	if(utmpOpen(UTMP_FILE)==-1){
		perror(UTMP_FILE);
		return 1;
	}

	while((ut=utmpNext())!=(struct utmp *)NULL){
		showInfo(ut);
	}
	utmpClose();
	return 0;
}
#endif

int showInfo(struct utmp *up){
	putchar('v');
	return 0;
}
