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
	char buffer[BUFSIZ];

	/* make named pipe - fifo - my_fifo */
	status = mkfifo("my_fifo", 0777);

	if(status != 0)
	{
		printf("fifo failed\n");
		exit (0);
	}

	status = fork();
	/* store data of file in fifo in child process */
	if(status == 0)
	{
		/* open file in read mode */
		if(( fp1 = open( argv[1], O_RDONLY )) == -1 )
		{
			printf("File1 not opened\n");
		}
			
		read( fp1, buffer, BUFSIZ );
		(void)close(fp1);

		/* open fifo in write mode */
		if(( fpfifo1 = open( "my_fifo", O_WRONLY )) == -1 )
		{
			printf("ERROR to write fifo\n" );
		}
		if(( write( fpfifo1, buffer, BUFSIZ )) == -1 )
		{
			printf("Error in write mode error\n");
		}
		sleep(2);
		(void)close(fpfifo1);
	}	

	/* copy data from fifo to another file */
	else
	{
		/* open fifo in read mode */
		if(( fpfifo2 = open( "my_fifo" , O_RDONLY )) == -1 )
		{
			printf("Error in read fifo\n");
		}

		read( fpfifo2, buffer, BUFSIZ);
		(void)close(fpfifo2);
		
		/* open file in write mode */
		if(( fp2 = open( argv[2], O_WRONLY )) == -1 )
		{
			printf("Error in file 2 open \n");
		}
		if(( write( fp2, buffer, strlen(buffer))) == -1 )
		{
			printf( "Error in writing in file2\n" );
		}
		(void)close(fp2);
		waitpid(status, NULL, 0);	
	}
	return 0;
}
