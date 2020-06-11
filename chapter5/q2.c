#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	int rc=fork();
	if(rc<0)
		exit(1);
	else if(rc==0){
		int file1=open("./text",O_WRONLY);
		write(file1,"Mac is a shit!",14);
		close(file1);
		printf("fork: %d",file1);
	}
	else{
		int rc_wait=wait(NULL);
		int file2=open("./text",O_WRONLY);
		write(file2,"Linux is a shit!",16);
		close(file2);
		printf("main: %d",file2);
	}
	return 0;
}
