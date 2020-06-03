/************************************************************************************
 *
 * Write a program to copy string from one process to another using unnamed pipe.
 *
************************************************************************************/

#include "6.h"
int main()
{
	int fifo_sta, bytes, fp;
        char buffer[BUFSIZ + 1];
	details person;

	/* set memory in NULL */
        memset(buffer, '\0', sizeof(buffer));

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
        exit(0);
}
