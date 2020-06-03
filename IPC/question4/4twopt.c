/******************************************************************************************
 *
 *   Describe Named FIFO and Unnamed FIFO.
 *   Write a program to copy data from file1 to file2 through named FIFO.
 *   Program done with two relavent processes and unrelavent processes.
 *   Example:
 *   my_cpy file1.txt file2.txt #This command will copy content of file1.txt to file2.txt.
 *
******************************************************************************************/

#include "4.h"

int main( int argc, char *argv[])
{

	int status, fp1, fp2, fpfifo1, fpfifo2;
	char buffer[BUFSIZ], buffercp[BUFSIZ], file2[1];

	/* set memory buffer to null */

	memset(buffer, '\0', sizeof(buffer));
	
	/* open fifo in read mode */
	if(( fpfifo2 = open( "my_fifo" , O_RDONLY )) == -1 )
        {
		printf("Error in read fifo\n");
        }

        read( fpfifo2, buffer, BUFSIZ );
	
        (void)close(fpfifo2);

	/* copy the 10 element into file name */
	strncpy(buffercp, buffer, 10);
	sprintf(file2, "%c", buffer[10]);

	/* open file i write mode */
	if(( fp2 = open( file2, O_WRONLY )) == -1 )
        {
	        printf("Error in file 2 open \n");
	}
        if(( write( fp2, buffercp, strlen(buffercp))) == -1 )
        {
                printf( "Error in writing in file2\n" );
        }
        (void)close(fp2);

	return 0;
}
