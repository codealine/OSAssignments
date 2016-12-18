#include<stdio.h>
int main(int argc,char** argv)
{
	char name[100][100];
	int at[100]; // arrival time w.r.t prev proc
	int bt[100]; //burst time (execution time)
	int at1[100]; // absolute arrival time
	int wt[100]; // wait time
	int tat[100]; //turn around time
	int btc[100]; //burst time (copy)
	FILE *fptr;
	fptr=fopen(argv[1],"r");
	int time_elapsed=-1;
	int time_quantum;
	scanf("%d",&time_quantum);
	int N;
	for(N=0;!feof(fptr);N++)
	{
		fscanf(fptr,"%s %d %d",name[N],&at[N],&bt[N]);
		btc[N]=bt[N];
		if(name[N][0]=='x')
		break;
	}
	int i,j;
	for(i=0;i<N-1;i++)   //calculate absolute arrival time
	{
		for(j=0;j<=i;j++)
		{
			at1[i]+=at[j];
		}
	}
	printf("N: %d\n",N);	
	while(1)
	{
		int f=0;
		for(i=0;i<N-1;i++)   //check for non-positive burst times
		{	if(btc[i]>0)
			f=1;
		}
		if(f==0)	//break if all bt are 0
		break;
	
	time_elapsed++;
	/* We are choosing each process one-by-one in a circular (round robin) manner
	   and adding the execcution time ( <= time_quantum) to its turn-around time
	   meanwhile adding the same to the waiting time of all the other processes.
	   With each time a process is executed, the execution time is subtracted from 
	   its total burst time. */
	for(i=0;i<N-1;i++)
	{
		
		if(time_elapsed<at1[i])
		continue;
		for(j=0;j<N-1;j++)
		{
			if(i!=j)
			{	if(btc[j]!=0){
				if(btc[i]<time_quantum)	
					wt[j]+=btc[i];
				else
					wt[j]+=time_quantum;
					}
	           	}

          	}

		if(btc[i]==0)
			continue;
		else	
		if(btc[i]<time_quantum)
		{
			tat[i]+=btc[i];
			btc[i]=0;
			time_elapsed+=btc[i];
		}
		else{
			btc[i]-=time_quantum;
			tat[i]+=time_quantum;
			time_elapsed+=time_quantum;
		}
		
		
	}
}	
	
	int awt=0;
	for(i=0;i<N-1;i++){
	wt[i]-=at1[i];
	awt+=wt[i];
	printf("Name:%s 	Execution time:%d	Total wait:%d\n",name[i],tat[i],wt[i]);
	}
	printf("Average wait: %d\n",awt/(N-1));
}

