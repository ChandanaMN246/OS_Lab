//Implement a producer consumer chain using simple mechanisms for protecting the buffer using linked list data structure. 
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int mutex = 1;
int full = 0;
int empty = MAX,x=0;

int producer(){
    --mutex;
    ++full;
    --empty;
    x++;    
    printf("produced %d\n", x);
    ++mutex;
    return x;
}

int consumer(){
    --mutex;
    --full;
    ++empty;
    printf("consumed %d\n", x);
    x--;
    ++mutex;
    return x;
}
struct node
{
  int data;
  struct node *next;
};

int main()
{
   
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* forth = NULL;
    
    for(int i=0;i<=MAX;i++)
    {   
        if(mutex == 1 && empty != 0)
        {
          head = (struct node*)malloc(sizeof(struct node));
          second = (struct node*)malloc(sizeof(struct node));
          third = (struct node*)malloc(sizeof(struct node));
          forth= (struct node*)malloc(sizeof(struct node));
          head->data = producer();
          head->next = second;
          second->data = producer();
          second->next = third;
          third->data = consumer();
          third->next = forth;
          forth->data = producer();
          forth->next = NULL;
         }

         else
            printf("Buffer is Full\n");
            n++;
    }
}
