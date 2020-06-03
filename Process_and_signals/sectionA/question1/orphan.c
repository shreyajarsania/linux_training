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
	pid_t pid;
        char *message;
        int n, status;

        printf("fork program\n");
        pid = fork();
        
	/* 
	 * executing parent process before child process will create orphan process.
	 * parent process terminates before child process without informing it, hence the child process executes in next line in command promt. to avoid, wait the process untill the child id finished
	 */
	switch(pid)
        {
                case -1:
                        perror("fork failed");
                        exit(1);
                case 0:
                        message = "This is the child";
                        n = 5;
                        break;
                default:
                        message = "This is the parent";
                        n = 3;
        break;
        }
        for(; n > 0; n--)
        {
                puts(message);
                sleep(1);
        }

        if(pid != 0)
        {
		printf("using wait function to avoid orphan process\n");
                wait(&status);
        }

        exit(0);
}
