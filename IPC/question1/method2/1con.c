#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int fifo_sta, bytes, fp, num;
	char buffer[BUFSIZ + 1];

	memset(buffer, '\0', sizeof(buffer));

	/* open named pipe- fifo in read mode */
	fp = open ("my_fifo", O_RDONLY);

	if(fp != -1)
	{
		/* read data of my_fifo in buffer */
		bytes = read(fp, &num, BUFSIZ);
	}
	else
	{
		printf("File not opened\n");
		exit(1);
	}
	printf("Process %d finished, bytes read %d, value is %d\n", getpid(), bytes, num);
	exit(0);
}
