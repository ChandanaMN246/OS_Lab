//Write an algorithm to detect cycle in the graph. A cycle in a directed graph is a non-empty trail where first and last nodes are equal. 
#include<stdio.h>
int main()
{
    int arr[20][20];
    int m,n;
    printf("enter the dimensions:");
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        printf("%d: ",i);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    int sum=0,flag=0;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            sum=sum+arr[i][j];
        }
        if(sum==m-2 && sum==n-2)
        {
            flag=1;
            sum=0;
            continue;
        }
        else
        {
            flag=0;
            printf("no cycles\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("graph has cycles\n");
    }
}
