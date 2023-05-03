//Implement a hierarchy as shown below where third generation terminates first, followed by second, followed by first and then the parent 


#include <stdio.h>
#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
int main()
{
	int id1 = fork();
	int id2 = fork();
	int id3=fork();

	// parent process
	if (id1 > 0 && id2 > 0  && id3 > 0)
	{
		wait(NULL);
		wait(NULL);
		wait(NULL);
		printf("Parent Terminated \n");
	}
	// 1st child
	else if (id1 == 0 && id2 > 0  && id3 > 0) 
	{

		int id4=fork();
		int id5=fork();

		if (id4 == 0 && id5 > 0) 
		{
			sleep(1);
			printf("First Child  of second generation Terminated \n");
		}
		else if (id4 > 0 && id5 == 0) 
		{
			sleep(2);
			printf("Second Child of second generation Terminated \n");
		}
		// grand child
		else
		{
			printf("Grand (3rd gen)Child Terminated \n");
		}
		sleep(4);
		wait(NULL);
		printf("First Child Terminated \n");
	}
	// second child
	else if (id1 > 0 && id2 == 0 && id3 > 0 )  
	{
		wait(NULL);
		wait(NULL);
		wait(NULL);
		sleep(5);
		printf("Second Child Terminated \n");
	}

	// third child
	else if (id1 > 0 && id2 > 0 && id3 == 0 )  
	{
		int id6=fork();
		if(id6==0)
		{
			sleep(3);
			printf("third child of second generation Terminated \n");
		}
		wait(NULL);
		sleep(6);
		printf("third Child Terminated \n");
	}
        return 0;

} 
