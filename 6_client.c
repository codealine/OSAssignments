#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(){
	char x[10], y[10], op[10], ch[10] = "y";
	int result, pid;
	while(strcmp(ch,"y") == 0 || strcmp(ch,"Y") == 0){	 
		printf("N1: ");
		gets(x);
		printf("N2: ");
		gets(y);
		printf("(+/-): ");
		gets(op); 
		
		pid = fork();
		if(pid == 0){
			if(execl("./server.out","server.out",x,y,op,(char*)NULL) == -1)
				perror("Server failed to start");
		}
		
		else if(pid>0){
			waitpid(pid,&result,0);
			printf("%d\n",WEXITSTATUS(result));
			printf("Continue (y/n)? ");
			gets(ch);
		}
	}
	printf("Client exited!\n");
	return 0;
}
