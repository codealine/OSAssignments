
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
	int c=1;
	char user[1000],p[1000];
	int pass;
	int result;
	int pid;
	while(c<=3)
	{
		printf("Enter username: ");
		
		scanf("%s",user);
		strcpy(p,getpass("Enter password: "));
		pid = fork();
		if(pid==0)
		{
			if(execl("./db","db",user,p,(char*)NULL)==-1);
			perror("Server failed");
		}
		else if(pid>0)
		{
			waitpid(pid,&result,0);
			int b = WEXITSTATUS(result);
			if(b == 1)
			{	printf("Access granted!\n");
				char s[100],d[100];
				printf("Enter address: ");
				strcpy(d,"google-chrome ");
				scanf("%s",s);
				strcat(d,s);
				system(d);
				c=10;
			}	
			else
				c++;
		}
	}
	if(c==3)
		printf("Maximum number of tries reached\n");
	return 0;
}	
		
	
