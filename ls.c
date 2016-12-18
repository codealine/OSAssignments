#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
int main()
{
	DIR* dir;
	struct dirent* file;
        struct stat st;	
	dir = opendir("/");
	while((file=readdir(dir))>0)
	{
		stat(file->d_name,&st);
		printf("%20s %ld\n",file->d_name,st.st_blocks);
	}
	}	
