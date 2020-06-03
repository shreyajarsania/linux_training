/*******************************************************************************
*
* Make a program for Executing a child process from parent process.
* what is zombie process? How can you overcome ? Explain through program.
* If Parent execute first then child, what happen? explain through program.
*
*******************************************************************************/

#include "1.h"
int main()
{
	/* 
	 * zombie process
	 * when fork is called, chiled process is created and runs the code further.
	 * even if child process is completed it's instance still stays ni program untill parent process if either terminated or called for wait. If child finishes first, will exists as zombie untill parent finishes. 
	 */
	pid_t pid;
	char *message;
	int n;
	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = 3;
			break;
		default:
			message = "This is the parent";
			n = 5;
	break;
	}
	for(; n > 0; n--) 
	{
		puts(message);
		sleep(1);
	}
	
	if(pid != 0)
	{
		waitpid(pid, (int *) 0, WNOHANG);
	}

	printf("Zombie process must be removed\n");
	exit(0);
}
