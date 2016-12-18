#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{	int p=-99;

	char user[10][100];
	char pass[10][100];
	strcpy(user[1],"raghav.rokr");
	strcpy(pass[1],"123");
	strcpy(user[2],"mommy");
	strcpy(pass[2],"456");
	if(strcmp(argv[1],user[1])==0)
	{
		if(strcmp(argv[2],pass[1])==0)
		p=1;
	}
	else
	if(strcmp(argv[1],user[2])==0)
	{
		if(strcmp(argv[2],pass[2])==0)
		p=1;
	}
	return p;
}

