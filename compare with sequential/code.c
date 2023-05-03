//Increase to large number of threads (say 20) and again compare with sequential. Is the gain % same as #4? Make inferences.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <time.h>

void *add1(void *vargp){
	int sum=0;
	for(int i=0; i<10; i++){
		sum=sum+i;
	}
	return NULL;
}


int main(){
	clock_t start, end;
	
	pthread_t thread_id1, thread_id2, thread_id3, thread_id4, thread_id5, thread_id6, thread_id7, thread_id8, thread_id9, thread_id10, thread_id11, thread_id12, thread_id13, thread_id14, thread_id15, thread_id16, thread_id17, thread_id18, thread_id19, thread_id20;
	
	double total;
		
	start = clock();
	
	pthread_create(&thread_id1, NULL, add1, NULL);
	pthread_join(thread_id1, NULL);
	printf("Thread 1 Executed\n");
	
	pthread_create(&thread_id2, NULL, add1, NULL);
	pthread_join(thread_id2, NULL);
	printf("Thread 2 Executed\n");
	
	pthread_create(&thread_id3, NULL, add1, NULL);
	pthread_join(thread_id3, NULL);
	printf("Thread 3 Executed\n");
	
	pthread_create(&thread_id4, NULL, add1, NULL);
	pthread_join(thread_id4, NULL);
	printf("Thread 4 Executed\n");
	
	pthread_create(&thread_id5, NULL, add1, NULL);
	pthread_join(thread_id5, NULL);
	printf("Thread 5 Executed\n");
	
	pthread_create(&thread_id6, NULL, add1, NULL);
	pthread_join(thread_id6, NULL);
	printf("Thread 6 Executed\n");
	
	pthread_create(&thread_id7, NULL, add1, NULL);
	pthread_join(thread_id7, NULL);
	printf("Thread 7 Executed\n");
	
	pthread_create(&thread_id8, NULL, add1, NULL);
	pthread_join(thread_id8, NULL);
	printf("Thread 8 Executed\n");
	
	pthread_create(&thread_id9, NULL, add1, NULL);
	pthread_join(thread_id9, NULL);
	printf("Thread 9 Executed\n");
	
	pthread_create(&thread_id10, NULL, add1, NULL);
	pthread_join(thread_id10, NULL);
	printf("Thread 10 Executed\n");
	
	pthread_create(&thread_id11, NULL, add1, NULL);
	pthread_join(thread_id11, NULL);
	printf("Thread 11 Executed\n");
	
	pthread_create(&thread_id12, NULL, add1, NULL);
	pthread_join(thread_id12, NULL);
	printf("Thread 12 Executed\n");
	
	pthread_create(&thread_id13, NULL, add1, NULL);
	pthread_join(thread_id13, NULL);
	printf("Thread 13 Executed\n");
	
	pthread_create(&thread_id14, NULL, add1, NULL);
	pthread_join(thread_id14, NULL);
	printf("Thread 14 Executed\n");
	
	pthread_create(&thread_id15, NULL, add1, NULL);
	pthread_join(thread_id15, NULL);
	printf("Thread 15 Executed\n");
	
	pthread_create(&thread_id16, NULL, add1, NULL);
	pthread_join(thread_id16, NULL);
	printf("Thread 16 Executed\n");
	
	pthread_create(&thread_id17, NULL, add1, NULL);
	pthread_join(thread_id17, NULL);
	printf("Thread 17 Executed\n");
	
	pthread_create(&thread_id18, NULL, add1, NULL);
	pthread_join(thread_id18, NULL);
	printf("Thread 18 Executed\n");
	
	pthread_create(&thread_id19, NULL, add1, NULL);
	pthread_join(thread_id19, NULL);
	printf("Thread 19 Executed\n");
	
	pthread_create(&thread_id20, NULL, add1, NULL);
	pthread_join(thread_id20, NULL);
	printf("Thread 20 Executed\n");
	
	end = clock();
	
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Execution time is %f\n", total);
	
	exit(0);
}
