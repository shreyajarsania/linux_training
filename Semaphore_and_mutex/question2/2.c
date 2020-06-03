/*******************************************************************************
 *
 *  Write a program to create two threads.
 *  - One thread will write A to Z a file "temp.txt"
 * - Other thread will write a to z to the same file "temp.txt"
 * - Restriction is, A to Z or a to z should be continuous pattern, whichever 
 *   is started first.
 *
*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *capitalAlphabets();
void *smallAlphabets();
pthread_mutex_t lock; 

int main()
{
	/* create two threads */
	pthread_t thread_one, thread_two;
	int status;

	/* initiate mutex */
//	status = pthread_mutex_init(&lock, NULL);
//	if (status != 0)
//	{
//		printf("mutex failed\n");
//	}

	/* create thread one for capital and thread 2 for small*/
	status = pthread_create(&thread_one, NULL, capitalAlphabets, NULL);
	if(status != 0)
	{
		printf("Error occured in creating the thread\n");
	}
	status = pthread_create(&thread_two, NULL, smallAlphabets, NULL);
	if(status != 0)
        {
                printf("Error occured in creating the thread\n");
        }
	sleep(1);

	/* termiate both the threads */
	status = pthread_join(thread_one, NULL);
	if(status != 0)
        {
                printf("Error occured in joining the thread\n");
        }
	status = pthread_join(thread_two, NULL);
        if(status != 0)
        {
                printf("Error occured in joining the thread\n");
        }
	return 0;
}

void *capitalAlphabets()
{
	FILE *fp;
	int loop;
	
	pthread_mutex_lock(&lock); // lock mutex 
	
	/* operate in file */
	fp = fopen("temp.txt", "a");
	fprintf(fp, "FROM THREAD ONE: ");
	for(loop = 0; loop < 26; loop++)
	{
		fprintf(fp, "%c", 'A' + loop);
	}
	fprintf(fp, "\n");
	sleep(1);
	fclose(fp);
	
	pthread_mutex_unlock(&lock); // unlock mutex
}

void *smallAlphabets()
{
        FILE *fp;
        int loop;
	
	pthread_mutex_lock(&lock); // lock mutex

	/* operate in file */
        fp = fopen("temp.txt", "a");
	fprintf(fp, "FROM THREAD TWO: ");
	for(loop = 0; loop < 26; loop++)
        {
                fprintf(fp, "%c", 'a' + loop);
        }
	fprintf(fp, "\n");
	sleep(1);
	fclose(fp);
	
	pthread_mutex_unlock(&lock); // unlock mutex
}
