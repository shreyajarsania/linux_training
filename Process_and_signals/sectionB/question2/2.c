/*******************************************************************************
*
* Create 5 processes but not from the common parent. Meaning, each child
* creates a new process. clean-up the children using waitpid(). waitpid()
* must be called after all the children are created and the parent has
* completed its work real work,if any. You must interpret the exit code of the
* cleaned-up processes, using waitpid(), in the parent process
* – you must cover all the possible scenarios !!!
*
*******************************************************************************/

#include "2.h"
int main()
{
        pid_t child[5], child_fork;
        int loop, exit_code, status, inner_loop = 0;

        /* store the childs into an array */

        for(loop = 0; loop < 5; loop++)
        {
		/* create the child process */
                if((child_fork = fork()) != 0)
                {
			printf("Child created with pid %d and parent pid %d\n", getpid(), getppid());
			sleep(1);

			/* close the child process once created*/
			waitpid(child_fork, &status, 0);
	        
			if(WIFEXITED(status))
                	{
                       		printf("Child with exit_code %d and pid %d teminated\n", WEXITSTATUS(status), getpid());
                	}
			exit(0);
		}
	}

        return 0;
}
