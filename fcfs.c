#include<stdio.h>
int main(int argc,char** argv)
{
	char name[100][100];
	int at[100];
	int bt[100];
	int at1[100];
	int wt[100];

	FILE *fptr;
	fptr=fopen(argv[1],"r");
	
	int N;
	for(N=0;!feof(fptr);N++)
	{
		fscanf(fptr,"%s %d %d",name[N],&at[N],&bt[N]);
		if(name[N][0]=='x')
		break;
	}
	int i,j;
	for(i=0;i<N-1;i++)
	{	wt[i]=0;
		for(j=0;j<=i;j++)
		{
			at1[i]+=at[j];
		
			}
		printf("		%d\n",at1[i]);
	}
	printf("N: %d\n",N);	
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
		wt[i]-=at1[i];
	}
	int awt=0;
	for(i=0;i<N-1;i++){
	printf("%s	%d\n",name[i],wt[i]);
	awt+=wt[i];
	}
	printf("Avg: %d\n",awt/(N-1));
}
