/*******************************************************************************
*
* Create 5 children processes from a common parent and ensure that the
* parent terminates after cleaning all the terminated children using waitpid().
* The waitpid() must be called after all the children are created
* and the parent has completed its work real work,if any. You must interpret
* the exit code of the cleaned-up processes, using waitpid(), in parent process
* – you must cover all the possible scenarios !!!
*
*******************************************************************************/

#include "1.h"
int main()
{
	pid_t child[5];
	int loop, status;

	/* store the child into an array */

	for(loop = 0; loop < 5; loop++) 
    	{ 
        	if((child[loop] = fork()) == 0) 
       	 	{ 
            		printf("Child created with pid %d and parent pid %d\n",getpid(),getppid());
		        sleep(1);	
			exit(0); 
        	} 
    	} 	

	/* call wait pid to terminate all childs */
	for(loop = 0; loop < 5; loop++)
	{
		waitpid(child[loop], &status, 0);
		if(WIFEXITED(status))
		{
			printf("child with pid %d is terminated with status %d\n", child[loop], WEXITSTATUS(status) );
	
		}
	}
	
	return 0;
}
