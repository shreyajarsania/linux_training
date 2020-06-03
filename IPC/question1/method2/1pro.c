#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int fifo_sta, fp, bytes, num;
	char * fifo = "my_fifo";
	char buffer[BUFSIZ + 1];

	/* create namned pipe fifo- my_fifo */
	fifo_sta = mkfifo(fifo, 0777);
	
	if(fifo_sta != 0)
	{
		printf("%s cannot be created, remove my_fifo\n", fifo);
		return 1;
	}
	/* open fifo in write mode */
	fp = open(fifo, O_WRONLY);

	printf("Enter the number : ");
	scanf("%d", &num);

	if(write( fp, &num, sizeof(num) ) == -1)
	{
		printf("Error on pipe\n");
		exit (1);
	}
	close (fp);
	printf("Process %d finished\n", getpid());
	exit(0);
}
