#include "stdio.h"
#include "sys/type.h"
#include "unistd.h"
#include "time.h"
#include "utmp.h"
#include "string.h"
#include "fcntl.h"

int logoutTty(char *user){
	struct utmp curU;
	int fp;
	int len=sizeof(struct utmp)
	int rtnVal=-1;

	if((fp=open(UTMP_FILE,O_RDWR))==-1){
		return rtnVal;
	}

	while(read(fp,&curU,len)==len){
		if(strncmp(curU.ut_user,user,sizeof(curU.ut_user))==0){
			curU.ut_type=DEAD_PROCESS;
		}

		if(time(&curU.ut_time)!=-1){
			if(lseek(fp,-len,SEEK_CUR)!=-1){
				if(write(fp,&curU,len)==len){
					rtnVal=0;
				}
			}
		}
		break;
	}
	if(close(fp)==-1){
		rtnVal=-1
	}
	return rtnVal;
}
