/*******************************************************************************
 *
 * Write a program to copy string from one process to another using unnamed pipe
 *
********************************************************************************/
#include "5.h"

int main()
{
	int file_pipe[2], bytes, fork_sta;
	char buffer[BUFSIZ + 1];
	char str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	
	/* clear buffer to NULL */
	memset(buffer, '\0', sizeof(buffer));

	if(pipe(file_pipe) == 0)
	{
		if((fork_sta = fork()) == -1)
		{
			printf("Fork failed");
			exit (1);
		}
		
		/* execute data in child process */
		if(fork_sta == 0)
		{
			sprintf(buffer, "%d", file_pipe[0]);
			(void)execl("5con", "5con", buffer, NULL);
		}
		else
		{
			bytes = write(file_pipe[1], str, strlen(str));
                        printf("%d - wrote %d bytes form 1st process \n", getpid(), bytes);
		}
	}
	exit(0);
}
