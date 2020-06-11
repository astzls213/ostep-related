#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
        int rc=fork();
        if(rc<0)
                exit(0);
        else if(rc==0){
                char *myargs[3];
                myargs[0]="/bin/ls";
                myargs[1]="-l";
                myargs[2]=NULL;
                //execle("/bin/ls","ls","-l",NULL,NULL);
                //execl("/bin/ls","ls","-l",NULL);
                execve(myargs[0],myargs,NULL);
        }
        else{
                int rc_wait=wait(NULL);
        }
        return 0;
}