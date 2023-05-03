//Write an algorithm for FCFS 
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
int wt=0,tat,wtotal=0,tatotal=0,prevbttime = 0;

printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
temp = head;

int c=0;
while(temp != NULL )
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
int avgwt=wtotal/n;
printf("\naverage waiting time:%d",avgwt);

int avgtat=tatotal/n;
printf("\naverage turn around time:%d",avgtat);
}
