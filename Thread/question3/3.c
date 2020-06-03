/********************************************************************************************
 *
 * Make a program to check how two threads simultaneous works. One thread incrementing even 
 * number & print it on console and simultaneously second thread incrementing odd number & 
 * print it on console.
 *
*********************************************************************************************/

#include "3.h"

int main()
{
        int create_status, loop;
        pthread_t thread_multiple[2];

	/* creating 2 threads */
        for ( loop = 0; loop < 2; loop++ )
        {
                create_status = pthread_create( &thread_multiple[loop], NULL, myoddeven,  &loop );
                /* retruns 0 on success */
                if(create_status != 0)
                {
                        printf("failed to reate thread\n");
                        exit (1);
                }
		else
		{
			printf("thread created successfully\n");
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
void *myoddeven(void *(arguments))
{
	int id = *(int *)arguments;
	int num = 0, even = 0, odd = 1;
	
	if( id == 0 )
	{
		while(num++ <= 10)
		{
                	even += 2;
               		printf("%d ", even);
		}
		printf("\n");
	}
	else
	{
		while(num++ <= 10)
		{
                	odd += 2;
                	printf("%d ", odd);
		}
	}
	printf("\n");
}

