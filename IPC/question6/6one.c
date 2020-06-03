/*******************************************************************************
 *
 * Write a program to copy structure of your name, address, phone no from one 
 * process to another process using named pipe.
 *
********************************************************************************/
#include "6.h"

int main()
{
	int status, fp, bytes;
        char * fifo = "my_fifo";
        char buffer[BUFSIZ + 1];
	details student,person; // make 2 variable od this structure

	/* make the named pipe fifo- my_fifo */
        status = mkfifo(fifo, 0777);

        if(status != 0)
        {
                printf("%s cannot be created", fifo);
                return 1;
        }

	/* get data from child process and put it to string */
	if((status = fork()) == 0)
	{
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
	}
	/* get the data out of fifo in parent process */
	else
	{
		/* open fifo in read mode */
	        fp = open ("my_fifo", O_RDONLY);

	        if(fp != -1)
	        {
	                bytes = read(fp, (void *)&person, sizeof(details));
	        }
	        else
	        {
	                printf("File not opened\n");
	                exit(1);
	        }
	        /* print data in 2nd process */
	        printf("Process %d finished, bytes read %d, values: \n", getpid(), bytes);
	        printf("NAME: \t\t %s \n", person.name);
	        printf("Address: \t %s \n", person.address);
	        printf("phone no.: \t %ld \n", person.phone);
		close(fp);
	}
	return 0;
}
