#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int rc=fork();
	if(rc<0)
		exit(0);
	else if(rc==0){
		int rc_wait = wait(NULL);
		printf("I'm child%d, my dad is %d\n",getpid(),rc_wait);
	}
	else{
		printf("I'm dad%d\n",getpid());
	}
	return 0;
}