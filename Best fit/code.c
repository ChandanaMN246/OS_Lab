#include <stdio.h>
#define N 5

int p[N]={1,2,3,4,5};
int block_size[N]={300,50,200,350,70};
int process_size[N]={200,47,212,426,10};
int allocated[N];

int bestFit(int min[])
{
  int m=1000000,index=-1;
  for(int i=0; i<N; i++)
  {
    if(min[i]!=-1 && min[i]<m)
    {
      index=i;
      m=min[i];
    }
  }
  return index;
}

int minimumSpace(int size)
{
  int min[N];
  for(int i=0; i<N; i++)
  {
    if(block_size[i]>=size && allocated[i]==-1)
    {
      min[i]=block_size[i]-size;
    }
    else{
      min[i]=-1;
    }
  }
  return bestFit(min);
}

int main()
{
  int pos;
  for(int i=0; i<N; i++)
  {
      allocated[i]=-1;
  }
  for(int i=0; i<N; i++)
  {
    pos=minimumSpace(process_size[i]);
    allocated[pos]=p[i];
  }
  printf("BlockSize ProcessSize AllocatedProcess\n");
  for(int i=0; i<N; i++)
  {
    if(allocated[i]!=-1)
    {
      printf("%d\t%d\t%d\t\n",block_size[i],process_size[i],allocated[i]);
    }
    else{
      printf("%d\t%d\tNot Allocated\n",block_size[i],process_size[i]);
    }
  }
}
