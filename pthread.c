#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t sem;
void *pthread(void* t)
{	
	sem_wait(&sem);
	int a = *(int*)(t);
	for(;a<100;a++)
	{
		printf("%d\n",a);
	}
	sem_post(&sem);
}

int main()
{
	pthread_t t1,t2;
	sem_init(&sem,0,1);
	int a = 1;
	pthread_create(&t1,NULL,pthread,(void*)&a);
	pthread_create(&t2,NULL,pthread,(void*)&a);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
	
