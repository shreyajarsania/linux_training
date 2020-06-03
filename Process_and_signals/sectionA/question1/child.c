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
	/* execute child process from parent process */

	int fork_val;
	printf("parent process with pid = %d and ppid = %d\n", getpid(), getppid());
	
	/* creating child process */
	fork_val = fork();

	/* fork_val for parent will give pid of child and for child will give 0 */
	printf("process pid = %d and ppid = %d and fork output = %d\n", getpid(), getppid(), fork_val);
}
