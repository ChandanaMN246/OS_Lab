//Use Peterson’s solution to protect the critical section in the above code using the IP and Boolean flag. 
#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>

int flag[2];
int turn;
int a;

void lock_init()
{
	flag[0] = flag[1] = 0;
	turn = 0;
}

void lock(int self)
{
	flag[self] = 1;
	turn = 1-self;
	while (flag[1-self]==1 && turn==1-self) ;
}

void unlock(int self)
{
	flag[self] = 0;
}

void* func1(void *s)
{
	int i = 0;
	int self = (int *)s;
	printf("Thread Entered: %d\n", self);

	lock(self);
	for (i=0; i<=10000; i++)
		a++;

	unlock(self);
}
void* func2(void *s)
{
	int i = 0;
	int self = (int *)s;
	printf("Thread Entered: %d\n", self);

	lock(self);
	for (i=0; i<=10000; i++)
		a--;

	unlock(self);
}

int main()
{
	pthread_t p1, p2;
	lock_init();

	pthread_create(&p1, NULL, func1, (void*)0);
	pthread_create(&p2, NULL, func2, (void*)1);
	
	pthread_join(p1, NULL);
	printf("Actual Count: %d \n",a);
	pthread_join(p2, NULL);
	printf("Actual Count: %d \n",a);
	return 0;
}
