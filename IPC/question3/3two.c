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
	int shmid, total = 0, string[50], length;
	shared_mem *strings;
	char rev;

	/* get the id of shared memory */
	if( (shmid = shmget((key_t)1234, sizeof(shared_mem), 0777 | IPC_CREAT)) == -1)
	{
		printf("SHMGET failed\n");
		exit(1);
	}

	/* attach to that memory */
	if ((memory = shmat(shmid, NULL, 0)) == (void *)-1)
	{
		printf("ERROR IN SHMAT\n");
		exit(1);
	}
	
	strings = (shared_mem *)memory;

	/* address of 2nd program */
	printf("strings are stored at %d in 2nd program\n", (int)memory);
	
	/* print strings, reverse them and store at same location */
	while(total < strings->num)
	{
		printf("%s\n", strings->str[total]);
		length = strlen(strings->str[total]);
		while(length > 0)
		{
			rev = strings->str[total][0];
			strings->str[total][0] = strings->str[total][length - 1];
			strings->str[total][length - 1] = rev;
			length--;
		}
		total++;
	}

	printf("strings after reversing in 2nd program: \n");
	total = 0;
	while(total < strings->num)
        {
                printf("%s\n", strings->str[total]);
                total++;
        }

	/* detach memeory */
	shmdt(memory);

	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}


