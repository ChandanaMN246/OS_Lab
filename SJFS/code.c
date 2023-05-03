//Write an algorithm for SJFS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int n;
struct node
{
  int process;
  int busttime;
  struct node *next;
}*head;

void sortList()
{ 
  struct node *current = head, *index = NULL; 
  int temp,t; 

  if(head == NULL)
  { 
    return; 
  } 
  else
  { 
    while(current != NULL)
    {
      index = current->next; 
      while(index != NULL)
      { 
        if(current->busttime > index->busttime)
        { 
        temp = current->busttime;
        t=current->process;
        current->busttime = index->busttime;
        current->process=index->process;
        index->busttime = temp; 
        index->process=t;
        } 
        index = index->next; 
      } 
      current = current->next; 
    } 
  } 
} 

int main()
{
  clock_t start,end;
  int p,b;
  int n;
  printf("enter the number of process:");
  scanf("%d",&n);
  struct node *newNode, *temp;
  head = (struct node *)malloc(sizeof(struct node));
  if(head == NULL)
  {
    printf("Unable to allocate memory.");
    exit(0);
  }
  printf("\nenter the process and bust time:");
  scanf("%d %d",&p,&b);
  head->process = p;
  head->busttime = b;
  head->next = NULL;
  temp = head;
  for(int i=2; i<=n; i++)
  {
    newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
      printf("Unable to allocate memory.");
      break;
    }
    start=clock();
    printf("\nenter the process and bust time:");
    scanf("%d %d",&p,&b);
    newNode->process = p;
    newNode->busttime = b;
    newNode->next = NULL;
    temp->next = newNode;
    temp = temp->next;
    end=clock();
    int wt=(end+temp->busttime)-start;
    printf("wait:%d\n",wt);
  }

  sortList();

  int wt=0,tat=0,wtotal=0,tatotal=0,prevbttime=0;

  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
  temp = head;
  int c=0;
  while(temp != NULL)
  {
    if (c>0)
    {
      wt=wt+prevbttime;
      wtotal=wtotal+wt;
    }
    tat=temp->busttime+wt;
    tatotal=tatotal+tat;
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d",temp->process,temp->busttime,wt,tat);
    prevbttime = temp->busttime;
    temp = temp->next;
    c++;
  }
}
