#include "1.h"
int main()
{
        int file_pipe[2], bytes, fork_sta, num1, num2, file_des;
        char buffer[BUFSIZ + 1];


        /* create unnamed pipe */
	if(pipe(file_pipe) == 0)
        {
                if((fork_sta = fork()) == -1)
                {
                        printf("Fork failed");
                        exit (1);
                }
	}

	/* get data from child process */
        if(fork_sta == 0)
        {
		printf("Enter a number to producer: ");
        	scanf("%d", &num1);
               
		bytes = write(file_pipe[1], &num1, sizeof(num1));
                printf("%d wrote %d bytes\n", getpid(), bytes );
		exit(0);
        }
	/* print data from parent process */
        else
	{
		sprintf(buffer, "%d", file_pipe[0]);
        	bytes = read(file_pipe[0], &num2, sizeof(num2));
        	printf("%d - read %d bytes: %d\n", getpid(), bytes, num2);
        }
	waitpid(fork_sta, NULL, 0);
        exit(0);
}
