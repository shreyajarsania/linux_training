/*******************************************************************************
 *
 * Write a program to copy structure of your name, address, phone no from one 
 * process to another process using named pipe.
 *
********************************************************************************/
#include "7.h"

int main()
{
	
        void *memory = NULL;
        int shmid;
	char strings[50];
        
	/* inititate shared memory */
	if( (shmid = shmget((key_t)1234, 500, 0777 | IPC_CREAT)) == -1)
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

	strcpy(memory, "");
	/* loop untill end */
	while( strcmp(memory, "end") != 0 )
	{
		/* check if memory is differnt */
		if(strcmp(strings, memory) != 0) 
        	{	
			printf("data received is %s\n", memory);
                	printf("Enter data to send to other program and end to end: \n");
			gets(memory);
			strcpy(strings, memory);
                	printf("data sent is %s\n", memory);
			sleep(3);
		}
	}
	/* detach the memory */
	shmdt(memory);

	printf("terminated\n");
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
