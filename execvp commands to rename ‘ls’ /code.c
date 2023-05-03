//Use execvp commands to rename ‘ls’ command by your name 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
	char ch[20];
	scanf("%s",ch);
	char *ch1[] = {ch, NULL};
	execvp("ls", ch1);
	printf("Ending...");
}
