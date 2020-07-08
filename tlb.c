#include<sys/time.h>
#include<stdio.h>
#include <stdlib.h>

#define PAGESIZE 4096

int main(int argc,char **argv){
	if(argc!=3)
	{
		printf("Too few arguments!\n");
		exit(0);
	}

	int jump = PAGESIZE / sizeof(int);
	int NUMPAGES = (int)strtol(argv[1],NULL,10);
	int trials = (int)strtol(argv[2],NULL,10);
	int iteration = NUMPAGES * jump;
	int *a=(int *)calloc(iteration,sizeof(int));
	struct timeval begin, end;

	//preprocess
	for(int j=0;j<iteration;j+=jump){
			a[j]+=1;
	}

	gettimeofday(&begin,NULL);

	for(int i=0;i<trials;i++){
		for(int j=0;j<iteration;j+=jump){
			a[j]+=1;
		}
	}

	gettimeofday(&end,NULL);

	long gap=1000000 * (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec);
	printf("Gap(ns): %.3f\n",gap / 1000.0);
	return 0;
}