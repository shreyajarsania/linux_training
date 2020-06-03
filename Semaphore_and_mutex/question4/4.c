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
 *  Write the above program using "mutex and conditional variables" instead 
 *  of "semaphores"
*******************************************************************************/

#include "4.h"

int main()
{
	int num = 0;
	pthread_t pro_thread, con_thread;

	/* loop to get and fetch 1000 numbers */
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

	/* destroy mutex */
	if( pthread_mutex_destroy(&lock) != 0 )
	{
		printf("Error occured in destroying mutex\n");
	}
	return 0;
}

void *producer(void *argument)
{
        int num = *(int *)argument;
        
	pthread_mutex_lock(&lock); // lock mutex

        buffer[pro_loop] = num; // add value into the buffer 
	
	/* perform task */
        printf("producer value is %d at stack %d\n", num, pro_loop);
        if(pro_loop <= 15)
        {
               pro_loop++;
        }
        else
        {
                pro_loop = 0;
        }
        
	pthread_mutex_unlock(&lock); // unlock mutex
        pthread_exit(NULL); // termitate thread
}

void *consumer()
{
        pthread_mutex_lock(&lock);// lock mutex

	/* perform task */
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

        pthread_mutex_unlock(&lock); // unlock mutex
        pthread_exit(NULL);
}
