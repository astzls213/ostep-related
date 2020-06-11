#include <stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
	int fd[2];
	int flag=pipe(fd);
	if(flag==-1)
		exit(0);

	int rc1=fork();
	if(rc1<0)
		exit(1);
	else if(rc1==0){
		//rc1 负责写东西
		close(fd[0]);
		char sth[]="Here is my gross dick, please suck with your warm mouth!";
		write(fd[1],sth,sizeof(sth));
		exit(0);
	}
	else{
		wait(NULL);
	}
	
	int rc2=fork();
	if(rc2<0)
		exit(1);
	else if(rc2==0){
		//rc2 负责读东西，并输出至屏幕。
		close(fd[1]);
		char buf[100];
		read(fd[0],buf,100);
		printf("%s\n",buf);
		exit(0);
	}
	else{
		wait(NULL);
	}
	return 0;
}