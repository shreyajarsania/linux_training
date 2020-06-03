/*******************************************************************************
 *
 * Write a program to copy structure of your name, address, phone no from one 
 * process to another process using named pipe.
 *
********************************************************************************/
#include "6.h"

int main()
{
	int fifo_sta, fp, bytes;
        char * fifo = "my_fifo";
        char buffer[BUFSIZ + 1];
	details student;

        fifo_sta = mkfifo(fifo, 0777);

        if(fifo_sta != 0)
        {
                printf("%s cannot be created", fifo);
                return 1;
        }

	printf( "Enter name: " );
	scanf( "%s", student.name );
	getchar();
	printf( "Enter address: " );
	scanf( "%s", student.address );
	getchar();
	printf( "Enter phone number: " );
	scanf( "%d", &student.phone );

        fp = open(fifo, O_WRONLY);
	{
		write(fp, (void *)&student, sizeof(details));
	}
	close(fp);

	printf("Process %d finished writing\n", getpid());		
	return 0;
}
