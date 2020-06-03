/*******************************************************************************
 * Producer - Consumer program using semaphores
 *  - A "circular buffer" will be shared among two threads
 *       a. Producer thread
 *       b. Consumer thread
 *  - Producer thread will write a number/numbers in the circular buffer
 *  - Consumer should read the number from circular buffer and print it on 
 *    console
 *  - Write all numbers from 0 to 1000.
 *  - Size of "circular buffer" is 16
 *  - Display exact time taken for the program to execute
*******************************************************************************/

#include "3.h"

int main()
{
	int num = 0;
	pthread_t pro_thread, con_thread;

	/* intiate semaphores */
	if(sem_init(&empty, 0, 16) != 0)
	{
		printf("Error in intilization\n");
		return 1;
	}
	if(sem_init(&fill, 0, 0) != 0)
	{
		printf("Error im im initlization\n");
		return 1;
	}

	/* get and fetch 1000 numbers */
	while(num <= 1000)
	{
		if(pthread_create(&pro_thread, NULL, producer, &num) != 0)
		{
			printf("Producer thread not created\n");
			return 1;
		}
		sleep(0.75);
		if(pthread_create(&con_thread, NULL, consumer, NULL) != 0)
		{
			printf("Consumer thread not created\n");
			return 1;
		}
		sleep(0.5);
		num++;
	}

	/* destroy semaphores*/

	sem_destroy(&fill);
	sem_destroy(&empty); 
	return 0;
}

void *producer(void *argument)
{
        int num = *(int *)argument;
        sem_wait(&empty); // decrease empty as we want to fill in the buffer

        buffer[pro_loop] = num;
        printf("producer value is %d at stack %d\n", num, pro_loop);
        if(pro_loop <= 15)
        {
                pro_loop++;
        }
        else
        {
                pro_loop = 0;
        }
        sem_post(&fill);// increase fill as a value is added to buffer
        pthread_exit(NULL); // terminate thread
}

void *consumer()
{
        sem_wait(&fill); // decrease fill as number is extracted from buffer
        
	int num =  buffer[con_loop];
        
	printf("consumer value is %d at stack %d\n", num, con_loop);
        if(con_loop <= 15)
        {
                con_loop++;
        }
        else
        {
                con_loop = 0;
        }

        sem_post(&empty); // increase empty as number is extracted
        pthread_exit(NULL); // terminate thread
}
