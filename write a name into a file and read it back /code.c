//Write a program to write a name into a file and read it back 

#include<stdio.h>
#include<stdlib.h>
int main()
{
char ch[20],ch1;
FILE *fptr;
fptr=fopen("name.txt","w");
if(fptr==NULL)
{
printf("Error");
exit(1);
}
printf("enter the text");
scanf("%s",ch);
fprintf(fptr,"%s",ch);
fclose(fptr);

fptr=fopen("name.txt","r");
printf("name=");
while(!feof(fptr))
{
ch1=fgetc(fptr);
printf("%c",ch1);
}
printf("/n");
fclose(fptr);
}
