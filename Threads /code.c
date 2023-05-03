//program to create 2 dissimilar functions and create 4 threads , where each is operated alternately

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *myThread1(void *vargp)
{
  sleep(2);
  printf("Hello World\n");
  return NULL;
}
void *myThread2(void *vargp)
{
  sleep(2);
  printf("Byee World\n");
  return NULL;
}

int main()
{
    pthread_t thread_id1;
    pthread_create(&thread_id1, NULL, myThread1, NULL);
    pthread_join(thread_id1, NULL);

    pthread_t thread_id2;
    pthread_create(&thread_id2, NULL, myThread2, NULL);
    pthread_join(thread_id2, NULL);

    pthread_t thread_id3;
    pthread_create(&thread_id3, NULL, myThread1, NULL);
    pthread_join(thread_id3, NULL);

    pthread_t thread_id4;
    pthread_create(&thread_id4, NULL, myThread2, NULL);
    pthread_join(thread_id4, NULL);

    exit(0);

} 
