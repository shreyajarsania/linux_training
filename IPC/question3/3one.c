/******************************************************************************************************
 *
 *  Understanding of shared memory. Below program demostrating usage of shared memory.
 *  - One program to write strings to shared memory. 
 *  - Number of strings and string patterns will be given by user from command line.
 *  - Second program should read the number of strings and string patterns from shared memory region.
 *  - Strings should be reversed and stored to at the same location.
 *  - In both the programs, memory addresses should be printed where the strings are stored. 
 *
******************************************************************************************************/
#include "3.h"


int main(int argc, char *argv[])
{
	void *memory = NULL;
	int shmid, total = 0, string[50];
	shared_mem *strings;

	if(argv[1] == NULL)
	{
		printf("Please enter no. of strings and then the string patterns \n");
		exit (1);
	}
	/* initiate the message queue */
	if( (shmid = shmget((key_t)1234, sizeof(shared_mem), 0777 | IPC_CREAT)) == -1)
	{
		printf("SHMGET failed\n");
		exit(1);
	}
	/* attach shared memory */
	if ((memory = shmat(shmid, NULL, 0)) == (void *)-1)
	{
		printf("ERROR IN SHMAT\n");
		exit(1);
	}

	/* address of 1 st program */
	printf("Storing data at %d in 1st program\n",(int)memory);
	
	strings = (shared_mem *)memory;
	
	/* store total number stirngs in num */
	strings->num = atoi(argv[1]);

	/* write all the stings in the structure's 2D array */ 
	while(total < strings->num)
	{
		sprintf(strings->str[total],argv[total + 2]);
        	printf("%s\n", strings->str[total]);
		total++;
	}

	/* execute 3two in child process */
	if(fork() == 0)
	{
		(void)execl( "3two", "3two", NULL );
		printf("execl failed\n");
		exit(1);
	}
	else
	{
		sleep(1);
		/* validate if strings got reversed or not */
		printf("string after reversing in 1st program:\n");
		total = 0;
		while(total < strings->num)
        	{
        	        printf("%s\n", strings->str[total]);
        	        total++;
        	}

	}

	/* detach memory */
	shmdt(memory);
	return 0;
}


