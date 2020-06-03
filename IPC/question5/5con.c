/************************************************************************************
 *
 * Write a program to copy string from one process to another using unnamed pipe.
 *
************************************************************************************/

#include "5.h"
int main(int argc, char *argv[])
{
	int bytes, file_des;
	char buffer[BUFSIZ + 1]; 
	
	sscanf(argv[1],"%d", &file_des); 
	/* read data from buffer */
	bytes = read(file_des, buffer, BUFSIZ);

	printf("%d - read %d bytes: %s from 2nd proccess\n", getpid(), bytes, buffer);
	exit(0);
}
