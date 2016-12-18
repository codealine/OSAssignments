#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
double arr1[1000][1000];
double arr2[1000][1000];
int r1,c1,r2,c2,t;
double res[1000][1000];
int row[1000];
int st[1000];
void *thread_fn(void *arg){
	int n= *(int*)(arg);
	int i,j,k;
	for(i = st[n];i<st[n]+row[n];i++)
	{
		for(j = 0;j < c2;j++)
		{	res[i][j]=0;
			for(k = 0;k < r2;k++)
			{
				res[i][j]+=arr1[i][k]*arr2[k][j];
			}
		
		}
	}
}
			
	


int main(int argc,char* argv[])
{	

	t = atoi(argv[3]);
	//r=4;
	//	c=4;
	pthread_t th[t];
		
	
	int i,j;
	FILE* fp;
	fp=fopen(argv[1],"r");
	fscanf(fp,"%d %d",&r1,&c1);
	
	for( i = 0;i < r1;i++)
	{	
		for( j = 0 ; j < c1; j++)
		{	
			fscanf(fp,"%lf",&arr1[i][j]);
		}
	}
	fclose(fp);
	for(i=0;i<t;i++)
	{
		row[i]=r1/t;
	}
	for(i=0;i<r1%t;i++)
	{
		row[i]++;
	}
	
	fp=fopen(argv[2],"r");
	fscanf(fp,"%d %d",&r2,&c2);
	for( i = 0;i < r2;i++)
	{
		for( j = 0 ; j < c2; j++)
		{	
			fscanf(fp,"%lf",&arr2[i][j]);
		}
	}	
	fclose(fp);

	for(i =0; i<t; i++)
	{st[i]=0;
		for(j=0;j<i;j++)
		{
			st[i]+=row[j];
		}
	printf("\t\t\t\tSt. Each: %d\n",st[i]);
	}
	int p[1000];
	for(i = 0; i < t; i++)
	{	
		p[i]=i;
		pthread_create(&th[i], NULL, thread_fn,(void*)&p[i]);
		}
	
	for(i = 0; i < t; i++)
		pthread_join(th[i],NULL);
//	printf("Result:\n");
//	for( i = 0;i < r1;i++)
	{
//		for( j = 0 ; j < c2; j++)
//			printf("%lf ",res[i][j]);
		printf("\n");			
	}


	return 0;
}





	
	
