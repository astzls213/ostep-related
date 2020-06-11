#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	for(int i=0;i<10;i++){
		int rc=fork();
		if(rc < 0){
			printf("Error\n");
			exit(1);
		}
		else if(rc == 0){
			printf("Child Process%d's PID: %d\n",i,getpid());
			exit(0);
		}
		else{
			wait(NULL);
		}
	}
	return 0;
}