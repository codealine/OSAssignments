#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define BUFFSIZE 80
#include<semaphore.h>
#include<sys/shm.h>
#include<semaphore.h>
int main()
{
	int fd[2];
	int n=0;
	int i;
	char line[BUFFSIZE];
	pipe(fd);
	int sm;
	sm = shmget(IPC_PRIVATE,sizeof(int),0777|IPC_CREAT);
	
	if(fork() == 0){
	close(fd[0]);
	int *b = (int*)shmat(sm,0,0);
	*b=1;
	while(1){
	while(*b==0);
	if(strcmp(line,"exit")==0)exit(0);
	printf("Enter input: ");
	scanf("%s",line);
	printf("Writing buffer to pipe..");
	write(fd[1],line,BUFFSIZE);
	printf("done\n");
	*b=0;
	//sleep(1);
	}}
	else {
	close(fd[1]);
	int* a = (int*)shmat(sm,0,0);
	
	while(1){
	printf("Waiting for input...");
	while(*a==1);
	read(fd[0],line,BUFFSIZE);
	printf("Got it: '%s'\n",line);
	if(strcmp(line,"exit")==0)
	{	printf("Exiting\n");
		exit(0);
	}
	*a=1;
}
}
}

	
