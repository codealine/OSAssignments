
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	
	char buf[100];
	getcwd(buf,100);
	printf("%s\n",buf);
	chdir("/home");
	getcwd(buf,100);
	printf("%s\n",buf);
	return 0;
}
