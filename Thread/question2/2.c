/********************************************************************************************
 *
 * Create two threads, print its PIDs & PPIDs.
 *
*********************************************************************************************/

#include "2.h"

int main()
{
	int create_status, loop;
	pthread_t thread_multiple[2];

	/* creating 2 threads */
	for ( loop = 0; loop < 2; loop++ )
	{
		create_status = pthread_create( &thread_multiple[loop], NULL, myPidThread,  &loop );
		/* retruns 0 on success */
		if(create_status != 0)
		{
			printf("failed to reate thread\n");
			exit (1);
		}
		sleep(1);
	}

	/* terminating 2 threads */
	for(loop = 0; loop <= 1; loop++)
	{
		create_status = pthread_join(thread_multiple[loop], NULL);
		/* returns 0 on success */
		if(create_status == 0)
		{
			printf("thread joined successfully\n");
		}
		else
		{
			printf("thread join failed\n");
		}
	}
	return 0;
}

/* defining the fnction to get pid and ppid */
void *myPidThread(void *(arguments))
{
	int thread_num = *(int *)arguments;
	printf("thread no. %d has pid %d and ppid %d\n", thread_num, getpid(), getppid());
	sleep(1);
}
