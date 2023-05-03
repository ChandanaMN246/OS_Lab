//Compare time taken to call function sequentially to calling in threads in above case 
//Hint: use clock() 

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
  clock_t start,start1, end,end1;
  double total;

  start1=clock();
  pthread_t thread_id1;
  start=clock();
  pthread_create(&thread_id1, NULL, myThread1, NULL);
  pthread_join(thread_id1, NULL);
  end = clock();
  total = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Execution time for first function is %f\n", total);

  pthread_t thread_id2;
  start=clock();
  pthread_create(&thread_id2, NULL, myThread2, NULL);
  pthread_join(thread_id2, NULL);
  end = clock();
  total = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Execution time for second function is %f\n", total);

  pthread_t thread_id3;
  start=clock();
  pthread_create(&thread_id3, NULL, myThread1, NULL);
  pthread_join(thread_id3, NULL);
  end = clock();
  total = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Execution time for first function is %f\n", total);

  pthread_t thread_id4;
  start=clock();
  pthread_create(&thread_id4, NULL, myThread2, NULL);
  pthread_join(thread_id4, NULL);
  end = clock();
  total = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Execution time for second function is %f\n", total);
  end1=clock();
  total = (double)(end1 - start1) / CLOCKS_PER_SEC;
  printf("Execution time for all 4 threads is %f\n", total);

  exit(0);
} 
