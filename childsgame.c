#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/time.h>
#include<semaphore.h>
#include<sys/sem.h>
#define MAX_BUF 1024
sem_t sem1,sem2;
sem_t rd1,rd2;
int ran()
{
	struct timeval tm;
	unsigned long seed;
	gettimeofday(&tm,NULL);
	seed = tm.tv_sec + tm.tv_usec;
	srand48(seed);
	return (int)((10000000*drand48())/1);
}

int flag1,flag2;
int main()
{		int set;
		char* pipe1 = "/tmp/pipe1";
		char* pipe2 = "/tmp/pipe2";		
		char buf1[100];
		char buf2[100];
		int c=0,d=0;
		pid_t pid1,pid2;
		int i;
		if((pid1=fork())!=0)
		{
			if((pid2=fork())!=0)
			{	int cs=0;int ds=0;
				mkfifo(pipe1,0666);
				mkfifo(pipe2,0666);
				int count=0;
				while(1)
				{	set=ran()%2;
					int fd1,fd2;
					fd1=open(pipe1,O_RDONLY);
					read(fd1,buf1,MAX_BUF);
					close(fd1);
					sscanf(buf1,"%d",&c);
					printf("C read as: %d	",c);
					fd2=open(pipe2,O_RDONLY);
					read(fd2,buf2,MAX_BUF);
					close(fd2);
					sscanf(buf2,"%d",&d);
					printf("D read as: %d\n",d);

					if(set==0)
					{
						if(c>d)cs++;
						else ds++;
					}
					else
					{
						if(c>d)ds++;
						else cs++;
					}
					printf("Mode: %d\n",set);
					printf("Score of C: %d\nScore of D: %d\n",cs,ds);
					if(cs==10||ds==10)break;
				}
			printf("================================\nThe Winner is: ");
			if(cs>ds)
			{	
				printf("C!\n");
			}
			else
			if(cs<ds){
				printf("D!\n");
			}
			else
				printf("Both! It's a tie.\n");
			exit(0);
			}
			else
			{
				
				//mkfifo(pipe1,0666);
				char buf[100];
				int fd;
				int r;
				while(1)
				{
					r=ran();
					sprintf(buf,"%d",r);
					fd=open(pipe1,O_WRONLY);
					write(fd,buf,sizeof(buf));
					close(fd);
					printf("C wrote: %s\n",buf);
					
					
				}
			}
		}
		else
		{
			//mkfifo(pipe2,0666);
			char buf[100];
			int fd;
			int r;
			while(1)
			{
				r=ran();
				sprintf(buf,"%d",r);
				fd=open(pipe2,O_WRONLY);	

				write(fd,buf,sizeof(buf));
				close(fd);
				printf("	D wrote: %s\n",buf);
				sleep(1);
				
				}
		}

	return 0;
}		
								
			
				
					
					
					
				
