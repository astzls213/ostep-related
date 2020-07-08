#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char **argv){
	char *mem=NULL;
	if(argc==1){
		return 0;
	}
	else{
		mem=(char *)malloc(atoi(argv[1])*1024*1024);//allocated ?mb.
		printf("PID: %d\n", getpid());
		sleep(atoi(argv[2]));//sleeping.
		return 0;
	}
}
