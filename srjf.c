#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	FILE* fd;
	fd=fopen(argv[1],"r");
	char str[100][100];
	int a[100],b[100],wt[100];
	int c=0;
	int q[100];
	int flag;
	while(!feof(fd))
	{
		fscanf(fd,"%s %d %d",str[c],&a[c],&b[c]);
		c++;
	}
	printf("%d\n",c);
	c--;
	int i;
	q[0]=0;
	for(i=1;i<c;i++)
	{	wt[i]=0;
		a[i]+=a[i-1];
		printf("%d\n",a[i]);	
	}
	
	int time=0;
	int count=c;
	int current;
	int smallest=0;
	while(count!=0)
	{	flag=0;
		for(i=0;i<c;i++)
			if(b[i]>0 && a[i]<=time)
				smallest=i;
		for(i=0;i<c;i++)
		{	
			if(a[i]<=time && b[i]>0)
			{	flag=1;	
				q[i]=1;
				if( b[i] < b[smallest] )
				{
					smallest = i;
				}
				
			}
		}
		time++;
		if(flag==0) continue;
		
		b[smallest]--;
		for(i=0;i<c;i++)
		{
			if(i!=smallest && b[i]!=0)
				wt[i]++;
		}
		printf("Time: %d, Proc: %d, Time left: %d\n",time,smallest,b[smallest]);
		
		
		if(b[smallest]==0)
			count--;
	}
	double t=0;
	for(i=0;i<c;i++){
		wt[i]-=a[i];
		t+=wt[i];
		printf("Wait: %d\n",wt[i]);
}
	printf("Avg: %lf\n",t/c);
		}
				
