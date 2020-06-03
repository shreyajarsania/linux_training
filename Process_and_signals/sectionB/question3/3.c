/*******************************************************************************
*
* Create a 5 child process from a common parent and launch different
* applications from the children processes - you may launch firefox
* Gedit, and gcc - parent process must use waitpid() to
* collect the termination status of the child process - waitpid()
* must be called after all the children are created and the parent has
* completed its work real work,if any. You must interpret the exit code 
* of thecleaned-up processes, using waitpid(), in the parent process
* – you must cover all the possible scenarios -meaning, terminate the 
* children processes normally(successful/unsuccessful) or abnormally !!!
*
*******************************************************************************/

#include "3.h"
int main(int argc, char **argv) 
{
	pid_t pid;
	int loop;

	/* take an array of applications to be open */
	char *app_list[] = { "/usr/bin/firefox", "/usr/bin/shotwell", "/usr/bin/gedit", "/usr/bin/gcc", "/usr/bin/libreoffice"};

	for (loop = 0; loop < 5; loop++)
	{
		/* create child process */
		pid = fork();

		/* error case */
  		if (pid == -1)
    		perror("fork failed");

		/* execute the function only in child process */
  		if (pid == 0) 
  		{
    			execvp( app_list[loop], NULL );
  		}
  		else 
  		{
  		}
	}
  	return 0;
}
