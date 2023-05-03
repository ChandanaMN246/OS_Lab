//Use execvp command 
#include<stdio.h>
#include<unistd.h>
void main(){
	printf("lab5_4.c called via execvp()");
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
	char *args[]={"./prog3",NULL};
	execvp(args[0],args);
	printf("Ending...");
}
