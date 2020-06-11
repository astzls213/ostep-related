#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int rc=fork();
	if(rc<0)
		exit(1);
	else if(rc==0){
		close(STDOUT_FILENO);
		printf("what happens...\n");//doesnt output to screen.
	}
	else{
		int rc_wait=wait(NULL);
	}
	return 0;
}