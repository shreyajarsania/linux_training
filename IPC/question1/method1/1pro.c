#include "1.h"

int main()
{
	int file_pipe[2], bytes, fork_sta, num;
	char buffer[BUFSIZ];
	printf("Enter a number to producer: ");
	scanf("%d", &num);
	
	/* create pipe */
	if(pipe(file_pipe) == 0)
	{
		if((fork_sta = fork()) == -1)
		{
			printf("Fork failed");
			exit (1);
		}
		
		/* execute consumer program from child process */
		if(fork_sta == 0)
		{
			sprintf(buffer, "%d", file_pipe[0]);
			(void)execl("1con", "1con", buffer, (char *)0);
		}
		else
		{
			/* copy data of num to file pipe */
			bytes = write(file_pipe[1], &num, sizeof(num));
                        printf("%d wrote %d bytes\n", getpid(), bytes);
		}
	}
	exit(0);
}
