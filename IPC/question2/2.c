/******************************************************************************************************
 * 
 * Producer - Consumer program using threads and semaphore
 *  - A queue will be shared among two threads
 *        a. Producer thread
 *        b. Consumer thread
 *  - Producer thread will write a number in the queue
 *  - Consumer should read the number from queue and print it on console only if the queue is 
 *  not empty.
 *
******************************************************************************************************/
#include "2.h"

int main()
{
        pthread_t pro_thread, con_thread;

        /* intiate semaphores */
        if(sem_init(&syn, 0, 1) != 0)
        {
                printf("Error in intilization\n");
                return 1;
        }

	/* intitate message queue */
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

	/* create threads */
        if(pthread_create(&pro_thread, NULL, producer, NULL) != 0)
        {
        	printf("Producer thread not created\n");
        	return 1;
        }
        sleep(1);
        if(pthread_create(&con_thread, NULL, consumer, NULL) != 0)
        {
        	printf("Consumer thread not created\n");
        	return 1;
        }
        sleep(1);
        /* destroy semaphores*/

	pthread_join(con_thread, NULL);
	pthread_join(pro_thread, NULL);
        sem_destroy(&syn);
        return 0;
}

void *producer()
{
	sem_wait(&syn); // decrease empty as we want to fill in the buffer

	printf("Enter the number ");
	scanf("%d", &message.msg_num);

	printf("Number sent is %d\n", message.msg_num);
	/* send the data to consumer */
	int stat = msgsnd(msgid, &message.msg_num, sizeof(message.msg_num), 0);

       	sem_post(&syn);// increase fill as a value is added to buffer
	pthread_exit(NULL); // terminate thread
}

void *consumer()
{       
        sem_wait(&syn); // decrease fill as number is extracted from buffer

	int stat;
	/* receive data from producer */
	if(msgrcv(msgid, (void *)&buffer, sizeof(buffer.msg_num), (long int)0, 0) != -1)
	{
		printf("Received data is %d\n", message.msg_num);

		msgctl(msgid, IPC_RMID, NULL);
	}
	
	else
	{
		printf("receiving error\n");
	}
        sem_post(&syn); // increase empty as number is extracted
        pthread_exit(NULL); // terminate thread
}
